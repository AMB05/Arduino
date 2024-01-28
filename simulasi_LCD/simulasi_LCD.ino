#include <LiquidCrystal.h>
LiquidCrystal LCD(2,3,4,5,6,7);
#define LM35 A0

int led_a = 8;
float rcv=0.0;
float temp = 0.0;


byte deg[8]={B00110, B01001, B01001, B00110, B00000, B00000, B00000, B00000};


void setup() 
{
  LCD.begin(16,2);
  LCD.setCursor(0,0);
  LCD.print("Temp = ");
  LCD.createChar(3, deg);
  LCD.setCursor(5,1);
  LCD.write(byte(3));
  pinMode (led_a, OUTPUT);
}

void loop() 
{
  rcv = analogRead(LM35);
  temp = (rcv * (5.0/1024.0)*1000)/10;
  LCD.setCursor(0,1);
  LCD.print(temp);
  LCD.setCursor(6,1);
  LCD.print("C");
  if (temp >=38)
  {
    digitalWrite(led_a, HIGH);
  }
  else
  {
    digitalWrite(led_a, LOW);
  }
  delay (500);
}
