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

int main(int argc, char **argv){

    parametri file = readInput(argc,argv);

    A *testaPtr = NULL;
    readFile(&testaPtr,file.input);
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

    //da qua in poi fatto con chat gpt
A *insertOrdered(A **headPtr, A *newNode) {                                             
    if (*headPtr == NULL || (*headPtr)->anno_apertura > newNode->anno_apertura) {
        // Inserimento in testa
        newNode->nextPtr = *headPtr;
        *headPtr = newNode;
    } else {
        // Trova la posizione corretta
        A *currentPtr = *headPtr;
        while (currentPtr->nextPtr != NULL && currentPtr->nextPtr->anno_apertura < newNode->anno_apertura) {
            currentPtr = currentPtr->nextPtr;
        }
        // Inserisci il nuovo nodo
        newNode->nextPtr = currentPtr->nextPtr;
        currentPtr->nextPtr = newNode;
    }
    return *headPtr;
}

A *readFile(A **headPtr, char input[35]) {
    FILE *filePtr = fopen(input, "r");
    if (filePtr == NULL) {
        fprintf(stderr, "\nErrore nell'apertura del file\n");
        exit(-1);
    }

    printf("\nFile aperto correttamente\n");

    while (!feof(filePtr)) {
        A *newNode = malloc(sizeof(A));
        if (newNode == NULL) {
            fprintf(stderr, "\nErrore di allocazione memoria\n");
            exit(-1);
        }

        if (fscanf(filePtr, "%s %s %d %d %f", newNode->nome, newNode->cognome, 
                   &newNode->numero_conto, &newNode->anno_apertura, &newNode->saldo) == 5) {
            newNode->nextPtr = NULL;
            *headPtr = insertOrdered(headPtr, newNode);
        } else {
            free(newNode);
        }
    }

    fclose(filePtr);

    A *newPtr = *headPtr;

    while(newPtr != NULL){
        printf("%s %s %d %d %.2f\n",newPtr->nome,newPtr->cognome,newPtr->numero_conto,newPtr->anno_apertura,newPtr->saldo);
        newPtr = newPtr->nextPtr;
    }

    return *headPtr;
}


