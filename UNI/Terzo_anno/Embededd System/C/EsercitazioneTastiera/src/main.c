/*
 * keypad.c
 */

#include <stdio.h>
#include "stm32_unict_lib.h"

// Mappatura dei tasti (4x4 standard)
/*const char keymap[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};*/

int contatore = 1;

void loop(){

switch (contatore) {
    case 1: // Colonna 1 -> PB4
        GPIO_write(GPIOA, 10, 1);
        GPIO_write(GPIOB, 3,  1);
        GPIO_write(GPIOB, 5,  1);
        GPIO_write(GPIOB, 4,  0);
        break;
    case 2: // Colonna 2 -> PB5
        GPIO_write(GPIOA, 10, 1);
        GPIO_write(GPIOB, 3,  1);
        GPIO_write(GPIOB, 5,  0);
        GPIO_write(GPIOB, 4,  1);
        break;
    case 3: // Colonna 3 -> PB3
        GPIO_write(GPIOA, 10, 1);
        GPIO_write(GPIOB, 3,  0);
        GPIO_write(GPIOB, 5,  1);
        GPIO_write(GPIOB, 4,  1);
        break;
    case 4: // Colonna 4 -> PA10
        GPIO_write(GPIOA, 10, 0);
        GPIO_write(GPIOB, 3,  1);
        GPIO_write(GPIOB, 5,  1);
        GPIO_write(GPIOB, 4,  1);
        break;
}

    delay_ms(70);
    contatore++;
    if(contatore > 4){
        contatore = 1;
    }

}

void EXTI15_10_IRQHandler(void)
{
    if (EXTI_isset(EXTI10)) {
        //PB10
        if(contatore == 1){
            //1
            printf("*\n");
        }
        if(contatore == 2){
            //2
            printf("0\n");
        }
        if(contatore == 3){
            //3
            printf("#\n");
        }
        if(contatore == 4){
            //A
            printf("D\n");
        }
        EXTI_clear(EXTI10);
    }
}

void EXTI9_5_IRQHandler(void)
{
    if (EXTI_isset(EXTI7)) {
        //PC7

        if(contatore == 1){
            //1
            printf("1\n");
        }
        if(contatore == 2){
            //2
            printf("2\n");
        }
        if(contatore == 3){
            //3
            printf("3\n");
        }
        if(contatore == 4){
            //A
            printf("A\n");
        }

        EXTI_clear(EXTI7);
    }
    if (EXTI_isset(EXTI8)) {
        //PA8
        if(contatore == 1){
            //1
            printf("7\n");
        }
        if(contatore == 2){
            //2
            printf("8\n");
        }
        if(contatore == 3){
            //3
            printf("9\n");
        }
        if(contatore == 4){
            //A
            printf("C\n");
        }
       
        EXTI_clear(EXTI8);
    }
    if (EXTI_isset(EXTI9)) {
        //PA9

        if(contatore == 1){
            //1
            printf("4\n");
        }
        if(contatore == 2){
            //2
            printf("5\n");
        }
        if(contatore == 3){
            //3
            printf("6\n");
        }
        if(contatore == 4){
            //A
            printf("B\n");
        }
       
        EXTI_clear(EXTI9);
    }
}

int main(void)
{
	ClockConfig();
	CONSOLE_init();

	GPIO_init(GPIOA);
	GPIO_init(GPIOB);
	GPIO_init(GPIOC);

	// cols
	// PA10, PB3, PB5, PB4
	GPIO_config_output(GPIOA, 10);
	GPIO_OPEN_DRAIN(GPIOA, 10);
	GPIO_write(GPIOA, 10, 1);

	GPIO_config_output(GPIOB, 3);
	GPIO_OPEN_DRAIN(GPIOB, 3);
	GPIO_write(GPIOB, 3, 1);

	GPIO_config_output(GPIOB, 5);
	GPIO_OPEN_DRAIN(GPIOB, 5);
	GPIO_write(GPIOB, 5, 1);

	GPIO_config_output(GPIOB, 4);
	GPIO_OPEN_DRAIN(GPIOB, 4);
	GPIO_write(GPIOB, 4, 1);

	// rows
	// PB10, PA8, PA9, PC7
	GPIO_config_input(GPIOB, 10);
	GPIO_PULL_UP(GPIOB, 10);
	GPIO_config_input(GPIOA, 8);
	GPIO_PULL_UP(GPIOA, 8);
	GPIO_config_input(GPIOA, 9);
	GPIO_PULL_UP(GPIOA, 9);
	GPIO_config_input(GPIOC, 7);
	GPIO_PULL_UP(GPIOC, 7);

    GPIO_config_EXTI(GPIOB, EXTI10); // attach PB10 to EXTI10
    GPIO_config_EXTI(GPIOA, EXTI8); 
    GPIO_config_EXTI(GPIOA, EXTI9); 
    GPIO_config_EXTI(GPIOC, EXTI7); 

    EXTI_enable(EXTI10, FALLING_EDGE);
    EXTI_enable(EXTI8, FALLING_EDGE);
    EXTI_enable(EXTI9, FALLING_EDGE);
    EXTI_enable(EXTI7, FALLING_EDGE);

	printf("Starting...\n");

	for(;;) { 

        loop();
    }
}

