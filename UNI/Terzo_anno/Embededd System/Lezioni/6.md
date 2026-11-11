# **TIMER**
Un timer è un circuito che permette al software di avere contezza del tempo
- Per semplificare possiamo dire che è una variabile globale (timer counter) che si incrementa o decrementa sulla base di una sorgente di clock
- La variabile timer counter può essere letta o scritta dal software
- Un timer può generare interrupts
- Può essere usato in 2 modi:
  - Il timer funziona in **uscita**. Conta in autonomia fino a un certo valore di soglia e, ogni volta che lo raggiunge, commuta uno pin del microcontrollore e serve a generare segnali periodici.
  - Il timer funziona in **ingresso**. Rimane in ascolto su un pin: quando rileva una variazione di tensione (un fronte di salita $\uparrow$ o di discesa $\downarrow$), "fotografa" e salva immediatamente il valore corrente del suo contatore interno. Serve a misurare la frequenza, il periodo o la durata (ampiezza) di un impulso esterno con precisione al microsecondo.
  - *Il timer è completamente slegato dall'attività della CPU*, se la CPU è ferma il timer continua comunque a funzionare.

**Un timer è formato da 3 componenti hardware**
- La *clock source* -> il circuito che genera il tick per il timer
- La *time base* -> il circuito che si occupa di prendere il segnale dalla clock source e incrementare il counter
- Lo *slave circuit* -> è un circuito che guarda il contenuto del registro e in base al codice interagisce con altre componenti come pin e GPIO

Gli MCU STM32 offrono vari timer/counters con le seguenti funzionalità:
- Selezione del clock, interno esterno o altro
- Risoluzione di counter variable a 16 o 32 bit
- Un prescaler programmabile (il prescaler è quel componente che prende la sorgente di clock della scheda che gira a frequenze elevatissime e **rallentarlo** dividendo la frequenza per un valore intero programmabile, prima di inviare i "tick" al contatore vero e proprio.)
- Quattro canali indipendenti configurabili come: Input Capture, Output Compare, PWM Mode, One-pulse Output
- Generazione di interrupt sulla base di specifici eventi 

---

**L'interfaccia software dei timer**
Ogni timer presente ha diversi SFR (special function register) e sono tutti accessibili tramite le variabili globali chiamate TIMx dove la x sta per il numero del timer TIM1, TIM2 ecc...

Il tipo di queste variabili è `TIM TypeDef *` cioè un puntatore ad una struct i cui campi sono i vari SFR del timer

---

**Sorgente di clock**
La sorgente di clock del timer può essere di vari tipi:
- Interna (clock di sistema, è il default)
- Esterno (proveniente da un pin)
- Esterno in QUEI mode (Quadrature-encoder interface)
- Vari gate/trigger possono essere configurati in modo da fare da start/stop sulla base di specifici eventi

---

**Conteggio del tempo e incremento del counter**
Il conteggio è gestito dai seguenti registri
- TIMx->PSC: il registro del prescaler che specifica il fattore di divisione
- TIMx->CNT: il registro del contatore, contiene il valore del counter e lo incrementa/decrementa in base al clock in ingresso
- TIMx->ARR: il registro di "auto-reload", il suo valore viene impostato dal programmatore e CNT conta fino ad ARR, poi CNT ritorna a 0 e ricomincia
- Quando CNT ricomincia può generare un evento che causa un interrupt

---
**Funzioni per i timer nella libreria stm32_unict_lib**
> [!warning] al momento stm32_unict_lib supporta i timer dal TIM2 al TIM5, il TIM5 è utilizzato anche dal display

Vediamo delle funzioni utili:
 - Inizializzazione del timer:
   `void TIM_init(TIM TypeDef * timer);`
 - Configurare la timebase
   `void TIM_config_timebase(TIM_TypeDef * timer, uint32_t prescaler, uint32_t autoreload);`
 - Startare il timer:
   `void TIM_on(TIM TypeDef * timer);`
 - Stoppare il timer:
   `void TIM_off(TIM TypeDef * timer);`
 - Leggere il counter:
   `int32_t TIM_get(TIM TypeDef * timer);`
 - Scrivere sul counter:
   `void TIM_set(TIM TypeDef * timer, int32 t value);`
 - Controllare se un evento di update è avvenuto:
   `int TIM_update_check(TIM TypeDef * timer);`
 - Pulire la notifica di un evento di update:
   `void TIM update clear(TIM TypeDef * timer);`
 - Abilitare gli interrupt:
   `void TIM_enable_irq(TIM TypeDef * timer, int irq type);`

Vediamo adesso un esempio:
*Accendere un led ogni 500ms*
- La clock source interna al STM è 84 MHz, circa un oscillazione ogni 12 ns
- Dobbiamo ricavare un periodo di 500 ms
- Usiamo un fattore di divisione di 8400 in modo da avere un clock count signal di 0.1 ms, quindi se volessimo un periodo di 500 ms dobbiamo avere 5000 incrementi
![[Pasted image 20261103110353.png|522]]

