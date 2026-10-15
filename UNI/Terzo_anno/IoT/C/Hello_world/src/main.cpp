#include <iot_board.h>

void pulsanteOnePremuto(uint8_t pinBtn){
  Serial.println("BTN 1 pressed.");

  digitalWrite(LED_RED, !digitalRead(LED_RED));
}

void pulsanteDosPremuto(uint8_t pinBtn){
  Serial.println("BTN 2 pressed.");

  digitalWrite(LED_GREEN, !digitalRead(LED_GREEN));
}

void setup() {

  IoTBoard::init_serial();
  IoTBoard::init_buttons();
  IoTBoard::init_display();
  IoTBoard::init_leds();
  display->clearDisplay();
  display->println("\n\n");
  
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, LOW);
  display->println("LEDs spenti.");

  display->display();

  buttons->onBtn1Release(pulsanteOnePremuto);
  buttons->onBtn2Release(pulsanteDosPremuto);
  display->println("Pulsanti Configurati.");
  display->display();
  
  display->println("Board Pronta!");
  display->display();


}


void loop() {

  buttons->update();



}
