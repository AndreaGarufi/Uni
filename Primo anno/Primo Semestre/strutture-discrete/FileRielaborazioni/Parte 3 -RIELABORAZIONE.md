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
![[Pasted image 20250116092009.png]]



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

Le probabilità sono definite su uno spazio di campioni S, i cui elementi sono detti eventi elementari. 
Ogni evento elementare è l’esito di un esperimento ed è un sottoinsieme dello spazio dei campioni. 
S stesso è l’evento certo, mentre ∅ è l’evento nullo Due eventi E1 e E2 sono mutuamente esclusivi se E1 ∩ E2 = ∅

**Esempio** 
Per l'esperimento del lancio di 2 monete, spazio dei campioni è costituito da tutte le possibili coppie S = {TT , TC, CT , CC}. L’evento "si ottiene una testa ed una croce" è E = {TC, CT}

La definizione classica della probabilità del verificarsi di un evento A è uguale al rapporto tra il numero di casi favorevoli ($f_A$) ed il numero di casi totali (n)

Probabilità di A = $\frac{f_A}{n}$ 

**notiamo che questa definizione assume che tutti gli eventi hanno la stessa probabilità di accadere** (si dice quindi che è una definizione circolare)

es. lancio dei dadi: ogni numero ha la stessa probabilità di uscire
**Questa definizione quindi non considera la possibilità di eventi non equiprobabili**


Semplificando il discorso, assumiamo di ripetere un esperimento n volte e verifichiamo quante volte si è verificato l’esito studiato. Per esempio, lanciamo il dado 10 volte e vediamo quante volte è uscito un numero inferiore a 3. Definiamo la probabilità dell’evento come il limite del rapporto tra il numero di volte in cui si è verificato l’esito fA ed il numero degli esperimenti n

In questo caso la formula è:

Probabilità di A =$\lim_{n \to \infty} \frac{f_A}{n}$

Questa definizione (che si chiama frequentista) ha un problema di fondo insuperabile:
**Non tutti gli esperimenti sono ripetibili e quindi alcune probabilità non sarebbero calcolabili** 
Per esempio, qual è la probabilità che entro i prossimi 100 anni un meteoroide colpisca la terra generando la quasi estinzione della vita come accadde ai tempi dei dinosauri?

allora nasce una definizione assiomatica che però non ci da delle metodologie di calcolo dei valori di probabilità 

**TEORIA DELLA PROBABILITA'**

Assiomi della teoria della probabilità (P) 
Una distribuzione di probabilità P in uno spazio di campioni S associa agli eventi numeri reali, soddisfacendo i seguenti assiomi:

Siano A e B due eventi qualsiasi (sottoinsiemi di S)
1) **A1** 0 ≤ P(A) ≤ 1  -> la probabilità di A è compresa tra 0 e 1
2) **A2** P(S) = 1 e P(∅) = 0 -> probabilità di tutti gli eventi = 1, probabilità di nessun evento = 0
3) **A3** P(A ∪ B) = P(A) + P(B) − P(A ∩ B)

- L’assioma (A3) può essere riscritto utilizzando il formalismo logico, in questo modo:
  P(A ∨ B) = P(A) + P(B) − P(A ∧ B) 
  
- ossia: **"La probabilità che si verifichi A oppure B è la probabilità che si verifichi A più la probabilità che si verifichi B meno la probabilità che si verifichino entrambi."** 
 
- Se due eventi A e B sono mutuamente esclusivi ovvero se A ∩ B = ∅, si ha allora:
  P(A ∨ B) = P(A) + P(B) 
  
- In particolare, quindi, abbiamo 
  P(A ∨ ¬A) = P(S) = 1 
  
- e quindi P(¬A) = 1 − P(A) 

- ovvero, la probabilità che un evento non si verifichi è uguale a -> 1 meno la probabilità che l’evento si verifichi. 
- La distribuzione di probabilità è detta uniforme se tutti gli eventi sono equiprobabili.

Talvolta può capitare che la probabilità un evento A sia condizionata da un altro evento B, questa è la formula della **probabilità condizionata**:
![[Pasted image 20250102102516.png|250]]
P(A|B) ->"La probabilità che $B$ si verifichi, sapendo che $A$ si è verificato"

Invece se 2 eventi sono indipendenti tra loro abbiamo:
                        P(A ∧ B) = P(A) · P(B)

**Il concetto di indipendenza è spesso dimenticato causando errori molto gravi**. Per esempio, errore comune, per chi gioca al "lotto", è pensare che se un numero non esce da tante estrazioni, allora la probabilità di uscire alla prossima è più alta. Niente di più falso, perché la probabilità rimane la stessa, essendo le estrazioni eventi indipendenti.

**Esempio**
Se lanciamo un dado 3 volte la probabilità di ottenere [2,1,6] è più alta di quella di ottenere [3,3,3]?
Risposta: **NO** 
tutti questi numeri hanno probabilità $\frac{1}{6}$ di uscire, quindi P([2,1,6]) = $\frac{1}{6} · \frac{1}{6} · \frac{1}{6} = \frac{1}{216}$ 
stessa cosa vale per P([3,3,3])

