#include <iot_board.h>
#include <WiFi.h>
#include <esp_now.h>

typedef struct __attribute__((packed)) {
  char nick[8];          // who is sending
  char text[128];
} Msg;   

Msg outMSG;

uint8_t peer_broadcast_address[6] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

Msg inMSG;



void onRecv(const uint8_t *mac,const uint8_t *data, int len) {
  Serial.printf("Ho ricevuto qualcosa grande %d byte.\n",len);

  if (len != sizeof(Msg)){
  return;   // not ours
  }     
  memcpy(&inMSG, data, sizeof(Msg));

  Serial.printf("Messaggio da %s ha scritto: %s\n",inMSG.nick,inMSG.text);

}


void setup() {

  IoTBoard::init_serial();
  IoTBoard::init_leds();
  IoTBoard::init_buttons();
  //buttons->onBtn1Release(onBtn1);
  strcpy(outMSG.nick,"ANDREA");

  WiFi.mode(WIFI_STA);       // radio on, no AP
  esp_now_init();
  esp_now_peer_info_t peerBroadcast = {};
  memcpy(peerBroadcast.peer_addr, peer_broadcast_address, 6);
  peerBroadcast.channel = 6;
  peerBroadcast.encrypt = false;

  esp_now_register_recv_cb(onRecv);
  esp_now_add_peer(&peerBroadcast);
  Serial.setTimeout(4000);


}


String m; 
void loop() {
  // put your main code here, to run repeatedly:
  
  if(IoTBoard::runEvery(3000)){

    m.clear();
    m = "CIAO ANDREA";
    
    if(m.length() > 0){
      memcpy(outMSG.text,m.c_str(),m.length());
      
      esp_now_send(peer_broadcast_address,(uint8_t*)&outMSG, sizeof(outMSG));
    }
  }

}

