/*Esercizio 2 — Contatore di byte (mywc -c)
Scrivi un programma che, dato un percorso, apre il file e conta quanti byte contiene leggendolo a blocchi (senza usare lseek per saltare alla fine!). Stampa il totale.

Bonus: prova anche con lseek(fd, 0, SEEK_END) e confronta il risultato — dovrebbe coincidere.*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){

    int file1 = open("sorgente.txt",O_RDONLY);
    if(file1 < 0){
        perror("Errore nell'apertura del file da leggere ");
        exit(EXIT_FAILURE);
    }

    int byteLetti = 0;
    int byteLettiTOT = 0;
    char buffer[1024];

    while((byteLetti = read(file1,buffer,sizeof(buffer))) > 0){

        printf("Leggo blocchi da 1024 Byte.\n");
        byteLettiTOT = byteLettiTOT + byteLetti;

    }

    printf("I byte letti in totale sono: %d.\n",byteLettiTOT);
    lseek(file1,0,SEEK_SET);
    printf("Stessa misurazione fatta con lseek: %ld.",lseek(file1,0,SEEK_END));

    close(file1);
}