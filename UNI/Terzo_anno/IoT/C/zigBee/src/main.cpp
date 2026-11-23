#include <iot_board.h>

#define MY_ID    0x0017   // unique on every board!
#define PAN_ID   0x8888   // same for the whole group
#define CHANNEL  15       // 2425 MHz: between Wi-Fi 1 and 6

bool received = false;
uint16_t lastAddrRecv;
char lastPayload[109];

void onZigbeeReceive(rx_info_t *packet){
  lastAddrRecv = zigbee->readUnsignedInt();  // same order
  strcpy(lastPayload,zigbee->readString());
  received = true;

}

void onBt1Pressed(uint8_t btn){

  zigbee->startPacket();
  //zigbee->writeUnsignedInt(MY_ID);            // sender ID first
  zigbee->writeString("Ciao sono Andrea");                   // text + '\0'
  zigbee->sendPacket(0xFFFF); 

}


void setup() {
  
  IoTBoard::init_serial();
  IoTBoard::init_leds();
  IoTBoard::init_display();
  IoTBoard::init_buttons();

  IoTBoard::init_spi();
  if(IoTBoard::init_zigbee()){
    display->clearDisplay();
    display->setCursor(0,0);
    display->println("ZIGBEE Buono");
    display->display();
    Serial.printf("ZigBee Buono");
  }

  zigbee->setPanId(PAN_ID);      // hardware address filter
  zigbee->setAddress(MY_ID);
  zigbee->setChannel(CHANNEL);
  zigbee->onReceiveCallback(onZigbeeReceive);
  //display->clearDisplay(); 
  //display->setCursor(0, 0);
  //display->printf("Node %04X ch %d\n", MY_ID, CHANNEL);
  //display->display();
  buttons->onBtn1Release(onBt1Pressed);

}

void loop() {

  if(received){
    received = false;
    Serial.printf("%02x ha mandato %s\n",lastAddrRecv,lastPayload);
  }


}
