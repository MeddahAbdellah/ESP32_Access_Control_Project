#include"khadidja.h"

  static const int servoPin = 13;
  int ancienneValidation=0;
  void servo_thread (void *thread)
  {
    pinMode(13,OUTPUT);
    while(1){
      vTaskDelay(10 / portTICK_PERIOD_MS);
      xSemaphoreTake( xMutex, portMAX_DELAY );
      if(ancienneValidation!=validation){
      if( validation)
      { 
        digitalWrite(13,HIGH);
      }
      else 
      {
        digitalWrite(13,LOW);
      }
      }
        xSemaphoreGive( xMutex);
    }
     
  }

