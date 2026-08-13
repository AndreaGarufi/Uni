/*Devi sincronizzare due thread (Produttore e Consumatore) che condividono un singolo intero (int buffer), usato come canale di comunicazione.

Il Produttore:
Genera i numeri da 1 a 5 e li inserisce uno alla volta in buffer.
Quando ha finito, inserisce -1 nel buffer per segnalare la fine dei dati e termina.

Il Consumatore:
Legge i valori da buffer e li stampa a schermo ("Consumato: X").
Se legge -1, stampa "Fine" e termina.

⚙️ Vincoli di Sincronizzazione
Il buffer ha capienza 1 (contiene un solo numero alla volta).
Il Produttore non deve sovrascrivere un valore se il Consumatore non l'ha ancora letto.
Il Consumatore non deve leggere lo stesso valore due volte, né accedere prima che sia stato prodotto.
Usa due semafori (spazio_disponibile, dato_pronto) per gestire l'alternanza e un mutex per proteggere la lettura/scrittura su buffer.*/

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

    int buffer[1];
    sem_t spazioDisponibile;
    sem_t dato_pronto;

    pthread_mutex_t mutex;

}shared;


void *gestioneProduzione(void *arg){

    shared *condiviso = (shared*)arg;

    for(int i = 1; i < 6; i++){

        sem_wait(&condiviso->spazioDisponibile);
        pthread_mutex_lock(&condiviso->mutex);

        condiviso->buffer[0] = i;
        printf("Prodotto %d.\n",i);

        pthread_mutex_unlock(&condiviso->mutex);
        sem_post(&condiviso->dato_pronto);
    }


    sem_wait(&condiviso->spazioDisponibile);
    pthread_mutex_lock(&condiviso->mutex);

    condiviso->buffer[0] = -1;

    pthread_mutex_unlock(&condiviso->mutex);
    sem_post(&condiviso->dato_pronto);    


    return NULL;
}

void *gestioneConsumo(void *arg){

    shared *condiviso = (shared*)arg;

    while(true){
        int numero = 0;

        sem_wait(&condiviso->dato_pronto);
        pthread_mutex_lock(&condiviso->mutex);

        numero = condiviso->buffer[0];

        if(numero == -1){
            pthread_mutex_unlock(&condiviso->mutex);
            sem_post(&condiviso->spazioDisponibile); 
            break;
        }else{
            printf("Consumato numero %d.\n",numero);
        }


        pthread_mutex_unlock(&condiviso->mutex);
        sem_post(&condiviso->spazioDisponibile);  

    }
    

    return NULL;
}

int main(){

    printf("[MAIN] creo il thread produttore e il thread consumatore.\n");

    pthread_t threadProduttore;
    
    pthread_t threadConsumatore;

    shared *condiviso = malloc(sizeof(shared));
    sem_init(&condiviso->dato_pronto,0,0);
    sem_init(&condiviso->spazioDisponibile,0,1);
    pthread_mutex_init(&condiviso->mutex,NULL);

    pthread_create(&threadProduttore,NULL,gestioneProduzione,condiviso);
    pthread_create(&threadConsumatore,NULL,gestioneConsumo,condiviso);

    pthread_join(threadProduttore,NULL);
    pthread_join(threadConsumatore,NULL);   

    printf("LAVORO TERMINATO.\n");

}