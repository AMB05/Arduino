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
int pulse;
float rps, rpm;

void setup() 
{
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

unsigned long timelast;


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
     
    if (millis() - timelast >= 500)
    {
      timelast = millis();
      rps = pulse / 650.00/0.5;
      rpm = rps*60;
      Serial.print("Pulse :");
      Serial.print(pulse);
      Serial.print("\t");
      Serial.print("RPS :");
      Serial.print(rps);
      Serial.print("\t");
      Serial.print("RPM :");
      Serial.println(rpm);
    
      pulse = 0;
    }
  }

  //tombol stop ditekan
  if (!digitalRead(btn_stop)) 
  {
    //kecepatan=0
    analogWrite (enA, 0);
    analogWrite (enB, 0);
  }

}
