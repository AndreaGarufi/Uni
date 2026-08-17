/*Esercizio 28 — Più thread in attesa, broadcast vs signal

Scrivi un programma con 1 thread "starter" e 3 thread "attesa" (tutti uguali tra loro, distinti solo da un id).

I 3 thread "attesa" partono subito, prendono il mutex, e aspettano (while(via == 0) pthread_cond_wait(...)) 
su una variabile condizione condivisa. Appena si svegliano e trovano via == 1, stampano "[THREAD-x] parto!".
Il thread "starter" aspetta 2 secondi, poi imposta via = 1 e chiama pthread_cond_broadcast (non signal!).

Lancialo un paio di volte e osserva: tutti e 3 i thread "attesa" dovrebbero stampare "parto!" praticamente insieme, poco dopo i 2 secondi.*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

typedef struct{

    int via;
    pthread_mutex_t mutex;
    pthread_cond_t cond;

}shared;

typedef struct{

    int id;
    shared *condivisione;

}datiAttesa;

void *gestionePartenza(void *arg){

    shared *condiviso = (shared*)arg;
    printf("STARTER.\n");

    while(true){
        sleep(2);
        pthread_mutex_lock(&condiviso->mutex);
        
        printf("[THREAD STARTER] via = 3.\n");
        condiviso->via = 3;
        pthread_cond_broadcast(&condiviso->cond);
        pthread_mutex_unlock(&condiviso->mutex);
    }
    
}

void *gestioneAttesa(void *arg){

    datiAttesa *dati = (datiAttesa*)arg;
    printf("ATTESA.\n");
    while(true){
        pthread_mutex_lock(&dati->condivisione->mutex);
        while(dati->condivisione->via == 0){
            pthread_cond_wait(&dati->condivisione->cond,&dati->condivisione->mutex);
        }
        dati->condivisione->via--;
        printf("[THREAD %d] parto! via = %d.\n",dati->id,dati->condivisione->via);
        pthread_mutex_unlock(&dati->condivisione->mutex);
    }
}

int main(){

    pthread_t arrayAttesa[3];
    pthread_t threadStarter;

    shared *condiviso = malloc(sizeof(shared));
    condiviso->via = 0;
    pthread_mutex_init(&condiviso->mutex,NULL);
    pthread_cond_init(&condiviso->cond,NULL);

    pthread_create(&threadStarter,NULL,gestionePartenza,condiviso);

    for(int i = 0; i < 3; i++){
        datiAttesa *dati = malloc(sizeof(datiAttesa));
        dati->condivisione = condiviso;
        dati->id = i;
        pthread_create(&arrayAttesa[i],NULL,gestioneAttesa,dati);
    }

    pthread_join(threadStarter,NULL);
    
    for(int i = 0; i < 3; i++){
        pthread_join(arrayAttesa[i],NULL); 
    }

}