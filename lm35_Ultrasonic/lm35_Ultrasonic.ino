#define trig  7
#define eco  6
#define led1  A5
#define led2  3

float temp =  A0;
float in;

long duration, distance;

void setup() 
{
  Serial.begin(9600);
  pinMode (A0, INPUT);
  pinMode (7, OUTPUT);
  pinMode (6, INPUT);
  pinMode (A5, OUTPUT);
  pinMode (3, OUTPUT);
}

void loop() 
{
  if (Serial.available()>0)
  {
    int dataIn = Serial.read();
    if (dataIn == '*')
    {
      temperature();
      digitalWrite(led1, HIGH);
    }
    if (dataIn == '&')
    {
      ultrasonic();
      
    }
  }
}

void temperature ()
{
  in = analogRead(A0);
  in = in * 0.48828125;

  Serial.print('#');
  Serial.print(in);
  Serial.println('/');

  delay(1000);
}

void ultrasonic ()
{
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
