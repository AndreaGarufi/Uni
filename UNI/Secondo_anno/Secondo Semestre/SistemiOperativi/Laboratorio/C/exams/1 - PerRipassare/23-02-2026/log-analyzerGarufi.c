#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef struct{

    char timestamp[20];
    int severita;
    char buffer[200];
    char *nomeFile;

}valoriRecord;

typedef struct{

    valoriRecord *codaGrezza[10];
    int numeroElementi;
    pthread_mutex_t mutexGrezzo;
    sem_t semaforoLiberi;
    sem_t semaforoOccupati;
    int lettoriAttivi;
    
    valoriRecord *codaFiltrata[5];
    int numeroFiltrati;
    pthread_mutex_t mutexFiltrato;
    sem_t semaforoLiberiFiltrato;
    sem_t semaforoOccupatiFiltrato;
    int filtriAttivi;

    int severity;

}shared;

typedef struct{

    int id;
    char *nomeFile;
    shared *condivisione;

}datiLettori;

typedef struct{

    int id;
    shared *condivisione;

}datiFiltratori;

int severitaNumero(char stringa[]){
    //0 debug, 1 info, 2 warning, 3 error, 4 critical
    if(strcmp(stringa,"DEBUG") == 0){
        return 0;
    }else if(strcmp(stringa,"INFO") == 0){
        return 1;
    }else if(strcmp(stringa,"WARNING") == 0){
        return 2;
    }else if(strcmp(stringa,"ERROR") == 0){
        return 3;
    }else if(strcmp(stringa,"CRITICAL") == 0){
        return 4;
    }else{
        printf("VALORE DI SEVERITY NON CORRETTO.\n");
        exit(EXIT_FAILURE);
    }
}

void *gestioneLettura(void *arg){
    datiLettori *dati = (datiLettori*)arg;
    printf("Entrano i lettori.\n");



}

void *gestioneFiltro(void *arg){
    datiFiltratori *dati = (datiFiltratori*)arg;
    printf("Entrano i filtratori.\n");


    

}

int main(int argc, char *argv[]){

    if(argc < 4){
        perror("Errore, devi avviarmi con: <severity> <R-filters> <file-1> <file-2> ... <file-N>.\n");
        exit(EXIT_FAILURE);
    }

    int numeroLettori = argc - 3;
    int numeroFiltratori = atoi(argv[2]);
    pthread_t arrayLettori[numeroLettori];
    pthread_t arrayFiltratori[numeroFiltratori];   

    char stringa[20];
    strcpy(stringa,argv[1]);

    shared *condiviso = malloc(sizeof(shared));

    condiviso->filtriAttivi = numeroFiltratori;
    condiviso->lettoriAttivi = numeroLettori;
    condiviso->numeroElementi = 0;
    condiviso->numeroFiltrati = 0;
    pthread_mutex_init(&condiviso->mutexGrezzo,NULL);
    pthread_mutex_init(&condiviso->mutexFiltrato,NULL);
    sem_init(&condiviso->semaforoLiberi,0,10);
    sem_init(&condiviso->semaforoOccupati,0,0);
    sem_init(&condiviso->semaforoLiberiFiltrato,0,5);
    sem_init(&condiviso->semaforoOccupatiFiltrato,0,0);

    condiviso->severity = severitaNumero(stringa);
    printf("[MAIN] Severità: %s(%d).\n",stringa,condiviso->severity);

    printf("[MAIN] Creazione di %d thread Lettori e %d thread Filtratori.\n",numeroLettori,numeroFiltratori);

    for(int i = 0; i < numeroLettori;i++){
        datiLettori *dati = malloc(sizeof(datiLettori));
        dati->id = i;
        dati->nomeFile = argv[i+3];
        dati->condivisione = condiviso;
        pthread_create(&arrayLettori[i],NULL,gestioneLettura,dati);
    }

    for(int i = 0; i < numeroFiltratori; i++){
        datiFiltratori *dati = malloc(sizeof(datiFiltratori));
        dati->id = i;
        dati->condivisione = condiviso;
        pthread_create(&arrayFiltratori[i],NULL,gestioneFiltro,dati);
    }
    

    //estrazione nel main


    for(int i = 0; i < numeroLettori; i++){
        pthread_join(arrayLettori[i],NULL);
    }

    for(int i = 0; i < numeroFiltratori; i++){
        pthread_join(arrayFiltratori[i],NULL);
    }


}