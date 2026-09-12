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
#include <string.h>

typedef struct{

    uint8_t matrice[9];
    int numeroProgressivo;
    char *fileProvenienza;
    int stato; // 0 = EMPTY, 1 = TO_VERIFY 2 = VERIFIED
    bool semiMagic;

}semiMagic;

typedef struct{

    uint8_t matrice[9];
    int numeroProgressivo;
    char *fileProvenienza;
    int stato; // 0 = EMPTY, 1 = TO_VERIFY 2 = VERIFIED
    bool simm;

}simmetric;

typedef struct{

    char *fileProvenienza;
    char tipoRilevato[32];

}coda;

typedef struct{

    semiMagic *slot1;
    pthread_mutex_t mutexSlot1;
    pthread_cond_t condSlot1;


    simmetric *slot2;
    pthread_mutex_t mutexSlot2;
    pthread_cond_t condSlot2;

    coda *codaRisultati[5];
    pthread_mutex_t mutexCoda;
    pthread_cond_t condCoda;
    int numeroElementi;

    int lettoriAttivi;

}shared;

typedef struct{

    shared *condivisione;
    int id;
    char *fileName;

}datiLettori;

typedef struct{

    shared *condivisione;
    char buffer[32];

}datiVerificatori;

void insertCoda(datiLettori *dati, coda *elementoSpeciale) {
    pthread_mutex_lock(&dati->condivisione->mutexCoda);
    while (dati->condivisione->numeroElementi >= 5) {
        pthread_cond_wait(&dati->condivisione->condCoda, &dati->condivisione->mutexCoda);
    }
    dati->condivisione->codaRisultati[dati->condivisione->numeroElementi] = elementoSpeciale;
    dati->condivisione->numeroElementi++;
    pthread_cond_broadcast(&dati->condivisione->condCoda);
    pthread_mutex_unlock(&dati->condivisione->mutexCoda);
}

bool isMagic(semiMagic *elementoLettoSlot1){


    int somma1,somma2,somma3,somma4,somma5,somma6;
    int matriceT[9] = {0};
    for(int i = 0; i < 9; i++){
        matriceT[i] = elementoLettoSlot1->matrice[i];
    }
    //righe
    somma1 = matriceT[0] + matriceT[1] + matriceT[2];
    somma2 = matriceT[3] + matriceT[4] + matriceT[5];
    somma3 = matriceT[6] + matriceT[7] + matriceT[8];

    //colonne
    somma4 = matriceT[0] + matriceT[3] + matriceT[6];
    somma5 = matriceT[1] + matriceT[4] + matriceT[7];
    somma6 = matriceT[2] + matriceT[5] + matriceT[8];    

    if(somma1 == somma2 && somma2 == somma3 && somma3 == somma4 && somma4 == somma5 && somma5 == somma6){
        return true;
    }else{
        return false;
    }

}

bool isSimmetric(simmetric *elementoLettoSlot1){

    uint8_t matriceT[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matriceT[i][j] = elementoLettoSlot1->matrice[i * 3 + j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) { // j parte da i + 1: evita la diagonale e i duplicati
            if (matriceT[i][j] != matriceT[j][i]) {
                return false;
            }
        }
    }
    return true;

}