- Configuriamo quindi i registri del prescaler a 8400 (TIMx->PSC) e quello di autoreload a 5000 (TIMx->ARR)
- Controlliamo l'update event che genererà l'interrupt in cui accenderemo il led
- Quando avviene facciamo il toggle del led e puliamo l'evento
(tutto con le funzioni viste prima)

Vediamo quindi il codice (facendo polling e quindi senza interrupt): 
```
#include "stm32_unict_lib.h"

int main()
{
    // LED at PC3
    GPIO_init(GPIOC);
    GPIO_config_output(GPIOC, 3);

    // init the timer
    TIM_init(TIM2);

    // Configure the timebase
    // Counter clock set to 0.1 ms (84MHz / 8400 = 10kHz -> T = 0.1 ms)
    // Period = 5000 counts * 0.1 ms = 500 ms
    TIM_config_timebase(TIM2, 8400, 5000);

    TIM_set(TIM2, 0); // resets the counter
    TIM_on(TIM2);     // starts the timer

    // infinite loop
    for (;;) {
        // check the update event (polling)
        if (TIM_update_check(TIM2)) {
            GPIO_toggle(GPIOC, 3);
            
            // clear the update event
            TIM_update_clear(TIM2);
        }
    }
}
```

>[!info] Cosa vuol dire polling?
>Nel contesto dei sistemi embedded e della programmazione I/O, **"polling"** (o _fare polling_) significa **controllare continuamente via software lo stato di un registro hardware o di un flag** all'interno di un ciclo (loop) finché non si verifica un determinato evento.
>Polling VS interrupt
>- **Polling (Attesa attiva / Busy Waiting):** Il processore è completamente dedicato a "guardare" il flag. È semplice da implementare ma **spreca cicli di CPU**, impedendo l'esecuzione di altro codice durante i $500\text{ ms}$ di attesa.
>- **Interrupt (Interruzione):** Il processore fa altro; quando il timer scatta, l'hardware interrompe la CPU ed esegue una funzione dedicata (ISR).

**Utilizzare gli interrupt**
Ogni evento può essere usato per generare interruzioni hardware ed eseguire ISR, questa funzionalità può essere attivata settando degli specifici bits nel SFR del timer.

Per abilitarli usiamo questa funzione:
`void TIM_enable_irq(TIM TypeDef * timer, int irq type);`
Dove `irq_type` è settato a `IRQ_UPDATE`.
Quando si verifica l'evento, si attiva una specifica ISR chiamata: `TIMx IRQHandler`
l'ISR deve gestire l'evento e poi notificare la pulizia con `TIM update clear()`

Vediamo un esempio usando gli interrupt e un button:
```
#include "stm32_unict_lib.h"

bool flashing = false;

int main()
{
    int last_key_state;
    // LED at PC3
    GPIO_init(GPIOC);
    GPIO_config_output(GPIOC, 3);
    // pushbutton X (PB10)
    GPIO_init(GPIOB);
    GPIO_config_input(GPIOB, 10);

    // init the timer
    TIM_init(TIM2);

    // Configure the timebase
    // Counter clock set to 0.1 ms
    TIM_config_timebase(TIM2, 8400, 5000);

    TIM_enable_irq(TIM2, IRQ_UPDATE);
    TIM_set(TIM2, 0); // resets the counter
    TIM_on(TIM2); // starts the timer

    last_key_state = GPIO_read(GPIOB, 10);
    for (;;) {
        int current_key_state = GPIO_read(GPIOB, 10);
        if (last_key_state == 1 && current_key_state == 0) flashing = !flashing;
        last_key_state = current_key_state;
    }
}

void TIM2_IRQHandler(void){
	if(flashing){
		GPIO_toggle(GPIOC,3);
	}else{
		GPIO_write(GPIOC,3,0);
	}
	TIM_update_clear(TIM2);
}
```

---
##### Altre funzionalità e aggiunte dei semafori
**Slave circuit**
![[Pasted image 20261106205909.png]]

I timer hanno degli *slave circuit* e possono essere usati per:
- Generare particolari segnali periodici
- Per misurare il periodo dei segnali in input

Ogni STM32 ha 4 slave channel, ogni channel può essere connesso ad una linea GPIO e può essere programmato per:
- **input capture**: cattura il valore corrente del contatore al verificarsi di un evento esterno.
- **PWM input measurement**: una variante del primo.
- **Output compare**: confronta costantemente il valore del contatore con un valore di riferimento memorizzato, quando coincidono il canale può generare un interrupt o cambiare lo stato di un pin di uscita.
- **PWM output generation**: utilizza il meccanismo di output compare per generare in modo autonomo un segnale ad onda quadra a frequenza e duty cicle variabili (controllo di motori)

> [!info] Cosa è il duty cicle ?
> Il **duty cycle** (o _ciclo di lavoro_) è la percentuale di tempo in cui un segnale, un dispositivo o un sistema è in stato **attivo** (ON) rispetto al tempo totale di un ciclo di funzionamento (periodo).
> Valori tipici:
> - **0%**: Segnale costantemente spento ($t_{\text{ON}} = 0$).
> - **25%**: Il segnale è attivo per un quarto del periodo e spento per tre quarti.
> - **50%**: Onda quadra perfetta (tempo ON uguale al tempo OFF).
> - **75%**: Il segnale è attivo per tre quarti del periodo.
> - **100%**: Segnale costantemente attivo ($t_{\text{OFF}} = 0$, tensione continua fissa).


