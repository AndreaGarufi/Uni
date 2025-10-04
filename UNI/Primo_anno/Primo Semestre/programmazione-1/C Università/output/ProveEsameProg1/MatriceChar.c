/*Si scriva un programma C che:

- A prenda un input da tastiera (argomenti della funzione main()) un intero k in [10,15], un carattere w in [‘a’-’z’] e due interi N ed M in [4,8]; 
se gli argomenti a riga di comando non rispondono ai suddetti requisiti, il programma stampa un messaggio di errore sullo standard error 
e termina la propria esecuzione con codice di errore “-1”;

- B allochi dinamicamente una matrice S di stringhe (char*) di dimensioni N x M;

- C riempia la matrice S con NxM stringhe di lunghezza k composte di caratteri pseudo-casuali in [a-z];

- D ordini ogni colonna della matrice S in modo crescente (ordinamento lessicografico) con un algoritmo di ordinamento a scelta tra 
Insertion Sort e Bubble Sort;

- E stampi la matrice sullo standard output;

- F stampi sullo standard output la stringa (e gli indici all'interno della matrice) che contiene il maggior numero di occorrenze del simbolo w. 
Queste ultime vanno sostituite, sullo standard output, con il carattere '*'.

SPECIFICHE
- readInput: funzione che prende in input il numero argc e il vettore argv della funzione main(), 
che controlli la presenza ed i requisiti degli argomenti k, w, N ed M, e che li inserisca in un record (struct) da restituire allo user code 
(funzione main). La funzione deve gestire correttamente gli errori relativi a input non corretti;

- allocateS: funzione per allocazione dinamica della matrice di dimensioni NxM, tale matrice va restituita come dato di ritorno al chiamante 
(funzione main());

- genString: funzione che restituisce una stringa della lunghezza specificata con caratteri pseudo-casuali in un ben determinato insieme specificato 
mediante opportuni parametri formali;

- fillS: funzione di riempimento della matrice S come specificato nel punto C;

- sortS: funzione di ordinamento della matrice come specificato nel punto D; NB: si faccia uso, al suo interno, della funzione di libreria strcmp();

- printMatrix: funzione per la stampa della matrice S;

- printMax: funzione per la stampa della stringa contenente il maggior numero di occorrenze del simbolo w come specificato nel punto F
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct parametri{
    int parK;
    char parW;
    int parN;
    int parM;
};
typedef struct parametri parametri;

int readInput(int dim, char *vettore[], parametri dati,parametri *ptr);

char*** allocateS(char ***s,int N, int M, int K);

char* genString(int dimString);

char*** fills(char ***s, char *stringaK, int N, int M);


int main(int argc, char *argv[]){

    parametri dati;
    parametri *puntatore = malloc(sizeof(parametri));

    puntatore->parK = 0;

    readInput(argc,argv,dati,puntatore);
    printf("(VALORI PASSATI DA RIGA DI COMANDO %d,%c,%d,%d)\n",puntatore->parK,puntatore->parW,puntatore->parN,puntatore->parM);

    int K = puntatore->parK;
    int N = puntatore->parN;
    int M = puntatore->parM;
    char *stringa = malloc(sizeof(char) * K);

    printf("Allocazione spazio per la matrice...\n");
    printf("Generazione stringa di lunghezza K...\n");
    printf("Riempimento Matrice di Stringhe...\n");
    char ***S = allocateS(S,N,M,K);

    printf("STAMPA MATRIX\n");

    for(int i = 0; i<N;i++){
        for(int j = 0;j<M;j++){
            printf("%10s",S[i][j]);
        }
        puts("");
    }    


    printf("\nEND");

}
int readInput(int dim, char *vettore[], parametri dati,parametri *ptr){


    int k = 0;
    char w = '\0';
    int N = 0;
    int M = 0;

    printf("\nargomenti passati: %d ",dim);

    k = atoi(vettore[1]);        //atoi converte ascii in int
    w = vettore[2][0];
    N = atoi(vettore[3]);
    M = atoi(vettore[4]);

    if(k < 10 || k > 15){
        fprintf(stderr,"-1");
        exit(-1);
    }

    ptr->parK = k;
    ptr->parW = w;
    ptr->parN = N;
    ptr->parM = M;

    return ptr->parK,ptr->parW,ptr->parN,ptr->parM;

}

char*** allocateS(char ***s,int N, int M,int K){
    printf("\nALLOCATE S");

    s = malloc(sizeof(char**) * N);

    for(int i = 0; i < N; i++){
        s[i] = malloc(sizeof(char*) * M);
        for(int j = 0; j < M; j++){
            s[i][j] = malloc(sizeof(char) * K);
            
            fills(s,genString(K),N,M);
        }
    }

    return s;
}

char* genString(int dimString){
    printf("\nGEN STRINGK");

    char* string = malloc(sizeof(char) * dimString);

    for(int i = 0; i < dimString-1; i++){

        int s = 65 + rand() % 90;
        char lettere = (char)s;
        string[i] = lettere;
    }
    string[dimString] = '\0';

    return string;
}

char*** fills(char ***s, char *stringaK, int N, int M){

    printf("\nFILL");
    for(int i = 0; i < N;i++){
        for(int j = 0; j < M; j++){
            strcpy(s[i][j],stringaK);
        }    
    }
    
    return s;
}
