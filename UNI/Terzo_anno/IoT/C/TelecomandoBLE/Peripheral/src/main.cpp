#include <iot_board.h>
#include <BLEDevice.h>

#define Service_UUID "73ff3c56-9a5e-4d83-bcf8-6ad9cbdd3fa6"
#define Led_UUID "6726b2f5-d6da-42d6-936f-ef4f149aeb4f"

BLECharacteristic *LED;
volatile bool connected = false,printDisplay = true,lit = false;
volatile bool green = false,yellow = false, red = false;
char ledOn[10] = "off\0";

class ServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer *s) { connected = true; printDisplay = true;}
  void onDisconnect(BLEServer *s) {
    connected = false;
    printDisplay = true;
    BLEDevice::startAdvertising();
  }
};

class LedCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *c) {

    green = false;
    yellow = false;
    red = false;

    strcpy(ledOn,c->getValue().c_str());
    if(strcmp(ledOn,"green") == 0){
      green = true;
      lit = true;
    }else if(strcmp(ledOn,"yellow") == 0){
      yellow = true;
      lit = true;
    }else if(strcmp(ledOn,"red") == 0){
      red = true;
      lit = true;
    }
    c->notify();
  }
};

void litLed(){

  digitalWrite(LED_GREEN,green);
  digitalWrite(LED_YELLOW,yellow);
  digitalWrite(LED_RED,red);

  green = false;
  yellow = false;
  red = false;

}

void setup() {
  IoTBoard::init_serial();
  IoTBoard::init_leds();
  IoTBoard::init_display();

  BLEDevice::init("Led-comandati");

  BLEServer *server = BLEDevice::createServer();
  server->setCallbacks(new ServerCallbacks());

  BLEService *svc = server->createService(Service_UUID);

  LED = svc->createCharacteristic(Led_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_WRITE |
      BLECharacteristic::PROPERTY_NOTIFY);

  LED->setValue("off");
  LED->setCallbacks(new LedCallbacks());
  svc->start();
  server->start();

  BLEAdvertising *adv = BLEDevice::getAdvertising();
  adv->addServiceUUID(Service_UUID);
  adv->setScanResponse(true);
  BLEDevice::startAdvertising();
}

void loop() {

  if(printDisplay == true){
    display->clearDisplay();
    display->setCursor(0, 0);
    display->println(connected ? "Connected" : "Advertising");
    display->display();
    printDisplay = false;
  }

  if(lit == true){
    litLed();
    lit = false;
  }


}