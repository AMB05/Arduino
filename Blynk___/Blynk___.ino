#define BLYNK_TEMPLATE_ID           "project1"
#define BLYNK_DEVICE_NAME           "project1"
#define BLYNK_AUTH_TOKEN            "d27UXH8GYEPDob4g1YoEU3_cM3-eteDY"
#define trig  7
#define eco  6
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
float temp =  A0;
float in;
long duration, distance;
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Redmi2";
char pass[] = "Rodhiyah2";

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); 
   digitalWrite(trig, LOW);
      delayMicroseconds(2);
      digitalWrite(trig, HIGH);
      delayMicroseconds(10);
      digitalWrite(trig, LOW);
      
      duration = pulseIn(eco, HIGH);
      distance = (duration/2) / 29.1;
      if (distance >= 50) 
      {
        digitalWrite(led2, HIGH);
      }

      Serial.print('#');
      Serial.print(distance);
      Serial.println('/');
  
}

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
