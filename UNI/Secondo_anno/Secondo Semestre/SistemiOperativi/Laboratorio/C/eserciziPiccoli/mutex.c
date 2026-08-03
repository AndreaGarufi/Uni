/*Esercizio 16 — Fix con Mutex
Prendi l'Esercizio 15 e correggilo usando un pthread_mutex_t: proteggi l'incremento di contatore con pthread_mutex_lock/unlock. 
Verifica che ora il risultato finale sia sempre esattamente 4.000.000, ripetendo l'esecuzione più volte.*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>

int contatore = 0;

pthread_mutex_t mutexContatore;

void* gestioneContatore(void *arg){
    for(int i = 0; i < 1000000; i++){
        pthread_mutex_lock(&mutexContatore);
        contatore++;
        pthread_mutex_unlock(&mutexContatore);
    }
}

int main(){
    
    pthread_mutex_init(&mutexContatore,NULL);

    pthread_t threads[4];   // un id per ciascun thread, non sovrascritti

    for(int i = 0; i < 4; i++){
        pthread_create(&threads[i], NULL, gestioneContatore, NULL);
    }

    for(int i = 0; i < 4; i++){
        pthread_join(threads[i], NULL);   // aspetta ESPLICITAMENTE ognuno dei 4
    }
    pthread_mutex_destroy(&mutexContatore);
    printf("La variabile contatore dovrebbe essere 4.000.000 ma invece è: %d\n", contatore);


}