#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Dichiarazione della funzione coinflip
void coinflip(long int *puntiTesta, long int *puntiCroce, int n);

int main() {
    srand(time(NULL));
    
    long int puntiCroce = 0, puntiTesta = 0;
    int n = 0;
    
    // Chiedi all'utente il numero di lanci
    printf("Quante volte vuoi lanciare? \n");
    scanf("%d", &n);
    
    // Chiama la funzione coinflip passando i puntatori a puntiTesta e puntiCroce
    coinflip(&puntiTesta, &puntiCroce, n);
    
    // Stampa i risultati
    printf("\nPUNTI TESTA = %ld, PUNTI CROCE = %ld, LANCI TOT = %ld\n", puntiTesta, puntiCroce, puntiTesta + puntiCroce);
    
    return 0;
}

// Definizione della funzione coinflip
void coinflip(long int *puntiTesta, long int *puntiCroce, int n) {
    for (int i = 0; i < n; i++) {
        int lancio = rand() % 2;  // genera 0 o 1 casualmente
        
        if (lancio == 0) {
            printf("Heads ");
            (*puntiTesta)++;  // Incrementa puntiTesta usando il puntatore
        } else {
            printf("Tails ");
            (*puntiCroce)++;  // Incrementa puntiCroce usando il puntatore
        }
    }
    printf("\n");  // Va a capo dopo i lanci
}
