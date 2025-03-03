//con il programma cosi com'è facendo un conto avrei dovuto prendere da 19 a 22
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct parametri{
    char fileName[100];
};
typedef struct parametri parametri;

struct P{
    int numero;
    struct P *nextPtr;
};
typedef struct P P;

parametri decodeParameters(int argc, char ** argv);
P *readFile(P **headPtr);
float getMean(P **headPtr);
P *fillP(P **headPtr, float media);
int *sort(int *y, P *headPtr);

int main(int argc, char **argv){

    parametri stringa = decodeParameters(argc,argv);

    printf("\nParametro passato -> %s\n",stringa.fileName);

    P *testaPtr = NULL;
    testaPtr = readFile(&testaPtr);
    int *Y = sort(Y,testaPtr);
    float m = getMean(&testaPtr);
    printf("\nMedia -> %.2f\n",m);

    testaPtr = fillP(&testaPtr,m);
}

parametri decodeParameters(int argc, char ** argv){
    
    parametri input;

    if(argc != 2){
        fprintf(stderr,"\nErrore nel numero dei parametri\n");
        exit(-1);
    }
    
    if((strcmp(argv[1],"input.txt")) != 0){
        fprintf(stderr,"\nErrore nell'inserimento del nome del file\n");
        exit(-1);        
    }
    strcpy(input.fileName,argv[1]);

    return input;

}

P *readFile(P **headPtr){

    FILE *filePtr = NULL;

    if((filePtr = fopen("input.txt","r")) == NULL){
        fprintf(stderr,"\nErrore nell'apertura del file\n");
        exit(-1);        
    }else{
        printf("\nFile aperto correttamente\n");
    }
    int numero = 0;
    P *newPtr = NULL;
    int i = 1;
    while(fscanf(filePtr,"%d",&numero) == 1){
        if(i == 1){
            *headPtr = malloc(sizeof(P));
            (*headPtr)->numero = numero;
        }else if(i == 2){
            newPtr = (*headPtr)->nextPtr = malloc(sizeof(P));
            newPtr->numero = numero;
        }else{
            newPtr = newPtr->nextPtr = malloc(sizeof(P));
            newPtr->numero = numero;
            newPtr->nextPtr = NULL;
        }
        i++;
    }
    
    fclose(filePtr);

    newPtr = *headPtr;

    while(newPtr != NULL){
        printf("%d ",newPtr->numero);
        newPtr = newPtr->nextPtr;
    }

    return *headPtr;
}

float getMean(P **headPtr){

    int arrayMedia[12] = {0};

    P *newPtr = *headPtr;
    P *lastPtr = NULL;
    int i = 0;
    while(newPtr != NULL){
        if(newPtr->nextPtr == NULL){
            arrayMedia[i] = newPtr->numero;
            i++;
            free(newPtr);
            lastPtr->nextPtr = NULL;
            newPtr = *headPtr;
            
        }
        lastPtr = newPtr;
        newPtr = newPtr->nextPtr;
    }
    arrayMedia[i] = (*headPtr)->numero;
    free(*headPtr);
    puts("");
    
    float media;
    int somma = 0;
    for(int i = 0; i < 12; i++){
        somma = somma + arrayMedia[i];
    }
    media = somma / 12;

    return media;
}

P *fillP(P **headPtr, float media){

    FILE *filePtr = NULL;

    if((filePtr = fopen("input.txt","r")) == NULL){
        fprintf(stderr,"\nErrore nell'apertura del file\n");
        exit(-1);        
    }else{
        printf("\nFile aperto correttamente\n");
    }

    P *lastPtr = NULL;
    P *newPtr = NULL;
    int numero = 0,temp = 0;
    int i = 1;
    /*while(fscanf(filePtr,"%d",&numero) == 1){
        if(i == 1){
            *headPtr = malloc(sizeof(P));
            (*headPtr)->numero = numero;
        }else if(i == 2){
            if(numero > media){
                newPtr = (*headPtr)->nextPtr = malloc(sizeof(P));
                newPtr->numero = numero;
            }else{
                temp = (*headPtr)->numero;
                (*headPtr)->numero = (numero+temp)/2;
                newPtr = *headPtr;
                //printf("%d ",(*headPtr)->numero);
            }
        }else{
            lastPtr = newPtr;
            if(numero > media){
                newPtr = newPtr->nextPtr = malloc(sizeof(P));
                newPtr->numero = numero;
                newPtr->nextPtr = NULL;
            }else{
                temp = lastPtr->numero;
                lastPtr->numero = (numero+temp)/2;
                lastPtr->nextPtr = NULL;
            }
        }
        i++;
    }

    newPtr = *headPtr;

    while(newPtr != NULL){
        printf("%d ",newPtr->nextPtr);
        newPtr = newPtr->nextPtr;
    }*/

    fclose(filePtr);
    return *headPtr;
}

int *sort(int *y, P *headPtr){
    
    y = malloc(sizeof(int) * 12);

    P *newPtr = headPtr;
    int i = 0;
    while(newPtr != NULL){
        y[i] = newPtr->numero;
        i++;
        newPtr = newPtr->nextPtr;
    }

    printf("\n\nStampa array non ordinatao\n");
    for(int i = 0; i < 12; i++){
        printf("%d ",y[i]);
    }

    printf("\nOrdinamento tramite bubble sort\n");

    for(int i = 0; i < 12-1; i++){
        for(int j = 0; j < 12-1; j++){
            if(y[j] > y[j+1]){
                int temp = y[j+1];
                y[j+1] = y[j];
                y[j] = temp;
            }
        }
    }

    for(int i = 0; i < 12; i++){
        printf("%d ",y[i]);
    }    

}