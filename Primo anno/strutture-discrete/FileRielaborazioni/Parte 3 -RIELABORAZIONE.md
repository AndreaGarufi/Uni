**Parte III: Calcolo Combinatorio e Probabilità Discrete**

**Contenuti**
![[Pasted image 20241224085109.png|400]]


Di seguito delle domande di esempio alla quale risponderemo dopo aver introdotto il calcolo combinatorio:

- **Domanda 1:** Se sto scrivendo un programma che simula il poker, il mio programma deve fare in modo che la probabilità di un poker d'assi servito sia quella giusta. Ma qual è tale probabilità?
- **Domanda 2:** Quanti sono i codici PIN di una carta bancomat a 5 cifre e quante sono le probabilità che un ladro riesca ad indovinare entro 3 tentativi? 
- **Domanda 3:** Quante sono le possibili password fatte di 8 simboli alfa-numerici (maiuscole e minuscole sono diverse) e quanto tempo ci mette un programma che genera 1000 password al secondo a trovare quella giusta?
- **Domanda 4:** Se dovessi scommettere che in un’aula con 20 persone, ce ne siano almeno 2 che fanno il compleanno lo stesso giorno, scommetterei di si oppure no? E se ce ne sono 30, 40, 50 o più di persone?
- **Domanda 5:** Quante squadre di calcio diverse posso formare da un gruppo di 50 studenti?


**Regola della somma**
Se vogliamo contare quanti elementi appartengono all'unione di 2 insiemi (con nessun elemento in comune) basta fare |A| + |B|:
es. A = 23 elementi B = 23 elementi, 23+23 = 46
**Regola del prodotto**
Se vogliamo contare quanti sono le possibili coppie di elementi, il primo scelto da A e il secondo da B ci basta fare |A|∗|B|.

- Se denotiamo con A tutte le lettere dell'alfabeto minuscole e con B tutte le lettere dell'alfabeto maiuscole allora il numero di coppie possibili sono 26∗26=676

- Più in generale se dobbiamo fare k operazioni di scelta, tali che la prima si può fare in $n_1$ modi, la seconda in $n_2$ modi indipendenti dalla scelta precedenti, la i-esima in $n_i$ modi e quindi la k-esima in $n_k$ modi diversi allora il numero di scelte totali è
                          $n_1 · n_2 · .... · n_k$     

Con la regola del prodotto possiamo già rispondere parzialmente a 2 delle domande:

Quanti sono i codici PIN di una carta bancomat a 5 cifre? -> $10^5=100000$ 

Quante sono le password fatte di 8 simboli alfa-numerici ? Se consideriamo equivalenti lettere maiuscole e minuscole, allora la risposta è -> $36^8=2.821.109.907.456$
se invece considerassimo 62 caratteri abbiamo ->$62^8=218.340.105.584.896$

**Disposizioni e combinazioni**

