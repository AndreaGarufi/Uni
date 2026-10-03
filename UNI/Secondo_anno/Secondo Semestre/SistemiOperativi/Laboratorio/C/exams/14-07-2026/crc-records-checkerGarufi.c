#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <stdbool.h>
#include <string.h>

typedef struct{

    int dichiarati;
    int integri;
    int corrotti;

}terne;

typedef struct{

    char *fileProvenienza;
    int numeroProgressivo;
    uint8_t checksum;
    uint8_t checksumCalcolato;
    uint8_t vettoreRecord[16]; //15 elementi + checksum
    terne *ternaProvenienza;
}record;

typedef struct{

    record *codaCandidati[10];
    int numeroElementi;
    pthread_mutex_t mutexCandidati;
    pthread_cond_t condCandidati;

    record *codaScarti[5];
    int numeroElementiScarti;
    pthread_mutex_t mutexScarti;
    pthread_cond_t condScarti;   
    
    terne *vettoreTerne;
    pthread_cond_t condTerne; 
    pthread_mutex_t mutexTerne;    

    int lettoriAttivi;
    int verificatoriAttivi;

    bool finitoCandidati;
    bool finitoScarti;


}shared;

typedef struct{

    int id;
    char *nomeFile;
    shared *condivisione;

}datiThread;

void *gestioneLettura(void *arg){
    datiThread *dati = (datiThread*)arg;
    //printf("Entrano i lettori.\n");

    int file = open(dati->nomeFile,O_RDONLY);
    if(file < 0){
        perror("Errore nella creazione del file descriptor.\n");
        exit(EXIT_FAILURE);
    }

    struct stat infoFile;
    fstat(file,&infoFile);

    uint32_t totRecord;
    int numeroRecord;


    uint8_t *datiFile = mmap(NULL,infoFile.st_size,PROT_READ,MAP_PRIVATE,file,0);
    if(datiFile == MAP_FAILED){
        perror("Errore nella mappatura del file.\n");
        exit(EXIT_FAILURE);
    }else{
        totRecord = (uint32_t)datiFile[0];
        numeroRecord = ((int)infoFile.st_size - 4)/16;
        printf("[READER-%d] file '%s': %d record totali, %u dichiarati integri.\n",dati->id,dati->nomeFile,numeroRecord,totRecord);
    }

    int indiceTerna = dati->id - 1; 
    
    terne *nuovaTerna = &dati->condivisione->vettoreTerne[indiceTerna];

    pthread_mutex_lock(&dati->condivisione->mutexTerne);
    nuovaTerna->dichiarati = totRecord;
    nuovaTerna->integri = 0;
    nuovaTerna->corrotti = 0;
    pthread_mutex_unlock(&dati->condivisione->mutexTerne);

    int contatore = 0;
    for(int i = 0 + sizeof(uint32_t); i < infoFile.st_size; i = i + 16){
        record *elementoLetto = malloc(sizeof(record));
        
        for(int j = 0; j < 16; j++){
            elementoLetto->vettoreRecord[j] = datiFile[i+j];
            //printf("%u ",vettoreLetto[j]);
        }
        //printf("\n");
        contatore++;
        elementoLetto->fileProvenienza = dati->nomeFile;
        elementoLetto->numeroProgressivo = contatore;
        elementoLetto->checksum = elementoLetto->vettoreRecord[15];
        elementoLetto->checksumCalcolato = 0;
        elementoLetto->ternaProvenienza = nuovaTerna;

        pthread_mutex_lock(&dati->condivisione->mutexCandidati);
        while(dati->condivisione->numeroElementi >= 10){
            pthread_cond_wait(&dati->condivisione->condCandidati,&dati->condivisione->mutexCandidati);
        }

        dati->condivisione->codaCandidati[dati->condivisione->numeroElementi] = elementoLetto;
        printf("[READER-%d] record candidato numero %d (offset %d).\n",dati->id,elementoLetto->numeroProgressivo,i);
        dati->condivisione->numeroElementi++;

        pthread_cond_broadcast(&dati->condivisione->condCandidati);
        pthread_mutex_unlock(&dati->condivisione->mutexCandidati);

    }

    //poison pill
    pthread_mutex_lock(&dati->condivisione->mutexCandidati);
    dati->condivisione->lettoriAttivi--;
    printf("[READER-%d] Terminato.\n",dati->id);
    if(dati->condivisione->lettoriAttivi == 0){
        pthread_mutex_unlock(&dati->condivisione->mutexCandidati);

        dati->condivisione->finitoCandidati = true;
        pthread_cond_broadcast(&dati->condivisione->condCandidati);
        return NULL;
    }else{
        pthread_mutex_unlock(&dati->condivisione->mutexCandidati);
        return NULL;
    }


}

