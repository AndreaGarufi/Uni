#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

typedef struct{

    uint8_t matrice[9];

}matrice;

typedef struct{

    matrice *codaIntermedia[5];
    int numeroElementi;
    pthread_mutex_t mutexIntermedio;
    pthread_cond_t condLettori;

    matrice *recordFinale[1];
    pthread_mutex_t mutexFinale;
    pthread_cond_t condVerificatore; 
    
    int lettoriAttivi;

}shared;

typedef struct{

    int id;
    char *nomeFile;
    shared *condivisione;

}datiLettori;

typedef struct{

    int id;
    shared *condivisione;

}datiVerificatore;

void *gestioneLettura(void *arg){
    datiLettori *dati = (datiLettori*)arg;
    //printf("Entrano i lettori.\n");

    int file = open(dati->nomeFile,O_RDONLY);
    if(file < 0){
        perror("Errore nell'apertura del file binario.\n");
        exit(EXIT_FAILURE);
    }else{
        printf("[READER %d] file '%s'.\n",dati->id,dati->nomeFile);
    }

    struct stat dimensioneFile;
    fstat(file,&dimensioneFile);

    uint8_t *datiDaLeggere = mmap(NULL,dimensioneFile.st_size,PROT_READ,MAP_PRIVATE,file,0);
    if(datiDaLeggere == MAP_FAILED){
        perror("Errore nella mappatura del file.\n");
        exit(EXIT_FAILURE);
    }

    



}

void *gestioneVerifica(void *arg){
    datiVerificatore *dati = (datiVerificatore*)arg;
    //printf("Entra il verificatore.\n");


}

int main(int argc, char *argv[]){

    if(argc < 3 || atoi(argv[1]) != 5 && atoi(argv[1]) != 9){
        fprintf(stderr,"Errore, devi avviarmi con <M-square-size> <bin-file-1> ...  <bin-file-N> (i file sono solo 5x5 o 9x9 scegli una M che sia 5 o 9).\n");
        exit(EXIT_FAILURE);
    }

    int numeroLettori = argc - 2;
    
    pthread_t arrayLettori[numeroLettori];
    pthread_t verificatore;

    shared *condiviso = malloc(sizeof(shared));
    
    condiviso->numeroElementi = 0;
    condiviso->lettoriAttivi = numeroLettori;
    pthread_mutex_init(&condiviso->mutexFinale,NULL);
    pthread_mutex_init(&condiviso->mutexIntermedio,NULL);
    pthread_cond_init(&condiviso->condLettori,NULL);
    pthread_cond_init(&condiviso->condVerificatore,NULL);

    for(int i = 0; i < numeroLettori; i++){
        datiLettori *dati = malloc(sizeof(datiLettori));
        dati->id = i;
        dati->nomeFile = argv[i+2];
        dati->condivisione = condiviso;
        pthread_create(&arrayLettori[i],NULL,gestioneLettura,dati);
    }

    datiVerificatore *dati = malloc(sizeof(datiVerificatore));
    dati->id = 1;
    dati->condivisione = condiviso;
    pthread_create(&verificatore,NULL,gestioneVerifica,dati);
    

    //estrazione nel main


    for(int i = 0; i < numeroLettori; i++){
        pthread_join(arrayLettori[i],NULL);
    }

    pthread_join(verificatore,NULL);

    pthread_mutex_destroy(&condiviso->mutexFinale);
    pthread_mutex_destroy(&condiviso->mutexIntermedio);
    pthread_cond_destroy(&condiviso->condLettori);
    pthread_cond_destroy(&condiviso->condVerificatore);
    free(condiviso);
    return 0;
}