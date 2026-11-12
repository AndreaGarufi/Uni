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

    char bufferID[20];
    int categoria;      //3->quarto premio, 4->terzo premio, 5-> secondo premio, 6-> jackpot    //fare funzione per assegnare il premio in base ai numeri
    int numeroCorrispondenze;

}valoriVincenti;

typedef struct{

    char bufferID[20];
    int bufferNumeri[6];
    char *fileName;

}valoriCandidati;

typedef struct{

    valoriCandidati *codaCandidati[10];
    int elementiCandidati;
    pthread_mutex_t mutexCandidati;
    sem_t semaforoLiberi;
    sem_t semaforoOccupati;

    valoriVincenti *codaVincenti[3];
    int elementiVincenti;
    pthread_mutex_t mutexVincenti;
    sem_t semaforoLiberiVincenti;
    sem_t semaforoOccupatiVincenti;

    int lettoriAttivi;
    int verificatoriAttivi;

    int arrayVincenti[6];   //qua possono entrare senza mutex perche devono solo leggere

}shared;

typedef struct{

    int id;
    char *filName;
    shared *condivisione;
    int numeroVerificatoriThread;

}datiLettori;

typedef struct{

    int id;
    shared *condivisione;

}datiVerificatori;

void *gestioneLettura(void *arg){
    //printf("Entrano i lettori.\n");
    datiLettori *dati = (datiLettori*)arg;
    
    char buffer[BUFSIZ];

    FILE *fileLettura = fopen(dati->filName,"r");

    if(fileLettura == NULL){
        perror("Errore nell'apertura del file.\n");
        exit(EXIT_FAILURE);
    }else{
        printf("[READER %d] file '%s'.\n",dati->id,dati->filName);
    }

    int contatore = 0;
    char *savePrt;
    while(fgets(buffer,BUFSIZ,fileLettura) != NULL){
        contatore++;

        valoriCandidati *valoriLetti = malloc(sizeof(valoriCandidati));
        
        strcpy(valoriLetti->bufferID,__strtok_r(buffer,";",&savePrt));
        valoriLetti->fileName = dati->filName;
        int vettoreNumeri[6];
        
        for(int i = 0; i < 6; i++){
            vettoreNumeri[i] = atoi(__strtok_r(NULL,",\n\r",&savePrt));
            valoriLetti->bufferNumeri[i] = vettoreNumeri[i];
        }

        //fase di inserimento in coda candidati
        sem_wait(&dati->condivisione->semaforoLiberi);
        pthread_mutex_lock(&dati->condivisione->mutexCandidati);

        dati->condivisione->codaCandidati[dati->condivisione->elementiCandidati] = valoriLetti;
        printf("[READER %d] biglietto condidato n.%d: %s ",dati->id,contatore,dati->condivisione->codaCandidati[dati->condivisione->elementiCandidati]->bufferID);
        for(int i = 0; i < 6; i++){
            printf(" %d ",dati->condivisione->codaCandidati[dati->condivisione->elementiCandidati]->bufferNumeri[i]);
        }
        printf("\n");
        dati->condivisione->elementiCandidati++;

        pthread_mutex_unlock(&dati->condivisione->mutexCandidati);
        sem_post(&dati->condivisione->semaforoOccupati);

    }

    //inseriamo la sentinella
    pthread_mutex_lock(&dati->condivisione->mutexCandidati);
    dati->condivisione->lettoriAttivi--;
    printf("[READER %d] lavoro terminato.\n",dati->id);
    if(dati->condivisione->lettoriAttivi == 0){
        pthread_mutex_unlock(&dati->condivisione->mutexCandidati);

        for(int i = 0; i < dati->numeroVerificatoriThread; i++){
            valoriCandidati *valoriSentinella = calloc(1,sizeof(valoriCandidati));
            for(int i = 0; i < 6; i++){
                valoriSentinella->bufferNumeri[i] = -1;
            }
            sem_wait(&dati->condivisione->semaforoLiberi);
            pthread_mutex_lock(&dati->condivisione->mutexCandidati);
        
            dati->condivisione->codaCandidati[dati->condivisione->elementiCandidati] = valoriSentinella;
            dati->condivisione->elementiCandidati++;
        
            pthread_mutex_unlock(&dati->condivisione->mutexCandidati);
            sem_post(&dati->condivisione->semaforoOccupati);
        }
    }else{
        pthread_mutex_unlock(&dati->condivisione->mutexCandidati);
    }

    fclose(fileLettura);
    free(dati);
    return NULL;

}

