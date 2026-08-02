/*Esercizio 4 — Buco nel file (sparse file)
Scrivi un programma che:

Apre/crea un file.
Scrive la stringa "inizio" all'offset 0.
Si sposta con lseek all'offset, ad esempio, 1000 (senza scrivere nulla lì).
Scrive la stringa "fine".
Chiude il file.
Poi da shell controlla:
ls -l nomefile      # dimensione "logica"
du -h nomefile      # spazio realmente occupato su disco

Dovresti vedere che ls -l riporta una dimensione grande (~100KB) ma du mostra che i blocchi realmente allocati sono molti meno — il "buco" non occupa spazio reale.*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){
    umask(0);
    int file1 = open("bucoNelFile.txt",O_CREAT | O_RDWR, 0644);
    char buffer[] = "inizio";
    char buffer1[] = "fine";
    lseek(file1,0,SEEK_SET);
    write(file1,buffer,sizeof(buffer)-1);
    lseek(file1,1000,SEEK_CUR);
    write(file1,buffer1,sizeof(buffer1)-1);
    close(file1);
}