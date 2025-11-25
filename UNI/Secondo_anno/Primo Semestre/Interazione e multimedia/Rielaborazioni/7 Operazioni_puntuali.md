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

Un operatore puntuale può essere descritto come una funzione che prende un immagine f(x,y) applica un operazione T e restituisce una seconda immagine g(x,y) diversa in qualcosa dalla prima.
![[Pasted image 20251125103249.png|500]]

Ad un input che è 0 la funzione restituisce 2, input = 1 restituisce 3 e cosi via, questo è un esempio di una funzione di questo genere

Questo tipo di grafico si chiama look-up tables (LUT)
![[Pasted image 20251125103459.png|300]]
Sono delle tabelle che associano ad un valore di f (x, y), il valore g(x, y) data una trasformazione T 


- **NEGATIVO**
  E' la più semplice operazione puntuale e inverte il valore del pixel f(x,y) seguendo la formula 255-f(x,y) (il bianco diventa nero e il nero diventa bianco e cosi via)
  ![[Pasted image 20251125104050.png|400]]
  Ovviamente cambiano anche gli istogrammi perché si invertono
- **TRASFORMAZIONE LOGARITMICA**
  Si tratta di una trasformazione che consente di comprimere la gamma dinamica, permettendo la memorizzazione o la visualizzazione, con una scala dei grigi usuale, di immagini caratterizzate da escursioni di intensità molto ampie.
  (comprime i valori alti dal bianco verso il grigio e il valori bassi dal nero verso il grigio)
  $g(x, y) = c · log(1 + f (x, y))$ 
  c è una costante positiva che serve a normalizzare i valori all'interno del range (0,255)
  ![[Pasted image 20251125105303.png|400]]
  ![[Pasted image 20251125110342.png|400]]
  A noi interessa in questo caso vedere come è la curva della trasformazione logaritmica
  
- **Trasformazione di potenza**
  La trasformazione di potenza può essere espressa come:
  $g(x, y) = c · (f (x, y))^γ$
  anche qui c è una costante positiva che serve a normalizzare il valore del pixel, mentre per γ anche lei ha sempre valore positivo e per valori minori di 1 ha effetti simili alla trasformazione logaritmica, mentre per valori maggiori di 1 ha effetti opposti
  ![[Pasted image 20251125110436.png|580]]
  Possiamo vedere che per gamma = 1 l'immagine resta la stessa, per gamma minore di 1 segue la funzione del logaritmo di prima e per valori superiori a 1 diventa l'opposto del log
  ![[Pasted image 20251125110701.png|500]]
- **BINARIZZAZIONE**
  Rende l'immagine in bianco e nero, si sceglie una soglia T sotto la quale ogni pixel diventerà nero e ogni pixel sopra diventerà bianco
- **VARIAZIONI DI CONTRASTO**
  Aumentare il contrasto, significa rendere più evidenti le differenze di colore. Ciò si ottiene andando a cambiare il valore di un pixel con un altro che sia più scuro o più chiaro
  ![[Pasted image 20251125111634.png]]
- **CURVE NON MONOTONE**
  È possibile fare delle variazioni alle curve in modo che questa diventi non monotona, ovvero anziché crescere sempre, potrebbe in alcuni punti decrescere, un esempio è la solarizzazione
  ![[Pasted image 20251125111929.png|600]]
  
  La **solarizzazione**, nelle operazioni puntuali, è una trasformazione che **inverte i toni solo oltre una certa soglia**.  
  In pratica: fino a un certo valore l'immagine resta normale, oltre quel valore i pixel diventano il loro negativo.
  
  

  

