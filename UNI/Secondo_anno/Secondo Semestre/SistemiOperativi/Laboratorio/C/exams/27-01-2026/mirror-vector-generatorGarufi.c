#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <time.h>
#include <stdbool.h>

typedef struct{

    int *vettore;
    int round;

}vettoreGenerato;

typedef struct{

    vettoreGenerato *codaProposte[20];
    int numeroElementi;
    pthread_mutex_t mutexProposte;
    sem_t semaforoProposteLiberi;
    sem_t semaforoProposteOccupati;

    vettoreGenerato *codaScartati[20];
    int numeroElementiScartati;
    pthread_mutex_t mutexScartati;
    sem_t semaforoScartatiLiberi;
    sem_t semaforoScartatiOccupati;    

    int numeroVettori;
    int dimensioneVettori;

    int contatore;
    pthread_mutex_t mutexContatore;

    int numeroVerificatori;
}shared;

typedef struct{

    int id;
    shared *condivisione;

}datiThread;


bool isMirr(vettoreGenerato *elemento, datiThread *dati){
    
    int somma1 = 0,somma2 = 0;
    for(int i = 0; i < dati->condivisione->dimensioneVettori/2; i++){
        somma1 = somma1 + elemento->vettore[i];
    }
    printf("\n");
    for(int i = dati->condivisione->dimensioneVettori/2; i < dati->condivisione->dimensioneVettori; i++){
        somma2 = somma2 + elemento->vettore[i]; 
    }

    if(somma1 == somma2){
        return true;
    }else{
        return false;
    }
}

void *gestioneGenerazione(void *arg){
    datiThread *dati = (datiThread*)arg;
    //printf("Entra il generatore.\n");

    int numeroVettoriDaGenerare = dati->condivisione->numeroVettori;
    int dimensione = dati->condivisione->dimensioneVettori;

    for(int i = 0; i < numeroVettoriDaGenerare; i++){
        vettoreGenerato *elementoGenerato = malloc(sizeof(vettoreGenerato));
        elementoGenerato->round = 0;
        elementoGenerato->vettore = malloc(sizeof(int) *dimensione);

        for(int j = 0; j < dimensione; j++){
            elementoGenerato->vettore[j] = rand() % (99 - 0 + 1) + 0;
        }

        sem_wait(&dati->condivisione->semaforoProposteLiberi);
        pthread_mutex_lock(&dati->condivisione->mutexProposte);
        
        dati->condivisione->codaProposte[dati->condivisione->numeroElementi] = elementoGenerato;
        printf("[GEN] vettore candidato numero %d: ",i+1);
        for(int j = 0; j < dimensione; j++){
            printf("%d ",dati->condivisione->codaProposte[dati->condivisione->numeroElementi]->vettore[j]);
        }
        printf("\n");
        dati->condivisione->numeroElementi++;

        pthread_mutex_unlock(&dati->condivisione->mutexProposte);
        sem_post(&dati->condivisione->semaforoProposteOccupati);


    }
    printf("[GEN] terminato.\n");
    return NULL;
}

