#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct{

    int *vettore;
    int round;

}vettoreGenerato;

typedef struct{

    vettoreGenerato *codaProposte[5];
    int numeroElementi;
    pthread_mutex_t mutexProposte;
    sem_t semaforoProposteLiberi;
    sem_t semaforoProposteOccupati;

    vettoreGenerato *codaScartati[5];
    int numeroElementiScartati;
    pthread_mutex_t mutexScartati;
    sem_t semaforoScartatiLiberi;
    sem_t semaforoScartatiOccupati;  
    
    int numeroVettori;
    int numeroElementiVettori;

}shared;

typedef struct{

    int id;
    shared *condivisione;

}datiThread;

void *gestioneRiparazione(void *arg){
    datiThread *dati = (datiThread*)arg;
    printf("Entrano i riparatori.\n");



}

void *gestioneGenerazione(void *arg){
    datiThread *dati = (datiThread*)arg;
    printf("Entra il generatore.\n");

}

void *gestioneVerifica(void *arg){
    datiThread *dati = (datiThread*)arg;
    printf("Entra il verificatore.\n");

}


int main(int argc, char *argv[]){

    if(argc < 4){
        fprintf(stderr,"Errore devi avviarmi con: <N> <T> <R>.\n");
        exit(EXIT_FAILURE);
    }

    int numeroE = atoi(argv[1]);
    int numeroV = atoi(argv[2]);
    int numeroRiparatori = atoi(argv[3]);

    pthread_t arrayRiparatori[numeroRiparatori];
    pthread_t generatore,verificatore;

    shared *condiviso = malloc(sizeof(shared));
    condiviso->numeroElementi = 0;
    condiviso->numeroElementiScartati = 0;
    condiviso->numeroElementiVettori = numeroE;
    condiviso->numeroVettori = numeroV;
    pthread_mutex_init(&condiviso->mutexProposte,NULL);
    pthread_mutex_init(&condiviso->mutexScartati,NULL);
    sem_init(&condiviso->semaforoProposteLiberi,0,5);
    sem_init(&condiviso->semaforoProposteOccupati,0,0);
    sem_init(&condiviso->semaforoScartatiLiberi,0,5);
    sem_init(&condiviso->semaforoScartatiOccupati,0,0);    

    for(int i = 0; i < numeroRiparatori; i++){
        datiThread *dati = malloc(sizeof(datiThread));
        dati->condivisione = condiviso;
        dati->id = i+1;
        pthread_create(&arrayRiparatori[i],NULL,gestioneRiparazione,dati);
    }

    datiThread *datiGeneratore = malloc(sizeof(datiThread));
    datiGeneratore->condivisione = condiviso;
    datiGeneratore->id = 0;
    pthread_create(&generatore,NULL,gestioneGenerazione,datiGeneratore);

    datiThread *datiVerificatore = malloc(sizeof(datiThread));
    datiVerificatore->condivisione = condiviso;
    datiVerificatore->id = 0;
    pthread_create(&verificatore,NULL,gestioneVerifica,datiVerificatore);


    for(int i = 0; i < numeroRiparatori; i++){
        pthread_join(arrayRiparatori[i],NULL);
    }

    pthread_join(generatore,NULL);
    pthread_join(verificatore,NULL);

    printf("[MAIN] terminazione.\n");
    pthread_mutex_destroy(&condiviso->mutexProposte);
    pthread_mutex_destroy(&condiviso->mutexScartati);
    sem_destroy(&condiviso->semaforoProposteLiberi);
    sem_destroy(&condiviso->semaforoProposteOccupati);
    sem_destroy(&condiviso->semaforoScartatiLiberi);
    sem_destroy(&condiviso->semaforoScartatiOccupati);
    free(condiviso);

}