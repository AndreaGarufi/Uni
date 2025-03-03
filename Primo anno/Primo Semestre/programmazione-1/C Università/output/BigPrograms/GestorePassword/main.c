//GESTORE  E GENERATORE PASSWORD
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main(){ //33-126
    printf("\nCosa vuoi fare? \n-> Genera password casuale con lettere, numeri e simboli\n-> Genera password casuale con solo lettere e numeri\n-> Genera password casuale con solo lettere e simboli\n-> Genera password casuale con solo numeri e simboli\n-> Genera password casuale con solo lettere\n-> Genera password casuale con solo numeri\n-> Genera password casuale con solo simboli\n");

    int operazione = 0;
    do{
        scanf("%d",&operazione);
        switch(operazione){
            case 1: printf("");
            break;
            
            default : if(operazione != -1){
                printf("Inserisci un numero giusto");
            }else{
                exit(-1);
            }
        }

    }while(operazione != -1);
}