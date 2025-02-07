## **Capitolo V - Funzioni**
Quando passiamo un **argomento ad una funzione questo viene sempre passato per valore**, quindi se il valore dell'elemento viene cambiato dentro la funzione, il **cambiamento non si ripercuote fuori dalla funzione**, a meno che l'elemento passato non sia un **array o un puntatore** alla variabile nel main, **queste 2 cose vengono passate per riferimento** perché ne sto passando l'indirizzo e non una copia locale che vale solo per la funzione.
Quindi:
Se devo passare per valore -> `funzione(variabile);`
Se devo passare per riferimento -> `funzione(&variabile);` (dentro la funzione poi devo usare * per modificare il valore della variabile)

## **Capitolo VI - Array**
Un **array è una struttura di dati contigua** in memoria **tutte dello stesso tipo**. Un **array non è altro che un puntatore al primo elemento di se stesso**, **il tipo di un array dipende dal tipo di valore che devo mettere dentro** (int, float, char, struct ecc...)
Sugli array si possono fare degli ordinamenti in base ad un criterio specifico, i più famosi (anche se poco efficienti ma semplici) sono il **bubble sort e selection sort**

**BUBBLE SORT**
`for(int i = 0; i < dim-1; i++){`

    `for(int j = 0; j < dim-1; j++){`
        `if(a[j] > a[j+1]){`
        
            `int temp = a[j];`
            `a[j] = a[j+1];`
            `a[j+1] = temp;`
        `}`
    `}`
`}`

Ordina l'array in maniera crescente (appunti più dettagliati -> [[Tips Algoritmi#**BUBBLE SORT PER ORDINARE GLI ELEMENTI DI UN ARRAY**|Bubble Sort Array]])

**SELECTION SORT**
`for(int i = 0; i < dim-1; i++){`
    `int minimo = i;`

    `for(int j = i+1; j < dim; j++){`

        `if(a[j] < a[minimo]){`
            `minimo = j;`
        `}`
    `}`
    `int temp = a[i];`
    `a[i] = a[minimo];`
    `a[minimo] = temp;`
`}`

Ordina l'array in maniera crescente (appunti più dettagliati -> [[Tips Algoritmi#**SELECTION SORT ARRAY**|Selection Sort Array]])

---

Sugli array si possono anche **fare delle ricerche di determinati elementi**, le più famose sono: la **ricerca binaria  e ricerca tramite key**

**RICERCA BINARIA**
`int ricerca_binaria_ricorsiva(int a[],int key, int low,int high){`

    `if(low <= high){`
        `if(a[(low+high)/2] == key){`
            `return (low+high)/2;`
	        `}else if(a[(low+high)/2] < key){`
	            `return ricerca_binaria_ricorsiva(a,key,(low+high)/2 + 1,high);`
		        `}else{`
		            `return ricerca_binaria_ricorsiva(a,key,low,(low+high)/2 - 1);`
		        `}`
		    `}`
    `return -1;`
`}`
Ricerca un determinato elemento e restituisce la posizione alla funzione chiamante (Questa è una verisone ricorsiva) (appunti più dettagliati -> [[Tips Algoritmi#**RICERCA BINARIA NELL' ARRAY**|Ricerca Binaria Array]])

**RICERCA TRAMITE CHIAVE**
`int linear_search(int a[],int key, size_t n){`
    `for(int i = 0; i < n; i++){`
        `if( a[i] == key){`
            `return i;`
        `}`
    `}`
`return -1;`
`}`
Ricerca un determinato elemento e restituisce la posizione alla funzione chiamante
 (appunti più dettagliati -> [[Tips Algoritmi#**RICERCA TRAMITE CHIAVE NELL' ARRAY**|Ricerca Tramite Key Array]])
 
---

**Per passare l'array ad una funzione non serve usare un puntatore o altro basta passarlo normalmente come fosse una variabile normale, verrà in automatico passato per riferimento** (int array[10] = {0};      funzione(array,10);) solitamente si passa l'array e la sua dimensione.
**Se invece dobbiamo passare un elemento allora dobbiamo usare un puntatore, perché l'elemento viene passato per valore** (int array[10] = {0};      funzione(&array[5]);)
(possiamo vedere un array come una sorta di puntatore e il singolo elemento come una variabile normale)

---

**Possiamo anche creare array multidimensionali** che sarebbero delle matrici o più semplicemente sono array che contengono altri array al loro interno
es. `int array[3][2] = {{1,2},{3,4},{5,6}};` -> un array che contiene altri 3 array dentro con ognuno 2 elementi (array o matrice 2D), possiamo fare tutte le dimensioni che vogliamo.

## **Capitolo VII - Puntatori**
I puntatori sono variabili i cui valori sono indirizzi di memoria. Quindi il puntatore contiene l'indirizzo di una variabile che contiene un valore. Il puntatore va dichiarato così: 
`tipo *nomePuntatore` -> `int *ptr` e per assegnare un valore bisogna usare la "&" proprio perché abbiamo bisogno dell'indirizzo della variabile a cui farlo puntare (si dice che un puntatore "punta" alla variabile che gli è stata assegnata)

**L' " * " si dice operatore di dereferenziazione** e restituisce il valore che sta venendo puntato da un puntatore
`printf("%d", *yPtr);` -> stamperà il valore della variabile a cui punta (es. 5)

---

Esiste l'**aritmetica dei puntatori,** **ovvero posso effettuare delle operazioni su di loro**, infatti **posso aggiungere un unità e farli spostare nella memoria puntata** (es. se il puntatore punta alla locazione AAA0000FFF e aggiungo 4 byte adesso il puntatore punterà a: AAA0004FFF, quindi mi sono spostato di 4 byte nella memoria che sta puntando).
**Utile ad esempio con un array**, infatti un array è un puntatore che punta al primo elemento dell'array, quindi se aggiungo dei byte (4 nel caso degli interi perché ogni int occupa 4 byte in memoria) mi posso spostare al prossimo elemento (posso anche sottrarli)

es. `aptr = aptr +1;` cosi incremento di 4 byte (4 per int, 8 per double ecc...)

---

**Con i puntatori posso passare per riferimento delle variabili ad una funzione passandone l'indirizzo** e lavorando (dentro la funzione) con un puntatore che punta all'indirizzo della variabile passata
Quindi : Quando l’indirizzo di una variabile viene passato a una funzione (&), si può usare nella funzione l’operatore di indirezione ( * ) per modificare il valore in quella locazione nella memoria della funzione chiamante.


## **Capitolo VII,5** **- Allocazione Dinamica **