void *gestioneVerifica(void *arg){
    datiThread *dati = (datiThread*)arg;
    //printf("Entrano i verificatori.\n");

    while(true){
        record *elementoEstratto;

        pthread_mutex_lock(&dati->condivisione->mutexCandidati);
        while(dati->condivisione->numeroElementi == 0 && dati->condivisione->finitoCandidati == false){
            pthread_cond_wait(&dati->condivisione->condCandidati,&dati->condivisione->mutexCandidati);
        }

        if(dati->condivisione->finitoCandidati == true && dati->condivisione->numeroElementi == 0){
            pthread_mutex_unlock(&dati->condivisione->mutexCandidati);
            printf("[VERIF-%d] Terminato.\n",dati->id);

            pthread_mutex_lock(&dati->condivisione->mutexScarti);
            dati->condivisione->verificatoriAttivi--;
            if(dati->condivisione->verificatoriAttivi == 0){
                pthread_mutex_unlock(&dati->condivisione->mutexScarti);

                dati->condivisione->finitoScarti = true;
                pthread_cond_broadcast(&dati->condivisione->condScarti);
            }else{
                pthread_mutex_unlock(&dati->condivisione->mutexScarti);
            }

            return NULL;
        }

        elementoEstratto = dati->condivisione->codaCandidati[0];
        for(int i = 1; i < dati->condivisione->numeroElementi; i++){
            dati->condivisione->codaCandidati[i-1] = dati->condivisione->codaCandidati[i];
        }
        dati->condivisione->numeroElementi--;

        pthread_cond_broadcast(&dati->condivisione->condCandidati);
        pthread_mutex_unlock(&dati->condivisione->mutexCandidati);


        int checksumParziale = 0;
        for(int i = 0; i < 15; i++){
            checksumParziale = checksumParziale + elementoEstratto->vettoreRecord[i];
        }
        int checksum = checksumParziale % 256;

        if(elementoEstratto->vettoreRecord[15] == checksum){
            printf("[VERIF-%d] record numero %d del file '%s': checksum dichiarato: %d, calcolato %d -> integro.\n",dati->id,elementoEstratto->numeroProgressivo,elementoEstratto->fileProvenienza,elementoEstratto->vettoreRecord[15],checksum);
            elementoEstratto->ternaProvenienza->integri++;
        
        }else{
            elementoEstratto->ternaProvenienza->corrotti++;
            elementoEstratto->checksumCalcolato = checksum;
            pthread_mutex_lock(&dati->condivisione->mutexScarti);
            while(dati->condivisione->numeroElementiScarti >= 5){
                pthread_cond_wait(&dati->condivisione->condScarti,&dati->condivisione->mutexScarti);
            }
            
            printf("[VERIF-%d] record numero %d del file '%s': checksum dichiarato: %d, calcolato %d -> corrotto.\n",dati->id,elementoEstratto->numeroProgressivo,elementoEstratto->fileProvenienza,elementoEstratto->vettoreRecord[15],checksum);
            dati->condivisione->codaScarti[dati->condivisione->numeroElementiScarti] = elementoEstratto;
            dati->condivisione->numeroElementiScarti++;
            pthread_cond_broadcast(&dati->condivisione->condScarti);
            pthread_mutex_unlock(&dati->condivisione->mutexScarti);

        }

    }

    
}


