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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void readInput(int dim, char *argv[]);


struct datiPersone{     //struct contenente i dati delle persone da leggere da file di input e creare poi la lista come indicato nel pdf
    char nome[255];
    char cognome[255];
    int eta;
    int peso;
    int altezza;
    char sesso;

    struct datiPersone *nextPtr;
};

int main(int argc, char *argv[]){

readInput(argc,argv);

}

void readInput(int argc, char *argv[]){

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
