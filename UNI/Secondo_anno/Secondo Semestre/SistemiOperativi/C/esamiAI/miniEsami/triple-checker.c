/*ESERCIZIO STILE COMPITO 1 — con MUTEX e SEMAFORI

Creare un programma triple-checker.c in linguaggio C che accetti invocazioni 
sulla riga di comando del tipo:

triple-checker <M-verifiers> <file-1> <file-2> ... <file-N>

Il programma prende in input N file di testo, ciascuno contenente una 
sequenza di numeri interi (uno per riga), e individua quelli che sono 
multipli di 3 ma NON di 9 (esempio: 6, 12, 15, 21 vanno bene; 9, 18, 27 
NO perché sono anche multipli di 9).

Al suo avvio il programma creerà N + M thread ausiliari:
- N thread lettori (uno per file) che leggono i numeri e li inseriscono, 
  uno alla volta, in una coda "candidati" con capienza massima 8;
- M thread verificatori (M passato da riga di comando) che estraggono i 
  numeri dalla coda "candidati", verificano la proprietà, e inseriscono 
  i numeri validi in una coda "risultati" con capienza massima 4.

Le strutture dati condivise saranno:
- una coda "candidati" (FIFO, capienza 8) con un mutex, un semaforo 
  posti_liberi e un semaforo elementi_presenti;
- una coda "risultati" (FIFO, capienza 4) con un mutex, un semaforo 
  posti_liberi e un semaforo elementi_presenti;
- un contatore lettori_attivi (init N), protetto dal mutex della coda 
  candidati;
- un contatore verificatori_attivi (init M), protetto dal mutex della 
  coda risultati.

Ogni lettore, terminata la lettura del proprio file, decrementa 
lettori_attivi; l'ultimo lettore rimasto inserisce M sentinelle nella 
coda candidati (una per ciascun verificatore).

Ogni verificatore, quando estrae una sentinella dalla coda candidati, 
decrementa verificatori_attivi; l'ultimo verificatore rimasto inserisce 
una sentinella nella coda risultati.

Il thread principale estrae dalla coda risultati e stampa ogni numero 
trovato, fino alla sentinella, poi stampa il totale.

Non si devono usare strutture dati con visibilità globale: tutto va 
incapsulato in struct passate ai thread tramite puntatore.

Output atteso (esempio con 2 file e 2 verificatori):
[MAIN] creazione di 2 thread lettori e 2 thread verificatori
[READER-1] file 'numeri-1.txt'
[READER-2] file 'numeri-2.txt'
[READER-1] letto 12 dal file 'numeri-1.txt'
[VERIF-1] 12 è multiplo di 3 ma non di 9!
[READER-1] letto 9 dal file 'numeri-1.txt'
[VERIF-1] 9 scartato (multiplo anche di 9)
...
[READER-1] terminazione con 20 numeri letti
[READER-2] terminazione con 15 numeri letti
[VERIF-1] terminazione con 18 numeri verificati
[VERIF-2] terminazione con 17 numeri verificati
[MAIN] trovato: 12
[MAIN] trovato: 21
...
[MAIN] totale numeri trovati: 8
[MAIN] terminazione

Tempo suggerito: 50 minuti
*/

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

  int numero;

}coda;

typedef struct{

  coda *codaCandidati[8];
  pthread_mutex_t mutexCandidati;
  sem_t semaforoLiberi;
  sem_t semaforoOccupati;
  int numeroElementi;

  int lettoriAttivi;
  int verificatoriAttivi;

  coda *codaRisultati[4];
  pthread_mutex_t mutexRisultati;
  sem_t semaforoLiberiRisultati;
  sem_t semaforoOccupatiRisultati;
  int numeroElementiRisultati;

}shared;

typedef struct{

  int id;
  int numeroVerificatoriThread;
  char *nomeFile;
  shared *condivisione;

}datiLettori;

typedef struct{

  int id;
  shared *condivisione;

}datiVerificatori;

bool isCorrect(coda *numeroEstratto){
  
  if(numeroEstratto->numero % 3 == 0){
    if(numeroEstratto->numero % 9 == 0){
      return false;
    }else{
      return true;
    }
  }else{
    return false;
  }

}


