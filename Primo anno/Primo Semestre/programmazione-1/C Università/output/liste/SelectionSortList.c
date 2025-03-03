/*Scrivere un programma in c che legge in input una sequenza di numeri interi, 
la memorizza in una lista, quindi ordina la lista utilizzando l'algoritmo di insertion sort*/

#include <stdio.h>
#include <stdlib.h>

struct listaNumeri{

    int numero;
    struct listaNumeri *nextPtr;
};
typedef struct listaNumeri listaNumeri;

int main(){

    int dimensione = 0;
    int interi = 0;

    listaNumeri *testaPtr = NULL;
    listaNumeri *newPtr = NULL;
    listaNumeri *Lptr = NULL;

    printf("Quanti numeri vuoi inserire?\n");
    scanf("%d",&dimensione);
    printf("\nInserisci una lista di %d numeri interi\n",dimensione);

    for(int i = 0; i < dimensione; i++){

        if(i == 0){
            testaPtr = malloc(sizeof(listaNumeri)); //creazione primo nodo della lista
            }else if(i == 1){
                newPtr = testaPtr->nextPtr = malloc(sizeof(listaNumeri));  // creazione del secondo nodo (questo avviene al secondo ciclo)
                }else{
                    newPtr = newPtr->nextPtr = malloc(sizeof(listaNumeri));  // creazione altri nodi
                }

        printf("\nInserisci il %d numero-> ",i+1);
        scanf("%d",&interi);
        if(i == 0){                                     //assegnazione del numero al primo nodo
            testaPtr->numero = interi;
            testaPtr->nextPtr = NULL;
            //printf("TESTA %d\n",testaPtr->numero);
        }else{                                          //assegnazione degli altri numeri agli altri nodi
            newPtr->numero = interi;
            //printf("ALTRI NODI %d\n",newPtr->numero);
        }
    }
    printf("\nSTAMPA DELLA LISTA NON ORDINATA...\n");
    newPtr = testaPtr;
    int i = 0;

    while(newPtr != NULL){
        i++;
        printf("NUMERO NODO %d -> %d\n",i,newPtr->numero);
        //ptr = newPtr;     //cosi ho un modo per avere un puntatore al nodo precedente
        newPtr = newPtr->nextPtr;
    }


    printf("\nSTAMPA DELLA LISTA ORDINATA TRAMITE SELECTION SORT...\n");


    newPtr = testaPtr; // Nodo corrente (inizia dal primo nodo)
    while (newPtr != NULL) {

        Lptr = newPtr->nextPtr;     //secondo elemento della lista
        listaNumeri *minPtr = newPtr; //minimo (primo elemento della lista)

        while (Lptr != NULL) {
            if (Lptr->numero < minPtr->numero) {
                minPtr = Lptr; // Aggiorna il puntatore al nodo con il valore minimo
            }
            Lptr = Lptr->nextPtr;
        }

        if (minPtr != newPtr) {     //se il minimo trovato è più piccolo del primo allora scambiali, altrimenti si sposta di 1 nella lista
            int temp = newPtr->numero;
            newPtr->numero = minPtr->numero;
            minPtr->numero = temp;
        }

        
        newPtr = newPtr->nextPtr;           // Passa al prossimo nodo
    }
    
    newPtr = testaPtr;
    i = 0;
    while(newPtr != NULL){
        i++;
        printf("NUMERO NODO %d -> %d\n",i,newPtr->numero);
        newPtr = newPtr->nextPtr;
    }
}