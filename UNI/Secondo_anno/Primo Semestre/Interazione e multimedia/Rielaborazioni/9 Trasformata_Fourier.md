Una **funzione periodica** può essere espressa come somma di seni e/o coseni di differenti frequenze e ampiezze **(Serie di Fourier)**. Anche una **funzione non periodica**, (sotto certe condizioni) può essere espressa come integrale di seni e/o coseni, moltiplicati per opportune funzioni-peso **(Trasformata di Fourier)**
![[Pasted image 20260102104554.png|500]]

**Ricostruzione**
Sia la serie di Fourier che la Trasformata di Fourier condividono il fatto che una funzione possa essere “ricostruita” (recovered) con un semplice processo di inversione senza perdita di informazione
E’ cioè possibile lavorare nel cosiddetto dominio di Fourier e tornare nel dominio originale della funzione in maniera del tutto naturale

**Immagini come funzioni**
Un'immagine può essere vista come una funzione discreta in cui i valori rappresentano i livelli di grigio dei pixel, questa funzione immagine può essere vista come un segnale all'interno di un dominio con una propria frequenza (costante o variabile)
![[Pasted image 20260102105149.png|600]]


**Trasformata (DFT) e antitrasformata di Fourier**
$$
F(u,v) = \frac{1}{MN} \sum_{x=0}^{M-1} \sum_{y=0}^{N-1} f(x,y) e^{-i 2\pi \left( \frac{ux}{M} + \frac{vy}{N} \right)} \quad \text{per } u=0, \dots, M-1; \ v=0, \dots, N-1
$$
Questa formula converte l'immagine 2-D dal dominio dei pixel (x,y) a quello delle frequenze (u,v) e serve ad analizzare quali frequenze compongono l'immagine

$$
f(x,y) = \sum_{u=0}^{M-1} \sum_{v=0}^{N-1} F(u,v) e^{i 2\pi \left( \frac{ux}{M} + \frac{vy}{N} \right)} \quad \text{per } x=0, \dots, M-1; \ y=0, \dots, N-1
$$
Mentre questa è l'antitrasformata e converte dal dominio delle frequenze a quello dei pixel, in pratica serve a ricostruire l'immagine partendo dal segnale che abbiamo trovato con la prima formula
**A cosa servono?**
Quindi quando un immagine deve essere modificata, l'ordine di esecuzione è questo:
Applico la trasformata di Fourier per convertire l'immagine in segnale, applico le modifiche (sfocature ecc...) direttamente sul segnale che ho ricavato con la prima formula e successivamente riconverto da segnale a immagine ricostruendo usando l'antitrasformata di Fourier

**Formula di Eulero**
Per ogni numero reale X si ha che: 
$e^{ix} = cos \,\,x + i sen\,\, x$
e  quindi:
$e^{-ix} = cos \,\,x - i sen\,\, x$

![[Pasted image 20260102200054.png]]

Per lo spettro noi consideriamo il valore assoluto:
![[Pasted image 20260103100456.png]]

**Range dinamico**
Quando si visualizza lo spettro di Fourier come immagine di intensità, esso manifesta in genere una dinamica molto più grande di quella riproducibile su un tipico display, per cui solo le parti più luminose dello spettro risulteranno visibili, possiamo ovviare a questo mediante una compressione di tipo logaritmo che tende a normalizzare i valori dentro un certo range così che l'immagine sia visibile:
$D(u,v)=c \,\,\,log(1+ F(u,v))$ , D è l'immagine normalizzata, F è il segnale ottenuto con la trasformata di Fourier, e c è una costante per normalizzare i valori.

![[Pasted image 20260102210854.png]]

![[Pasted image 20260102210911.png|500]]
Questa è l'immagine $|F(u,v)|$ 
![[Pasted image 20260102210941.png|500]]
Questa è $D(u,v)$

