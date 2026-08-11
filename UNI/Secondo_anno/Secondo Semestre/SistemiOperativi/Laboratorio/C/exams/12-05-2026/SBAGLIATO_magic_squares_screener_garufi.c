#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <string.h>

#define CAP_INTERMEDIA 10
#define CAP_FINALE 3

typedef struct{
    
    int *codaIntermedia[CAP_INTERMEDIA];
    int headInter;
    int tailInter;
    pthread_mutex_t lockInter;
    sem_t sem_posti_liberi_inter;
    sem_t sem_elementi_pronti_inter;

    int *codaFinale[CAP_FINALE];
    int headFinale;
    int tailFinale;
    pthread_mutex_t lockFinale;
    sem_t sem_posti_liberi_finale;
    sem_t sem_elementi_pronti_finale;

}CodeCondivise;

typedef struct {
    int id;
    char *filename;
    CodeCondivise *shared;
}DatiLettore;

typedef struct {
    int id;
    CodeCondivise *shared;
}DatiVerificatore;

bool isMagic(int magico[9]){

    int somma1,somma2,somma3,somma4,somma5;

    somma1 = magico[0] + magico[1] + magico[2];
    somma2 = magico[3] + magico[4] + magico[5];
    somma3 = magico[6] + magico[7] + magico[8];

    somma4 = magico[0] + magico[4] + magico[8];
    somma5 = magico[2] + magico[4] + magico[6];

    if(somma1 == somma2 && somma2 == somma3 && somma4 == somma5 && somma4 == somma3){
        printf("Quadrato Magico!.\n");
        return true;
    }else{
        return false;
    }
}

void *gestioneLettura(void *arg){

    DatiLettore *dati = (DatiLettore*)arg;
    printf("[READER - %d ]\n",dati->id);

    FILE *fileLettore;
    if((fileLettore = fopen(dati->filename,"r")) == NULL){
        perror("Errore apertura file\n");
        exit(EXIT_FAILURE);
    }

    int j = 0;

    while (1) {
        int letti = 0;
        int *matrice = malloc(9 * sizeof(int));

        for (int i = 0; i < 9; i++) {
            if (fscanf(fileLettore, "%d,", &matrice[i]) == 1 ||
                fscanf(fileLettore, "%d", &matrice[i]) == 1) {
                letti++;
            } else {
                break;
            }
        }

        if (letti != 9){
            free(matrice); // 🔧 FIX memory leak
            break;
        }

        j++;
        printf("[READER - %d ] Quadrato candidato n. %d: ",dati->id,j);
        for (int i = 0; i < 9; i++) {
            printf("%d ", matrice[i]);
        }
        printf("\n--------------------------\n");

        sem_wait(&dati->shared->sem_posti_liberi_inter);
        pthread_mutex_lock(&dati->shared->lockInter);

        dati->shared->codaIntermedia[dati->shared->tailInter] = matrice;
        dati->shared->tailInter = (dati->shared->tailInter + 1) % CAP_INTERMEDIA;

        pthread_mutex_unlock(&dati->shared->lockInter);
        sem_post(&dati->shared->sem_elementi_pronti_inter);
    }

    free(dati);
    fclose(fileLettore);
    return NULL;
}

void *gestioneVerifica(void *arg){

    DatiVerificatore *dati = (DatiVerificatore*)arg;
    printf("[VERIF - %d ]\n",dati->id);

    int matrice[9];
    
    while(1){

        sem_wait(&dati->shared->sem_elementi_pronti_inter);
        pthread_mutex_lock(&dati->shared->lockInter);

        int *matrice_estratta = dati->shared->codaIntermedia[dati->shared->headInter];

        if(matrice_estratta == NULL){
            pthread_mutex_unlock(&dati->shared->lockInter); // 🔧 FIX
            break;
        }

        memcpy(matrice, matrice_estratta, 9 * sizeof(int));

        dati->shared->codaIntermedia[dati->shared->headInter] = NULL;
        dati->shared->headInter = (dati->shared->headInter + 1) % CAP_INTERMEDIA;

        pthread_mutex_unlock(&dati->shared->lockInter);
        sem_post(&dati->shared->sem_posti_liberi_inter);

        free(matrice_estratta);

        if(isMagic(matrice)){
            // opzionale: inserimento coda finale
        }
    }
    
    free(dati);
    return NULL;
}

int main(int argc, char *argv[]){

    int numeroLettori = argc-2;
    pthread_t arrayThreadLettori[numeroLettori];
    int numeroVerificatori = atoi(argv[1]);
    pthread_t arrayThreadVerificatori[numeroVerificatori];

    CodeCondivise *shared = malloc(sizeof(CodeCondivise));  

    sem_init(&shared->sem_elementi_pronti_inter,0,0);
    sem_init(&shared->sem_posti_liberi_inter,0,10); 
    sem_init(&shared->sem_elementi_pronti_finale,0,0);     
    sem_init(&shared->sem_posti_liberi_finale,0,3);

    pthread_mutex_init(&shared->lockInter,NULL);
    pthread_mutex_init(&shared->lockFinale,NULL);

    shared->headInter = 0;
    shared->tailInter = 0;
    shared->headFinale = 0;
    shared->tailFinale = 0;    

    // LETTORI
    for(int i = 0; i < numeroLettori; i++){
        DatiLettore *dati = calloc(1,sizeof(DatiLettore));
        dati->id = i;
        dati->filename = argv[i+2];
        dati->shared = shared;
        pthread_create(&arrayThreadLettori[i],NULL,gestioneLettura,dati);
    }
    
    // VERIFICATORI
    for(int i = 0; i < numeroVerificatori; i++){
        DatiVerificatore *dati = malloc(sizeof(DatiVerificatore));
        dati->id = i;
        dati->shared = shared;
        pthread_create(&arrayThreadVerificatori[i],NULL,gestioneVerifica,dati);
    }

    // JOIN LETTORI
    for(int i = 0; i < numeroLettori; i++){
        pthread_join(arrayThreadLettori[i], NULL);
    }

    // 🔥 INSERT POISON PILLS (UNO PER VERIFICATORE)
    for(int i = 0; i < numeroVerificatori; i++){
        sem_wait(&shared->sem_posti_liberi_inter);
        pthread_mutex_lock(&shared->lockInter);

        shared->codaIntermedia[shared->tailInter] = NULL;
        shared->tailInter = (shared->tailInter + 1) % CAP_INTERMEDIA;

        pthread_mutex_unlock(&shared->lockInter);
        sem_post(&shared->sem_elementi_pronti_inter);
    }

    // JOIN VERIFICATORI
    for(int i = 0; i < numeroVerificatori; i++){
        pthread_join(arrayThreadVerificatori[i], NULL);
    }

    free(shared);
}