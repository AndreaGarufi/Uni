#include <iot_board.h>
#include <WiFi.h>

//const char *ssid = "ARSLab-IoT_2G";
//const char *password = "arslabiot";

const char *ssid = " Galaxy S21 5G";
const char *password = "campobasso12345";


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

void setup() {

  IoTBoard::init_serial();
  IoTBoard::init_display();
  IoTBoard::init_leds();
  
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  int numeroReti = WiFi.scanNetworks();

  for(int i = 0; i < numeroReti; i++){

    Serial.printf("%-20s ch %2d %4d dBm %s\n",
      WiFi.SSID(i).c_str(), (int)WiFi.channel(i),
      (int)WiFi.RSSI(i),
      WiFi.encryptionType(i) == WIFI_AUTH_OPEN ? "open" : "secured");

  }
  WiFi.scanDelete();
  delay(1000);  

  display->clearDisplay();
  display->setCursor(0,0);

  display->printf("Connessione in corso a: \n %s\n", ssid);
  display->display();

  WiFi.onEvent(onWiFi);
  WiFi.begin(ssid,password);    
  
  


}


void loop() {


}
