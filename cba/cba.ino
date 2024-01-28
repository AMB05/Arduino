int m1 = A0;
int h = 255;
int i = 0;
String motion;

void setup() 
{
  Serial.begin(9600);
  pinMode(m1, OUTPUT);
  analogWrite(m1, h);
}

void loop() 
{
  while(Serial.available()== 0)
  {
    motion = Serial.readString();
    if(motion == "p")
    {
      analogWrite(m1, i);
    }
    if (motion == "s")
    {
      analogWrite(m1, h);
    }
  }
}
