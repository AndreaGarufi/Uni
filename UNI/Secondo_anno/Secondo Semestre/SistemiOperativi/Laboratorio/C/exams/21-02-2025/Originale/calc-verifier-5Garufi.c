#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    //se sono = 0 li considero "liberi"
    long long operando1;        //sara calc ha impostarli a 0 una volta che li usa
    long long operando2;
    long long risultato;

    char operazione;

    pthread_cond_t cond1;       //per op1 op2 e ops
    pthread_cond_t cond2;       //per calc

    pthread_mutex_t mutex;

    bool risultato_pronto;

}shared;

typedef struct{

    char *nomeFile;
    int id;
    shared *condivisone;


}datiOP;

typedef struct{

    char *nomeFile;
    shared *condivisione;

}datiOPS;

typedef struct{

    shared *condivisione;

}datiCALC;

void *gestioneOP(void *arg){
    datiOP *dati = (datiOP*)arg; 
    //printf("ENTRA OP %d.\n",dati->id);

    FILE *fileLettura = fopen(dati->nomeFile,"r");
    if(fileLettura == NULL){
        perror("Errore nell' apertura del file.\n");
        exit(EXIT_FAILURE);
    }else{
        printf("[OP %d] leggo gli operandi dai file '%s'.\n",dati->id,dati->nomeFile);
    }

    int numero = 0;
    int contatoreOP1 = 0;
    int contatoreOP2 = 0;
    while(fscanf(fileLettura,"%d",&numero) == 1){

        if(dati->id == 1){  //sono nel caso di op1
            contatoreOP1++;
            pthread_mutex_lock(&dati->condivisone->mutex);
            while(dati->condivisone->operando1 != -1){
                pthread_cond_wait(&dati->condivisone->cond1,&dati->condivisone->mutex);
            }
            dati->condivisone->operando1 = numero;
            printf("[OP %d] primo operando n.%d: %lld.\n",dati->id,contatoreOP1,dati->condivisone->operando1);
            pthread_cond_signal(&dati->condivisone->cond2);  //sveglio calc
            pthread_mutex_unlock(&dati->condivisone->mutex);


        }else{  //sono nel caso op2
            contatoreOP2++;
            pthread_mutex_lock(&dati->condivisone->mutex);
            while(dati->condivisone->operando2 != -1){
                pthread_cond_wait(&dati->condivisone->cond1,&dati->condivisone->mutex);
            }
            dati->condivisone->operando2 = numero;
            printf("[OP %d] secondo operando n.%d: %lld.\n",dati->id,contatoreOP2,dati->condivisone->operando2);
            pthread_cond_signal(&dati->condivisone->cond2);  //sveglio calc
            pthread_mutex_unlock(&dati->condivisone->mutex); 

        }

    }

    //inserisco la sentinella (-2)
    if(dati->id == 1){  //sono nel caso di op1

        pthread_mutex_lock(&dati->condivisone->mutex);
        while(dati->condivisone->operando1 != -1){
            pthread_cond_wait(&dati->condivisone->cond1,&dati->condivisone->mutex);
        }
        dati->condivisone->operando1 = -2;
        printf("[OP 1] termino.\n");
        pthread_cond_signal(&dati->condivisone->cond2);  //sveglio calc
        pthread_mutex_unlock(&dati->condivisone->mutex);


    }else{  //sono nel caso op2
        pthread_mutex_lock(&dati->condivisone->mutex);
        while(dati->condivisone->operando2 != -1){
            pthread_cond_wait(&dati->condivisone->cond1,&dati->condivisone->mutex);
        }
        dati->condivisone->operando2 = -2;
        printf("[OP 2] termino.\n");
        pthread_cond_signal(&dati->condivisone->cond2);  //sveglio calc
        pthread_mutex_unlock(&dati->condivisone->mutex); 
    }   
    
    return NULL;

}

