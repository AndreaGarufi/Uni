/*Esercizio 17 — Parcheggio con posti limitati

Scrivi un programma che simula un parcheggio con solo 3 posti disponibili, a cui provano ad accedere 8 thread (le "macchine").

Crea un semaforo con sem_init(&posti, 0, 3) (attenzione a pshared: qui i thread sono dello stesso processo, quindi va 0).
Ogni thread (macchina) deve:
- stampare "Macchina %d in attesa di un posto\n"
- fare sem_wait (occupare un posto)
- stampare "Macchina %d è entrata nel parcheggio\n"
- restare "parcheggiata" per un tempo casuale (usa sleep(1 + rand() % 3))
- stampare "Macchina %d sta uscendo\n"
- fare sem_post (liberare il posto)
Nel main, crea gli 8 thread passando a ciascuno il proprio numero identificativo 
(attenzione: qui torna utile la tecnica della struct/puntatore per passare un dato diverso a ciascun thread, 
visto che ognuno deve conoscere il proprio numero).*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t posti; // Dichiarazione della variabile semaforo

void *gestioneParcheggio(void *arg){
    
    int id = *(int*)arg;
    printf("Macchina %d in attesa di un posto\n",id);

    sem_wait(&posti);
    printf("Macchina %d parcheggiata per 5 secondi\n",id);
    int valore;
    sem_getvalue(&posti, &valore);
    printf("\nPosti rimanenti: %d. \n",valore);
    sleep(5);
    printf("Macchina %d sta uscendo\n",id);
    sem_post(&posti);

}

int main(){

    sem_init(&posti,0,3);

    pthread_t threads[8];   // un id per ciascun thread, non sovrascritti
    int thread_ids[8]; // Array distinto per salvare gli ID

    for (int i = 0; i < 8; i++) {
        thread_ids[i] = i; // Assegnazione dell'ID univoco
    }

    for(int i = 0; i < 8; i++){
        pthread_create(&threads[i], NULL, gestioneParcheggio, &thread_ids[i]);
    }

    for(int i = 0; i < 8; i++){
        pthread_join(threads[i], NULL);   // aspetta ESPLICITAMENTE ognuno dei 4
    }

    sem_destroy(&posti);
}
