#include <stdio.h>
#include <stdlib.h>

struct codice{
    int codice;
    struct codice *nextPtr;
};
typedef struct codice codice;

int main(){
    int codici = 0;
    // int i = 1;
    // printf("Inserisci i 5 codici\n");
    // scanf("%d",&codici);

    codice *testaPtr = NULL;
    // testaPtr->codice = codici;
    // printf("\n CODICE %d\n",testaPtr->codice);

    // while(i < 5){
    //     scanf("%d",&codici);
    //     if(i == 1){
    //          newPtr = testaPtr->nextPtr = malloc(sizeof(codice));       //crea il secondo nodo
    //          newPtr->codice = codici;
    //          printf("\n CODICE %d \n",newPtr->codice);
    //     }else if(i < 5){
    //         newPtr = newPtr->nextPtr = malloc(sizeof(codice));      //qui crea tutti gli altri
    //         newPtr->codice = codici;
    //         printf("\n CODICE %d \n",newPtr->codice);
    //     }
    //     i++;
    //     if(i == 5){
    //         newPtr->nextPtr = NULL;                                 //qui assegna il puntatore a NULL
    //     }
    // } 

    for(int i = 0; i<5;i++){
        printf("Inserisci il %d codice: ",i+1);
        scanf("%d", &codici);
        if(testaPtr == NULL){
            testaPtr = malloc(sizeof(codice));
            testaPtr->codice = codici;
            testaPtr->nextPtr = NULL;
        }else{
            codice *newPtr = malloc(sizeof(codice));
            newPtr->codice = codici;
            newPtr->nextPtr = testaPtr;
            testaPtr = newPtr;
        }

    }
    codice *ptr = testaPtr;

    // printf("\nCREAZIONE 6 NODO\n");
    while(ptr != NULL){
        printf("|%d, %p|->",ptr->codice,ptr->nextPtr);
        ptr = ptr->nextPtr;
    }
    printf("NULL"); //Faccio questa cosa per rendere più intuitivo il fatto che l'ultimo nextPtr punta a NULL

    // ptr->nextPtr = malloc(sizeof(codice));
    // ptr->codice = 2269420;

    // printf(" CODICE FINALE %d",ptr->codice);


}