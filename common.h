#include "Arduino.h"
#include <pthread.h>
#include <BLEServer.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLE2902.h>
extern String mac;
extern int validation;
extern SemaphoreHandle_t xMutex;
extern BLEServer *pServer;
