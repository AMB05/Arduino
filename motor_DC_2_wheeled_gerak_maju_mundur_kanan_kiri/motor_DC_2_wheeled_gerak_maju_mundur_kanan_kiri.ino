//pin arduino kemodule L298N
#define enA 7
#define in1 6
#define in2 5
#define in3 4
#define in4 3
#define enB 2

//tomboll kontrol (pengendali)
#define btn_kiri      9
#define btn_kanan     10
#define btn_mundur    11
#define btn_maju      12
#define btn_stop      13

//nilai pwm (kecepatan)
int kecepatan = 255;

void setup() 
{
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);

  pinMode(btn_maju,   INPUT_PULLUP);
  pinMode(btn_mundur, INPUT_PULLUP);
  pinMode(btn_kiri,   INPUT_PULLUP);
  pinMode(btn_kanan,  INPUT_PULLUP);
  pinMode(btn_stop,   INPUT_PULLUP);
}

void loop() 
{
  //TOMBOL MAJU DITEKAN
  if(!digitalRead(btn_maju))
  {
    motor_maju();
  }

  //TOMBOL MUNDUR DITEKAN
  if(!digitalRead(btn_mundur))
  {
    motor_mundur();
  }

  //TOMBOL BELOK KIRI DITEKAN
  if(!digitalRead(btn_kiri))
  {
    motor_belok_kiri();
  }

  //TOMBOL BELOK KANAN DITEKAN
  if(!digitalRead(btn_kanan))
  {
    motor_belok_kanan();
  }

  //TOMBOL STOP DITEKAN
  if(!digitalRead(btn_stop))
  {
    motor_stop();
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
