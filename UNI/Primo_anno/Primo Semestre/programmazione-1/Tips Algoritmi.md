### **SCAMBIO DI NUMERI**
Per scambiare 2 numeri ho bisogno di una terza variabile temporanea:
![[Pasted image 20241011134142.png|300]]



Stampa le prime n+1 potenze del numero 2



# **ORDINAMENTI SU ARRAY**
### **BUBBLE SORT PER ORDINARE GLI ELEMENTI DI UN ARRAY**

LIBRO PAG 243-244

La Figura 6.15 ordina i valori negli elementi di un array a di 10 elementi (riga 10) in ordine crescente. La tecnica che usiamo è chiamata bubble sort (letteralmente “ordinamento a bolle”) o sinking sort (letteralmente “ordinamento per affondamento”), perché i valori più piccoli sal- gono verso la cima dell’array a poco a poco “come bolle”, come le bolle d’aria che si formano nell’acqua, mentre i valori più grandi scendono verso il fondo dell’array. La tecnica consiste nell’effettuare diverse passate lungo l’array. A ogni passata vengono confrontate le successive coppie di elementi (l’elemento 0 e l’elemento 1, poi l’elemento 1 e l’elemento 2, ecc.). Se una coppia è in ordine crescente (o se i valori sono identici), si lasciano i valori come sono. Se una coppia è in ordine decrescente, i valori vengono scambiati nell’array.

1 // Fig. 6.15: fig06_15.c 
2 // Ordinare i valori di un array in ordine crescente. 
3 #include <stdio.h> 
4 #define SIZE 10 
5 
6 // la funzione main inizia l'esecuzione del programma 
7 int main(void) 
8 { 
9 int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};       // inizializza a 10
11 
12 puts("Data items in original order"); 
13  
14 // stampa l'array originario 
15 for (size_t i = 0; i < SIZE; ++i) { 
16 printf("%4d", a[i]); 
17 } 
18 
19 // bubble sort 
20 // ciclo per il numero di passate 
21 for (unsigned int pass = 1; pass < SIZE; ++pass) { 
22 
23 // ciclo per il numero di confronti a ogni passata 
24 for (size_t i = 0; i < SIZE – 1; ++i) { 
25 
26 // confronta due elementi adiacenti e scambiali se il primo 
27 // elemento e' maggiore del secondo elemento 
28 if (a[i] > a[i + 1]) { 
29 int hold = a[i]; 
30 a[i] = a[i + 1]; 
31 a[i + 1] = hold; 
32 } 
33 } 
34 } 
35 
36 puts("\nData items in ascending order"); 
37 
38 // stampa l'array ordinato 
39 for (size_t i = 0; i < SIZE; ++i) { 
40 printf("%4d", a[i]); 
41 } 
42 
43 puts(""); 
44 }


##### **CODICE PER COPIA INCOLLA**
// Fig. 6.15: fig06_15.c

// Ordinare i valori di un array in ordine crescente.

#include <stdio.h>

#define SIZE 10

  

// la funzione main inizia l'esecuzione del programma

int main(void) {

    // inizializza a 10

    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};

  

    puts("Data items in original order");

  

    // stampa l'array originario

    for (size_t i = 0; i < SIZE; ++i) {

        printf("%4d", a[i]);

    }

  

    // bubble sort

    // ciclo per il numero di passate

    for (unsigned int pass = 1; pass < SIZE; ++pass) {

  

        // ciclo per il numero di confronti a ogni passata

        for (size_t i = 0; i < SIZE - 1; ++i) {


            // confronta due elementi adiacenti e scambiali se il primo

            // elemento e' maggiore del secondo elemento

            if (a[i] > a[i + 1]) {

                int hold = a[i];

                a[i] = a[i + 1];

                a[i + 1] = hold;

            }

        }

    }

  

    puts("\nData items in ascending order");

  

    // stampa l'array ordinato

    for (size_t i = 0; i < SIZE; ++i) {

        printf("%4d", a[i]);

    }

  

    puts("");

}

