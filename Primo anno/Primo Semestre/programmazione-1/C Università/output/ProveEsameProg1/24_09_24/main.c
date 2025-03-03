#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct parametri{
    char input_fileName[50];            //struct parametri
    char output_fileName[50];
};
typedef struct parametri parametri;

struct x{
    char stringa[50];                        //strcu lista
    struct x *nextPtr;
};
typedef struct x x;

//funzioni
parametri decodeParameters(int argc, char **argv);
x *readFile();

int main(int argc, char **argv){
 
    parametri dati = decodeParameters(argc,argv);

    printf("input 1 -> %s\ninput 2 -> %s\n",dati.input_fileName,dati.output_fileName);

    x *headPtr = readFile();

}

parametri decodeParameters(int argc, char **argv){

    printf("\nParametri passati %d\n",argc);

    parametri stringa;

    if(argc != 3){
        fprintf(stderr,"ERRORE");
        exit(-1);   
    }

    if(strcmp(argv[1],"input.text") != 0 || strcmp(argv[2],"output.output") != 0){
        fprintf(stderr,"ERRORE");
        exit(-1);
    }

    strcpy(stringa.input_fileName,argv[1]);
    strcpy(stringa.output_fileName,argv[2]);

    return stringa;

}

x *readFile(){

    FILE *filePtr = NULL;
    
    if((filePtr = fopen("input.text","r")) == NULL){
        fprintf(stderr,"\nERRORE APERTURA FILE");
        exit(-1);
    }else{
        printf("\nFile aperto correttamente\n\n");
    }

    /*x *testaPtr = malloc(sizeof(x));
    x *newPtr = testaPtr;
    int i = 1;
    while(!feof(filePtr)){

        if(i == 1){
            fscanf(filePtr,"%s",testaPtr->stringa);     //mette in testa
        }
        newPtr = newPtr->nextPtr = malloc(sizeof(x));       //crea nuovo nodo
        fscanf(filePtr,"%s",newPtr->stringa);
        i++;
    }

    newPtr = testaPtr;
    while(newPtr != NULL){
        printf("%s\n",newPtr->stringa);
        newPtr = newPtr->nextPtr;
    }*/

   

    return testaPtr;
}