Dalla probabilità condizionata deriva la regola di Bayes (di Siwa), (infatti la formula è simile)

**Regola di Bayes**
![[Pasted image 20250102104058.png|250]]
la regola di Bayes è utile nell'ambito informatico e dell'Intelligenza Artificiale in particolare

 **Teorema della Probabilità Totale**
 Sia A un evento e siano $B_1,B_2.....B_n$ n eventi mutuamente esclusivi, tali che P($B_i$) $\neq$ 0 per ogni i ed inoltre P($B_1 ∨ B_2 ∨ .... B_n$) = 1 
 ovvero gli eventi sono esaustivi
 Allora
![[Pasted image 20250102111443.png]]
**Esempio**
![[Pasted image 20250102111747.png]]



**Problemi d'urna**

I problemi d'urna sono tutti quei problemi in cui si studia l'estrazione di oggetti (palline, biglie, carte, ecc.) da un'urna o da un insieme, con determinate condizioni
es. lancio dei dadi, estrazione del lotto ecc...
La condizione comune è che il gioco non sia truccato e che ogni estrazione è indipendente dalle precedenti

**Si possono ordinare in 4 modi combinando questi 2 criteri**
1) Estrazioni ordinate oppure non ordinate, ovvero se l'ordine di estrazione è importante oppure no
2) Estrazione con reinserimento oppure no, ovvero se ad ogni estrazione la pallina estratta viene reinserita nell'urna

Supponiamo di estrarre k palline da un urna contenente n palline
Nei 4 casi possibili, il numero totale è:
- $D^r_{n,k}=n^k$ -> numero di disposizioni con ripetizione, se l'ordine è importante e la pallina viene reinserita dopo ogni estrazione
- $D_{n,k}=\frac {n!}{(n-k)!}$ -> numero delle disposizioni semplici, se l'ordine è importante ma la pallina estratta non viene reinserita
- $C_{n,k}=\binom{n}{k}=\frac {n!}{n!(n-k)!}$ -> combinazioni semplici, se l'ordine non è importante e la pallina estratta non viene reinserita
- $C^r_{n,k}=\frac {n+k-1!}{k!(n-1)!}$ -> combinazioni con ripetizione, se l'ordine non è importante e la pallina viene reinserita

![[Pasted image 20250102165350.png]]

------
Guarda altri esempi d'urna da slide 65 a 75, esercizi da slide 76 a 78

---

**Variabile casuale e valore atteso**
Una variabile casuale è una funzione X che associa un numero reale ad un evento. Definiamo quindi un evento come il fatto che la variabile X assume un valore x ovvero 
X = x

Possiamo allora definire il valore medio e valore atteso di una variabile:
![[Pasted image 20250103174940.png|300]]

**Esempio**
Se la variabile casuale X contiene il valore ottenuto dopo il lancio di un dado
Abbiamo che:
![[Pasted image 20250103175357.png]]

**Proprietà del valore atteso**
- Il valore atteso ha una proprietà di linearità

1) Ovvero se abbiamo due variabili casuali X e Y e consideriamo la variabile casuale "somma" X+Y allora
 ![[Pasted image 20250103175607.png|250]]
**Esempio**
Se lanciamo due dadi, il valore atteso della somma è:
![[Pasted image 20250103175807.png|350]]

**Prova di Bernoulli**

Questa prova ha solamente 2 risultati: **successo o fallimento**
Abbiamo quindi un esperimento con 2 uscite:
1) successo con probabilità p
2) insuccesso con probabilità q = 1-p

- Tutti i tentativi sono indipendenti l'uno dall'altro e la probabilità rimane costante

Il numero atteso dei numeri di tentativi da fare per ottenere "successo" è dato da $\frac{1}{p}$
ne segue che minore è la probabilità di successo, più tentativi si dovranno fare

**Esempi:**
![[Pasted image 20250103181608.png]]



**LEGGE DEI GRANDI NUMERI (Teorema di Bernoulli)** 

 **La legge dei grandi numeri** detta anche **teorema di Bernoulli** ci garantisce che la media dei risultati ottenuti dopo un grande numero di tentativi si avvicina al valore atteso, ad esempio se lanciamo un dado 1000 volte la media si avvicinerà a 3,5 e se lanciamo all’infinito un dado, la media ottenuta sarà esattamente 3,5

**CASO STUDIO: GIOCHI E PARADOSSI PROBABILISTICI**

**Qui vediamo 4 degli esempi più famosi**
1) Il paradosso dei 2 bambini (proposto da M. Gardner nel 1959)
2) Il paradosso delle 3 carte o delle 3 scatole
3) Il paradosso dei 3 prigionieri (proposto da M. Gardner nel 1959)
4) Il paradosso Monty Hall (1975, 1990)


**Paradosso dei 2 bambini**

"Il professore di Probabilità ha due bambini. Non sono due femmine. Qual è la probabilità che entrambi i bambini siano maschi?"

I casi possibili sono:
M M
F M
M F

(F F non può essere perché ha detto che non sono due femmine)
quindi la possibilità che entrambi i figli siano maschi è 1 su 3 

valli a guardare a slide 102 in poi



ESERICIZI PAG 76-78 83 94-96
