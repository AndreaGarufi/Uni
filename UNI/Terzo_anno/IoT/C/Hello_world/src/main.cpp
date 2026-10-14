#include <iot_board.h>

void setup() {

IoTBoard::init_serial();
  pinMode(LED_RED,OUTPUT);
  pinMode(LED_YELLOW,OUTPUT);
  pinMode(LED_GREEN,OUTPUT);

  digitalWrite(LED_RED,LOW);
  digitalWrite(LED_YELLOW,LOW);
  digitalWrite(LED_GREEN,LOW);

  Serial.println("Configurazione Ultimata.");
  Serial.println("Avvio del loop.");

}

int count = 1;

void loop() {

  digitalWrite(LED_RED,count);
  sleep(1);
  digitalWrite(LED_YELLOW,count);
  sleep(1);
  digitalWrite(LED_GREEN,count);
  sleep(1);  

  count = !count;

}
