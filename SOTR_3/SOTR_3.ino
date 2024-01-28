#include <Arduino_FreeRTOS.h>

#include <semphr.h>
#define LED1 8
#define LED2 9
#define LED3 10
#define LED4 11

SemaphoreHandle_t xSerialSemaphore;
void Task_LED1(void *pvParameters);
void Task_LED2(void *pvParameters);
void Task_LED3(void *pvParameters);
void Task_LED4(void *pvParameters);

void setup() 
{
 Serial.begin(9600);
 if(xSerialSemaphore ==NULL)
 {
   xSerialSemaphore = xSemaphoreCreateMutex();
   if (xSerialSemaphore != NULL)
   xSemaphoreGive((xSerialSemaphore));
 }
   xTaskCreate(Task_LED1,"T1",128,NULL,1,NULL);
   xTaskCreate(Task_LED2,"T2",128,NULL,1,NULL);
   xTaskCreate(Task_LED3,"T3",128,NULL,1,NULL);
   xTaskCreate(Task_LED4,"T4",128,NULL,1,NULL);
}
 
void loop() {}

 void Task_LED1(void *pvParameters)
 {
   pinMode(LED1, OUTPUT);
   for(;;)
   {
     digitalWrite(LED1, !digitalRead(LED1));
     vTaskDelay(300);
   }
 }
 
 void Task_LED2(void *pvParameters)
 {
   pinMode(LED2, OUTPUT);
   for(;;)
   {
     digitalWrite(LED2, !digitalRead(LED2));
     vTaskDelay(600);
   }
 }
 
 void Task_LED3(void *pvParameters)
 {
   pinMode (LED3, OUTPUT);
   for(;;)
   {
     digitalWrite (LED3, !digitalRead (LED3));
     int c= !digitalRead(LED3);
     Serial.println(c);
     vTaskDelay(900);
   }
 }
 void Task_LED4(void *pvParameters)
 {
   pinMode (LED4, OUTPUT); 
   for(;;)
   {
     digitalWrite (LED4, !digitalRead (LED4));
     int c= !digitalRead(LED4);
     Serial.println(c);
     vTaskDelay(1200);
   }
 }
