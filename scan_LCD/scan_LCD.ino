#include <Wire.h>;
void setup(){
  Wire.begin();
  Serial.begin(9600);
  while (!Serial);
  Serial.println("\nI2C Scanner");
}
void loop(){
  byte error, address;
  int nDevices;
  Serial.println("Mencari Alamat I2C...");
  
  nDevices = 0;
  for(address = 1; address < 127; address++ ){
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    
    if (error == 0){
      Serial.print("Alamat I2C kamu adalah = 0x");
      if (address<16)
      Serial.print("0");
      Serial.print(address,HEX);
      Serial.println(" !");
      
      nDevices++;
    }
    else if (error==4){
      Serial.print("Tidak ditemukan alamat 0x");
      if (address<16)
      Serial.print("0");
      Serial.println(address,HEX);
    }
  }
  if (nDevices == 0)
    Serial.println("Tidak ditemukan alamat i2c\n");
    else
    Serial.println("Selesai\n");
    
    delay(5000);
}
