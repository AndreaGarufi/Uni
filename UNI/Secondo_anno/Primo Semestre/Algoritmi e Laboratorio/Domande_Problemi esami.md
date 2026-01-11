**Domande frequenti esame**
*Cosa è un problema di ottimizzazione?*
Un problema si dice di ottimizzazione quando esistono varie soluzioni ma solo alcune di queste sono le migliori, per capire qual è la migliore ad ogni soluzione applichiamo la funzione bontà che è definita cosi: $f: S \rightarrow R$ , dove $S$ è l'insieme delle soluzioni e $R$ i numeri reali

Ad esempio nel problema dei cammini minimi nei grafi se parto da un nodo A potrei poter scegliere 2 percorsi diversi per arrivare a C: A-B-C o A-D-B-C, normalmente il primo cammino è la soluzione migliore, ma non è sempre così, il grado di bontà assegnato ad ogni soluzione è diverso in base al problema che si affronta

*Cosa è un ordinamento topologico di un grafo?*
- Un ordinamento topologico di un grafo è un ordinamento lineare dei nodi in modo che ci sia una determinata relazione, se $∃ (u,a) ∈ E$ tale che $u<v$ . Ad esempio:
  A-F-D-G-C-E-B, questo potrebbe essere un esempio di ordinamento topologico di un grafo
- In un grafo possono esserci più ordinamenti topologici.
- Se il grafo ha un ciclo non posso fare ordinamenti topologici



**Problemi esami con heap**

### 6 Settembre 2024

`A = [1,3,4,7,8,11,12,13,14,15,18,22,24,25]`
`lun(A) = 13`
Questa è la configurazione iniziale di un min-heap

Consegna:
effettuare 13 estrazioni del minimo e mostrare cosa succede al nostro array

Albero iniziale:
![[Pasted image 20251109112457.png|250]]

![[Pasted image 20251109112654.png|500]]
![[Pasted image 20251109112739.png|502]]
![[Pasted image 20251109113944.png|503]]
				((11)questo 22 è un 25 e (12)questo è un 25)

partendo dal min-heap iniziale devo fare 13 estrazioni del minimo che avvengono così:
- Per ogni minimo da estrarre:
  1) scambio la root che è il minimo con l'ultimo nodo foglia che sarà il massimo (l'ultimo numero nell' array) 
  2) Ho estratto il minimo
  3) Chiamo heapfy che riordina l'heap trovando il nuovo minimo e facendo scendere il massimo (che era ancora al posto della root) fino in fondo
  4) Ricomincio e rieseguo per tutte le estrazioni che devo fare

(nel caso dell'array non è che il minimo lo estraggo e lo tolgo dall'array semplicemente viene messo in fondo e nei passi successivi riduco di 1 la dimensione dell'array)


### 14 Maggio 2025

Consegna:
Scrivere la procedura updateKey(H,i,k)

`updateKey(H,i,k)`
	`if i > heapsize return`
	`if k > H[i] then increaseKey(H,i,k)`
	`else`
		`H[i] = k`
		`heapfy(H,i)`

All'esame vanno scritte anche le funzioni heapfy e increaseKey, in generale se faccio uso di altre funzioni le devo scrivere

### 17 Febbraio 2025
Scrivere una procedura UpdateKey(H, i, k) che aggiorni, in un Heap Binario Massimo, la chiave in posizione i con il nuovo valore k, e ripristini le proprietà dell’heap massimo. L’algoritmo deve gestire correttamente entrambi i casi in cui $k > H[i]$ e $k < H[i]$

`updateKey(H,i,k)`
	`if i > heapsize return`
	`if k > H[i] then increaseKey(H,i,k)`
	`else if k < H[i] then 
		`H[i] = k`
		`max-heapfy(H,i)`

`INCREASE-KEY(H,i,k)`
    `H[i] = k`
    `while (i > 1 and H[parent(i)] < H[i]) do`
        `swap(H,i,parent(i))`
        `i = parent(i)`

quando ho un max heap in questo caso per gestire entrambi i casi devo chiamare increaseKey quando $k > H[i]$ e quando invece è minore chiamo max-heapfy, con il min heap funziona al contrario devo chiamare decreaseKey

### 16 Giugno 2025

Consegna:
scrivere la procedura heapMerge(H1,H2,n) (n è il numero di chiavi)
La procedura deve avere complessità $O(n)$

`Heap-merge(H1,H2,n)`
     `H = newArray(2n)`
     `for i = 0 to n do`
         `H[i] = H1[i]`
         `H[i+n] = H2[i]`
    `buildMax-heap(H,2n)`


### 1 Settembre 2025
Si fornisca un funzione ricorsiva, IsHeap(A, i), che preso in input un Max-Heap A (rappresentato come un array) e un indice i > 0, verifica se il sotto albero radicato in nel nodo i di A sia effettivamente un Heap, ovvero rispetti la proprietà dell’ordinamento parziale. La procedura restituisce True/False.

`IsHeap(A, i)`
    `// Calcolo indici dei figli`
    `l = 2*i + 1`
    `r = 2*i + 2`
    `// CASO BASE IMPLICITO:`
    `// Se i nodi l o r escono dall'array, quel ramo è valido (è NULL).`
    `// I controlli "if l < heapSize" e "if r < heapSize" gestiscono le foglie.`
    `// 1. CONTROLLO SOTTOALBERO SINISTRO`
    `if l < heapSize then`
        `// Violazione locale: il figlio è maggiore del padre`
        `if A[l] > A[i] then return False`
        `// Violazione ricorsiva nel sottoalbero sinistro`
        `if IsHeap(A, l) == False then return False`
    `// 2. CONTROLLO SOTTOALBERO DESTRO`
    `if r < heapSize then`
        `// Violazione locale: il figlio è maggiore del padre`
        `if A[r] > A[i] then return False`    
        `// Violazione ricorsiva nel sottoalbero destro`
        `if IsHeap(A, r) == False then return False`
    `// Se non ho trovato violazioni, è un Heap valido`
    `return True`

versione senza commenti:
`IsHeap(A, i)`
    `l = 2*i + 1`
    `r = 2*i + 2`
    `if l < heapSize`
        `if A[l] > A[i] or IsHeap(A, l) == False`
            `return False`
    `if r < heapSize`
        `if A[r] > A[i] or IsHeap(A, r) == False`
            `return False`
    `return True`

