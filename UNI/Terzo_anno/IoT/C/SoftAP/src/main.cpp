#include <iot_board.h>
#include <WiFi.h>
 
void setup() {
  //Serial.begin(115200);
  WiFi.mode(WIFI_AP);
  // ssid, password, channel, hidden, max clients
  WiFi.softAP("IoTBoard-42", "iot-lab-2026", 6, 0, 4);
  Serial.print("AP address: ");
  Serial.println(WiFi.softAPIP());   // 192.168.4.1
}

void loop() {
  Serial.printf("Clients: %d\n", WiFi.softAPgetStationNum());
  delay(5000);

}