void *gestioneOPS(void *arg){
    datiOPS *dati = (datiOPS*)arg;
    //printf("ENTRA OPS.\n");

    FILE *fileLettura = fopen(dati->nomeFile,"r");
    if(fileLettura == NULL){
        perror("Errore nell' apertura del file.\n");
        exit(EXIT_FAILURE);
    }else{
        printf("[OPS] leggo le operazioni e il risultato atteso dal file '%s'.\n",dati->nomeFile);
    }

    int numeroFinaleFILE = 0;
    int sommatoria = 0;
    char buffer[16];
    int contatore = 0;

    while(fgets(buffer,16,fileLettura) != NULL){
        contatore++;
        if(strstr(buffer,"+") != NULL){
            pthread_mutex_lock(&dati->condivisione->mutex);
            while(dati->condivisione->operazione != 0){
                pthread_cond_wait(&dati->condivisione->cond1,&dati->condivisione->mutex);
            }
            dati->condivisione->operazione = buffer[0];
            printf("[OPS] operazione n.%d: %c.\n",contatore,dati->condivisione->operazione);
            pthread_cond_signal(&dati->condivisione->cond2); //sveglio calc
            pthread_mutex_unlock(&dati->condivisione->mutex);

        }else if(strstr(buffer,"x") != NULL){

            pthread_mutex_lock(&dati->condivisione->mutex);
            while(dati->condivisione->operazione != 0){
                pthread_cond_wait(&dati->condivisione->cond1,&dati->condivisione->mutex);
            }
            dati->condivisione->operazione = buffer[0];
            printf("[OPS] operazione n.%d: %c.\n",contatore,dati->condivisione->operazione);
            pthread_cond_signal(&dati->condivisione->cond2); //sveglio calc
            pthread_mutex_unlock(&dati->condivisione->mutex);

        }else if(strstr(buffer,"-") != NULL){

            pthread_mutex_lock(&dati->condivisione->mutex);
            while(dati->condivisione->operazione != 0){
                pthread_cond_wait(&dati->condivisione->cond1,&dati->condivisione->mutex);
            }
            dati->condivisione->operazione = buffer[0];
            printf("[OPS] operazione n.%d: %c.\n",contatore,dati->condivisione->operazione);
            pthread_cond_signal(&dati->condivisione->cond2); //sveglio calc
            pthread_mutex_unlock(&dati->condivisione->mutex); 

        }else{  //se non è nessuno di questi abbiamo letto il numero;
            numeroFinaleFILE = atoi(buffer);
            printf("[OPS] numero finale che dovrà risultare: %d.\n",numeroFinaleFILE);
            break;
        }
        
        //altra parte di OPS in cui calcola man mano la sommatoria dei risultati
        //sommatoria
        pthread_mutex_lock(&dati->condivisione->mutex);
        while(dati->condivisione->risultato_pronto == false){
            pthread_cond_wait(&dati->condivisione->cond1,&dati->condivisione->mutex);
        }
        sommatoria = sommatoria + dati->condivisione->risultato;
        printf("[OPS] sommatoria dei risultati parziali dopo %d operazione/i: %d.\n",contatore,sommatoria);
        dati->condivisione->risultato_pronto = false;

        pthread_mutex_unlock(&dati->condivisione->mutex);
        
    }

    if(numeroFinaleFILE == sommatoria){
      printf("[OPS] risultato finale atteso: %d (corretto)",sommatoria);  
      return NULL;
    }else{
        fprintf(stderr,"C'è stato qualche problema nella sommatoria: %d (non corretto).\n",sommatoria);
        return NULL;
    }

}

void *gestioneCALC(void *arg){
    datiCALC *dati = (datiCALC*)arg;
    //printf("ENTRA CALC.\n");
    int contatore = 0;
    while(true){

        pthread_mutex_lock(&dati->condivisione->mutex);
        if(dati->condivisione->operando1 == -2 || dati->condivisione->operando2 == -2){

            printf("[CALC] termino.\n");
            pthread_mutex_unlock(&dati->condivisione->mutex);
            free(dati);
            return NULL;
        }
        
        while(dati->condivisione->operando1 == -1 || dati->condivisione->operando2 == -1 || dati->condivisione->operazione == 0){
            pthread_cond_wait(&dati->condivisione->cond2,&dati->condivisione->mutex);
        }

        if(dati->condivisione->operazione == '+'){
            dati->condivisione->risultato = dati->condivisione->operando1 + dati->condivisione->operando2;
        }else if(dati->condivisione->operazione == 'x'){
            dati->condivisione->risultato = dati->condivisione->operando1 * dati->condivisione->operando2;
        }else if(dati->condivisione->operazione == '-'){
            dati->condivisione->risultato = dati->condivisione->operando1 - dati->condivisione->operando2;
        }
        contatore++;
        printf("[CALC] operazione minore n.%d: %lld %c %lld = %lld.\n",contatore,dati->condivisione->operando1,dati->condivisione->operazione,dati->condivisione->operando2,dati->condivisione->risultato);
        dati->condivisione->operando1 = -1;
        dati->condivisione->operando2 = -1;
        dati->condivisione->operazione = 0;
        dati->condivisione->risultato_pronto = true;
        pthread_cond_broadcast(&dati->condivisione->cond1);
        pthread_mutex_unlock(&dati->condivisione->mutex);
    }

}



int main(int argc, char *argv[]){

    if(argc != 4){
        fprintf(stderr,"Errore, devi avviarmi con <first-operands> <second-operands> <operations>.\n");
        exit(EXIT_FAILURE);
    }

    printf("[MAIN] creo i thread ausiliari.\n");
    shared *condiviso = malloc(sizeof(shared));

    condiviso->operando1 = -1;
    condiviso->operando2 = -1;
    condiviso->risultato = 0;
    condiviso->operazione = 0;
    condiviso->risultato_pronto = false;
    pthread_mutex_init(&condiviso->mutex,NULL);
    pthread_cond_init(&condiviso->cond1,NULL);
    pthread_cond_init(&condiviso->cond2,NULL);

    pthread_t OP1,OP2,OPS,CALC;

    datiOP *datiOP1 = malloc(sizeof(datiOP));
    datiOP1->condivisone = condiviso;
    datiOP1->id = 1;
    datiOP1->nomeFile = argv[1];
    pthread_create(&OP1,NULL,gestioneOP,datiOP1);

    datiOP *datiOP2 = malloc(sizeof(datiOP));
    datiOP2->condivisone = condiviso;
    datiOP2->id = 2;
    datiOP2->nomeFile = argv[2];
    pthread_create(&OP2,NULL,gestioneOP,datiOP2);

    datiOPS *datiOPS1 = malloc(sizeof(datiOPS));
    datiOPS1->condivisione = condiviso;
    datiOPS1->nomeFile = argv[3];
    pthread_create(&OPS,NULL,gestioneOPS,datiOPS1);

    datiCALC *datiCALC1 = malloc(sizeof(datiCALC));
    datiCALC1->condivisione = condiviso;
    pthread_create(&CALC,NULL,gestioneCALC,datiCALC1);


    pthread_join(OP1,NULL);
    pthread_join(OP2,NULL);
    pthread_join(OPS,NULL);
    pthread_join(CALC,NULL);


}