void *gestioneLettura(void *arg){
    //printf("Entrano i lettori.\n");
    datiLettori *dati = (datiLettori*)arg;

    int fileLettura = open(dati->fileName,O_RDONLY);
    if(fileLettura < 0){
        perror("Errore nell'apertura del file.\n");
    }

    struct stat infoFile;
    fstat(fileLettura,&infoFile);

    uint8_t *datiFile = mmap(NULL,infoFile.st_size,PROT_READ,MAP_PRIVATE,fileLettura,0);
    if(datiFile == MAP_FAILED){
        perror("Errore nella mappatura del file.\n");
        exit(EXIT_FAILURE);
    }else{
        printf("[READER-%d] file '%s'.\n",dati->id,dati->fileName);
    }

    uint32_t semiMagicNelFile,simmetricNelFile;

    memcpy(&semiMagicNelFile,datiFile,sizeof(uint32_t));
    memcpy(&simmetricNelFile,datiFile + sizeof(uint32_t),sizeof(uint32_t));
    int numeroMatrici = ((int)infoFile.st_size - 8) / 9;

    printf("[READER-%d] totale matrici: %d, matrici semi-magiche: %d, matrici simmetriche: %d.\n",dati->id,numeroMatrici,semiMagicNelFile,simmetricNelFile);

    int matriceTemp[9] = {0};
    int contatore = 1;
    for(int i = 0 + (2*sizeof(uint32_t)); i < infoFile.st_size; i = i + 9){
        //printf("%d ",datiFile[i]);
    
        for(int j = 0; j < 9; j++){
            matriceTemp[j] = datiFile[i+j];
        }
        pthread_mutex_lock(&dati->condivisione->mutexSlot1);
        while(dati->condivisione->slot1->stato != 0){   //finche è diverso da empty
            pthread_cond_wait(&dati->condivisione->condSlot1,&dati->condivisione->mutexSlot1);
        }
        for(int k = 0; k < 9; k++){
            dati->condivisione->slot1->matrice[k] = matriceTemp[k];
        }
        printf("[READER-%d] matrice candidata numero %d.\n",dati->id,contatore);
        dati->condivisione->slot1->fileProvenienza = dati->fileName;
        dati->condivisione->slot1->numeroProgressivo = contatore;
        dati->condivisione->slot1->stato = 1;   //to verify
        pthread_cond_broadcast(&dati->condivisione->condSlot1);
        pthread_mutex_unlock(&dati->condivisione->mutexSlot1);
        
        //fino a qui verificatore is magic
        
        pthread_mutex_lock(&dati->condivisione->mutexSlot2);
        while(dati->condivisione->slot2->stato != 0){   //finche è diverso da empty
            pthread_cond_wait(&dati->condivisione->condSlot2,&dati->condivisione->mutexSlot2);
        }
        for(int k = 0; k < 9; k++){
            dati->condivisione->slot2->matrice[k] = matriceTemp[k];
        }
        //printf("[READER-%d] matrice candidata numero %d.\n",dati->id,contatore);
        dati->condivisione->slot2->fileProvenienza = dati->fileName;
        dati->condivisione->slot2->numeroProgressivo = contatore;
        dati->condivisione->slot2->stato = 1;   //to verify
        pthread_cond_broadcast(&dati->condivisione->condSlot2);
        pthread_mutex_unlock(&dati->condivisione->mutexSlot2);        
        
        // INIZIO MODIFICA: attesa degli esiti e inserimento nella coda

        // Aspetto che VERIF-SEMI abbia terminato
        pthread_mutex_lock(&dati->condivisione->mutexSlot1);
        while(dati->condivisione->slot1->stato != 2){
            pthread_cond_wait(&dati->condivisione->condSlot1,&dati->condivisione->mutexSlot1);
        }

        bool semi = dati->condivisione->slot1->semiMagic;

        dati->condivisione->slot1->stato = 0;
        pthread_cond_broadcast(&dati->condivisione->condSlot1);
        pthread_mutex_unlock(&dati->condivisione->mutexSlot1);


        // Aspetto che VERIF-SIMM abbia terminato
        pthread_mutex_lock(&dati->condivisione->mutexSlot2);
        while(dati->condivisione->slot2->stato != 2){
            pthread_cond_wait(&dati->condivisione->condSlot2,&dati->condivisione->mutexSlot2);
        }

        bool simm = dati->condivisione->slot2->simm;

        dati->condivisione->slot2->stato = 0;
        pthread_cond_broadcast(&dati->condivisione->condSlot2);
        pthread_mutex_unlock(&dati->condivisione->mutexSlot2);


        contatore++;

        if(semi || simm){
            coda *elementoSpeciale = malloc(sizeof(coda));

            elementoSpeciale->fileProvenienza = dati->fileName;

            if(semi){
                strcpy(elementoSpeciale->tipoRilevato, "semi-magica");
            }else{
                strcpy(elementoSpeciale->tipoRilevato, "simmetrica");
            }

            insertCoda(dati, elementoSpeciale);
        }

        // FINE MODIFICA



    }


    //poison pill
    pthread_mutex_lock(&dati->condivisione->mutexSlot1);
    dati->condivisione->lettoriAttivi--;
    if(dati->condivisione->lettoriAttivi == 0){
        pthread_mutex_unlock(&dati->condivisione->mutexSlot1);

        //slot1

        pthread_mutex_lock(&dati->condivisione->mutexSlot1);
        while(dati->condivisione->slot1->stato != 0){   //finche è diverso da empty
            pthread_cond_wait(&dati->condivisione->condSlot1,&dati->condivisione->mutexSlot1);
        }
        for(int k = 0; k < 9; k++){
            dati->condivisione->slot1->matrice[k] = 0;
        }
        dati->condivisione->slot1->fileProvenienza = dati->fileName;
        dati->condivisione->slot1->numeroProgressivo = -1;
        dati->condivisione->slot1->stato = 1;   //to verify
        pthread_cond_broadcast(&dati->condivisione->condSlot1);
        pthread_mutex_unlock(&dati->condivisione->mutexSlot1);
        
        //slot2

        pthread_mutex_lock(&dati->condivisione->mutexSlot2);
        while(dati->condivisione->slot2->stato != 0){   //finche è diverso da empty
            pthread_cond_wait(&dati->condivisione->condSlot2,&dati->condivisione->mutexSlot2);
        }
        for(int k = 0; k < 9; k++){
            dati->condivisione->slot2->matrice[k] = 0;
        }
        dati->condivisione->slot2->fileProvenienza = dati->fileName;
        dati->condivisione->slot2->numeroProgressivo = -1;
        dati->condivisione->slot2->stato = 1;   //to verify
        pthread_cond_broadcast(&dati->condivisione->condSlot2);
        pthread_mutex_unlock(&dati->condivisione->mutexSlot2); 
    
        coda *sentinella = calloc(1,sizeof(coda));  
        strcpy(sentinella->tipoRilevato,"fine");  
        insertCoda(dati,sentinella);        
        
    }else{
        pthread_mutex_unlock(&dati->condivisione->mutexSlot1);
    }




    munmap(datiFile,infoFile.st_size);
    return NULL;
}

