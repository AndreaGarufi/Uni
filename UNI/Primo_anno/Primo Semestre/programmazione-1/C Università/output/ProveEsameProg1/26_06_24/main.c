#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct parametri{
    char input[35];
    char output[35];
    int n;
};
typedef struct parametri parametri;

parametri decodeParameters(int argc, char **argv);
int fibonacci(int i);
char *sampleString(char string[13], int h,int n);
char **getStringArray(int n);

int main(int argc, char **argv){
    parametri dati = decodeParameters(argc,argv);

    printf("\ninput -> %s | intero n -> %d | output -> %s\n",dati.input,dati.n,dati.output);


    int *A = malloc(sizeof(int)*dati.n);
    printf("\nSequenza di Fibonacci -> ");
    for(int i = 0; i < dati.n; i++){
        A[i] = fibonacci(i);
        printf("%d ",A[i]);
    }

    char ** B = getStringArray(dati.n);

    


}

parametri decodeParameters(int argc, char **argv){

    parametri input;

    if(argc != 4){
        fprintf(stderr,"\nErrore nel numero dei parametri\n");
        exit(-1);
    }

    FILE *filePtr = NULL;

    if((filePtr = fopen(argv[1],"r")) == NULL){
        fprintf(stderr,"\nErrore nell'apertura del file\n");
        exit(-1);
    }else{
        printf("\nFile aperto correttamente\n");
    }

    char stringa[13] = {0};

    fscanf(filePtr,"%s",stringa);
    fclose(filePtr);

    if(strlen(stringa) < 8 || strlen(stringa) > 12){
        fprintf(stderr,"\nIl file non contiene i giusti parametri\n");
        exit(-1);
    }else{
        printf("\nIl file contiene i giusti parametri\n");
    }

    if(atoi(argv[2]) < 3 || atoi(argv[2]) > 12){
        fprintf(stderr,"\nIl numero n non e' valido\n");
        exit(-1);
    }else{
        printf("\nl'intero n e' valido\n");

    }

    strcpy(input.input,argv[1]);
    input.n = atoi(argv[2]);
    strcpy(input.output,argv[3]);


    return input;

}

int fibonacci(int i){

    if(i == 0 || i == 1){
        return i;
    }else{
        i = fibonacci(i - 1) + fibonacci(i - 2);
        return i;
    }


}   

char *sampleString(char string[13], int h,int n){

//creo stringa casuale
    char *casual = malloc(sizeof(char)*h +1);

    for(int j = 0; j < h+1; j++){
        int indice = 0 + rand() % 10;
        casual[j] = string[indice];
    }

    casual[h] = '\0';

    return casual;

}

char **getStringArray(int n){

    FILE *filePtr = NULL;

    if((filePtr = fopen("input.txt","r")) == NULL){
        fprintf(stderr,"\nErrore nell'apertura del file\n");
        exit(-1);
    }else{
        printf("\nFile aperto correttamente\n");
    }

    char stringa[13] = {0};
    fscanf(filePtr,"%s",stringa);
    fclose(filePtr);

    char **B = malloc(sizeof(char*)*n); //lunghezza di B
    for(int i = 0; i < n; i++){
        //strcpy(stringa,sampleString(stringa,i));        //lunghezza casuale
        B[i] = malloc(sizeof(char)*i);              //spazio per ogni stringa
        strcpy(B[i],sampleString(stringa,i,n));                       //copiatura della stringa casuale di lunghezza i (h)
        printf("%s ",B[i]);
    }

    return B;
    
}
