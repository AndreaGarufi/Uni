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

bool isEqui(vettoreGenerato *elemento){
    return false;
}

void *gestioneGenerazione(void *arg){
    datiThread *dati = (datiThread*)arg;
    //printf("Entra il generatore.\n");

    int vettoriDaGenerare = dati->condivisione->numeroVettori;
    int dimensioneVettore = dati->condivisione->numeroElementiVettori;
    for(int i = 0; i < vettoriDaGenerare; i++){
        vettoreGenerato *array = malloc(sizeof(vettoreGenerato));
        array->vettore = calloc(1,sizeof(int)*dimensioneVettore);
        for(int j = 0; j < dimensioneVettore; j++){
            array->vettore[j] = rand() % (99 - 0 + 1) + 0;
        }
        array->round = i+1;
        sem_wait(&dati->condivisione->semaforoProposteLiberi);
        pthread_mutex_lock(&dati->condivisione->mutexProposte);

        dati->condivisione->codaProposte[dati->condivisione->numeroElementi] = array;
        printf("[GEN] vettore candidato numero %d: ",dati->condivisione->codaProposte[dati->condivisione->numeroElementi]->round);
        for(int k = 0; k < dimensioneVettore; k++){
            printf("%d ",dati->condivisione->codaProposte[dati->condivisione->numeroElementi]->vettore[k]);
        }
        printf("\n");
        dati->condivisione->numeroElementi++;

        pthread_mutex_unlock(&dati->condivisione->mutexProposte);
        sem_post(&dati->condivisione->semaforoProposteOccupati);

    }

    //poison pill


}

void *gestioneVerifica(void *arg){
    datiThread *dati = (datiThread*)arg;
    //printf("Entra il verificatore.\n");

    int vettoriDaGenerare = dati->condivisione->numeroVettori;
    int dimensioneVettore = dati->condivisione->numeroElementiVettori;
    int contatore = 0;
    vettoreGenerato *elementoEstratto;
    while(true){

        sem_wait(&dati->condivisione->semaforoProposteOccupati);
        pthread_mutex_lock(&dati->condivisione->mutexProposte);

        elementoEstratto = dati->condivisione->codaProposte[0];
        for(int j = 1; j < dati->condivisione->numeroElementi; j++){
            dati->condivisione->codaProposte[j-1] =  dati->condivisione->codaProposte[j];
        }
        dati->condivisione->numeroElementi--;

        pthread_mutex_unlock(&dati->condivisione->mutexProposte);
        sem_post(&dati->condivisione->semaforoProposteLiberi);

        printf("[VERIF] estratto un vettore candidato con round pari a %d: ",elementoEstratto->round);
        for(int j = 0; j < dimensioneVettore; j++){
            printf("%d ",elementoEstratto->vettore[j]);
        }
        printf("\n");

        if(isEqui(elementoEstratto)){
            contatore++;
            printf("[VERIF] vettore verificato e accettato dopo %d aggiustamenti (%d/10).\n",elementoEstratto->round,contatore);
        }else{
            
            sem_wait(&dati->condivisione->semaforoScartatiLiberi);
            pthread_mutex_lock(&dati->condivisione->mutexScartati);
            
            dati->condivisione->codaScartati[dati->condivisione->numeroElementiScartati] = elementoEstratto;
            dati->condivisione->numeroElementiScartati++;
            printf("[VERIF] vettore non verificato e rigettato");

            pthread_mutex_unlock(&dati->condivisione->mutexScartati);
            sem_post(&dati->condivisione->semaforoScartatiOccupati);
        }

    }

}

void *gestioneRiparazione(void *arg){
    datiThread *dati = (datiThread*)arg;
    //printf("Entrano i riparatori.\n");

    int vettoriDaGenerare = dati->condivisione->numeroVettori;
    int dimensioneVettore = dati->condivisione->numeroElementiVettori;

    while(true){
        vettoreGenerato *elementoEstratto;
        sem_wait(&dati->condivisione->semaforoScartatiOccupati);
        pthread_mutex_lock(&dati->condivisione->mutexScartati);

        elementoEstratto = dati->condivisione->codaScartati[0];
        for(int i = 1; i < dimensioneVettore; i++){
            dati->condivisione->codaScartati[i-1] = dati->condivisione->codaScartati[i];
        }
        dati->condivisione->numeroElementiScartati--;

        printf("[REP-%d] estratto un vettore da riparare:",dati->id);
        for(int i = 0; i < dimensioneVettore; i++){
            printf("%d ",elementoEstratto->vettore[i]);
        }
        printf("\n");
        pthread_mutex_unlock(&dati->condivisione->mutexScartati);
        sem_post(&dati->condivisione->semaforoScartatiLiberi);

        if(elementoEstratto->round == -1){
            return NULL;
        }

        elementoEstratto->round++;
        int numeroDaCambiare = rand() % (dimensioneVettore - 0 + 1) + 0;
        int numeroNuovo = rand() % (99 - 0 + 1) + 0;
        int numeroVecchio = elementoEstratto->vettore[numeroDaCambiare];
        elementoEstratto->vettore[numeroDaCambiare] = numeroNuovo;

        sem_wait(&dati->condivisione->semaforoScartatiLiberi);
        pthread_mutex_lock(&dati->condivisione->mutexScartati);

        dati->condivisione->codaScartati[dati->condivisione->numeroElementiScartati] = elementoEstratto;
        dati->condivisione->numeroElementiScartati++;
        printf("[REP-%d] reinserito vettore riparato (%d->%d) con round pari a %d.\n",dati->id,numeroVecchio,numeroNuovo,elementoEstratto->round);
        
        pthread_mutex_unlock(&dati->condivisione->mutexScartati);
        sem_post(&dati->condivisione->semaforoScartatiOccupati);
    
    }



}



int main(int argc, char *argv[]){

    if(argc < 4){
        fprintf(stderr,"Errore devi avviarmi con: <N> <T> <R>.\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

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

    printf("[MAIN] creazione di un thread generatore, di un thread verificatore e di %d thread riparatori",numeroRiparatori);

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