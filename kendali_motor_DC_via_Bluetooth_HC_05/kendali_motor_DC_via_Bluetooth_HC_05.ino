//pin arduino ke module L298N
#define enA 7
#define in1 6
#define in2 5
#define in3 4
#define in4 3
#define enB 2

//tombol kontrol
#define btn_lwd     9
#define btn_rwd     10
#define btn_bkwd    11
#define btn_fwd     12
#define btn_stop    13

//nilai pwm (kecepatan putar)
int kecepatan=255;

void setup() 
{
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
    
  pinMode(btn_fwd,  INPUT_PULLUP);
  pinMode(btn_bkwd, INPUT_PULLUP);
  pinMode(btn_lwd,  INPUT_PULLUP);
  pinMode(btn_rwd,  INPUT_PULLUP);
  pinMode(btn_stop, INPUT_PULLUP);
}

void loop() 
{
  //tombol maju ditekan
  if(!digitalRead(btn_fwd))
  {
    motor_maju();
  }

  //tombol mundur ditekan
  if(!digitalRead(btn_bkwd)) 
  {
    motor_mundur();
  }

  //tombol belok kiri
  if(!digitalRead(btn_lwd))
  {
    motor_belok_kiri();
  }

  //tombol belok kanan
  if(!digitalRead(btn_rwd))
  {
    motor_belom_kanan();
  }

  //tombol stop ditekan
  if (!digitalRead(btn_stop)) 
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
void motor_belom_kanan()
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
