# ESP32_Access_Control_Project

This project displays the capabilites of the ESP32 and FreeRTOS. It contains the implementation of FreeRTOS tasks along with FreeRTOS
semaphores. It also displays the ability of the ESP32 to run the Wifi and BLE at the same time.

## Workflow

    - An Android/IOS App sends the MAC address of the Phone through BLE to the ESP32.
    - The ESP32 recieving the MAC address sends it to the server.
    - According to the Response of the server the ESP32 wil either Open a door to which it is connected or not.

This will let users Access a room/building using their phones without the necessity of possessing a special RFID card for the purpose
or a complexe/high cose finger print system.
