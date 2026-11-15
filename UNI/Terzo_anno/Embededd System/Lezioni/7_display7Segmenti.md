![[Pasted image 20261114174216.png|387]]
# **Funzioni per il display a 7 segmenti**
La libreria stm32_unict_lib fornisce delle funzioni utili che semplificano l'utilizza dello schermo.
Queste funzioni usano TIM5, quindi quando il display è attivo questo timer non è disponibile.
I numeri del display si contano da sinistra verso destra e vanno da 0 a 3

- Inizializzazione del display:
  `void DISPLAY_init(void)`
- Scrivere un carattere "c" nel numero "d"
  `void DISPLAY_putc(int d, char c)`
- Scrivere una stringa "s" partendo da un numero "d"
  `void DISPLAY_puts(int digit, char * s)`
- "Accendere e spegnere" la cifra decimale del numero "d"
  `void DISPLAY_dp(int digit, int on off)`

---

Andiamo più nel dettaglio del display:
Il display è composto da 4 cifre, ogni cifra è fatta da 8 LEDs (7 segmenti + il punto decimale)
Nella teoria ogni singolo led delle 4 cifre potrebbe essere acceso usando una GPIO, ma il numero di GPIO da dover utilizzare sarebbe troppo grande: 8 LEDs x 4 cifre = 32 GPIO!

In questa tipologia di display ogni segmento di una cifra è identificato da una lettera:A![[Pasted image 20261114174304.png|159]]

Per evitare di dover utilizzare tutte queste porte abbiamo adottato una soluzione che ne usa di meno:
In pratica si usa un singolo collegamento per ogni lettera (segmento) e un singolo collegamento per ogni cifra, in questo modo avendo 8 LEDs e 4 cifre portiamo il totale delle porte utilizzate a 12 anziché 32.
![[Pasted image 20261114174833.png|396]]
Per capirci se accendessimo PC9 accenderemmo il LED a di ogni cifra, a meno che non spegniamo le altre cifre utilizzando le porte in basso (es. vogliamo accendere solo il segmento a della prima cifra, accendiamo PC9 e PB12, tutto il resto sta spento)

---
##### Mappatura ASCII
Per mostrare i vari caratteri sul display occorre fare una mappatura dei codici ASCII di ogni carattere in un pattern specifico di bit che rappresenta il segmento da accendere:
Ad esempio:
![[Pasted image 20261114180054.png|464]]

per visualizzare 1 dovremmo accendere il bit b6 e b7 (caratteri b e c)
![[Pasted image 20261114180137.png|469]]

La mappatura può essere effettuata usando un array di `uint8_t` da 256 elementi:
`uint8_t character_table[256];` -> questa riga è proprio scritta dentro la stm32_unict_lib
![[Pasted image 20261114180512.png|321]]... per tutti i vari caratteri

Il passo successivo consiste nell'analizzare il bit pattern e scrivere il giusto valore sulla linea GPIO del relativo segmento, in base al parametro passato (una determinata lettera passata corrisponde ad uno dei valori dentro l'array, una volta individuato si accende il giusto segmento).

Ogni segmento è quindi associato:
- A un bit pattern (0x44,0x02,0xfe ...)
- Ad una porta GPIO (GPIOA,GPIOB ...)
- Ad uno specifico pin GPIO (9,10,8 ...)

C'è un problema: cosi come descritto noi possiamo solo gestire un segmento alla volta o comunque non possiamo accendere segmenti diversi di cifre diverse, il che è un problema, a meno che non usiamo un sistema di *time-sharing* per ogni segmento (per questo prima ho scritto che il timer 5 è occupato con il display inizializzato):
- definiamo un timer che genera un interrupt ad una frequenza altissima, < 1ms (cosi l'occhio umano non se ne accorge)
- ad ogni interrupt, spegniamo il segmento corrente e accendiamo l'altro (dopo aver fatto tutto il lavoro descritto prima), e cosi via...

In questo modo accendiamo e spegnami i vari led migliaia di volte al secondo ma tecnicamente nessun segmento è acceso contemporaneamente ad un altro.
Possiamo apprezzare questo meccanismo ad occhio nudo, semplicemente cambiando il valore del timer, anziché generare un interrupt ogni ms o meno, lo facciamo generare magari ogni 100 ms o più in questo modo vedremo proprio lo sfarfallio continuo di ogni segmento che si accende o si spegne.

Il programmatore scrive semplicemente i caratteri sul buffer e poi questo è il lavoro fatto dietro le quinte.