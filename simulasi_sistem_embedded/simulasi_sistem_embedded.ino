#include <LiquidCrystal.h>
LiquidCrystal lcd (7, 6, 5, 4, 3, 2);

void setup() 
{
  lcd.begin(16,2);
  lcd.setCursor(1,0);
  lcd.print("Temp = ");
  lcd.setCursor(10,0);
  lcd.print("C");
  lcd.setCursor(1,1);
}

void loop() 
{
  int Valuer = analogRead(A0);
  int Vout=Valuer*5.0/1023*1000;
  int temp=Vout/10;

  lcd.setCursor(7,0);
  lcd.print(temp);
}
