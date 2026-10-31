#include <iot_board.h>
#include <WiFi.h>
#include <esp_now.h>

typedef struct __attribute__((packed)) {
  char nick[8];          // who is sending
  char text[128];
} Msg;   

Msg outMSG;
Msg inMSG;
String m; //il nostro messaggio
uint8_t peer_broadcast_address[6] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};  //indirizzo mac per il broadcast

esp_now_peer_info_t peerBroadcast = {};

bool discovery = true;  //boleano che serve per la fase iniziale e scoprire i mac address di tutte le schede
uint8_t discoveryCounter = 0;

void onRecv(const uint8_t *mac,const uint8_t *data, int len) {  

  esp_now_peer_info_t peer = {};  //per salvare tutti i nuovi peer

  Serial.printf("Ho ricevuto qualcosa grande %d byte.\n",len);

  if (len != sizeof(Msg)){  
  return;   // not ours
  }  

  if(!esp_now_is_peer_exist(mac)){
    
    memcpy(peer.peer_addr, mac, 6); 
    peer.channel = 0;  
    peer.encrypt = false; 
    esp_now_add_peer(&peer);

    display->printf("Nuovo peer aggiunto!\n");
    display->display();    
  }

  memcpy(&inMSG, data, sizeof(Msg));
  inMSG.text[sizeof(inMSG.text) - 1] = '\0';  
  display->printf("Msg da %s ha scritto: %s\n",inMSG.nick,inMSG.text);
  display->display();


  

}

void brodcastDiscovery(){
  if(discovery == true){

    if(IoTBoard::runEvery(5000)){   //timer run every 5 seconds

      m.clear();    //pulisco la stringa
      m = "Ti ho inviato il mio MAC ";    //scrivo il messaggio
      
      if(m.length() > 0){ //controllo che non sia vuoto
        memcpy(outMSG.text,m.c_str(),m.length()+1); //copio la stringa dentro la struct outMSG
        
        esp_now_send(peer_broadcast_address,(uint8_t*)&outMSG, sizeof(outMSG)); //faccio la sand in broadcast (primo paramentro) e mando il i byte della struct 
      }
      discoveryCounter++;
      if(discoveryCounter >= 5){
        discovery = false;
        //display->clearDisplay();
        //display->setCursor(0,0);
        display->display();
        return;
      }
    }

  }else{
    return;
  }

}

void clear(uint8_t pinBtn){
  display->clearDisplay();
  display->setCursor(0,0);
  display->display();

}

void setup() {

  IoTBoard::init_serial();
  IoTBoard::init_leds();
  IoTBoard::init_buttons();
  IoTBoard::init_display();
  display->clearDisplay();
  display->setCursor(0,0);
  display->display();

  uint8_t myMac[6];
  WiFi.mode(WIFI_STA);       // radio on, no AP
  WiFi.macAddress(myMac);
  //preparo la struct in uscita con il "nome" della scheda
  snprintf(outMSG.nick, sizeof(outMSG.nick), "%02X%02X%02X", myMac[3], myMac[4], myMac[5]); 
  

  esp_now_init();
  memcpy(peerBroadcast.peer_addr, peer_broadcast_address, 6); //copio dentro peer_addr il mac address broadcast perche voglio mandare messaggi in broadcast
  peerBroadcast.channel = 0;  //canale wireless da usare (da 1 a 13) con 0 setta lo stesso della radio
  peerBroadcast.encrypt = false; //cifratura del messaggio, se true serve anche una chiave di decrittazzione

  esp_now_register_recv_cb(onRecv); //dice: ogni volta che arriva un messaggio ESP-NOW destinato a me, chiama la funzione onRecv
  esp_now_add_peer(&peerBroadcast); //questa funzione aggiunge effettivamente il peer che abbiamo compilato prima


  buttons->onBtn1Release(clear);  //per cancellare il display alla pressione del tasto

}



void loop() {
  
  brodcastDiscovery();  //runna solo se discovery è true, discovery parte da true e diventa false dopo 5 cicli
  buttons->update();

}