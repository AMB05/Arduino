#include<LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  //pin arduino LCD
int ledPin = 10;
int inPin = A2;
int val = 0;

void setup() 
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Robotika Praktikum");
  delay(200);
  lcd.clear();
  pinMode(ledPin, OUTPUT);
  pinMode(inPin, INPUT);
}

void loop() 
{
  val = digitalRead(inPin);
  if(val == LOW)
  {
    digitalWrite(ledPin, LOW);
    lcd.setCursor(0,0);
    lcd.print("Lampu Mati");
  }
  else if (val == HIGH)
  {
    digitalWrite(ledPin, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Lampu Nyala");
  }
}
