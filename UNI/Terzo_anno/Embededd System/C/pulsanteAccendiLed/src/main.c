#include "stm32_unict_lib.h"

void setup(void){
    ClockConfig();  // 84MHz
    GPIO_init(GPIOB);
    
    GPIO_config_output(GPIOB, 0); // PB0 (LED rosso) come Uscita
    GPIO_config_input(GPIOB, 4);  // PB4 (Pulsante Y) come Ingresso
}

void loop(void){                //in questo programma il led resta acceso finche il pulsante è premuto
    int pin = GPIO_read(GPIOB, 4);      //prendo il valore letto dal pulsante (premuto o non premuto)
    GPIO_write(GPIOB, 0, pin);          //accendo il led in base al valore che ha la variabile pin
}

int main(){
    setup();
    for(;;){
        loop();
    }
}