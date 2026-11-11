/*
 * CONSEGNA ESERCIZIO: Gestione Interrupt EXTI e ISR su NUCLEO-F401RE
 * 
 * Obiettivo: Realizzare un sistema di conteggio eventi gestito interamente tramite 
 * interrupt esterni (EXTI) e routine di servizio (ISR), con segnalazione di allarme.
 * 
 * Requisiti di funzionamento:
 * 1. Pressione Pulsante X (PB10): Genera un interrupt (EXTI15_10) su fronte di discesa 
 *    per incrementare il valore del contatore globale.
 * 2. Pressione Pulsante Y (PB4): Genera un interrupt (EXTI9_5) su fronte di discesa 
 *    per decrementare il valore del contatore globale (valore minimo = 0).
 * 3. Pressione Pulsante Z (PB5): Genera un interrupt (EXTI9_5) su fronte di discesa 
 *    per azzerare il contatore globale.
 * 4. LED Rosso (PB0): Viene acceso nel ciclo principale se il contatore supera 
 *    o raggiunge la soglia di allarme (valore >= 5), altrimenti rimane spento.
 * 5. Display a 7 segmenti: Visualizza in tempo reale il valore del contatore nel main.
 * 
 */
#include "stm32_unict_lib.h"
#include <stdio.h>

volatile int contatore = 0;

void setup(void)
{
    ClockConfig();
    // configure the clock @ 84 MHz
    GPIO_init(GPIOB); // initialize port B
    GPIO_init(GPIOC); // initialize port C
    GPIO_config_output(GPIOB, 0); // configure pin PB0 as output
    GPIO_config_output(GPIOC, 3); // configure pin PB3 as output

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

    DISPLAY_init();
    CONSOLE_init();
}

void EXTI15_10_IRQHandler(void)
{
    if (EXTI_isset(EXTI10)) {
        // pushbutton X
        contatore++;
        printf("Contatore: %d\n",contatore);

        EXTI_clear(EXTI10);
    }
}

void EXTI4_IRQHandler(void)
{
    if (EXTI_isset(EXTI4)) {
        // pushbutton Y
        if(contatore > 0){
            contatore--;
            printf("Contatore: %d\n",contatore);

        }else{
            printf("Contatore al valore minimo.\n");

        }
        EXTI_clear(EXTI4);
    }
}

void EXTI9_5_IRQHandler(void)
{
    if (EXTI_isset(EXTI5)) {
        // pushbutton Z
        contatore = 0;
        printf("Contatore azzerato\n");

        EXTI_clear(EXTI5);
    }
    if (EXTI_isset(EXTI6)) {
        // pushbutton T
       // GPIO_toggle(GPIOB, 0); // change state to the LED
        EXTI_clear(EXTI6);
    }
}

void loop(void)
{
    //delay_ms(200);
    //GPIO_toggle(GPIOC, 3);

    if(contatore >= 5){
        GPIO_write(GPIOB,0,1);
    }else{
        GPIO_write(GPIOB,0,0);
    }
    
    DISPLAY_putc(0, '0' + contatore);
    

}

int main()
{
    setup();
    for (;;) {
        loop();
    }
}