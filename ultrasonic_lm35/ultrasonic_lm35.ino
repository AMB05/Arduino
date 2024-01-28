#define led1 3
#define led2 4
#define led3 5
#define led4 A5
#define lm35 A0
#define trigPin 7
#define echoPin 6

long duration, distance;
int baca_sensor;
float suhu; 

void setup() 
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() 
{
  int dataIn = Serial.read();
  if (dataIn == '*')
  {
     baca_sensor = analogRead(lm35); // membaca nilai adc
     suhu = baca_sensor * 0.48828125;
     if ( suhu >=36)
     {
       digitalWrite(led4, HIGH);
     }
     else
     {
       digitalWrite(led4, LOW);
     }

     Serial.print('#');
     Serial.print(suhu);
     Serial.println('/');
  }
  else if (dataIn == '&')
  {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance = (duration/2) / 29.1;
      
      if (distance >= 50) 
      {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW); 
        digitalWrite(led3, LOW); 
        
      }
      if (distance >= 30 && distance <=49) 
      {
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, LOW);
        
      }
      if (distance <= 29) 
      {
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
        
      }

      Serial.println('$');
      Serial.println(distance);
      Serial.println('@');
  }
    
  delay(1000);
}
