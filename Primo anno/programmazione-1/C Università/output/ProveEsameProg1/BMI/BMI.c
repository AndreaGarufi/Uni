/*A. Prenda in input da riga di comando un parametro stringa “input” che contenga il nome di un
file con estensione “txt” (ad esempio “file_di_input.txt”), e un parametro stringa “output” che
contenga il nome di un file con estensione “txt” (ad esempio “file_di_output.txt”). Il
programma controlla che l’utente abbia specificato il numero corretto di parametri e che i
nomi dei file abbiano effettivamente estensione “txt”. Se i parametri passati non rispettano i
requisiti richiesti, il programma stampa un messaggio di errore sullo standard error e termina
la sua esecuzione con un appropriato codice di terminazione.
Si stampino a schermo i valori dei parametri ricevuti dall’utente.

B. Legga il contenuto del file e salvi i dati relativi in una lista concatenata A. Il file di testo
contiene diverse righe relative a persone con associate età, pesi (in kg), altezze (in cm) e sesso:
nome cognome età peso altezza sesso
Ciascun dato contenuto nella lista concatenata deve essere una struct. Si assuma che nome e
cognome siano delle stringhe di lunghezza massima 255 caratteri, età, peso e altezza
siano tre interi, e sesso sia un carattere. I dati vanno inseriti nella lista in ordine di età.
Si stampi a schermo il contenuto della lista dopo gli inserimenti.

C. Determini l’elemento in A con più alto indice di massa corporea. Dato un soggetto di peso p
(in kg) e altezza a (in cm), l’indice di massa corporea è calcolato come segue:

(guarda pdf per la formula)

Si stampi a schermo l’elemento individuato.

D. Inizializzi una nuova lista concatenata vuota B. Sposti i tre elementi con più alto indice di
massa corporea dalla lista A alla lista B. Tali inserimenti vanno effettuati in testa.
Suggerimento: lo spostamento può essere effettuato ripetendo per tre volte le operazioni di
ricerca dell’elemento con più alto indice di massa corporea, inserimento di copia
dell’elemento in B e cancellazione dell’elemento da A.
Si stampino a schermo i contenuti della lista A e della lista B dopo le operazioni di
spostamento.

E. Salvi il contenuto della lista B sul file il cui nome è indicato dal parametro “output”. Il file di
output dovrà seguire lo stesso formato del file di input.
Nota: gestire opportunamente i casi in cui i file non possono essere correttamente aperti in lettura o
scrittura stampando un errore sullo standard error e terminando l’esecuzione del programma.

Specifiche

- readInput: funzione che prende in input il vettore argv e il numero argc della funzione main(),
controlli la presenza ed i requisiti degli argomenti e li inserisca in un record (struct) da
restituire allo user code (funzione main). La funzione deve gestire correttamente gli errori
relativi a input non corretti;

- readFile: funzione per la lettura del contenuto del file. La funzione prende in input il nome
del file da leggere e restituisce un riferimento alla testa della lista concatenata.

- imc: funzione che calcola l’indice di massa corporea di un dato elemento della lista.

- getMax: funzione che restituisce l’elemento con il più alto indice di massa corporea.

- writeFile: funzione per la scrittura del contenuto di una lista su file come specificato nel punto
E.*/

//.\a.exe file_di_input.txt file_di_output.txt  <--- inserire da riga di comando per avviarlo correttamente

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


struct datiPersone{     //struct contenente i dati delle persone da leggere da file di input e creare poi la lista come indicato nel pdf
    char nome[255];
    char cognome[255];
    int eta;
    int peso;
    int altezza;
    char sesso;

    struct datiPersone *nextPtr;
};
typedef struct datiPersone datiPersone;

struct B{     //struct contenente i dati delle 3 persone con IMC più alto come indicato nel pdf
    char nome[255];
    char cognome[255];
    int eta;
    int peso;
    int altezza;
    char sesso;

    struct B *nextPtr;
};
typedef struct B B; 

void readInput(int dim, char *argv[]);
datiPersone *readFile(char nomeFile[], int dim);
void imc(datiPersone *headPtr);

//inizio main
int main(int argc, char *argv[]){

readInput(argc,argv);

datiPersone *testaPtr = NULL;

char nomeFile[18] = {0};
strcpy(nomeFile,argv[1]);

testaPtr = readFile(nomeFile,18);

imc(testaPtr);
}

void readInput(int argc, char *argv[]){
    printf("\nREAD INPUT\n");

    printf("Parametri passati (%d):",argc-1);

    for(int i = 1; i < argc; i++){
        puts("");
        printf("%s",argv[i]);
    }
    puts("");
    if(argc != 3){
        printf("\nHai inserito il numero sbagliato di parametri, chiusura programma...\n");
        fprintf(stderr,"-1");
        exit(-1);
    }else{
        printf("Numero di parametri inseriti OK\n");
    }
   
    if(strcmp(argv[1], "file_di_input.txt") != 0 || strcmp(argv[2], "file_di_output.txt") != 0){
        fprintf(stderr,"-1");
        exit(-1);  
    }else{
        printf("Parametri inseriti OK\n");
    }
}

