**Parte IV: Grafi ed Alberi**
**Contenuti**
![[Pasted image 20250105145017.png|500]]
![[Pasted image 20250105145043.png|500]]


Introduciamo il problema delle strette di mano:

Roberto e la moglie Giulia hanno organizzato una cena a casa loro ed invitano altre 4 coppie sposate di amici. 
Alcuni si salutano stringendosi la mano (ovviamente mogli e mariti non si stringono la mano). 
Alla fine della festa, Roberto chiede a ciascuno a quante persone abbia stretto la mano e riceve nove risposte differenti. 
**Domande**: 
Quante persone hanno stretto la mano a Roberto? 
Quante persone hanno stretto la mano a Giulia? 
Roberto e Giulia hanno stretto la mano alle stesse persone?

Per rispondere a queste domande ci aiutiamo con un disegno:
![[Pasted image 20250105145637.png|300]]
Tutte le persone sono rappresentate da un cerchio rosso, indichiamo con una R Roberto 
![[Pasted image 20250105150541.png|300]]
Poiché ogni persona può stringere la mano ad al più 8 persone, e Roberto riceve 9 risposte differenti deduciamo che queste risposte siano: 0, 1, 2, . . . , 8.
ogni numero rappresenta una persona e quante strette di mano ha fatto (es. 8 = ottava persona e 8 strette di mano)

adesso disegniamo dei segmenti per collegare 2 cerchietti se le persone si sono strette la mano, ne disegniamo 8 che partono dal cerchietto 8 e si collegano a tutti i cerchi tranne che allo 0 (perché ha stretto la mano a 0 persone (quindi 8,0 sono una coppia))
![[Pasted image 20250105150932.png|300]]
e così via, ad esempio il 7 va collegato ad altri 7 cerchi (è già collegato all'8)
va collegato pero in base ai numeri, perché ad esempio l'1 non può essere più collegato perché già ha stretto 1 mano (poiché 7 e 1 non si sono stretti la mano rappresentano una coppia)
![[Pasted image 20250105151158.png|300]]
una volta fatti tutti i collegamenti arriviamo a questa situazione:
![[Pasted image 20250105151243.png|300]]
Possiamo dunque rispondere alle domande:
Quante persone hanno stretto la mano a Roberto? Risposta: 4
Quante persone hanno stretto la mano a Giulia? Risposta: 4 
Roberto e Giulia hanno stretto la mano alle stesse persone? Risposta: Si

Utilizzando un **grafo** si possono risolvere problemi apparentemente impossibili

**GRAFI**
**Ogni cerchio è un vertice o nodo**
**Ogni connessione tra due cerchi è un arco **

**Definizione**
**Grafo semplice non orientato**
Un grafo semplice non orientato, denotato con G = (V,E) consiste in:
- Un insieme finito e non vuoto V = {1,2...m} i cui elementi sono i nodi (cerchi)
- Un insieme finito E = {$e_1,e_2...e_n$} i cui elementi sono sottoinsiemi di V di cardinalità 2 ovvero $e_k$  = {i,j} con i e j ∈ V. Tali elementi sono detti archi del grafo (le connessioni)
- i DUE nodi collegati da un arco sono detti "estremi dell'arco" e si dicono adiacenti
- un arco che ha come estremo un nodo "i" si dice "incidente a i"
- Un nodo che non è l'estremo di alcun arco si dice isolato

Un grafo semplice non orientato può collegare al massimo 2 nodi tra loro

**Grafo semplice non orientato**:
![[Pasted image 20250105153126.png|250]]


**Definizione**
**Grafo semplice orientato (digrafo)**
Un grafo semplice orientato, denotato con G = (V,E) è praticamente uguale al grafo non orientato solo che qua conta la direzione: infatti ci sono delle frecce tra i 2 nodi che ne indicano il verso
![[Pasted image 20250105153947.png|250]]

**I grafi orientati e non che hanno più di un arco che collega coppie di nodi sono detti multigrafi**
![[Pasted image 20250105154139.png|550]]

nei multigrafi possiamo avere un arco che collega lo stesso nodo, questo si chiama cappio

**Grado di un nodo**
Dato un grafo G = {V,E} **il grado di un nodo v ∈ V, denotato con δ(v) (delta di v), è il numero di archi ad esso incidenti.**

Se G è un digrafo (grafo ordinato), abbiamo 2 nozioni diverse del grado di un nodo:
1) Grado in ingresso  $δ^-(v)$ è il numero di archi orientati che "entrano" nel nodo
2) Grado in uscita $δ^+(v)$ è il numero di archi orientati che "escono" dal nodo

**Esempio**
![[Pasted image 20250105185346.png]]

**Teorema delle strette di mano**
Sia G = {V,E} un <u>grafo non orientato</u>, allora la somma dei gradi di ogni vertice è uguale al doppio del numero degli archi ossia -> 2|E|

