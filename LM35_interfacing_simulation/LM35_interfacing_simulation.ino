float temp =  A0;
float in;

void setup() 
{
  Serial.begin(9600);
  pinMode (A0, INPUT);
}

void loop() 
{
  if (Serial.available()>0)
  {
    int dataIn = Serial.read();
    if (dataIn == '*')
    {
      temperature();
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
}
