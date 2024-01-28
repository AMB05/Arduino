#define enA 7
#define in1 6
#define in2 5
#define in3 4
#define in4 3
#define enB 2
int kecepatan = 255;

#define lm35 A0
long duration, distance;
int baca_sensor;
float suhu;

void setup() {
  Serial.begin (9600);
  
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);

}

void loop() {
     baca_sensor = analogRead(lm35); // membaca nilai adc
     suhu = baca_sensor * 0.48828125;
     if ( suhu >=36)
     {
        analogWrite(enA, kecepatan);
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        digitalWrite(in3,HIGH);
        digitalWrite(in4,LOW);
        analogWrite(enB,kecepatan);
     }
     else
     {
        analogWrite(enA, kecepatan);
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        digitalWrite(in3,LOW);
        digitalWrite(in4,LOW);
        analogWrite(enB,kecepatan);
     }
}
