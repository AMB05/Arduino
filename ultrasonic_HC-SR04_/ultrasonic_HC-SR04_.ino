#define led 3
#define trig_pin 7
#define echo_pin 6

void setup() 
{
  Serial.begin (9600);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(led, OUTPUT);
}
void loop() 
{
  long duration, distance;
  
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  
  duration = pulseIn(echo_pin, HIGH);
  distance = (duration/2) / 588.10;
  
  if (distance >= 30)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
    
  Serial.print("Jarak :");
  Serial.print(distance);
  Serial.println("cm");
  delay(250);
}