int main(int argc, char *argv[]){

    if(argc < 3){
        fprintf(stderr,"Errore devi avviarmi con: <M-verifiers> <file-bin-1> ... <file-bin-N>.\n");
        exit(EXIT_FAILURE);
    }

    int numeroLettori = argc - 2;
    int numeroVerificatori = atoi(argv[1]);

    pthread_t arrayLettori[numeroLettori],arrayVerificatori[numeroVerificatori];

    shared *condiviso = malloc(sizeof(shared));
    condiviso->numeroElementi = 0;
    condiviso->numeroElementiScarti = 0;
    condiviso->verificatoriAttivi = numeroVerificatori;
    condiviso->lettoriAttivi = numeroLettori;
    condiviso->finitoCandidati = false;
    condiviso->finitoScarti = false;
    pthread_mutex_init(&condiviso->mutexCandidati,NULL);
    pthread_mutex_init(&condiviso->mutexScarti,NULL);
    pthread_mutex_init(&condiviso->mutexTerne,NULL);
    pthread_cond_init(&condiviso->condCandidati,NULL);
    pthread_cond_init(&condiviso->condScarti,NULL);
    condiviso->vettoreTerne = malloc(sizeof(terne) * numeroLettori);

    for(int i = 0; i < numeroLettori; i++){
        datiThread *datiLettori = malloc(sizeof(datiThread));
        datiLettori->id = i+1;
        datiLettori->condivisione = condiviso;
        datiLettori->nomeFile = argv[i+2];
        pthread_create(&arrayLettori[i],NULL,gestioneLettura,datiLettori);
    }

    for(int i = 0; i < numeroVerificatori; i++){
        datiThread *datiVerificatori = malloc(sizeof(datiThread));
        datiVerificatori->id = i+1;
        datiVerificatori->condivisione = condiviso;
        datiVerificatori->nomeFile = NULL;
        pthread_create(&arrayVerificatori[i],NULL,gestioneVerifica,datiVerificatori);
    }

    //estrazione nel main;
    while(true){
            record *elementoEstratto;

            pthread_mutex_lock(&condiviso->mutexScarti);
            while(condiviso->numeroElementiScarti == 0 && condiviso->finitoScarti == false){
                pthread_cond_wait(&condiviso->condScarti,&condiviso->mutexScarti);
            }

            if(condiviso->finitoScarti == true && condiviso->numeroElementiScarti == 0){
                pthread_mutex_unlock(&condiviso->mutexScarti);
                break;
            }

            elementoEstratto = condiviso->codaScarti[0];
            for(int i = 1; i < condiviso->numeroElementiScarti; i++){
                condiviso->codaScarti[i-1] = condiviso->codaScarti[i];
            }
            condiviso->numeroElementiScarti--;

            pthread_cond_broadcast(&condiviso->condScarti);
            pthread_mutex_unlock(&condiviso->mutexScarti);

            printf("[MAIN] record corrotto numero %d del file '%s' (checksum dichiarato %d, calcolato %d).\n",elementoEstratto->numeroProgressivo,elementoEstratto->fileProvenienza,elementoEstratto->checksum,elementoEstratto->checksumCalcolato);

        }

        if(condiviso->vettoreTerne[0].dichiarati == condiviso->vettoreTerne[0].integri){
            printf("[MAIN] file '%s': %d integri e %d corrotti -> verifica automatica superata (dichiarati %d).\n",argv[2],condiviso->vettoreTerne[0].integri,condiviso->vettoreTerne[0].corrotti,condiviso->vettoreTerne[0].dichiarati);
        }else{
            printf("[MAIN] file '%s': %d integri e %d corrotti -> verifica automatica fallita (dichiarati %d).\n",argv[2],condiviso->vettoreTerne[0].integri,condiviso->vettoreTerne[0].corrotti,condiviso->vettoreTerne[0].dichiarati);
        }
    
        if(condiviso->vettoreTerne[1].dichiarati == condiviso->vettoreTerne[1].integri){
            printf("[MAIN] file '%s': %d integri e %d corrotti -> verifica automatica superata (dichiarati %d).\n",argv[3],condiviso->vettoreTerne[1].integri,condiviso->vettoreTerne[1].corrotti,condiviso->vettoreTerne[1].dichiarati);
        }else{
            printf("[MAIN] file '%s': %d integri e %d corrotti -> verifica automatica fallita (dichiarati %d).\n",argv[3],condiviso->vettoreTerne[1].integri,condiviso->vettoreTerne[1].corrotti,condiviso->vettoreTerne[1].dichiarati);
        }

        if(condiviso->vettoreTerne[2].dichiarati == condiviso->vettoreTerne[2].integri){
            printf("[MAIN] file '%s': %d integri e %d corrotti -> verifica automatica superata (dichiarati %d).\n",argv[4],condiviso->vettoreTerne[2].integri,condiviso->vettoreTerne[2].corrotti,condiviso->vettoreTerne[2].dichiarati);
        }else{
            printf("[MAIN] file '%s': %d integri e %d corrotti -> verifica automatica fallita (dichiarati %d).\n",argv[4],condiviso->vettoreTerne[2].integri,condiviso->vettoreTerne[2].corrotti,condiviso->vettoreTerne[2].dichiarati);
        }



    for(int i = 0; i < numeroLettori; i++){
        pthread_join(arrayLettori[i],NULL);
    }


    for(int i = 0; i < numeroVerificatori; i++){
        pthread_join(arrayVerificatori[i],NULL);
    }   
    
    printf("[MAIN] terminazione.\n");
    pthread_cond_destroy(&condiviso->condCandidati);
    pthread_cond_destroy(&condiviso->condScarti);
    pthread_mutex_destroy(&condiviso->mutexCandidati);
    pthread_mutex_destroy(&condiviso->mutexScarti);
    pthread_mutex_destroy(&condiviso->mutexTerne);

    free(condiviso);


}