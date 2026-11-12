/*Esercizio 22 — Da argv a thread dinamici

Scrivi un programma conta-righe <M> <file1> <file2> ... <fileN> che:

legge M da argv[1],
calcola N dal numero di file rimanenti,
crea N thread lettori (uno per file, ognuno apre il proprio file e conta quante righe ha, stampando "[READER-2] file 'nome.txt': 42 righe"),
crea M thread "stampatori" che non fanno nulla di complesso, solo dimostrano che sai creare/joinare 
correttamente un numero variabile di thread letto da riga di comando, passando a ciascuno un id/nome file diverso tramite struct (niente global!).*/


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

  int id;
  char *nomeFile;

}datiLettori;

typedef struct{

  int id;

}datiStampatori;

void *gestioneLettori(void *arg){
  //printf("Gestione Lettori.\n");
  datiLettori *dati = (datiLettori*)arg;

  FILE *fileRighe = fopen(dati->nomeFile,"r");
  if(fileRighe == NULL){
    perror("Errore nell'apertura del file.\n");
    exit(EXIT_FAILURE);
  }else{
    printf("File aperto correttamente.\n");
  }

  int righe = 0;
  int c;                   
  int ultimo_char_letto = 0;
  while ((c = fgetc(fileRighe)) != EOF) {
      if (c == '\n') righe++;
      ultimo_char_letto = c;
  }

  if (ultimo_char_letto != 0 && ultimo_char_letto != '\n') {
      righe++;
  }
  printf("[READER %d] nome file: '%s', totale righe %d.\n",dati->id,dati->nomeFile,righe);
  fclose(fileRighe);
  free(dati);
  return NULL;

}

void *gestioneStampatori(void *arg){

  datiStampatori *dati = (datiStampatori*)arg;

  printf("[STAMPATORE %d] Non servo a niente devo solo essere creato.\n",dati->id);

  free(dati);
  return NULL;

}

int main(int argc, char *argv[]){

    if(argc < 3){
        perror("Errore devi avviarmi con: <M> <file1> <file2> ... <fileN>");
        exit(EXIT_FAILURE);
    }

    int threadLettori = argc -2;
    int threadStampatori = atoi(argv[1]);

    printf("[MAIN] creo %d Thread Stampatori e %d Thread Lettori.\n",threadStampatori,threadLettori);

    pthread_t arrayLettori[threadLettori];
    pthread_t arrayStampatori[threadStampatori];

    for(int i = 0; i < threadLettori; i++){

        datiLettori *dati = malloc(sizeof(datiLettori));
        dati->id = i;
        dati->nomeFile = argv[i+2];
        pthread_create(&arrayLettori[i],NULL,gestioneLettori,dati);
    }


    for(int i = 0; i < threadStampatori; i++){

        datiStampatori *dati = malloc(sizeof(datiStampatori));
        dati->id = i;
        pthread_create(&arrayStampatori[i],NULL,gestioneStampatori,dati);
    }    


    for(int i = 0; i < threadLettori; i++){
      pthread_join(arrayLettori[i],NULL);
    }

    for(int i = 0; i < threadStampatori; i++){
      pthread_join(arrayStampatori[i],NULL);
    }
    
}
