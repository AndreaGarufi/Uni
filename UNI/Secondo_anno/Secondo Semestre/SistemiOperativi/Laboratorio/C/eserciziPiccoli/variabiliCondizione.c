/*Scrivi un programma con 2 thread:

thread A: aspetta 3 secondi (sleep(3)), poi stampa "[A] pronto, sveglio B", imposta un flag condiviso pronto = 1, e sveglia chi è in attesa.
thread B: appena parte, controlla il flag condiviso pronto. Se è ancora 0, si mette in attesa sulla variabile condizione. 
Quando viene svegliato, ricontrolla il flag (sempre in un while, mai in un if — è la regola d'oro delle variabili condizione) e, 
se ora è 1, stampa "[B] sveglio, procedo".*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

typedef struct {
    int pronto;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} Shared;

void *gestioneA(void *arg){
    //printf("Entra A.\n");

    Shared *condiviso = (Shared*)arg;

    while(true){
        sleep(3);
        printf("[A] pronto sveglio B.\n");
    
        pthread_mutex_lock(&condiviso->mutex);
        condiviso->pronto = 1;
        pthread_cond_signal(&condiviso->cond);
        pthread_mutex_unlock(&condiviso->mutex);
    }


}

void *gestioneB(void *arg){
    //printf("Entra B.\n");  

    Shared *condiviso = (Shared*)arg;

    while(true){
        pthread_mutex_lock(&condiviso->mutex);
    
        while(condiviso->pronto == 0){
            pthread_cond_wait(&condiviso->cond,&condiviso->mutex);
        }
        printf("[B] sveglio, procedo.\n");
        condiviso->pronto = 0;
        pthread_mutex_unlock(&condiviso->mutex);
    }

}

int main(){
    printf("[MAIN] creo thread A e thread B.\n");

    Shared *condiviso = malloc(sizeof(Shared));
    condiviso->pronto = 0;

    pthread_mutex_init(&condiviso->mutex,NULL);
    pthread_cond_init(&condiviso->cond,NULL);


    pthread_t threadA,threadB;

    pthread_create(&threadA,NULL,gestioneA,condiviso);
    pthread_create(&threadB,NULL,gestioneB,condiviso);

    pthread_join(threadA,NULL);
    pthread_join(threadB,NULL);
}