void *gestioneVerifica(void *arg){
    //printf("Entrano i verificatori.\n");
    datiVerificatori*dati = (datiVerificatori*)arg;

    while(true){

        valoriCandidati *valoriEstratti;
        sem_wait(&dati->condivisione->semaforoOccupati);
        pthread_mutex_lock(&dati->condivisione->mutexCandidati);

        valoriEstratti = dati->condivisione->codaCandidati[0];
        for(int i = 1; i < dati->condivisione->elementiCandidati; i++){
            dati->condivisione->codaCandidati[i-1] = dati->condivisione->codaCandidati[i];
        }
        dati->condivisione->elementiCandidati--;

        pthread_mutex_unlock(&dati->condivisione->mutexCandidati);
        sem_post(&dati->condivisione->semaforoLiberi);

        if(valoriEstratti->bufferNumeri[0] == -1){                      //se la coda è finita
            pthread_mutex_lock(&dati->condivisione->mutexVincenti);
            printf("[CHECK %d] lavoro terminato.\n",dati->id);
            dati->condivisione->verificatoriAttivi--;
            if(dati->condivisione->verificatoriAttivi == 0){            //inserisco sentinella
                pthread_mutex_unlock(&dati->condivisione->mutexVincenti);

                sem_wait(&dati->condivisione->semaforoLiberiVincenti);
                pthread_mutex_lock(&dati->condivisione->mutexVincenti);

                valoriVincenti *valoriSentinella = calloc(1,sizeof(valoriVincenti));
                valoriSentinella->categoria = -1;

                dati->condivisione->codaVincenti[dati->condivisione->elementiVincenti] = valoriSentinella;
                dati->condivisione->elementiVincenti++;

                pthread_mutex_unlock(&dati->condivisione->mutexVincenti);
                sem_post(&dati->condivisione->semaforoOccupatiVincenti);

                free(dati);
                free(valoriEstratti);
                return NULL;

            }else{
                pthread_mutex_unlock(&dati->condivisione->mutexVincenti);

                free(dati);
                free(valoriEstratti);
                return NULL;
            }
        }

        int categoriaVincita = 0;
        bool vincente = false;
        int contatore = 0;
        char *stringhe[5] = {"nessun premio","quarto premio","terzo premio","secondo premio","jackpot"};   ////3->quarto premio, 4->terzo premio, 5-> secondo premio, 6-> jackpot
        char premio[20] = {0};
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                if(valoriEstratti->bufferNumeri[i] == dati->condivisione->arrayVincenti[j]){
                    contatore++;
                }
            }
        }
        switch(contatore){
        case 0:
            strcpy(premio,stringhe[0]);
            break;
        case 1:
            strcpy(premio,stringhe[0]);
            break;
        case 2:
            strcpy(premio,stringhe[0]);
            break;
        case 3:
            strcpy(premio,stringhe[1]);
            categoriaVincita = 3;
            break;
        case 4:
            strcpy(premio,stringhe[2]);
            categoriaVincita = 4;
            break;
        case 5:
            strcpy(premio,stringhe[3]);
            categoriaVincita = 5;
            break;
        case 6:
            strcpy(premio,stringhe[4]);
            categoriaVincita = 6;
            break;
        default:
            break;
        }

        if(contatore >= 3){
            vincente = true;
        }

        if(vincente == true){   //inserisco in codaVincenti
            valoriVincenti *bigliettoVincente = malloc(sizeof(valoriVincenti));
            strcpy(bigliettoVincente->bufferID,valoriEstratti->bufferID);
            bigliettoVincente->numeroCorrispondenze = contatore;
            bigliettoVincente->categoria = categoriaVincita;

            sem_wait(&dati->condivisione->semaforoLiberiVincenti);
            pthread_mutex_lock(&dati->condivisione->mutexVincenti);

            printf("[CHECK %d] verifico biglietto: %s: %d numeri idovinati su 6 -> %s.\n",dati->id,valoriEstratti->bufferID,contatore,premio);
            dati->condivisione->codaVincenti[dati->condivisione->elementiVincenti] = bigliettoVincente;
            dati->condivisione->elementiVincenti++;

            pthread_mutex_unlock(&dati->condivisione->mutexVincenti);
            sem_post(&dati->condivisione->semaforoOccupatiVincenti);
        }



    }
    
    return NULL;

}

