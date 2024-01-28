int pinReset = 11;

void setup() {
digitalWrite(pinReset,HIGH);
delay(200);

pinMode(pinReset,OUTPUT);
Serial.begin(9600);
Serial.println("Coba Reset");
delay(2000);
}

void loop(){
Serial.println("Reset");
delay(10);
digitalWrite(pinReset,LOW); //perintah reset
Serial.println("Umpamakan teks ini bagian erornya jadi tidak muncul");
}
