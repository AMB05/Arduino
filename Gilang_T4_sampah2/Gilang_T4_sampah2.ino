#include <Servo.h>
#define trig_pin 11
#define echo_pin 10

Servo myservo;
int pos = 0;

void setup() 
{
  myservo.attach(7);
  myservo.write(0);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  long duration, distance;
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(8);
  digitalWrite(trig_pin, LOW);

  duration = pulseIn(echo_pin, HIGH);
  distance = (duration/2) / 588.10;

  if(distance <= 10)
  {
    myservo.write(90);
    
  }
  else
  {
    myservo.write(0);
    
  }
  Serial.println("Jarak : ");
  Serial.print(distance);
  Serial.println("cm");
  delay(250);
}
