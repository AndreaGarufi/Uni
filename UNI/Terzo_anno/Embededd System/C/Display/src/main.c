#include "stm32_unict_lib.h"
#include <stdio.h>

int counter = 0;

int main() {
    GPIO_init(GPIOA);
    GPIO_init(GPIOB);
    GPIO_init(GPIOC);
    GPIO_init(GPIOD);
    //DISPLAY_init();
    // Configurazione pin dei segmenti
    GPIO_config_output(GPIOC, 9);  // a
    GPIO_config_output(GPIOC, 10); // b
    GPIO_config_output(GPIOC, 8);  // c
    GPIO_config_output(GPIOD, 2);  // d
    GPIO_config_output(GPIOA, 6);  // e
    GPIO_config_output(GPIOC, 6);  // f
    GPIO_config_output(GPIOC, 11); // g
    GPIO_config_output(GPIOA, 7);  // h

    // Configurazione pin dei digit
    GPIO_config_output(GPIOB, 12); // digit 0
    GPIO_config_output(GPIOA, 11); // digit 1
    GPIO_config_output(GPIOC, 5);  // digit 2
    GPIO_config_output(GPIOA, 12); // digit 3

    // write ‘‘0’’
    GPIO_write(GPIOC, 9, 1);  // ‘‘a’’ ON
    GPIO_write(GPIOC, 10, 1); // ‘‘b’’ ON
    GPIO_write(GPIOC, 8, 1);  // ‘‘c’’ ON
    GPIO_write(GPIOD, 2, 1);  // ‘‘d’’ ON
    GPIO_write(GPIOA, 6, 1);  // ‘‘e’’ ON
    GPIO_write(GPIOC, 6, 1);  // ‘‘f’’ ON
    GPIO_write(GPIOC, 11, 0); // ‘‘g’’ OFF
    GPIO_write(GPIOA, 7, 0);  // ‘‘h’’ OFF

    GPIO_write(GPIOB, 12, 1); // digit 0 ON
    GPIO_write(GPIOA, 11, 0); // digit 1 OFF
    GPIO_write(GPIOC, 5, 0);  // digit 2 OFF
    GPIO_write(GPIOA, 12, 1); // digit 3 ON

    for (;;) {}
}