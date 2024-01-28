#define BLYNK_PRINT SwSerial
#include <SoftwareSerial.h>
SoftwareSerial SwSerial(10, 11); // RX, TX
#include <BlynkSimpleStream.h>

char auth[] = "nltdNg8nhz9clY5-Y6C98EHBsBn9UMPu";

WidgetLCD lcd(V1);
long duration, distance;
int trig =4;
int eco = 5;

BlynkTimer timer;
void myTimerEvent()
{
  int data = analogRead(A2)*(3.20/1023.0)*100.0;
  Blynk.virtualWrite(V5, data);
}

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  //SwSerial.print("V1 Slider value is: ");
  //SwSerial.println(pinValue);
  digitalWrite(2, pinValue);
  digitalWrite(3, pinValue);
}

void setup()
{
  SwSerial.begin(9600);
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
  timer.setInterval(1000L, myTimerEvent);

  pinMode(trig, OUTPUT);
  pinMode(eco, INPUT);
  lcd.clear();
  lcd.print(0, 0, "Jarak CM");
  
}

void loop()
{
  lcd.clear();
  lcd.print(0, 0, "Jarak CM"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
  
  digitalWrite(trig, LOW);  
  delayMicroseconds(3); 
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);
    
  duration = pulseIn(eco, HIGH);
  distance = (duration/2) /588.10;
  //Serial.print(distance);
  //Serial.println("Cm");
  lcd.print(7, 1, distance);

  Blynk.run();
  timer.run(); // Initiates BlynkTimer 
  delay(1000);
}
