//pin arduino ke module L298N
#define enA 9
#define in1 8
#define in2 7
#define in3 6
#define in4 5
#define enB 4

//pin button
#define btn_mulai 3
#define btn_stop 2

//pin module ULN2003A
#define A 13
#define B 12
#define C 11
#define D 10

//nilai PWM
int kecepatan = 255;

void setup() 
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);

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
  pergerakan_1();
  delay(1000);
  pergerakan_2();
  delay(1000);
  pergerakan_3();
  delay(1000);
  pergerakan_4();
  delay(1000);
}

void loop() 
{
  //mulai
  if(!digitalRead(btn_mulai))
  {
    analogWrite(enA, kecepatan);
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    analogWrite(enB,kecepatan);
  }

  //stop
  if(!digitalRead(btn_stop))
  {
    analogWrite(enA,0);
    analogWrite(enB,0);
  }
  
  pergerakan();
}
