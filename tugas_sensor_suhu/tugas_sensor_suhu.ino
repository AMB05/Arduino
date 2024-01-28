int analogPin = A0;
float suhu = 00;
int suhu1=00;

void setup() {
  Serial.begin (9600);

}

void loop() {
  suhu1 = analogRead(analogPin);
  suhu = suhu1 / 2.0479;

  Serial.println(suhu);
  delay(50);

}
