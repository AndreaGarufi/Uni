/*Esercizio 3 — Creazione file con permessi controllati
Scrivi un programma che:

Stampa la umask corrente (puoi leggerla/impostarla con umask(), occhio che ritorna la vecchia maschera).
Crea un file con open(..., O_CREAT|O_WRONLY, 0666).
Verifica "manualmente" (stampando in ottale con printf("%o", ...)) che i permessi effettivi non siano 0666 ma 0666 & ~umask.
Prova a cambiare la umask con il comando di shell prima di lanciare il programma e osserva come cambia il risultato.*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define RWRWRW_MASK (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(){

    mode_t vecchia_umask = umask(0);   // imposto 0, ottengo il valore corrente
    umask(vecchia_umask);              // ripristino subito il valore originale
    printf("Umask corrente: %o\n", vecchia_umask);

    int permessi_attesi = 0666 & ~vecchia_umask;
    printf("Permessi attesi sul nuovo file: %o\n", permessi_attesi);

    int fd = open("destinazione.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (fd < 0) {
        perror("Errore nella creazione del file");
        exit(EXIT_FAILURE);
    }

    close(fd);

    printf("Ora controlla con: ls -l destinazione.txt\n");
    return EXIT_SUCCESS;


}