(STAMPA DELL'ESERCIZIO)
![[Pasted image 20241105114445.png]]
Figura 6.15 Ordinare i valori di un array in ordine crescente. Dapprima il programma confronta a[0] e a[1], poi a[1] e a[2], quindi a[2] e a[3], e così via, finché completa la passata confrontando a[8] e a[9]. Benché vi siano 10 elementi, sono eseguiti solo nove confronti. Per via del modo in cui sono fatti i successivi confronti, un valore grande si può muovere in giù lungo l’array di molte posizioni in una singola passata, ma un valore piccolo si può muovere in su solo di una posizione. Alla prima passata è garantito che il valore più grande scenda giù fino all’elemento che sta al fondo dell’array, a[9]. Alla seconda passata è garantito che il secondo valore più grande scenda giù fino ad a[8]. Alla nona passata il nono valore più grande scende fino ad a[1]. Questo lascia il valore più piccolo in a[0], così, pur essendovi dieci elementi, sono necessari solo nove passate per ordinare l’array.

L’ordinamento è eseguito dai cicli annidati for (righe 21–34). Se è necessario uno scambio, questo è eseguito con le tre assegnazioni
![[Pasted image 20241105114703.png]]
dove la variabile extra hold memorizza temporaneamente uno dei due valori da scambiare. Lo scambio non può essere eseguito con le sole due assegnazioni
![[Pasted image 20241105114731.png]]
Se, ad esempio, a[i] è 7 e a[i + 1] è 5, dopo la prima assegnazione entrambi i valori saranno 5 e il valore 7 sarà perduto. Da qui la necessità di una variabile extra hold. Il principale pregio del bubble sort consiste nella facilità di programmarlo. Tuttavia, esso opera lentamente, poiché ogni scambio sposta un elemento solo di una posizione verso la sua destina- zione finale. Questo risulta evidente quando si ordinano array grandi. Negli esercizi esamineremo versioni più efficienti del bubble sort. Sono state sviluppate tecniche di ordinamento di gran lunga più efficienti del bubble sort. Analizzeremo altri algoritmi nell’Appendice D. I corsi più avanzati di informatica analizzano più approfonditamente l’ordinamento e la ricerca di elementi in array.

### **SELECTION SORT ARRAY**
![[Pasted image 20250110102918.png]]

parte con i = 0 è quello è il "minimo provvisorio" poi continua con una j che parte dal successivo dopo i (j = i +1) confronta il minimo provvisorio con la j (che sarebbe il numero successivo) se j è più piccolo il nuovo minimo diventa il numero in posizione j. Fa questa cosa "dim" volte e cosi ha trovato il primo vero minimo, poi scambia la posizione i con il vero minimo, fa questo processo "dim-1" volte cosi da trovare ogni volta tutti i nuovi minimi e scambiarli.

1) ciclo:
   i = 0 -> minimo provvisorio = 0 -> (j = i +1), j = 1 -> se array[j] < array[minimo (questo è il minimo provvisorio)] il minimo vero diventa la posizione j -> continua "dim" volte -> finisce il ciclo for interno e scambia il valore in posizione i (0) con il valore minimo trovato nel ciclo interno -> ricomincia il ciclo esterno con i = 1 poi 2 ,3 ... dim-1 (dim-1) perché corrisponderà al massimo (quindi il ciclo interno con la j si ripete "dim-1" volte)



# **RICERCHE SU ARRAY**
### **RICERCA TRAMITE CHIAVE NELL' ARRAY**
LIBRO PAG 250...

1 #include <stdio.h>
2 int linear_search(int a[],int key, size_t n);
3
4 int main(){
5
6 int array[10] = {1,2,3,4,5,6,7,8,9,10};
7 int chiave = 0;
8
9 printf("Inserisci il numero da cercare nel vettore: \n");
10 scanf("%d",&chiave);
11
12 int index = linear_search(array, chiave, 10);
13
14 if(index != -1){
15
16   printf("il numero e' stato trovato nell'indice %d",index);
17
18 }else{
19   printf("il numero non e' stato trovato");
20 }
21}
22
23 //funzione per la ricerca lineare
24 int linear_search(int a[],int key, size_t n){
25 
26  for(int i = 0; i < n; i++){ 
27       if( a[i] == key){
28          return i;
29      }
30  }
31 return -1;
32 }

##### **CODICE PER COPIA INCOLLA**
#include <stdio.h>

int linear_search(int a[],int key, size_t n);

int main(){

int array[10] = {1,2,3,4,5,6,7,8,9,10};

int chiave = 0;

printf("Inserisci il numero da cercare nel vettore: \n");

scanf("%d",&chiave);

int index = linear_search(array, chiave, 10);

if(index != -1){

    printf("il numero e' stato trovato nell'indice %d",index);

}else{

    printf("il numero non e' stato trovato");

}

}

//funzione per la ricerca lineare

