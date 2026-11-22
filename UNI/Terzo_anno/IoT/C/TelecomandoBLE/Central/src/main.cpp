#include <iot_board.h>
#include <BLEDevice.h>

static BLEUUID SVC_UUID("73ff3c56-9a5e-4d83-bcf8-6ad9cbdd3fa6");
static BLEUUID LED_UUID("6726b2f5-d6da-42d6-936f-ef4f149aeb4f");

BLERemoteCharacteristic *remoteLed = nullptr;

volatile bool inizializza = true;
volatile bool green = false, yellow = false, red = false;
 
bool connectTo(BLEAdvertisedDevice *dev) {
  BLEClient *client = BLEDevice::createClient();

  if (!client->connect(dev)) return false;  //se non si riesce a connettere return false
  
  BLERemoteService *svc = client->getService(SVC_UUID);
  if (svc == nullptr) return false;

  remoteLed = svc->getCharacteristic(LED_UUID);
  if (remoteLed == nullptr) return false;

  return true;
}

void onBtn1(uint8_t pin) { // flag only
  green = true; 
} 

void onBtn2(uint8_t pin) { // flag only
  yellow = true; 
}  

void onPressed(uint8_t pin) { // flag only
  red = true; 
}  
 
void setup() {
  IoTBoard::init_serial();
  IoTBoard::init_leds();
  IoTBoard::init_buttons();
  IoTBoard::init_display();
  buttons->onBtn1Release(onBtn1);
  buttons->onBtn2Release(onBtn2);
  buttons->onBtn1Press(onPressed);

  BLEDevice::init("");
  BLEScanResults *scanResults= BLEDevice::getScan()->start(5, false);

  for (int i = 0; i < scanResults->getCount(); i++) {      //trova il telecomando tra i dispositivi scansionati
    BLEAdvertisedDevice dev = scanResults->getDevice(i);
    if (!dev.isAdvertisingService(SVC_UUID)) continue;
    if (connectTo(&dev)) break;
  }
}
 
void loop() {

  if(inizializza == true){
    display->clearDisplay();
    display->setCursor(0,0);
    display->print("Tieni premuto Bt1 per accendere il rosso sul telecomando\npremi e rilascia Bt1 per accendere il verde\npremi e rilascia Bt2 per accendere il giallo");
    display->display();
    inizializza = false;
  }

  if(remoteLed != nullptr){
    if(green == true){
      remoteLed->writeValue("green", true);
      green = false;
    }
    if(yellow == true){
      remoteLed->writeValue("yellow", true);
      yellow = false;
    }
    if(red == true){
      remoteLed->writeValue("red", true);
      red = false;
    }
  }

}
