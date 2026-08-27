/*Esercizio 31 — Creare e leggere un file binario con mmap

PARTE A — Creazione del file binario (bin-writer.c)
Scrivi un programma che genera un file binario "numeri.bin" contenente 
25 record, ciascuno di 12 byte, dove ogni byte è un numero casuale tra 
0 e 99 (usa unsigned char, non int!).

- Usa open() con O_CREAT | O_WRONLY | O_TRUNC per creare il file (permessi 0644).
- Per ogni record, genera 12 numeri casuali con rand() % 100, mettili in un 
  buffer di tipo unsigned char[12], e scrivili nel file con write().
- Chiudi il file con close().
- Stampa a video, mentre scrivi, ogni record generato (per poterlo poi 
  confrontare con quello che leggerai nella Parte B): 
  "[WRITER] record n.X scritto: 12, 45, 7, ..."

PARTE B — Lettura del file binario con mmap (bin-reader.c)
Scrivi un secondo programma che apre "numeri.bin" e lo legge SOLO tramite 
mmap (niente read/fread):

- Apri il file con open() in sola lettura.
- Usa fstat() per ottenere la dimensione del file.
- Mappa il file in memoria con mmap() (PROT_READ, MAP_PRIVATE).
- Chiudi il file descriptor con close() (la mappatura resta valida).
- Calcola quanti record da 12 byte contiene il file (dimensione / 12).
- Per ogni record, stampa i suoi 12 byte: 
  "[READER] record n.X letto: 12, 45, 7, ..."
- Chiudi la mappatura con munmap().

Verifica che l'output della Parte B coincida ESATTAMENTE con quello della 
Parte A (stessi 25 record, stessi valori, nello stesso ordine) — questo ti 
conferma che mmap sta leggendo correttamente i byte grezzi dal file.
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#define NUM_RECORD 25
#define RECORD_SIZE 12
#define FILE_NAME "numeri.bin"

int main() {
    // Inizializza il generatore di numeri casuali
    srand(time(NULL));

    // Apertura/creazione del file binario con i flag e permessi richiesti
    int fd = open(FILE_NAME, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Errore durante l'apertura del file");
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[RECORD_SIZE];

    for (int i = 0; i < NUM_RECORD; i++) {
        // Popola il buffer con numeri casuali tra 0 e 99
        for (int j = 0; j < RECORD_SIZE; j++) {
            buffer[j] = (unsigned char)(rand() % 100);
        }

        // Scrittura del record corrente nel file
        ssize_t bytes_written = write(fd, buffer, RECORD_SIZE);
        if (bytes_written != RECORD_SIZE) {
            perror("Errore durante la scrittura del record");
            close(fd);
            exit(EXIT_FAILURE);
        }

        // Stampa di controllo a video del record appena scritto
        printf("[WRITER] record n.%d scritto: ", i);
        for (int j = 0; j < RECORD_SIZE; j++) {
            printf("%u%s", (unsigned int)buffer[j], (j == RECORD_SIZE - 1) ? "\n" : ", ");
        }
    }

    // Chiusura del file descriptor
    if (close(fd) < 0) {
        perror("Errore durante la chiusura del file");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}