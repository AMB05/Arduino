#define dirA 7
#define pwmA 6
#define dirB 4
#define pwmB 5

int pulse;
float rps, rpm;


void motor_run(int mA, int mB){
  if (mA >= 0){
  digitalWrite (dirA, 0);
  analogWrite (pwmA, mA);
  }
  else if (mA < 0){
  digitalWrite (dirA, 1);
  analogWrite (pwmA,  mA+255);
  }
  
  if (mB >= 0){
  digitalWrite (dirB, 0);
  analogWrite (pwmB, mB);
  }
  else if (mB < 0){
  digitalWrite (dirB, 1);
  analogWrite (pwmB,  mB+255);
  }
}

void setup(){
  Serial.begin(9600);
  pinMode (dirA, OUTPUT);
  pinMode (dirB, OUTPUT);
  pinMode (2, INPUT_PULLUP);
  pinMode (3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), encoder, CHANGE);
  
}
unsigned long timelast;

void loop(){
  motor_run(0, analogRead(A0)/4);
  if (millis() - timelast >= 500){
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

void encoder(){
  if (digitalRead (2) == digitalRead(3)){
  pulse ++;
  }
  else {
  pulse --;
  }
}
