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


**Come capire la classe di una funzione**
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

**A partire dalla procedura posso capire la classe?**
(si) da capire e fare




**Strutture dati**
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

