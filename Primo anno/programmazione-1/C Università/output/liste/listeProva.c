#include <stdio.h>
#include <stdlib.h>

struct caratteri{
    char dati;
    struct caratteri *nextPtr;
};

typedef struct caratteri caratteri;

int main(){

    caratteri lettere;
    char valore;

    printf("Inserisci delle lettere\n");
    scanf(" %c",&valore);

    //printf(" %c ",lettere.dati);

    caratteri *testaPtr = NULL;                         //dichiarazione puntatore alla testa della lista
    testaPtr = malloc(sizeof(caratteri));               //creazione primo nodo
    testaPtr->dati = valore; 
    printf("\n%c",testaPtr->dati);
    testaPtr->nextPtr = malloc(sizeof(caratteri));      //creazione secondo nodo

    caratteri *newPtr = testaPtr->nextPtr;              //assegnazione indirizzo secondo nodo a newPtr
    newPtr->dati = 'H';                 
    printf("\n%c",newPtr->dati);

    newPtr->nextPtr = malloc(sizeof(caratteri));        //creazione terzo nodo
    newPtr = newPtr->nextPtr;
    newPtr->dati = 'C';
    printf("\n%c",newPtr->dati);
    newPtr->nextPtr = NULL;




    



}