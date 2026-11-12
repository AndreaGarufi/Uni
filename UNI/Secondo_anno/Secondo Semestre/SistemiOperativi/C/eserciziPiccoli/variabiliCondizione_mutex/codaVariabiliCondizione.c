/*Esercizio 30 — Coda FIFO bounded con variabili condizione (niente semafori!)

Scrivi un programma che implementa una coda FIFO condivisa di interi con 
capienza massima 3, usando UNA SOLA variabile condizione + un mutex 
(niente sem_t in questo esercizio: l'obiettivo è rifare da zero, con le 
variabili condizione, lo stesso comportamento che prima ottenevi con i 
due semafori).

La coda va implementata con un array di 3 interi + un contatore 
numero_elementi (0 = vuota, 3 = piena), gestita come vera coda FIFO 
(estrazione da posizione 0 + shift degli elementi rimanenti, come hai 
già fatto negli esercizi precedenti).

Struttura dati condivisa:
typedef struct {
    int array[3];
    int numero_elementi;
    pthread_mutex_t mutex;
    pthread_cond_t cond;      // UNA SOLA variabile condizione per entrambi i casi
} Coda;

Le due funzioni push e pop devono avere questa forma:

void push(Coda *c, int valore) {
    pthread_mutex_lock(&c->mutex);
    while (c->numero_elementi == 3) {           // coda piena, aspetto spazio
        pthread_cond_wait(&c->cond, &c->mutex);
    }
    c->array[c->numero_elementi] = valore;
    c->numero_elementi++;
    pthread_cond_broadcast(&c->cond);            // sveglio chi aspettava (produttori E consumatori)
    pthread_mutex_unlock(&c->mutex);
}

int pop(Coda *c) {
    pthread_mutex_lock(&c->mutex);
    while (c->numero_elementi == 0) {            // coda vuota, aspetto un elemento
        pthread_cond_wait(&c->cond, &c->mutex);
    }
    int valore = c->array[0];
    for (int i = 1; i < c->numero_elementi; i++) {
        c->array[i-1] = c->array[i];
    }
    c->numero_elementi--;
    pthread_cond_broadcast(&c->cond);
    pthread_mutex_unlock(&c->mutex);
    return valore;
}

Il thread produttore dovrà:
- inserire nella coda, con push, i numeri interi da 1 a 15 (uno alla volta), 
  stampando ad ogni inserimento "[PROD] inserito %d";
- terminare (per questo esercizio niente sentinella, ci concentriamo solo 
  sul meccanismo cond_wait/broadcast).

Il thread consumatore dovrà:
- estrarre esattamente 15 elementi dalla coda con pop, uno alla volta, 
  stampando ad ogni estrazione "[CONS] estratto %d";
- terminare.

Il main crea i 2 thread, li aspetta con pthread_join, poi distrugge 
mutex e variabile condizione.
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

typedef struct {
    int array[3];
    int numero_elementi;
    pthread_mutex_t mutex;
    pthread_cond_t cond;      // UNA SOLA variabile condizione per entrambi i casi
}Coda;

void push(Coda *c, int valore) {
    pthread_mutex_lock(&c->mutex);
    while (c->numero_elementi == 3) {           // coda piena, aspetto spazio
        pthread_cond_wait(&c->cond, &c->mutex);
    }
    c->array[c->numero_elementi] = valore;
    c->numero_elementi++;
    pthread_cond_broadcast(&c->cond);            // sveglio chi aspettava (produttori E consumatori)
    pthread_mutex_unlock(&c->mutex);
}

int pop(Coda *c) {
    pthread_mutex_lock(&c->mutex);
    while (c->numero_elementi == 0) {            // coda vuota, aspetto un elemento
        pthread_cond_wait(&c->cond, &c->mutex);
    }
    int valore = c->array[0];
    for (int i = 1; i < c->numero_elementi; i++) {
        c->array[i-1] = c->array[i];
    }
    c->numero_elementi--;
    pthread_cond_broadcast(&c->cond);
    pthread_mutex_unlock(&c->mutex);
    return valore;
}

void *gestioneProduzione(void *arg){

    printf("Entra il produttore.\n");
    Coda *coda = (Coda*)arg;

    for(int i = 1; i <= 15; i++){
        push(coda,i);
        printf("[PROD] inserito %d.\n",i);
    }

    return NULL;

}

void *gestioneConsumo(void *arg){

    printf("Entra il consumatore.\n");
    Coda *coda = (Coda*)arg;
    for(int i = 1; i <= 15; i++){
        int k = pop(coda);
        printf("[CONS] estratto %d.\n",k);
    }

    return NULL;
}

int main(){

    Coda *coda = malloc(sizeof(Coda));
    coda->numero_elementi = 0;
    pthread_mutex_init(&coda->mutex,NULL);
    pthread_cond_init(&coda->cond,NULL);

    pthread_t produttore,consumatore;

    pthread_create(&produttore,NULL,gestioneProduzione,coda);
    pthread_create(&consumatore,NULL,gestioneConsumo,coda);

    pthread_join(produttore,NULL);
    pthread_join(consumatore,NULL);

    pthread_mutex_destroy(&coda->mutex);
    pthread_cond_destroy(&coda->cond);
    free(coda);


}