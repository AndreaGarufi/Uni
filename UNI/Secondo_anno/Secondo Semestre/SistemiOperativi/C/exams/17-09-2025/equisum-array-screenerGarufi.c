#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>

typedef struct{

    uint8_t vettore[12];

}codaArray;

typedef struct{

    codaArray *codaCandidati[10];
    int numeroElementi;
    pthread_mutex_t mutexCoda;
    sem_t semaforoOccupati;
    sem_t semaforoLiberi;

    codaArray *recordFinale[1];   //array che il main deve leggere e svuotare tutte le volte
    pthread_mutex_t mutexFinale;
    sem_t semaforoOccupatiFinale;
    sem_t semaforoLiberiFinale;

    int lettoriAttivi;
    int verificatoriAttivi;

}shared;

typedef struct{

    int id;
    char *nomeFile;
    int numeroVerificatoriThread;
    shared *condivisione;

}datiLettori;

typedef struct{

    int id;
    shared *condivisione;

}datiVerificatori;



int equisum(codaArray *elementoEstratto){

    int sommaDispari = 0;
    int sommaPari = 0;
    for(int i = 0; i < 12; i++){

        if(i % 2 == 0){
            sommaPari = sommaPari + elementoEstratto->vettore[i];
        }else{
            sommaDispari = sommaDispari + elementoEstratto->vettore[i];
        }
    }

    if(sommaDispari == sommaPari){
        return sommaPari;
    }else{
        return -1;
    }

}

void *gestioneLettura(void *arg){
    datiLettori *dati = (datiLettori*)arg;
    //printf("Entrano i lettori.\n");

    //fase di apertura del file

    int file = open(dati->nomeFile,O_RDONLY);

    if(file < 0){
        perror("Errore nell'apertura del file binario:\n");
        exit(EXIT_FAILURE);
    }else{
        printf("[READER %d] file '%s'.\n",dati->id,dati->nomeFile);
    }

    struct stat datiFile;
    fstat(file,&datiFile);

    uint8_t *datiDaLeggere = mmap(NULL,datiFile.st_size,PROT_READ,MAP_PRIVATE,file,0);
    //file mappato lo possiamo trattare come un array
    //printf("[READER %d] %d.\n",dati->id,datiDaLeggere[0]); il file è mappato bene
    if (datiDaLeggere == MAP_FAILED) {
        perror("mmap fallita");  
        exit(EXIT_FAILURE); 
    }

    int contatore = 1;
    for(int i = 0; i + 12 <= datiFile.st_size; i = i + 12){
        codaArray *letti = malloc(sizeof(codaArray));
        for(int j = 0; j < 12; j++){
            letti->vettore[j] = datiDaLeggere[i+j];
            //printf("[READER %d] %d.\n",dati->id,letti->vettore[j]);
        }

        sem_wait(&dati->condivisione->semaforoLiberi);
        pthread_mutex_lock(&dati->condivisione->mutexCoda);

        dati->condivisione->codaCandidati[dati->condivisione->numeroElementi] = letti;
        printf("[READER %d] vettore candidato n.%d: ",dati->id,contatore);
        for(int k = 0; k < 12; k++){
            printf("%d ",dati->condivisione->codaCandidati[dati->condivisione->numeroElementi]->vettore[k]);
        }
        printf("\n");
        contatore++;
        dati->condivisione->numeroElementi++;


        pthread_mutex_unlock(&dati->condivisione->mutexCoda);
        sem_post(&dati->condivisione->semaforoOccupati);
    }

    //inserimento sentinella

    pthread_mutex_lock(&dati->condivisione->mutexCoda);
    dati->condivisione->lettoriAttivi--;
    printf("[READER %d] HO FINITO.\n ",dati->id);
    if(dati->condivisione->lettoriAttivi == 0){
        pthread_mutex_unlock(&dati->condivisione->mutexCoda);

        for(int i = 0; i < dati->numeroVerificatoriThread; i++){

        codaArray *sentinella = calloc(1,sizeof(codaArray));
        sentinella->vettore[0] = -1;
        sem_wait(&dati->condivisione->semaforoLiberi);
        pthread_mutex_lock(&dati->condivisione->mutexCoda);
        
        dati->condivisione->codaCandidati[dati->condivisione->numeroElementi] = sentinella;
        dati->condivisione->numeroElementi++;

        pthread_mutex_unlock(&dati->condivisione->mutexCoda);
        sem_post(&dati->condivisione->semaforoOccupati);
        }

        munmap(datiDaLeggere,datiFile.st_size);
        return NULL;
    }else{
        pthread_mutex_unlock(&dati->condivisione->mutexCoda);
    }

    munmap(datiDaLeggere,datiFile.st_size);
    return NULL;    

}

