#include <iot_board.h>
#include <WiFi.h>
#include "credentials.h"

int secondi = 0;
int minuti = 0;
bool start = false;

void pulsante1(uint8_t pinBtn){

  display->clearDisplay();
  display->setCursor(0,0);
  display->display();

  start = !start;
  if(start == true){
    display->print("Cronometo avviato\n");
    display->display();
  }else{
    display->clearDisplay();
    display->print("Cronometo fermato\n");
    display->printf("%d : %d",minuti,secondi); 
    display->display();   
  }


}

void timer(){

  secondi++;
  display->clearDisplay();
  display->setCursor(0,0);
  display->printf("%d : %d",minuti,secondi);
  display->display();
  if(secondi == 60){
    secondi = 0;
    minuti++;
  }
  if(minuti == 60){
    secondi = 0;
    minuti = 0;
  }
  

}

void setup() {

  IoTBoard::init_buttons();
  IoTBoard::init_display();
  IoTBoard::init_serial();

  WiFi.disconnect();


  display->print("Bt1 per avviare il timer");
  buttons->onBtn1Release(pulsante1);
  display->display();

}

void loop() {
  // put your main code here, to run repeatedly:

  buttons->update();
  if(start == true && IoTBoard::runEvery(1000)){
    timer();
  }

}