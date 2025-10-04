/*Questo programma gestisce una lista di studenti, leggendo e scrivendo i dati da/a un file e permettendo l'aggiunta di nuovi studenti 
tramite gli argomenti del programma.

Specifiche del programma
Gli studenti sono memorizzati in una lista collegata.
I dati sono salvati in un file chiamato studenti.txt.
Il programma accetta tre argomenti per aggiungere un nuovo studente:
Nome
Età
Media voti (intera)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studente{
    int eta;
    char nome[35];
    int media;
};
typedef struct studente studente;

studente decodeParameters(int argc, char **argv);
studente *CreateList(int eta, char nome[], int media);
studente *readFile();

int main(int argc, char **argv){

    studente dati = decodeParameters(argc,argv);


    
}

studente decodeParameters(int argc, char **argv){
    studente parametri;

    printf("\nParametri passati %d\n",argc);

    if(argc != 4){
        fprintf(stderr,"Errore numero parametri errato");
        exit(-1);
    }

    parametri.eta = atoi(argv[1]);
    strcpy(parametri.nome,argv[2]);
    parametri.media = atoi(argv[3]);

    if(parametri.eta < 0 || parametri.eta > 99){
        fprintf(stderr,"Errore nell'inserimento dell'eta'");
        exit(-1);
    }
    if(strlen(argv[2]) > 34){
        fprintf(stderr,"Errore nell'inserimento del nome");
        exit(-1);
    }
    if(parametri.media < 0 || parametri.media > 10){
        fprintf(stderr,"Errore nell'inserimento della media");
        exit(-1);
    }

    return parametri;

}

studente *CreateList(int eta, char nome[], int media){      //crea la lista se nel file non è scritto nulla, altrimenti fai inserimenti in coda
    puts("\nCrea Lista\n");

    FILE *filePtr = NULL;   
    int eta = 0,media = 0;
    char nome[35]

}

studente *readFile(){
    printf("\nLettura File\n");
}


