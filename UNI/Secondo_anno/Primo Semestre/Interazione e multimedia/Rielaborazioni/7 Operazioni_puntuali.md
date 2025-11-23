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


   


