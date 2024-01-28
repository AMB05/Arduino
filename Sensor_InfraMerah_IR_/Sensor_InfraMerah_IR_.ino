#define sensorIR 2
#define led 13

void setup() {
  Serial.begin(9600);
  pinMode(sensorIR, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  int nilaiBacasensor;
  nilaiBacasensor = digitalRead(sensorIR);
  Serial.println(nilaiBacasensor);
  delay(250);
  

}
