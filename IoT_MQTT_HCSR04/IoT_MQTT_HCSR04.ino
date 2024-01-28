#define trig_pin 4 // pin trigger
#define echo_pin 5 // pin echo
long duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

}

void loop() {
  if(Serial.available()>0)
  {
    char cmd = Serial.read();
    if(cmd == 'A')
    {
      digitalWrite(trig_pin, LOW);
      delayMicroseconds(2);
      digitalWrite(trig_pin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trig_pin, LOW);
      
      duration = pulseIn(echo_pin, HIGH);
      distance = (duration/2) / 588.10;
      Serial.print(distance);
      Serial.println(" cm");
    }
  }
}
