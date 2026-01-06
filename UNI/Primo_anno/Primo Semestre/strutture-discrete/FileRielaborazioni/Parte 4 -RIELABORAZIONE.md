**Parte IV: Grafi ed Alberi**
**Contenuti**
![[Pasted image 20250105145017.png|500]]
![[Pasted image 20250105145043.png|500]]


**INDICE SULLE TIPOLOGIE DI GRAFI**
[[#**Grado di un nodo**]]
[[#**Grafi Regolari**]]
[[#**Grafi Completi**]]
[[#**Torneo**]]
[[#**Grafi Orientati Completi**]]
[[#**Grafi Bipartiti**]]
[[#**Grafi Bipartiti Completi**]]
[[#**Sottografo**]]
[[#**Sottografo Indotto**]]
[[#**Grafi Isomorfi**]]
[[#**Grafi Omeomorfi**]]

[[#**Percorso**|#**Percorsi,cammini,circuiti,cicli**]]
[[#**Grafi Aciclici**]]
[[#**Nodi connessi**]]
[[#**Grafo Connesso**]]
[[#**Grafi k-connessi**]] 

[[#**Rappresentazione di un grafo come matrice**]]
[[#**Rappresentazione di un grafo con liste di adiacenza**]]

[[#**Circuito Euleriano**]]
[[#**Cammino Hamiltoniano**]]
[[#**Grafi Pesati**]]
[[#**Grafi Planari**]]
[[#**Formula di Eulero**]]
[[#**Grafi Planari Massimali o Triangolari**]]
[[#**Colorazione di un Grafo**]]

**ALBERI**
[[#**ALBERO LIBERO**]]
[[#**Alberi Radicati**]]

**PROBLEMI COMBINATORI SU GRAFI**
[[#**Numero Cromatico**]]
[[#**Questo ed altri sono detti problemi $N P-hard$**|#**Problemi N P-hard**]] 
[[#**Elenco problemi $N P-hard$**]] 


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

##### **Grado di un nodo**
Dato un grafo G = {V,E} **il grado di un nodo v ∈ V, denotato con δ(v) (delta di v), è il numero di archi ad esso incidenti.**

Se G è un digrafo (grafo ordinato), abbiamo 2 nozioni diverse del grado di un nodo:
1) Grado in ingresso  $δ^-(v)$ è il numero di archi orientati che "entrano" nel nodo
2) Grado in uscita $δ^+(v)$ è il numero di archi orientati che "escono" dal nodo

**Esempio**
![[Pasted image 20250105185346.png]]

**Teorema delle strette di mano**
Sia G = {V,E} un <u>grafo non orientato</u>, allora la somma dei gradi di ogni vertice è uguale al doppio del numero degli archi ossia -> 2|E|

- Corollario: Sia G = {V, E} un <u>grafo non orientato</u>, il numero dei vertici di grado dispari è un numero pari

---
######  **Grafi Regolari**
Sia G = {V,E} un <u>grafo non orientato</u> 
**Se tutti i nodi del grafo hanno lo stesso grado r allora il grafo è regolare di grado r**

ne deduciamo che:                                                                            (|V| = numero di nodi)
1) $\lvert V \rvert = \frac{2 \lvert E \rvert}{r}$
2) Se r è dispari allora |V| è pari, ovvero un grafo regolare di grado dispari contiene un numero pari di nodi

---
###### **Grafi Completi**
Sia G = {V,E} <u>un grafo non orientato</u>, **Diciamo che G è completo se ogni coppia di nodi è connessa da un SOLO arco**
ne deduciamo che il numero di archi del grafo completo è $\binom{|V|}{2}$ ovvero il numero di tutte le possibili coppie di nodi
Un grafo completo con n nodi viene denotato con $K_n$
![[Pasted image 20250105190329.png|600]]

---
###### **Torneo**
Sia G = {V,E} un <u>grafo completo</u>. **Il grafo orientato attenuto assegnando uno dei due possibili versi ad ogni arco di G si dice torneo**
In pratica è un grafo completo in cui agli archi viene data una direzione
ma <u>non</u> sono grafi orientati completi
![[Pasted image 20250105194229.png|250]]

---
###### **Grafi Orientati Completi**
Sia G = {V,E} un digrafo. **G è completo se ogni coppia di nodi è connessa da un arco (i,j) e (j,i)** quindi bisogna avere "andata e ritorno"
![[Pasted image 20250105194825.png|300]]

---
###### **Grafi Bipartiti**
Sia G = {V,E} un <u>grafo non orientato</u>. **Diciamo che G è bipartito se possiamo partizionare l'insieme dei nodi in 2 insiemi, $V_1$ e $V_2$ in maniera che tutti gli archi di G hanno come estremi un nodo in $V_1$ e l'altro in $V_2$** 
![[Pasted image 20250105195406.png|500]]

---
###### **Grafi Bipartiti Completi**
Un grafo Bipartito G = {V,E} si dice completo se data la partizione dei nodi $V_1$ e $V_2$ esiste un arco per ogni coppia di nodi $v ∈ V_1$ e $u ∈ V_2$
Un grafo bipartito completo si indica con $k_{n,m}$ dove n = |$V_1$| e m = |$V_2$|
![[Pasted image 20250105195941.png|350]]

---
###### **Sottografo**
Sia G = {V,E} un grafo non orientato. Diciamo che **G' = {V',E'} è un sotto grafo di G se**:
1) **V' ⊆ V**
2) **E' ⊆ E** 
(In pratica un parte più piccola del grafo)
**Stessa cosa vale anche per i grafi orientati**
![[Pasted image 20250106110336.png|500]]
![[Pasted image 20250106110441.png|500]]

---
###### **Sottografo Indotto**
Sia G = {V,E} un grafo (o digrafo). Sia V ′ ⊆ V. **Il sottografo indotto da V' è il sottografo**
**G' = {V',E'} ottenuto eliminando da G tutti i nodi non appartenenti a V' e tutti gli archi incidenti ad almeno uno dei vertici eliminati** 
![[Pasted image 20250106110805.png]]

---

###### **Grafi Isomorfi**
Chiediamoci, in che senso due grafi possono essere considerati uguali? Ricordiamo che la proprietà caratteristica di un grafo è il modo in cui i vertici sono collegati dagli archi

**Definizione** **(complicata (slide Cutello))**
**Isomorfismo tra grafi (sono uguali)**
Due grafi, sia entrambi orientati che entrambi non orientati, $G_1$ = ($V_1, E_1$) e $G_2$ = ($V_2, E_2$) si dicono isomorfi se esiste una applicazione biunivoca f dall’insieme dei nodi $V_1$ nell’insieme dei nodi $V_2$ tale che (f (u), f (v)) è un arco di $E_2$ se e solo se (u, v) è un arco di $E_1$. La biiezione f è detta isomorfismo
**Esempio:**
![[Pasted image 20250106111929.png|600]]



**Definizione** **(semplice (chatGPT))**
Due **grafi** si dicono **isomorfi** se hanno lo stesso numero di nodi e archi e c'è una corrispondenza biunivoca tra i nodi dei due grafi che preserva le connessioni. In altre parole, i grafi sono strutturalmente identici, anche se i nodi hanno etichette diverse.
**Esempio**:  
Se il grafo $G_1$​ ha i nodi **A,B,C** e gli archi **(A,B),(B,C)(A, B)** e il grafo $G_2$​ ha i nodi **1,2,3** e gli archi **(1,2),(2,3)** i due grafi sono isomorfi. La corrispondenza potrebbe essere A↔1, B↔2, C↔3

- Ovviamente se i due grafi sono isomorfi allora:
  $|V_1| = |V_2| e |E_1| = |E_2|$
- Sappiamo anche che dato che f(u) = v allora anche δ(u) = δ(v) (vale anche per grafi orientati)
- Se due grafi sono isomorfi allora esistono almeno altri 2 sottografi isomorfi a loro volta
- **Se 2 grafi hanno gli stessi nodi e stessi archi non per forza sono isomorfi**

**Grafi non isomorfi esempio:**
![[Pasted image 20250107111211.png|400]]
1) l grafo $G_1$ ha un vertice c tale che δ(c) = 1. Tutti i vertici di $G_2$, invece, hanno grado maggiore o uguale a 2
2) Il sottografo di $G_1$ ottenuto eliminando il vertice c è un $K_4$ ovvero un grafo completo con 4 vertici. Nessuno dei 5 sottografi di $G_2$ con 4 vertici è un grafo completo

**Grafi orientati non isomorfi esempio:**
![[Pasted image 20250107111240.png|400]]
1) Non sono isomorfi perché nel grafo $G_1$ il vertice 2 ha grado in uscita 2 mentre nessun vertice in $G_2$ ha lo stesso grado in uscita
2) Notiamo anche che se invertiamo il verso dell’arco (2, 1) in $G_1$ e quindi otteniamo un arco che va da 1 a 2 allora i due grafi diventano isomorfi

---

###### **Grafi Omeomorfi**
In che senso due grafi hanno la stessa forma? Diamo intanto queste denifizioni

**Definizione suddivisione di un arco (grafo non orientato)**
Sia G = {V,E} un <u>grafo non orientato</u> e sia e = {u,v} un arco di G
Una suddivisione dell'arco e = {u,v} è ottenuta introducendo un nuovo nodo w e sostituendo in G l'arco (u,v) con gli archi e$_1$ = {u,w} e  e$_2$ = {w,u}

![[Pasted image 20250107112111.png|350]]

**Vale la stessa cosa anche sui grafi orientati**
![[Pasted image 20250107112312.png|460]]


**Omeomorfismo tra grafi**
**Definizione**
Due <u>grafi non orientati</u> $G_1 = (V_1, E_1) e G_2 = (V_2, E_2)$ si dicono omeomorfi se attraverso una serie di suddivisioni di archi di $G_1$ e $G_2$ si possono ottenere 2 grafi $G'_1$ e $G'_2$ che sono isomorfi

![[Pasted image 20250107112740.png|400]]



**La definizione di omeomorfismo si estende ai grafi orientati tenendo però presente la suddivisione di archi orientati in due o più archi orientati**

![[Pasted image 20250107112906.png|400]]

---

###### **Percorso**
Un **percorso in un grafo** è una sequenza di **nodi (o vertici)**, adiacenti, collegati tra loro da **archi** (o linee). Può essere visto come un "cammino" che parte da un nodo iniziale e passa attraverso altri nodi seguendo gli archi.

in un percorso da $v_1$ fino a $v_k$ , $v_1$ è detto nodo origine e $v_k$ è detto nodo destinazione 

La lunghezza di un percorso è il numero di archi che lo compongono
![[Pasted image 20250107220424.png]]

**vale lo stesso discorso per i grafi orientati**
![[Pasted image 20250107220503.png]]


**Cammino**

E' uguale al percorso ma se tutti i nodi sono diversi viene detto cammino
![[Pasted image 20250107220715.png]]


**Circuito**
Si dice circuito un <u>percorso</u> in cui il nodo d'origine è lo stesso di destinazione
![[Pasted image 20250107220844.png]]

**Ciclo**
Si dice ciclo un <u>cammino</u> in cui il nodo d'origine è lo stesso di destinazione
![[Pasted image 20250107221354.png]]
Se il grafo è non orientato servono minimo 3 nodi, se è orientato ne bastano 2

---
###### **Grafi Aciclici**
Un grafo (digrafo) G = {V,E} si dice aciclico se non possiede cicli
![[Pasted image 20250107221651.png|500]]

---
 ###### **Nodi connessi**
Dato un grafo G = {V,E}, diciamo che 2 vertici u,v sono connessi se esiste un cammino da u a v
Si può dimostrare facilmente che la connessione tra nodi è una relazione di equivalenza. 
Quindi l’insieme V si può partizionare in classi di equivalenza, dove in ogni classe ci sono nodi collegati da un cammino

**Definizione Componenti Connesse (difficile slide Cutello)**
Sia $G = {V,E}$ un grafo e sia V = $V_1 ∪ V_2 ∪ · · · ∪ V_k$  la partizione indotta dalla relazione di connessione tra i nodi. Sia G = {$V_i,E_i$} il sottografo indotto da $V_i$ per ogni $i = 1...k$. Tali sottografi si chiamano componenti connesse di $G$

**Definizione Componenti Connesse (semplice chatGPT)**
Quando il grafo non è connesso, si può dividere il grafo in gruppi di vertici che sono connessi tra loro, ma non connessi agli altri gruppi. Questi gruppi si chiamano <u>componenti connesse</u>

**Esempi**
![[Pasted image 20250108114343.png|500]]

---

###### **Grafo Connesso** 
**Definizione grafo connesso**
Un grafo si dice connesso se ha una sola componente connessa. (è un unico pezzo)

**Definizione digrafo debolmente connesso**
un digrafo G = {V,E} si dice debolmente connesso se il grafo non orientato ottenuto eliminando da G l'orientamento degli archi è connesso
**Esempio**
![[Pasted image 20250108114616.png|500]]

**Un digrafo (grafo orientato) è fortemente connesso se esiste un percorso "in entrambi i sensi di marcia" tra i nodi: es. u->v   v->u 
Quindi si dice che è fortemente connesso quando ha una sola componente fortemente connessa**

In un grafo orientato quando ho un ciclo ho una componente fortemente connessa
![[Pasted image 20250108115131.png|180]]
Componenti fortemente connesse = {1,5,4,2,1}, {6,3,7,6,3}

###### **Grafi k-connessi**
**Definizione**
Sia dato un grafo G = {V,E}
Il grafo G si dice **k-connesso rispetto agli archi** se dati due nodi u,v esistono k cammini ad archi disgiunti tra u,v
Il grafo G si dice **k-connesso rispetto ai nodi** se dati due nodi u,v esistono k cammini a nodi disgiunti tra u, v

---
---

##### **Problema per gli informatici**

- I grafi sono una struttura matematica che presenta enormi vantaggi quando si tratta di progettare software per risolvere particolari problemi
- Ma se vogliamo usare la nozione di grafo come "struttura dati" dobbiamo trovare un modo per rappresentare un grafo, utilizzando le strutture dati tipicamente disponibili in un linguaggio di programmazione
- La scelta, come vedremo, è abbastanza naturale, ossia utilizzare array bidimensionali (**matrici**) o array di arrays (**liste**) per rappresentare un grafo

##### **Rappresentazione di un grafo come matrice**
Sia dato un grafo G = {V,E} con |V | = n

Supponiamo allora che V = {1, 2, . . . , n}. Costruiamo una matrice quadrata M di dimensione n × n così fatta:
M[i, j] = 1 se i vertici i e j sono connessi da un arco
M[i, j] = 0 se i vertici i e j non sono connessi da un arco
Questa è la matrice di adiacenza al grafo

**Esempio grafo non orientato**
- Il grafo contiene 6 vertici, quindi costruiamo una matrice M di dimensione 6 × 6
- **Le righe della matrice corrispondono ai nodi del grafo** 
- **Le colonne della matrice corrispondono agli archi del grafo**
- La matrice è a valori 0-1 e la somma degli 1 in ogni riga è il grado del nodo corrispondente
![[Pasted image 20250108141948.png]]

Notiamo inoltre che la diagonale principale ha solo valori 0 poiché non vi è un arco da un vertice a se stesso

Dato che il grafo non è orientato, la matrice è simmetrica, ossia, per ogni i e j M[i, j] = M[j, i].

**Esempio grafo orientato**
In questo caso abbiamo un grafo con 7 vertici e quindi la matrice avrà dimensione 7 × 7
![[Pasted image 20250108142256.png|600]]

Rimane tutto uguale a prima ma questa volta la matrice non è simmetrica

**Matrici e Componenti Connesse**
![[Pasted image 20250108142729.png]]

- Come si può vedere, M2 e M3 consistono di blocchi quadrati di dimensione diverse 
- Ogni blocco corrisponde ad una componente connessa ed ha dimensione k × k se k è il numero di vertici della componente 
- Gli altri blocchi sono fatti tutti di 0
- Ovviamente il motivo è che i vertici di una componente non sono connessi da archi con vertici di altre componenti


Grazie al **Pigeonhole Principle** sappiamo che vale questo teorema sui grafi
**Teorema (questa è una condizione sufficiente ma non necessaria)**
Sia G = {V,E} un <u>grafo orientato</u> e per ogni nodo i ∈ V siano $δ^+(i)$ e $δ^−(i)$ rispettivamente il grado in uscita ed in entrata di i
Se:
1) per ogni i ∈ V $δ^+(i)$ > 0 
2) oppure se per ogni i ∈ $V δ^−(i)$ > 0
allora G contiene un ciclo
**Dimostrazione** (dimostriamo solo il primo caso perché per il secondo è analogo)
Se prendiamo un nodo $i_0$ sappiamo che il $δ^+(v)$ è > 0 quindi è collegato ad un altro nodo $i_1$ che a sua volta sarà collegato ad un altro nodo $i_2$ e cosi via, per avere un ciclo abbiamo bisogno che tutti i nodi siano collegati tra loro, quindi per il Pigeonhole Principle sappiamo che c'è un ciclo perché se ogni nodo ha grado in uscita > 0 saranno tutti connessi

###### (dimostrazione per come la farei io in un compito:)
se il grado in uscita di ogni nodo del grafo è > 0, vuol dire che ogni coppia di nodi appartenente a V è collegata da un arco, 
e cosi fino a raggiungere l'ultimo nodo che anch'esso ha grado in uscita > 0 il che vuol dire che collega uno degli altri nodi del grafo chiudendo il ciclo
dimostrazione analoga per il grado in entrata.

**Esempio**
![[Pasted image 20250108144134.png]]


**Esempio condizione sufficiente ma non necessaria**
![[Pasted image 20250108144357.png]]

Questo teorema può però diventare necessario anche se per i sottografi, infatti se lo riscriviamo cosi:
**Teorema**
Sia G = (V , E) un grafo orientato. Allora G possiede un ciclo se e solo se esiste un sottoinsieme V ′ ⊆ V , tale che il sottografo indotto G = (V ′, E′) verifica la seguente proprietà: per ogni vertice i ∈ V ′ siano $δ^+(i) e δ^−(i)$ rispettivamente il grado in uscita ed in entrata di i in G′ 
1)  allora 1 per ogni i ∈ V , $δ^+(i)$ > 0
2) oppure 2 per ogni i ∈ V , $δ^−(i)$ > 0

è sostanzialmente lo stesso teorema ma applicato ai sottografi (quindi ha anche la stessa dimostrazione)

---

**Percorsi tra nodi**

La matrice ci dice se esiste un percorso di lunghezza 1 (nodi direttamente collegati) tra 2 nodi, ma se volessimo trovare percorsi più lunghi?
nella foto tra il nodo 4 e 2 esistono 2 percorsi di lunghezza 2 e tra i nodi 6 e 5 ne esiste 1 di lunghezza 1
![[Pasted image 20250108222913.png|200]]

**Come trovare tali percorsi più lunghi di 1?**

**Ci basta moltiplicare la matrice M per se stessa** quindi M x M cosi troviamo quanti percorsi 
![[Pasted image 20250108223425.png]]
$M^2[3,5]$ = 2 quindi ci sono due cammini di lunghezza 2 tra 3 e 5

**Ma sono giusti i valori nella diagonale principale?**
Vediamo un esempio con un grafo orientato
- Nell’esempio, tra i nodi 1 e 4 non esiste un percorso di lunghezza 1, però ne esiste uno di lunghezza 2. 
- Analogamente, tra i nodi 5 e 2 non esiste un percorso di lunghezza 1, però ne esiste uno di lunghezza 2
![[Pasted image 20250108223654.png|500]]

Se calcoliamo il prodotto M x M troviamo il numero di percorsi di lunghezza 2 per ogni coppia di nodi
![[Pasted image 20250108224007.png|700]]
(se ti vai a guardare ad esempio il punto 1,3 indica che c'è un percorso di lunghezza 2 tra 1 e 3 (1->2->3))

**E se volessimo trovare i percorsi di lunghezza 3?** 

Se abbiamo la matrice di adiacenza $M$ , $M^2$ ci dice quanti sono i percorsi di lunghezza 2 tra due nodi, quindi se vogliamo trovare quanti sono i percorsi di lunghezza 3 dal nodo $i$ al nodo $j$ , cerchiamo i percorsi di lunghezza 2 da $i$ ad ogni altro nodo $k$ e poi verifichiamo se c’è un arco che porta da $k$ a $j$

$i$ -> "nodo n" -> $k$ -> $j$ 
![[Pasted image 20250109095831.png]]

Per generalizzare quanto visto abbiamo questo teorema

**Teorema**
Sia dato un grafo (digrafo) G = {V,E} e sia M la sua matrice di adiacenza. Il numero di percorsi di lunghezza k ≥ 1 per ogni coppia di vertici i e j è dato dal valore della matrice
$M^k[i,j]$ 

##### **Rappresentazione di un grafo con liste di adiacenza** 
Rappresentare un grafo con una matrice e semplice ed è veloce cercare un determinato elemento, ma se il grafo è molto grande la matrice diventa enorme, in più se il grafo ha pochi archi, la matrice avrà molti 0 all'interno, che quindi occupano memoria senza contenere informazione, ecco perché usiamo le liste (occupano meno memoria ma è più difficile trovare gli elementi)

Dato un grafo (digrafo) G = {V,E} con |V| = n , gli associamo una **lista di adiacenza** di dimensione n, ossia il numero dei nodi, ed ogni elemento della lista è a sua volta una lista (di solito concatenata), dove mettiamo in sequenza non ordinata, tutti i vertici collegati al vertice corrispondente
![[Pasted image 20250109100732.png|650]]

**Esempio**
Se avessimo un grafo con 7 vertici e 9 archi, la matrice avrebbe 49 entrate, mentre una lista solo n + |E| quindi 7 + 9 = 16 valori
![[Pasted image 20250109100932.png|500]]


##### **Circuito Euleriano**
**Definizione**
Sia G = {V,E} un grafo connesso. Un circuito Euleriano di G è un circuito che passa per ogni arco di G esattamente una ed una sola volta
Un grafo si dice Euleriano se possiede un ciclo Euleriano

*Attenzione ->* passa da ogni arco 1 sola volta, ma può passare più volte su un nodo (ecco perché si chiama circuito e non cammino)
![[Pasted image 20250109101812.png|200]]
Il grafo ha un Circuito Euleriano -> 1-2-3-5-4-3-6-4-1

**Teorema di Eulero**
Un grafo G = {V,E} è euleriano se e solo se è connesso ed i suoi nodi hanno grado pari

##### **Cammino Euleriano**
Se si parla di cammino vale il seguente teorema

**Teorema**
Un grafo G = {V,E} possiede un cammino euleriano se e solo se è connesso ed i suoi vertici, tranne al più 2 hanno tutti grado pari. I 2 vertici di grado dispari, saranno il primo e l'ultimo vertice del cammino
![[Pasted image 20250109111055.png|300]]
l grafo in figura ha infatti 2 vertici di grado dispari 1 e 3 ma possiede un cammino che passa per tutti gli archi una ed una sola volta: A − B − C − D − E − A − C

##### **Cammino Hamiltoniano**
- Il Teorema di Eulero appena visto, risponde alla domanda: "Esiste un percorso di G che passa per ogni arco esattamente una sola volta ?" 
- La domanda complementare è ovviamente: "Esiste un cammino di G che passa per ogni vertice esattamente una sola volta ?" 
- In questo caso parliamo di "cammino" e non di "percorso" perché non può esserci ripetizione di vertici

Fu proposto da (Sir Lewis) Hamilton e il suo problema utilizzava un dodecaedro con 12 facce 20 vertici e 30 spigoli.
Ogni vertice era una città, il problema riguardava se si potesse partire da una città, visitarle tutte e tornare alla città di partenza senza passare 2 volte da una stessa città
![[Pasted image 20250109111504.png|200]]

Immaginiamo di allargare il dodecaedro e schiacciarlo sul tavolo (come fosse fatto di plastilina) 
![[Pasted image 20250109111644.png|300]]
**Definizione**
Sia G = {V,E} <u>un grafo (digrafo) connesso</u>. Un cammino Hamiltoniano di G è un circuito che passa una ed una sola volta per tutti i nodi di G. Se il cammino è chiuso, ovvero se è un ciclo, tale ciclo si dice Ciclo Hamiltoniano. 
Un grafo si dice Hamiltoniano, se possiede un ciclo Hamiltoniano


Sapere se in un grafo c'è un cammino hamiltoniano è un problema impossibile (non esistono algoritmi veloci)

##### **Grafi Pesati**
In molte applicazioni in cui si usano i grafi come strutture dati, risulta naturale e necessario introdurre un concetto di peso, o costo, sugli archi oppure sui vertici.

**Definizione difficile (slide Cutello)**
n grafo (digrafo) G = (V , E) si dice pesato se è data un’applicazione 
$c : E \to \mathbb{R}$  
oppure 
$c : V \to \mathbb{R}$

**Definizione semplice (chatGPT)**
Un grafo è pesato quando è presente una funzione, indicata come ccc, che associa numeri reali:

1. **Agli archi**: $c : E \to \mathbb{R}$, cioè a ogni arco e ∈ E viene assegnato un numero reale (per esempio, il peso può rappresentare una distanza, un costo o un tempo).
    
2. **Ai vertici**:$c : V \to \mathbb{R}$, cioè a ogni vertice v ∈ V viene assegnato un numero reale (potrebbe rappresentare un valore come una priorità o un'etichetta)

I pesi (costi, valori) possono essere associati agli archi, ai nodi od ad entrambi. Nella rappresentazione grafica di un grafo, il peso di un arco o di un nodo si scrive vicino all’arco o al nodo

**Quindi il costo dipende dal numero e dall'unita di misura usata per valutarlo**
![[Pasted image 20250109160042.png|500]]

Dato un grafo o digrafo pesato con $c : E \to \mathbb{R}$ (1) o con $c : V \to \mathbb{R}$ (2) il costo α di un cammino p 
($v_1,v_2...v_k$) è:

1) la somma dei costi associati ai suoi archi, cioè $α = c(v_1, v_2) + c(v_2,v_3) + . . . + c(v_k−1, v_k )$

2) oppure la somma dei costi associati ai suoi vertici, cioè $α = c(v_1) + c(v_2) + . . . + c(v_k)$

**Esempio**
![[Pasted image 20250109181630.png|600]]

---

**Cammini Minimi e cammini Massimi**
In un <u>grafo pesato</u> **un cammino minimo** è quel cammino da v a w che ha costo minimo rispetto alla funzione usata
In un <u>grafo pesato</u> **un cammino massimo** è quel cammino da v a w che ha costo massimo rispetto alla funzione usata

anche i grafi pesati si possono rappresentare con una matrice semplicemente al posto degli 1 (quindi se c'è un arco) mettiamo direttamente il peso dell'arco

---
##### **Problema del Commesso Viaggiatore (TSP)**
E' il **problema di trovare un circuito hamiltoniano che minimizza il costo** (distanza) totale per un grafo pesato, dove ad ogni arco è associato un peso positivo

Anche per questo problema non abbiamo un algoritmo veloce, infatti:
- Se avessi un grafo con 4 vertici partendo da un nodo a caso dovrei trovare tutte le possibili permutazioni (cammini possibili) dei restanti 3 nodi che sono: 3! / 2 = 3 cammini possibili e fin qua è semplice.
- Ma se avessi un grafo con 30 vertici diventerebbe:![[Pasted image 20250110114601.png]]
Ecco perché anche questo è un problema impossibile (non esistono algoritmi veloci)
---
##### **Grafi Planari**
Sia G = {V,E} un <u>grafo non orientato</u>. Diciamo che G è planare se può essere raffigurato (disegnato) in un piano in modo che non ci siano archi che si intersecano
Altrimenti si dice non planare
![[Pasted image 20250110141755.png]]

---
**Teorema di Kuratowski**
Un grafo è planare se e solo se non contiene alcun sottografo che sia omeomorfo a $K_5$ o a $K_{3,3}$
 

(vedi da slide 122 a 124)

Quando disegniamo un grafo su un piano senza fare intersecare gli archi (grafo planare) possiamo contarne le facce, ovvero le zone delimitate dagli archi più la zona esterna (virtualmente infinita)
![[Pasted image 20250110143154.png|500]]

---
##### **Formula di Eulero**
Se al numero di nodi lo indichiamo con v, con e il numero di archi e con f le facce, vale la seguente formula detta formula di Eulero:
$v - e +f =2$ 
per i grafi di prima:
grafo con 3 facce -> v = 6 e = 7 f = 3 -> 6 - 7 + 3 = 2
grafo con 5 facce -> v = 7 e = 10 f = 5 -> 7 -10 +5 = 2

**Vogliamo dimostrare la formula di Eulero ma prima dimostriamo il seguente teorema**
**Teorema** 
Sia G = {V,E} un <u>grafo connesso</u> con |V| ≥ 3. Supponiamo che δ(v ) ≥ 2 per ogni v (nodo). Allora G possiede un ciclo

**Dimostrazione**
Ordiniamo i vertici e chiamiamoli $v_1, v_2, . . . , v_n$ con $n = |V| ≥ 3$. Partiamo allora dal vertice $v_1$ e costruiamo un cammino il più lungo possibile senza ripetizione di vertici. Supponiamo, senza ledere la generalità del discorso, che il cammino più lungo senza ripetizione di vertici sia $v_1, v_2, . . . , v_k$ . Se k = n allora abbiamo trovato un cammino hamiltoniano. In ogni caso, dal vertice $v_k$ possiamo ancora raggiungere un altro vertice, visto che il suo grado è almeno 2. Dal momento che ci siamo fermati, vuol dire che possiamo raggiungere un vertice già visto, quindi uno tra $v_1, . . . , v_{k−2}$ il che dimostra l’esistenza di un ciclo

###### (dimostrazione che farei io in un compito)
Chiamiamo |V| = n. Se costruiamo un cammino dal nodo $v_1$ fino a $v_k$, se k = n allora abbiamo un ciclo perché ogni nodo ha grado ≥ 2 quindi $v_k$ dovrà essere connesso ad un altro nodo, quindi questo dimostra l'esistenza di un ciclo

##### **Dimostriamo anche quest'altro**
**Teorema**
Sia G = {V,E} un <u>grafo connesso e aciclico</u>. Allora |E| = |V| − 1

**Dimostrazione**
Dimostriamo il teorema per induzione su |V|. Il teorema è banalmente vero se |V| ≤ 2. Supponiamo allora |V| ≥ 3. Essendo il grafo connesso ed aciclico, deve esistere un vertice di grado 1 altrimenti il grafo avrebbe un ciclo, per quanto dimostrato prima, oppure sarebbe disconnesso, avendo almeno un vertice con grado 0. Prendiamo allora un vertice v di grado 1 e rimuoviamolo dal grafo assieme all’arco su esso incidente. Il grafo indotto da V \ {v } è connesso, altrimenti dovremmo avere 2 vertici, u, w che sono connessi solo da un cammino passante per v , ossia u, . . . , u′, v , w′, . . . , w ma ciò implicherebbe che v ha grado maggiore di 1. Quindi, tale grafo indotto è connesso ed aciclico e quindi per induzione ha |V| − 2 archi. Aggiungendo v e l’arco ad esso incidente, abbiamo quindi che |E| = |V| − 1

##### Dimostrazione che farei io in un compito
caso banale: il teorema è banalmente vero se |V| ≤ 2.
passo induttivo: supponiamo per |V| ≥ 3, essendo che il grafo è connesso ma aciclico, vuol dire che ci sarà un nodo di grado 1, quindi se rimuoviamo quel nodo e l'arco ad esso incidente, 
**continuala**

**Dimostriamo adesso la formula di Eulero**

**Teorema formula di Eulero** 
Sia G = {V,E} un grafo planare connesso, con v nodi, e archi e f facce. 
Allora v − e + f = 2

**Dimostrazione**
Se il grafo possiede un ciclo, allora togliamo uno degli archi che completa tale ciclo. Il numero di archi e di facce si abbassa allora di una unità. In questo modo, la quantità v − e + f rimane invariata. Ripetiamo tali sottrazioni di archi, sino a quando non eliminiamo tutti i cicli dal grafo, ovviamente mantenendolo connesso. A questo punto, avremo ottenuto un grafo connesso ed aciclico con e = v − 1 e ovviamente f = 1 visto che non ci sono cicli. Quindi, v − e + f = 2

---

##### **Grafi Planari Massimali o Triangolari**
Un grafo planare si dice massimale, o triangolare, se è planare e se aggiungendo un nuovo arco ad una qualunque coppia di vertici (non connessi da un arco ovviamente), il grafo non è più planare
![[Pasted image 20250110180503.png|600]]
**Per sapere quanti archi ha in totale un grafo planare (e quindi sapere anche qual è il massimale per quel grafo) dobbiamo fare 3 |V| -6** 

---

##### **Colorazione di un Grafo**
- Colorare un grafo vuol dire assegnare un’etichetta, un colore, ad ogni vertice del grafo in maniera tale che due vertici collegati da un arco, abbiano colori distinti
- Un grafo G è k-colorabile se è possibile colorare i suoi vertici, rispettando il vincolo su descritto, utilizzando al più k colori
- Il numero cromatico di un grafo G, tradizionalmente denotato con χ(G) (chi di G) è il numero minimo di colori necessari per colorare il grafo

**Esempio**
In figura, possiamo vedere una colorazione del grafo di Petersen con 3 colori
![[Pasted image 20250110181342.png|170]]


Per un grafo completo $K_n$ per definizione ogni nodo è connesso da un arco quindi se il grafo a n nodi serviranno n colori


Se abbiamo un grafo bipartito G = {V,E} sappiamo che i nodi sono posizionati in 2 insiemi $V_1$ e $V_2$ possiamo colorare ogni vertice dello stesso insieme con lo stesso colore, quindi il grafo è 2-colorabile
![[Pasted image 20250110215016.png|300]]


**Una colorazione ottimale di un grafo è una colorazione dei nodi di G che usa il numero minimo di colori, ossia χ(G)**
Anche per questo problema non esistono algoritmi veloci

Ci sono però alcuni risultati per casi speciali, e risultati che ci danno un limite superiore a χ(G)

---

**Teorema di Brooks**
Sia G = {V,E} <u>un grafo connesso</u> con n nodi e siano $δ_1 ≥ δ_2 ≥ · · · ≥ δ_n$ i gradi dei nodi del grafo in ordine decrescente. Allora χ(G) ≤ $δ_1$ + 1

**Dimostrazione**
Il Teorema si può facilmente dimostrare per induzione. Se togliamo infatti il vertice di grado maggiore $v_1$, rimaniamo con un grafo con un vertice in meno e colorabile, per ipotesi induttiva, con al più $δ_2 + 1 ≤ δ_1 + 1$ colori. Quando aggiungiamo il vertice tolto, il caso peggiore è che i $δ_1$ vertici a lui connessi, siano tutti di colore diverso e quindi gli dobbiamo dare il colore rimasto dei $δ_1 + 1$

**Teorema di Brooks, versione forte**
Sia G = {V,E} un grafo connesso con n nodi, e siano $δ_1 ≥ δ_2 ≥ · · · ≥ δ_n$ i gradi dei nodi del grafo in ordine decrescente. Se G non è un grafo completo e G non è un ciclo semplice con numero dispari di nodi, allora χ(G) ≤ δ1.

---

Nel corso dei secoli si accorsero che le mappe geografiche potevano essere sempre colorate usando solo 4 colori
![[Pasted image 20250111145932.png|400]]
Immaginando che ogni regione sia un nodo diverso.
![[Pasted image 20250111150032.png|210]]
Il problema della colorazione di una mappa è equivalente al problema della colorazione di un grafo planare

**Teorema dei 4 colori**
Sia G = {V,E} un grafo planare, allora χ(G) ≤ 4
**Esempio**
![[Pasted image 20250111150920.png|200]]
A(rosso) 
B(blu) 
C(rosso) 
D(blu) 
E(rosso)
F(rosso)
G(verde)

---

##### **Albero libero**
**Definizione**
Un albero libero è un grafo G = {V,E} connesso e aciclico

- Quindi per quanto dimostrato un albero ha |V| - 1 archi
- Ogni vertice ha grado almeno 1 inoltre almeno 1 vertice ha grado 1 altrimenti ci sarebbe un ciclo
![[Pasted image 20250111151339.png|400]]


**Terminologia**
![[Pasted image 20250111151505.png|600]]

![[Pasted image 20250111152123.png|650]]
![[Pasted image 20250111152219.png|300]]

---
##### **Alberi Radicati**

Se immaginiamo di prendere un albero e piantare un chiodo su un nodo dell'albero in una lavagnetta, l'albero cadrà per gravita, otteniamo cosi un albero radicato o semplicemente albero
![[Pasted image 20250111152557.png|500]]

![[Pasted image 20250111152923.png]]
![[Pasted image 20250111153030.png|200]]





#### **PROBLEMI COMBINATORI SU GRAFI**
###### **Numero Cromatico**
Il numero cromatico è la χ(G) ovvero la colorazione ottimale del grafo, al giorno d'oggi non esistono algoritmi efficienti per risolvere il problema, 
attenzione perché l'algoritmo esiste ma non è efficiente, infatti bisogna controllare tutte le n! permutazioni (n = |V|) quindi per un grafo da 100 nodi abbiamo: $9^{157}$ permutazioni 
**ma allora come fare?**
- Se il grafo è piccolo (n ≤ 10) possiamo anche usare l'algoritmo inefficiente
- Se il grafo è planare allora χ(G) è al più 4
- In generale, l’unica cosa che possiamo fare è rinunciare all’ottimalità e provare a trovare una colorazione qualunque, che si spera sia buona e per fare ciò si usano algoritmi di approssimazione

**Algoritmo "greedy" per la colorazione (approssimazione)**
Abbiamo un grafo e cominciamo da un nodo qualunque:
A lo coloriamo di blu, poi ci spostiamo al nodo B e lo coloriamo di rosso, il nodo C lo possiamo di nuovo colorare di blu continuiamo cosi fino ad ottenere:
![[Pasted image 20250112110507.png|400]]
L’algoritmo è "greedy" perché ad ogni passo cerca di fare la scelta migliore, ovvero, nello specifico cerca di usare uno dei colori già usati. 
Abbiamo risolto il problema generale? 
Purtroppo no. 
Siamo stati fortunati, l’ordine dei nodi che abbiamo scelto (la permutazione) è stata buona
Ma potrebbe capitare una permutazione sfortunata come ad esempio questa:
![[Pasted image 20250112110715.png|400]]

dove abbiamo usato più colori di prima

##### **Questo ed altri sono detti problemi $N P-hard$**  
Ovvero problemi per cui non esistono algoritmi "polinomiali" (efficienti) ma solo algoritmi esponenziali o di approssimazione

---
**Rendere aciclico un grafo**
Se il grafo contiene dei ciclo vogliamo eliminare il minor numero di nodi in modo da renderlo a ciclico
Questo problema $N P-hard$ si chiama: Feedback Vertex Set minimo (MFVS)
- Come trovare un FVS? 
- Semplice: controlliamo tutte le permutazioni dei vertici del grafo. 
- Per ogni permutazione, togliamo i vertici uno alla volta seguendo l’ordine della permutazione e ci fermiamo quando otteniamo un grafo aciclico. 
- Soluzione semplice ma improponibile.
- Dato che il problema è N P-hard sappiamo di non poter fare di meglio. Possiamo provare con un algoritmo di approssimazione greedy

**Algoritmo greedy per il MFVS**
![[Pasted image 20250112111714.png|600]]
![[Pasted image 20250112111722.png|300]]

##### **Elenco problemi $N P-hard$** 
1) problema dell’esistenza di un ciclo hamiltoniano
2) problema del commesso viaggiatore
3) problema della χ(G) (numero cromatico)
4) problema del Feedback Vertex Set minimo (MFVS)
5) Problema del massimo insieme indipendente
6) Problema del vertex cover

**Tutti i problemi visto fino ad ora si possono caratterizzare in questo modo:**
Trova une permutazione dell’insieme dei vertici .... che ti dia il risultato migliore

