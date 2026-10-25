#include <iot_board.h>
#include <WiFi.h>
#include "credentials.h"

bool stampa = false;
int numeroClient = 0;
int previusNumeroClient = 0;

void onWiFi(WiFiEvent_t event, WiFiEventInfo_t info) {

  switch (event) {
    case ARDUINO_EVENT_WIFI_STA_CONNECTED:
      display->println("Associated to the AP");
      break;
    case ARDUINO_EVENT_WIFI_STA_GOT_IP:
      display->print("IP: ");
      display->println(IPAddress(info.got_ip.ip_info.ip.addr));
      break;
    case ARDUINO_EVENT_WIFI_STA_DISCONNECTED:
      display->printf("Link lost, reason %d\n",
                    info.wifi_sta_disconnected.reason);
      break;                      // auto-reconnect is on
    default:
      break;
  }
  display->display();
}

void connetti(uint8_t pinBtn){
  
  WiFi.softAPdisconnect(true);
  WiFi.mode(WIFI_STA);

  display->clearDisplay();
  display->setCursor(0,0);

  display->printf("Connessione in corso a: %s\n", SECRET_SSID);
  display->display();
  
  WiFi.onEvent(onWiFi);
  WiFi.begin(SECRET_SSID, SECRET_PASS);     

}

void AP(uint8_t pinBtn){

  WiFi.disconnect();
  WiFi.mode(WIFI_AP);

  numeroClient = 0;
  previusNumeroClient = 0;

  display->clearDisplay();
  display->setCursor(0,0);

  display->printf("AP = 'IoTBoard-42'\n");
  display->display();  

  // ssid, password, channel, hidden, max clients
  WiFi.softAP("IoTBoard-42", "iot", 6, 0, 4);
  display->print("AP addr: ");
  display->println(WiFi.softAPIP());   // 192.168.4.1  
  display->display();


}

void stampaClients(){

  display->printf("Clients connessi: %d\n", numeroClient);
  display->display();  
  stampa = false;

}

void setup() {

  IoTBoard::init_serial();
  IoTBoard::init_buttons();
  IoTBoard::init_display();
  IoTBoard::init_leds();

  display->clearDisplay();
  display->setCursor(0,0);
  WiFi.disconnect();

  display->println("\n\nBt1 per connetterti alla rete.\n");
  display->println("Bt2 per fare da AP.\n");  
  display->display();

  buttons->onBtn1Release(connetti);
  buttons->onBtn2Release(AP);
}

void loop() {

  buttons->update();
  // Esegui la verifica dei client solo quando l'AP è attivo
  if (WiFi.getMode() == WIFI_AP || WiFi.getMode() == WIFI_AP_STA) {
    numeroClient = WiFi.softAPgetStationNum();
    if (numeroClient > previusNumeroClient && numeroClient > 0) {
      stampa = true;
    }
    if (stampa == true) {
      stampaClients();
    }
    previusNumeroClient = numeroClient;
  }
  
}
