/*Esercizio 15 — Contatore con race condition (senza mutex)
Scrivi un programma che crea 4 thread, ognuno dei quali incrementa una variabile globale contatore per 1.000.000 di volte in un ciclo (contatore++). 
Alla fine, dopo aver fatto pthread_join su tutti e 4, stampa il valore finale di contatore.
Dovresti notare che il risultato non è 4.000.000 come ti aspetteresti — questo dimostra la race condition.*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>

int contatore = 0;

void* gestioneContatore(void *arg){
    for(int i = 0; i < 1000000; i++){
        contatore++;
    }
}

int main(){
    pthread_t threads[4];   // un id per ciascun thread, non sovrascritti

    for(int i = 0; i < 4; i++){
        pthread_create(&threads[i], NULL, gestioneContatore, NULL);
    }

    for(int i = 0; i < 4; i++){
        pthread_join(threads[i], NULL);   // aspetta ESPLICITAMENTE ognuno dei 4
    }

    printf("La variabile contatore dovrebbe essere 4.000.000 ma invece è: %d\n", contatore);


}