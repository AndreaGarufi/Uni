#include <iot_board.h>

bool stato = true;

void pulsanteOnePremuto(uint8_t pinBtn){
  Serial.println("BTN 1 pressed.");
  

  if(stato == true){
    display->clearDisplay();
    display->setCursor(0,0);

    display->println("Led Giallo acceso!");   
    display->display();

    digitalWrite(LED_YELLOW, HIGH);
    stato = !stato;
    return;
  }else if(stato == false){
    display->clearDisplay();
    display->setCursor(0,0);
    display->println("Board inizializzata!");  
    display->display();

    digitalWrite(LED_YELLOW, LOW);
    stato = !stato;   
    return;
  }
}

void setup() {

  IoTBoard::init_serial();
  IoTBoard::init_buttons();
  IoTBoard::init_display();
  IoTBoard::init_leds();

  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, LOW);
  display->println("Board inizializzata!");   
  display->display(); 

  buttons->onBtn1Release(pulsanteOnePremuto);


}

void loop() {

  if (IoTBoard::runEvery(500,0)) {
    digitalWrite(LED_RED,!digitalRead(LED_RED));
  }

  buttons->update();

}

