    #include "stm32_unict_lib.h"
    #include <stdbool.h>
    #include <stdio.h>

    int secondi = 0;
    int centesimi = 0;
    bool flag = false;
    int punti = 0;
    bool screen = false;
    bool giallo = false;
    int gialloCounter = 0;
    bool memoria = false;

    typedef struct{

        int secondiSalvati;
        int centesimiSalvati;

    }tempoSalvato;

    typedef struct{

        tempoSalvato datiArray;

    }arrayDati;

    arrayDati arraySalvati[10];
    int numeroElementi = 0;

    void setup(void)
    {
        ClockConfig();
        // configure the clock @ 84 MHz
        GPIO_init(GPIOB); // initialize port B
        GPIO_init(GPIOC); // initialize port C
        GPIO_config_output(GPIOB, 0); // configure pin PB0 as output LED ROSSO
        GPIO_config_output(GPIOC, 3); // configure pin PC3 as output LED VERDE
        GPIO_config_output(GPIOC, 2); // configure pin PC2 as output LED GIALLO
        GPIO_config_output(GPIOB, 8); // 2 punti dello schermo a 7 segmenti

        GPIO_config_input(GPIOB, 10); // configure pin PB10 as input PULSANTE X
        GPIO_config_input(GPIOB, 4); // configure pin PB4 as input   PULSANTE Y
        GPIO_config_input(GPIOB, 5); // configure pin PB5 as input   PULSANTE Z
        GPIO_config_input(GPIOB, 6); // configure pin PB6 as input   PULSANTE T

    
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

    void visualizzaMemoria(bool memory){

        if(memory == true){

            for(int i = 0; i < numeroElementi; i++){

                char s[10];
                sprintf(s, "%02d%02d", arraySalvati[i].datiArray.secondiSalvati, arraySalvati[i].datiArray.centesimiSalvati);
                DISPLAY_puts(0, s); 
                delay_ms(1000);

                if(flag == true){
                    memoria = false;
                    break;
                }
            }


        }
        return;

    }


    void screenShot(bool screenS){

        if(screenS == true){

            tempoSalvato dati;
            dati.centesimiSalvati = centesimi;
            dati.secondiSalvati = secondi;
        
        
            if(numeroElementi == 10){
                printf("Screen massimi raggiunti.\n");
                screen = false;
                return;
            }
            giallo = true;
            gialloCounter = 0;
            arraySalvati[numeroElementi].datiArray.centesimiSalvati = dati.centesimiSalvati;
            arraySalvati[numeroElementi].datiArray.secondiSalvati = dati.secondiSalvati;
            printf("ScreenShot salvato: secondi: %d, centesimi: %d.\n",arraySalvati[numeroElementi].datiArray.secondiSalvati,arraySalvati[numeroElementi].datiArray.centesimiSalvati);
            numeroElementi++;
            
            
        }

        screen = false;
        return;
    }

    void azzeraCrono(){
        secondi = 0;
        centesimi = 0;
        printf("Reset crono.\n");
        return;
    }

    void startCronometro(bool flag){

        if(flag == false){
            return;
        }

        delay_ms(10);
        centesimi ++; 
        punti++;
        gialloCounter++;
        if(giallo == true){
            GPIO_write(GPIOC,2,1);
            if(gialloCounter == 100){
                GPIO_write(GPIOC,2,0);
                giallo = false; 
            }
        }
               

        if(punti == 50){
            GPIO_toggle(GPIOB,8);
            punti = 0;
        }
        if (centesimi == 100) {
            secondi++;
            centesimi = 0;
        }

        //printf("Secondi: %d, centesimi: %d.\n",secondi,centesimi);

    }


    void EXTI15_10_IRQHandler(void)
    {
        if (EXTI_isset(EXTI10)) {
            // pushbutton X
            flag = !flag;
            EXTI_clear(EXTI10);
        }
    }

    void EXTI4_IRQHandler(void)
    {
        if (EXTI_isset(EXTI4)) {
            azzeraCrono();
            EXTI_clear(EXTI4);
        }
    }

    void EXTI9_5_IRQHandler(void)
    {
        if (EXTI_isset(EXTI5)) {
            // pushbutton Z
            screen = true;
            EXTI_clear(EXTI5);
        }
        if (EXTI_isset(EXTI6)) {
            // pushbutton T
            if(flag == false){
                GPIO_toggle(GPIOB, 0); // change state to the LED
                memoria = true;
            }
            EXTI_clear(EXTI6);
        }
    }



    void loop(void){


        char s[10];

        startCronometro(flag);
        screenShot(screen);
        sprintf(s, "%02d%02d", secondi, centesimi);
        visualizzaMemoria(memoria);
        DISPLAY_puts(0, s);     

    }

    int main()
    {
        setup();
        for (;;) {
            loop();
        }
    }