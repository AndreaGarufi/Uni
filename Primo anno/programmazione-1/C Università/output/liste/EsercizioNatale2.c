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

    while(newPtr->nextPtr != NULL){
        i++;
        printf("NUMERO NODO %d -> %d\n",i,newPtr->numero);
        newPtr = newPtr->nextPtr;
    }
    printf("NUMERO NODO %d -> %d\n",i + 1,newPtr->numero);


    printf("STAMPA DELLA LISTA ORDINATA TRAMITE INSERTION SORT...");

    for(int i = 1; i < dimensione; i++){
        int posizione = i;
        if(i == 1){
            newPtr = testaPtr->nextPtr;
        }
        int valore = newPtr->numero;
        
        while(posizione > 0 && ){

        }
    }
}