void *gestioneLettura(void *arg){
  datiLettori *dati = (datiLettori*)arg;
  //printf("Entrano i lettori.\n");

  FILE *fileLettura = fopen(dati->nomeFile,"r");
  if(fileLettura == NULL){
    perror("Errore nell'apertura del file:");
    exit(EXIT_FAILURE);
  }else{
    printf("[READER -%d] file '%s'.\n",dati->id,dati->nomeFile);
  }
  int numeroEstratto = 0;
  int contatore = 0;
  while((fscanf(fileLettura,"%d",&numeroEstratto)) == 1){
    coda *numeroLetto = malloc(sizeof(coda));
    numeroLetto->numero = numeroEstratto;

    sem_wait(&dati->condivisione->semaforoLiberi);
    pthread_mutex_lock(&dati->condivisione->mutexCandidati);

    dati->condivisione->codaCandidati[dati->condivisione->numeroElementi] = numeroLetto;
    printf("[READER %d] letto %d dal file '%s'.\n",dati->id,dati->condivisione->codaCandidati[dati->condivisione->numeroElementi]->numero,dati->nomeFile);
    dati->condivisione->numeroElementi++;

    pthread_mutex_unlock(&dati->condivisione->mutexCandidati);
    sem_post(&dati->condivisione->semaforoOccupati);
    contatore++;
  }

  pthread_mutex_lock(&dati->condivisione->mutexCandidati);
  dati->condivisione->lettoriAttivi--;
  if(dati->condivisione->lettoriAttivi == 0){
    pthread_mutex_unlock(&dati->condivisione->mutexCandidati);

    for(int i = 0; i < dati->numeroVerificatoriThread; i++){

    coda *sentinella = malloc(sizeof(coda));
    sentinella->numero = -1;
    sem_wait(&dati->condivisione->semaforoLiberi);
    pthread_mutex_lock(&dati->condivisione->mutexCandidati);

    dati->condivisione->codaCandidati[dati->condivisione->numeroElementi] = sentinella;
    dati->condivisione->numeroElementi++;

    pthread_mutex_unlock(&dati->condivisione->mutexCandidati);
    sem_post(&dati->condivisione->semaforoOccupati);      
    }
  }else{
    pthread_mutex_unlock(&dati->condivisione->mutexCandidati);
  }

  fclose(fileLettura);
  printf("[READER %d] ho letto %d numeri.\n",dati->id,contatore);
  return NULL;

}

void *gestioneVerifica(void *arg){
  datiVerificatori *dati = (datiVerificatori*)arg;
  //printf("Entrano i Verificatori.\n");
  int contatore = 0;
  while(true){

    sem_wait(&dati->condivisione->semaforoOccupati);
    pthread_mutex_lock(&dati->condivisione->mutexCandidati);
    coda *numeroEstratto = malloc(sizeof(coda));

    numeroEstratto = dati->condivisione->codaCandidati[0];
    for(int i = 1; i < dati->condivisione->numeroElementi; i++){
      dati->condivisione->codaCandidati[i-1] = dati->condivisione->codaCandidati[i];
    }
    dati->condivisione->numeroElementi--;
    
    pthread_mutex_unlock(&dati->condivisione->mutexCandidati);
    sem_post(&dati->condivisione->semaforoLiberi);

    printf("[VERIF %d] verifico il numero %d.\n",dati->id,numeroEstratto->numero);

    if(numeroEstratto->numero == -1){
      pthread_mutex_lock(&dati->condivisione->mutexRisultati);
      dati->condivisione->verificatoriAttivi--;
      if(dati->condivisione->verificatoriAttivi == 0){
        pthread_mutex_unlock(&dati->condivisione->mutexRisultati);

        sem_wait(&dati->condivisione->semaforoLiberiRisultati);
        pthread_mutex_lock(&dati->condivisione->mutexRisultati);

        coda *sentinella = malloc(sizeof(coda));
        sentinella->numero = -1;
        dati->condivisione->codaRisultati[dati->condivisione->numeroElementiRisultati] = sentinella;
        dati->condivisione->numeroElementiRisultati++;

        pthread_mutex_unlock(&dati->condivisione->mutexRisultati);
        sem_post(&dati->condivisione->semaforoOccupatiRisultati);

        free(numeroEstratto);
        printf("[VERIF %d] ho verificato %d numeri.\n",dati->id,contatore);
        return NULL;

      }else{
        pthread_mutex_unlock(&dati->condivisione->mutexRisultati);
        free(numeroEstratto);
        printf("[VERIF %d] ho verificato %d numeri.\n",dati->id,contatore);
        return NULL;
      }
    }else if(isCorrect(numeroEstratto)){

      sem_wait(&dati->condivisione->semaforoLiberiRisultati);
      pthread_mutex_lock(&dati->condivisione->mutexRisultati);

      printf("[VERIF %d] il numero %d è multiplo di 3 ma non di 9!.\n",dati->id,numeroEstratto->numero);
      dati->condivisione->codaRisultati[dati->condivisione->numeroElementiRisultati] = numeroEstratto;
      dati->condivisione->numeroElementiRisultati++;

      pthread_mutex_unlock(&dati->condivisione->mutexRisultati);
      sem_post(&dati->condivisione->semaforoOccupatiRisultati);

    }else{
      free(numeroEstratto);
    }
    contatore++;
  }

}


