#include "stm32_unict_lib.h"

void setup(void){
    ClockConfig();  //84Mhz
    GPIO_init(GPIOB);
    GPIO_config_output(GPIOB,0);
    GPIO_config_output(GPIOB,4);
}

void loop(void){
    
    int pin = GPIO_read(GPIOB,4);
    GPIO_write(GPIOB,0,pin);
}

int main(){
    setup();
    for(;;){
        loop();
    }
}