#include <stm32_unict_lib.h>
#include <stdbool.h>

volatile bool measure_done = false;
volatile bool timeout = false;

void TIM3_IRQHandler(){
    if(TIM_update_check(TIM3)){

        //period match, timeout
        GPIO_write(GPIOB,0,0);
        timeout = true;
        TIM_update_clear(TIM3);
    }

    if(TIM_cc_check(TIM3,1)){
        //cattura
        GPIO_write(GPIOB,0,0);
        measure_done = 1;
        TIM_cc_clear(TIM3,1);
    }

}

int main(){
    DISPLAY_init();
    GPIO_init(GPIOB);
    GPIO_config_output(GPIOB,0);        //il LED
    GPIO_config_alternate(GPIOB,4,2);   //button Y

    TIM_init(TIM3);
    TIM_config_timebase(TIM3,8400,50000);
    TIM_config_IC(TIM3,1,IC_FALLING_EDGE);  //cattura on falling edge (pushbutton)
    TIM_set(TIM3,0);
    TIM_on(TIM3);
    TIM_enable_irq(TIM3,IRQ_UPDATE | IRQ_CC_1);

    for(;;){
        delay_ms(3000); //aspetta 3 secondi prima di iniziare il gioco
        TIM_set(TIM3,0);
        measure_done = false;
        timeout = false;
        GPIO_write(GPIOB,0,1); //lit the LED
        DISPLAY_puts(0,"      ");
        TIM_on(TIM3);//forse sbagliato da provare
        while(measure_done == false && timeout == false){

        }

        if(measure_done == true){
            //cattura ok
            int ms = TIM3->CCR1/10;
            char s[5];
            sprintf(s,"%4d",ms);
            DISPLAY_puts(0,s);
        }else{
            //timeout
            DISPLAY_puts(0,"tout");
        }
    }

}


