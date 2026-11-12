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

    int *codaIntermedia[10];
    int elementiIntermedia;
    pthread_mutex_t mutexIntermedio;
    sem_t semaforoLiberi;
    sem_t semaforoOccupati;
    int lettoriAttivi;

    int *codaFinale[3];
    int elementiFinale;
    pthread_mutex_t mutexFinale;
    sem_t semaforoLiberiFinale;
    sem_t semaforoOccupatiFinale;
    int verificatoriAttivi;

}shared;

typedef struct{

    int id;
    char *nomeFile;
    shared *condivisione;
    int numeroVerificatoriThread;

}datiLettori;

typedef struct{

    int id;
    shared *condivisione;

}datiVerificatori;

bool isMagic(int matrice[]){
    //printf("ENTRA IN MAGICO.\n");
    int somma1,somma2,somma3,somma4,somma5;

    somma1 = matrice[0] + matrice[1] + matrice[2];
    somma2 = matrice[3] + matrice[4] + matrice[5];
    somma3 = matrice[6] + matrice[7] + matrice[8];

    somma4 = matrice[0] + matrice[4] + matrice[8];
    somma5 = matrice[2] + matrice[4] + matrice[6];

    if(somma1 == somma2 && somma1 == somma3 && somma4 == somma5 && somma1 == somma5){
        return true;
    }else{
        return false;
    }

}


void *gestioneLettura(void *arg){

    //printf("ENTRA IN LETTURA.\n");
    datiLettori *dati = (datiLettori*)arg;
    FILE *fileLettura = fopen(dati->nomeFile,"r");
    if(fileLettura == NULL){
        perror("Errore nell'apertura del file.\n");
        exit(EXIT_FAILURE);
    }else{
        printf("[READER %d] file '%s'.\n",dati->id,dati->nomeFile);
    }

    int k = 0;
    while(true){
        int numero;
        int *matrice = malloc(9 * sizeof(int));
        bool flag = false;
        for(int i = 0; i < 9; i++){  
            if((fscanf(fileLettura,"%d,",&numero)) == 1){
                matrice[i] = numero;
                flag = true;
            }else{
                //printf("File FINITO.\n");
                break;
            }
        }
        if(flag == false){
            free(matrice);
            break;
        }
        k++;
        sem_wait(&dati->condivisione->semaforoLiberi);
        pthread_mutex_lock(&dati->condivisione->mutexIntermedio);
        printf("[READER %d] quadrato candidato n.%d: ",dati->id,k);
        for(int i = 0; i < 9; i++){
            printf("%d ",matrice[i]);
        }
        printf("\n");
        dati->condivisione->codaIntermedia[dati->condivisione->elementiIntermedia] = matrice;
        dati->condivisione->elementiIntermedia++;

        pthread_mutex_unlock(&dati->condivisione->mutexIntermedio);
        sem_post(&dati->condivisione->semaforoOccupati);
    }



    pthread_mutex_lock(&dati->condivisione->mutexIntermedio);
    printf("[READER %d] HO FINITO.\n",dati->id);    
    dati->condivisione->lettoriAttivi--;
    if(dati->condivisione->lettoriAttivi == 0){
        //inserisco M sentinelle
        pthread_mutex_unlock(&dati->condivisione->mutexIntermedio);

        for(int i = 0; i < dati->numeroVerificatoriThread; i++){
            sem_wait(&dati->condivisione->semaforoLiberi);
            pthread_mutex_lock(&dati->condivisione->mutexIntermedio);
            int *matriceSentinella = malloc(9 * sizeof(int));

            for(int j = 0; j < 9; j++){
                matriceSentinella[j] = -1;
            }

            dati->condivisione->codaIntermedia[dati->condivisione->elementiIntermedia] = matriceSentinella;
            dati->condivisione->elementiIntermedia++;
    
            pthread_mutex_unlock(&dati->condivisione->mutexIntermedio);
            sem_post(&dati->condivisione->semaforoOccupati);        
        }
        fclose(fileLettura);
        free(dati);
        return NULL;
    }

    pthread_mutex_unlock(&dati->condivisione->mutexIntermedio); 

    fclose(fileLettura);
    free(dati);
    return NULL;

}


