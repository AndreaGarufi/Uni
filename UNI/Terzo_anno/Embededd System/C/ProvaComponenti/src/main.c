#include <string.h>
#include <stdio.h>
#include "stm32_unict_lib.h"

int t_on_1;
int t_on_2;

void setup(void)
{
    ClockConfig();
    // configure the clock @ 84 MHz
    DISPLAY_init();
    CONSOLE_init();
    GPIO_init(GPIOB); // initialize port B
    GPIO_init(GPIOC); // initialize port C
    GPIO_config_output(GPIOB, 0); // configure pin PB0 as output
    GPIO_config_output(GPIOC, 3); // configure pin PB3 as output
    GPIO_config_output(GPIOC, 2);// configure pin PB2 as output

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

    ADC_init(ADC1, ADC_RES_8, ADC_ALIGN_RIGHT); //l'ADC converta una lettura analogica in un valore numerico digitale (quindi discreto),imposta la risoluzione a 8 bit, quindi i valori analogici saranno mappati su 8 bit quindi da 0 a 255, allinea il risultato a destra del registro
    ADC_channel_config(ADC1, GPIOC, 0, 10); //associa la GPIOC pin 0 (PC0) al canale 10 dell'ADC1 (guardare foto schema di collagamento nella nota obsidian 2 2_ottobre_26)
    ADC_on(ADC1);   //accende il modulo ADC1
    
    ADC_channel_config(ADC1, GPIOC, 1, 11); //associa la GPIOC pin 0 (PC0) al canale 10 dell'ADC1 (guardare foto schema di collagamento nella nota obsidian 2 2_ottobre_26)
    

    TIM_init(TIM3); //inizializzo il timer 3
    TIM_config_timebase(TIM3, 420, 1000); //imposto il prescaler a 420 e ARR (valore massimo del counter prima di azzerarsi) a 1000
    TIM_set(TIM3, 0);   //imposto counter a 0
    TIM_config_PWM(TIM3, 3); //Attiva la generazione del segnale PWM sul Canale 3 di timer 3
    TIM_on(TIM3);   //attiva il timer

    TIM_init(TIM4); //inizializzo il timer 4
    TIM_config_timebase(TIM4, 84000, 3000); //imposto il prescaler a 420 e ARR (valore massimo del counter prima di azzerarsi) a 1000
    TIM_enable_irq(TIM4,IRQ_UPDATE);
    TIM_set(TIM4, 0);   //imposto counter a 0
    TIM_on(TIM4);   //attiva il timer 


}

void EXTI15_10_IRQHandler(void)
{
    if (EXTI_isset(EXTI10)) {
        // pushbutton X
        GPIO_write(GPIOC, 3, 0);
        EXTI_clear(EXTI10);
    }
}

void EXTI4_IRQHandler(void)
{
    if (EXTI_isset(EXTI4)) {
        // pushbutton Y
        GPIO_write(GPIOC, 2, 0);
        EXTI_clear(EXTI4);
    }
}

void EXTI9_5_IRQHandler(void)
{
    if (EXTI_isset(EXTI5)) {
        // pushbutton Z
        GPIO_write(GPIOB, 0, 0);
        EXTI_clear(EXTI5);
    }
    if (EXTI_isset(EXTI6)) {
        // pushbutton T
        GPIO_write(GPIOB, 0, 1);
        GPIO_write(GPIOC, 2, 1);
        GPIO_write(GPIOC, 3, 1);
        EXTI_clear(EXTI6);
    }
}

void TIM4_IRQHandler(void){
    printf("Trimmer sopra (11): %4d\n", t_on_2);


    TIM_update_clear(TIM4);
}

void loop(void)
{
    ADC_sample_channel(ADC1, 10);       // Seleziona il canale 10
    ADC_start(ADC1);                    // Avvia la conversione
    while (!ADC_completed(ADC1)) {}     // Attende la fine
    int val_trimmer1 = ADC_read(ADC1);  // Salva il valore (0-255)

    // --- LETTURA SECONDO TRIMMER (Canale 11 - PC1) ---
    ADC_sample_channel(ADC1, 11);       // Cambia il multiplexer sul canale 11
    ADC_start(ADC1);                    // Avvia una nuova conversione
    while (!ADC_completed(ADC1)) {}     // Attende la fine
    int val_trimmer2 = ADC_read(ADC1);  // Salva il valore (0-255)

    // --- UTILIZZO DEI VALORI ---
    t_on_1 = (val_trimmer1 * 1000) / 255;
    t_on_2 = (val_trimmer2 * 1000) / 255;

    TIM3->CCR3 = t_on_1; // Esempio: il primo trimmer controlla il PWM sul canale 3 (PB0)
    TIM3->CCR3 = t_on_2; // Esempio: il primo trimmer controlla il PWM sul canale 3 (PB0)

    
    // Esempio: visualizzo sul display il valore del secondo trimmer (o li alterni)
    char s[5];
    sprintf(s, "%4d", t_on_1);
    DISPLAY_puts(0, s);
    


}

int main()
{
    setup();
    for (;;) {
        loop();
    }
}