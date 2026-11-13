#include "stm32_unict_lib.h"
#include <stdio.h>
#include <stdbool.h>

int secondi = 0;
int minuti = 0;
int ore = 0;
int previusOre = 0;

bool lampeggia = false;


void setup(){

    DISPLAY_init();
    GPIO_init(GPIOC);
    GPIO_init(GPIOB);

    GPIO_config_output(GPIOB,8);
    GPIO_config_output(GPIOC,3);

    TIM_init(TIM4);
    TIM_config_timebase(TIM4, 84000, 1000); 
    TIM_enable_irq(TIM4,IRQ_UPDATE);
    TIM_set(TIM4,0);
    TIM_on(TIM4);
    
}

void TIM4_IRQHandler(void){

    secondi++;
    if(secondi == 60){
        secondi = 0;
        minuti++;
    }
    if(minuti == 60){
        minuti = 0;
        previusOre = ore;
        lampeggia = true;
        ore++;
    }
    if(ore == 24){
        ore = 0;
        minuti = 0;
        secondi = 0;
    }
    GPIO_toggle(GPIOB,8);

    if(ore > previusOre && lampeggia == true){
        GPIO_Write(GPIOC,3,1);
        lampeggia = false;
    }

    TIM_update_clear(TIM4);
}


void loop(){

    char orario[5];
    snprintf(orario, sizeof(orario), "%02d%02d", ore, minuti);

    DISPLAY_puts(0,orario);

}

int main(){

    setup();

    for(;;){
        loop();
    }
}