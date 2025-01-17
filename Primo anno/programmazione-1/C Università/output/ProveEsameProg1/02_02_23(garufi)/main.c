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

//continua per come lo sai fare


