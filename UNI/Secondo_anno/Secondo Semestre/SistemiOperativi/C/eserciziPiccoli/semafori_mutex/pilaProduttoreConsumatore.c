/*Esercizio 19 — Pila condivisa bounded (produttore/consumatore)

Scrivi un programma che implementa una pila (stack, LIFO) condivisa di interi 
con capienza massima di 5 elementi, accessibile in modo concorrente da un 
thread produttore e un thread consumatore.

La pila va implementata con un array di 5 interi e un indice top che tiene 
traccia della prossima posizione libera. Per proteggerla dagli accessi 
concorrenti serve:
- un mutex, per proteggere le operazioni di lettura/scrittura sull'array e su top;
- un semaforo posti_liberi, inizializzato a 5, che si occupa di far attendere 
  chi vuole inserire (push) quando la pila è piena;
- un semaforo elementi_presenti, inizializzato a 0, che si occupa di far 
  attendere chi vuole estrarre (pop) quando la pila è vuota.

Il thread produttore dovrà:
- inserire nella pila, con una push, i numeri interi da 1 a 20 (uno alla volta), 
  stampando ad ogni inserimento "[PROD] inserito %d";
- una volta inseriti tutti i 20 numeri, inserire un valore sentinella (-1) 
  che segnali la fine del lavoro al consumatore;
- terminare.

Il thread consumatore dovrà:
- estrarre elementi dalla pila con una pop, uno alla volta, stampando ad ogni 
  estrazione "[CONS] estratto %d";
- quando il valore estratto è la sentinella (-1), interrompere il ciclo senza 
  stampare la sentinella stessa, e terminare.

Il thread principale (main) dovrà:
- inizializzare correttamente pila, mutex e semafori;
- creare i 2 thread ausiliari (produttore e consumatore);
- attendere la terminazione di entrambi con pthread_join;
- distruggere mutex e semafori (pthread_mutex_destroy, sem_destroy);
- terminare.

Non si devono usare variabili globali: la pila, il mutex e i semafori vanno 
incapsulati in una struttura dati, il cui indirizzo sarà passato come unico 
argomento a entrambi i thread tramite pthread_create.

Nota: essendo una pila (LIFO, Last In First Out), l'ordine con cui il 
consumatore riceve i numeri sarà in generale diverso dall'ordine di inserimento 
del produttore — non è un errore, è il comportamento atteso di questa struttura 
dati.
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

typedef struct{

  int arrayPila[5];
  int top;
  pthread_mutex_t mutex;
  sem_t semaforoLiberi;
  sem_t semaforoOccupati;


}shared;

void *gestioneInserimento(void *arg){
  //printf("Inserimento.\n");
  shared *condiviso = (shared*)arg;

  for(int i = 1; i <= 20; i++){

    sem_wait(&condiviso->semaforoLiberi);
    pthread_mutex_lock(&condiviso->mutex);

    condiviso->top++;
    condiviso->arrayPila[condiviso->top] = i;
    printf("[PROD] elemento %d inserito.\n",i);

    pthread_mutex_unlock(&condiviso->mutex);
    sem_post(&condiviso->semaforoOccupati);
    
  }
    sleep(1); //mi accerto che prima di mettere la sentinella la pila si vuoti altrimenti il consumatore potrebbe leggere la sentinella e fermarsi prima di aver tolto tutti gli elementi
      //ultimo inserimento di -1 (valore sentinella)
    sem_wait(&condiviso->semaforoLiberi);
    pthread_mutex_lock(&condiviso->mutex);

    condiviso->top++;
    condiviso->arrayPila[condiviso->top] = -1;

    pthread_mutex_unlock(&condiviso->mutex);
    sem_post(&condiviso->semaforoOccupati);    

  return NULL;
}

void *gestioneEstrazione(void *arg){
  //printf("Estrazione.\n");
  shared *condiviso = (shared*)arg;
  int numeroEstratto = 0;
  for(int i = 1; i <= 20; i++){

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
  return NULL;

}

int main(){

  printf("[MAIN] Creo il thread produttore e consumatore\n");

  pthread_t threadProduttore;    
  pthread_t threadConsumatore;

  shared *condiviso = malloc(sizeof(shared));
  sem_init(&condiviso->semaforoLiberi,0,5);
  sem_init(&condiviso->semaforoOccupati,0,0);
  pthread_mutex_init(&condiviso->mutex,NULL);
  condiviso->top = -1;

  pthread_create(&threadProduttore,NULL,gestioneInserimento,condiviso);
  pthread_create(&threadConsumatore,NULL,gestioneEstrazione,condiviso);

  pthread_join(threadProduttore,NULL);
  pthread_join(threadConsumatore,NULL);

  printf("\nLavoro Terminato.\n");
  pthread_mutex_destroy(&condiviso->mutex);
  sem_destroy(&condiviso->semaforoLiberi);
  sem_destroy(&condiviso->semaforoOccupati);

  free(condiviso);

  return 0;
}