int linear_search(int a[],int key, size_t n){
 

    for(int i = 0; i < n; i++){

        if( a[i] == key){

            return i;

        }

    }

return -1;
}
##### **RICERCA CON CHIAVE RICORSIVA (COPIA E INCOLLA)**
int linear_search_ricorsiva(int a[], int key, int low, int high){

    if(low <= high){

        if(a[low] == key){
            return low;
        }

        return linear_search_ricorsiva(a,key,low+1,high);  //si richiama 
													//aumentando low di 1 cosi
				                                                              //si scorre l'array 1 alla volta
    }

    return -1;      //elemento non trovato

}

### **RICERCA BINARIA NELL' ARRAY**
![[Pasted image 20241106204157.png|1000]]

#### **CODICE PER COPIA INCOLLA**
#include <stdio.h>

  

int binary_search(const int a[], int chiave, int low, int high); //prototipo di funzione

  

int main(){

  

int vettore[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};          //vettore

  

int key = 0;

  

printf("Inserisci il numero da cercare: \n");

scanf("%d",&key);

  

int risultato = binary_search(vettore , key , 0 , 10-1);        //salva il risultato il valore che ritorna da questa chiamata di funzione

  

if(risultato != -1){

  

    printf("il valore %d e' stato trovato nella posizione : %d",key,risultato);

  

}else{

    printf("valore non trovato");

}

  

}

  

int binary_search(const int a[], int chiave, int low, int high){            //funzione

  

    while(low <= high){

  

        int centro = (low + high) / 2;

        if(a[centro] == chiave){

            return centro;

        }else if(a[centro] > chiave){

            high = centro - 1;

        }else{

            low = centro + 1;}

        }

        return -1;

    }



##### **RICERCA BINARIO RICORSIVA (COPIA INCOLLA)**
int ricerca_binaria_ricorsiva(int a[],int key, int low,int high){

    if(low <= high){


        if(a[(low+high)/2] == key){

            return (low+high)/2;

        }else if(a[(low+high)/2] < key){

            return ricerca_binaria_ricorsiva(a,key,(low+high)/2 + 1,high);

        }else{


            return ricerca_binaria_ricorsiva(a,key,low,(low+high)/2 - 1);

        }

    }

    return -1;
}

La ricerca binaria si basa sul **divide et impera**: invece di controllare tutti gli elementi di un array uno per uno (come nella ricerca lineare), il metodo divide ripetutamente l'array a metà fino a trovare l'elemento cercato.
### **Idea principale:**
1. L'array deve essere **ordinato**.
2. Si confronta l'elemento cercato con l'elemento centrale.
    - Se è uguale, lo si ha trovato.
    - Se è minore, si cerca nella metà sinistra.
    - Se è maggiore, si cerca nella metà destra.
3. Il processo si ripete fino a trovare l'elemento o fino a ridurre la ricerca a un intervallo vuoto.

# **ALTRI ALGORITMI**
### **INVERTIRE I NUMERI USANDO ARRAY**
![[Pasted image 20241105120250.png]]
in pratica scorro l'array al contrario e lo stampo
#### **CODICE PER COPIA INCOLLA**
#include <stdio.h>

#define SIZE 4

int main() {

    int array[SIZE] = {7, 6, 5, 4};

    for (int i = SIZE - 1; i >= 0; i--) {

        printf("%d ", array[i]);

    }

}

### **PALINDROMO**
![[Pasted image 20241107193836.png]]

##### **CODICE PER COPIA E INCOLLA**
int palindromo(char a[], int n){

    int low = 0;

    int high = n - 1;

    while(low <= high){

        if(a[low] != a[high]){

            return 0;

        }

        low++;

        high--;

    }

    return 1;  

}


## **MATRICE 3D**
Automatica
`int matriceAutomatica[3][3][3] = {{{1,2,3},{1,2,3},{1,2,3}},{{1,2,3},{1,2,3},{1,2,3}},{{1,2,3},{1,2,3},{1,2,3}}};`

Dinamica
![[Pasted image 20250110220716.png]]

