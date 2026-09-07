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

    int tensione;
    int corrente;
    int temperatura;

}valoriPila;

typedef struct{

    valoriPila *codaIntermedia[8];
    pthread_mutex_t mutexIntermedia;
    sem_t semaforoLiberi;
    sem_t semaforoOccupati;
    int elementiPresenti;
    int lettoriAttivi;

    valoriPila *pilaFinale[5];
    pthread_mutex_t mutexFinale;
    sem_t semaforoLiberiFinale;
    sem_t semaforoOccupatiFinale;
    int top;
    int analistiAttivi;


}shared;

typedef struct{

    int id;
    char *nomeFile;
    shared *condivisione;
    int numeroAnalistiAttivi;

}datiLettori;

typedef struct{

    int id;
    shared *condivisione;

}datiAnalisti;

bool isOpt(valoriPila *valoriEstratti){
    //printf("Misurazione.\n");

    int potenza = valoriEstratti->tensione * valoriEstratti->corrente;
    if(potenza > 1000 && valoriEstratti->temperatura < 40){
        return true;
    }else{
        return false;
    }

}

void *gestioneLettura(void *arg){

    datiLettori *dati = (datiLettori*)arg;
    //printf("Entrano i lettori.\n");

    FILE *fileLettura = fopen(dati->nomeFile,"r");
    if(fileLettura == NULL){
        perror("Errore nell'apertura del file.\n");
        exit(EXIT_FAILURE);
    }else{
        printf("[READER %d] file '%s'.\n",dati->id,dati->nomeFile);
    }

    int tension, current, temperature;
    int contatore = 0;
    while (fscanf(fileLettura, "%d,%d,%d", &tension, &current, &temperature) == 3) {
        //fase di inserimento
        sem_wait(&dati->condivisione->semaforoLiberi);
        pthread_mutex_lock(&dati->condivisione->mutexIntermedia);
        contatore++;
        dati->condivisione->codaIntermedia[dati->condivisione->elementiPresenti] = malloc(sizeof(valoriPila));
        dati->condivisione->codaIntermedia[dati->condivisione->elementiPresenti]->tensione = tension;
        dati->condivisione->codaIntermedia[dati->condivisione->elementiPresenti]->corrente = current;
        dati->condivisione->codaIntermedia[dati->condivisione->elementiPresenti]->temperatura = temperature;
        printf("[READER %d] lettura candidata n.%d: V %d, I %d, T %d.\n",dati->id,contatore,dati->condivisione->codaIntermedia[dati->condivisione->elementiPresenti]->tensione,dati->condivisione->codaIntermedia[dati->condivisione->elementiPresenti]->corrente,dati->condivisione->codaIntermedia[dati->condivisione->elementiPresenti]->temperatura);
        dati->condivisione->elementiPresenti++;

        pthread_mutex_unlock(&dati->condivisione->mutexIntermedia);
        sem_post(&dati->condivisione->semaforoOccupati);

    }

    //file finito

    pthread_mutex_lock(&dati->condivisione->mutexIntermedia);
    dati->condivisione->lettoriAttivi--;
    printf("[READER %d] HO FINITO.\n",dati->id);
    if(dati->condivisione->lettoriAttivi == 0){
        pthread_mutex_unlock(&dati->condivisione->mutexIntermedia);

        for(int i = 0; i < dati->numeroAnalistiAttivi; i++){
            sem_wait(&dati->condivisione->semaforoLiberi);
            pthread_mutex_lock(&dati->condivisione->mutexIntermedia);
    
            dati->condivisione->codaIntermedia[dati->condivisione->elementiPresenti] = malloc(sizeof(valoriPila));
            dati->condivisione->codaIntermedia[dati->condivisione->elementiPresenti]->tensione = -1;
            dati->condivisione->codaIntermedia[dati->condivisione->elementiPresenti]->corrente = -1;
            dati->condivisione->codaIntermedia[dati->condivisione->elementiPresenti]->temperatura = -1;
            dati->condivisione->elementiPresenti++;
    
            pthread_mutex_unlock(&dati->condivisione->mutexIntermedia);
            sem_post(&dati->condivisione->semaforoOccupati);  
        }
    }
    pthread_mutex_unlock(&dati->condivisione->mutexIntermedia);

    fclose(fileLettura);
    return NULL;

}

