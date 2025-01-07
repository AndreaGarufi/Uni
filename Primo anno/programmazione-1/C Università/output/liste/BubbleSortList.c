#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct listaEta{
    int eta;
    struct listaEta * nextPtr;
};
typedef struct listaEta listaEta;



int main(){
    srand(time(NULL));

    printf("\nGenerazione random della lista (numero nodi e contenuto)\n");

    int dim = 1 + rand()% 10;
    listaEta *testaPtr = NULL;
    listaEta *newPtr = NULL;

    printf("\nDimensione Lista -> %d\n",dim);

    for(int i = 0; i < dim; i++){

        if(i == 0){
            testaPtr = malloc(sizeof(listaEta));
        }else if(i == 1){
            newPtr = testaPtr->nextPtr = malloc(sizeof(listaEta));
        }else{
            newPtr = newPtr->nextPtr = malloc(sizeof(listaEta));
        }

    }

    newPtr = testaPtr;

    while(newPtr != NULL){
        newPtr->eta = 1+rand()%110;
        newPtr = newPtr->nextPtr;
    }
    
    printf("\nStampa Lista non ordinata\n");
    newPtr = testaPtr;
    int i = 1;
    while(newPtr != NULL){
        printf("nodo numero %d -> eta' -> %d\n",i,newPtr->eta);
        newPtr = newPtr->nextPtr;
        i++;
    }
    

    printf("\nStampa Lista ordinata con Bubble Sort\n");

    listaEta *successivoPtr = NULL;

    /*while(newPtr->nextPtr != NULL){

        newPtr = testaPtr;
        successivoPtr = newPtr->nextPtr;

        while(successivoPtr != NULL){

            if(newPtr->eta > successivoPtr->eta){
                int temp = newPtr->eta;
                newPtr->eta = successivoPtr->eta;
                successivoPtr->eta = temp;
            }
            newPtr = successivoPtr;
            successivoPtr = successivoPtr->nextPtr;

        }

    }*/

   while (1) { // Ciclo esterno infinito, controllo manuale
    int scambiato = 0; // Aggiunto: Variabile per verificare se ci sono stati scambi
    newPtr = testaPtr; 
    successivoPtr = newPtr->nextPtr;

    while (successivoPtr != NULL) { 
        if (newPtr->eta > successivoPtr->eta) {
            
            int temp = newPtr->eta;
            newPtr->eta = successivoPtr->eta;
            successivoPtr->eta = temp;

            scambiato = 1; // Aggiunto: Segnala che è avvenuto uno scambio
        }
        newPtr = successivoPtr; 
        successivoPtr = successivoPtr->nextPtr;
    }

    if (scambiato == 0) { 
        break; // Aggiunto: Esce dal ciclo esterno se non ci sono stati scambi
    }
}

    newPtr = testaPtr;
    i = 1;
    while(newPtr != NULL){
        printf("nodo numero %d -> eta' -> %d\n",i,newPtr->eta);
        newPtr = newPtr->nextPtr;
        i++;
    }    

}