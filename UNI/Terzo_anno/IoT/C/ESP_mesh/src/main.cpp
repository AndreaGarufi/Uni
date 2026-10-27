#include <iot_board.h>
//#include <WiFi.h>
#include "credentials.h"
#include <sys/socket.h>
#include <IPAddress.h>

//per connettersi alla mesh gli esp32 hanno prima bisogno di connettersi ad un AP come il router di casa o l'hotspot cellulare

//const char *SSID = "ARSLab-IoT_2G";
//const char *PASS = "arslabiot";
uint32_t numero = 0;
float tempInt = temperatureRead();

IPAddress ipPortatile;

void onMesh(const EspMeshEvent &e) {    //evento di tipo espmesh

  switch (e.type)
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
  ipPortatile.fromString("192.168.0.125");

  numero = (esp_random() % 10) + 1;

  EspMeshConfig configMesh;
  configMesh.router_ssid = SECRET_SSID;
  configMesh.router_pass = SECRET_PASS;
  configMesh.on_event = onMesh;
  configMesh.forward_ip = ipPortatile;
  configMesh.forward_port = 5000;


  IoTBoard::init_espmesh(configMesh);

  display->clearDisplay();
  display->setCursor(0,0);
  display->display();

}

void loop(){
  espmesh->update();
  tempInt = temperatureRead();
  

  if(IoTBoard::runEvery(3000)){
    String messaggio = "Andrea Garufi--" + String(tempInt) + "--" + String(numero) + "\n";
    espmesh->sendToServer(ipPortatile,5000,messaggio.c_str(), messaggio.length());  //noi usiamo sentToServer (UDP) perche vogliamo comunicare con il PC portatile, altrimenti se volessimo comunicare con la root avremmo fatto sendToRoot (che non prende IP e porta)
    display->clearDisplay();
    display->setCursor(0,0);
    display->print(messaggio);
    display->printf("\n");
    display->display();
  }

}


