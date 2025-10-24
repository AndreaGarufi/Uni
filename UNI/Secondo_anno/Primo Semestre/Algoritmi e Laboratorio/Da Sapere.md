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
4) $F(n) = n\,\,\,log\,\,\,n$ funzione **linearitmica** cresce un po di più della funzione lineare

- funzioni polinomiali
5) $F(n^2)$ funzione **quadratica**
6) $F(n^3)$ funzione **cubica** e cosi via...

- funzione esponenziale
 7) $F(n)= k^n$ 

- Funzione fattoriale
8) $F(n)= n!$
![[Pasted image 20251011121033.png]]


### **Come capire la classe di una funzione**
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

### **A partire dalla procedura posso capire la classe?**
(si) da capire e fare


### **Risoluzione equazioni di ricorrenza**
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

#### TEOREMA MASTER










### **Strutture dati**
**HEAP** 
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
Struttura dati non lineare. E' un albero binario dove ogni nodo ha al più due figli. È posizionale, ha un figlio sinistro e uno destro, a sinistra è più piccolo della clave a destra più grade. È completo. Tutti i livelli sono pieni. L'ultimo livello può essere non pieno ma solo se i nodi sono allineati da sinistra verso destra![[Pasted image 20251020180427.png|400]]
![[Pasted image 20251020180450.png]]

