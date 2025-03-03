/*Scrivi un programma che:

Chieda all'utente di inserire 5 numeri interi in un array.
Calcoli la somma dei numeri nell'array utilizzando un puntatore per scorrere gli elementi.
Stampi la somma finale.*/


#include <stdio.h>

int main(){

    int array[5] = {0};
    int valore = 0;
    int *arrayPtr = array;
    int somma = 0;

    printf("Inserisci i 5 numeri: \n");

    for(int i = 0; i < 5; i++){
        scanf("%d",&valore);
        array[i] = valore;
    }
    puts("");
    for(int i = 0; i < 5; i++){
        printf("%d ",array[i]);
    }    

    while(arrayPtr != (array + 5)){
        somma = somma + *arrayPtr;
        arrayPtr++;
    }

    printf("SOMMA %d",somma);

}