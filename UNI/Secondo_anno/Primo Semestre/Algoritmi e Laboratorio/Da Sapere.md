### **RICORSIONE**
Per applicare la ricorsione devo scomporre il problema in più problemi identici a quello di partenza che siano più piccoli 

### **PROBLEMA DI OTTIMIZZAZIONE**
L'ottimizzazione è una caratteristica del problema che esiste a prescindere dalla soluzione.
Un problema si dice di ottimizzazione quando questo ha più soluzioni ma non tutte sono uguali e la capacità di prendere la soluzione con valore di *bontà* più alto (o più basso) in base a ciò che chiede il problema stesso

Bontà = punteggio assegnato alle soluzioni per scegliere poi la migliore

### **ALBERO DI RICORSIONE**
E' un albero dove ogni nodo corrisponde ad una chiamata ricorsiva
![[Pasted image 20251011114749.png]]

**Aspetti negativi della ricorsione**
- La ricorsione occupa memoria per le tante chiamate
- Algoritmo iterativo più veloce a livello pratico perché non deve gestire chiamate nella memoria
### **EQUAZIONE DI RICORRENZA**
Descrive il tempo di esecuzione di un algoritmo ricorsivo
$T(n)$ dove $T$ è il tempo impiegato in base all'input $n$


### **ANALISI DEL COSTO DI UN ALGORITMO**
Analisi asintotica $->$ comportamento dell'algoritmo con valori molto grandi
**Confronto tra funzioni**
1) $F(n) = k | 0<k<∞$ **costante**
2) $F(n) = n$ cresce **linearmente** all'input dato
3) $F(n)= log_2\,\,\,n$ cresce meno rispetto alla lineare
4) $F(n) = n\,\,\,log\,\,\,n$ funzione **linearitmica** cresce un po' di più della funzione lineare

- funzioni polinomiali
5) $F(n^2)$ funzione **quadratica**
6) $F(n^3)$ funzione **cubica** e cosi via...

- funzione esponenziale
 7) $F(n)= k^n$ 

- Funzione fattoriale
8) $F(n)= n!$
![[Pasted image 20251011121033.png]]


### **COME CAPIRE LA CLASSE DI UNA FUNZIONE**
Se la funzione è $F(n) = n^3 + 7n^4 + 2n\,\,log^3\,\,n+3$
confrontiamo i termini e da li capiamo quello con la grandezza maggiore:
in questo caso quello che cresce più velocemente è $7n^4$ quindi l'ordine di grandezza è $n^4$

Le classi principali sono 3  $𝚯(g(n))$, $O(g(n))$, $Ω(g(n))$ 
1) $𝚯(g(n))$ -> theta di g di n
   è la classe di tutte le funzioni che hanno un comportamento asintotico simile a g(n),
   $$𝚯(g(n))= \{F(n):Ǝ\,\, c_1,c_2,n_0| 0≤ c_1\,g(n)≤F(n)≤ c_2\,g(n)∀n ≥ n_0  \}$$
![[Pasted image 20251011154542.png|300]]
$F(n)$ sta sempre in mezzo o al massimo uguale a $c_1\,g(n)$ e $c_2\,g(n)$

2)  $O(g(n))$ 
   è la classe che limita superiormente il comportamento di una funzione: ovvero la funzione non andrà mai sopra $O(n)$
   $$O(g(n)) = \{F(n):Ǝ\,\, c,n_0| 0≤ F(n)≤c\,g(n)∀n ≥ n_0\}$$ ![[Pasted image 20251011155511.png|300]]
$F(n)$ sta sempre sotto o al massimo uguale alla funzione $O(g(n))$

3) $Ω(g(n))$
   è la classe che limita inferiormente il comportamento di una funzione: ovvero la funzione non andrà mai sotto $Ω(g(n))$
   $$Ω(g(n)) = \{F(n):Ǝ\,\, c,n_0| 0≤ c\,g(n)≤F(n)∀n ≥ n_0\}$$   
![[Pasted image 20251011160111.png|300]]
$F(n)$ sta sempre sopra o al massimo uguale alla funzione $Ω(g(n))$

esiste anche $o$ piccolo ed è uguale a $O$ solo che la funzione si comporta sempre meglio e mai uguale

