#include <LiquidCrystal.h>
#define N 150   // lubang pada cakram
#define T 400  // Time window = 80 ms
#define res 1 // 60000/(T*N)
LiquidCrystal lcd(13,12,10,9,6,4);
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
int slot = 0;
int velo;
char tulisan[16];
char PW = 90;
char fase = 1;

void setup() {

lcd.begin(16, 2);Serial.begin(9600);
inputString.reserve(200);
EICRA |= (1<<ISC01);
EIMSK |= (1<<INT0);
sei();
lcd.setCursor(7, 1);lcd.print("W=    Rpm");
  pinMode(11, OUTPUT);    // OC2A PWM generator
  noInterrupts();         // disable all interrupts
  TCCR0A = 0;TCCR0B = 0;  // Timer0 as Time Window
  TCCR1A = 0;TCCR1B = 0;  // Timer1 as Encoder Pulse Counter
  TCCR2A = 0;TCCR2B = 0;  // Timer2 as PWM generator
  OCR0A  = 250;// T = 250*5*64 us = 80000 us
  TCCR0A |= (1<<WGM01);   // CTC mode, Output Compare Timer 0A.
  TCCR0B |= (1<<CS02) | (1<<CS00);  //1024 prescaller, XTAL 16 MHz, tick = 64 us.
  TIMSK0 |= (1<<OCIE0A);  // enable timer 0A compare interrupt
  TCCR1B |= (1<<CS12) | (1<<CS11) | (1<<CS10);  //rising edge 16-bit counter
  TCCR2A |= (1<<WGM21);   // CTC mode, Output Compare Timer 2A.
  TCCR2B |= (1<<CS22) | (1<<CS21) | (1<<CS20);  //1024 prescaler
  TIMSK2 |= (1<<OCIE2A);  // enable timer 2A compare interrupt
  TCNT2  = 0; OCR2A = PW;
  EICRA  = 0; EIMSK = 0;
  EIMSK  |= (1<<INT1)  | (1<<INT0);  // interrupt enable
  EICRA  |= (1<<ISC11) | (1<<ISC01); // falling edge trigger
  interrupts();           // enable all interru
}
ISR(TIMER0_COMPA_vect)    // timer0A compare interrupt service routine
{
  slot++;
  if(slot == 5) TCNT1=0; // 30-25 = 5 slot = 80000 us, agar res = 15 rpm
  if(slot == 30) {        // 30 slot = 480000 us, 0.48 detik, interval update speed di LCD
    noInterrupts(); // disable all interrupt
    velo = TCNT1;
    velo = velo*1;
    itoa(velo,tulisan,10);   // convert int to decimal string
    lcd.setCursor(9, 1);    // kolom kelima baris kedua
    lcd.print("   ");
    lcd.setCursor(9, 1);
    lcd.print(tulisan);
    slot = 0;
    interrupts(); // enable interrupt
    }
}
ISR(TIMER2_COMPA_vect)    // timer2A compare interrupt service routine
{//duty cycle 2*PW %, OCR2A = 2*PW, 200-2*PW
  switch (fase) {
    case 1: fase  = 2; OCR2A = 200 - 2*PW;
            digitalWrite(11, LOW); break;
    case 2: fase  = 1; OCR2A = 2*PW;
            digitalWrite(11, HIGH); break; }
}
ISR(INT0_vect) { PW -= 5;if(PW<=0) PW = 5;}
ISR(INT1_vect) {PW += 5;if(PW>=100) PW = 95;}

void loop() {

  if (stringComplete) {
    if(inputString.charAt(0) == 's') lcd.setCursor(0,0);
       else lcd.setCursor(0,1);
    lcd.print(inputString);
    inputString = ""; stringComplete = false;}
}
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {stringComplete = true;}}}
