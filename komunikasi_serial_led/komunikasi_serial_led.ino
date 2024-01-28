boolean i = true;
boolean j = true;
boolean k = true;

void setup() 
{
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
}

void loop() 
{
if (Serial.available()>0)
  {
    char data = Serial.read();
    if (data == 'A') 
    {
      Serial.print('#');
      Serial.println("Perintah [A] Diterima");
      
      
      if(i==true) 
      {
        digitalWrite(A0, HIGH);
        Serial.println("LAMPU NYALA");
        i = false;
      }
      else
      {
        digitalWrite(A0, LOW);
        Serial.println("LAMPU MATI");
        i = true;
      }
      Serial.print('/');
    }
    else if (data == 'B') 
    {
      Serial.print('#');
      Serial.println("Perintah [B] Diterima");
      
      if(j==true) 
      {
        digitalWrite(A1, HIGH);
        Serial.println("LAMPU NYALA");
        j = false;
      }
      else
      {
        digitalWrite(A1, LOW);
        Serial.println("LAMPU MATI");
        j = true;
      }
      Serial.print('/');
    }
    else if (data == 'C') 
    {
      Serial.print('#');
      Serial.println("Perintah [C] Diterima");
      
      if(k==true) 
      {
        digitalWrite(A2, HIGH);
        Serial.println("LAMPU NYALA");
        k = false;
      }
      else
      {
        digitalWrite(A2, LOW);
        Serial.println("LAMPU MATI");
        k = true;
      }
      Serial.print('/');
    }
    else Serial.println("Perintah Tidak Dikenali");
  }
}
