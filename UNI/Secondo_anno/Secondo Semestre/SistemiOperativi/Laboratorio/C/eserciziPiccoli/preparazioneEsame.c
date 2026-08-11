/*Esercizio 24 — "Multipli-screener": coda FIFO + thread dinamici da riga di comando

Scrivi un programma multipli-screener <M> <file1> <file2> ... <fileN> che:
- legge M (numero di thread verificatori) da argv[1];
- calcola N (numero di thread lettori) dal numero di file passati come 
  argomenti restanti;
- individua, tra tutti i numeri interi contenuti nei file, quelli che sono 
  multipli sia di 3 che di 5 (cioè multipli di 15).

Ogni file di input contiene una sequenza di numeri interi, uno per riga.

Struttura dati "coda_candidati" (condivisa, incapsulata in una struct, NON globale):
- una VERA coda FIFO, implementata con array (capienza massima 8) + un contatore 
  numero_elementi che tiene traccia di quanti slot sono occupati (niente indice 
  circolare: l'elemento più vecchio sta sempre in posizione 0);
- inserimento: si aggiunge un elemento in coda all'array (posizione 
  numero_elementi), poi si incrementa numero_elementi;
- estrazione: si preleva sempre l'elemento in posizione 0, poi si spostano 
  (con un ciclo for) tutti gli elementi rimanenti di una posizione a sinistra, 
  e si decrementa numero_elementi;
- un mutex per proteggere array/numero_elementi;
- un semaforo posti_liberi (init 8) e uno elementi_presenti (init 0);
- un contatore intero lettori_attivi (init N), protetto dallo stesso mutex 
  della coda.

Struttura dati "coda_finale" (condivisa, incapsulata in una struct separata):
- stessa identica struttura FIFO della coda_candidati, ma con capienza massima 5;
- un contatore intero verificatori_attivi (init M).

Thread LETTORI (N thread, identificati READER-1, READER-2, ...):
- ciascuno apre il proprio file e legge i numeri riga per riga (con fgets + 
  atoi, o fscanf);
- per ogni numero letto, lo inserisce nella coda_candidati, stampando 
  "[READER-x] letto %d dal file 'nome.txt'";
- una volta terminata la lettura del file, chiude il file e decrementa (in 
  mutua esclusione) il contatore lettori_attivi della coda_candidati;
- se il decremento porta il contatore a 0, questo lettore (l'ultimo rimasto 
  attivo) inserisce M valori sentinella (-1) nella coda_candidati, uno per 
  ciascun verificatore che dovrà fermarsi (così sei sicuro che OGNI 
  verificatore, prima o poi, ne trovi una);
- termina.

Thread VERIFICATORI (M thread, identificati VERIF-1, VERIF-2, ...):
- ciascuno, in un ciclo, estrae un numero dalla coda_candidati;
- se il numero estratto è la sentinella (-1): decrementa (in mutua esclusione) 
  il contatore verificatori_attivi della coda_finale; se il decremento porta 
  il contatore a 0, questo verificatore (l'ultimo rimasto attivo) inserisce 
  una sentinella (-1) nella coda_finale, per segnalare al main la fine; poi 
  il ciclo termina per questo verificatore;
- altrimenti, se il numero è multiplo di 15, lo inserisce nella coda_finale 
  stampando "[VERIF-x] %d è multiplo di 15!"; se non lo è, lo scarta senza 
  stampare nulla (per non intasare troppo l'output);
- termina dopo aver incontrato la sentinella.

Thread MAIN:
- inizializza coda_candidati e coda_finale;
- crea gli N thread lettori e gli M thread verificatori;
- in un ciclo, estrae numeri dalla coda_finale: se è la sentinella (-1), il 
  ciclo termina; altrimenti stampa "[MAIN] trovato multiplo di 15: %d" e 
  incrementa un contatore locale;
- attende la terminazione di tutti i thread ausiliari con pthread_join;
- distrugge mutex e semafori di entrambe le code;
- stampa "[MAIN] totale multipli di 15 trovati: %d";
- termina.

Non si devono usare strutture dati con visibilità globale. Tutte le strutture 
dati (coda, id thread, nome file) vanno passate ai thread tramite struct 
allocate dinamicamente con malloc, passate come argomento a pthread_create.
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
    
    int codaCandidati[8];
    int numeroElementi;
    pthread_mutex_t mutexCandidati;
    sem_t semaforoLiberi;
    sem_t semaforoOccupati;
    int lettoriAttivi;

    int codaFinale[5];
    int numeroElementiFinale;
    pthread_mutex_t mutexFinale;
    sem_t semaforoLiberiFinale;
    sem_t semaforoOccupatiFinale;
    int verificatoriAttivi;


}shared;

typedef struct{

    int id;
    char *nomeFile;
    shared *condivisione;
    int numeroVerificatoriThread; //per gestire le sentinelle

}datiLettori;

typedef struct{

    int id;
    shared *condivisione;

}datiVerificatori;

bool isMultiply(int numeroEstratto){

    if(numeroEstratto % 3 == 0 && numeroEstratto % 5 == 0){
        return true;
    }else{
        return false;
    }

}

void *gestioneLettura(void *arg){
    //printf("Entrano i lettori.\n");
    datiLettori *dati = (datiLettori*)arg;

    FILE *fileNumeri = fopen(dati->nomeFile,"r");
    if(fileNumeri == NULL){
        perror("Errore nell'apertura del file.\n");
        exit(EXIT_FAILURE);
    }else{
        printf("File aperto correttamente.\n");
    }

    int numero  = 0;

    while((fscanf(fileNumeri,"%d",&numero)) == 1){
        
        //inserimento in coda
        sem_wait(&dati->condivisione->semaforoLiberi);
        pthread_mutex_lock(&dati->condivisione->mutexCandidati);
        
        dati->condivisione->codaCandidati[dati->condivisione->numeroElementi] = numero;
        dati->condivisione->numeroElementi++;
        printf("[READER %d] Elemento %d letto dal file '%s' e inserito nella coda.\n",dati->id,numero,dati->nomeFile);

        pthread_mutex_unlock(&dati->condivisione->mutexCandidati);
        sem_post(&dati->condivisione->semaforoOccupati);
    }

    //abbiamo finito di leggere il file
    pthread_mutex_lock(&dati->condivisione->mutexCandidati);
    dati->condivisione->lettoriAttivi--;
    if(dati->condivisione->lettoriAttivi == 0){
        pthread_mutex_unlock(&dati->condivisione->mutexCandidati);   
        //inserisco M sentinelle
        for(int i = 0; i < dati->numeroVerificatoriThread; i++){
            sem_wait(&dati->condivisione->semaforoLiberi);
            pthread_mutex_lock(&dati->condivisione->mutexCandidati);
            
            dati->condivisione->codaCandidati[dati->condivisione->numeroElementi] = -1;
            dati->condivisione->numeroElementi++;

            pthread_mutex_unlock(&dati->condivisione->mutexCandidati);  
            sem_post(&dati->condivisione->semaforoOccupati);   
        }
        printf("[READER %d] ha finito.\n",dati->id);
        fclose(fileNumeri);
        free(dati);
        return NULL;
    }
    pthread_mutex_unlock(&dati->condivisione->mutexCandidati); 

    printf("[READER %d] ha finito.\n",dati->id);

    fclose(fileNumeri);
    free(dati);
    return NULL;

}

void *gestioneVerifica(void *arg){
    //printf("Entrano i verificatori.\n");
    datiVerificatori *dati = (datiVerificatori*)arg;

    int numeroEstratto = 0;
    while(true){
        
        sem_wait(&dati->condivisione->semaforoOccupati);
        pthread_mutex_lock(&dati->condivisione->mutexCandidati);
        numeroEstratto = dati->condivisione->codaCandidati[0];

        for(int i = 1; i < dati->condivisione->numeroElementi; i++){
            dati->condivisione->codaCandidati[i-1] = dati->condivisione->codaCandidati[i];
        }
        dati->condivisione->numeroElementi--;
        pthread_mutex_unlock(&dati->condivisione->mutexCandidati);        
        sem_post(&dati->condivisione->semaforoLiberi);

        //i controlli vanno fatti ora
        if(numeroEstratto == -1){
            pthread_mutex_lock(&dati->condivisione->mutexFinale);
            dati->condivisione->verificatoriAttivi--;
            if(dati->condivisione->verificatoriAttivi == 0){
                pthread_mutex_unlock(&dati->condivisione->mutexFinale);

                sem_wait(&dati->condivisione->semaforoLiberiFinale);
                pthread_mutex_lock(&dati->condivisione->mutexFinale);
                dati->condivisione->codaFinale[dati->condivisione->numeroElementiFinale] = -1;
                dati->condivisione->numeroElementiFinale++;
                pthread_mutex_unlock(&dati->condivisione->mutexFinale);
                sem_post(&dati->condivisione->semaforoOccupatiFinale);

                free(dati);
                return NULL;
            }
            pthread_mutex_unlock(&dati->condivisione->mutexFinale);
            
            free(dati);
            return NULL;
        }else if(isMultiply(numeroEstratto)){  
            //inserimento in coda finale
            sem_wait(&dati->condivisione->semaforoLiberiFinale);
            pthread_mutex_lock(&dati->condivisione->mutexFinale); 

            dati->condivisione->codaFinale[dati->condivisione->numeroElementiFinale] = numeroEstratto;
            dati->condivisione->numeroElementiFinale++;
            printf("[VERIF-%d] %d è multiplo di 15! Inserimento in coda finale.\n",dati->id,numeroEstratto);

            pthread_mutex_unlock(&dati->condivisione->mutexFinale);    
            sem_post(&dati->condivisione->semaforoOccupatiFinale);

            
        }

    }
            free(dati);
            return NULL;
}

int main(int argc, char *argv[]){

    if(argc < 3){
        perror("Errore devi avviarmi con: <M-verificatori> <file1> <file2> ... <fileN>");
        exit(EXIT_FAILURE);
    }

    int numeroLettori = argc - 2;
    int numeroVerificatori = atoi(argv[1]);

    pthread_t arrayLettori[numeroLettori];
    pthread_t arrayVerificatori[numeroVerificatori];

    shared *condiviso = malloc(sizeof(shared)); //alloco struct per dati condivisi e la inizializzo

    condiviso->lettoriAttivi = numeroLettori;
    condiviso->verificatoriAttivi = numeroVerificatori;
    condiviso->numeroElementi = 0;
    condiviso->numeroElementiFinale = 0;
    pthread_mutex_init(&condiviso->mutexCandidati,NULL);
    pthread_mutex_init(&condiviso->mutexFinale,NULL);
    sem_init(&condiviso->semaforoLiberi,0,8);
    sem_init(&condiviso->semaforoOccupati,0,0);
    sem_init(&condiviso->semaforoLiberiFinale,0,5);
    sem_init(&condiviso->semaforoOccupatiFinale,0,0);

    printf("[MAIN] Creo %d Threads verificatori e %d Thread Lettori.\n",numeroVerificatori,numeroLettori);

    for(int i = 0; i < numeroLettori; i++){
        datiLettori *dati = malloc(sizeof(datiLettori));
        dati->condivisione = condiviso;
        dati->id = i;
        dati->nomeFile = argv[i+2];
        dati->numeroVerificatoriThread = numeroVerificatori;
        pthread_create(&arrayLettori[i],NULL,gestioneLettura,dati);
    }

    for(int i = 0; i < numeroVerificatori; i++){
        datiVerificatori *dati = malloc(sizeof(datiVerificatori));
        dati->condivisione = condiviso;
        dati->id = i;
        pthread_create(&arrayVerificatori[i],NULL,gestioneVerifica,dati);
    }

    //estraggo dalla coda finale

    int numeroEstratto = 0;
    int contatore = 0;
    while(true){

        sem_wait(&condiviso->semaforoOccupatiFinale);
        pthread_mutex_lock(&condiviso->mutexFinale);
        numeroEstratto = condiviso->codaFinale[0];

        for(int i = 1; i < condiviso->numeroElementiFinale; i++){
            condiviso->codaFinale[i-1] = condiviso->codaFinale[i];
        }
        condiviso->numeroElementiFinale--;
        pthread_mutex_unlock(&condiviso->mutexFinale);        
        sem_post(&condiviso->semaforoLiberiFinale);

        if(numeroEstratto == -1){
            break;
        }else{
            printf("[MAIN] trovato multiplo di 15: %d\n",numeroEstratto);
            contatore++;
        }

    }

    for(int i = 0; i < numeroLettori; i++){
        pthread_join(arrayLettori[i],NULL);
    }

    for(int i = 0; i < numeroVerificatori; i++){
        pthread_join(arrayVerificatori[i],NULL);
    }

    printf("\nTotale numeri multipli di 15 trovati: %d.\n",contatore);

    pthread_mutex_destroy(&condiviso->mutexCandidati);
    pthread_mutex_destroy(&condiviso->mutexFinale);
    sem_destroy(&condiviso->semaforoLiberi);
    sem_destroy(&condiviso->semaforoLiberiFinale);
    sem_destroy(&condiviso->semaforoOccupati);
    sem_destroy(&condiviso->semaforoOccupatiFinale);
    free(condiviso);
    return 0;

}