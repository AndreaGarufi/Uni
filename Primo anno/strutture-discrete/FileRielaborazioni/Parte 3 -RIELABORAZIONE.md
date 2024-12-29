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

Proviamo a rispondere a queste 4 domande matematiche:
1) Dati due insiemi A e B, con |A| = k, |B| = n quante sono le applicazioni di A in B?         (Numero delle disposizioni con ripetizione di n elementi di classe k:denotato con $F_{n,k}$)
2) Dati due insiemi A e B, con |A| = k, |B| = n quante sono le applicazioni iniettive di A in B?(Numero delle disposizioni semplici di n elementi di classe k: denotato con $D_{n,k}$)
3) Dato un insieme B, con |B| = n, e preso un intero k ≤ n, quanti sono i sottoinsiemi di B composti di k elementi ?(Numero delle combinazioni di n elementi di classe k: denotato con $C_{n,k}$)
4) Dato un insieme di n variabili, {x1, x2, . . . , xn} e preso un un intero k ≤ n, quanti sono i monomi, con coefficiente 1, di grado k definiti sulle n variabili date? Esempio: $x^2_ 1 x^3x^3_4$ monomio di grado 6, $x^2_2 x^4x_5$ monomio di grado 4.(Numero delle combinazioni di n elementi di classe k con ripetizione: denotato con $C^r_{n,k}$)

 
 1) **Disposizioni con ripetizione**
Per calcolare $F_{n,k}$  utilizziamo la regola del prodotto, per ognuno dei k elementi di A dobbiamo scegliere uno tra gli elementi di B che sono in n. Ogni scelta è indipendente dalle scelte fatte precedentemente. Quindi:

$F_{n,k}$ = $n^k$

**Esempio di funzioni booleane**
Quante sono le funzioni booleane definite su un insieme di k variabili booleane? Sono tutte funzioni del tipo:

f : A -> {0,1}
dove |A| = k quindi,
 $F_{2,k} = 2^k$ 

2) **Disposizioni semplici**
Notiamo come prima cosa che affinché esista un'applicazione iniettiva da A in B, deve essere n ≥ k ( [[Parte 1 -RIELABORAZIONE- Logica Proposizionale, Teoria degli insiemi Relazioni e funzioni#Funzione iniettiva|vedi le funzioni]] ) Per calcolare $D_{n,k}$  utilizziamo la regola del prodotto. Dobbiamo fare k operazioni di scelta tali che:
1) la prima operazione si può fare in n modi
2) la seconda in n-1 modi
3) ...
4) la k-esima operazione si può fare in n-k+1 modi

**per riassumere il numero di scelte totali è $\frac{n!}{(n-k)!}$**  

**Esempio**

- Quante squadre di calcio diverse posso formare da un gruppo di 50 studenti?
- risposta (applico la formula $\frac{n!}{(n-k)!}$ ): $D_{50,11}$ = 50  · 49 · . . . · 40 ≈ $1,5 · 10^{18}$ 

**Le permutazioni o sostituzioni è il numero di disposizioni semplici di n cioè** $D_{n,n}$
ovvero n!

Se si prende B = A, spesso si indicano le permutazioni di classe n con il simbolo $P_n$ o $S_n$ nel caso si chiamino sostituzioni (sono la stessa cosa)
Possiamo vedere una permutazione come un ri-odinamento di n elementi:
es. A = {1,2,3}

$P_3$ = {(1, 2, 3), (1, 3, 2), (2, 1, 3), (2, 3, 1), (3, 1, 2), (3, 2, 1)}

$|P_3|$ = 3! = 6

**Combinazioni**
**Una combinazione** è un sottoinsieme di $k$ elementi scelti da un insieme di $n$ elementi, **senza tener conto dell'ordine** degli elementi.

In altre parole, due sottoinsiemi con gli stessi elementi ma in ordine diverso sono considerati la stessa combinazione.

si denotano con $C_{n,k}$ e i suoi valori sono i coefficienti binomiali: $\binom{n}{k}$ 

![[Pasted image 20241228152423.png||300]]

**Esempi**

![[Pasted image 20241228152951.png]]

**Teorema binomiale**
Siano a e b numeri reali. Allora vale l'uguaglianza:

![[Pasted image 20241228155756.png|350]]


Dato un insieme di n > 1 variabili, {$x_0, x_1, . . . , x_{n−1}$} e preso un un intero k, i monomi di grado k sono:
![[Pasted image 20241229100936.png|200]]

**Esempio**
![[Pasted image 20241229101511.png]]


**Per riassumere tutto in breve...**
![[Pasted image 20241229101609.png]]

https://uni-notes-girlando.netlify.app/Primo-anno/strutture-discrete/FileRielaborazioni/03_Parte3
$\uparrow$
qui tutta questa parte è spiegata bene se non capisci qui prova sul sito di Girlando

**Pigeonhole principle**

Nella sua forma più semplice, il Principio afferma che:
se dobbiamo fare entrare n + 1 piccioni in una piccionaia che contiene n cassette, allora almeno una cassetta dovrà contenere più di un piccione. 

**Esempio** 
Coppia di calzini:
- Immaginiamo di avere il cassetto di un comodino pieno di calzini, neri e blu
- Vogliamo, prendere al buio il numero minimo di calzini sufficiente ad avere una coppia completa
- Immaginiamo che ogni colore sia un "cassetto". Se prendiamo 3 calzini, almeno 2 calzini saranno dello stesso colore.
- infatti in questo caso possiamo avere o 3 calzini dello stesso colore, oppure 2 di un colore ed il terzo dell'altro colore


**Esempio**
Capelli Catanesi
- Un essere umano ha, in media, circa 110000 capelli sulla testa. Qualcuno arriva sino a 150000 mila. Se vogliamo esagerare, possiamo pensare che ci siano persone che abbiano sino a 200000 capelli in testa.
- Domanda: esistono a Catania due persone con lo stesso numero di capelli in testa?
- Risposta: si. Ed ecco la prova:
    - Catania città ha più di 300000 abitanti. 
    - Dal momento che il numero di abitanti è superiore al numero massimo di capelli possibile, esisteranno sicuramente almeno 2 abitanti di Catania che hanno lo stesso numero di capelli in testa.

(da slide 33 a 41 ci sono vari esempi e esercizi [[Parte3.pdf]])

-------------------
**CALCOLO COMBINATORIO E PROBABILITA' DISCRETE**