void *gestioneSemiMagic(void *arg){
    //printf("Entra verif is magic.\n");
    datiVerificatori *dati = (datiVerificatori*)arg;

    while(true){

        pthread_mutex_lock(&dati->condivisione->mutexSlot1);
        while(dati->condivisione->slot1->stato != 1){
            pthread_cond_wait(&dati->condivisione->condSlot1,&dati->condivisione->mutexSlot1);
        }

        if(dati->condivisione->slot1->numeroProgressivo == -1){
            dati->condivisione->slot1->stato = 0;
            pthread_mutex_unlock(&dati->condivisione->mutexSlot1);
            return NULL;
        }

        if(isMagic(dati->condivisione->slot1)){
            printf("[VERIF-SEMI] matrice numero %d del file '%s': ",dati->condivisione->slot1->numeroProgressivo,dati->condivisione->slot1->fileProvenienza);
            for(int i = 0; i < 9; i++){
                printf("%d ",dati->condivisione->slot1->matrice[i]);
            }
            printf("-> semi-Magica.\n");
            dati->condivisione->slot1->semiMagic = true;

        }else{
            printf("[VERIF-SEMI] matrice numero %d del file '%s': ",dati->condivisione->slot1->numeroProgressivo,dati->condivisione->slot1->fileProvenienza);
            for(int i = 0; i < 9; i++){
                printf("%d ",dati->condivisione->slot1->matrice[i]);
            }
            printf("-> no.\n");   
            dati->condivisione->slot1->semiMagic = false;
        }

        // INIZIO MODIFICA: il verificatore comunica l'esito al reader
        dati->condivisione->slot1->stato = 2; // VERIFIED
        // FINE MODIFICA
        pthread_cond_broadcast(&dati->condivisione->condSlot1);
        pthread_mutex_unlock(&dati->condivisione->mutexSlot1);

    }



}

void *gestioneSimmetric(void *arg){
    //printf("Entra verif simmetrico.\n");
    datiVerificatori *dati = (datiVerificatori*)arg;

    while(true){

        pthread_mutex_lock(&dati->condivisione->mutexSlot2);
        while(dati->condivisione->slot2->stato != 1){
            pthread_cond_wait(&dati->condivisione->condSlot2,&dati->condivisione->mutexSlot2);
        }

        if(dati->condivisione->slot2->numeroProgressivo == -1){
            dati->condivisione->slot2->stato = 0;
            pthread_mutex_unlock(&dati->condivisione->mutexSlot2);
            return NULL;
        }

        if(isSimmetric(dati->condivisione->slot2)){
            printf("[VERIF-SIMM] matrice numero %d del file '%s': ",dati->condivisione->slot2->numeroProgressivo,dati->condivisione->slot2->fileProvenienza);
            for(int i = 0; i < 9; i++){
                printf("%d ",dati->condivisione->slot2->matrice[i]);
            }
            printf("-> simmetrica.\n");
            dati->condivisione->slot2->simm = true;

        }else{
            printf("[VERIF-SIMM] matrice numero %d del file '%s': ",dati->condivisione->slot2->numeroProgressivo,dati->condivisione->slot2->fileProvenienza);
            for(int i = 0; i < 9; i++){
                printf("%d ",dati->condivisione->slot2->matrice[i]);
            }
            printf("-> no.\n");   
            dati->condivisione->slot2->simm = false;
        }

        // INIZIO MODIFICA: il verificatore comunica l'esito al reader
        dati->condivisione->slot2->stato = 2; // VERIFIED
        // FINE MODIFICA
        pthread_cond_broadcast(&dati->condivisione->condSlot2);
        pthread_mutex_unlock(&dati->condivisione->mutexSlot2);

    }    





}

