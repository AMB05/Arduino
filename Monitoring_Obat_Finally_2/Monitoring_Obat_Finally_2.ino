#include "CTBot.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

//wifi
#ifndef STASSID
#define STASSID "e6"
#define STAPSK  "12345678"
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;

//bot
CTBot myBot;
String token = "5514202023:AAGdnSipDveJx0mtBZPuM7oB2bCrW8Cum_4";
const int id = 1241079100;


//api wordl time
const char* host = "http://worldtimeapi.org/api/timezone/Asia/Jakarta";
String api_jam, api_menit, api_jam_menit;
String waktu1 = "07:30", waktu2="13:00", waktu3="17:00"; 
bool do_waktu1 = false, do_waktu2 = false, do_waktu3 = false;

LiquidCrystal_I2C lcd(0x27, 16, 2);

//infrared esp1
#define sensor1d  D8
#define sensor2d  D3
#define buzzer    D4

void setup() 
{
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  pinMode(sensor1d, INPUT);
  pinMode(sensor2d, INPUT);
  pinMode(buzzer,OUTPUT);
//  wifi();
//  sensor();

} 
void loop() 
{
  time_t now;
  struct tm * timeinfo;
  time(&now);
  timeinfo = localtime(&now);  
  Serial.println(timeinfo->tm_hour);
  delay(1000);
//  wifi();
}

void wifi()
{
//Koneksi ke wifi
  Serial.println("Starting TelegramBot...");
  myBot.wifiConnect(ssid, password);
  myBot.setTelegramToken(token);
  if (myBot.testConnection())
    Serial.println("Connection OK");
    
  else
    Serial.println("Connection Failed");
}

void sensor()
{
  //sensor
  int sd1 = digitalRead(sensor1d);
  int sa1 = analogRead(D7);
  int sd2 = digitalRead(sensor2d);
  int sa2 = analogRead(D2);

  //timeif
  HTTPClient http;
  WiFiClient client;
  http.begin(client, host);
  String payload = http.getString();
  int httpCode = http.GET();
  if(httpCode == 200)
  {
    const size_t capacity = JSON_OBJECT_SIZE(15);
    DynamicJsonBuffer jsonBuffer(capacity);
    JsonObject& root = jsonBuffer.parseObject(payload);
    if (!root.success()) 
    {
      Serial.println(F("Parsing failed!"));
      return;
    }
    Serial.print(F("Datetime:"));
    String datetime = String(root["datetime"].as<char*>());
    Serial.println(String(datetime));
    api_jam = String(datetime.charAt(11)) + String(datetime.charAt(12));
    api_menit = String(datetime.charAt(14)) + String(datetime.charAt(15));
    api_jam_menit = api_jam + ":" + api_menit;
    lcd.setCursor(0,0);
    lcd.println("H: " + api_jam + ":" + api_menit);    
    
  }
  else 
  {
    Serial.println("Error in response");
  }
  if(api_jam == waktu1)
  {
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(0, 0);
    lcd.println("waktunya minum obat");
    lcd.setCursor(0, 1);
    lcd.println("obat dikotak 1");

    if (sd1 < 1)
    {
      myBot.sendMessage(id, "paracteamol telah diambil");
      digitalWrite(buzzer, LOW);
    }
  }
  else if(api_jam == waktu2)
  {
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(0, 0);
    lcd.println("waktunya minum obat");
    lcd.setCursor(0, 1);
    lcd.println("obat dikotak 2");
    if (sd2 < 1)
    {
      myBot.sendMessage(id, "oskadon telah diambil");
      digitalWrite(buzzer, LOW);
    }
  }
  http.end();
}
