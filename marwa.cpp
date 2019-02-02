#include"marwa.h"

BLECharacteristic *pCharacteristic;
bool deviceConnected = false; 
bool timee=true;
int i;
String rx="";



#define SERVICE_UUID           "75cf7374-a137-47e7-95e5-e675189c8a3e"         
#define CHARACTERISTIC_UUID_RX "0d563a58-196a-48ce-ace2-dfec78acc814"
#define CHARACTERISTIC_UUID_TX "0d563a58-196a-48ce-ace2-dfec78acc814"
int lastRestart=millis();
class MyServerCallbacks: public BLEServerCallbacks 
      {
        void onConnect(BLEServer* pServer) 
          {
           deviceConnected = true;
           Serial.println("User Connected");
          };
       void onDisconnect(BLEServer* pServer) 
          {
            //pServer->getAdvertising()->stop();
            deviceConnected = false;
            //pServer->getAdvertising()->start();
          }
      };


  class MyCallbacks: public BLECharacteristicCallbacks 
      {
        void onWrite(BLECharacteristic *pCharacteristic) 
          {
          Serial.print("MAC Recieved From BLE : ");
          Serial.println(mac);
          rx= pCharacteristic->getValue().c_str();
          }
      };


          
                      
void initialisation() {
 
  
  // BLEDevice 
  BLEDevice::init("ENPELN"); 
  
  // BLE Server
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Service BLE
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Characteristique BLE
  pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID_TX,BLECharacteristic::PROPERTY_NOTIFY);
  pCharacteristic->addDescriptor(new BLE2902());
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID_RX,BLECharacteristic::PROPERTY_WRITE);
  pCharacteristic->setCallbacks(new MyCallbacks());
         
 
  // Lancer le service
  pService->start();
  
  // Start advertising
  pServer->getAdvertising()->start();
  Serial.println("Connexion du client...");
  }


void BLE_thread(void *thread)
{
      
      while(1){
       // vTaskDelay(10 / portTICK_PERIOD_MS);
        xSemaphoreTake(xMutex,portMAX_DELAY);
        if(rx.length()>1)
        {
          mac=rx;
          Serial.print("Mac address collected by BLE : ");
          Serial.println(mac);
          rx="";
        }
       /* if(millis()-lastRestart > 10){
            pServer->getAdvertising()->stop();
            lastRestart=millis();
            pServer->getAdvertising()->start();
        }*/
        xSemaphoreGive(xMutex);

      }
}
      




  



       
