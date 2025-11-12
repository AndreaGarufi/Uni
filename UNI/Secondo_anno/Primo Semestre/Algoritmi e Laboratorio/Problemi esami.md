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


### 16 Giugno 2025

Consegna:
scrivere la procedura heapMerge(H1,H2,n) (n è il numero di chiavi)
La procedura deve avere complessità $O(n)$

pag 6 note numero 6