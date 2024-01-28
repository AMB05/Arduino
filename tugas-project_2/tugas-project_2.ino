#include "WiFiEsp.h"
#include <SoftwareSerial.h>
#include "DHT.h"
  
char ssid[] = "****";        // Isi dengan nama profil Wifi
char pass[] = "********";            // password wifi
char server[] = "x.x.x.x";
 
long waktuMintaData = 1000; //minta data setiap 1000ms
 
#define pinFlame    A0
#define pinMQ       A1
#define pinDHT      A2
#define pinBuzzer   8
#define pinRelay    9
 
float setSuhu = 31.0;
 
String Respon = "";
long waktuMulai;
bool responDariServer = false;
bool prosesKirimDataKeServer = false;
  
WiFiEspClient client;
int status = WL_IDLE_STATUS;
 
SoftwareSerial wifi(2,3);
DHT dht(pinDHT, DHT11);
  
void setup()
{
  pinMode(pinFlame, INPUT_PULLUP);
  pinMode(pinMQ, INPUT_PULLUP);
  pinMode(pinDHT, INPUT_PULLUP);
  pinMode(pinBuzzer, OUTPUT);
  digitalWrite(pinRelay, HIGH);
  pinMode(pinRelay, OUTPUT);
 
  Serial.begin(115200);
  
  wifi.begin(115200);
  WiFi.init(&wifi);
  
  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue
    while (true);
  }
  
  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }
  
  // you're connected now, so print out the data
  Serial.println("You're connected to the network");
    
  printWifiStatus();
  dht.begin();
  waktuMulai = millis();
}
  
void loop()
{
  float suhu = dht.readTemperature();
//print status
  Serial.println();
  Serial.print("Api = ");
  Serial.println(digitalRead(pinFlame));
  Serial.print("Asap = ");
  Serial.println(digitalRead(pinMQ));
  Serial.print("suhu = ");
  Serial.println(suhu);
   
  if(!digitalRead(pinFlame) && !digitalRead(pinMQ) && (suhu < setSuhu))
  {
    digitalWrite(pinRelay, HIGH);
    digitalWrite(pinBuzzer, LOW);
     
  }
  if(digitalRead(pinFlame))
  {
    digitalWrite(pinRelay, LOW);
    digitalWrite(pinBuzzer, HIGH);
  }
  if(digitalRead(pinMQ))
  {
    digitalWrite(pinRelay, LOW);
    digitalWrite(pinBuzzer, HIGH);
  }
  if(suhu >= setSuhu)
  {
    digitalWrite(pinBuzzer, HIGH);
  }
  //kirim data
  if(waktuMintaData < millis() - waktuMulai)
  {
    waktuMulai = millis();
    prosesKirimDataKeServer = kirimDataKeServer();
  }
 
  while (client.available()) 
  {
    char c = client.read();
    Respon += c;
  }
 
  Serial.print("prosesKirimDataKeServer = ");
  Serial.println(prosesKirimDataKeServer);
 
  if (!client.connected() && prosesKirimDataKeServer) {
    Serial.println("Disconnecting from server...");
    client.stop();
    responDariServer = true;
    prosesKirimDataKeServer = false;
  }
 
  // penanganan data yang diterima dari server
  if(responDariServer)
  {
    responDariServer = false;
    Serial.println(Respon);
    int posisiData = Respon.indexOf("\r\n\r\n");
    String Data = Respon.substring(posisiData+4);
    Data.trim();
  
    String variabel;
    String nilai;
  
    Serial.println("Data dari server");
    posisiData = Data.indexOf('=');
    if(posisiData > 0)
    {
      variabel = Data.substring(0,posisiData);
      nilai = Data.substring(posisiData+1);
    
      //===========Penanganan respon disini
      if(variabel == "setSuhu")
      {
        setSuhu = nilai.toFloat();
      }
//      Serial.print(variabel);
//      Serial.print(" = ");
//      Serial.println(nilai);
    }
    Respon = "";
  }
}
 
bool kirimDataKeServer()
{
  Serial.println();
  Serial.println("Starting connection to server...");
  // if you get a connection, report back via serial
  if (client.connect(server, 80)) {
    Serial.println("Connected to server");
    // Make a HTTP request
  
    client.print("GET /index.php/databaseArduino/dariArduino");
    client.print("?Api=");
    client.print(digitalRead(pinFlame));
      
    client.print("&Asap=");
    client.print(digitalRead(pinMQ));
 
    client.print("&Suhu=");
    client.print(dht.readTemperature());
      
    client.println(" HTTP/1.1");
    client.print("Host: ");
    client.println(server);
    client.println("Connection: close");
    client.println();
    return true;
  }
  return false;
}
  
void printWifiStatus()
{
  // print the SSID of the network you're attached to
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  
  // print your WiFi shield's IP address
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  
  // print the received signal strength
  long rssi = WiFi.RSSI();
  Serial.print("Signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  
  IPAddress gateway = WiFi.gatewayIP();
  Serial.print("gateway:");
  Serial.print(gateway);
  Serial.println(" ");
}
