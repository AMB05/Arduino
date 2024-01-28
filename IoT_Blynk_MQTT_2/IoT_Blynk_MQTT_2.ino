#include <LM35.h>
LM35 suhu(A2);
#define trig_pin 8 // pin trigger
#define echo_pin 9 // pin echo
int A=4; 
int B=5;
int C=6;
int D=7; 
long duration, distance;
void setup()
{
  Serial.begin(9600);
  pinMode(A2, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(A,OUTPUT); pinMode(B,OUTPUT);
  pinMode(C,OUTPUT); pinMode(D,OUTPUT);
}

void pergerakan_1()
{
  digitalWrite(A,1); 
  digitalWrite(D,00);
  digitalWrite(B,1);
  digitalWrite(C,00); 
}
 
void pergerakan_2()
{
  digitalWrite(A,00); 
  digitalWrite(D,00);
  digitalWrite(B,1);
  digitalWrite(C,1); 
}
 
void pergerakan_3()
{
  digitalWrite(A,00); 
  digitalWrite(D,1);
  digitalWrite(B,00);
  digitalWrite(C,1);
}
 
void pergerakan_4()
{
  digitalWrite(A,1); 
  digitalWrite(D,1);
  digitalWrite(B,00);
  digitalWrite(C,00);
}
 
void loop()
{
  if(Serial.available()>0)
  {
    char cmd = Serial.read();
    if(cmd == 'A')
    {
     float in = analogRead(A2);
     in = in * 0.48828125;
      Serial.println(in);
    }
    else if (cmd == 'b')
    {
      digitalWrite(2, LOW);
    }
    else if (cmd == 'B')
    {
      digitalWrite(2, HIGH);
    }
    else if (cmd == 'c')
    {
      digitalWrite(3, LOW);
    }
    else if (cmd == 'C')
    {
      digitalWrite(3, HIGH);
    }
    else if (cmd == 'D')
    {
      pergerakan_1();
    }
    else if (cmd == 'd')
    {
      pergerakan_2();
    }
     else if (cmd == 'E')
    {
      pergerakan_3();
    }
    else if (cmd == 'e')
    {
      pergerakan_4();
    }

    
  }
}
