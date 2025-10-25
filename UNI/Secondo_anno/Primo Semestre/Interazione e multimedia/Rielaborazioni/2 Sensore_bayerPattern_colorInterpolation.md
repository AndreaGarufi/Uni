Quando la luce colpisce un oggetto, una parte viene assorbita ed una parte viene riflessa. 
Quella che viene riflessa, da’ origine al colore percepito.
Per creare una immagine digitale, è essenziale che tale luce riflessa sia catturata da un sensore ed elaborata

**Come funziona il sensore**
L’energia che colpisce il sensore è trasformata in impulso elettrico dal sensore che è fatto di un materiale particolarmente sensibile alla luce. Tale impulso elettrico è successivamente digitalizzato


Nelle macchine fotografiche digitali, i sensori sono disposti su una matrice. 
Non è necessario spostare il sensore, come nei casi precedenti, per effettuare una scansione.
I più diffusi sensori di questo tipo sono i CCD

**CCD: Charged Coupled Device**
Le celle del CCD sono sensibili alla luce e assumono una carica positiva se colpiti, non possono over-saturarsi perché è come se fossero dei secchi di acqua che oltre un certo limite non possono riempirsi, il parametro di qualità per misurare il numnero di celle è il megapixel.
![[Pasted image 20251025110811.png]]


Poiché ogni cella memorizzerà solo un colore per volta e non una terna, occorre scegliere qual è il modello di memorizzazione ottimale,i due colori mancanti per completare la terna, saranno ottenuti per interpolazione dai pixel vicini

**Bayer pattern**
l'algoritmo migliore di color interpolation è il **bayer pattern**, esso presenta un rapporto 1:2:1 per R:G:B quindi si ha un maggior numero di pixel verdi nella matrice, predilige il canale verde perché è il più importante per la percezione umana, per salvare un immagine in bayer pattern si utilizza il formato raw
![[Pasted image 20251025111257.png|300]]
Il verde rispetto a blu e rosso singolarmente è il doppio, quindi se sommiamo blu e rosso otteniamo lo stesso numero di verde
![[Pasted image 20251025111436.png|350]]

Se per ogni pixel, si memorizza solo una componente di colore, tutte le altre dovranno essere ottenute per interpolazione dai pixel vicini,infatti:
![[Pasted image 20251025111604.png|600]]

La matrice di dati rilasciati dal sensore può essere visualizzata come immagine. In questo caso si vedrebbe una immagine in scala di grigi. 
L’aver conservato solo una componente della terna del colore comporta la visione dell’immagine come se fosse composta da un mosaico.
Per ottenere una immagine a colori occorre procedere con un algoritmo di color interpolation che ricava i valori mancanti per ogni singola terna dai dati dell’intorno. 
Poiché dall'immagine a colori sparisce l’effetto a mosaico, l’algoritmo di color interpolation viene anche chiamato algoritmo di «demosaicking»

![[Pasted image 20251025111833.png|450]]

Anche in questo caso di color interpolation abbiamo varie tecniche:
REPLICATION
Per ogni singolo pixel gli elementi mancanti della terna vengono copiati dall’intorno. 
Questa tecnica viene anche chiamata «Nearest-neighbor interpolation»
![[Pasted image 20251025112029.png|450]]

BILINEAR
Nella matrice di R non si deve fare nulla.
In G occorre ricavare i dati da un intorno selezionando i 4 valori rilasciati dal sensore.
In B occorre ricavare i dati da un intorno selezionando i 4 valori rilasciati dal sensore
![[Pasted image 20251025112146.png|500]]
La stessa cosa si ripete rispettivamente per gli altri 2 colori
![[Pasted image 20251025112253.png|400]]

