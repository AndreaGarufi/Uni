/*Scrivere un programma in C che:

Permetta di scegliere tra array e lista.
Permetta di scegliere tra bubble sort, insertion sort o selection sort.
Ordini i dati e li stampi*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSortArray();
void selectionSortArray();
void insertionSortArray();
void bubbleSortList();
void selectionSortList();
void insertionSortList();
void bubbleSortNode();
void selectionSortNode();
void insertionSortNode();

struct listaOrdine{
    int numero;
    struct listaOrdine *nextPtr;
};
typedef struct listaOrdine listaOrdine;

int main(){
    srand(time(NULL));

    printf("Cosa vuoi fare? \n(1) Bubble sort (2) Selection sort e (3) Insertion sort su array\n(4) Bubble sort (5) Selection sort e (6) Insertion sort su liste (scambiando solo i valori all'interno)\n(7) Bubble sort (8) Selection sort e (9) Insertion sort su liste (scambianod i nodi)\n");

    int operazione = 0;
    do{
        puts("\nInserisci il numero\n");
        scanf("%d",&operazione);
        switch(operazione){

            case 1: bubbleSortArray();
            break;
            case 2: selectionSortArray();
            break;
            case 3: insertionSortArray();
            break;
            case 4: bubbleSortList();
            break;
            case 5: selectionSortList();
            break;
            case 6: insertionSortList();
            break;
            case 7: bubbleSortNode();
            break;
            case 8: selectionSortNode();
            break;
            case 9: insertionSortNode();
            break;
            default: if(operazione != 1 && operazione != 2 && operazione != 3 && operazione != 4 && operazione != 5 && operazione != 6 && operazione != 7 && operazione != 8 && operazione != 9 && operazione != -1){
                printf("Inserisci un numero giusto");
                break;
            }
        }
    }while(operazione != -1);


}
void bubbleSortArray(){
    printf("BUBBLE SORT ARRAY");
    puts("");

    int *array = NULL;  //array che non ha una dimensione perche gli verrà data con malloc
    int dim = 0;

    printf("Inserisci la dimensione dell'array di interi\n");

    scanf("%d",&dim);

    array = (int*) malloc(sizeof(int)*dim);

    printf("\nAssegnazione Numeri...\n");

    for(int i = 0; i < dim; i++){
        array[i] = 1 + rand() % 21;
    }

    printf("\nStampa Array non ordinato -> ");
    for(int i = 0; i < dim; i++){
        printf("%d ",array[i]);
    }
    puts("");

    printf("\nBUBBLE SORT\n");

    for(int i = 0; i < dim; i++){

        for(int j = 0; j < dim-1; j++){

            if(array[j] > array[j + 1]){
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;

            }
        }
    }

    printf("\nStampa Array ordinato -> \n");
    for(int i = 0; i < dim; i++){
        printf("%d ",array[i]);
    }
    puts(""); 
    free(array);   

}//end of function

void selectionSortArray(){
    printf("SELECTION SORT ARRAY");
    puts("");

    int *array = NULL;
    int dim = 0;

    printf("Inserisci la dimensione dell'array di interi\n");

    scanf("%d",&dim); 

    array = (int*) malloc(sizeof(int)*dim);

    printf("\nAssegnazione Numeri...\n");

    for(int i = 0; i < dim; i++){
        array[i] = 1 + rand() % 21;
    }

    printf("\nStampa Array non ordinato -> ");

    for(int i = 0; i < dim; i++){
        printf("%d ",array[i]);
    }
    puts("");

    printf("\nSELECTION SORT\n");

    for(int i = 0; i < dim-1; i++){
        int minimo = i;                     //il mimino provisorio è la posizione corrente
        for(int j = i + 1; j < dim; j++){   //j parte da quello dopo il minimo
            if(array[j] < array[minimo]){   //se j è più piccolo del minimo, il nuovo minimo diventa j
                minimo = j;
            }
        }
        int temp = array[i];
        array[i] = array[minimo];        //a[minimo] è il minimo e lo metto dentro a[i] (che sarà la posizione giusta del minimo) e a[i] dentro a[minimo]
        array[minimo] = temp;
    }

    printf("\nStampa array ordinato -> ");
    for(int i = 0; i < dim; i++){
        printf("%d ",array[i]);
    }
    free(array);
    
}//end of function

void insertionSortArray(){
    printf("INSERTION SORT ARRAY");
    puts("");
}

void bubbleSortList(){
    printf("BUBBLE SORT LIST");
    puts("");

    listaOrdine *testaPtr = NULL;
    listaOrdine *newPtr = NULL;
    int dim = 0;

    printf("Inserisci la dimesione della lista\n");
    scanf("%d",&dim);

    for(int i = 0; i < dim; i++){                                       //creazione nodi della lista

        if(i == 0){
            testaPtr = malloc(sizeof(listaOrdine));
        }else if(i == 1){
            newPtr = testaPtr->nextPtr = malloc(sizeof(listaOrdine));
        }else{
            newPtr = newPtr->nextPtr = malloc(sizeof(listaOrdine));
        }
    }
    printf("\nStampa lista non ordinata -> ");
    newPtr = testaPtr;
    while(newPtr != NULL){
        newPtr->numero = 1 + rand() % 21;
        printf("%d ",newPtr->numero);
        newPtr = newPtr->nextPtr;
    }

    printf("\nBUBBLE SORT\n");

    int flag = 1;
    listaOrdine *ultimoPtr = NULL;

    while(flag == 1){
        newPtr = testaPtr;
        flag = 0;
        while(newPtr->nextPtr != ultimoPtr){
            if(newPtr->numero > (newPtr->nextPtr)->numero){
                int temp = newPtr->numero;
                newPtr->numero = (newPtr->nextPtr)->numero;
                (newPtr->nextPtr)->numero = temp;
                flag = 1;
            }
            newPtr = newPtr->nextPtr;
        }
        ultimoPtr = newPtr;
    }

    newPtr = testaPtr;
    while(newPtr != NULL){
        printf("%d ",newPtr->numero);
        newPtr = newPtr->nextPtr;
    }

    listaOrdine *tempPtr = NULL;        //free dei 10 nodi della lista
    newPtr = testaPtr;
    while (newPtr != NULL) {
        tempPtr = newPtr->nextPtr;  // Salva il nodo successivo
        free(newPtr);              // Libera il nodo corrente
        newPtr = tempPtr;          // Passa al nodo successivo
    }
    testaPtr = NULL;  // Buona pratica: resettare la testa

}//end of function

void selectionSortList(){
    printf("SELECTION SORT LIST"); 
    puts("");

    int dim = 0;
    listaOrdine *testaPtr = NULL;
    listaOrdine *newPtr = NULL;

    printf("Inserisci la dimensione della lista\n");
    scanf("%d",&dim);

    for(int i = 0; i < dim; i++){
        if(i == 0){
            testaPtr = malloc(sizeof(listaOrdine));
        }else if(i == 1){
            newPtr = testaPtr->nextPtr = malloc(sizeof(listaOrdine));
        }else{
            newPtr = newPtr->nextPtr = malloc(sizeof(listaOrdine));
        }
    }

    printf("\nAssegnazione Numeri...\n");
    printf("\nStampa lista non ordinata -> ");
    newPtr = testaPtr;
    while(newPtr != NULL){
        newPtr->numero = 1 + rand() % 21;
        printf("%d ",newPtr->numero);
        newPtr = newPtr->nextPtr;
    }

    printf("\nSELECTION SORT\n");

    newPtr = testaPtr;
    listaOrdine *Lptr = NULL;
    listaOrdine *minimoPtr = NULL;

    while(newPtr != NULL){                                  //tutto questo while è come se fosse il for della i


        minimoPtr = newPtr;             //nodo corrente (parto dalla testa)
        Lptr = newPtr->nextPtr;         //questo è il successivo (come se fosse la j)

        while(Lptr != NULL){                                //tutto questo while è come se fosse il for della j
            if(Lptr->numero < minimoPtr->numero){
                minimoPtr = Lptr;
            }
            Lptr = Lptr->nextPtr;
        }

        if(minimoPtr != newPtr){                        //questo serve perché nell ultimo ciclo del while esterno, dentro il while interno la condizione non sarà mai verificata (perché ormai c'è solo il massimo) e quindi Lptr scorre fino ad uscire dal while e minimoPtr sarà rimasto = a newPtr (elemento corrente del while esterno)
            int temp = newPtr->numero;                  //quindi serve cosi in tutti gli altri cicli entra dentro questo if e si scambiano
            newPtr->numero = minimoPtr->numero;
            minimoPtr->numero = temp;
        }
        newPtr = newPtr->nextPtr;       //passa al prossimo nodo (come se fosse la i che si incrementa)

    }

    newPtr = testaPtr;
    while(newPtr != NULL){
        printf("%d ",newPtr->numero);
        newPtr = newPtr->nextPtr;
    }

    listaOrdine *tempPtr = NULL;        //free dei 10 nodi della lista
    newPtr = testaPtr;
    while (newPtr != NULL) {
        tempPtr = newPtr->nextPtr; 
        free(newPtr);             
        newPtr = tempPtr;          
    }
    testaPtr = NULL; 

}

void insertionSortList(){
    printf("INSERTION SORT LIST");
    puts("");
}

void bubbleSortNode(){
    printf("BUBBLE SORT NODE");
    puts("");
}

void selectionSortNode(){
    printf("SELECTION SORT NODE");
    puts("");
}

void insertionSortNode(){
    printf("INSERTION SORT NODE");
    puts("");
}