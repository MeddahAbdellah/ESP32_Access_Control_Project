#include "abdellah.h"
int lastValidation=0;
void ledsThread(void *thread)
{
    while(1)
    { vTaskDelay(10 / portTICK_PERIOD_MS);
      xSemaphoreTake(xMutex,portMAX_DELAY);
        if(lastValidation!=validation){
          if(validation){
              Serial.println("Valid");
              digitalWrite(13,HIGH);
          }else{
              digitalWrite(13,LOW);
              if(Serial.available()){
                mac=Serial.readString();
              }
          }
        }
     xSemaphoreGive(xMutex);
    }
}

