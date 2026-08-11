/*Esercizio 20 — Più produttori, un consumatore

Modifica l'Esercizio 19: crea 3 thread produttori (ognuno inserisce 10 numeri, con un id per distinguerli tipo "[PROD-2] inserito 7") 
che condividono la stessa pila e lo stesso mutex.

Attenzione: ora la sentinella diventa più delicata. 
Come fa il consumatore a sapere quando tutti e 3 i produttori hanno finito, e non solo uno? 
(hint: puoi usare un contatore condiviso protetto da mutex, che ogni produttore decrementa quando finisce; 
l'ultimo produttore che arriva a 0 inserisce la sentinella nella coda).*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <string.h>

typedef struct{

  int arrayPila[5];
  int top;
  pthread_mutex_t mutex,mutexContatori;
  sem_t semaforoLiberi;
  sem_t semaforoOccupati;

  int contatoreProduttori;


}shared;

typedef struct{

  int id;
  shared *condivisione;

}datiProduttori;

void *gestioneInserimento(void *arg){
  //printf("Inserimento.\n");
  datiProduttori *dati = (datiProduttori*)arg;

  for(int i = 1; i <= 10; i++){

    sem_wait(&dati->condivisione->semaforoLiberi);
    pthread_mutex_lock(&dati->condivisione->mutex);

    dati->condivisione->top++;
    dati->condivisione->arrayPila[dati->condivisione->top] = i;
    printf("[PROD - %d] elemento %d inserito.\n",dati->id,i);

    pthread_mutex_unlock(&dati->condivisione->mutex);
    sem_post(&dati->condivisione->semaforoOccupati);
  }

  pthread_mutex_lock(&dati->condivisione->mutexContatori);
  printf("IL PRODUTTORE %d HA FINITO.\n",dati->id);
  dati->condivisione->contatoreProduttori--;  //un produttore ha finito

  if(dati->condivisione->contatoreProduttori == 0){ //se tutti i produttori hanno finito l'ultimo inserira la sentinella
    sem_wait(&dati->condivisione->semaforoLiberi);
    pthread_mutex_lock(&dati->condivisione->mutex);
    dati->condivisione->top++;
    dati->condivisione->arrayPila[dati->condivisione->top] = -1;
    pthread_mutex_unlock(&dati->condivisione->mutex);
    sem_post(&dati->condivisione->semaforoOccupati);
  }

  pthread_mutex_unlock(&dati->condivisione->mutexContatori);


   

  return NULL;
}

void *gestioneEstrazione(void *arg){
  //printf("Estrazione.\n");
  shared *condiviso = (shared*)arg;
  int numeroEstratto = 0;
  while(true){

    //printf("[CONS] elementi nella coda: %d.\n",condiviso->top);
    sem_wait(&condiviso->semaforoOccupati);
    pthread_mutex_lock(&condiviso->mutex);

    numeroEstratto = condiviso->arrayPila[condiviso->top];
    condiviso->arrayPila[condiviso->top] = 0;
    condiviso->top--;
    if(numeroEstratto == -1){
      pthread_mutex_unlock(&condiviso->mutex);
      sem_post(&condiviso->semaforoLiberi);
      break;
    }else{
      printf("[CONS] elemento %d estratto.\n",numeroEstratto);
    }

    pthread_mutex_unlock(&condiviso->mutex);
    sem_post(&condiviso->semaforoLiberi);

  }
  printf("IL CONSUMATORE HA FINITO.\n");
  return NULL;

}

int main(){

  printf("[MAIN] Creo il thread produttore e consumatore\n");

  pthread_t ArraythreadProduttore[3];
  int arrayCodici[3] = {1,2,3};

  pthread_t threadConsumatore;


  shared *condiviso = malloc(sizeof(shared));
  sem_init(&condiviso->semaforoLiberi,0,5);
  sem_init(&condiviso->semaforoOccupati,0,0);
  pthread_mutex_init(&condiviso->mutex,NULL);
  pthread_mutex_init(&condiviso->mutexContatori,NULL);
  condiviso->top = -1;
  condiviso->contatoreProduttori = 3;

  for(int i = 0; i < 3; i++){
    datiProduttori *dati = malloc(sizeof(datiProduttori));
    dati->id = arrayCodici[i];
    dati->condivisione = condiviso;
    pthread_create(&ArraythreadProduttore[i],NULL,gestioneInserimento,dati);
  }

  pthread_create(&threadConsumatore,NULL,gestioneEstrazione,condiviso);

  for(int i = 0; i < 3; i++){
    pthread_join(ArraythreadProduttore[i],NULL);
  }

  pthread_join(threadConsumatore,NULL);

  printf("\nLavoro Terminato.\n");
  pthread_mutex_destroy(&condiviso->mutex);
  sem_destroy(&condiviso->semaforoLiberi);
  sem_destroy(&condiviso->semaforoOccupati);

  free(condiviso);

  return 0;
}