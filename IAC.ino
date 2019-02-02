#include "WiFi.h"
#include"marwa.h"
#include"sarah.h"
#include"abdellah.h"
#include"khadidja.h"
const char* ssid = "D-Link";
const char* password =  "renard2007";

void setup()
{

    Serial.begin(115200);
    delay(4000);
    Serial.println("wifi");
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Connecting to WiFi..");
    }

    Serial.println("Connected to the WiFi network");

    initialisation();

    xTaskCreate(wifiThread,"wifiThread",15000,NULL,2,NULL);
    vTaskDelay(10 / portTICK_PERIOD_MS);
    xTaskCreate(BLE_thread,"BLE_thread",5000,NULL,3,NULL);
    vTaskDelay(10 / portTICK_PERIOD_MS);
    xTaskCreate(ledsThread,"ledsThread",2000,NULL,5,NULL);
    vTaskDelay(10 / portTICK_PERIOD_MS);
    xTaskCreate(servo_thread,"servo_thread",2000,NULL,4,NULL);
    

}
void loop()
{
  delay(10);
}