void *gestioneVerifica(void *arg){
    datiThread *dati = (datiThread*)arg;
    //printf("Entrano i verificatori.\n");

    int numeroVettoriDaGenerare = dati->condivisione->numeroVettori;
    int dimensione = dati->condivisione->dimensioneVettori;
    bool esci = false;
    //int contatore = 0;
    while(true){

        vettoreGenerato *elementoEstratto;

        sem_wait(&dati->condivisione->semaforoProposteOccupati);
        pthread_mutex_lock(&dati->condivisione->mutexProposte);

        elementoEstratto = dati->condivisione->codaProposte[0];
        for(int i = 1; i < dati->condivisione->numeroElementi; i++){
            dati->condivisione->codaProposte[i-1] = dati->condivisione->codaProposte[i];
        }
        dati->condivisione->numeroElementi--;

        if(elementoEstratto->round == -2){
            pthread_mutex_unlock(&dati->condivisione->mutexProposte);
            sem_post(&dati->condivisione->semaforoProposteLiberi);
            printf("[VERIF-%d] terminato.\n",dati->id);
            free(elementoEstratto);
            return NULL;
        }

        printf("[VERIF-%d] estratto un vettore candidato con round pari a %d: ",dati->id,elementoEstratto->round);
        for(int i = 0; i < dimensione; i++){
            printf("%d ",elementoEstratto->vettore[i]);
        }
        //printf("\n");
        pthread_mutex_unlock(&dati->condivisione->mutexProposte);
        sem_post(&dati->condivisione->semaforoProposteLiberi);


        if(isMirr(elementoEstratto,dati)){
            pthread_mutex_lock(&dati->condivisione->mutexContatore);
            dati->condivisione->contatore++;
            
            printf("[VERIF-%d] vettore verificato e accettato dopo %d round di aggiustamenti (%d di %d).\n",dati->id,elementoEstratto->round,dati->condivisione->contatore,dati->condivisione->numeroVettori);
            
            if(dati->condivisione->contatore == numeroVettoriDaGenerare){
                esci = true;
            }
            pthread_mutex_unlock(&dati->condivisione->mutexContatore);

            if(esci == true){

                for(int i = 0; i < 3; i++){
                vettoreGenerato *sentinella = calloc(1,sizeof(vettoreGenerato));
                sentinella->round = -1;

                sem_wait(&dati->condivisione->semaforoScartatiLiberi);
                pthread_mutex_lock(&dati->condivisione->mutexScartati);
                        
                dati->condivisione->codaScartati[dati->condivisione->numeroElementiScartati] = sentinella;
                dati->condivisione->numeroElementiScartati++;

                pthread_mutex_unlock(&dati->condivisione->mutexScartati);
                sem_post(&dati->condivisione->semaforoScartatiOccupati);                    
                }

                for(int i = 0; i < 2; i++){
                    vettoreGenerato *sentinella = calloc(1,sizeof(vettoreGenerato));  
                    sentinella->round = -2;  

                    sem_wait(&dati->condivisione->semaforoProposteLiberi);
                    pthread_mutex_lock(&dati->condivisione->mutexProposte);
                    
                    dati->condivisione->codaProposte[dati->condivisione->numeroElementi] = sentinella;
                    dati->condivisione->numeroElementi++;

                    pthread_mutex_unlock(&dati->condivisione->mutexProposte);
                    sem_post(&dati->condivisione->semaforoProposteOccupati);                    
                }
                printf("[VERIF-%d] terminato.\n",dati->id);
                return NULL;
            }
            free(elementoEstratto);
        }else{
            
            sem_wait(&dati->condivisione->semaforoScartatiLiberi);
            pthread_mutex_lock(&dati->condivisione->mutexScartati);
            
            dati->condivisione->codaScartati[dati->condivisione->numeroElementiScartati] = elementoEstratto;
            dati->condivisione->numeroElementiScartati++;
            printf("[VERIF-%d] vettore verificato e rigettato.\n",dati->id);

            pthread_mutex_unlock(&dati->condivisione->mutexScartati);
            sem_post(&dati->condivisione->semaforoScartatiOccupati);

        }

    }


}

void *gestioneRiparazione(void *arg){
    datiThread *dati = (datiThread*)arg;
    //printf("Entrano i riparatori.\n");

    int numeroVettoriDaGenerare = dati->condivisione->numeroVettori;
    int dimensione = dati->condivisione->dimensioneVettori;
    
    while(true){

        vettoreGenerato *elementoDaRiparare;

        sem_wait(&dati->condivisione->semaforoScartatiOccupati);
        pthread_mutex_lock(&dati->condivisione->mutexScartati);

        elementoDaRiparare = dati->condivisione->codaScartati[0];
        for(int i = 1; i < dati->condivisione->numeroElementiScartati; i++){
            dati->condivisione->codaScartati[i-1] = dati->condivisione->codaScartati[i];
        }
        dati->condivisione->numeroElementiScartati--;        
        
        pthread_mutex_unlock(&dati->condivisione->mutexScartati);
        sem_post(&dati->condivisione->semaforoScartatiLiberi);

        if(elementoDaRiparare->round == -1){
            printf("[REP-%d] terminato.\n",dati->id);
            return NULL;
        }

        printf("[REP-%d] estratto un vettore da riparare: ",dati->id);
        for(int i = 0; i < dimensione; i++){
            printf("%d ",elementoDaRiparare->vettore[i]);
        }
        printf("\n");
        elementoDaRiparare->round++;

        int MSlot = rand() % dimensione;
        int numeroNuovo = rand() % 100;
        int numeroVecchio = elementoDaRiparare->vettore[MSlot];
        elementoDaRiparare->vettore[MSlot] = numeroNuovo;

        sem_wait(&dati->condivisione->semaforoProposteLiberi);
        pthread_mutex_lock(&dati->condivisione->mutexProposte);

        dati->condivisione->codaProposte[dati->condivisione->numeroElementi] = elementoDaRiparare;

        printf("[REP-%d] reinserito vettore riparato (%d->%d) con round pari a %d: ",dati->id,numeroVecchio,numeroNuovo,dati->condivisione->codaProposte[dati->condivisione->numeroElementi]->round);
        for(int i = 0; i < dimensione; i++){
            printf("%d ",dati->condivisione->codaProposte[dati->condivisione->numeroElementi]->vettore[i]);
        }
        printf("\n");
        dati->condivisione->numeroElementi++;

        pthread_mutex_unlock(&dati->condivisione->mutexProposte);
        sem_post(&dati->condivisione->semaforoProposteOccupati);

    }

}