**Nella realtà...**
Tuttavia, nella pratica, gli algoritmi raramente operano nei loro casi estremi. Un algoritmo descritto come $O(n^2)$ potrebbe, in molti scenari reali, comportarsi quasi sempre come un algoritmo $O(n\,\,log\,\, n)$, se le condizioni medie del problema lo favoriscono. Viceversa, un algoritmo con complessità $Ω(n)$ nel caso migliore potrebbe raramente riuscire a raggiungere quel limite, perché le situazioni ottimali sono poco frequenti.

Nell’analisi asintotica degli algoritmi, è prassi comune trascurare i fattori costanti e i termini di ordine inferiore. Questo approccio consente di concentrarsi sulla crescita dominante della funzione di costo al crescere della dimensione dell’input n. Tuttavia, nella pratica quotidiana — soprattutto per input di piccole o medie dimensioni — queste costanti possono fare una differenza sostanziale.

Infatti magari un algoritmo con una complessità peggiore potrebbe essere più efficiente (per input medi o piccoli) di un altro con complessità migliore
In sintesi, possiamo dire che: 
• le notazioni asintotiche descrivono il comportamento a lungo termine;
• i fattori costanti e i termini minori influenzano le prestazioni nel breve termine; 
• un algoritmo asintoticamente migliore può essere più lento di un altro per una vasta gamma di input reali.



### **A partire dalla procedura posso capire la classe?**
(si) da capire e fare


### **RISOLUZIONE EQUAZIONI DI RICORRENZA**
Se indichiamo con T(n) il costo dell’algoritmo su un problema di dimensione n, possiamo esprimere questo comportamento nel modo seguente:
$$T(n) = aT(\frac{n}{b}) + f(n)$$Dove a rappresenta il numero di sottoproblemi prodotti, b il fattore di riduzione della dimensione e f (n) il costo complessivo delle operazioni non ricorsive, ossia di tutte quelle attività che non comportano nuove chiamate, come la divisione del problema, la fusione dei risultati o eventuali operazioni preliminari

Non tutti gli algoritmi ricorsivi possono essere descritti mediante l' equazione soprastante:
(es. quickSort)
Questi esempi mostrano che, quando la riduzione del problema non è uniforme, non è possibile applicare direttamente formule standard come il teorema Master, e occorre analizzare la ricorrenza caso per caso. Tuttavia, i principi generali rimangono gli stessi: è sempre possibile visualizzare la struttura delle chiamate come un albero, contare i nodi generati e sommare i costi dei livelli per ottenere il comportamento complessivo dell’algoritmo

#### **Il metodo dell'albero di ricorsione**
L'idea è costruire un albero in cui ogni nodo rappresenta una singola invocazione dell'algoritmo ed ogni arco corrisponda ad una chiamata ricorsiva. In questo modo possiamo capire passo dopo passo come si distribuisce il lavoro complessivo nei diversi livelli di ricorsione
Immaginiamo di avere un algoritmo descritto da: $$T(n) = aT(\frac{n}{b}) + f(n)$$Il metodo dell’albero di ricorsione consiste nel rappresentare questa relazione sotto forma di un albero in cui:
• la *radice* dell’albero corrisponde al problema iniziale di dimensione $n$; 
• i *nodi interni* rappresentano le chiamate ricorsive generate a ciascun livello; 
• ogni nodo è etichettato con il costo del lavoro locale f ($n_i$), dove $n_i$ è la dimensione del sottoproblema corrispondente; 
• i *figli di un nodo* rappresentano le chiamate generate da quel nodo, ognuna di dimensione ridotta di un fattore $b$.

La costruzione di questo albero permette di scomporre la ricorsione in livelli. Il primo livello contiene un solo nodo (il problema originale), il secondo livello contiene $a$ nodi (uno per ciascun sottoproblema), il terzo livello ne contiene $a_2$, e così via. A ogni livello $k$ dell’albero il numero di nodi è $a^k$, e la dimensione dei sottoproblemi è ridotta a $\frac{n}{b^k}$. Il costo totale associato al livello $k$ può quindi essere scritto come: $$C^k = a^k \,f(\frac{n}{b^k})$$cioè come il numero di nodi di quel livello moltiplicato per il costo del lavoro svolto in ciascun nodo.
L'idea è quella di fare la somma dei costi dei singoli livelli dell'albero
![[Pasted image 20251024110126.png|400]]
dove:
- $L$ rappresenta la profondità dell'albero
Questo approccio fornisce non solo un modo intuitivo per stimare la crescita di T (n), ma anche una rappresentazione visiva dell’andamento del lavoro. Osservando come varia il costo dei livelli successivi, è possibile capire se il lavoro complessivo è dominato dai livelli più alti (quelli vicini alla radice), dai livelli intermedi o da quelli più profondi dell’albero

