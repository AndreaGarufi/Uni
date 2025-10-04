#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct parametri{
    char input[35];
    char output[35];
};
typedef struct parametri parametri;

struct A{
    char nome[255];
    char cognome[255]; 
    int numero_conto;
    int anno_apertura;
    float saldo;

    struct A *nextPtr;
};
typedef struct A A;

parametri readInput(int argc, char **argv);
A *readFile(A **headPtr,char input[35]);
float getMax(A **headPtr);
float findx(A **headPtr, float m);
A *removeAccount(A **headPtr);



int main(int argc, char **argv){

    parametri file = readInput(argc,argv);

    A *testaPtr = NULL;
    readFile(&testaPtr,file.input);
    float m = getMax(&testaPtr);
    float x = findx(&testaPtr,m);

    testaPtr = removeAccount(&testaPtr);

}

parametri readInput(int argc, char **argv){

    parametri input;

    if(argc != 3){
        fprintf(stderr,"Errore nel numero dei parametri");
        exit(-1);
    }

    if(strcmp(argv[1],"input.txt") != 0){
        fprintf(stderr,"Errore nell'inserimento del nome in input (inserire input.txt)");
        exit(-1);        
    }

    if(strcmp(argv[2],"output.txt") != 0){
        fprintf(stderr,"Errore nell'inserimento del nome in input (inserire output.txt)");
        exit(-1);  
    }

    printf("\nParametri ok\n");

    strcpy(input.input,argv[1]);
    strcpy(input.output,argv[2]);

    return input;

}

A *readFile(A **headPtr,char input[35]){

    FILE *filePtr = NULL;
    A *newPtr = NULL;

    if((filePtr = fopen(input,"r")) == NULL){
        fprintf(stderr,"\nErrore nell'apertura del file\n");
        exit(-1);
    }
    int i = 1;
    while(!feof(filePtr)){
        
        if(i == 1){
            *headPtr = malloc(sizeof(A));
            fscanf(filePtr,"%s %s %d %d %f",(*headPtr)->nome,(*headPtr)->cognome,&(*headPtr)->numero_conto,&(*headPtr)->anno_apertura,&(*headPtr)->saldo); 
        }else if(i == 2){
            newPtr = (*headPtr)->nextPtr = malloc(sizeof(A));
            fscanf(filePtr,"%s %s %d %d %f",newPtr->nome,newPtr->cognome,&newPtr->numero_conto,&newPtr->anno_apertura,&newPtr->saldo);             
        }else{
            if(!feof(filePtr)){
                newPtr = newPtr->nextPtr = malloc(sizeof(A));
                fscanf(filePtr,"%s %s %d %d %f",newPtr->nome,newPtr->cognome,&newPtr->numero_conto,&newPtr->anno_apertura,&newPtr->saldo);  
            }          
        }    
        i++;
    }
    puts("");
    /*while(newPtr->nextPtr != NULL){
        newPtr = newPtr->nextPtr;
    }
    newPtr->nextPtr = NULL;*/
    newPtr = *headPtr;
    while(newPtr->nextPtr != NULL){
        printf("%s %s %d %d %.2f\n",newPtr->nome,newPtr->cognome,newPtr->numero_conto,newPtr->anno_apertura,newPtr->saldo);
        newPtr = newPtr->nextPtr;
    }

    return *headPtr;

}

float getMax(A **headPtr){
    A *newPtr = *headPtr;
    float massimo = 0;

    massimo = newPtr->saldo;
    while(newPtr->nextPtr != NULL){
        newPtr = newPtr->nextPtr;
        if(massimo < newPtr->saldo){
            massimo = newPtr->saldo;
        }
    }

    printf("\nMassimo saldo %.2f\n",massimo);

    return massimo;
}

float findx(A **headPtr, float m){

    A *newPtr = *headPtr;
    int minimo = 0,parziale = 0;
    float x[10] = {0};

    int i = 0;
    while(newPtr != NULL){
        if((parziale = (2023-newPtr->anno_apertura)/5) <= 1){
            minimo = parziale;
        }else{
            minimo = 1;
        }
        
        x[i] = (minimo)*(newPtr->saldo/m);
        //printf(" %.7f ",x[i]);
        float massimo = x[0];
        for(int i = 0; i < 9; i++){
            if(massimo < x[i+1]){
                massimo = x[i+1];
            }
        }

        i++;
        newPtr = newPtr->nextPtr;
    }

    //massimo nel vettore

    //printf("Massima X%.7f",massimo);

}

A *removeAccount(A **headPtr){

    char nome[255];
    char cognome[255]; 
    int numero_conto;
    int anno_apertura;
    float saldo;

    int n = 0;
    FILE *filePtr = NULL;

    if((filePtr = fopen("input.txt","r")) == NULL){
        fprintf(stderr,"\nErrore nell'apertura del file\n");
        exit(-1);
    }
    while(!feof(filePtr)){
        fscanf(filePtr,"%s %s %d %d %f",nome,cognome,&numero_conto,&anno_apertura,&saldo);             
        n++;
    }

    int h = n/2;
    //printf("%d",h);

}

