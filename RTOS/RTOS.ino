#include <Arduino_FreeRTOS.h>
#include <semphr.h>

#define LED1 7
#define LED2 8
#define LED3 9
#define LED4 10

SemaphoreHandle_t xSerialSemaphore;

void Task_LED1(void *parameters);
void Task_LED2(void *parameters);
void Task_LED3(void *parameters);
void Task_LED4(void *parameters);

void setup() 
{
  Serial.begin(9600);
  if(xSerialSemaphore == NULL)
  {
    xSerialSemaphore = xSemaphoreCreateMutex();
    if ((xSerialSemaphore ) != NULL)
    xSemaphoreGive((xSerialSemaphore));
  }
  
}

void loop() {}
void Task_LED1, (void *pvParameters_attribute_((unused)))
{
  pinMode (LED1, OUTPUT);
  for(;;)
  {
    digitalWrite(LED1, !digitalRead(LED1));
    int a= !digitalRead(LED1);
    Serial.println(a);
    vTaskDelay(300);
  }
}

void Task_LED2, (void *pvParameters_attribute_((unused)))
{
  pinMode (LED2, OUTPUT);
  for(;;)
  {
    digitalWrite(LED2, !digitalRead(LED2));
    int b= !digitalRead(LED2);
    Serial.println(b);
    vTaskDelay(600);
  }
}

void Task_LED3, (void *pvParameters_attribute_((unused)))
{
  pinMode (LED3, OUTPUT);
  for(;;)
  {
    digitalWrite(LED3, !digitalRead(LED3));
    int c= !digitalRead(LED3);
    Serial.println(c);
    vTaskDelay(900);
  }
}

void Task_LED4, ( void *pvParameters_attribute_( (unused) ) )
{
  pinMode (LED4, OUTPUT);
  for(;;)
  {
    digitalWrite(LED4, !digitalRead(LED4));
    int d= !digitalRead(LED4);
    Serial.println(d);
    vTaskDelay(1200);
  }
}
