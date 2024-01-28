#include <SoftwareSerial.h> 

// motor A 
int enA = 7; 
int in1 = 6; 
int in2 = 5; 

// motor B 
int in3 = 4; 
int in4 = 3; 
int enB = 2;

int kecepatan = 255; 

//led 
int led_1 = 13;
int led_2 = 12;
int led_3 = 11;
int led_4 = 10;

String data; 
 
SoftwareSerial mySerial(A1, A0); // RX, TX 

void setup() { 
  mySerial.begin(9600); // Untuk Serial Bluetooth // Serial.begin(9600); // Untuk Serial Biasa 
  pinMode(enA, OUTPUT);  
  pinMode(enB, OUTPUT);  
  pinMode(in1, OUTPUT);  
  pinMode(in2, OUTPUT);  
  pinMode(in3, OUTPUT);  
  pinMode(in4, OUTPUT);

  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT); 
}

void loop() 
{ 
  // kita harus memperhatikan dari mana data yang dikirimkan 
  // menggunakan "Serial" jika dari Arduino biasa 
  // menggunakan "mySerial" jika dari bluetooth 
  while (mySerial.available() == 0) 
  {
    data = mySerial.readString(); // Membaca data yang dikirim dari processing 
    if(data == 'W') // maju
    { 
      analogWrite (enA, kecepatan);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite (enB, kecepatan);

      digitalWrite(led_1, HIGH); 
      digitalWrite(led_2, LOW); 
      digitalWrite(led_3, LOW); 
      digitalWrite(led_4, LOW); 
    } 
    if(data == 'D') // KANAN 
    { 
      analogWrite (enA, kecepatan);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite (enB, kecepatan);
      
      digitalWrite(led_1, LOW); 
      digitalWrite(led_2, LOW); 
      digitalWrite(led_3, HIGH); 
      digitalWrite(led_4, LOW); 
    } 
    if(data == 'A') // KIRI 
    {
      analogWrite (enA, kecepatan);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite (enB, kecepatan);
      
      digitalWrite(led_1, LOW); 
      digitalWrite(led_2, HIGH); 
      digitalWrite(led_3, LOW); 
      digitalWrite(led_4, LOW); 
    } 
    if(data == 'S') // MUNDUR 
    {
      analogWrite (enA, kecepatan);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite (enB, kecepatan);
      
      digitalWrite(led_1, LOW); 
      digitalWrite(led_2, LOW); 
      digitalWrite(led_3, LOW); 
      digitalWrite(led_4, HIGH); 
    } 
    if(data == 'X') //STOP 
    {
      analogWrite (enA, kecepatan);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      analogWrite (enB, kecepatan);

      digitalWrite(led_1, HIGH); 
      digitalWrite(led_2, HIGH); 
      digitalWrite(led_3, HIGH); 
      digitalWrite(led_4, HIGH); 
    }
  }
}
