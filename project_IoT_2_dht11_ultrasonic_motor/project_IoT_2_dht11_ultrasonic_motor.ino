//l298n
#define enA 10
#define in1 9
#define in2 8
int kecepatan = 255;

//dht11
#include "DHT.h"
#define DHTPIN 3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

//hcsr-04
#define trig_pin 13
#define echo_pin 12

//uln2003A
int A=7; 
int B=6;
int C=5;
int D=4; 

void setup(){
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  dht.begin();
  
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
    
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

  pinMode(A, OUTPUT); pinMode(B, OUTPUT);
  pinMode(C, OUTPUT); pinMode(D, OUTPUT);
}

void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  if ( isnan(t) <=36 && isnan(h) >=40 && isnan(h) <=60)
  {
     analogWrite(enA, kecepatan);
     digitalWrite(in1,LOW);
     digitalWrite(in2,LOW);
  }
  else
  {
     analogWrite(enA, kecepatan);
     digitalWrite(in1,HIGH);
     digitalWrite(in2,LOW);
  }

  long duration, distance;
  
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  
  duration = pulseIn(echo_pin, HIGH);
  distance = (duration/2) / 588.10;
  
  if (distance <= 20)
  {
    digitalWrite(A,1); 
    digitalWrite(D,00);
    digitalWrite(B,1);
    digitalWrite(C,00);
  }
  else
  {
    digitalWrite(A,00); 
    digitalWrite(D,1);
    digitalWrite(B,00);
    digitalWrite(C,1);
  }
}
