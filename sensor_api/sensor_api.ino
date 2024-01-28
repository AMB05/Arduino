    int pinSensor = A1;
    int pinBuzzer = 12;
    void setup() {
      Serial.begin(9600);
      pinMode(pinSensor, INPUT);
      pinMode(pinBuzzer, OUTPUT);
    }
    void loop() {
      int nilai = analogRead(pinSensor);
      Serial.println(nilai);
      if (nilai < 100) {
        digitalWrite(pinBuzzer, HIGH);
        Serial.println("Api terdeteksi");
      } else {
        digitalWrite(pinBuzzer, LOW);
        Serial.println("tidak ada api");
      }
      delay(500);
    }
