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
    int numeroFiltratoriThread;
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

bool isSevere(valoriRecord *valoriEstratti, shared *condiviso){

    if(valoriEstratti->severita >= condiviso->severity){
        return true;
    }else{
        return false;
    }

}

void *gestioneLettura(void *arg){
    datiLettori *dati = (datiLettori*)arg;
    //printf("Entrano i lettori.\n");

    char stringa[150] = {0};

    FILE *fileLettura = fopen(dati->nomeFile,"r");
    if(fileLettura == NULL){
        perror("Errore nell'apertura del file.\n");
        exit(EXIT_FAILURE);
    }else{
        printf("File '%s'.\n",dati->nomeFile);
    }
    int contatore = 1;
    while (fscanf(fileLettura, "%149[^\n]\n", stringa) == 1){

        char *tempo;
        char *severity; //mi serve da passare alla funzione per farmi restituire l'int
        int severita1;
        char *buffer1;

        tempo = strtok(stringa,"|");
        severity = strtok(NULL,"|");
        buffer1 = strtok(NULL,"|\r\n");

        severita1 = severitaNumero(severity);
        //printf("\nseverita %d\n",severita);

        sem_wait(&dati->condivisione->semaforoLiberi);
        pthread_mutex_lock(&dati->condivisione->mutexGrezzo);
        
        valoriRecord *valori = calloc(1,sizeof(valoriRecord));
        strcpy(valori->timestamp,tempo);
        valori->severita = severita1;
        strcpy(valori->buffer,buffer1);
    
        printf("[READER %d] riga di log n.%d : %s|%s|%s\n",dati->id,contatore,valori->timestamp,severity,valori->buffer);
        contatore++;

        dati->condivisione->codaGrezza[dati->condivisione->numeroElementi] = valori;
        dati->condivisione->numeroElementi++;

        pthread_mutex_unlock(&dati->condivisione->mutexGrezzo);
        sem_post(&dati->condivisione->semaforoOccupati);

    }

    //inserimento sentinella
    pthread_mutex_lock(&dati->condivisione->mutexGrezzo);
    dati->condivisione->lettoriAttivi--;
    printf("[READER %d] HO FINITO.\n",dati->id);
    if(dati->condivisione->lettoriAttivi == 0){
        pthread_mutex_unlock(&dati->condivisione->mutexGrezzo);
        //inserisco R sentinelle
        for(int i = 0; i < dati->numeroFiltratoriThread;i++){
            sem_wait(&dati->condivisione->semaforoLiberi);
            pthread_mutex_lock(&dati->condivisione->mutexGrezzo);

            valoriRecord *valori = malloc(sizeof(valoriRecord));
            valori->severita = -1;
            dati->condivisione->codaGrezza[dati->condivisione->numeroElementi] = valori;
            dati->condivisione->numeroElementi++;

            pthread_mutex_unlock(&dati->condivisione->mutexGrezzo);
            sem_post(&dati->condivisione->semaforoOccupati);
        }
        fclose(fileLettura);
        free(dati);
        return NULL;
    }
    pthread_mutex_unlock(&dati->condivisione->mutexGrezzo);

    fclose(fileLettura);
    free(dati);
    return NULL;

}