int main(int argc, char *argv[]){

    if(argc < 3){
        fprintf(stderr,"Errore devi avviarmi con: <N> <M> (con M pari).\n");
        exit(EXIT_FAILURE);
    }
    if(atoi(argv[2]) % 2 != 0){
        fprintf(stderr,"Errore devi avviarmi M pari.\n");
        exit(EXIT_FAILURE);        
    }

    srand(time(NULL));

    pthread_t arrayVerificatori[3];
    pthread_t arrayRiparatori[3];
    pthread_t generatore;  
    
    shared *condiviso = malloc(sizeof(shared));
    condiviso->numeroElementi = 0;
    condiviso->numeroElementiScartati = 0;
    condiviso->numeroVettori = atoi(argv[1]);
    condiviso->dimensioneVettori = atoi(argv[2]);
    condiviso->numeroVerificatori = 3;
    pthread_mutex_init(&condiviso->mutexProposte,NULL);
    pthread_mutex_init(&condiviso->mutexScartati,NULL);
    pthread_mutex_init(&condiviso->mutexContatore,NULL);
    sem_init(&condiviso->semaforoProposteLiberi,0,20);
    sem_init(&condiviso->semaforoProposteOccupati,0,0);
    sem_init(&condiviso->semaforoScartatiLiberi,0,20);
    sem_init(&condiviso->semaforoScartatiOccupati,0,0);

    printf("[MAIN] creazione di un thread generator, di 3 thread verificatore e di 3 thread riparatori.\n");

    for(int i = 0; i < 3; i++){
        datiThread *datiVerificatori = malloc(sizeof(datiThread));
        datiVerificatori->condivisione = condiviso;
        datiVerificatori->id = i+1;
        pthread_create(&arrayVerificatori[i],NULL,gestioneVerifica,datiVerificatori);

        datiThread *datiRiparatori = malloc(sizeof(datiThread));
        datiRiparatori->condivisione = condiviso;
        datiRiparatori->id = i+1;
        pthread_create(&arrayRiparatori[i],NULL,gestioneRiparazione,datiRiparatori);
    }

    datiThread *datiGeneratore = malloc(sizeof(datiThread));
    datiGeneratore->condivisione = condiviso;
    datiGeneratore->id = 0;
    pthread_create(&generatore,NULL,gestioneGenerazione,datiGeneratore);    


    pthread_join(generatore,NULL);

    for(int i = 0; i < 3; i++){
        pthread_join(arrayVerificatori[i],NULL);
        pthread_join(arrayRiparatori[i],NULL);
    }

    printf("[MAIN] terminazione.\n");
    pthread_mutex_destroy(&condiviso->mutexProposte);
    pthread_mutex_destroy(&condiviso->mutexScartati);
    sem_destroy(&condiviso->semaforoProposteLiberi);
    sem_destroy(&condiviso->semaforoProposteOccupati);
    sem_destroy(&condiviso->semaforoScartatiLiberi);
    sem_destroy(&condiviso->semaforoScartatiOccupati);
    free(condiviso);

}
    