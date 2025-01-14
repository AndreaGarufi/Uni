/*implementa inserimento in testa, inserimento in mezzo, inserimento ordinato 
cancellazione in testa, cancellazione in mezzo, canzellazione in coda*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct lista{
    int numero;
    struct lista *nextPtr;
};
typedef struct lista lista;

lista *inTesta(lista **headPtr);
lista *inMezzo(lista *headPtr, int dim);
lista *cancInTesta(lista **headPtr);
lista *cancInCoda(lista **headPtr);

int main(){
    srand(time(NULL));

    lista *testaPtr = NULL;
    lista *newPtr = NULL;

    int operazione = 0;
    int nodi = 0;

    printf("\nCreazione random dei nodi...\n");
    int dim = 2 + rand() % 7;

    for(int i = 0; i < dim; i++){

        if(i == 0){
            testaPtr = malloc(sizeof(lista));
            testaPtr->numero = i+1;
        }else if(i == 1){
            newPtr = malloc(sizeof(lista));
            newPtr = testaPtr->nextPtr = malloc(sizeof(lista));
            newPtr->numero = i+1;
        }else{
            newPtr = newPtr->nextPtr = malloc(sizeof(lista));
            newPtr->numero = i+1;
        }
    }
    printf("\n\n\nNodi Creati -> %d\n\n\n",dim);

    newPtr = testaPtr;
    printf("\n-------lista-------\n");
    while(newPtr != NULL){
        printf("\n%d\n",newPtr->numero);
        newPtr = newPtr->nextPtr;
    }
    printf("\n-------lista-------\n");

    do{
        printf("\n1 per inserire in testa\n2 per inserire in mezzo\n3 per l'inserimento ordinato\n4 per la cancellazione in testa\n5 per la cancellazione in mezzo\n6 per la cancellazione in coda\n7 per stampare la lista\n\n");
        scanf("%d",&operazione);
        puts("");

        switch(operazione){
            case 1: inTesta(&testaPtr);
            dim++;
            break;
            case 2: inMezzo(testaPtr,dim);
            dim--;
            break;
            case 4: cancInTesta(&testaPtr);
            break;
            case 6: cancInCoda(&testaPtr);
            case 7:
                printf("\n-------lista-------\n");
                newPtr = testaPtr;
                while(newPtr != NULL){
                    printf("\n%d\n",newPtr->numero);
                    newPtr = newPtr->nextPtr;
                }
                printf("\n-------lista-------\n");
            break;

            default: if(operazione != -1){
                printf("\nInserisci il numero giusto\n");
            }
        }

    }while(operazione != -1);

}

lista *inTesta(lista **headPtr){
    puts("\nInserimento in testa\n");

    lista *newTestaPtr = malloc(sizeof(lista));
    lista *newPtr = NULL;

    newTestaPtr->nextPtr = *headPtr;

    *headPtr = newTestaPtr;
    (*headPtr)->numero = 100 + rand() % 110;   //numeri per inserimenti in testa

    newPtr = *headPtr;
    printf("\n-------lista-------\n");
    while(newPtr != NULL){
        printf("\n%d\n",newPtr->numero);
        newPtr = newPtr->nextPtr;
    }
    printf("\n-------lista-------\n");
    puts("");

    return *headPtr;
    
}

lista *inMezzo(lista *headPtr, int dim){
    puts("\nInserimento in mezzo\n");

    if(headPtr->nextPtr == NULL){   //vuol dire che ho un solo nodo
        free(headPtr);
        return 0;
    }

    lista *newPtr = headPtr;
    lista *lastPtr = NULL;
    int nodo = 1 + (rand() %(dim-1));

    printf("\nSara' cancellato casualmente il nodo numero %d\n",nodo+1);

    int i = 0;
    while(newPtr != NULL){
        if(i == nodo){          //trovato il nodo da cancellare
            break;
        }
        lastPtr = newPtr;
        newPtr = newPtr->nextPtr;
        i++;
    }
    lastPtr->nextPtr = newPtr->nextPtr;    //collegamento al nodo successivo a quello che verra cancellato
    free(newPtr);                           //cancellazione del nodo

    newPtr = headPtr;
    printf("\n-------lista-------\n");
    while(newPtr != NULL){
        printf("\n%d\n",newPtr->numero);
        newPtr = newPtr->nextPtr;
    }
    printf("\n-------lista-------\n");
    puts("");

    return headPtr;
}

lista *cancInTesta(lista **headPtr){
    printf("\nCancellazione in testa\n");

    if(*headPtr == NULL){
        printf("\nLista gia vuota\n");
        return 0;
    }
    if((*headPtr)->nextPtr == NULL){
        free(*headPtr);
        return 0;
    }

    lista *newTesta = (*headPtr)->nextPtr;
    free(*headPtr);

    *headPtr = newTesta;

    lista *newPtr = newTesta;
    printf("\n-------lista-------\n");
    while(newPtr != NULL){
        printf("\n%d\n",newPtr->numero);
        newPtr = newPtr->nextPtr;
    }
    printf("\n-------lista-------\n");
    puts("");

    return *headPtr;
}

lista *cancInCoda(lista **headPtr){
    printf("\nCancellazione in coda\n");
}

