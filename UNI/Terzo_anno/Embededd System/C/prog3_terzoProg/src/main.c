#include "stm32_unict_lib.h"

int prev_pin_state;
int led_state = 0;

void setup(void){
    ClockConfig();  //84Mhz
    GPIO_init(GPIOB);
    GPIO_config_output(GPIOB,0);
    GPIO_config_output(GPIOB,4);
    prev_pin_state = GPIO_read(GPIOB,4);
}

void loop(void){
    
    int current_pin_state = GPIO_read(GPIOB,4);
    if(prev_pin_state == 1 && current_pin_state == 0){
        //il bottone è premuto
        if(led_state == 0){
            GPIO_write(GPIOB,0,1);
            led_state = 1;
        }else{
            GPIO_write(GPIOB,0,0);
            led_state = 0;
        }
    }
    
    prev_pin_state = current_pin_state;
}

int main(){
    setup();
    for(;;){
        loop();
    }
}