Successivamente la gestisco similmente a come se fosse una matrice 2D solo che aggiungo un ciclo for in più per la profondità
Ha 3 *** perché è un puntatore a puntatori a puntatori (l'array è un puntatore), quindi primo * perché è un array che punta agli altri array dentro di lui (corrisponde a questo -> { { {1,2,3},{1,2,3},{1,2,3} },{ {1,2,3},{1,2,3},{1,2,3} },{ {1,2,3},{1,2,3},{1,2,3} } } ossia le graffe più esterne) il secondo * perché punta agli array interni (le seconde graffe) e l'ultimo * per i singoli elementi

# **ALGORITMI E TIPS LISTE**

## **COME CREARE UNA LISTA**

![[Pasted image 20250109095035.png]]

    for(int i = 0; i < dim; i++){       //(usando 2 puntatori)

        if(i == 0){

            testaPtr = malloc(sizeof(listaEta));          //creazione primo nodo

        }else if(i == 1){

            newPtr = testaPtr->nextPtr = malloc(sizeof(listaEta)); //creazione                                                                   secondo nodo
        }else{
            newPtr = newPtr->nextPtr = malloc(sizeof(listaEta));    //creazione                                                                   altri nodi
        }

    }
    
## **COME STAMPARE UNA LISTA**
![[Pasted image 20250109095114.png]]
    
    newPtr = testaPtr;

    i = 0;

    while(newPtr != NULL){

        i++;

        printf("NUMERO NODO %d -> %d\n",i,newPtr->numero);

        newPtr = newPtr->nextPtr;

    }

## **COME FARE LA FREE AD UNA LISTA**
![[Pasted image 20250110105024.png]]
    
    listaOrdine *tempPtr = NULL;

    newPtr = testaPtr;

    while (newPtr != NULL) {

        tempPtr = newPtr->nextPtr;  // Salva il nodo successivo

        free(newPtr);              // Libera il nodo corrente

        newPtr = tempPtr;          // Passa al nodo successivo

    }

    testaPtr = NULL;  // Buona pratica: resettare la testa

## **BUBBLE SORT LISTA (sposta gli elementi non i nodi)**
![[Pasted image 20250109095210.png]]

// Accetta come parametro il puntatore al primo elemento

// della lista; la ordina utilizzando l'algoritmo "bubble

// sort" e restituisce il puntatore al primo elemento

// della lista.


struct nodo * bubble_sort(struct nodo *primo) {

	struct nodo *p, *ultimo;

	int flag, appo;

	ultimo = NULL;

	flag = 1;

	while (flag == 1) {

	p = primo;
	
	flag = 0;
	
	while (p->next != ultimo) {
	
		if (p->info > (p->next)->info) {
		
		appo = p->info;
		
		p->info = (p->next)->info;
		
		(p->next)->info = appo;
		
		flag = 1;
	
	}
	
	p = p->next;
	
	}
	
	ultimo = p;

}

	return(primo);

}


## **SELECTION SORT LISTA (sposta gli elementi non i nodi)**
![[Pasted image 20250110111042.png]]

Il concetto rimane uguale rispetto a quello fatto con gli array, solo che ci sono i while e i puntatori al posto dei for e a[] 

## **TESTA DELLA LISTA PER RIFERIMENTO (E ALTRO)**
Se devo agire sul nodo testa della lista (come ad esempio se devo cancellare la testa o aggiungere un nodo in testa) devo passare la testa per riferimento, ovvero nella funzione 
-> `lista *aggiuntaInTesta(lista **testaPtr);`
(poi nel main devo passare l'indirizzo -> `aggiuntaInTesta(&testaPtr));` )

Mentre se devo agire sul resto della lista (aggiungendo nodi, cancellando nel mezzo, cancellando in coda ecc...) posso anche passare la testaPtr per valore
N.B. se devi fare una cancellazione in coda è meglio passare lo stesso la testa per riferimento perché se la lista è formata da un solo nodo la testa corrisponderà alla coda e quindi dovrà essere cancellata

### **Inserimento in testa**
![[Pasted image 20250115112105.png]]
Per inserire in testa ho bisogno di un puntatore di appoggio `*newTestaPtr` , creo il nuovo nodo da mettere in testa, e lo collego con la testa tramite `newTestaPtr->nextPtr = *headPtr;`
cosi nextPtr della nuova testa punta alla vecchi testa (headPtr) poi non mi resta che scambiare i puntatori con `*headPtr = newTestaPtr;` in questo modo sposto headPtr dalla vecchia testa alla nuova
In questo caso dato **che agisco sulla testa ho bisogno di passarla per riferimento** altrimenti viene cambiata solo nella funzione e non nel resto del programma 

### **Inserimento in mezzo**
![[Pasted image 20250117170344.png]]
Per inserire in mezzo mi basta allocare il nuovo nodo inserire dentro i dati e collegarlo al nextPtr del nodo precedente.
Per avere il nodo precedente faccio un while e attraverso un currentPtr mi segno il corrente, con lastPtr mi segno il precedente e poi inserisco il nuovo nodo in mezzo

### **Cancellazione in testa**
![[Pasted image 20250115114254.png]]
Qui gestisco anche se la lista è vuota (primo if) o se la lista ha solo la testa (secondo if).
Mi basta usare un nuovo puntatore di appoggio per la nuova testa (che sarà il secondo nodo) e tramite `newTesta = (*headPtr)->nextPtr;` lo faccio.
Dopo elimino la testa con `free(*headPtr);`, infine assegno faccio puntare headPtr alla nuova testa (secondo nodo).
In questo caso dato **che agisco sulla testa ho bisogno di passarla per riferimento** altrimenti viene cambiata solo nella funzione e non nel resto del programma
### **Cancellazione in mezzo**
![[Pasted image 20250115184107.png]]
**Qui devo gestire anche il caso in cui ho un solo nodo e quindi devo cancellare la testa**.
Decido quale nodo cancellare e in base a quello scorro tutti i nodi finché non arrivo a quello che mi interessa, dopo di che devo collegare il nodo precedente a quello da eliminare con quello successivo tramite -> `lastPtr->newPtr = newPtr->nextPtr` 
Ovviamente quando scorro la lista ho sempre bisogno di tenere un collegamento al precedente (`lastPtr = newPtr`) e scorrere avanti (`newPtr = newPtr->nextPtr`)cosi se al prossimo ciclo trovo il nodo da cancellare ho già il collegamento al precedente.
la condizione "if" mi serve per capire quale sia il nodo da cancellare, può essere fatta anche con elementi del nodo (es. devo cancellare il nodo in cui l'età è 18: 
`if (newPtr->eta == 18){`
`break;`
`}`)
con break esco dal while e nel ciclo precedente avevo salvato il nodo precedente a questo da cancellare, quindi devo solo collegarlo al successivo ed eliminare il corrente con `free(newPtr)`
dopo di ché ritorno la testa della lista
In questo caso dato **che è possibile agire sulla testa ho bisogno di passarla per riferimento** altrimenti viene cambiata solo nella funzione e non nel resto del programma

### **Cancellazione in coda**
![[Pasted image 20250115184202.png]]
Per cancellare in coda ho bisogno di gestire il caso in cui la lista sia vuota (primo if) o ci sia solo la testa (secondo if), dopo di ciò ho bisogno di un puntatore al precedente perché quando verrà eliminato il nodo in coda bisogna porre a NULL nextPtr del nodo precedente alla coda.
Opero con un while che scorre tutta la lista e un if:
`if(newPtr->nextPtr == NULL)` vuol dire che mi trovo nell'ultimo nodo (che devo cancellare), quindi pongo `lastPtr->nextPtr == NULL` (essendo la nuova coda va posto a NULL il suo nextPtr) e poi con la `free(newPtr)` elimino il nodo.
Fuori dall'if (come fatto per la cancellazione in mezzo) nel ciclo precedente a quello in cui l'if sarà vero avrò salvato in lastPtr il nodo precedente alla coda (dopo mi muovo di un nodo nella lista e ricomincia il while)
In questo caso dato **che è possibile agire sulla testa ho bisogno di passarla per riferimento** altrimenti viene cambiata solo nella funzione e non nel resto del programma
## **INSERIMENTO ORDINATO NELLA LISTA**
![[Pasted image 20250117100855.png]]
L'inserimento ordinato ordina in base ad un criterio o valore scelto (in questo caso è numero1), qui è stato ordinato in maniera crescente, ovvero il numero che inserisce l'utente deve essere messo prima dei numeri più grandi di lui.
Mi serve un currentPtr che scorra la lista partendo dalla testa e mi serve tenere a mente un precedente di currentPtr: finché currentPtr != NULL e finché il numero di currentPtr è più piccolo del numero inserito dall'utente, cicla. Quando questa condizione non è verificata esce
dal while avendo però salvato un riferimento al nodo precedente nell'ultimo ciclo. Abbiamo perciò trovato dove posizionare il nuovo nodo, dopo devo fare un `if(lastPtr == NULL)` perché se entrerò in questo if vorrà dire che o la lista è vuota o la testa è più grande del numero da inserire e quindi bisognerà inserire il numero dell'utente in testa (richiamando la funzione "inTesta"), altrimenti (else) creo il nuovo nodo, inserisco il numero dell'utente nel nodo e poi il nextPtr del nuovo nodo è uguale a nextPtr di lastPtr (il precedente di prima, `newNodePtr->nextPtr = lastPtr->nextPtr;`) mentre dopo lastPtr->nextPtr sarà uguale al nuovo nodo (ho a tutti gli effetti fatto un inserimento in mezzo). 
4) 3->5->7    <-lista     numero1 = 4 (inserito dall'utente, questo è il criterio di ordinamento)
5) (dopo il while) lastPtr = 3, currentPtr = 5  (devo inserire 4 in mezzo)
6) 3->4->5->7 (faccio questo attraverso le istruzioni nell'else)