- Corollario: Sia G = {V, E} un <u>grafo non orientato</u>, il numero dei vertici di grado dispari è un numero pari


######  **Grafi Regolari**
Sia G = {V,E} un <u>grafo non orientato</u> 

**Se tutti i nodi del grafo hanno lo stesso grado r allora il grafo è regolare di grado r**

ne deduciamo che:                                                                            (|V| = numero di nodi)
1) $\lvert V \rvert = \frac{2 \lvert E \rvert}{r}$
2) Se r è dispari allora |V| è pari, ovvero un grafo regolare di grado dispari contiene un numero pari di nodi


###### **Grafi Completi**
Sia G = {V,E} <u>un grafo non orientato</u>, **Diciamo che G è completo se ogni coppia di nodi è connessa da un SOLO arco**
ne deduciamo che il numero di archi del grafo completo è $\binom{|V|}{2}$ ovvero il numero di tutte le possibili coppie di nodi
Un grafo completo con n nodi viene denotato con $K_n$
![[Pasted image 20250105190329.png|600]]


###### **Torneo**
Sia G = {V,E} un <u>grafo completo</u>. **Il grafo orientato attenuto assegnando uno dei due possibili versi ad ogni arco di G si dice torneo**
In pratica è un grafo completo in cui agli archi viene data una direzione
ma <u>non</u> sono grafi orientati completi
![[Pasted image 20250105194229.png|250]]


###### **Grafi Orientati Completi**
Sia G = {V,E} un digrafo. **G è completo se ogni coppia di nodi è connessa da un arco (i,j) e (j,i)** quindi bisogna avere "andata e ritorno"
![[Pasted image 20250105194825.png|300]]


###### **Grafi Bipartiti**
Sia G = {V,E} un <u>grafo non orientato</u>. **Diciamo che G è bipartito se possiamo partizionare l'insieme dei nodi in 2 insiemi, $V_1$ e $V_2$ in maniera che tutti gli archi di G hanno come estremi un nodo in $V_1$ e l'altro in $V_2$** 
![[Pasted image 20250105195406.png|500]]

###### **Grafi Bipartiti Completi**
Un grafo Bipartito G = {V,E} si dice completo se data la partizione dei vertici $V_1$ e $V_2$ esiste un arco per ogni coppia di nodi $v ∈ V_1$ e $u ∈ V_2$
Un grafo bipartito completo si indica con $k_{n,m}$ dove n = |$V_1$| e m = |$V_2$|
![[Pasted image 20250105195941.png|350]]


###### **Sottografo**
Sia G = {V,E} un grafo non orientato. Diciamo che **G' = {V',E'} è un sotto grafo di G se**:
1) **V' ⊆ V**
2) **E' ⊆ E** 
(In pratica un parte più piccola del grafo)
**Stessa cosa vale anche per i grafi orientati**
![[Pasted image 20250106110336.png|500]]
![[Pasted image 20250106110441.png|500]]


###### **Sottografo Indotto**
Sia G = {V,E} un grafo (o digrafo). Sia V ′ ⊆ V. **Il sottografo indotto da V' è il sottografo**
**G = {V',E'} ottenuto eliminando da G tutti i vertici non appartenenti a V' e tutti gli archi incidenti ad almeno uno dei vertici eliminati**
![[Pasted image 20250106110805.png]]


###### **Grafi Isomorfi**
Chiediamoci in che senso due grafi possono essere considerati uguali? Ricordiamo che la proprietà caratteristica di un grafo è il modo in cui i vertici sono collegati dagli archi

**Definizione** **(complicata (slide Cutello))**
**Isomorfismo tra grafi (sono uguali)**
Due grafi, sia entrambi orientati che entrambi non orientati, $G_1$ = ($V_1, E_1$) e $G_2$ = ($V_2, E_2$) si dicono isomorfi se esiste una applicazione biunivoca f dall’insieme dei vertici V1 nell’insieme dei vertici $V_2$ tale che (f (u), f (v)) è un arco di $E_2$ se e solo se (u, v) è un arco di $E_1$. La biiezione f è detta isomorfismo
**Esempio:**
![[Pasted image 20250106111929.png|600]]



**Definizione** **(semplice (chatGPT))**
Due **grafi** si dicono **isomorfi** se hanno lo stesso numero di nodi e archi e c'è una corrispondenza biunivoca tra i nodi dei due grafi che preserva le connessioni. In altre parole, i grafi sono strutturalmente identici, anche se i nodi hanno etichette diverse.
**Esempio**:  
Se il grafo $G_1$​ ha i nodi **A,B,C** e gli archi **(A,B),(B,C)(A, B)** e il grafo $G_2$​ ha i nodi **1,2,3** e gli archi **(1,2),(2,3)** i due grafi sono isomorfi. La corrispondenza potrebbe essere A↔1, B↔2, C↔3

slide 37