Abbiamo 3 possibili casistiche che corrispondono ai 3 casi del teorema master
1) Quando la somma è dominata dai primi livelli, il costo totale è determinato dal lavoro iniziale $f (n)$
2) Quando tutti i livelli hanno lo stesso ordine di grandezza, il costo cresce come il numero dei livelli
3) Quando i livelli inferiori diventano progressivamente più costosi, il termine dominante si sposta verso il fondo dell’albero

**COME APPLICARE QUESTO METODO**
**Esempio ricerca binaria**
Consideriamo l'equazione:
$$T(n) = T(\frac{n}{2})+1$$
Ogni chiamata ricorsiva genera una sola chiamata su metà dell'input, e il lavoro aggiuntivo (calcolo dell'indice medio e confronto) è costante. Possiamo immaginare l'albero della ricorsione come una catena di chiamate successive, in cui ogni nodo produce un unico figlio di dimensione dimezzata, è una dimensione che ogni livello si dimezza quindi la profondità dell'albero è pari a $log_2 \,\,n$. Il costo totale si ottiene sommando il lavoro di tutti i livelli
Albero: 
![[Pasted image 20251024113845.png|30]]
$$T (n) = 1 + 1 + 1 + · · · + 1$$
dove il numero dei termini 1 è pari a $log_2 \,\,n+ 1$. Da qui risulta immediatamente che la complessità è $T(n) = O(log n)$
In questo caso, il costo per livello è costante e l’albero ha profondità logaritmica: il risultato è quindi una crescita proporzionale al numero dei livelli



#### Il metodo della sostituzione
Consiste nel formulare un’ipotesi sulla forma asintotica della soluzione e nel dimostrare che tale ipotesi è corretta attraverso un ragionamento induttivo.
Si parte dall’ equazione di ricorrenza e, osservando la struttura del problema, si tenta di “indovinare” la crescita di T (n), ad esempio di O(n) O($n^2$) ecc... . Una volta formulata una ipotesi la si sostituisce nell'equazione e si verifica se l'uguaglianza (o disuguaglianza) risulta soddisfatta per valori sufficientemente grandi di n. Se l’ipotesi risulta coerente, viene così confermata; altrimenti, la si modifica finché non produce una forma valida.
Questo metodo è chiamato “della sostituzione” perché prevede di sostituire l’ipotesi nella ricorrenza, semplificarla e controllare che il risultato sia coerente.

Si hanno quindi 3 fasi da seguire:
1) Si formula un’ipotesi sul comportamento asintotico di T (n). Spesso l’ipotesi deriva dall'intuizione fornita da metodi più intuitivi come l’albero di ricorsione 
2) Si sostituisce questa ipotesi all’interno dell’equazione di ricorrenza e si verifica se l’uguaglianza o disuguaglianza risulta soddisfatta
3) Se necessario, si aggiusta l’ipotesi (ad esempio includendo una costante o un termine logaritmico) fino a ottenere un’espressione coerente

**COME APPLICARE QUESTO METODO**
**Esempio ricerca binaria**
Consideriamo l'equazione:
$$T(n) = T(\frac{n}{2})+1$$
L'intuizione suggerisce una crescita logaritmica. Supponiamo quindi $T(n)≤ c \,log_2 \,\,n$, sostituendolo nell'equazione otteniamo: 
![[Pasted image 20251024135108.png]]
Affinché la disuguaglianza $T(n)≤ c \,log_2\,\,n$ sia rispettata, è sufficiente che $-c+1≤ 0$ cioè $c≥1$ Anche in questo caso la nostra ipotesi è coerente $T(n) = O(log\,\,n)$

#### TEOREMA MASTER (Importante)
Dopo aver visto il metodo dell’albero di ricorsione, che offre una rappresentazione intuitiva della struttura del costo, e il metodo della sostituzione, che consente una verifica formale dell’ipotesi asintotica, possiamo introdurre un terzo strumento, spesso più diretto ed efficace: il Teorema Master questo risultato fornisce una regola generale per determinare in modo sistematico l’ordine di grandezza di molte equazioni di ricorrenza della forma
$$T(n) = aT(\frac{n}{b}) + f(n)$$
dove:
- $a ≥ 1$ il numero di sottoproblemi in cui viene suddiviso il problema di dimensione $n$
- $b>1$ il fattore di riduzione della dimensione di ciascun sottoproblema.
- $f(n)$ il costo del lavoro non ricorsivo, ossia il tempo a suddividere il problema e a combinare i risultati

