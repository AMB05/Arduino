//Alarm Kebakaran dengan Flame Sensor
const int pinSensor = 3;         //inisialisasi pin sensor
const int inA       = 9;         //inisialisasi pin INA di fan motor
const int inB       = 8;         //inisialisasi pin INB di fan motor
const int pinSpeker = 12;        //inisialisasi pin speker
const int ledRed    = 13;        //inisialisasi pin LED

void setup() {
Serial.begin (9600);             //program menyalakan serial monitor
pinMode (pinSensor, INPUT);      //menetapkan pin 3 sebagai input
pinMode (inA, OUTPUT);           //menetapkan pin 9 sebagai output
pinMode (inB, OUTPUT);           //menetapkan pin 8 sebagai output
pinMode (pinSpeker, OUTPUT);     //menetapkan pin 12 sebagai output
pinMode (ledRed, OUTPUT);        //menetapkan pin 13 sebagai output
}

void loop() {
//Membaca data dari pin yang dihubungkan ke sensor
int dataDigital = digitalRead (pinSensor);

//Program ketika sensor mendeteksi api
if (dataDigital == 1) {
  Serial.println ("Mendeteksi Api");
  digitalWrite (inA, HIGH);
  digitalWrite (inB, LOW);

  //program untuk menyalakan sirine
  // matikan LED
  digitalWrite( ledRed, LOW );
  // mainkan nada di pin#8 dg. frekuensi 261Hz selama 500 ms
  tone( pinSpeker, 261 );
  delay( 500 );
  // nyalakan LED
  digitalWrite( ledRed, HIGH );
  // mainkan nada di pin#8 dg. frekuensi 392Hz selama 500 ms
  tone( pinSpeker, 392 );
  delay( 500 );
}

//Program ketika sensor tidak mendeteksi api
else if (dataDigital == 0) {
  Serial.println ("Tidak Ada Api");
  noTone(pinSpeker);
  digitalWrite (inA, LOW);
  digitalWrite (inB, LOW);
  digitalWrite (ledRed, LOW);
}
}
