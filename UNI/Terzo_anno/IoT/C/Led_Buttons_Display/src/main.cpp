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
  display->println("LEDs spenti.");   //la println cosi come la printf o la print scrivono sul buffer di memoria, quindi serve mettere la funzione sotto
  display->display();                  //perché scuota il buffer e quindi stampa a schermo

  buttons->onBtn1Release(pulsanteOnePremuto); //onBtn1Release funzione della libreria che quando si verifica l'evento (bt1 rilasciato) esegue la funzione tra parentesi
  buttons->onBtn2Release(pulsanteDosPremuto);
  display->println("Pulsanti Configurati.");
  display->display();
  
  display->println("Board Pronta!");
  display->display();


}


void loop() {

  buttons->update();    //come fa onBtn1Release a capire in che stato è il pulsante? update() nella loop controlla continuamente lo stato dei pulsanti e in caso richiama quelle funzioni associate



}
