#include "math.h"
#include "DHT.h"
#include "string.h"

#define kpa2atm 0.00986923267
#define DHTPIN 11
#define DHTTYPE DHT11

int LDR = A1;
DHT dht(DHTPIN, DHTTYPE);
int pressurePin = A0;
int val;
float pkPa; // pressure in kPa

void setup()
{
  Serial.begin(9600);
  dht.begin();
  pinMode(LDR, INPUT);
}

void loop()
{
  if (Serial.available() > 0) {
    int dataIn = Serial.read();

    switch (dataIn) {
      case '*':
        baca_sensor(); 
        break;
    }
    }
}

void baca_sensor() {
  val = analogRead(pressurePin);
  pkPa = ((float)val / (float)1023 + 0.095) / 0.009;

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  int vout1 = analogRead(LDR);
  float vout = vout1 / 204.6;
  float R = (11000 - vout * 2200) / vout;
  float lux = (pow( R, (1 / -0.8616))) / (pow( 10, (5.118 / -0.8616))); //lux calculation

  Serial.print("*");
  Serial.print(pkPa,1);Serial.print(" ");
  Serial.print(h,1);Serial.print(" ");
  Serial.print(t,1);Serial.print(" ");
  Serial.print(lux,1);
  Serial.println("#");
}
