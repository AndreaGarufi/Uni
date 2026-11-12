#include <stdio.h>
#include "stm32_unict_lib.h"

#define PERIOD_PWM 1000     //questo è il periodo dell'onda PWM ed è il valore massimo del contatore del timer

int main(void) 
{
    DISPLAY_init();
    
    GPIO_init(GPIOB);
    GPIO_config_alternate(GPIOB, 0, 2); // AF2 --> TIM3_CH3     //configura il pin 0 della porta B in alternate funciton, si collega al canale 3 del timer 3

    ADC_init(ADC1, ADC_RES_8, ADC_ALIGN_RIGHT); //l'ADC converte una lettura analogica in un valore numerico digitale (quindi discreto),imposta la risoluzione a 8 bit, quindi i valori analogici saranno mappati su 8 bit quindi da 0 a 255, allinea il risultato a destra del registro
    ADC_channel_config(ADC1, GPIOC, 0, 10); //associa la GPIOC pin 0 (PC0) al canale 10 dell'ADC1 (guardare foto schema di collagamento nella nota obsidian 2 2_ottobre_26)
    ADC_on(ADC1);   //accende il modulo ADC1
    ADC_sample_channel(ADC1, 10);   //seleziona il canale 10 come il canale da campionare   (in totale ho 16 canali)

    TIM_init(TIM3); //inizializzo il timer 3
    TIM_config_timebase(TIM3, 420, PERIOD_PWM); //imposto il prescaler a 420 e ARR (valore massimo del counter prima di azzerarsi) a 1000
    TIM_set(TIM3, 0);   //imposto counter a 0
    TIM_config_PWM(TIM3, 3); //Attiva la generazione del segnale PWM sul Canale 3 di timer 3
    TIM_on(TIM3);   //attiva il timer

    for (;;) {
        ADC_start(ADC1);    //attiva una singola conversione analogico digitale (Prendi la tensione elettrica presente in questo momento sul pin selezionato e inizia a convertirla in un numero)
        while (!ADC_completed(ADC1)) {} //anttende che la conversione sia terminata (mi metto ad aspettare perche non è la CPU a fare la conversione ma un componente hardware, altrimenti il mio programma andrebbe avanti)

        int t_on = (ADC_read(ADC1) * PERIOD_PWM) / 255;   //ADC_read legge il valore numerico preso dalla conversione (0-255) e lo scala sul valore di PWM (Se ADC = 0 -> t_on = 0Se ADC = 255 -> t_on = 1000)
        TIM3->CCR3 = t_on;  //Scrive direttamente nel registro CCR3 (Capture/Compare Register del Canale 3). Questo determina per quanti conteggi sul totale dei 1000 il segnale in uscita sul pin PB0 rimarrà a livello alto (ON).

        char s[5];
        sprintf(s, "%4d", t_on);        //formattazione e scrittura sul display
        DISPLAY_puts(0, s);
    }

    return 0;
}