#include <LM35.h>

LM35 suhu (A0);

void setup() 
{
 Serial.begin(9600);

}

void loop() 
{
  if(Serial.available()>0)
  {
    char cmd = Serial.read();
    if(cmd == 'A')
    {
      int t = suhu.cel();
      Serial.print('*');
      Serial.print(t);
      Serial.print('#');
    }
  }

}
