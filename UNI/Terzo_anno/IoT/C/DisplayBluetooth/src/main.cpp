#include <iot_board.h>
#include <BLEDevice.h>

#define UUID_service "a533db93-7dbd-48d9-8aff-71b50c91de4e"
#define UUID_display "6cc63ab1-69c2-430d-a616-8ed0ad3aefc1"
#define MAX_LEN 128

volatile bool connected = false;
volatile bool writeDisplay = false;
char arrayFrase[MAX_LEN] = "";

BLECharacteristic *ledChar;

class LedCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *c) {

    String val = c->getValue();
    if(val.length() > 0 && writeDisplay == false){
      strncpy(arrayFrase,val.c_str(),MAX_LEN-1);
      arrayFrase[MAX_LEN-1] = '\0';
      writeDisplay = true;  
    }

  }
};

class ServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer *s) {

    digitalWrite(LED_GREEN,HIGH);
    digitalWrite(LED_YELLOW,LOW);
    connected = true;
    
    }

  void onDisconnect(BLEServer *s) {
    connected = false;
    digitalWrite(LED_GREEN,LOW);
    digitalWrite(LED_YELLOW,HIGH);
    BLEDevice::startAdvertising();
  }
};

void printDisplay(){
  display->clearDisplay();
  display->setCursor(0,0);
  display->printf("%s",arrayFrase);
  display->display();
}

void setup(){

  IoTBoard::init_display();
  IoTBoard::init_leds();  //led giallo non connesso con adv, led verde connesso

  BLEDevice::init("Display-BLE");
  BLEServer *server = BLEDevice::createServer();
  server->setCallbacks(new ServerCallbacks());
  BLEService *svc = server->createService(UUID_service);
  ledChar = svc->createCharacteristic(UUID_display,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_WRITE |
      BLECharacteristic::PROPERTY_NOTIFY);

  ledChar->setValue("0");
  ledChar->setCallbacks(new LedCallbacks());
  svc->start();
  server->start();

  BLEAdvertising *adv = BLEDevice::getAdvertising(); 
  adv->addServiceUUID(UUID_service); 
  adv->setScanResponse(true); 
  BLEDevice::startAdvertising();
  digitalWrite(LED_YELLOW,HIGH);

}


void loop(){

  if(writeDisplay == true){
    printDisplay();
    writeDisplay = false;
  }


}
