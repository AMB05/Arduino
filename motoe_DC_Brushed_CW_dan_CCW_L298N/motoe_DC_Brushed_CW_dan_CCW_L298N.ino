//pin arduino ke module L298N
#define enA 9
#define in1 8
#define in2 7
#define in3 6
#define in4 5
#define enB 4

//tombol kontrol
#define btn_bkwd    3
#define btn_stop    2

//nilai pwm (kecepatan putar)
int kecepatan=255;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
  
  pinMode(btn_bkwd, INPUT_PULLUP);
  pinMode(btn_stop, INPUT_PULLUP);
  motor_stop();
  delay(500);
}

void loop() {
  //tombol mundur ditekan
  if(!digitalRead(btn_bkwd)) {
    motor_mundur();
  }

  //tombol stop ditekan
  if (!digitalRead(btn_stop)) {
    motor_stop();
  }
}

void motor_mundur(){
  analogWrite (enA, kecepatan);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite (enB, kecepatan);
}
void motor_stop(){
  //kecepatan=0
  analogWrite (enA, 0);
  analogWrite (enB, 0);
}
