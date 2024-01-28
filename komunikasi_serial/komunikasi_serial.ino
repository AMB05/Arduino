void setup() 
{
  Serial.begin (9600);
}

void loop() 
{
  if(Serial.available()>0)
  {
    int x = Serial.read();
    if (x == '*')
    {
      Serial.print('#');
      Serial.print("Hello Word");
      Serial.print('/');
    }
  }
  
}
