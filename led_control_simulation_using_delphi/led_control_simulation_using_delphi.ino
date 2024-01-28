int led_a = 6; //deklarasi variabel led
int led_b = 7; //deklarasi variabel led
int data;

void setup() 
{
 //konfigurasi Baud Rate untuk Komunikasi Data Serial
 Serial.begin(9600);
 pinMode (led_a, OUTPUT);
 pinMode (led_b, OUTPUT);
}

void loop() 
{
 //membaca komunikasi serial
 if(Serial.available()>0)
 {
    data = Serial.read();
        if (data == 'a')
          {
            digitalWrite(led_a, HIGH); 
          }
        else if (data == 's')
          {
            digitalWrite(led_a, LOW);
          }
        else {}

       if (data == 'z')
       {
        digitalWrite(led_b, HIGH);
       }
       else if (data == 'x')
       {
        digitalWrite(led_b,LOW);
       }
      else {}
  }
}