datiPersone *readFile(char nomeFile[], int dim){
    printf("\nREAD FILE\n");

    datiPersone dati;
    FILE *filePtr = NULL;

    if((filePtr = fopen("file_di_input.txt","r")) == NULL){
        printf("nFILE NON APERTO\n");
    }else{
        printf("\nFILE APERTO CORRETTAMENTE\n");
    }

    fseek(filePtr,0,SEEK_SET);  //mi sposto all'inizio del file per cominciare a prendere i dati da inserire nella lista
    puts("");

    datiPersone *headPtr = NULL;
    datiPersone *newPtr = NULL;

    for(int i = 0; i < 10; i++){      
        if(i == 0){
            headPtr = malloc(sizeof(datiPersone)); //creazione primo nodo della lista
            }else if(i == 1){
                newPtr = headPtr->nextPtr = malloc(sizeof(datiPersone));  // creazione del secondo nodo (questo avviene al secondo ciclo)
                }else{
                    newPtr = newPtr->nextPtr = malloc(sizeof(datiPersone));  // creazione altri nodi
                }
                if(i == 9){
                    printf("\ncreazione 10 nodi\n\n");
                }
    }

    newPtr = headPtr;
    
    //riempimento delle liste
        
        while(newPtr != NULL){
            while(fscanf(filePtr,"%249s %249s %d %d %d %c",dati.nome,dati.cognome,&dati.eta,&dati.peso,&dati.altezza,&dati.sesso) == 6){    //se scanf legge 6 dati ritorna il 6 quindi quando il 6 non ritorna esce dal ciclo    
                strcpy(newPtr->nome, dati.nome);
                strcpy(newPtr->cognome, dati.cognome);
                newPtr->eta = dati.eta;
                newPtr->peso = dati.peso;
                newPtr->altezza = dati.altezza;
                newPtr->sesso = dati.sesso;

                newPtr = newPtr->nextPtr;
        }
    }

    int i = 0;
    newPtr = headPtr;
    while(newPtr != NULL){
        i++;
        printf("NUMERO NODO %d -> %s %s %d %d %d %c\n",i,newPtr->nome,newPtr->cognome,newPtr->eta,newPtr->peso,newPtr->altezza,newPtr->sesso);
        newPtr = newPtr->nextPtr;
    }


    printf("\nORIDNAMENTO IN BASE ALL'ETA'...\n");            //implementa bubble sort lista

    //bubble sort
    datiPersone *successivoPtr = NULL;

while (1) { 
    int scambiato = 0; 
    datiPersone *precedentePtr = NULL; // Per tenere traccia del nodo precedente
    datiPersone *newPtr = headPtr; 
    datiPersone *successivoPtr = newPtr->nextPtr;

    while (successivoPtr != NULL) { 
        if (newPtr->eta > successivoPtr->eta) {
            // Gestione dello scambio
            if (precedentePtr == NULL) {
                // Se stiamo scambiando il primo nodo
                headPtr = successivoPtr;
            } else {
                // Collegamento del nodo precedente al successivo
                precedentePtr->nextPtr = successivoPtr;
            }

            // Scambio dei puntatori nextPtr
            newPtr->nextPtr = successivoPtr->nextPtr;
            successivoPtr->nextPtr = newPtr;

            // Segnala che è avvenuto uno scambio
            scambiato = 1;

            // Aggiorna i puntatori per il prossimo ciclo
            precedentePtr = successivoPtr;
            successivoPtr = newPtr->nextPtr;
        } else {
            // Avanza i puntatori se non c'è stato scambio
            precedentePtr = newPtr;
            newPtr = successivoPtr;
            successivoPtr = successivoPtr->nextPtr;
        }
    }

    if (scambiato == 0) { 
        break; 
    }
}

    newPtr = headPtr;
    i = 1;
    while(newPtr != NULL){
        printf("NUMERO NODO %d -> %s %s %d %d %d %c\n",i,newPtr->nome,newPtr->cognome,newPtr->eta,newPtr->peso,newPtr->altezza,newPtr->sesso);        
        newPtr = newPtr->nextPtr;
        i++;
    } 

    fclose(filePtr);

    return headPtr;
}

void imc(datiPersone *headPtr){
    printf("\nIMC\n");

    int imc = 0;
    int pesoIMC = 0;
    int altezzaIMC = 0;
    int arrayIMC[10] = {0};
    int massimo = 0;

    datiPersone *newPtr = headPtr;
    
        /*pesoIMC = newPtr->peso;
        altezzaIMC = newPtr->altezza;               
        imc = pesoIMC/pow((altezzaIMC/100),2);*/                //funziona in entrambi i modi
        printf("\nIndici di massa corporea\n");
        for(int i = 0; i < 10; i++){
            if(newPtr == NULL){
                break;
            } 
            imc = (newPtr->peso)/pow((newPtr->altezza)/100,2);
        
            arrayIMC[i] = imc;
            newPtr = newPtr->nextPtr;
            printf("%d ",arrayIMC[i]);
        }

       
        for(int i = 0; i < 10; i++){

            for(int j = 0; j < 9;j++){

                if(arrayIMC[j] > arrayIMC[j+1]){
                    int temp = arrayIMC[j];
                    arrayIMC[j] = arrayIMC[j+1];
                    arrayIMC[j+1] = temp;
                }
            }
            
        }

        printf("\nIl massimo IMC e': %d, gli altri 2 piu' alti sono: %d, %d\n",arrayIMC[9],arrayIMC[8],arrayIMC[7]);

       newPtr = headPtr;

}

