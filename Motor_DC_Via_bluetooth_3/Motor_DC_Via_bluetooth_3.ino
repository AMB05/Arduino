// motor A 
#define enA  7 
#define in1  6 
#define in2  5 

// motor B 
#define in3  4 
#define in4  3 
#define enB  2

int Led_1 = 13;
int Led_2 = 12;
int Led_3 = 11;
int Led_4 = 10;

int kecepatan = 255; 
int data = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(enA, OUTPUT);  
  pinMode(enB, OUTPUT);  
  pinMode(in1, OUTPUT);  
  pinMode(in2, OUTPUT);  
  pinMode(in3, OUTPUT);  
  pinMode(in4, OUTPUT);

  pinMode(Led_1, OUTPUT);  
  pinMode(Led_2, OUTPUT);  
  pinMode(Led_3, OUTPUT);  
  pinMode(Led_4, OUTPUT);

  motor_stop();
  delay(1000);
  Serial.println("Kode Perintah ");
  Serial.println("F = Maju");
  Serial.println("B = Mundur");
  Serial.println("R = Kanan");
  Serial.println("L = Kiri");
  Serial.println("S = Berhenti");
  Serial.println("Masukan Perintah dibawah ini :");

}

void loop() 
{
  if(Serial.available()>0)
  {
    data=Serial.read();
  }
  if(!digitalRead(data == 'F'))
  {
    motor_maju();
    led_maju();
  }
  if(!digitalRead(data == 'B'))
  {
    motor_mundur();
    led_mundur();
  }
  if(!digitalRead(data == 'R'))
  {
    motor_belok_kanan();
    led_kanan();
  }
  if(!digitalRead(data == 'L'))
  {
    motor_belok_kiri();
    led_kiri();
  }
  if(!digitalRead(data == 'S'))
  {
    motor_stop();
    led_stop();
  }
}

void motor_maju()
{
  analogWrite (enA, kecepatan);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite (enB, kecepatan);
}

void motor_mundur()
{
  analogWrite (enA, kecepatan);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite (enB, kecepatan);
}

void motor_belok_kiri()
{
  analogWrite (enA, kecepatan);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite (enB, kecepatan);
}

void motor_belok_kanan()
{
  analogWrite (enA, kecepatan);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite (enB, kecepatan);
}

void motor_stop()
{
  analogWrite (enA, kecepatan);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite (enB, kecepatan);
}

void led_kanan()
{
  digitalWrite(Led_1, HIGH);
  digitalWrite(Led_2, LOW);
  digitalWrite(Led_3, LOW);
  digitalWrite(Led_4, LOW);
}
void led_kiri()
{
  digitalWrite(Led_1, LOW);
  digitalWrite(Led_2, HIGH);
  digitalWrite(Led_3, LOW);
  digitalWrite(Led_4, LOW);
}
void led_maju()
{
  digitalWrite(Led_1, LOW);
  digitalWrite(Led_2, LOW);
  digitalWrite(Led_3, HIGH);
  digitalWrite(Led_4, LOW);
}
void led_mundur()
{
  digitalWrite(Led_1, LOW);
  digitalWrite(Led_2, LOW);
  digitalWrite(Led_3, LOW);
  digitalWrite(Led_4, HIGH);
}
void led_stop()
{
  digitalWrite(Led_1, LOW);
  digitalWrite(Led_2, LOW);
  digitalWrite(Led_3, LOW);
  digitalWrite(Led_4, LOW);
}