void *gestioneVerifica(void *arg){

    //printf("ENTRA IN VERIFICA.\n");
    datiVerificatori *dati = (datiVerificatori*)arg;

    while(true){

        ///////////estrazione elemento////////////////////
        int *matrice;
        sem_wait(&dati->condivisione->semaforoOccupati);
        pthread_mutex_lock(&dati->condivisione->mutexIntermedio);
    
        matrice = dati->condivisione->codaIntermedia[0];
        printf("[VERIF %d] verifico quadrato: ",dati->id);
        for(int i = 0; i < 9; i++){
            printf("%d ",matrice[i]);
        }
        printf("\n");
        for(int i = 1; i < dati->condivisione->elementiIntermedia; i++){
            dati->condivisione->codaIntermedia[i-1] = dati->condivisione->codaIntermedia[i];
        }
        dati->condivisione->elementiIntermedia--;
        
        pthread_mutex_unlock(&dati->condivisione->mutexIntermedio);    
        sem_post(&dati->condivisione->semaforoLiberi);
        /////////////////////////////////////////////////////

        //////////controlli/////////////////////
        if(matrice[0] == -1){
            //valore sentinella
            pthread_mutex_lock(&dati->condivisione->mutexFinale);
            dati->condivisione->verificatoriAttivi--;
            printf("[VERIF %d] HO FINITO.\n",dati->id);
            if(dati->condivisione->verificatoriAttivi == 0){    //qui aggiungo la sentinella alla coda finale
                pthread_mutex_unlock(&dati->condivisione->mutexFinale);

                sem_wait(&dati->condivisione->semaforoLiberiFinale);
                pthread_mutex_lock(&dati->condivisione->mutexFinale);

                int *matriceSentinella = malloc(9 * sizeof(int));

                for(int i = 0; i < 9; i++){
                    matriceSentinella[i] = -1;
                }

                dati->condivisione->codaFinale[dati->condivisione->elementiFinale] = matriceSentinella;
                dati->condivisione->elementiFinale++;

                pthread_mutex_unlock(&dati->condivisione->mutexFinale);
                sem_post(&dati->condivisione->semaforoOccupatiFinale);
                free(matrice);
                free(dati);
                return NULL;
            }
            pthread_mutex_unlock(&dati->condivisione->mutexFinale);

            free(matrice);
            free(dati);
            return NULL;
        }else if(isMagic(matrice)){     //se è magico inserisco nella coda finale
            
            sem_wait(&dati->condivisione->semaforoLiberiFinale);
            pthread_mutex_lock(&dati->condivisione->mutexFinale);
            printf("[VERIF %d] trovato quandrato magico!.\n",dati->id);
            dati->condivisione->codaFinale[dati->condivisione->elementiFinale] = matrice;
            dati->condivisione->elementiFinale++;

            pthread_mutex_unlock(&dati->condivisione->mutexFinale);
            sem_post(&dati->condivisione->semaforoOccupatiFinale);
        }

    }


}

int main(int argc, char *argv[]){

    if(argc < 3){
        fprintf(stderr,"Errore devi avviarmi con <M-verifiers> <file-1> <file-2> ... <file-N>.\n");
        exit(EXIT_FAILURE);
    }

    int numeroLettori = argc - 2;
    int numeroVerificatori = atoi(argv[1]);

    pthread_t arrayLettori[numeroLettori];
    pthread_t arrayVerificatori[numeroVerificatori];    

    printf("[MAIN] creo %d Thread Lettori e %d Thread Verificatori.\n",numeroLettori,numeroVerificatori);

    shared *condiviso = malloc(sizeof(shared));
    condiviso->elementiIntermedia = 0;
    condiviso->elementiFinale = 0;
    condiviso->lettoriAttivi = numeroLettori;
    condiviso->verificatoriAttivi = numeroVerificatori;
    pthread_mutex_init(&condiviso->mutexIntermedio,NULL);
    pthread_mutex_init(&condiviso->mutexFinale,NULL);
    sem_init(&condiviso->semaforoLiberi,0,10);
    sem_init(&condiviso->semaforoOccupati,0,0);
    sem_init(&condiviso->semaforoLiberiFinale,0,3);
    sem_init(&condiviso->semaforoOccupatiFinale,0,0);

    for(int i = 0; i < numeroLettori; i++){
        datiLettori *dati = malloc(sizeof(datiLettori));
        dati->condivisione = condiviso;
        dati->id = i;
        dati->nomeFile = argv[i+2];
        dati->numeroVerificatoriThread = numeroVerificatori;

        pthread_create(&arrayLettori[i],NULL,gestioneLettura,dati);
    }


    for(int i = 0; i < numeroVerificatori; i++){
        datiVerificatori *dati = malloc(sizeof(datiVerificatori));
        dati->condivisione = condiviso;
        dati->id = i;

        pthread_create(&arrayVerificatori[i],NULL,gestioneVerifica,dati);
    }

    

    //estraggo da coda finale
    while(true){
        int *matrice;
        sem_wait(&condiviso->semaforoOccupatiFinale);
        pthread_mutex_lock(&condiviso->mutexFinale);

        matrice = condiviso->codaFinale[0];
        
        for(int i = 1; i < condiviso->elementiFinale; i++){
            condiviso->codaFinale[i-1] = condiviso->codaFinale[i];
        }
        condiviso->elementiFinale--;

        if(matrice[0] == -1){
            pthread_mutex_unlock(&condiviso->mutexFinale);
            sem_post(&condiviso->semaforoLiberiFinale);
            break;
        }else{
            printf("[MAIN] quadrato magico trovato: ");
            for(int i = 0; i < 9; i++){
                printf("%d ",matrice[i]);
            }
            printf("\n");
        }

        pthread_mutex_unlock(&condiviso->mutexFinale);
        sem_post(&condiviso->semaforoLiberiFinale);
        
    }
    
    

    for(int i = 0; i < numeroLettori; i++){
        pthread_join(arrayLettori[i],NULL);
    }

    for(int i = 0; i < numeroVerificatori; i++){
        pthread_join(arrayVerificatori[i],NULL);
    }

    printf("[MAIN] TERMINAZIONE");
    pthread_mutex_destroy(&condiviso->mutexIntermedio);
    pthread_mutex_destroy(&condiviso->mutexFinale);
    sem_destroy(&condiviso->semaforoLiberi);
    sem_destroy(&condiviso->semaforoLiberiFinale);
    sem_destroy(&condiviso->semaforoOccupati);
    sem_destroy(&condiviso->semaforoOccupatiFinale);
    free(condiviso);
    return 0;

}