#include <iot_board.h>
#include <BLEDevice.h>

//indirizzi univoci a 128 bit BLE lo richiede per identificare i servizi 
#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"   //identifica il servizio generale della lampada
#define LED_UUID     "beb5483e-36e1-4688-b7f5-ea07361b26a8" //indentifica la specifica caratteristica del led (on/off)

BLECharacteristic *ledChar; //caratteristica BLE del led, messo qui cosi da leggerlo in qualsiasi punto del codice
//

volatile bool connected = false, ledOn = false, redraw = true, notifica = false;
 
class LedCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *c) {     // a central wrote
    ledOn = (c->getValue() == "on");       
    digitalWrite(LED_GREEN, ledOn ? HIGH : LOW);
    c->notify();                           // echo to subscribers
    redraw = true;                         // display: in loop()
  }
};

class ServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer *s) { connected = true; redraw = true; }
  void onDisconnect(BLEServer *s) {
    connected = false; redraw = true;
    BLEDevice::startAdvertising();         // discoverable again
  }
};

void pulsanteOnePremuto(uint8_t pinBtn){

  ledOn = !ledOn;
  digitalWrite(LED_GREEN, ledOn ? HIGH : LOW);
  redraw = true;
  notifica = true;

}

void setup() {
  IoTBoard::init_serial();
  IoTBoard::init_leds();
  IoTBoard::init_display();
  IoTBoard::init_buttons();

  BLEDevice::init("Garufi's-Lamp");             // GAP name
  BLEServer *server = BLEDevice::createServer();
  server->setCallbacks(new ServerCallbacks());
  BLEService *svc = server->createService(SERVICE_UUID);
  ledChar = svc->createCharacteristic(LED_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_WRITE |
      BLECharacteristic::PROPERTY_NOTIFY);

  ledChar->setValue("off");
  ledChar->setCallbacks(new LedCallbacks());
  svc->start();
  server->start();

  buttons->onBtn1Release(pulsanteOnePremuto);
  
 
  BLEAdvertising *adv = BLEDevice::getAdvertising();
  adv->addServiceUUID(SERVICE_UUID);
  adv->setScanResponse(true);
  BLEDevice::startAdvertising();
}

void loop() {         // UI only
  if(buttons->isBtn1Pressed()){
    Serial.println("BTN 1 is down");
  }

  if(notifica){
    ledChar->setValue(ledOn ? "on" : "off");
    ledChar->notify();
    notifica = false;
  }

  if (!redraw){
    return;
  } 
    

  redraw = false;
  display->clearDisplay();
  display->setCursor(0, 0);
  display->println(connected ?
      "Connected" : "Advertising");
  display->print("LED: ");
  display->print(ledOn ? "on" : "off");
  display->display();

  

}