int main(int argc, char *argv[]){

    if(argc < 2){
        fprintf(stderr,"Errore devi avviarmi con: matrix-type-checker <file-bin-1> ... <file-bin-N>.\n");
        exit(EXIT_FAILURE);
    }

    int numeroLettori = argc - 1;
    pthread_t arrayLettori[numeroLettori];
    pthread_t verifSemi,verifSimm;

    shared *condiviso = malloc(sizeof(shared));
    condiviso->numeroElementi = 0;
    condiviso->lettoriAttivi = numeroLettori;
    pthread_mutex_init(&condiviso->mutexCoda,NULL);
    pthread_mutex_init(&condiviso->mutexSlot1,NULL);
    pthread_mutex_init(&condiviso->mutexSlot2,NULL);
    pthread_cond_init(&condiviso->condCoda,NULL);
    pthread_cond_init(&condiviso->condSlot1,NULL);
    pthread_cond_init(&condiviso->condSlot2,NULL);

    semiMagic *elementoLettoslot1 = malloc(sizeof(semiMagic));
    simmetric *elementoLettoslot2 = malloc(sizeof(simmetric));
    condiviso->slot1 = elementoLettoslot1;
    condiviso->slot2 = elementoLettoslot2;

    condiviso->slot1->stato = 0;
    condiviso->slot1->semiMagic = false;    
    condiviso->slot2->stato = 0;   
    condiviso->slot2->simm = false; 

    for(int i = 0; i < numeroLettori; i++){
        datiLettori *dati = malloc(sizeof(datiLettori));
        dati->condivisione = condiviso;
        dati->fileName = argv[i+1];
        dati->id = i+1;
        pthread_create(&arrayLettori[i],NULL,gestioneLettura,dati);
    }

    datiVerificatori *datiIsMagic = malloc(sizeof(datiVerificatori));
    datiIsMagic->condivisione = condiviso;
    strcpy(datiIsMagic->buffer,"VERIF-SEMI");
    pthread_create(&verifSemi,NULL,gestioneSemiMagic,datiIsMagic);

    datiVerificatori *datiSimmetric = malloc(sizeof(datiVerificatori));
    datiSimmetric->condivisione = condiviso;
    strcpy(datiSimmetric->buffer,"VERIF-SIMM");
    pthread_create(&verifSimm,NULL,gestioneSimmetric,datiSimmetric);   
    
    
    //estrazione nel main
    int contatoreMagiche = 0,contatoreSimmetriche = 0;


    while(true){
        coda *elementoEstratto;
        pthread_mutex_lock(&condiviso->mutexCoda);
        while(condiviso->numeroElementi == 0){
            pthread_cond_wait(&condiviso->condCoda,&condiviso->mutexCoda);
        }  
        
        elementoEstratto = condiviso->codaRisultati[0];
        for(int i = 1; i < condiviso->numeroElementi; i++){
            condiviso->codaRisultati[i-1] = condiviso->codaRisultati[i];
        }
        condiviso->numeroElementi--;
        pthread_cond_signal(&condiviso->condCoda);
        pthread_mutex_unlock(&condiviso->mutexCoda);

        if(strcmp(elementoEstratto->tipoRilevato,"fine") == 0){
            free(elementoEstratto);
            break;
        }
        
        if(strcmp(elementoEstratto->tipoRilevato,"semi-magica") == 0){
            contatoreMagiche++;
        }else{
            contatoreSimmetriche++;
        }

        free(elementoEstratto);

    }

    printf("[MAIN] terminazione con %d matrici semi-magiche e %d matrici simmetriche.\n",contatoreMagiche,contatoreSimmetriche);



    for(int i = 0; i < numeroLettori; i++){
        pthread_join(arrayLettori[i],NULL);
    }

    pthread_join(verifSemi,NULL);
    pthread_join(verifSimm,NULL);

}