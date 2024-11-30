//inizializzare un array con i puntatori

#include <stdio.h>

int main() {
    int array[5];
    int *ptr = array; // Puntatore che punta al primo elemento dell'array

    // Inizializza l'array usando il puntatore
    for (int i = 1; i <= 5; i++) {
        *(ptr + i) = i;  // Assegna valori da 1 a 5 agli elementi dell'array
    }

    // Stampa l'array usando il puntatore
    printf("Gli elementi dell'array sono:\n");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", *(ptr + i));  // Stampa i valori a cui il puntatore fa riferimento
    }
    printf("\n");

}