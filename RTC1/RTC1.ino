#include <DS3231.h>
#include <SPI.h>
#include <SD.h>
#include <Wire.h>

DS3231  rtc(SDA, SCL); 
File myFile;
 
void setup()
{
Serial.begin(9600);
rtc.begin();
 
  //setting pertama download program
//  rtc.setDate(11, 5, 2019);   //mensetting tanggal 07 april 2018
//  rtc.setTime(13, 58, 00);     //menset jam 22:00:00
//  rtc.setDOW(1);     //menset hari "selasa"
 
 Serial.println("Read MicoSd Card");
 delay(1000);
  Serial.println("Initializing SD card...");
  if (!SD.begin(4)) { //pin digital
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
 delay(1000);
} 
 
void loop()
{
  myFile = SD.open("log.txt", FILE_WRITE);// proses nyimpan ke SDcard type log.txt
  if (myFile) {
    Serial.println("Writing to log.txt...");
     
    String tgl,waktu, timestamp;
    tgl = rtc.getDateStr(FORMAT_LONG,FORMAT_BIGENDIAN,'-');//style penulisan tanggal
    waktu = rtc.getTimeStr();
    timestamp = tgl + " " + waktu;
    Serial.print(timestamp + "\t ");
    myFile.print(timestamp + "\t ");// menulis waktu pada log.txt
    
    Serial.println(rtc.getTemp());
    myFile.println(rtc.getTemp());// menulis data suhu log.txt
    myFile.close();
 }
 else 
 {
 Serial.println("Failed open log.txt");//jika format tidak sesuai / tidak bisa baca log.txt
 }

   myFile = SD.open("log.txt"); //line 52 untuk membuka file yang telah di simpan
   Serial.println("Isi log.txt:");
  if (myFile) {
    
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close();
  } else {
    Serial.println("error opening log.txt");
  }

 delay(2000); 
}