void *gestioneFiltro(void *arg){
    datiFiltratori *dati = (datiFiltratori*)arg;
    //printf("Entrano i filtratori.\n");

    while(true){

        //fase di estrazione
        valoriRecord *valoriEstratti = calloc(1,sizeof(valoriRecord));
        memset(valoriEstratti,0,sizeof(valoriRecord));
        sem_wait(&dati->condivisione->semaforoOccupati);
        pthread_mutex_lock(&dati->condivisione->mutexGrezzo);

        strcpy(valoriEstratti->timestamp,dati->condivisione->codaGrezza[0]->timestamp);
        strcpy(valoriEstratti->buffer,dati->condivisione->codaGrezza[0]->buffer);
        valoriEstratti->severita = dati->condivisione->codaGrezza[0]->severita;

        free(dati->condivisione->codaGrezza[0]);
        for(int i = 1; i < dati->condivisione->numeroElementi; i++){
            dati->condivisione->codaGrezza[i-1] = dati->condivisione->codaGrezza[i]; 
        }
        dati->condivisione->numeroElementi--;

        pthread_mutex_unlock(&dati->condivisione->mutexGrezzo);
        sem_post(&dati->condivisione->semaforoLiberi);

        if(valoriEstratti->severita == -1){
            printf("[VERIF %d] HO FINITO.\n",dati->id);
            pthread_mutex_lock(&dati->condivisione->mutexFiltrato);
            dati->condivisione->filtriAttivi--;
            if(dati->condivisione->filtriAttivi == 0){
                pthread_mutex_unlock(&dati->condivisione->mutexFiltrato);
                //inserisco la sentinella nella coda filtrata per il main
                sem_wait(&dati->condivisione->semaforoLiberiFiltrato);
                pthread_mutex_lock(&dati->condivisione->mutexFiltrato);

                dati->condivisione->codaFiltrata[dati->condivisione->numeroFiltrati] = valoriEstratti;
                dati->condivisione->numeroFiltrati++;

                pthread_mutex_unlock(&dati->condivisione->mutexFiltrato);
                sem_post(&dati->condivisione->semaforoOccupatiFiltrato);
                
                return NULL;
            }
            pthread_mutex_unlock(&dati->condivisione->mutexFiltrato);
            return NULL;
        }else if(isSevere(valoriEstratti,dati->condivisione)){
            //inserisco in coda filtrata
            sem_wait(&dati->condivisione->semaforoLiberiFiltrato);
            pthread_mutex_lock(&dati->condivisione->mutexFiltrato);

            dati->condivisione->codaFiltrata[dati->condivisione->numeroFiltrati] = valoriEstratti;
            dati->condivisione->numeroFiltrati++;
            printf("[VERIF %d] verifico riga: %s|%d|%s .\n",dati->id,valoriEstratti->timestamp,valoriEstratti->severita,valoriEstratti->buffer);

            pthread_mutex_unlock(&dati->condivisione->mutexFiltrato);
            sem_post(&dati->condivisione->semaforoOccupatiFiltrato);
        }else{
            free(valoriEstratti);
        }

    }


    

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
        dati->numeroFiltratoriThread = numeroFiltratori;
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
    int debug = 0,info = 0,warning = 0,error = 0,critical = 0;
    while(true){

        valoriRecord *valoriEstratti = calloc(1,sizeof(valoriRecord));
        memset(valoriEstratti,0,sizeof(valoriRecord));
        sem_wait(&condiviso->semaforoOccupatiFiltrato);
        pthread_mutex_lock(&condiviso->mutexFiltrato);

        strcpy(valoriEstratti->timestamp,condiviso->codaFiltrata[0]->timestamp);
        strcpy(valoriEstratti->buffer,condiviso->codaFiltrata[0]->buffer);
        valoriEstratti->severita = condiviso->codaFiltrata[0]->severita;

        free(condiviso->codaFiltrata[0]);
        for(int i = 1; i < condiviso->numeroFiltrati; i++){
            condiviso->codaFiltrata[i-1] = condiviso->codaFiltrata[i]; 
        }
        condiviso->numeroFiltrati--;

        pthread_mutex_unlock(&condiviso->mutexFiltrato);
        sem_post(&condiviso->semaforoLiberiFiltrato);

        if(valoriEstratti->severita == -1){
            free(valoriEstratti);
            break;
        }else{
            printf("[MAIN] ricevuta riga >= a %s.\n",stringa);
            
            if(valoriEstratti->severita == 0){
                debug++;;
            }else if(valoriEstratti->severita == 1){
                info++;;
            }else if(valoriEstratti->severita == 2){
                warning++;
            }else if(valoriEstratti->severita == 3){
                error++;
            }else if(valoriEstratti->severita == 4){
                critical++;
            }
            free(valoriEstratti);
        }

    }
    printf("\nTOTALE VALORI TROVATI: DEBUG %d, INFO %d, WARNING %d, ERROR %d, CRITICAL %d.\n",debug,info,warning,error,critical);
    printf("\nTERMINAZIONE.\n");

    for(int i = 0; i < numeroLettori; i++){
        pthread_join(arrayLettori[i],NULL);
    }

    for(int i = 0; i < numeroFiltratori; i++){
        pthread_join(arrayFiltratori[i],NULL);
    }

    pthread_mutex_destroy(&condiviso->mutexFiltrato);
    pthread_mutex_destroy(&condiviso->mutexGrezzo);
    sem_destroy(&condiviso->semaforoLiberi);
    sem_destroy(&condiviso->semaforoLiberiFiltrato);
    sem_destroy(&condiviso->semaforoOccupati);
    sem_destroy(&condiviso->semaforoOccupatiFiltrato);
    
    free(condiviso);
    return 0;

}