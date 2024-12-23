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

int main(int argc, char **argv){
    
    int k = 0;
    char w = '\0';
    int N = 0,M = 0;

    printf("argomenti passati: %d ",argc);

    k = argv[1];
    w = argv[2];
    N = argv[3];
    M = argv[4];

    for(int i = 0; i < 4; i++){
        printf("%c , %c ,%c ,%c",argv[1],argv[2],argv[3],argv[4]);
    }


}