La visualizzazione dello spettro riguarda in realtà non $|F(u,v)|$ ma una sua versione compressa logaritmicamente. Altrimenti si vedrebbe solo un puntino al centro.

*L’ampiezza* contiene l’informazione relativa al fatto che **una certa struttura periodica è presente nell'immagine**. 

*La fase* contiene l’informazione **relativa al dove le strutture periodiche evidenziate nella DFT sono collocate**. Quindi è molto più significativa di quello che possa sembrare nell’immagine

|**Immagine**|**Tipo di segnale**|**È periodico?**|**Dove si vede nello Spettro?**|
|---|---|---|---|
|**Cielo Azzurro**|Costante (piatto)|**NO**|Un forte punto luminoso solo al **centro**.|
|**Muro di Mattoni**|Pattern ripetuto|**SÌ**|Punti luminosi (o "stelle") sparsi **attorno al centro**.|
|**Volto umano**|Complesso, non ripetitivo|**NI** (misto)|Una nuvola diffusa attorno al centro, senza punti netti e isolati.|

![[Pasted image 20260103101416.png]]
(Solo modulo intende $|F(u,v)|$)

![[Pasted image 20260103101502.png]]

**Vantaggi della trasformata di Fourier**
Nello spazio delle frequenze è possibile: 
 sopprimere frequenze indesiderate 
 ridurre lo spazio occupato dai dati pur limitando la degenerazione del segnale (JPEG, MPEG, DivX, MP3) 
 rigenerare segnali degradati

**Discussioni**
La trasformazione diretta può essere vista come un processo di analisi: il segnale $f(x)$ viene scomposto nelle sue componenti elementari, che sono nella forma dei vettori di base. I coefficienti della trasformata specificano quanto di ogni componente di base è presente nel segnale. Nella trasformazione inversa, mediante un processo di sintesi, il segnale viene ricostruito, come somma pesata delle componenti di base: il peso di ogni vettore di base nella ricostruzione del segnale è rappresentato dal corrispondente coefficiente della trasformata. Il coefficiente della trasformata è una misura della correlazione tra il segnale ed il corrispondente vettore di base. La trasformazione non comporta perdita di informazione: essa fornisce solo una rappresentazione alternativa del segnale originale

Esistono anche altre trasformate utilizzate nell'image processing e nella compressione delle immagini.


**Alcune proprietà della DFT 2-D** 
Con 2-D si intende un segnale bidimensionale ovvero un segnale che per ogni punto da individuare ha bisogno di 2 coordinate x,y (1-D -> x,   2-D -> x,y   3-D -> x,y,z)
1) Separabilità 
2) Traslazione 
3) Valor Medio 

**Separabilità**
La trasformata di Fourier può essere separata ovvero per trovare la soluzione al problema 2-D posso calcolare 2 problemi 1-D e unirli:
![[Pasted image 20260103103748.png]]

in pratica prima trovo k usando la formula 1-D e poi applico un'altra formula 1-D su k per ottenere entrambe le coordinate che mi servono

**Traslazione**
Nel caso bidimensionale è utile prima di operare sulla trasformata applicare uno shift (traslazione) dell’origine nel punto ($M/2, N/2$) cioè nel centro della matrice dei coefficienti delle frequenze. In questo modo i dati vengono traslati in maniera tale che $F(0,0)$ risulti il centro del rettangolo delle frequenze definito tra $[0,M-1]$ e $[0,N-1]$
Queste proprietà vengono utilizzate per una migliore visualizzazione dello spettro
![[Pasted image 20260103104046.png]]
Nella parte di destra abbiamo applicato la traslazione in quella di sinistra no

La trasformata è però sensibile alla rotazione, applicarla potrebbe cambiare il risultato

**Valor medio**
![[Pasted image 20260103104327.png]]


