#include "common.h"

String mac=String("abcdefgh21");
int validation=0;
SemaphoreHandle_t xMutex=xSemaphoreCreateMutex();
BLEServer *pServer = NULL;
