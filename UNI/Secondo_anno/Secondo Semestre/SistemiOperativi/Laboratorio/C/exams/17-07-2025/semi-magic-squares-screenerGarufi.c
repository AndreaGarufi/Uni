#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdbool.h>

#define maxDim 16

typedef struct{

    uint8_t dimensione;
    uint8_t data[maxDim * maxDim];

}matrice;

typedef struct{

    matrice *codaIntermedia[5];
    pthread_mutex_t mutexIntermedio;
    pthread_cond_t condIntermedia;
    int numeroElementi;


    matrice *recordFinale[1];
    pthread_cond_t condFinale;
    pthread_mutex_t mutexFinale;
    bool pieno;
    
    int dimMatrice;
    int lettoriAttivi;

}shared;

typedef struct{

    int id;
    char *nomeFile;
    shared *condivisione;

}datiLettori;

typedef struct{

    shared *condivisione;

}datiVerificatore;

bool isMagic(matrice *elementoEstratto){

    int M = elementoEstratto->dimensione;
    
    // somma della prima riga, ci servirà come riferimento
    int totale = 0;
    for (int c = 0; c < M; c++) {
        totale += elementoEstratto->data[0 * M + c];
    }
    
    // controlla tutte le righe (compresa la prima, per coerenza)
    for (int r = 0; r < M; r++) {
        int somma_riga = 0;
        for (int c = 0; c < M; c++) {
            somma_riga += elementoEstratto->data[r * M + c];
        }
        if (somma_riga != totale) {
            return false;
        }
    }
    
    // controlla tutte le colonne
    for (int c = 0; c < M; c++) {
        int somma_colonna = 0;
        for (int r = 0; r < M; r++) {
            somma_colonna += elementoEstratto->data[r * M + c];
        }
        if (somma_colonna != totale) {
            return false;
        }
    }
    
    return true;    

}


void *gestioneLettura(void *arg){
    datiLettori *dati = (datiLettori*)arg;
    //printf("Entrano i lettori.\n");

    int fileLettura = open(dati->nomeFile,O_RDONLY);
    if(fileLettura < 0){
        perror("Errore nell'apertura del file.\n");
        exit(EXIT_FAILURE);
    }

    struct stat infoFile;
    fstat(fileLettura,&infoFile);

    uint8_t *datiFile = mmap(NULL,infoFile.st_size,PROT_READ,MAP_PRIVATE,fileLettura,0);
    if(datiFile == MAP_FAILED){
        perror("Errore nella mappatura del file.\n");
        exit(EXIT_FAILURE);
    }else{
        printf("[READER-%d] file '%s'.\n",dati->id,dati->nomeFile);
    }

    int matriceSalto = dati->condivisione->dimMatrice * dati->condivisione->dimMatrice; //grandezza di ogni matrice nel file, cosi mi muovo correttamente

    int contatore = 1;

    for(int i = 0; i < infoFile.st_size; i = i + matriceSalto){
        matrice *elementoLetto = malloc(sizeof(matrice));
        
        for(int j = 0; j < matriceSalto; j++){
            //printf("%d",datiFile[j]);
            elementoLetto->dimensione = dati->condivisione->dimMatrice;
            elementoLetto->data[j] = datiFile[i+j];
        }
        pthread_mutex_lock(&dati->condivisione->mutexIntermedio);
        while(dati->condivisione->numeroElementi >= 5){
            pthread_cond_wait(&dati->condivisione->condIntermedia,&dati->condivisione->mutexIntermedio);
        }
        
        dati->condivisione->codaIntermedia[dati->condivisione->numeroElementi] = elementoLetto;
        printf("\n[READER-%d] quadrato candidato numero %d :",dati->id,contatore);
        for(int j = 0; j < matriceSalto; j++){
            printf("%d ",elementoLetto->data[j]);
        }  
        printf("\n");
        dati->condivisione->numeroElementi++;
        pthread_cond_broadcast(&dati->condivisione->condIntermedia);
        pthread_mutex_unlock(&dati->condivisione->mutexIntermedio);
        contatore++;
        
    }


    pthread_mutex_lock(&dati->condivisione->mutexIntermedio);
    dati->condivisione->lettoriAttivi--;
    printf("[READER-%d] Ho terminato.\n",dati->id);
    if(dati->condivisione->lettoriAttivi == 0){
        pthread_mutex_unlock(&dati->condivisione->mutexIntermedio);

        matrice *sentinella = calloc(1,sizeof(matrice));
        sentinella->dimensione = -1;
    
        pthread_mutex_lock(&dati->condivisione->mutexIntermedio);
        while(dati->condivisione->numeroElementi >= 5){
            pthread_cond_wait(&dati->condivisione->condIntermedia,&dati->condivisione->mutexIntermedio);
        }
            
        dati->condivisione->codaIntermedia[dati->condivisione->numeroElementi] = sentinella;
        dati->condivisione->numeroElementi++;
        pthread_cond_broadcast(&dati->condivisione->condIntermedia);
        pthread_mutex_unlock(&dati->condivisione->mutexIntermedio);    
    }else{
        pthread_mutex_unlock(&dati->condivisione->mutexIntermedio);
    }

    munmap(datiFile,infoFile.st_size);
    return NULL;
    

}


