    #include <ESP8266WiFi.h>
    #include "DHT.h"
    #define DHTTYPE DHT11
    const char* ssid = "CONNECT";
    const char* password = "PASSWORD";
    WiFiServer server(80);
    #define DHTPin 1
    DHT dht(DHTPin, DHTTYPE);
    void setup() {
      Serial.begin(9600);
      delay(20);
      dht.begin();
      Serial.println();
      Serial.print("Menghubungkan ke WIFI... ");
      Serial.println(ssid);
      WiFi.begin(ssid, password);
      while (WiFi.status() != WL_CONNECTED){ 
        delay(300);
        Serial.print(".");
      }
      Serial.println("");
      Serial.println("WiFi terkoneksi");
      server.begin();
      Serial.println("Koneksi Server dimulai");
      Serial.print("Alamat IP : ");
      Serial.print("http://");
      Serial.print(WiFi.localIP());
      Serial.println("/");
    }
    void loop() {
      WiFiClient client = server.available();
      if (!client) {
        return;
      }
      Serial.println("Koneksi baru");
      while (!client.available())
      {
        delay(5);
      }
      if (client) {
        boolean blank_line = true;
        while (client.connected()) {
          if (client.available()) {
            char c = client.read();
            if (c == '\n' && blank_line) {
              float h = dht.readHumidity();
              float t = dht.readTemperature();
              float f = dht.readTemperature(true);
              if (isnan(h) || isnan(t) || isnan(f)) {
                Serial.println("Failed to read from DHT sensor!");
              }
              else {
                Serial.print("Kelembaban : ");
                Serial.print(h);
                Serial.println("%");
                Serial.print("Suhu : ");
                Serial.print(t);
                Serial.print(" *C ");
                Serial.println(f);
              }
         
              client.println("HTTP/1.1 200 OK");
              client.println("Content-Type: text/html");
              client.println("Connection: close");
              client.println();
              client.println("<!DOCTYPE HTML>");
              client.println("<html>");
              client.println("<head></head><body><h2>Monitoring Sensor DHT11</h2><h3>Suhu Celcius : ");
              client.println(t);
              client.println("*C</h3><h3>Suhu Fahrenheit : ");
              client.println(f);
              client.println("*F</h3><h3>Kelembaban : ");
              client.println(h);
              client.println("%</h3><h3>");
              client.println("</body></html>");
              break;
            }
            if (c == '\n') {
              blank_line = true;
            }
            else if (c != '\r') {
              blank_line = false;
            }
          }
        }
        delay(5);
      }
    }
