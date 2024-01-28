#include <LiquidCrystal.h>
#include <Wire.h>
#define lm35 A0
#define LED 12
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int baca_sensor;
float suhu;
 
void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT_PULLUP);                      // button1 is connected to pin 8
  pinMode(9, INPUT_PULLUP);                      // button2 is connected to pin 9
  // set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  Wire.begin();                                  
  pinMode (LED, OUTPUT);
}
 
char Time[]     = ": :  ";
char Calendar[] = "/  / -20";
byte i, second, minute, hour, date, month, year;
 
void DS1307_display(){
  // Convert BCD to decimal
  second = (second >> 4) * 10 + (second & 0x0F);
  minute = (minute >> 4) * 10 + (minute & 0x0F);
  hour   = (hour >> 4)   * 10 + (hour & 0x0F);
  date   = (date >> 4)   * 10 + (date & 0x0F);
  month  = (month >> 4)  * 10 + (month & 0x0F);
  year   = (year >> 4)   * 10 + (year & 0x0F);
  // End conversion
  Time[7]     = second % 10 + 48;
  Time[6]     = second / 10 + 48;
  Time[4]      = minute % 10 + 48;
  Time[3]      = minute / 10 + 48;
  Time[1]      = hour   % 10 + 48;
  Time[0]      = hour   / 10 + 48;
  
  Calendar[4]  = month  % 10 + 48;
  Calendar[3]  = month  / 10 + 48;
  Calendar[1]  = date   % 10 + 48;
  Calendar[0]  = date   / 10 + 48;
  lcd.setCursor(0, 0);
  lcd.print(Time);                               // Display time
  lcd.setCursor(0, 1);
  lcd.print(Calendar);                           // Display calendar/date
}
void blink_parameter(){
  byte j = 0;
  while(j < 10 && digitalRead(8) && digitalRead(9)){
    j++;
    delay(25);
  }
}
byte edit(byte x, byte y, byte parameter){
  char text[3];
  while(!digitalRead(8));                        
  while(true){
    while(!digitalRead(9)){                      
      parameter++;
      if(i == 0 && parameter > 23)               
        parameter = 0;
      if(i == 1 && parameter > 59)               
        parameter = 0;
      if(i == 2 && parameter > 31)               
        parameter = 1;
      if(i == 3 && parameter > 12)              
        parameter = 1;
      if(i == 4 && parameter > 99)         
        parameter = 0;
      sprintf(text,"%02u", parameter);
      lcd.setCursor(x, y);
      lcd.print(text);
      delay(200);                           
    }
    lcd.setCursor(x, y);
    lcd.print("  ");                             
    blink_parameter();
    sprintf(text,"%02u", parameter);
    lcd.setCursor(x, y);
    lcd.print(text);
    blink_parameter();
    if(!digitalRead(8)){                        
      i++;                                       
      return parameter;                          
    }
  }
}
 
void loop() {
      baca_sensor = analogRead(lm35);
  suhu       = baca_sensor * 0.48828125; // konversi adc ke derajat celcius
  if ( suhu>=36)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
  lcd.setCursor(9, 10);
  lcd.print(suhu);
  lcd.print("'C");
  Serial.println("Suhu : ");        //tampilkan serial virtual
  Serial.println(suhu); 
  Serial.println(" ^Celcius ");    
  
  if(!digitalRead(8)){                           
      i = 0;
      hour   = edit(5, 0, hour);
      minute = edit(8, 0, minute);
      date   = edit(5, 1, date);
      month  = edit(8, 1, month);
      year   = edit(13, 1, year);
      // Convert decimal to BCD
      minute = ((minute / 10) << 4) + (minute % 10);
      hour = ((hour / 10) << 4) + (hour % 10);
      date = ((date / 10) << 4) + (date % 10);
      month = ((month / 10) << 4) + (month % 10);
      year = ((year / 10) << 4) + (year % 10);
      // End conversion
      // Write data to DS1307 RTC
      Wire.beginTransmission(0x68);              
      Wire.write(0);                      
      Wire.write(0);                            
      Wire.write(minute);                    
      Wire.write(hour);                     
      Wire.write(1);                            
      Wire.write(date);                       
      Wire.write(month);                    
      Wire.write(year);                     
      Wire.endTransmission();                    
      delay(200);                          
    }
    Wire.beginTransmission(0x68);                 
    Wire.write(0);                               
    Wire.endTransmission(false);                 
    Wire.requestFrom(0x68, 7);                    
    second = Wire.read();                         
    minute = Wire.read();                         
    hour   = Wire.read();                         
    Wire.read();              
    date   = Wire.read();                   
    month  = Wire.read();                         
    year   = Wire.read();                         
    DS1307_display();                            
    delay(50);                                    



}
