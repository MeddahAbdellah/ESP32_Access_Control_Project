#include "sarah.h"
int lastUpdate = 0;
void wifiThread(void *thread)
{

  HTTPClient http;
  while (1)
  { 
    vTaskDelay(10 / portTICK_PERIOD_MS);
    xSemaphoreTake(xMutex, portMAX_DELAY);
    
    if (WiFi.status() == WL_CONNECTED && mac.length() > 1 && (millis() - lastUpdate > 1000))
    {
     // pServer->getAdvertising()->stop();
      
      http.begin("http://09ea437f.ngrok.io/");                       //Specify the URL //
      http.addHeader("Content-Type", "text/plain");                  //Specify content-type header
      Serial.println("sending");
      int httpResponseCode = http.POST(mac);                         //Send the actual POST request
      
      if (httpResponseCode > 0)
      {
        Serial.println(httpResponseCode);
        String response = http.getString();                       //Get the response to the request
        mac = "";
        Serial.println(httpResponseCode);                         //Print return code
        Serial.println(response);                                 //Print request answer
        if (response == "found")
        {
          validation = 1;
        }
        else
        {
          validation = 0;
        }
        Serial.println(validation);
      }
      else
      {
        Serial.print("Error on sending POST: ");
        Serial.println(httpResponseCode);
      }

      http.end();  //Free resources
   //   pServer->getAdvertising()->start();
      Serial.println(pServer->getConnectedCount());
      Serial.println("started");
      lastUpdate = millis();
    }

    xSemaphoreGive(xMutex);
  }

}
