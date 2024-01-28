#include <ESP8266WiFi.h> 
#include <DHT.h>
#define DHTPIN D7 //Pin data dari DHT terhubung ke pin D7 NodeMCU
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Baca DHT11");
  dht.begin();
}

void loop() {
  delay(1000); //1 detik
  float h = dht.readHumidity(); //Membaca kelembaban
  float t = dht.readTemperature(); //Membaca suhu dalam satuan Celcius
  float f = dht.readTemperature(true); //Membaca suhu dalam satuan Fahrenheit
  Serial.print("Kelembaban: ");
  Serial.print(h);
  Serial.print("% RH ");
  Serial.print("Suhu: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.println(" *F");
}
