#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *filePtr = NULL;
    int i = 0;
    char filename[50]; // Buffer per il nome del file
    char command[60]; // Buffer per il comando system

    while (i <= 10) { // crea massimo 1000 file
        sprintf(filename, "file%d.bat", i); // Costruzione del nome del file
        filePtr = fopen(filename, "w");
        if (filePtr == NULL) {
            printf("Errore nella creazione del file %s\n", filename);
            break; // Uscire dal ciclo in caso di errore
        } else {
            printf("Creato: %s\n", filename);
            fprintf(filePtr,"START");
            fclose(filePtr); // Chiudi il file per evitare problemi di risorse
        }
        i++;
    }
    i = 0;
    while(i <= 10){ // esegue massimo 1000 file
        sprintf(command, "file%d.bat", i);  // Costruisci il comando
        printf("Eseguendo: %s\n", command);
        int ret = system(command);  // Esegui il file batch

        i++;
    }

    return 0;
}
