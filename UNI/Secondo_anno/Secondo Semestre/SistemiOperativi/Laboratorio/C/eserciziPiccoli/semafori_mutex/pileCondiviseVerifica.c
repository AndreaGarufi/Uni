/*Esercizio 21 — Pipeline a due stadi con pile e contatori di terminazione

Simula la struttura tipica degli esami: pila_A -> verifica -> pila_B -> main.

Struttura dati "pila_A" (condivisa, incapsulata in una struct, NON globale):
- array di interi, capienza massima 5, gestito come pila (LIFO) con indice top;
- un mutex per proteggere array/top;
- un semaforo posti_liberi (init 5) e uno elementi_presenti (init 0);
- un contatore intero produttori_attivi (init 2), protetto dallo stesso mutex 
  della pila, che tiene traccia di quanti thread produttori devono ancora 
  lavorare.

Struttura dati "pila_B" (condivisa, incapsulata in una struct separata):
- array di interi, capienza massima 3, gestito come pila (LIFO) con indice top;
- un mutex, un semaforo posti_liberi (init 3) e uno elementi_presenti (init 0);
- un contatore intero verificatori_attivi (init 2), protetto dallo stesso 
  mutex della pila.

Thread PRODUTTORI (2 thread, identificati PROD-1 e PROD-2):
- ciascuno genera e inserisce nella pila_A 10 numeri casuali (0-99), stampando 
  ad ogni inserimento "[PROD-x] inserito %d";
- terminato l'inserimento dei suoi 10 numeri, decrementa (in mutua esclusione) 
  il contatore produttori_attivi della pila_A;
- se il decremento porta il contatore a 0, questo produttore (l'ultimo rimasto 
  attivo) inserisce anche un valore sentinella (-1) nella pila_A, per segnalare 
  ai verificatori che non arriveranno più numeri;
- termina.

Thread VERIFICATORI (2 thread, identificati VER-1 e VER-2):
- ciascuno, in un ciclo, estrae un numero dalla pila_A;
- se il numero estratto è la sentinella (-1): siccome ci sono 2 verificatori 
  ma un solo valore sentinella, il verificatore che la trova deve reinserirla 
  subito nella pila_A (così anche l'altro verificatore, prima o poi, la trova 
  e si accorge che è finita), poi il ciclo termina per questo verificatore;
- altrimenti, se il numero è pari, lo inserisce nella pila_B stampando 
  "[VER-x] %d pari, inserito in coda B"; se è dispari, lo scarta stampando 
  "[VER-x] %d dispari, scartato";
- una volta uscito dal ciclo (sentinella incontrata), decrementa (in mutua 
  esclusione) il contatore verificatori_attivi della pila_B;
- se il decremento porta il contatore a 0, questo verificatore (l'ultimo 
  rimasto attivo) inserisce un valore sentinella (-1) nella pila_B, per 
  segnalare al main che non arriveranno più numeri pari;
- termina.

Thread MAIN:
- inizializza pila_A e pila_B (mutex, semafori, contatori);
- crea i 2 thread produttori e i 2 thread verificatori;
- in un ciclo, estrae numeri dalla pila_B: se è la sentinella (-1), il ciclo 
  termina; altrimenti stampa "[MAIN] ricevuto pari: %d";
- attende la terminazione di tutti e 4 i thread ausiliari con pthread_join;
- distrugge mutex e semafori di entrambe le pile;
- termina.

Non si devono usare strutture dati con visibilità globale: pila_A e pila_B 
vanno passate ai thread tramite puntatore (argomento di pthread_create).
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
  
  int pila_A[5];
  int topA;
  pthread_mutex_t mutex;
  sem_t semaforoLiberiA;
  sem_t semaforoOccupatiA;

  int pila_B[3];
  int topB;
  pthread_mutex_t mutexB;
  sem_t semaforoLiberiB;
  sem_t semaforoOccupatiB; 

  int produttoriAttivi;
  int consumatoriAttivi;

}shared;

typedef struct{

  int id;
  shared *condivisione;

}datiProduttori;

typedef struct{

  int id;
  shared *condivisione;

}datiVerificatori;

void *gestioneProduttori(void *arg){
  //printf("Produzione\n");

  datiProduttori *dati = (datiProduttori*)arg;

  int numero = 0;
  int casuale = 0;

  do{

    casuale = rand() % (99 - 0 + 1) + 0;

    sem_wait(&dati->condivisione->semaforoLiberiA);
    pthread_mutex_lock(&dati->condivisione->mutex);

    dati->condivisione->topA++;
    dati->condivisione->pila_A[dati->condivisione->topA] = casuale;
    printf("[PROD %d] elemento %d inserito.\n",dati->id,casuale);

    pthread_mutex_unlock(&dati->condivisione->mutex);
    sem_post(&dati->condivisione->semaforoOccupatiA);

    numero++;
  }while(numero < 10);

  //sleep(1);

  struct timespec ts;                             //mi serve per far si che la pila si svuoti e che -1 sia veramente l'ultimo numero quindi aspetto un po
  ts.tv_sec = 0;                  // 0 secondi
  ts.tv_nsec = 55000000;         // 55 milioni di nanosecondi = 0.055 secondi (55 ms)
  nanosleep(&ts, NULL);


  pthread_mutex_lock(&dati->condivisione->mutex);
  printf("IL PRODUTTORE %d HA FINITO.\n",dati->id);
  dati->condivisione->produttoriAttivi--;
  if(dati->condivisione->produttoriAttivi == 0){
    sem_wait(&dati->condivisione->semaforoLiberiA);
    dati->condivisione->topA++;
    dati->condivisione->pila_A[dati->condivisione->topA] = -1;
    sem_post(&dati->condivisione->semaforoOccupatiA);
    //printf("IL PRODUTTORE %d HA INSERITO -1.\n",dati->id);
    pthread_mutex_unlock(&dati->condivisione->mutex);
    free(dati);
    return NULL;
  }
  pthread_mutex_unlock(&dati->condivisione->mutex);  
  free(dati);
  return NULL;
}

void *gestioneVerificatori(void *arg){
  //printf("Verifica\n");
  datiVerificatori *dati = (datiVerificatori*)arg;
  
  while(true){

    int controllo = 0;

    sem_wait(&dati->condivisione->semaforoOccupatiA);
    pthread_mutex_lock(&dati->condivisione->mutex);

    controllo = dati->condivisione->pila_A[dati->condivisione->topA];
    if(controllo == -1 && dati->condivisione->consumatoriAttivi == 2){
      dati->condivisione->consumatoriAttivi--;
      printf("IL VERIFICATORE %d HA FINITO.\n",dati->id);
      pthread_mutex_unlock(&dati->condivisione->mutex);
      sem_post(&dati->condivisione->semaforoOccupatiA);
      free(dati);
      return NULL;

      }else if(controllo == -1 && dati->condivisione->consumatoriAttivi == 1){
        dati->condivisione->pila_A[dati->condivisione->topA] = 0;
        dati->condivisione->topA--;
        printf("IL VERIFICATORE %d HA FINITO.\n",dati->id);
        sem_wait(&dati->condivisione->semaforoLiberiB);
        pthread_mutex_lock(&dati->condivisione->mutexB);
        dati->condivisione->topB++;
        dati->condivisione->pila_B[dati->condivisione->topB] = -1;
        pthread_mutex_unlock(&dati->condivisione->mutexB);
        sem_post(&dati->condivisione->semaforoOccupatiB);

        pthread_mutex_unlock(&dati->condivisione->mutex);
        sem_post(&dati->condivisione->semaforoOccupatiA);
        free(dati);
        return NULL;
        
        }else if(controllo % 2 == 0){
          printf("[VERIF %d] numero %d pari, inserimento in pila B.\n",dati->id,controllo);
      
          sem_wait(&dati->condivisione->semaforoLiberiB);
          pthread_mutex_lock(&dati->condivisione->mutexB);
          dati->condivisione->topB++;
          //printf("DEBUG -> %d ",dati->condivisione->topB);
          dati->condivisione->pila_B[dati->condivisione->topB] = controllo;
              /*for(int i = 0; i < 3; i++){
                printf(" . %d",dati->condivisione->pila_B[i]);
              }
              printf("\n");*/
          pthread_mutex_unlock(&dati->condivisione->mutexB);
          sem_post(&dati->condivisione->semaforoOccupatiB);

          dati->condivisione->pila_A[dati->condivisione->topA] = 0;
          dati->condivisione->topA--;
          }else{
            printf("[VERIF %d] numero %d dispari, numero scartato.\n",dati->id,controllo);
            dati->condivisione->pila_A[dati->condivisione->topA] = 0;
            dati->condivisione->topA--;
          }

    pthread_mutex_unlock(&dati->condivisione->mutex);
    sem_post(&dati->condivisione->semaforoLiberiA);

  }
  free(dati);
  return NULL;

}

