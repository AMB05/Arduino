#include <LiquidCrystal.h>
#define lm35 A0
#define LED 12
LiquidCrystal lcd(  7, 6,  5,  4,  3, 2); // pin arduino
                // RS, E, D4, D5, D6, D7   pin lcd
int baca_sensor;
float suhu;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Sistem komputer");
  delay(200);
  lcd.clear(); // menghapus karakter pada lcd
  pinMode (LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  baca_sensor = analogRead(lm35); // membaca nilai adc
  suhu       = baca_sensor * 0.48828125; // konversi adc ke derajat celcius
  if ( suhu>=36)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
  lcd.setCursor(0, 0);        // kolom ke 1 baris ke 1
  lcd.print("Suhu Sekarang"); 
  lcd.setCursor(0, 1);        // kolom ke 1 baris ke 2
  lcd.print(suhu);
  lcd.print(" 'C");
  Serial.println("Suhu : ");
  Serial.println(suhu); 
  Serial.println(" ^Celcius ");    // menampilkan ke serial
  
  
  delay(500);
}
