#include <iot_board.h>
#include <WiFi.h>
#include <esp_now.h>
//ctrl + click -> per avere info su qualcosa nel codice
//__attribute__((packed)) serve per evitare il padding:
//Il padding sono byte “vuoti” che il compilatore inserisce di nascosto dentro una struct 
//per far sì che ogni campo si trovi a un indirizzo di memoria comodo per la CPU.

//quindi se c'è il padding vengono mandati anche quei byte vuoti, perche
//se mittente e destinatario hanno un layout diverso 
//(compilatori, architetture o versioni del codice diverse), non si capiscono

//noi quindi lo inseriremo a prescindere

typedef struct __attribute__((packed)) {
  char nick[8];          // who is sending
  char text[128];
} Msg;   

Msg outMSG;
Msg inMSG;
String m; //il nostro messaggio
uint8_t peer_broadcast_address[6] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};  //indirizzo mac per il broadcast


void onRecv(const uint8_t *mac,const uint8_t *data, int len) {  //on recv prende mac address i dati e la lunghezza dei dati in byte
  Serial.printf("Ho ricevuto qualcosa grande %d byte.\n",len);

  if (len != sizeof(Msg)){  //se la lunghezza di quello che è arrivato è maggiore della nostra struct vuol dire che è sbagliato
  return;   // not ours
  }     
  memcpy(&inMSG, data, sizeof(Msg));  //dentro la struct in ingresso copio i valori che mi sono stati mandati e li stampo

  display->printf("Messaggio da %s ha scritto: %s\n",inMSG.nick,inMSG.text);
  display->display();
}


void setup() {

  IoTBoard::init_serial();
  IoTBoard::init_leds();
  IoTBoard::init_buttons();
  IoTBoard::init_display();
  display->clearDisplay();
  display->setCursor(0,0);
  display->println("Inizializzato\n");
  display->display();

  strcpy(outMSG.nick,"ANDREA");   //preparo la struct in uscita con il mio nome

  WiFi.mode(WIFI_STA);       // radio on, no AP

  esp_now_init();
  esp_now_peer_info_t peerBroadcast = {}; //creo una variabile di tipo esp_now_peer_info_t e la inizializzo a 0 perche non andro ad usare tutti i campi
  memcpy(peerBroadcast.peer_addr, peer_broadcast_address, 6); //copio dentro peer_addr il mac address broadcast perche voglio mandare messaggi in broadcast
  peerBroadcast.channel = 0;  //canale wireless da usare (da 1 a 13) con 0 setta lo stesso della radio
  peerBroadcast.encrypt = false; //cifratura del messaggio, se true serve anche una chiave di decrittazzione

  esp_now_register_recv_cb(onRecv); //dice: ogni volta che arriva un messaggio ESP-NOW destinato a me, chiama la funzione onRecv
  esp_now_add_peer(&peerBroadcast); //questa funzione aggiunge effettivamente il peer che abbiamo compilato prima
  //Serial.setTimeout(4000);


}



void loop() {
  
  if(IoTBoard::runEvery(10000)){   //timer run every 3 seconds

    m.clear();    //pulisco la stringa
    m = "CIAO ANDREA";    //scrivo il messaggio
    
    if(m.length() > 0){ //controllo che non sia vuoto
      memcpy(outMSG.text,m.c_str(),m.length()); //copio la stringa dentro la struct outMSG
      
      esp_now_send(peer_broadcast_address,(uint8_t*)&outMSG, sizeof(outMSG)); //faccio la sand in broadcast (primo paramentro) e mando il i byte della struct 
    }
  }

  if(IoTBoard::runEvery(16500,2)){
    display->clearDisplay();
    display->setCursor(0,0);
    display->display();
  }

}