Ogni canale ha un registro aggiuntivo: **CCRy** (Capture/Compare Register) -> Ha la stessa dimensione in bit del contatore del timer (o 16 o 32 bit) e in modalità **Input Capture**, memorizza il valore di `CNT` nel momento dell'evento su pin. In modalità **Output Compare / PWM**, memorizza il valore target di confronto per impostare il punto di commutazione del segnale di uscita.

**Input Capture**
- Quando un canale *y* è configurato come input capture, la corrispondente linea GPIO deve essere configurata come input.

![[Pasted image 20261106211957.png]]

- Il circuito è in grado di rilevare un "edge" (rising o falling) nel segnale di input in accordo con la configurazione.
- Quando si verifica effettivamente un edge il valore del counter è copiato nel registro CCRy
- *Un capture-event interrupt viene generato*

**Funzioni della libreria stm32_unict_lib per l'input capture** 
- Configurare il channel
  `void TIM_config_IC(TIM_TypeDef * tim, int channel, IC_Mode_mode)`
  - tim -> è il timer 
  - channel -> è lo slave channel da 1 a 4
  - mode -> è la modalità della cattura: IC_RISING_EDGE, IC_FALLING_EDGE, IC_BOTH_EDGES
- Controllare un evento di cattura:
  `int TIM_cc_check(TIM_TypeDef * tim, int channel)`
  - tim -> è il timer
  - channel -> è lo slave channel da 1 a 4
  - ritorna true o false
- Pulire un evento di cattura:
  `void TIM_cc_clear(TIM_TypeDef * tim, int channel)`
  - tim -> è il timer
  - channel -> è lo slave channel da 1 a 4

**Caso studio: test di reazione**
Obbiettivo: Vogliamo misurare il tempo di reazione di una persona: accendiamo un LED e aspettiamo che la persona prema il button, noi misuriamo il tempo passato tra l'accensione del LED e la pressione del button, dopo 5 secondi notifichiamo un timeout
(misuriamo tutto con la modalità input capture)

```
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
```

---
##### PWM output
![[Pasted image 20261107192243.png|546]]

Un canale *y* può essere configurato per generare un PWM signal con una specifica frequenza/periodo e duty cicle
Il periodo è definito in termini di *count unit* e il valore deve essere assegnato al registro ARR del timer
Il duty cicle p specificato come la durata della parte positiva del segnale, anche questo è definito in termini di *count unit* e il valore deve essere assegnato al registro **CCRy** 


**Funzioni della libreria stm32_unict_lib per la PWM output**
- Per configurare il canale PWM si usa la seguente funzione:
  `void TIM_config_PWM(TIM_TypeDef * tim, int channel)`
- Il periodo è settato ad "autoreload" nel parametro della funzione: `TIM_config_timebase`
- Il duty cicle è settato assegnando il registro CCRy

**Caso studio: Controllo dell'intensità di un LED usando PWM output**
```
#include <stdio.h>
#include "stm32_unict_lib.h"

#define PERIOD_PWM 1000

int main(void) 
{
    DISPLAY_init();
    
    GPIO_init(GPIOB);
    GPIO_config_alternate(GPIOB, 0, 2); // AF2 --> TIM3_CH3

    ADC_init(ADC1, ADC_RES_8, ADC_ALIGN_RIGHT);
    ADC_channel_config(ADC1, GPIOC, 0, 10);
    ADC_on(ADC1);
    ADC_sample_channel(ADC1, 10);

    TIM_init(TIM3);
    TIM_config_timebase(TIM3, 420, PERIOD_PWM);
    TIM_set(TIM3, 0);
    TIM_config_PWM(TIM3, 3); // channel 3
    TIM_on(TIM3);

    for (;;) {
        ADC_start(ADC1);
        while (!ADC_completed(ADC1)) {}

        int t_on = (ADC_read(ADC1) * PERIOD_PWM) / 255;
        TIM3->CCR3 = t_on;

        char s[5];
        sprintf(s, "%4d", t_on);
        DISPLAY_puts(0, s);
    }

    return 0;
}
```
File su vs code:
![[Terzo_anno/Embededd System/C/LedIntensityControlPWMoutput/src/main.c]]

Il programma gira intorno al fatto che attraverso la rotazione della manopola del trimmer, leggo il valore analogico e lo converto in digitale e uso quel valore per generare un onda quadra (acceso/spento) con un duty cycle variabile, in questo modo cambio la luminosità del LED
![[Pasted image 20261111114631.png|720]]

Più il duty cycle è alto e più il led sarà luminoso perche gli arriva lo stato di acceso più di frequente (si possono vedere ad occhio nudo gli effetti dell'onda quadra se si cambia il codice impostando prescaler a 420000 e lasciando PERIOD_PWM = 1000)

