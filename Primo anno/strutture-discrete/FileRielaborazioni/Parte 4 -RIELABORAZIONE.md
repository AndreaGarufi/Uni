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
**Grafo semplice orientato**
Un grafo semplice orientato, denotato con G = (V,E) è praticamente uguale al grafo non orientato solo che qua conta la direzione: infatti ci sono delle frecce tra i 2 nodi che ne indicano il verso
![[Pasted image 20250105153947.png|250]]

**I grafi orientati e non che hanno più di un arco che collega coppie di nodi sono detti multigrafi**
![[Pasted image 20250105154139.png|550]]

nei multigrafi possiamo avere un arco che collega lo stesso nodo, questo si chiama cappio

