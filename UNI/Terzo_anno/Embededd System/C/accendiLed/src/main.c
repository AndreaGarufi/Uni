#include <stm32_unict_lib.h>

void setup(void){
    ClockConfig();  //84Mhz configura la frequenza del clock di sistema
    GPIO_init(GPIOB);   //inizializza la porta digitale GPIOB
    GPIO_config_output(GPIOB,0);  //configura il PB0 della porta B come uscita
}

void loop(void){
    GPIO_write(GPIOB,0,1);  //scrivo sul PB0 il valore 1 (led acceso)
    delay_ms(500);

    GPIO_write(GPIOB,0,0);  //scrivo sul PB0 il valore 0 (led spento)
    delay_ms(500);    
}

int main(){
    setup();
    for(;;){
        loop();
    }
}