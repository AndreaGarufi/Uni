#include <iot_board.h>
//#include <WiFi.h>
#include "credentials.h"
#include <sys/socket.h>
#include <IPAddress.h>

//per connettersi alla mesh gli esp32 hanno prima bisogno di connettersi ad un AP come il router di casa o l'hotspot cellulare

//const char *SSID = "ARSLab-IoT_2G";
//const char *PASS = "arslabiot";

float tempInt = temperatureRead();
String Nome;
String Cognome;

IPAddress ipPortatile;

String array[6] = {"Archimede","Galileo","Oppenheimer","bello","brutto","cattivo"};

void onMesh(const EspMeshEvent &e) {    //evento di tipo espmesh

  switch (e.type)   //controlla il tipo di evento, se di tipo connected, disconnected, became root o message
  {
  case EspMeshEventType::Connected:
    digitalWrite(LED_GREEN, HIGH);
    break;
  case EspMeshEventType::Disconnected:
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    break;
  case EspMeshEventType::BecameRoot:
    digitalWrite(LED_YELLOW, HIGH);
    break;
  case EspMeshEventType::Message:
    Serial.printf("From " MACSTR "\n", MAC2STR(e.from));
  default:
    break;
  }


}


void setup(){

  IoTBoard::init_serial();
  IoTBoard::init_leds();
  IoTBoard::init_display();
  ipPortatile.fromString("192.168.0.125");  //diamo l'ip che in questo momento ha il portatile alla stringa ipPortatile

  uint32_t var1 = esp_random() % 3;
  uint32_t var2 = (esp_random() % 3) + 3;

  Nome = array[var1];
  Cognome = array[var2];

  EspMeshConfig configMesh;             //raggruppiamo in un unica struct tutti i parametri per poter avviare la rete mesh
  configMesh.router_ssid = SECRET_SSID; //SSID dell'AP
  configMesh.router_pass = SECRET_PASS; //Password per connettersi ad AP
  configMesh.on_event = onMesh;         //automaticamente chiamerà la funzione onMesh sopra quando si verifica un evento mesh
  configMesh.forward_ip = ipPortatile;  //forniamo l'IP del portatile con cui comunicare
  configMesh.forward_port = 5000;       //forniamo la porta su cui comunicare


  IoTBoard::init_espmesh(configMesh);   //funzione di inizializzazione espmesh a cui passiamo configMesh

  display->clearDisplay();
  display->setCursor(0,0);
  display->display();

}

void loop(){
  espmesh->update();          //update di espmesh (stesso discorso di quando lo facciamo per i pulsanti)
  tempInt = temperatureRead();
  

  if(IoTBoard::runEvery(3000)){
    String messaggio = Nome + " " + Cognome + " " + String(tempInt) + "\n";
    espmesh->sendToServer(ipPortatile,5000,messaggio.c_str(), messaggio.length());  //noi usiamo sentToServer (UDP) perche vogliamo comunicare con il PC portatile, altrimenti se volessimo comunicare con la root avremmo fatto sendToRoot (che non prende IP e porta)
    display->clearDisplay();
    display->setCursor(0,0);
    display->print(messaggio);
    display->printf("\n");
    display->display();
  }

}


