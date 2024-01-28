#define trig_pin 11 // pin trigger
#define echo_pin 10 // pin echo

int IR = 3; // pin inframerah
int LED_1= 2;
int LED_2= 12;

void setup() 
{
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(IR, INPUT);
  pinMode(LED_2,  OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  // inframerah
  int x = digitalRead(IR);
  if (x == HIGH)
  {
    digitalWrite(LED_1, HIGH);
    Serial.println("Terdeteksi Sesuatu");
  }
  else if (x == LOW)
  {
    digitalWrite(LED_1, LOW);
    Serial.println("Ruangan Kosong");
  }
  delay(250);

  // ultrasonic
  long duration, distance;
  
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  
  duration = pulseIn(echo_pin, HIGH);
  distance = (duration/2) / 588.10;
  
  if (distance >= 30)
  {
    digitalWrite(LED_2, HIGH);
  }
  else
  {
    digitalWrite(LED_2, LOW);
  }
    
  Serial.print("Jarak :");
  Serial.print(distance);
  Serial.println("cm");
  delay(250);

}