**Complessità**
Nella sua forma classica la trasformata di Fourier è molto difficile da eseguire perché richiederebbe $N^2$ moltiplicazioni (N moltiplicazioni complesse e N-1 addizioni per ciascuno degli N valori di u). Per questo motivo attraverso varie tecniche di semplificazione si è riusciti ad arrivare alla *Fast Fourier transform* (FFT) che abbassa la complessità a $N\,\,\,log\,\,\,N$ 
![[Pasted image 20260103104651.png|400]]

**Frequenze: Low and High**
Esclusi i casi banali è normalmente impossibile fare associazioni dirette fra specifiche parti dell’immagine e la sua trasformata, perché la trasformata in se non ci da locazioni spaziali (per quello serve conoscere la fase), però ricordando che la frequenza è legata alla velocità di variazione è però possibile associare le basse frequenze alle zone uniformi dell’immagine, quelle alte alle variazioni più o meno brusche e quindi ai bordi o al rumore


**Filtraggio nel dominio della frequenza**
Ecco lo schema che si segue solitamente per applicare filtri alle immagini nel dominio della frequenza:
![[Pasted image 20260103192836.png|600]]

**TEOREMA DELLA CONVOLUZIONE**
Per gli operatori puntuali e locali si usa il dominio spaziale (si agisce direttamente sui pixel) mentre per gli operatori globali, che usano tutti i pixel dell'immagine si preferisce usare il dominio delle frequenze, perche?
Perché vale il seguente teorema

**La trasformata della convoluzione di due segnali nel dominio spaziale equivale al prodotto delle trasformate dei due segnali**

che significa anche:
**La convoluzione di due segnali nel dominio spaziale equivale all’antitrasformata del prodotto delle trasformate dei due segnali**

Il fondamento teorico dell'elaborazione delle immagini nel dominio delle frequenze è dato dal teorema di convoluzione
Questa è l'operazione nel dominio spaziale:
![[Pasted image 20260103192600.png]]

mentre questa in quello delle frequenze
![[Pasted image 20260103192729.png|500]]
Dove F è la trasformata dell'immagine, e H è la trasformata del filtro
Complessità per un segnale 1-D: 
Nel dominio delle frequenze $O(n\,\,\, log\,\,\,n)$ 
Nel dominio spaziale $O(n^2 )$
E' quindi conveniente passare al dominio delle frequenze

**Filtraggio...**
- Se il filtro ha dimensioni confrontabili con quelle dell’immagine è più efficiente computazionalmente effettuare il filtraggio nel dominio delle frequenze
- Con maschere (kernel), ovvero matrici più piccole diviene più efficiente il calcolo nel dominio spaziale
- La definizione di un filtro nel dominio delle frequenze è più intuitiva

Come ottenere un filtro a partire da una maschera spaziale 
1. Il filtro H ha la stessa dimensione dell’immagine I; 
2. H deve avere in alto a sinistra i valori della maschera spaziale, nel resto sempre il valore 0; 
3. Si fa lo shift di H 
4. Si calcola da H la trasformata di Fourier

**Filtri low pass**
Un filtro low pass è un filtro che lascia "passare" le basse frequenze e azzera o attenua quelle alte:
![[Pasted image 20260103193557.png]]
$D_0$ è la frequenza di cutoff ovvero una frequenza limite sotto il quale il filtro vale 1 sopra vale 0, 
- Ideal -> filtro ideale (teorico), sopra una certa frequenza taglia di netto
- Butterworth -> è una via di mezzo tra ideal e gaussiano, quindi è più morbido
- Gaussian -> il più morbido di tutti

**Filtri high-pass**
Sono il contrario di quelli low-pass
![[Pasted image 20260103194131.png]]

**Filtri band reject nel dominio della frequenza**
Seleziona un range di frequenze ed elimina solo quello, tutto quello sopra o sotto rimane intatto
![[Pasted image 20260103195039.png]]

Per capire come funzionano vedi pdf numero [[10 Lez 12 Fourier 2024-25.pdf|"10 Fourier"]] da slide 54 a 82

