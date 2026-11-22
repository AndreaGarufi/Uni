  #include <iot_board.h>
  #include <BLEDevice.h>

  BLEScan *scan;
  volatile bool initialization = true;
  volatile bool green = false,yellow = false, red = false,start = false;
  int rssi = 0;

  class ScanCallbacks : public BLEAdvertisedDeviceCallbacks {
    void onResult(BLEAdvertisedDevice dev) {
      if(dev.getName() == "Scanner-Tag"){

        green = false;
        yellow = false;
        red = false;

        Serial.print(dev.getAddress().toString());
        Serial.printf("  %d dBm  ", dev.getRSSI());
        rssi = dev.getRSSI();
        if (rssi >= -55) {                       
          green = true;
        } else if (rssi < -55 && rssi >= -75) {    
          yellow = true;
        } else {                                   
          red = true;
        }
        start = true;
        Serial.println(dev.getName());
      }else{
        Serial.printf("Non trovo Scanner-Tag\n");
      }
    }
  };

  void setup(){
    IoTBoard::init_serial();
    IoTBoard::init_display();
    IoTBoard::init_leds();
    
    BLEDevice::init("");
    scan = BLEDevice::getScan();
    scan->setAdvertisedDeviceCallbacks(new ScanCallbacks());
    scan->setActiveScan(true);
    scan->setInterval(100);
    scan->setWindow(99);
  }

  void loop(){

    if(initialization == true){
      display->clearDisplay();
      display->setCursor(0,0);
      display->print("Scansione attiva...\n");
      display->display();
      initialization = false;
    }

    BLEScanResults *found = scan->start(5, false);
    if(start == true){
      display->clearDisplay();
      display->setCursor(0,0);
      display->printf("Segnale: %d dBm\n",rssi);
      display->display();
      initialization = false;    

      digitalWrite(LED_RED,red);
      digitalWrite(LED_GREEN,green);
      digitalWrite(LED_YELLOW,yellow);
      red = false;
      green = false;
      yellow = false;
      start = false;
    }
    //Serial.printf("Found %d\n",found->getCount());

    scan->clearResults();
  }