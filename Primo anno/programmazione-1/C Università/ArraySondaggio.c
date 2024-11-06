/*A quaranta studenti viene chiesto di valutare la qualità del cibo nella caffetteria degli studenti con una scala da 1 a 10
(1 significa pessima e 10 eccellente).
Mettete le 40 risposte in un array intero e riassumete i risultati del sondaggio.*/

#include <stdio.h>
#include <math.h>
#include <stddef.h>

#define RISPOSTE 40
#define FREQUENZA 11

int main(){

int risposte[RISPOSTE] = {1, 2, 6, 4, 8, 5, 9, 7, 8, 10, 1, 6, 3, 8, 6, 10, 3, 8, 2, 7, 6, 5, 7, 6, 8, 6, 7, 5, 6, 6, 5, 6, 7, 5, 6, 4, 8, 6, 8, 10};
int frequenza[FREQUENZA] = {0};

// per ogni risposta, seleziona il valore di un elemento dell'array
// responses e usa quel valore come indice nell'array frequency per
// determinare l'elemento da incrementare

for(int i=0; i < RISPOSTE; i++){

    frequenza[risposte[i]]++;       //es. i = 0 risposte[i] = posizione 0 (valore 1), e fa: posizione 1 di "frequenza" ++ in questo modo aumento il counter dei voti "1" (il voto dell array "risposte" corrisponde alla posizione dell array "frequenza")
}
printf("%s%17s\n", "Rating", "Frequency");

for (int rating = 1; rating < FREQUENZA; ++rating ) {
    printf("%6d%17d\n", rating, frequenza[rating]);
}
}