int main(){
  srand(time(NULL));

  printf("[MAIN] creo e inizializzo tutti i thread.\n");

  shared *condiviso = malloc(sizeof(shared));

  condiviso->consumatoriAttivi = 2;
  condiviso->produttoriAttivi = 2;
  condiviso->topA = -1;
  condiviso->topB = -1;
  pthread_mutex_init(&condiviso->mutex,NULL);
  pthread_mutex_init(&condiviso->mutexB,NULL);
  sem_init(&condiviso->semaforoLiberiA,0,5);
  sem_init(&condiviso->semaforoOccupatiA,0,0);

  sem_init(&condiviso->semaforoLiberiB,0,3);
  sem_init(&condiviso->semaforoOccupatiB,0,0); 
  
  pthread_t arrayThreadProduttori[2];
  pthread_t arrayThreadVerificatori[2];  

  for(int i = 0; i < 2; i++){
    datiProduttori *dati = malloc(sizeof(datiProduttori));
    dati->id = i;
    dati->condivisione = condiviso;
    pthread_create(&arrayThreadProduttori[i],NULL,gestioneProduttori,dati);
  }

  for(int i = 0; i < 2; i++){
    datiVerificatori *dati = malloc(sizeof(datiVerificatori));
    dati->id = i;
    dati->condivisione = condiviso;
    pthread_create(&arrayThreadVerificatori[i],NULL,gestioneVerificatori,dati);
  }

  //estrazione numeri dalla pilaB
  while(true){

    int numeroEstratto = 0;
    sem_wait(&condiviso->semaforoOccupatiB);
    pthread_mutex_lock(&condiviso->mutexB);

    if(condiviso->pila_B[condiviso->topB] == -1){
      pthread_mutex_unlock(&condiviso->mutexB);
      sem_post(&condiviso->semaforoOccupatiB);

      break;
    }else{
      numeroEstratto = condiviso->pila_B[condiviso->topB];
      condiviso->pila_B[condiviso->topB] = 0;
      condiviso->topB--;
      printf("[MAIN] ricevuto pari: %d.\n",numeroEstratto);
    }
    pthread_mutex_unlock(&condiviso->mutexB);
    sem_post(&condiviso->semaforoLiberiB);

  }

  for(int i = 0; i < 2; i++){
    pthread_join(arrayThreadProduttori[i],NULL);
    pthread_join(arrayThreadVerificatori[i],NULL);
  }
  free(condiviso);
  /*for(int i = 0; i < 5; i++){
    printf(" . %d",condiviso->pila_A[i]);
  }*/

  printf("\nLavoro Terminato.\n");

  return 0;
    
}