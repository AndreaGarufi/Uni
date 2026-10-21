#include "stm32_unict_lib.h"
#include <stdio.h>
#include <stdbool.h>

bool start = false;

void setup(void)
{
    ClockConfig();
    // configure the clock @ 84 MHz
    GPIO_init(GPIOB); // initialize port B
    GPIO_init(GPIOC); // initialize port C
    GPIO_config_output(GPIOB, 0); // configure pin PB0 as output    led rosso
    GPIO_config_output(GPIOC, 2); // configure pin PC2 as output    led giallo
    GPIO_config_output(GPIOC, 3); // configure pin PC3 as output    led verde

    GPIO_config_input(GPIOB, 10); // configure pin PB10 as input
    GPIO_config_input(GPIOB, 4); // configure pin PB4 as input
    GPIO_config_input(GPIOB, 5); // configure pin PB5 as input
    GPIO_config_input(GPIOB, 6); // configure pin PB6 as input
   
    GPIO_config_EXTI(GPIOB, EXTI10); // attach PB10 to EXTI10
    GPIO_config_EXTI(GPIOB, EXTI4); // attach PB4 to EXTI4
    GPIO_config_EXTI(GPIOB, EXTI5); // attach PB5 to EXTI5
    GPIO_config_EXTI(GPIOB, EXTI6); // attach PB6 to EXTI6

    EXTI_enable(EXTI10, FALLING_EDGE);
    EXTI_enable(EXTI4, FALLING_EDGE);
    EXTI_enable(EXTI5, FALLING_EDGE);
    EXTI_enable(EXTI6, FALLING_EDGE);
}

void startSemaforo(bool start){
    
    if(start == true){
        GPIO_write(GPIOB,0,1);
        delay_ms(2000);
        GPIO_write(GPIOB,0,0);

        GPIO_write(GPIOC,2,1);
        delay_ms(2000);
        GPIO_write(GPIOC,2,0);

        GPIO_write(GPIOC,3,1);
        delay_ms(2000);
        GPIO_write(GPIOC,3,0);

    }

}

void EXTI15_10_IRQHandler(void)
{
    if (EXTI_isset(EXTI10)) {
        // pushbutton X
        start = !start;
        EXTI_clear(EXTI10);
    }
}

void EXTI4_IRQHandler(void)
{
    if (EXTI_isset(EXTI4)) {
        // pushbutton Y
        EXTI_clear(EXTI4);
    }
}

void EXTI9_5_IRQHandler(void)
{
    if (EXTI_isset(EXTI5)) {
        // pushbutton Z
        EXTI_clear(EXTI5);
    }
    if (EXTI_isset(EXTI6)) {
        // pushbutton T
        GPIO_toggle(GPIOB, 0); // change state to the LED
        EXTI_clear(EXTI6);
    }
}

void loop(void)
{
    startSemaforo(start);
    
}

int main()
{
    setup();
    for (;;) {
        loop();
    }
}