#include <stdio.h>
#include <stdlib.h>

struct codice{
    int codice;
    struct codice *nextPtr;
};
typedef struct codice codice;

int main(){
    int codici = 0;
    int i = 1;
    printf("Inserisci i 5 codici\n");
    scanf("%d",&codici);

    codice *testaPtr = NULL;
    codice *newPtr = NULL;
    testaPtr = malloc(sizeof(codice));  //creazione primo nodo della lista
    testaPtr->codice = codici;
    printf("\n CODICE %d\n",testaPtr->codice);

    while(i < 5){
        scanf("%d",&codici);
        if(i == 1){
             newPtr = testaPtr->nextPtr = malloc(sizeof(codice));       //crea il secondo nodo
             newPtr->codice = codici;
             printf("\n CODICE %d \n",newPtr->codice);
        }else if(i < 5){
            newPtr = newPtr->nextPtr = malloc(sizeof(codice));      //qui crea tutti gli altri 
            newPtr->codice = codici;
            printf("\n CODICE %d \n",newPtr->codice);
        }
        i++;
        if(i == 5){
            newPtr->nextPtr = NULL;                                 //qui assegna il puntatore a NULL
        }
    }

    codice *ptr = testaPtr;

    printf("\nCREAZIONE 6 NODO\n");
    while(ptr->nextPtr != NULL){                //scorro i nextPtr finche è diverso da NULL (ultimo elemento della lista)
        ptr = ptr->nextPtr;                     //ptr assume il valore di nextPtr cosi mi sposto nelle liste
    }
    ptr->nextPtr = malloc(sizeof(codice));
    ptr->codice = 2269420;

    printf(" CODICE FINALE %d",ptr->codice);


}