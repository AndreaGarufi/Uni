#include <stdio.h>
#include <stdlib.h>

struct codice{
    int codice;
    struct codice *nextPtr;
};
typedef struct codice codice;

int main(){
    int codici = 0;

    printf("Inserisci i 5 codici\n");

    codice *testaPtr = NULL;
    codice *newPtr = NULL;
    testaPtr = malloc(sizeof(codice));  //creazione primo nodo della lista

    for(int i = 0; i < 5;i++){

        scanf("%d",&codici);
        testaPtr->codice = codici;
        testaPtr->nextPtr = malloc(sizeof(codice));     //ceazione secondo nodo
        if(i == 0){
            newPtr = testaPtr->nextPtr;                 //assegnazione secondo nodo a newPtr
        }else if(i < 5){
            newPtr = newPtr->nextPtr;
        }else{
            newPtr->nextPtr = NULL;
        }
    }
    for(int i = 0;i < 5;i++){
        if(i == 0){
            printf("\n%d ",testaPtr->codice);
        }else{
            printf("\n%d ",newPtr->codice);
        }
        
    }
//SISTEMA LA CREAZIONE DI 5 NODI DELLA LISTA (PROBABILMENTE BISOGNA CANCELLARE TUTTO)
}