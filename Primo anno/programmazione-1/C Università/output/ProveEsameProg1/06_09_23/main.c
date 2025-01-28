#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct parametri{
    int n;
    char inputFileName[35];
};
typedef struct parametri parametri;

struct P{
    float x;
    struct P *nextPtr;
};
typedef struct P P;

parametri decodeParameters(int argc, char **argv);
int *readInput(int *a);
P *createStack(P **headPtr, int *a, int n);
bool multiplo(int a, int n);
P *inTesta(P **headPtr, int a,float media);
P *pop(P **headPtr,int valore);
float findMinMaxMean(P *headPtr,int i);
float media(P *headPtr);
int main(int argc, char **argv){

    parametri dati = decodeParameters(argc,argv);
    printf("\nPARAMETRI: n -> %d inputFileName -> %s\n",dati.n, dati.inputFileName);

    int *A = readInput(A);
    P *testaPtr = createStack(&testaPtr,A,dati.n);
    
    float Y[2] = {0};
    for(int i = 0; i < 2; i++){
        Y[i] = findMinMaxMean(testaPtr,i);
        printf("%.2f",Y[i]);
    }
    float mediaTot = media(testaPtr);
}

parametri decodeParameters(int argc, char **argv){

    parametri input;

    if(argc != 3){
        fprintf(stderr,"\nErrore nel numero di parametri\n");
        exit(-1);
    }

    if(atoi(argv[1]) < 5 || atoi(argv[1]) > 20){
        fprintf(stderr,"\nErrore nel numero n inserito\n");
        exit(-1);
    }

    if(strcmp(argv[2],"input.dat") != 0){
        fprintf(stderr,"\nErrore nel nome del file\n");
        exit(-1);
    }

    strcpy(input.inputFileName,argv[2]);
    input.n = atoi(argv[1]);

    return input;


}

int *readInput(int *a){

    FILE *filePtr = NULL;

    if((filePtr = fopen("input.dat","r")) == NULL){
        fprintf(stderr,"\nErrore nell'apertura del file\n");
        exit(-1);
    }else{
        printf("\nFile aperto correttamente\n");
    }
    int i = 0;
    int n = 0;
    while(fscanf(filePtr,"%d",&n) == 1){
        i++;
    }

    a = malloc(sizeof(int) * i);

    n = 0;
    i = 0;
    fseek(filePtr,0,SEEK_SET);
    while(fscanf(filePtr,"%d",&n) == 1){
        a[i] = n;
        printf("%d ",a[i]);
        i++;
    }    
    return a;
}

P *createStack(P **headPtr, int *a, int n){

   float m = 0;
    printf("\nCreazione Pila\n");

    P *newNodePtr = NULL;

    *headPtr = malloc(sizeof(P));
    (*headPtr)->x = a[0];
    (*headPtr)->nextPtr = NULL;
    //printf("%.2f ",(*headPtr)->x);

    for(int i = 1; i < 20; i++){    //scorro dal secondo elemento in poi

        bool condizione = false;
        condizione = multiplo(a[i],n);

        if(condizione == true){ //se è un multiplo inserisce in testa
            //printf("\n multiplo ");
            *headPtr = inTesta(headPtr,a[i],m);
        }else{  
            *headPtr = pop(headPtr,a[i]);

        }
    }

    P *newPtr = *headPtr;
    while(newPtr != NULL){
        printf("%.2f ",newPtr->x);
        newPtr = newPtr->nextPtr;
    }

}

bool multiplo(int a, int n){

    bool multiplo = false;

    if(a%n == 0){
        multiplo = true;
        return multiplo;
    }else{
        multiplo = false;
        return multiplo;
    }
}

P *inTesta(P **headPtr, int a,float media){


    P *newNodo = malloc(sizeof(P));
    if(media == 0){ //caso in cui il numero è multiplo
        newNodo->x = a;
    }else{
        newNodo->x = media;
    }
    newNodo->nextPtr = *headPtr;
    *headPtr = newNodo;

    return *headPtr;
}

P *pop(P **headPtr,int valore){
    //printf("melpo\n");
    float elemento = (*headPtr)->x;
    P *appoggio = *headPtr; //nodo di testa

    *headPtr = (*headPtr)->nextPtr;
    free(appoggio);

    //calcolo media
    float media = (elemento + valore)/2;

    *headPtr = inTesta(headPtr,valore,media);

    return *headPtr;

}

float findMinMaxMean(P *headPtr,int i){

    if(i == 0){
        P *newPtr = headPtr;
        float minimo = newPtr->x;
        while(newPtr->nextPtr != NULL){
            if(minimo > (newPtr->nextPtr)->x){
                minimo = (newPtr->nextPtr)->x;
            }
            newPtr = newPtr->nextPtr;
        }
        return minimo;
    }else if(i == 1){
        P *newPtr = headPtr;
        float massimo = newPtr->x;
        while(newPtr->nextPtr != NULL){
            if(massimo < (newPtr->nextPtr)->x){
                massimo = (newPtr->nextPtr)->x;
            }
            newPtr = newPtr->nextPtr;
        }
        return massimo;
    }

}
float media(P *headPtr){

    P *newPtr = headPtr;


}