void *gestioneAnalisi(void *arg){

    datiAnalisti *dati = (datiAnalisti*)arg;
    //printf("Entrano gli analisti.\n");

    while(true){
        valoriPila *valoriEstratti = malloc(sizeof(valoriPila));
        sem_wait(&dati->condivisione->semaforoOccupati);
        pthread_mutex_lock(&dati->condivisione->mutexIntermedia);

        valoriEstratti->tensione = dati->condivisione->codaIntermedia[0]->tensione;
        valoriEstratti->corrente = dati->condivisione->codaIntermedia[0]->corrente;
        valoriEstratti->temperatura = dati->condivisione->codaIntermedia[0]->temperatura;
        printf("[ANALIST %d] verifico misurazione: V %d, I %d, T %d.\n",dati->id,valoriEstratti->tensione,valoriEstratti->corrente,valoriEstratti->temperatura);
        for(int i = 1; i < dati->condivisione->elementiPresenti; i++){
            dati->condivisione->codaIntermedia[i-1] = dati->condivisione->codaIntermedia[i];
        }
        dati->condivisione->elementiPresenti--;

        pthread_mutex_unlock(&dati->condivisione->mutexIntermedia);
        sem_post(&dati->condivisione->semaforoLiberi);

        if(valoriEstratti->tensione == -1){
            pthread_mutex_lock(&dati->condivisione->mutexFinale);
            dati->condivisione->analistiAttivi--;
            printf("[ANALIST %d] HO FINITO.\n",dati->id);
            if(dati->condivisione->analistiAttivi == 0){
                pthread_mutex_unlock(&dati->condivisione->mutexFinale);
                //inserisco sentinella nella pila per il main
                sem_wait(&dati->condivisione->semaforoLiberiFinale);
                pthread_mutex_lock(&dati->condivisione->mutexFinale);

                dati->condivisione->pilaFinale[dati->condivisione->top] = malloc(sizeof(valoriPila));
                dati->condivisione->pilaFinale[dati->condivisione->top]->tensione = -1;
                dati->condivisione->pilaFinale[dati->condivisione->top]->corrente = -1;
                dati->condivisione->pilaFinale[dati->condivisione->top]->temperatura = -1;
                dati->condivisione->top++;

                pthread_mutex_unlock(&dati->condivisione->mutexFinale);
                sem_post(&dati->condivisione->semaforoOccupatiFinale);

                free(valoriEstratti);
                return NULL;
            }
            pthread_mutex_unlock(&dati->condivisione->mutexFinale);
            
            free(valoriEstratti);
            return NULL;
        }else if(isOpt(valoriEstratti)){
            //inserisco il valore ottimale nella pila
            sem_wait(&dati->condivisione->semaforoLiberiFinale);
            pthread_mutex_lock(&dati->condivisione->mutexFinale);

            dati->condivisione->pilaFinale[dati->condivisione->top] = malloc(sizeof(valoriPila));
            dati->condivisione->pilaFinale[dati->condivisione->top]->tensione = valoriEstratti->tensione;
            dati->condivisione->pilaFinale[dati->condivisione->top]->corrente = valoriEstratti->corrente;
            dati->condivisione->pilaFinale[dati->condivisione->top]->temperatura = valoriEstratti->temperatura;
            dati->condivisione->top++;
            free(valoriEstratti);
            pthread_mutex_unlock(&dati->condivisione->mutexFinale);
            sem_post(&dati->condivisione->semaforoOccupatiFinale);
        }

    }

}

