#include <LiquidCrystal.h>
#include <DS3232RTC.h>
#include <LM35.h>

LM35 suhu (A0);

const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);



void setup() 
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  setSyncProvider(RTC.get);
  pinMode (8, OUTPUT);
  pinMode (A2, OUTPUT);
}

void loop() 
{
  int tgl = day();
  int bln = month();
  int thn = year();
  int jam = hour();
  int mnt = minute();
    
  lcd.setCursor(0, 0);
  lcd.print(tgl);
  lcd.print('/');
  lcd.print(bln);
  lcd.print('/');
  lcd.print(thn);
  lcd.print(' ');
  lcd.print(jam);
  lcd.print(':');
  lcd.print(mnt);

  if ( (jam == 12) && (mnt == 38))
  {
    digitalWrite (8, HIGH);
  }
  else
  {
    digitalWrite (8, LOW);
  }
  
  int t = suhu.cel();
  Serial.println(t);

  lcd.setCursor(0, 1);
  lcd.print("suhu = ");
  lcd.print(t);

  if (t >= 36 )
  {
    digitalWrite (A2, HIGH);
  }
  else
  {
    digitalWrite (A2, LOW);
  }
  
delay (1000);
}
