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
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>

int main(){

    int file = open("numeri.bin",O_RDONLY);

    if(file == -1){
        perror("Errore nell'apertura del file.\n");
        exit(EXIT_FAILURE);
    }else{
        printf("File aperto correttamente.\n");
    }

    struct stat datiFile;

    fstat(file,&datiFile);

    printf("La dimensione del file 'numeri.bin' è: %ld byte.\n",(long)datiFile.st_size);

    unsigned char *dati = mmap(NULL,datiFile.st_size,PROT_READ,MAP_PRIVATE,file,0);
    close(file);

    int numeroRecord = (int)datiFile.st_size/12;
    printf("Il file binario contiene %d record da 12 byte ciascuno.\n",numeroRecord);

    for (int i = 0; i < numeroRecord; i++) {
        printf("[READER] record n.%d letto: ", i);
        for (int j = 0; j < 12; j++) {
            printf("%d ",dati[i *12 + j]);
            
        }
        printf("\n");
    }
    munmap(dati, datiFile.st_size);
    
}