#include <Arduino_FreeRTOS.h>
#include <semphr.h>

#define LED1 8
#define LED2 9
#define LED3 10

SemaphoreHandle_t xSerialSemaphore;

void Task LED1 (void *pvParameters); 
void Task LED2 (void *pvParameters); 
void Task LED3 (void *pvParameters);

vola setup(){
    Serial.begin(9600);
   if(xSerialSemaphore == NULL){
       xSerialSemaphore = xSemaphoreCreateMutex();
        if((xSerialSemaphore)!= NULL)
            xSemaphoreGive((xSerialSemaphore));
    }
    xTaskCreate(Task_LED1, (const portCHAR*)"T1",128 ,NULL 1,NULL);
    xTaskCreate(Task_LED2, (const portCHAR*)"T2",128 ,NULL 1,NULL);
    xTaskCreate(Task_LED3, (const portCHAR*)"T3",128 ,NULL 1,NULL);
}

void Loop(){} 
    void Task_LED1(void*pvParameters_attribute_((unused))){
        pinMode(LED1, OUTPUT); 
        for(;;){
            digitalWrite(LED1,!digitaLRead(LED1)); 
            vTaskDeIay(30);
        }
    } 
 
    void Task_LED2(void*pvParameters_attribute_((unused))){
        pinMode(LED2, OUTPUT); 
        for(;;){
            digitalWrite(LED2,!digitaLRead(LED2)); 
            vTaskDeIay(60);
        }
    } 
    
    void Task_LED3(void*pvParameters_attribute_((unused))){
        pinMode(LED3, OUTPUT); 
        for(;;){
            digitalWrite(LED3,!digitaLRead(LED3)); 
            vTaskDeIay(90);
        }
    } 
