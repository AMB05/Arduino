#include <NewPing.h>
#include <Servo.h>

#define TRIGGER_PIN 7
#define ECHO_PIN    6
#define MAX_DISTANCE 100
Servo myservo;
NewPing sonar (TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  delay(5000);
  Serial.print("jarak = ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");
  myservo.write(0);

  if (sonar.ping_cm()>0&&sonar.ping_cm()<50)
  {
    Serial.println("BUKA PINTU DAN BUANG SAMPAH SESUAI TEMPATNYA");
    myservo.write(180);
    delay(1000);
  }
}
