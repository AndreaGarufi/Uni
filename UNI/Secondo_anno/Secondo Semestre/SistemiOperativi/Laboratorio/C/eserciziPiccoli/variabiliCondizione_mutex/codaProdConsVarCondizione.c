/*Esercizio 19bis — Coda condivisa bounded con variabili condizione 
   (produttore/consumatore)

Scrivi un programma che implementa una coda FIFO condivisa di interi con 
capienza massima di 5 elementi, accessibile in modo concorrente da un 
thread produttore e un thread consumatore.

La coda va implementata con un array di 5 interi e un contatore 
numero_elementi che tiene traccia di quanti slot sono occupati (0 = vuota, 
5 = piena). Le operazioni sono:
- inserimento: si aggiunge l'elemento in posizione numero_elementi, poi si 
  incrementa numero_elementi;
- estrazione: si preleva sempre l'elemento in posizione 0 (il più vecchio), 
  poi si spostano con un ciclo for tutti gli elementi rimanenti di una 
  posizione a sinistra, e si decrementa numero_elementi.

Per proteggerla dagli accessi concorrenti serve:
- un mutex, per proteggere le operazioni di lettura/scrittura sull'array e 
  su numero_elementi;
- UNA SOLA variabile condizione (niente semafori in questo esercizio), 
  usata sia per far attendere chi vuole inserire quando la coda è piena, 
  sia per far attendere chi vuole estrarre quando la coda è vuota.

Struttura dati condivisa NON globale

Il thread produttore dovrà:
- inserire nella coda, con una push, i numeri interi da 1 a 20 (uno alla 
  volta), stampando ad ogni inserimento "[PROD] inserito %d";
- una volta inseriti tutti i 20 numeri, inserire (sempre con push) un valore 
  sentinella (-1) che segnali la fine del lavoro al consumatore;
- terminare.

Il thread consumatore dovrà:
- estrarre elementi dalla coda con una pop, uno alla volta, salvando il 
  valore restituito in una variabile locale e stampando ad ogni estrazione 
  "[CONS] estratto %d" (attenzione: usa il valore restituito da pop, non un 
  contatore di ciclo!);
- quando il valore estratto è la sentinella (-1), interrompere il ciclo 
  senza stamparla, e terminare.

Il thread principale (main) dovrà:
- inizializzare correttamente coda, mutex e variabile condizione;
- creare i 2 thread ausiliari (produttore e consumatore);
- attendere la terminazione di entrambi con pthread_join;
- distruggere mutex e variabile condizione (pthread_mutex_destroy, 
  pthread_cond_destroy);
- terminare.

Nota: a differenza della versione con la pila (Esercizio 19), essendo qui 
una VERA coda FIFO, il consumatore riceverà i numeri esattamente nello 
stesso ordine in cui il produttore li ha inseriti — incluso il fatto che la 
sentinella, essendo inserita per ultima, sarà anche l'ultimo valore estratto, 
senza rischio di "seppellire" numeri non ancora consumati (il problema che 
avevi incontrato con la pila).
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

    int arrayCoda[5];
    int numeroElementi;
    pthread_mutex_t mutexCoda;
    pthread_cond_t cond;

}shared;

typedef struct{

    int id;
    shared *condivisione;

}datiProduttori;

typedef struct{

    int id;
    shared *condivisione;

}datiConsumatori;

void *gestioneProduzione(void *arg){
    printf("ENTRA IL PRODUTTORE.\n");
    datiProduttori *dati = (datiProduttori*)arg;

    for(int i = 1; i <= 20; i++){
        pthread_mutex_lock(&dati->condivisione->mutexCoda);
        while(dati->condivisione->numeroElementi >= 5){
            pthread_cond_wait(&dati->condivisione->cond,&dati->condivisione->mutexCoda);
        }
        dati->condivisione->arrayCoda[dati->condivisione->numeroElementi] = i;
        dati->condivisione->numeroElementi++;
        printf("[PROD %d] inserito elemento: %d.\n",dati->id,i);
        pthread_cond_broadcast(&dati->condivisione->cond);
        pthread_mutex_unlock(&dati->condivisione->mutexCoda);
    }

    //inserisco sentinella
    pthread_mutex_lock(&dati->condivisione->mutexCoda);
    while(dati->condivisione->numeroElementi >= 4){
        pthread_cond_wait(&dati->condivisione->cond,&dati->condivisione->mutexCoda);
    }
    dati->condivisione->arrayCoda[dati->condivisione->numeroElementi] = -1;
    dati->condivisione->numeroElementi++;
    //printf("[PROD %d] inserito elemento: %d",dati->id,i);
    pthread_cond_broadcast(&dati->condivisione->cond);
    pthread_mutex_unlock(&dati->condivisione->mutexCoda);    

    return NULL;

}

void *gestioneConsumo(void *arg){
    printf("ENTRA IL CONSUMATORE.\n");
    datiConsumatori *dati = (datiConsumatori*)arg;

    while(true){
        pthread_mutex_lock(&dati->condivisione->mutexCoda);
        while(dati->condivisione->numeroElementi == 0){
            pthread_cond_wait(&dati->condivisione->cond,&dati->condivisione->mutexCoda);
        }
        int valore = dati->condivisione->arrayCoda[0];
        if(valore == -1){
            break;
        }
        printf("[CONS %d] estratto elemento: %d.\n",dati->id,valore);
        for(int i = 1; i < dati->condivisione->numeroElementi; i++){
            dati->condivisione->arrayCoda[i-1] = dati->condivisione->arrayCoda[i];
        }
        dati->condivisione->numeroElementi--;
        pthread_cond_broadcast(&dati->condivisione->cond);
        pthread_mutex_unlock(&dati->condivisione->mutexCoda);
    }

    return NULL;
    
}

int main(){

    pthread_t produttore, consumatore;
    shared *condiviso = malloc(sizeof(shared));

    condiviso->numeroElementi = 0;
    pthread_mutex_init(&condiviso->mutexCoda,NULL);
    pthread_cond_init(&condiviso->cond,NULL);

    datiProduttori *datiPROD = malloc(sizeof(datiProduttori));
    datiPROD->condivisione = condiviso;
    datiPROD->id = 0;

    datiConsumatori *datiCONS = malloc(sizeof(datiConsumatori));
    datiCONS->condivisione = condiviso;
    datiCONS->id = 1;    

    pthread_create(&produttore,NULL,gestioneProduzione,datiPROD);
    pthread_create(&consumatore,NULL,gestioneConsumo,datiCONS);

    pthread_join(produttore,NULL);
    pthread_join(consumatore,NULL);


    pthread_mutex_destroy(&condiviso->mutexCoda);
    pthread_cond_destroy(&condiviso->cond);
    free(condiviso);
    return 0;
}