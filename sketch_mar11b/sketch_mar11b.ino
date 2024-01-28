// inialisasi pin sensor dan alarm/buzzer
const int pinApi = 8; //pin api
const int pinAlarm = 9; //pin buzzer
const int smokeA0 = A5; // pin asap

// inialisasi variabel data
int data;
int dataAsap;

//Nilai threshold
int sensorThres = 100;

void setup()
{
 // inialisasi status I/O pin
 pinMode(pinApi, INPUT); // pin sebagai input
 pinMode(smokeA0, INPUT); // pin sebagai input
 pinMode(pinAlarm, OUTPUT); // pin sebagai output
 Serial.begin(9600);
}

void loop()
{
 // variabel data adalah hasil dari pembacaan sensor
 // berupa logic LOW/HIGH
 data = digitalRead(pinApi); //pembacaan sensor api
 int analogSensor = analogRead(smokeA0); //pembacaa sensor asap
 
 Serial.println(analogSensor);


 // jika data pada sensor API bernilai logic LOW
 if (data == LOW)
 {
   // alarm dinyalakan
   Serial.println("API TERDETEKSI"); //tampilan jika terdeteksi api
   digitalWrite(pinAlarm, HIGH); //alarm
   delay(5000); //delay 5 detik
 }

// jika data Analog pada sensor Asap lebih besar dari batas
 else if (analogSensor > sensorThres)
  {
    // alarm dinyalakan
    Serial.println("ASAP TERDETEKSI"); //tampilan jika terdeteksi asap
    tone(pinAlarm, 100, 200); //alarm
    delay(5000); //delay 5 detik
     
  }

 // jika data tidak bernilai logic LOW
 else
 {
  
   // alarm dimatikan
   digitalWrite(pinAlarm, LOW);
   delay(5000); //delay 5 detik
 }
}
