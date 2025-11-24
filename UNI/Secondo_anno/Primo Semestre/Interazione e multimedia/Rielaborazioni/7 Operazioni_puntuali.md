Possiamo vedere l'insieme dei pixel come una popolazione, su cui si possono ricavare varie informazioni
Una molto utile è l'istogramma

**Istogramma**
Per ogni livello di grigio (dal nero al bianco) si riporta il numero di pixel di quel colore
Per un immagine $I[m,n]$ si ha che $H(k)$ è il numero di pixel della tonalità k e la somma di tutti gli H è esattamente m x n
![[Pasted image 20251123201542.png]]

L'istogramma non tiene conto della distribuzione spaziale dei pixel (posizione) infatti immagini diverse possono avere istogrammi simili, basta che entrambe le immagini abbiamo lo stesso numero di pixel per le stesse tonalità di grigio

La tonalità dell'istogramma varia da nero a destra fino al bianco a sinistra, logico pensare che se un immagine è chiara l'istogramma sarà spostato verso sinistra e viceversa

**Espansione del contrasto (contrast stretching)**
È una tecnica che “allarga” i valori dei pixel quando un’immagine ha un contrasto scarso, cioè quando i toni sono tutti troppo vicini tra loro (ad esempio tutto un po’ grigio).  
Se l’immagine usa solo una piccola parte dei valori possibili, l’espansione del contrasto li “spinge” sull’intero intervallo.

![[Pasted image 20251123202015.png]]
Come si può vedere ci sono delle parti dell'istogramma non utilizzate e dopo l'espansione del contrasto l'istogramma si "stretcha"  assumendo un immagine a pettine
![[Pasted image 20251123202221.png]]

**Equalizzazione**
Si parla di *immagine equalizzata* quando il contributo di ogni differente tonalità di grigio è pressappoco eguale. Si parla anche di “istogramma” uniforme o appiattito. L’equalizzazione si ottiene usando appositi algoritmi. Attenzione non sempre l' equalizzazione migliora l’immagine! 
![[Pasted image 20251123203256.png|450]]
**Algoritmo di equalizzazione**

Se $r_k$ è un livello di grigio e $n_k$ il numero di pixel nell’immagine MxN di quel livello di grigio, si può definire
![[Pasted image 20251124091349.png]]
Se facciamo il plot di $r_k$ versus $p_r (r_k )$ quello che si ottiene è l’istogramma dell’immagine
I nuovi valori di grigio dell’istogramma sono così definiti:
![[Pasted image 20251124091436.png]]


**ARITMETICA SULLE IMMAGINI**
Dopo alcune operazioni aritmetiche sulle immagini può capitare che 
1) alcuni pixel abbiano valori negativi 
2) valori maggiori del massimo (255) 
3) oppure un valore non intero

il punto 3 si risolve facilmente troncando o approssimando il numero

i problemi 1 e 2 si chiamano *problemi di range* 
abbiamo 2 modalità di esecuzione per risolverli:
1) settare a 0 (nero) i pixel con valore negativo e a 255 (bianco) i pixel con valore superiore al massimo
2) Rinormalizzare il range trasformando ciascun valore secondo l'equazione:
   ![[Pasted image 20251123202650.png]]


**OPERAZIONI SULLE IMMAGINI**
Per semplificare lavoreremo su immagini a toni di grigio, le medesime operazioni valgono anche per RGB, infatti si agisce sui 3 canali separatamente e agendo come se fossero immagini in toni di grigio
Queste operazioni vanno a modificare i pixel quindi l'immagine originale apparirà differente da quella finale

Le operazioni possiamo definirle così: $g(x,y) = T[f(x,y)]$ 
dove $g$ è l'immagine in uscita, $f$ è quella in entrata a cui viene applicato un operatore $T$ nell'intorno $x,y$

La dimensione dell’intorno di $(x,y)$ definisce il carattere della elaborazione:
*Puntuale* -> agisce sul singolo pixel e x,y corrispondono a questo pixel
*Locale* (per esempio una piccola regione quadrata centrata sul pixel); 
*Globale* (l’intorno coincide con l’intera f)

**Operatori puntuali**
**Definizione**
Si dice operatore puntuale, un operatore che preso in input il valore di un pixel ne restituisce uno cambiato che dipende esclusivamente dal valore del pixel in ingresso

**Tipiche operazioni puntuali**
1) aggiunta o sottrazione di una costante a tutti i pixel (per compensare sotto o sovraesposizioni)
2) inversione della scala dei grigi (negativo)
3) espansione del contrasto
4) modifica (equalizzazione o specifica) dell'istogramma
5) presentazione in falsi colori