int main(int argc, char *argv[]){
    
    if(argc < 4){
        fprintf(stderr,"Errore, devi avviarmi con <winning-file> <M-checkers> <ticket-file-1> ... <ticket-file-N>");
        exit(EXIT_FAILURE);
    }

    int numeroVerificatori = atoi(argv[2]);
    int numeroLettori = argc - 3;

    shared *condiviso = malloc(sizeof(shared));
    condiviso->elementiCandidati = 0;
    condiviso->elementiVincenti = 0;
    pthread_mutex_init(&condiviso->mutexCandidati,NULL);
    pthread_mutex_init(&condiviso->mutexVincenti,NULL);
    sem_init(&condiviso->semaforoLiberi,0,10);
    sem_init(&condiviso->semaforoOccupati,0,0);
    sem_init(&condiviso->semaforoLiberiVincenti,0,3);
    sem_init(&condiviso->semaforoOccupatiVincenti,0,0); 
    condiviso->lettoriAttivi = numeroLettori;
    condiviso->verificatoriAttivi = numeroVerificatori;


    FILE *fileLettura = fopen(argv[1],"r");
    if(fileLettura == NULL){
        perror("Errore nell'apertura del file.\n");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while(fscanf(fileLettura,"%d,",&condiviso->arrayVincenti[i]) == 1){
        i++;
    }

    printf("[MAIN] numeri vincenti: ");
    for(int i = 0; i < 6; i++){
        printf("%d ",condiviso->arrayVincenti[i]);
    }
    printf("\n");

    printf("[MAIN] creazione di %d thread lettori e %d thread verificatori.\n",numeroLettori,numeroVerificatori);

    pthread_t arrayLettori[numeroLettori];
    pthread_t arrayVerificatori[numeroVerificatori];

    for(int i = 0; i < numeroLettori; i++){
        datiLettori *dati = malloc(sizeof(datiLettori));
        dati->id = i+1;
        dati->filName = argv[i+3];
        dati->condivisione = condiviso;
        dati->numeroVerificatoriThread = numeroVerificatori;
        pthread_create(&arrayLettori[i],NULL,gestioneLettura,dati);
    }


    for(int i = 0; i < numeroVerificatori; i++){
        datiVerificatori *dati = malloc(sizeof(datiVerificatori));
        dati->id = i+1;
        dati->condivisione = condiviso;
        pthread_create(&arrayVerificatori[i],NULL,gestioneVerifica,dati);
    }

    //parte di estrazione nel main
    int quartoPremio = 0;
    int terzoPremio = 0;
    int secondoPremio = 0;
    int jackpot = 0;

    while(true){

        valoriVincenti *biglietti;

        sem_wait(&condiviso->semaforoOccupatiVincenti);
        pthread_mutex_lock(&condiviso->mutexVincenti);

        biglietti = condiviso->codaVincenti[0];
        for(int i = 1; i < condiviso->elementiVincenti; i++){
            condiviso->codaVincenti[i-1] = condiviso->codaVincenti[i];
        }
        condiviso->elementiVincenti--;

        if(biglietti->categoria == -1){ //sentinella

            pthread_mutex_unlock(&condiviso->mutexVincenti);
            sem_post(&condiviso->semaforoLiberiVincenti);
            break;
        }

        pthread_mutex_unlock(&condiviso->mutexVincenti);
        sem_post(&condiviso->semaforoLiberiVincenti);

        switch(biglietti->categoria){
            case 3:
                printf("[MAIN] biglietto vincente %s: 3 numeri indovinati -> quarto premio.\n",biglietti->bufferID);
                quartoPremio++;
                break;
            case 4:
                printf("[MAIN] biglietto vincente %s: 4 numeri indovinati -> terzo premio.\n",biglietti->bufferID);
                terzoPremio++;
                break;
            case 5:
                printf("[MAIN] biglietto vincente %s: 5 numeri indovinati -> secondo premio.\n",biglietti->bufferID);
                secondoPremio++;
                break;
            case 6:
                printf("[MAIN] biglietto vincente %s: 6 numeri indovinati -> JACKPOT!.\n",biglietti->bufferID);
                jackpot++;
                break;
            default:
                break;
            }
    }

    printf("[MAIN] riepilogo finale:\n");
    printf("[MAIN] quarto premio: %d, terzo premio %d, secondo premio %d, jackpot %d.\n",quartoPremio,terzoPremio,secondoPremio,jackpot);


    for(int i = 0; i < numeroLettori;i++){
        pthread_join(arrayLettori[i],NULL);
    }

    for(int i = 0; i < numeroVerificatori;i++){
        pthread_join(arrayVerificatori[i],NULL);
    }

    printf("[MAIN] lavoro terminato.\n");
    pthread_mutex_destroy(&condiviso->mutexCandidati);
    pthread_mutex_destroy(&condiviso->mutexVincenti);
    sem_destroy(&condiviso->semaforoLiberi);
    sem_destroy(&condiviso->semaforoOccupati);    
    sem_destroy(&condiviso->semaforoLiberiVincenti);
    sem_destroy(&condiviso->semaforoOccupatiVincenti);

    free(condiviso);

    return 0;

}