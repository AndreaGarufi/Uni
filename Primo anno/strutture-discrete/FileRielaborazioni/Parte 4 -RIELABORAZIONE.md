**Parte IV: Grafi ed Alberi**
**Contenuti**
![[Pasted image 20250105145017.png|500]]
![[Pasted image 20250105145043.png|500]]


**INDICE SULLE TIPOLOGIE DI GRAFI**
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
Un grafo Bipartito G = {V,E} si dice completo se data la partizione dei vertici $V_1$ e $V_2$ esiste un arco per ogni coppia di nodi $v ∈ V_1$ e $u ∈ V_2$
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
**G = {V',E'} ottenuto eliminando da G tutti i vertici non appartenenti a V' e tutti gli archi incidenti ad almeno uno dei vertici eliminati**
![[Pasted image 20250106110805.png]]

---

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
Sia G = {V,E} un grafo e sia V = $V_1 ∪ V_2 ∪ · · · ∪ V_k$  la partizione indotta dalla relazione di connessione tra i nodi. Sia G = {$V_i,E_i$} il sottografo indotto da $V_i$ per ogni i = 1...k. Tali sottografi si chiamano componenti connesse di G

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
Il grafo G si dice **k-connesso rispetto ai nodi** se dati due vertici u, v esistono k cammini a nodi disgiunti tra u, v

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
2) oppure se 2 per ogni i ∈ $V δ^−(i)$ > 0
allora G contiene un ciclo
**Dimostrazione** (dimostriamo solo il primo caso perché per il secondo è analogo)
Se prendiamo un nodo $i_0$ sappiamo che il $δ^+(v)$ è > 0 quindi è collegato ad un altro nodo $i_1$ che a sua volta sarà collegato ad un altro nodo $i_2$ e cosi via, per avere un ciclo abbiamo bisogno che tutti i nodi siano collegati tra loro, quindi per il Pigeonhole Principle sappiamo che c'è un ciclo perché se ogni nodo ha grado in uscita > 0 saranno tutti connessi

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

slide 84