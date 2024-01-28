//pin arduino ke module L298N
#define enA 9
#define in1 8
#define in2 7
#define in3 6
#define in4 5
#define enB 4

//tombol kontrol
int btn_mulai=3;
int btn_stop =2;

//nilai pwm (kecepatan putar)
int kecepatan=255;

//pin modul ULN2003A
#define A 13
#define B 12
#define C 11
#define D 10

void setup() 
{
  pinMode(A,OUTPUT); 
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT); 
  pinMode(D,OUTPUT);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
  
  pinMode(btn_mulai, INPUT_PULLUP);
  pinMode(btn_stop, INPUT_PULLUP);
  
  delay(500);
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

void pergerakan()
{
//pergerakan dari 00, 90', 180', 270', 360'
  pergerakan_1(); delay(1000);  //90'
  pergerakan_2(); delay(1000);  //180'
  pergerakan_3(); delay(1000);  //270'
  pergerakan_4(); delay(1000);  //360'
}

void loop() 
{
  //tombol mulai ditekan
  if(!digitalRead(btn_mulai)) 
  {
    analogWrite (enA, kecepatan);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite (enB, kecepatan);
  }

  //tombol stop ditekan
  if (!digitalRead(btn_stop)) 
  {
    //kecepatan=0
    analogWrite (enA, 0);
    analogWrite (enB, 0);
  }

  pergerakan();
}
