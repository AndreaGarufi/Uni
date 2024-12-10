#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *filePtr = NULL;
    int i = 0;
    char filename[50]; // Buffer per il nome del file

    while (1) { // Ciclo infinito
        sprintf(filename, "file%d.txt", i); // Costruzione del nome del file
        filePtr = fopen(filename, "w");
        if (filePtr == NULL) {
            printf("Errore nella creazione del file %s\n", filename);
            break; // Uscire dal ciclo in caso di errore
        } else {
            printf("Creato: %s\n", filename);
            fclose(filePtr); // Chiudi il file per evitare problemi di risorse
        }
        //i++;  DANNO (se lo metti crea file all'infinito)
    }

    return 0;
}
