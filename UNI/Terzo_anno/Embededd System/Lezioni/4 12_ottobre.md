# **Interrupt**

Ogni linea di ingresso digitale può attivare un **IRQ** (interruzione hardware).
Ad esempio con la pressione di un pulsante o la lettura di un sensore.
L'interruzione non deve essere attiva continuamente ma solo in determinati casi.
Un IRQ può essere configurato per essere attivato:
- *Falling edge* -> si attiva solo se il segnale proveniente dalla linea di input passa da 1 a 0
- *Risign edge* -> si attiva solo se il segnale proveniente dalla linea di input passa da 0 a 1ù
- *Both edge* -> si attiva ad ogni variazione di segnale


*External interupt controller* (EXTI)
È il modulo hardware/circuito all'interno del microcontrollore dedicato a gestire queste interruzioni esterne.
Si occupa di rilevare le transizioni sui pin di I/O, applicare le configurazioni selezionate (fronte di salita, discesa o entrambi) e inoltrare la richiesta di interruzione (IRQ) al processore centrale.

![[Pasted image 20261018115902.png|665]]

L'EXTI gestisce internamente 23 linee di interrupt chiamate EXTI0, EXTI1, ... , EXTI22.
- Le linee dalla 0 alla 15 possono essere connesse agli input GPIO.
  Per questo motivo viene usato un **Multiplexer**:
  La linea **EXTI0** può essere collegata a **PA0, PB0, PC0, ...** (ma a **uno solo** di essi alla volta).
  La linea **EXTI1** può essere collegata a **PA1, PB1, PC1, ...** e così via fino alla linea **EXTI15** (PA15, PB15, PC15...).
  Al massimo **16 ingressi digitali esterni** possono generare interruzioni contemporaneamente
- Le linee da EXTI16 a EXTI22 **non provengono dai pin di I/O esterni**, ma sono collegate internamente ad altre periferiche del chip (ad esempio: segnale di wake-up del RTC - Real Time Clock, eventi USB, rilevamento di tensione PVD, ecc.).
- L'EXTI elabora tutti questi eventi e invia le linee di interruzione (IRQ) risultanti verso il processore / controller delle interruzioni (NVIC) per eseguire le rispettive _Interrupt Service Routine_ (ISR).

![[Pasted image 20261018120812.png]]


---

##### Come usare gli interrupt
1) Configurare il multiplexer in modo da connettere un pin GPIO alla linea EXTI
2) Configurare la linea EXTI per gestire l'interrupt specificando il *signal edge*
   - Falling edge
   - Rising edge
   - Both edge
3) Scrivere la **Interrupt Service Routine** per quella linea EXTI in cui al suo interno andrà gestito l'interrupt e andrà cancellato mediante una chiamata a funzione

---
##### stm32 unict lib EXTI functions
Nella nostra libreria di unict andremo a configurare le EXTI in questa maniera:

**Configurazione del Multiplexer**
`void GPIO_config_EXTI(GPIO_TypeDef *gpio, EXTI_line exti);`
* **`gpio`**: rappresenta la porta I/O (es. `GPIOA`, `GPIOB`, ...).
* **`exti`**: rappresenta la linea EXTI da associare, selezionabile tra le costanti `EXTI0`, `EXTI1`, ..., `EXTI15`.

**Abilitazione di una Linea EXTI tramite Configurazione del Fronte**
`void EXTI_enable(EXTI_line exti, edge_type edge);`
* **`exti`**: rappresenta la linea EXTI, selezionabile tra le costanti `EXTI0`, `EXTI1`, ..., `EXTI15`.
* **`edge`**: rappresenta la tipologia di fronte d'onda, selezionabile tra le costanti `RISING_EDGE`, `FALLING_EDGE` o `BOTH_EDGES`.


**Nei microcontrollori ST...**
```
void EXTI0 IRQHandler(void), line EXTI0 
void EXTI1 IRQHandler(void), line EXTI1 
void EXTI2 IRQHandler(void), line EXTI2 
void EXTI3 IRQHandler(void), line EXTI3 
void EXTI4 IRQHandler(void), line EXTI4 
void EXTI9 5 IRQHandler(void), lines EXTI5 to EXTI9 
void EXTI15 10 IRQHandler(void), lines EXTI10 to EXTI15
```

Questi sono i prototipi delle funzioni per gestire gli interrupt, le prime 5 linee ne hanno una dedicata e poi altre 2 per le linee dalla 5 alla 9 e dalla 10 alla 15

Se ad esempio andassi a configurare la linea EXTI0 andrò a gestire il suo interrupt usando come prototipo la prima funzione.

---
##### stm32 unict lib functions per controllare e pulire IRQs
**Verifica dell'Occorrenza di un'interrupt (IRQ)**
`int EXTI_isset(EXTI_line exti);`
* **`exti`**: rappresenta la linea EXTI da controllare, selezionabile tra le costanti `EXTI0`, `EXTI1`, ..., `EXTI15`.
* **Valore di ritorno**: restituisce un valore diverso da zero (vero) se l'interruzione sulla linea specificata è pendente/attiva, `0` altrimenti.

---

**Azzeramento (Reset) dell'Occorrenza di un'interrupt (IRQ)**
`void EXTI_clear(EXTI_line exti);`
* **`exti`**: rappresenta la linea EXTI di cui resettare il flag, selezionabile tra le costanti `EXTI0`, `EXTI1`, ..., `EXTI15`.

> [! warning] **Nota:** La chiamata a `EXTI_clear` è fondamentale all'interno dell'ISR per cancellare il flag di interruzione pendente (*pending bit*), evitando che la CPU rientri all'infinito nella stessa funzione di gestione.


Vediamo un esempio di codice:
Led gestito con interrupt.
```
#include "stm32_unict_lib.h"

int main()
{
    ClockConfig();
    // LED at PC3
    GPIO_init(GPIOC);
    GPIO_config_output(GPIOC, 3);

    // pushbutton Y (PB4)
    GPIO_init(GPIOB);
    GPIO_config_input(GPIOB, 4);

    GPIO_config_EXTI(GPIOB, EXTI4);
    EXTI_enable(EXTI4, FALLING_EDGE);

    for (;;) { } // do nothing
}

void EXTI4_IRQHandler(void)
{
    if (EXTI_isset(EXTI4)) {
        GPIO_toggle(GPIOC, 3);
        EXTI_clear(EXTI4);
    }
}
```

