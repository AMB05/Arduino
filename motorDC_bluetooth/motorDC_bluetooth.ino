// motor A 
int enA = 7; 
int in1 = 6; 
int in2 = 5; 

// motor B 
int in3 = 4; 
int in4 = 3; 
int enB = 2;

int kecepatan = 255; 

String data;

//led 
int led_1 = 13;
int led_2 = 12;
int led_3 = 11;
int led_4 = 10;

void setup() 
{
  Serial.begin(9600);
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
  Serial.println("Kode Perintah");
  Serial.println("W = Maju");
  Serial.println("S = Mundur");
  Serial.println("D = Kanan");
  Serial.println("A = Kiri");
  Serial.println("X = Berhenti");
  while(Serial.available()==0){
  
    data = Serial.readString();
    if(data == 'W') // maju
    { 
      motor_maju();
      
    }
    delay(1000);
     
    if(data == 'D') // KANAN 
    { 
      motor_kanan();
    } 
    delay(1000);
    
    if(data == 'A') // KIRI 
    {
      motor_kiri();
    } 
    delay(1000);
    
    if(data == 'S') // MUNDUR 
    {
      motor_mundur();
    } 
    delay(1000);
    
    if(data == 'X') //STOP 
    {
      berhenti();
    }
    delay(1000);
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

  digitalWrite(led_1, HIGH); 
  digitalWrite(led_2, LOW); 
  digitalWrite(led_3, LOW); 
  digitalWrite(led_4, LOW); 
}

void motor_mundur()
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

void motor_kiri()
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

void motor_kanan()
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

void berhenti()
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