void *gestioneVerifica(void *arg){
    datiVerificatore *dati = (datiVerificatore*)arg;
    //printf("Entra il verificatore.\n");
    int dim = dati->condivisione->dimMatrice * dati->condivisione->dimMatrice;

    while(true){
        matrice *matriceEstratta;
        pthread_mutex_lock(&dati->condivisione->mutexIntermedio);
        while(dati->condivisione->numeroElementi == 0){
            pthread_cond_wait(&dati->condivisione->condIntermedia,&dati->condivisione->mutexIntermedio);
        }

        matriceEstratta = dati->condivisione->codaIntermedia[0];
        for(int i = 1; i < dati->condivisione->numeroElementi; i++){
            dati->condivisione->codaIntermedia[i-1] = dati->condivisione->codaIntermedia[i];
        }
        dati->condivisione->numeroElementi--;

        pthread_cond_broadcast(&dati->condivisione->condIntermedia);
        pthread_mutex_unlock(&dati->condivisione->mutexIntermedio);

        if(matriceEstratta->dimensione == (uint8_t)-1){
            printf("[VERIF] Ho finito.\n");

            pthread_mutex_lock(&dati->condivisione->mutexFinale);
            while(dati->condivisione->pieno == true){
                pthread_cond_wait(&dati->condivisione->condFinale,&dati->condivisione->mutexFinale);
            }

            dati->condivisione->recordFinale[0] = matriceEstratta;
            dati->condivisione->pieno = true;
            pthread_cond_signal(&dati->condivisione->condFinale);
            pthread_mutex_unlock(&dati->condivisione->mutexFinale);

            return NULL;
        }else{
            
            printf("[VERIF] verifico quadrato: (");
            for(int i = 0; i < dim; i++){
                printf("%d ",matriceEstratta->data[i]);
            }
            printf(").\n");
        }

        if(isMagic(matriceEstratta)){
            
            pthread_mutex_lock(&dati->condivisione->mutexFinale);
            while(dati->condivisione->pieno == true){
                pthread_cond_wait(&dati->condivisione->condFinale,&dati->condivisione->mutexFinale);
            }
            
            printf("[VERIF] trovato quadrato semi-magico!");
            dati->condivisione->recordFinale[0] = matriceEstratta;
            dati->condivisione->pieno = true;
            pthread_cond_signal(&dati->condivisione->condFinale);
            pthread_mutex_unlock(&dati->condivisione->mutexFinale);            

        }else{
            free(matriceEstratta);
        }



    }


}

int main(int argc, char *argv[]){

    if(argc < 3){
        fprintf(stderr,"Errore devi avviarmi con: <M-square-size> <bin-file-1> ...  <bin-file-N>.\n");
        exit(EXIT_FAILURE);
    }


    int numeroLettori = argc - 2;

    pthread_t arrayLettori[numeroLettori];
    pthread_t verificatore;
    
    shared *condiviso = malloc(sizeof(shared));
    condiviso->dimMatrice = atoi(argv[1]);
    condiviso->lettoriAttivi = numeroLettori;
    condiviso->pieno = false;
    condiviso->numeroElementi = 0;
    pthread_mutex_init(&condiviso->mutexFinale,NULL);
    pthread_mutex_init(&condiviso->mutexIntermedio,NULL);
    pthread_cond_init(&condiviso->condIntermedia,NULL);
    pthread_cond_init(&condiviso->condFinale,NULL);

    for(int i = 0; i < numeroLettori; i++){
        datiLettori *dati = malloc(sizeof(datiLettori));
        dati->condivisione = condiviso;
        dati->id = i+1;
        dati->nomeFile = argv[i+2];
        pthread_create(&arrayLettori[i],NULL,gestioneLettura,dati);
    }


    datiVerificatore *dati = malloc(sizeof(datiVerificatore));
    dati->condivisione = condiviso;
    pthread_create(&verificatore,NULL,gestioneVerifica,dati);


    //estrazione nel main
    int contatore = 0;
    while(true){

        matrice *elementoEstratto;
        pthread_mutex_lock(&condiviso->mutexFinale);
        while(condiviso->pieno == false){
            pthread_cond_wait(&condiviso->condFinale,&condiviso->mutexFinale);
        }

        elementoEstratto = condiviso->recordFinale[0];
        condiviso->pieno = false;

        if(elementoEstratto->dimensione == (uint8_t)-1){
            pthread_mutex_unlock(&dati->condivisione->mutexFinale);
            break;
        }
        printf("[MAIN] quadrato magico: ");
        contatore++;
        for(int i = 0; i < elementoEstratto->dimensione * elementoEstratto->dimensione; i++){
            printf("%d ",elementoEstratto->data[i]);
        }
        pthread_cond_signal(&condiviso->condFinale);
        pthread_mutex_unlock(&condiviso->mutexFinale);
        free(elementoEstratto);

    }



    for(int i = 0; i < numeroLettori; i++){
        pthread_join(arrayLettori[i],NULL);
    }

    pthread_join(verificatore,NULL);

    printf("[MAIN] terminazione con %d quadrati semi-magici trovati.\n",contatore);
    pthread_cond_destroy(&condiviso->condFinale);
    pthread_cond_destroy(&condiviso->condIntermedia);
    pthread_mutex_destroy(&condiviso->mutexFinale);
    pthread_mutex_destroy(&condiviso->mutexIntermedio);
    free(condiviso);

}