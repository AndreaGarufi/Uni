#include <iot_board.h>
#include <BLEDevice.h>

#define SERVICE_UUID "b5c74380-44ca-453e-983c-bd9c13506201"
#define LED_UUID "78082cd7-4f19-4443-b28a-0e7b6933fff6"

volatile bool initialization = true;

void setup(){
  IoTBoard::init_serial();
  IoTBoard::init_display();
  IoTBoard::init_leds();
  
  BLEDevice::init("Scanner-Tag");
  BLEAdvertising *adv = BLEDevice::getAdvertising();
  //adv->addServiceUUID(SERVICE_UUID);
  adv->setScanResponse(true);
  BLEDevice::startAdvertising();
}

void loop(){
  if(initialization == true){
    display->clearDisplay();
    display->setCursor(0,0);
    display->print("Advertising attivo...\n");
    display->display();
    initialization = false;
  }
}