**Enunciato del teorema master**
Sia $T (n) = a T (n/b) + f (n)$ con $a ≥ 1$, $b > 1$, e $f (n)$ una funzione positiva. Allora valgono i seguenti casi:
1) se esiste una costante $ε > 0$ tale che:
   $$f(n) = O(n^{log_b\,\, a-ε})$$
   cioè il lavoro non ricorsivo è asintoticamente più piccolo del lavoro interno alla ricorsione, allora $$T (n) = Θ(n^{log_b\,\, a})$$
   In questo caso domina il costo generato dalla parte ricorsiva dell’algoritmo (le chiamate interne)

2) (generalizzato) se $$ f(n) = Θ(n^{log_b\,\, a} \,\,log^k\,\,n)$$
   ossia il lavoro non ricorsivo ha lo stesso ordine di grandezza del lavoro ricorsivo (a meno di un fattore logaritmico), allora $$T (n) = Θ(n^{log_b\,\, a} \,\,log^{k+1}\,\,n)$$
   In questo caso, tutti i livelli dell’albero di ricorsione contribuiscono in modo equivalente al costo totale, e la moltiplicazione per un fattore $log^k\,\,n$ nel termine $f (n)$ si traduce in un incremento di un ordine logaritmico nel costo complessivo

3) se esiste una costante $ε > 0$ tale che:
   $$ f(n) = Ω(n^{log_b\,\, a+ε})$$
   cioè il lavoro non ricorsivo cresce più velocemente del lavoro interno, e se inoltre è verificata una condizione di regolarità (detta condizione di dominanza) $a\,f(\frac{n}{b})≤ c\,\, f (n)$ per una costante $c < 1$ e $n$ sufficientemente grande, allora $$T (n) = Θ(f (n))$$
   In questo caso, la parte ricorsiva diventa trascurabile rispetto al lavoro non ricorsivo. Esempio tipico: una ricorrenza come $T (n) = 2T (n/2) + n^2$, dove il termine $n^2$ domina.



**L'idea in breve**
L’idea del Teorema Master è confrontare la funzione $f (n)$ — che misura il lavoro esterno alla ricorsione — con la quantità $n^{log_b\,\, a}$, che rappresenta il costo totale del lavoro ricorsivo. A seconda di quale dei due termini cresce più rapidamente, si individuano tre comportamenti distinti.
In sostanza, $n^{log_b\,\, a}$ descrive quanto “grande” diventa l’albero della ricorsione, mentre $f (n)$ misura il costo aggiuntivo sostenuto a ciascun livello.
Il comportamento finale di $T (n)$ dipende da quale di queste due componenti cresce più rapidamente:
- Se $f (n)$ cresce molto meno di $n^{log_b\,\, a}$ , il termine ricorsivo domina 
- Se cresce molto di più, prevale il termine non ricorsivo 
- Se le due funzioni hanno crescita simile, i contributi si equilibrano e il costo totale si distribuisce tra tutti i livelli.

Il parametro $ε$ viene introdotto proprio per formalizzare questa differenza di crescita: esso rappresenta una “distanza esponenziale” tra le due funzioni.

Quando si scrive, ad esempio, $f (n) = O(n^{log_b\,\, a-ε})$, si intende che f (n) cresce in modo sensibilmente più lento rispetto a $n^{log_b\,\, a}$ , tanto da risultare inferiore di un intero fattore polinomiale. Allo stesso modo, $f (n) = Ω(n^{log_b\,\, a+ε})$

**Come capire in che caso mi trovo**
Un modo semplice per orientarsi è il seguente: se tra $f (n)$ e $n^{log_b\,\, a}$ compare una differenza di potenze, anche minima, questa differenza è sufficiente a stabilire il caso corretto del teorema. Al contrario, quando le due funzioni sono dello stesso ordine, ma $f (n)$ contiene un termine moltiplicativo in $log\,\, n$ o una funzione molto vicina alla crescita polinomiale, il problema rientra nel caso “intermedio”

