#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct lista{
    char stringa[40];
    struct lista *nextPtr;
};
typedef struct lista lista;

int main(){
    FILE *filePtr = NULL;

    if((filePtr = fopen("dati.txt","r")) == NULL){
        fprintf(stderr,"\nErrore nell'apertura del file\n");
        exit(-1);
    }else{
        printf("\nFile aperto correttamente\n");
    }

    lista *testaPtr = NULL;
    lista *newPtr = NULL;

    char input[40];

    int i = 0;
    while(fscanf(filePtr,"%s",input) == 1){
        if(i == 0){
            testaPtr = malloc(sizeof(lista));
            strcpy(testaPtr->stringa,input);
        }else if(i == 1){
            newPtr = testaPtr->nextPtr = malloc(sizeof(lista));
            strcpy(newPtr->stringa,input);
        }else{
            newPtr = newPtr->nextPtr = malloc(sizeof(lista));
            strcpy(newPtr->stringa,input);
        }
        i++;
    }
    printf("\nLista Creata\n\n");
    

    newPtr = testaPtr;

    while(newPtr != NULL){
        printf("%s \n",newPtr->stringa);
        newPtr = newPtr->nextPtr;
    }

    fclose(filePtr);

    if((filePtr = fopen("datiOUT.txt","a")) == NULL){
        fprintf(stderr,"\nErrore nell'apertura del file\n");
        exit(-1);
    }else{
        printf("\nFile aperto correttamente\n");
    }
    
    newPtr = testaPtr;
    while(newPtr != NULL){
        fprintf(filePtr,"%s \n",newPtr->stringa);
        newPtr = newPtr->nextPtr;
    }  

    fclose(filePtr);
}