int main(int argc, char *argv[]){

  if(argc < 3){
    fprintf(stderr,"Errore devi avviarmi con: <M-verifiers> <file-1> <file-2> ... <file-N>.\n");
    exit(EXIT_FAILURE);
  }

  
  int numeroVerificatori = atoi(argv[1]);
  int numeroLettori = argc - 2;
  
  pthread_t arrayLettori[numeroLettori];
  pthread_t arrayVerificatori[numeroVerificatori];
  
  shared *condiviso = malloc(sizeof(shared));
  condiviso->numeroElementi = 0;
  condiviso->numeroElementiRisultati = 0;
  condiviso->verificatoriAttivi = numeroVerificatori;
  condiviso->lettoriAttivi = numeroLettori;
  pthread_mutex_init(&condiviso->mutexCandidati,NULL);
  pthread_mutex_init(&condiviso->mutexRisultati,NULL);
  sem_init(&condiviso->semaforoLiberi,0,8);
  sem_init(&condiviso->semaforoOccupati,0,0);
  sem_init(&condiviso->semaforoLiberiRisultati,0,4);
  sem_init(&condiviso->semaforoOccupatiRisultati,0,0);

  for(int i = 0; i < numeroLettori; i++){
    datiLettori *dati = malloc(sizeof(datiLettori));
    dati->id = i+1;
    dati->nomeFile = argv[i+2];
    dati->numeroVerificatoriThread = numeroVerificatori;
    dati->condivisione = condiviso;
    pthread_create(&arrayLettori[i],NULL,gestioneLettura,dati);
  }

  for(int i = 0; i < numeroVerificatori; i++){
    datiVerificatori *dati = malloc(sizeof(datiVerificatori));
    dati->id = i+1;
    dati->condivisione = condiviso;
    pthread_create(&arrayVerificatori[i],NULL,gestioneVerifica,dati);
  }

  int contatore = 0;
  while(true){

    sem_wait(&condiviso->semaforoOccupatiRisultati);
    pthread_mutex_lock(&condiviso->mutexRisultati);
    coda *numeroEstratto = malloc(sizeof(coda));

    numeroEstratto =condiviso->codaRisultati[0];
    for(int i = 1; i < condiviso->numeroElementiRisultati; i++){
      condiviso->codaRisultati[i-1] = condiviso->codaRisultati[i];
    }
    condiviso->numeroElementiRisultati--;
    
    pthread_mutex_unlock(&condiviso->mutexRisultati);
    sem_post(&condiviso->semaforoLiberiRisultati);

    
    if(numeroEstratto->numero == -1){
      free(numeroEstratto);
      break;
    }

    printf("[MAIN] trovato %d.\n",numeroEstratto->numero);
    contatore++;
  }


  for(int i = 0; i < numeroLettori; i++){
    pthread_join(arrayLettori[i],NULL);
  }

  for(int i = 0; i < numeroVerificatori; i++){
    pthread_join(arrayVerificatori[i],NULL);
  }

  printf("[MAIN] trovati %d numeri idonei.\n",contatore);

  printf("[MAIN] Terminazione.\n");
  sem_destroy(&condiviso->semaforoLiberi);
  sem_destroy(&condiviso->semaforoOccupati);
  sem_destroy(&condiviso->semaforoLiberiRisultati);
  sem_destroy(&condiviso->semaforoOccupatiRisultati);
  pthread_mutex_destroy(&condiviso->mutexCandidati);
  pthread_mutex_destroy(&condiviso->mutexRisultati);
  free(condiviso);
  return 0;

}