**Esempio 1**
Consideriamo la ricorrenza $T (n) = 2T (n/2) + n$. Qui $a = 2$, $b = 24 e quindi $n^{log_b\,\, a} = n$. Poiché $f (n) = n$ ha la stessa crescita, non esiste un $ε > 0$ tale che $f (n)$ sia né più piccolo né più grande di un fattore polinomiale rispetto a $n^{log_b\,\, a}$: ci troviamo dunque nel caso intermedio, e la soluzione è $T (n) = Θ(n\,\, log\,\, n)$

**Esempio 2**
Consideriamo invece $T (n) = 2T (n/2) + n^2$. In questo caso $n^{log_b\,\, a} = n$, ma $f (n) = n^2$ cresce più rapidamente di un intero fattore polinomiale, cioè $f (n) = Ω(n^1+ε)$ con $ε = 1$. Qui il termine non ricorsivo domina e la soluzione è $T (n) = Θ(n^2)$

**Applicazione del Teorema Master**
**Esempio ricerca binaria**
La ricerca binaria è descritta dalla ricorrenza $T (n) = T (n/2) + 1$

In questo caso $a = 1$, $b = 2$ e $f (n) = 1$. Calcoliamo il termine di riferimento $n^{log_b\,\, a}$: poiché $log_2\,\, 1 = 0$, si ottiene $n^{log_2\,\, 1} = n^0 = 1$. Confrontiamo ora $f (n)$ con questo valore: $f (n) = 1 = Θ(1) = Θ(n^{log_2\,\, 1})$
Siamo dunque nel secondo caso del Teorema Master, quello in cui $f (n)$ ha lo stesso ordine di grandezza del termine ricorsivo.
Applicando la formula corrispondente, otteniamo: $$T (n) = Θ(n^{log_2\,\, 1}\,log\,\,n) = Θ(log\,\, n)$$
In ogni passo della ricerca binaria, il problema viene dimezzato, ma il la- voro svolto ad ogni livello (una sola comparazione) è costante. Poiché ci sono $log_2\,\, n$ livelli fino a ridurre il problema a un singolo elemento, il costo totale cresce in modo logaritmico. Il Teorema Master, in questo caso, conferma in modo immediato ciò che l’intuizione suggerisce: ogni livello contribuisce in modo uniforme, e il numero di livelli determina la crescita complessiva

(altri 2 esempi per gli altri 2 casi nel pdf 4 a pagina 20, dopo ci sono anche altre eq. di ricorrenza risolte con i 3 metodi spiegati [[4 Risoluzione delle Equazioni di Ricorrenza.pdf]])



### **STRUTTURE DATI**
#### **HEAP** 
Per implementare una struttura dati astratta : Coda con priorità (lifo) 
- A parità di valore si considera il tempo di arrivo
- Si considera la chiave (valore più piccola)
![[Pasted image 20251020180019.png]]
le chiavi sono i valori dentro l'array, mai la posizione

Ovviamente per essere efficiente bisogna che abbia un costo basso

![[Pasted image 20251020180140.png|500]]

1) array disordinato
2) array ordinato
3) BST

**Definizione HEAP**
Struttura dati non lineare. E' un albero binario dove ogni nodo ha al più due figli. È posizionale, ha un figlio sinistro e uno destro, in base a come lo considero (min heap o max heap) posso avere i figli che siano tutti minori o uguali del padre(max heap) oppure tutti maggiori uguali del padre(min heap). È completo. Tutti i livelli sono pieni. L'ultimo livello può essere non pieno ma solo se i nodi sono allineati da sinistra verso destra![[Pasted image 20251020180427.png|400]]

Può essere rappresentato come un albero ma molte volte si sceglie di rappresentarlo come un array, quando aggiungo o rimuovo un elemento bisogna chiamare *heapfy* che risistema la struttura dati.

**HEAPFY**
Questa procedura è molto importante perché serve a ripristinare la struttura dello heap dopo una modifica

Ecco un esempio in pseudocodice
questo se lo rappresento come un albero
![[Pasted image 20251103204132.png|400]]

Questo se lo rappresento come un array
![[Pasted image 20251103203729.png|400]]

(heapsize è il numero di nodi contenuti nello heap)