int main(int argc, char *argv[]){
    
    if(argc < 3){
        perror("Errore devi avviarmi con <M-analysts> <file1> ... <fileN>.");
        exit(EXIT_FAILURE);
    }

    int numeroLettori = argc - 2;
    int numeroAnalisti = atoi(argv[1]);

    shared *condiviso = malloc(sizeof(shared));

    condiviso->analistiAttivi = numeroAnalisti;
    condiviso->lettoriAttivi = numeroLettori;
    condiviso->elementiPresenti = 0;
    condiviso->top = 0;

    pthread_mutex_init(&condiviso->mutexIntermedia,NULL);
    pthread_mutex_init(&condiviso->mutexFinale,NULL);

    sem_init(&condiviso->semaforoLiberi,0,8);
    sem_init(&condiviso->semaforoOccupati,0,0);
    
    sem_init(&condiviso->semaforoLiberiFinale,0,5);
    sem_init(&condiviso->semaforoOccupatiFinale,0,0);

    pthread_t arrayLettori[numeroLettori];
    pthread_t arrayAnalisti[numeroAnalisti];

    for(int i = 0; i < numeroLettori; i++){
        datiLettori *dati = malloc(sizeof(datiLettori));
        dati->condivisione = condiviso;
        dati->id = i;
        dati->nomeFile = argv[i+2];
        dati->numeroAnalistiAttivi = numeroAnalisti;
        pthread_create(&arrayLettori[i],NULL,gestioneLettura,dati);
    }

    for(int i = 0; i < numeroAnalisti; i++){
        datiAnalisti *dati = malloc(sizeof(datiAnalisti));
        dati->id = i;
        dati->condivisione = condiviso;
        pthread_create(&arrayAnalisti[i],NULL,gestioneAnalisi,dati);
    }

    //estraggo dalla pila finale
    int contatorePotenza = 0;
    while(true){
        valoriPila *valoriEstratti = malloc(sizeof(valoriPila));

        sem_wait(&condiviso->semaforoOccupatiFinale);
        pthread_mutex_lock(&condiviso->mutexFinale);

        condiviso->top--;
        valoriEstratti->tensione = condiviso->pilaFinale[condiviso->top]->tensione;
        valoriEstratti->corrente = condiviso->pilaFinale[condiviso->top]->corrente;
        valoriEstratti->temperatura = condiviso->pilaFinale[condiviso->top]->temperatura;
        if(valoriEstratti->tensione == -1){
            pthread_mutex_unlock(&condiviso->mutexFinale);
            sem_post(&condiviso->semaforoLiberiFinale);
            break;
        }
        printf("[MAIN] misurazione ottimale registrata: V %d, I %d, T %d.\n",valoriEstratti->tensione,valoriEstratti->corrente,valoriEstratti->temperatura);
        contatorePotenza = contatorePotenza + (valoriEstratti->tensione * valoriEstratti->corrente);
        pthread_mutex_unlock(&condiviso->mutexFinale);
        sem_post(&condiviso->semaforoLiberiFinale);
        free(valoriEstratti);
    }

    for(int i = 0; i < numeroLettori; i++){
        pthread_join(arrayLettori[i],NULL);
    }

    for(int i = 0; i < numeroAnalisti; i++){
        pthread_join(arrayAnalisti[i],NULL);
    }
   
    printf("\n[MAIN] potenza totale ottimale: %dW.\n",contatorePotenza);
    printf("[MAIN] terminazione.");
    pthread_mutex_destroy(&condiviso->mutexFinale);
    pthread_mutex_destroy(&condiviso->mutexIntermedia);
    sem_destroy(&condiviso->semaforoLiberi);
    sem_destroy(&condiviso->semaforoLiberiFinale);
    sem_destroy(&condiviso->semaforoOccupati);
    sem_destroy(&condiviso->semaforoOccupatiFinale);
    free(condiviso);
    return 0;
}