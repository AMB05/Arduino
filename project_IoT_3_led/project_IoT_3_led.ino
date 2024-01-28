#define BLYNK_PRINT SwSerial
#include <SoftwareSerial.h>
SoftwareSerial SwSerial(13, 12); // RX, TX
#include <BlynkSimpleStream.h>
char auth[] = "m00IATPreB8lOqkVvQNWJiTQhY9rfQyy";

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  //SwSerial.print("V1 Slider value is: ");
  //SwSerial.println(pinValue);
  digitalWrite(2,pinValue);
  digitalWrite(3,pinValue);
}
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