**CREARE UN HEAP (come array)**
1) parto da un array vuoto e inserisco gli elementi (non può essere chiamato ancora heap perche non è ordinato nella maniera corretta)
2) Uso la procedura build-minHeap
   `for i = n/2 down to 1 do
	   `heapfy(H,i)
	   
- **`n`** → è il **numero di elementi** presenti nell’array (la dimensione dell’heap).  
    Esempio: se l’array ha 10 valori, allora `n = 10`.
    
- **`H`** → è l’**array** che contiene gli elementi da sistemare in un heap.  
    È l’array su cui lavorano `Heapify` e `BuildHeap`.
    
- **`i`** → è **l’indice del nodo** che stiamo “heapificando” in quel momento.  
    Il ciclo parte da `n/2` (cioè dall’ultimo nodo che ha almeno un figlio) e va fino a `1` (la radice).



La struttura heap ci semplifica la vita quando parliamo di velocità e complessità nei problemi di ordinamento

Ad esempio nel **selection sort** normale con array il problema maggiore è trovare ogni volta il massimo il che ci porta ad avere una complessità $O(n^2)$ 
Possiamo invece usare una struttura heap che migliora la complessità, usando comunque un array 
Ecco quindi il procedimento per creare un selection sort con un heap:
(Viene rappresentato come un albero ma nella realtà è un array)
![[Pasted image 20251105184839.png]]
1) Parto da un array disordinato (sinistra) e chiamo **build-max-heap** che mi va a creare un max-heap in qui ho i figli sempre minori uguali del padre
2) Per prendere il massimo scambio il massimo (19) che è la root con il minimo (2) che è l'ultimo nodo, quindi prendo il nuovo ultimo nodo e chiamo **heapfy** che mi va a riordinare di nuovo il max-heap![[Pasted image 20251105185206.png]]
3) Posiziono il massimo (19) alla fine dell'array e ripeto questa procedura fino a quando l'array non è ordinato (ovviamente scalo la dimensione su cui opero di 1 ogni volta che posiziono un massimo)

Da questa idea di usare un heap come struttura dati nasce l'**heap-sort**

**HEAP SORT**
`heapSort(A,n)`
	`buildMaxHeap(A,n)`
	`for i = 0 to n-1 do`
		`extractMax(A)`

`extractMax(A)`
`Swap(A,1,n-1)`
`n = n-1`
`heapfy(A,1)`

Questa procedura ha complessità $O(n\,\,log \,\,n)$ molto simile al mergeSort che è $Θ(n\,\,log\,\,n)$ e consuma anche meno memoria perché qui lavoriamo con un singolo array a differenza del mergeSort

**Definizione**
E' dimostrato che un algoritmo di ordinamento che fa confronti non potrà mai scendere sotto $Θ(n\,\,log\,\,n)$ come complessità


Ma non tutti gli algoritmi di ordinamento hanno bisogno di fare comparazioni
##### **Algoritmi di ordinamento che non necessitano di confronti**
Ne vedremo 2:

**COUNTING SORT**
Costruiamo un array A:
`A = [4,3,5,3,5,3,2,3,4]`

adesso creo un secondo array chiamato C, questo array avrà l' ultimo indice = all'elemento massimo di A + 1, quindi nel nostro caso avrà dimensione 7 (max(A) = 5 + 1 ma dato che inizio da 0 avrà dimensione 7), lo inizializzo a 0:

`C = [0,0,0,0,0,0,0]`
`     0 1 2 3 4 5 6` 
L'ultimo indice è l'indice k che ci da la dimensione
Con questo array C, conterò le occorrenze dei numeri presenti in A, nel nostro caso:
`C = [0,0,1,4,2,2,0]`
`     0 1 2 3 4 5 6` 
infatti il 2 compare una volta, il 3 quattro volte ecc...
Quindi `C[i]` = numero di occorrenze dell' elemento i in A

Adesso modifichiamo l'array C rendendolo C', in cui in `C[i]` andiamo a sommare il numero `C[i]+C[i-1]`
Quindi sommiamo l'elemento corrente con il precedente e lo posizioniamo nell'elemento corrente
In pseudocodice stiamo facendo: `for i = 0 to k do (C[i] = C[i] + C[i-1])`
Otterremo cosi l'array C modificato in C':
`C' = [0,0,1,5,7,9,9]`
`      0 1 2 3 4 5 6` 

