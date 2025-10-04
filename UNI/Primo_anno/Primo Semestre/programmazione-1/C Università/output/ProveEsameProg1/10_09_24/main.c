#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct recordParameters{
    char carattere;
    char input[50];
    char output[50];
    struct recordParameters *ptr;
};
typedef struct recordParameters recordParameters;

struct alfabeto{
    char lettera;
    struct alfabeto *nextPtr;
    struct alfabeto *ptr;
};
typedef struct alfabeto alfabeto;

recordParameters decodeParameters(int dimP, char **arrayInOut);
alfabeto *readFile();
int countOccurrences(alfabeto *testaPtr,char c);
alfabeto *processL(alfabeto *testaPtr,int o);
void writeToFile(alfabeto *testaPtr);


int main(int argc, char **argv){

    recordParameters dato = decodeParameters(argc,argv);

    printf("\n\n%s , %s ,%c \n",dato.input,dato.output,dato.carattere);
    
    alfabeto *headPtr = readFile();

    char c = dato.carattere;
    int o = countOccurrences(headPtr,c);
    printf("\nOccorrenze trovate -> %d\n",o);

    headPtr = processL(headPtr,o);

    writeToFile(headPtr);

}

recordParameters decodeParameters(int dimP, char **arrayInOut){

    printf("\nParametri Passati %d\n",dimP);

    if(dimP != 4){
        fprintf(stderr,"-1");
        exit(-1);
    }

    recordParameters parametri;

    for(int i = 0; i < dimP; i ++){
        printf("\n%s ",arrayInOut[i]);
    }
    strcpy(parametri.input,arrayInOut[1]);
    strcpy(parametri.output,arrayInOut[2]);
    parametri.carattere = arrayInOut[3][0];

    return parametri;

}

alfabeto *readFile(){


    FILE *filePtr = NULL;

    if((filePtr = fopen("input", "r")) == NULL){
        fprintf(stderr,"Impossibile aprire il file");
        exit(-1);
    }else{
        printf("\nFile aperto correttamente\n");
    }

    alfabeto *testaPtr = malloc(sizeof(alfabeto));
    alfabeto *newPtr = testaPtr;
    int i = 1;
    while(!feof(filePtr)){
        
        if(i == 1){
            fscanf(filePtr,"%c",&(testaPtr->lettera));
        }
        newPtr = newPtr->nextPtr = malloc(sizeof(alfabeto));  //nuovo nodo
        fscanf(filePtr,"%c",&(newPtr->lettera));
        i++;
        
    }

    newPtr = testaPtr;

    while(newPtr != NULL){
        printf("%c",newPtr->lettera);
        newPtr = newPtr->nextPtr;
    }

    return testaPtr;
}

int countOccurrences(alfabeto *testaPtr, char c){


    int i = 0;

    alfabeto *newPtr = testaPtr;

    while(newPtr != NULL){
        if(newPtr->lettera == c){
            i++; //occorrenza trovata
        }
        newPtr = newPtr->nextPtr;
    }

    return i;
}

alfabeto *processL(alfabeto *testaPtr,int o){

    char e;
    int p = 0;
    int cancellazione = 0;
    alfabeto *newPtr = NULL;
    do{
        cancellazione = 0;
        alfabeto *newPtr = testaPtr;
        p = 0;
        printf("\nInserisci la lettera\n");
        scanf(" %c",&e);

        while(newPtr != NULL){
            if(newPtr->lettera == e){
                p++; //occorrenza trovata
                if(p >= o){
                    newPtr->lettera = '\0';
                    cancellazione++;
                    break;
                }
            }
            newPtr = newPtr->nextPtr;
        }

    }while(cancellazione != 0);

    newPtr = testaPtr;

    printf("\nContenuto lista\n");
    while(newPtr != NULL){
        printf("%c",newPtr->lettera);
        newPtr = newPtr->nextPtr;
    }

    return testaPtr;
}

void writeToFile(alfabeto *testaPtr){

    FILE *filePtr = NULL;
    alfabeto *newPtr = testaPtr;

    if((filePtr = fopen("output","w")) == NULL){
    
        fprintf(stderr,"\nERRORE APERTURA FILE DI OUTPUT\n");
        exit(-1);
    }else{
        printf("\nFile di output aperto correttamente\n");
    }

    while(newPtr != NULL){
        fprintf(filePtr,"%c",newPtr->lettera);
        newPtr = newPtr->nextPtr;
    }

}