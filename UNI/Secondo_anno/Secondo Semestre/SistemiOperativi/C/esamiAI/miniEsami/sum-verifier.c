/*ESERCIZIO STILE COMPITO 2 — con VARIABILI CONDIZIONE

Creare un programma sum-verifier.c in linguaggio C che accetti invocazioni 
sulla riga di comando del tipo:

sum-verifier <file-A> <file-B> <file-OPS>

Il programma verifica una sommatoria descritta a cavallo di 3 file: 
file-A e file-B contengono ciascuno una sequenza di interi (un numero per 
riga), file-OPS contiene una sequenza di segni '+' o '-' (uno per riga, 
uno per ogni coppia di numeri), seguiti nell'ultima riga dal risultato 
finale atteso.

Esempio: se file-A contiene "10, 4", file-B contiene "3, 7" e file-OPS 
contiene "+, -" seguito dal risultato finale, il programma calcola 
(10+3) + (4-7) e verifica se coincide con quanto dichiarato.

Al suo avvio il programma creerà 3 thread ausiliari oltre al main:
- un thread LETTORE_A che legge i numeri da file-A;
- un thread LETTORE_B che legge i numeri da file-B;
- un thread CALC che, per ogni coppia di numeri e relativo segno, calcola 
  il risultato dell'operazione e lo accumula in una sommatoria locale.

Il thread LETTORE_A e il thread LETTORE_B depositano, ciascuno, un solo 
numero alla volta in una struttura dati condivisa, segnalandone la 
disponibilità; il thread CALC legge anche il segno direttamente dal file 
file-OPS (leggilo tu stesso all'interno del thread CALC, riga per riga, 
in parallelo a quando riceve i due numeri) e calcola l'operazione minore 
solo quando ENTRAMBI i numeri (da A e da B) sono disponibili.

I thread si coordineranno usando ESATTAMENTE una variabile condizione e 
un mutex (niente semafori in questo esercizio). La struttura dati 
condivisa conterrà:
- numero_a (long long), numero_b (long long);
- due flag booleani a_pronto e b_pronto;
- eventuali altri flag/contatori utili al coordinamento.

Il thread CALC, dopo aver consumato una coppia di numeri, li rimette 
"liberi" (a_pronto = 0, b_pronto = 0) e sveglia i due lettori con un 
pthread_cond_broadcast (dato che entrambi potrebbero essere in attesa 
sulla stessa variabile condizione, per motivi diversi: LETTORE_A aspetta 
"a libero", LETTORE_B aspetta "b libero").

Ogni lettore, terminata la lettura del proprio file, segnala la propria 
terminazione con un flag dedicato (es. a_finito, b_finito); il thread 
CALC, quando rileva che uno dei due lettori ha finito, termina anch'esso, 
stampa la sommatoria finale accumulata e la confronta con il risultato 
atteso letto dall'ultima riga di file-OPS.

Non si devono usare strutture dati con visibilità globale.

Output atteso (esempio con 3 operazioni):
[MAIN] creazione dei thread ausiliari
[LETTORE-A] leggo i numeri dal file 'file-A'
[LETTORE-B] leggo i numeri dal file 'file-B'
[LETTORE-A] letto operando 10
[LETTORE-B] letto operando 3
[CALC] operazione: 10 + 3 = 13
[LETTORE-A] letto operando 4
[LETTORE-B] letto operando 7
[CALC] operazione: 4 - 7 = -3
[CALC] sommatoria parziale dopo 2 operazioni: 10
...
[LETTORE-A] termino
[LETTORE-B] termino
[CALC] sommatoria finale: 10, atteso: 10 (corretto)
[CALC] termino
[MAIN] terminazione

Tempo suggerito: 55 minuti
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
#include <time.h>

typedef struct{

  long numeroA;
  long numeroB;

  bool aPronto;
  bool bPronto;

  pthread_mutex_t mutex;
  pthread_cond_t cond;

  bool aFinito;
  bool bFinito;  

}shared;

typedef struct{

  char *fileName;
  shared *condivisione;

}datiLettori;

typedef struct{

  shared *condivisione;
  char *fileName;

}datiCalc;

void *gestioneA(void *arg){
  datiLettori *datiA = (datiLettori*)arg;
  //printf("ENTRA A.\n");

  FILE *fileLettura = fopen(datiA->fileName,"r");
  if(fileLettura == NULL){
    perror("Errore nell'apertura del file:");
    exit(EXIT_FAILURE);
  }else{
    printf("[LETTORE A] file '%s'.\n",datiA->fileName);
  }

  long addendo = 0;
  while((fscanf(fileLettura,"%ld",&addendo)) == 1){

    pthread_mutex_lock(&datiA->condivisione->mutex);
    while(datiA->condivisione->aPronto == true){
      pthread_cond_wait(&datiA->condivisione->cond,&datiA->condivisione->mutex);
    }
    datiA->condivisione->numeroA = addendo;
    printf("[LETTORE A] letto addendo %ld.\n",datiA->condivisione->numeroA);
    datiA->condivisione->aPronto = true;
    pthread_cond_broadcast(&datiA->condivisione->cond);
    pthread_mutex_unlock(&datiA->condivisione->mutex);

  }

  //finito di leggere
  pthread_mutex_lock(&datiA->condivisione->mutex);
  while(datiA->condivisione->aPronto == true){
    pthread_cond_wait(&datiA->condivisione->cond,&datiA->condivisione->mutex);
  }

  datiA->condivisione->aFinito = true;
  printf("[LETTORE A] termino.\n");
  pthread_cond_broadcast(&datiA->condivisione->cond);
  pthread_mutex_unlock(&datiA->condivisione->mutex);  

  fclose(fileLettura);
  return NULL;

}

void *gestioneB(void *arg){
  datiLettori *datiB = (datiLettori*)arg;
  //printf("ENTRA B.\n");

  FILE *fileLettura = fopen(datiB->fileName,"r");
  if(fileLettura == NULL){
    perror("Errore nell'apertura del file:");
    exit(EXIT_FAILURE);
  }else{
    printf("[LETTORE B] file '%s'.\n",datiB->fileName);
  }

  long addendo = 0;
  while((fscanf(fileLettura,"%ld",&addendo)) == 1){

    pthread_mutex_lock(&datiB->condivisione->mutex);
    while(datiB->condivisione->bPronto == true){
      pthread_cond_wait(&datiB->condivisione->cond,&datiB->condivisione->mutex);
    }
    datiB->condivisione->numeroB = addendo;
    printf("[LETTORE B] letto addendo %ld.\n",datiB->condivisione->numeroB);
    datiB->condivisione->bPronto = true;
    pthread_cond_broadcast(&datiB->condivisione->cond);
    pthread_mutex_unlock(&datiB->condivisione->mutex);

  }

  //finito di leggere
  pthread_mutex_lock(&datiB->condivisione->mutex);
  while(datiB->condivisione->bPronto == true){
    pthread_cond_wait(&datiB->condivisione->cond,&datiB->condivisione->mutex);
  }

  datiB->condivisione->bFinito = true;
  printf("[LETTORE B] termino.\n");
  pthread_cond_broadcast(&datiB->condivisione->cond);
  pthread_mutex_unlock(&datiB->condivisione->mutex);  

  fclose(fileLettura);  
  return NULL;


  
}

void *gestioneCALC(void *arg){
  datiCalc *dati = (datiCalc*)arg;
  //printf("ENTRA CALC.\n");

  FILE *fileLettura = fopen(dati->fileName,"r");
  if(fileLettura == NULL){
    perror("Errore nell'apertura del file:");
    exit(EXIT_FAILURE);
  }else{
    printf("[CALC] file '%s'.\n",dati->fileName);
  } 

  char operazione;
  long risultato = 0;
  int contatore = 1;
  long sommatoria = 0;
  while(true){

    pthread_mutex_lock(&dati->condivisione->mutex);
    while((dati->condivisione->aPronto == false || dati->condivisione->bPronto == false) && (dati->condivisione->aFinito == false || dati->condivisione->bFinito == false)){
      pthread_cond_wait(&dati->condivisione->cond,&dati->condivisione->mutex);
    }
    if(dati->condivisione->aFinito == true || dati->condivisione->bFinito == true){
      pthread_mutex_unlock(&dati->condivisione->mutex);
      break;
    }

    fscanf(fileLettura," %c",&operazione);
    if(operazione == '+'){
      risultato = dati->condivisione->numeroA + dati->condivisione->numeroB;
      printf("[CALC] operazione %ld + %ld = %ld.\n",dati->condivisione->numeroA,dati->condivisione->numeroB,risultato);
    }else if(operazione == '-'){
      risultato = dati->condivisione->numeroA - dati->condivisione->numeroB;
      printf("[CALC] operazione %ld - %ld = %ld.\n",dati->condivisione->numeroA,dati->condivisione->numeroB,risultato);
    }
    sommatoria = sommatoria + risultato;
    printf("[CALC] sommatoria dopo %d operazioni = %ld.\n",contatore,sommatoria);
    contatore++;
    dati->condivisione->aPronto = false;
    dati->condivisione->bPronto = false;
    pthread_cond_broadcast(&dati->condivisione->cond);
    pthread_mutex_unlock(&dati->condivisione->mutex);

  }

  long totale = 0;
  fscanf(fileLettura,"%ld",&totale);

  if(sommatoria == totale){
    printf("[CALC] sommatoria: %ld, risultato atteso: %ld. (corretto).\n",sommatoria,totale);
  }else{
    printf("[CALC] sommatoria: %ld, risultato atteso: %ld. (non corretto).\n",sommatoria,totale);
  }

  fclose(fileLettura);
  return NULL;
  
}


int main(int argc, char *argv[]){

  if(argc < 4){
    fprintf(stderr,"Errore devi avviarmi con: <file-A> <file-B> <file-OPS>.\n");
    exit(EXIT_FAILURE);
  }

  shared *condiviso = malloc(sizeof(shared));

  condiviso->aPronto = false;
  condiviso->bPronto = false;
  condiviso->aFinito = false;
  condiviso->bFinito = false;
  pthread_mutex_init(&condiviso->mutex,NULL);
  pthread_cond_init(&condiviso->cond,NULL);
  condiviso->numeroA = 0;
  condiviso->numeroB = 0;

  pthread_t lettoreA,lettoreB,calc;

  datiLettori *datiA = malloc(sizeof(datiLettori));
  datiA->condivisione = condiviso;
  datiA->fileName = argv[1];
  pthread_create(&lettoreA,NULL,gestioneA,datiA);

  datiLettori *datiB = malloc(sizeof(datiLettori));
  datiB->condivisione = condiviso;
  datiB->fileName = argv[2]; 
  pthread_create(&lettoreB,NULL,gestioneB,datiB);  

  datiCalc *dati = malloc(sizeof(datiCalc));
  dati->condivisione = condiviso;
  dati->fileName = argv[3];
  pthread_create(&calc,NULL,gestioneCALC,dati);
  
  pthread_join(lettoreA,NULL);
  pthread_join(lettoreB,NULL);
  pthread_join(calc,NULL);

  printf("[MAIN] terminazione.\n");

  free(dati);
  free(datiA);
  free(datiB);

  pthread_mutex_destroy(&condiviso->mutex);
  pthread_cond_destroy(&condiviso->cond);
  free(condiviso);

  return 0;

}