void *gestioneVerifica(void *arg){
    datiVerificatori *dati = (datiVerificatori*)arg;
    //printf("Entrano i verificatori.\n");

    //fase di estrazione
    int risultato = 0;
    while(true){

        sem_wait(&dati->condivisione->semaforoOccupati);
        pthread_mutex_lock(&dati->condivisione->mutexCoda);
    
        codaArray *elementoEstratto;
        elementoEstratto = dati->condivisione->codaCandidati[0];
        for(int i = 1; i < dati->condivisione->numeroElementi; i++){
            dati->condivisione->codaCandidati[i-1] = dati->condivisione->codaCandidati[i];
        }
        dati->condivisione->numeroElementi--;
    
        pthread_mutex_unlock(&dati->condivisione->mutexCoda);
        sem_post(&dati->condivisione->semaforoLiberi);

        printf("[VERIF %d] verifico vettore: ",dati->id);
        for(int i = 0; i < 12; i++){
            printf("%d ",elementoEstratto->vettore[i]);
        }
        printf("\n");

        if(elementoEstratto->vettore[0] == (uint8_t)-1){ //sentinella
            
            pthread_mutex_lock(&dati->condivisione->mutexFinale);
            dati->condivisione->verificatoriAttivi--;
            printf("[VERIF %d] HO FINITO.\n",dati->id);
            if(dati->condivisione->verificatoriAttivi == 0){
                pthread_mutex_unlock(&dati->condivisione->mutexFinale);

                sem_wait(&dati->condivisione->semaforoLiberiFinale);
                pthread_mutex_lock(&dati->condivisione->mutexFinale);
    
                dati->condivisione->recordFinale[0] = elementoEstratto;
                
                pthread_mutex_unlock(&dati->condivisione->mutexFinale);
                sem_post(&dati->condivisione->semaforoOccupatiFinale);

                return NULL;
            }else{
                pthread_mutex_unlock(&dati->condivisione->mutexFinale);
                free(elementoEstratto);
                return NULL;
            }

        }else if((risultato = equisum(elementoEstratto)) != -1){
            
            sem_wait(&dati->condivisione->semaforoLiberiFinale);
            pthread_mutex_lock(&dati->condivisione->mutexFinale);
            printf("[VERIF %d] si tratta di un vettore equisomma con somma %d!\n",dati->id,risultato);
    
            dati->condivisione->recordFinale[0] = elementoEstratto;
                
            pthread_mutex_unlock(&dati->condivisione->mutexFinale);
            sem_post(&dati->condivisione->semaforoOccupatiFinale);            

        }else{
            free(elementoEstratto);
        }
    }



}


int main(int argc, char *argv[]){

    if(argc < 2){
        fprintf(stderr,"Errore devi avviarmi con <file-bin-1> <file-bin-2> ... <file-bin-N>.\n");
        exit(EXIT_FAILURE);
    }

    int numeroLettori = argc - 1;
    int numeroVerificatori = 3;
    pthread_t arrayLettori[numeroLettori];
    pthread_t arrayVerificatori[numeroVerificatori];


    shared *condiviso = malloc(sizeof(shared));

    condiviso->numeroElementi = 0;
    condiviso->lettoriAttivi = numeroLettori;
    condiviso->verificatoriAttivi = numeroVerificatori;
    pthread_mutex_init(&condiviso->mutexCoda,NULL);
    pthread_mutex_init(&condiviso->mutexFinale,NULL);
    sem_init(&condiviso->semaforoLiberi,0,10);
    sem_init(&condiviso->semaforoOccupati,0,0);
    sem_init(&condiviso->semaforoLiberiFinale,0,1);
    sem_init(&condiviso->semaforoOccupatiFinale,0,0);

    for(int i = 0; i < numeroLettori; i++){
        datiLettori *dati = malloc(sizeof(datiLettori));
        dati->id = i;
        dati->nomeFile = argv[i+1];
        dati->numeroVerificatoriThread = 3;
        dati->condivisione = condiviso;
        pthread_create(&arrayLettori[i],NULL,gestioneLettura,dati);
    }

    for(int i = 0; i < numeroVerificatori; i++){
        datiVerificatori *dati = malloc(sizeof(datiVerificatori));
        dati->id = i;
        dati->condivisione = condiviso;
        pthread_create(&arrayVerificatori[i],NULL,gestioneVerifica,dati);
    }

    //estraggo nel main
    int contatore = 0;
    while(true){
        sem_wait(&condiviso->semaforoOccupatiFinale);
        pthread_mutex_lock(&condiviso->mutexFinale);
    
        codaArray *elementoEstratto;
        elementoEstratto = condiviso->recordFinale[0];

        pthread_mutex_unlock(&condiviso->mutexFinale);
        sem_post(&condiviso->semaforoLiberiFinale);

        if(elementoEstratto->vettore[0] == (uint8_t)-1){
            //sentinella, posso uscire
            free(elementoEstratto);
            break;
        }else{
            printf("[MAIN] ricevuto nuovo vettore equisomma: ");
            contatore++;
            for(int i = 0; i < 12; i++){
                printf("%d ",elementoEstratto->vettore[i]);
            }
            printf("\n");    
            free(elementoEstratto);    
        }

    }

    printf("[MAIN] terminazione con %d vettori equisomma trovati.\n",contatore);


    for(int i = 0; i < numeroLettori; i++){
        pthread_join(arrayLettori[i],NULL);
    }

    for(int i = 0; i < numeroVerificatori; i++){
        pthread_join(arrayVerificatori[i],NULL);
    }

    pthread_mutex_destroy(&condiviso->mutexCoda);
    pthread_mutex_destroy(&condiviso->mutexFinale);
    sem_destroy(&condiviso->semaforoLiberi);
    sem_destroy(&condiviso->semaforoOccupati);
    sem_destroy(&condiviso->semaforoLiberiFinale);
    sem_destroy(&condiviso->semaforoOccupatiFinale);
    free(condiviso);
    return 0;

}