#define BLYNK_PRINT SwSerial
#include <SoftwareSerial.h>
SoftwareSerial SwSerial(10, 11); // RX, TX

#include <BlynkSimpleStream.h>
char auth[] = "nltdNg8nhz9clY5-Y6C98EHBsBn9UMPu";

void setup()
{
  SwSerial.begin(9600);
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
}

void loop()
{
  Blynk.run();
}
