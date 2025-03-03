#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct listaEta{
    int eta;
    struct listaEta * nextPtr;
};
typedef struct listaEta listaEta;

void bubbleSortLista(listaEta *headPtr);

int main(){
    srand(time(NULL));

    printf("\nGenerazione random della lista (numero nodi e contenuto)\n");

    int dim = 1 + rand()% 10;
    listaEta *testaPtr = NULL;
    listaEta *newPtr = NULL;

    printf("\nDimensione Lista -> %d\n",dim);

    for(int i = 0; i < dim; i++){       //(usando 2 puntatori)

        if(i == 0){
            testaPtr = malloc(sizeof(listaEta));                    //creazione primo nodo
        }else if(i == 1){
            newPtr = testaPtr->nextPtr = malloc(sizeof(listaEta));  //creazione secondo nodo
        }else{
            newPtr = newPtr->nextPtr = malloc(sizeof(listaEta));    //creazione altri nodi
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

    //BUBBLE SORT (con questa bubble sort scambio i valori in ordine crescente, ma se ci fossero più variabili nella lista quelle rimarrebbero cosi come sono)
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

    bubbleSortLista(testaPtr);

}

void bubbleSortLista(listaEta *headPtr){

    printf("\nBubble Sort Per Spostare Tutta La Lista\n");
    listaEta *newPtr = NULL;
    listaEta *successivoPtr = NULL;

while (1) { 
    int scambiato = 0; 
    listaEta *precedentePtr = NULL; // Per tenere traccia del nodo precedente
    listaEta *newPtr = headPtr; 
    listaEta *successivoPtr = newPtr->nextPtr;

    while (successivoPtr != NULL) { 
        if (newPtr->eta > successivoPtr->eta) {
            // Gestione dello scambio
            if (precedentePtr == NULL) {
                // Se stiamo scambiando il primo nodo
                headPtr = successivoPtr;
            } else {
                // Collegamento del nodo precedente al successivo
                precedentePtr->nextPtr = successivoPtr;
            }

            // Scambio dei puntatori nextPtr
            newPtr->nextPtr = successivoPtr->nextPtr;
            successivoPtr->nextPtr = newPtr;

            // Segnala che è avvenuto uno scambio
            scambiato = 1;

            // Aggiorna i puntatori per il prossimo ciclo
            precedentePtr = successivoPtr;
            successivoPtr = newPtr->nextPtr;
        } else {
            // Avanza i puntatori se non c'è stato scambio
            precedentePtr = newPtr;
            newPtr = successivoPtr;
            successivoPtr = successivoPtr->nextPtr;
        }
    }

    if (scambiato == 0) { 
        break; 
    }
}

    newPtr = headPtr;
    int i = 1;
    while(newPtr != NULL){
        printf("nodo numero %d -> eta' -> %d\n",i,newPtr->eta);
        newPtr = newPtr->nextPtr;
        i++;
    } 


}