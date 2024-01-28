#include <SoftwareSerial.h>
#include <stdlib.h>

// inialisasi pin sensor dan alarm/buzzer
int lm35Pin = 0;
String apiKey = "Sensor_API"; // Ubah dengan API Key ente bro!
SoftwareSerial ser(10, 11); // RX, TX
const int pinApi = 8;
const int pinAlarm = 9;
const int smokeA0 = A5;

// inialisasi variabel data
int data;
int dataAsap;
//Nilai threshold
int sensorThres = 100;


// ----------- program default/setting awal ----------- //
void setup()
{
 // inialisasi status I/O pin
 
 pinMode(pinApi, INPUT); // pin sebagai input
 pinMode(smokeA0, INPUT); // pin sebagai input
 pinMode(lm35Pin, INPUT);
 pinMode(pinAlarm, OUTPUT); // pin sebagai output
 ser.begin(9600);
  ser.println("AT+RST");
 Serial.begin(57600);
 
}

// ----- program utama, looping/berulang terus-menerus ----- //
void loop()
{
 // variabel data adalah hasil dari pembacaan sensor
 // berupa logic LOW/HIGH
 data = digitalRead(pinApi);
 int analogSensor = analogRead(smokeA0);
 
 Serial.print("Pin A0: ");
 Serial.println(analogSensor);

   int val = 0;
  for(int i = 0; i < 10; i++) 
  {
      val += analogRead(lm35Pin);   
      delay(500);
  }
  float temp = val*50.0f/1023.0f;
  char buf[16];
  String strTemp = dtostrf(temp, 4, 1, buf);
  Serial.println(strTemp);
  
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += "184.106.153.149"; // api.thingspeak.com
  cmd += "\",80";
  ser.println(cmd);


 // jika data pada sensor API bernilai logic LOW
 if (data == LOW)
 {
 // alarm dinyalakan
 digitalWrite(pinAlarm, HIGH);
 delay(100);
 }

// jika data Analog pada sensor Asap lebih besar dari batas
 else if (analogSensor > sensorThres)
  {
    tone(pinAlarm, 1000, 200);
    delay(100);
     
  }
  else if (ser.find("Error"))
  {
    Serial.println("AT+CIPSTART error");
    return;
  }

  String getStr = "GET /update?api_key=";
  getStr += apiKey;
  getStr +="&field1=";
  getStr += String(strTemp);
  getStr += "\r\n\r\n";

  cmd = "AT+CIPSEND=";
  cmd += String(getStr.length());
  ser.println(cmd);

   if(ser.find(">"))
  {
    ser.print(getStr);
  }
  
 // jika data tidak bernilai logic LOW
 else
 {
 // alarm dimatikan
 ser.println("AT+CIPCLOSE");
    Serial.println("AT+CIPCLOSE");
 digitalWrite(pinAlarm, LOW);
 delay(100);
 delay(1000);
 }
}
