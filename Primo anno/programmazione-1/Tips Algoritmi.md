## **SCAMBIO DI NUMERI**
Per scambiare 2 numeri ho bisogno di una terza variabile temporanea:
![[Pasted image 20241011134142.png|300]]



Stampa le prime n+1 potenze del numero 2



## **BUBBLE SORT PER ORDINARE GLI ELEMENTI DI UN ARRAY**

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

## **RICERCA TRAMITE CHIAVE NELL' ARRAY**
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

## **RICERCA BINARIA NELL' ARRAY**
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


## **INVERTIRE I NUMERI USANDO ARRAY**
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

## **PALINDROMO**
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