In questo modo all'interno di C' avremo il numero di elementi in A minori o uguali ad i
infatti quanti elementi ci sono minori o uguali a 2 nell'array A? 1 (solo il 2)
quanti elementi ci sono minori o uguali a 3 nell'array A? 5 (i quattro 3 e il 2)
ecc...

Adesso creiamo un ultimo array B della stessa dimensione di A
`B =  [0,0,0,0,0,0,0,0,0]`
`      0 1 2 3 4 5 6 7 8` 

Fatto questo si scorre l'array A al contrario, quindi partendo dalla fine, questo serve a mantenere la stabilità, poi:
Per ogni elemento i (elemento corrente dentro A), si posiziona i in `B[C'[i]-1]` e successivamente si decrementa: `C'[i]` di 1, perché avendo posizionato l'elemento i ne ho 1 in meno da posizionare quindi devo scalare di 1 il numero degli elementi i: se `C'[3] = 5` ho 5 tre da posizionare, dopo aver posizionato il primo 3 `C'[3] = 4` e cosi via

Ecco lo pseudocodice del countingSort
`CountinSort(A,n){`
	`k = max(A)`
	`C = new Array(k+1)`
	`for i = 0 to k do C[i] = 0`
	`for i = 0 to n-1 do C[A[i]] = C[A[i]]+1`
	`for i = 1 to k do C[i] = C[i] + C[i-1]`
	`for i = n-1 down to 0 do`
	`B[C[A[i]]-1] = A[i]`
	`C[A[i]] = C[A[i]]-1`
`}`

La complessità del counting sort è $O(n + k)$ dove $n$ è il numero di elementi presenti in A e k è il MAX(A)


**RADIX SORT**
L'idea generale del radix sort è ordinare l'array in base alle cifre di ogni elemento, ovvero si ordina (generalmente) partendo dalla cifra meno significativa e ad ogni passata si va fino a quella più significativa

Faccio un esempio visivo:
`A = [329,457,657,839,436,720,355]`

329       720       720       329
457       355       329       355
657       436       436       436
839       457       839       457
436       657       355       657
720       329       457       720
355       839       657       839
Partendo dall'array iniziale, ho ordinato prima rispetto alla terza cifra (seconda colonna) poi rispetto alla seconda (terza colonna) e infine rispetto alla terza (quarta colonna), così facendo ho ordinato l'array

Pseudocodice
`RadixSort(A,n,h)`
	`for i = 0 to h = 1 do` 
		`countingSort(A,n,h)`

dove A è l'array, n la dimensione e h sono le cifre dei numeri all'interno (ovviamente devono avere tutti lo stesso numero di cifre) 

La formula per trovare il numero in base alla cifra che voglio (unità,decine,ecc...) è:
$$(\frac{A[i]}{10^h})\%10$$   esempio: con $10^0$ cioè la cifra delle unità
$$(\frac{345}{1})\%10$$
$$345\%10 = 5$$

La complessità del radix sort è $O(n)$



#### **TABELLE AD INDIRIZZAMENTO DIRETTO**
Queste tabelle funzionano in maniera molto simile all' array C del counting sort, ovvero un array in cui si salva il numero di occorrenze per ogni numero, all'indice che rappresenta quel numero, infatti per queste tabelle supponiamo di avere un insieme di numeri: 
S = {1,3,3,5,5,6,7}
salviamo il numero di occorrenze di questi numeri all'interno di un array T che ha dimensione pari al massimo+1 dell'insieme S
`T = [0,1,0,2,0,2,1,1]`
`     0 1 2 3 4 5 6 7`
Infatti nell'insieme S lo 0 compare zero volte l'1 una volta, il 3 due volte e cosi via
E' molto facile da capire e da implementare infatti in pseudocodice le operazioni sono:
Inserimento:
`insert(T,k)`
	`T[k] = T[k]+1`

Cancellazione:
`delete(T,k)`
	`if T[k] = 0 then T[k] = 0`
	`else T[k] = T[k] -1`

Ricerca:
`search(T,k)`
	`if(T[k] >= 1) return 1`
	`return`

dove T è l'array e k l'elemento

Questa struttura è molto semplice ma NON è efficiente se la differenza tra min e max nell'insieme è grande, infatti se avessi un insieme S = {1,2,3,300,5000} avrei 5000+1 caselle di cui la maggior parte vuota

Sarebbe ottimo avere una struttura con le caratteristiche di una tabella ad indirizzamento diretto ma che consumi il giusto numero di celle
