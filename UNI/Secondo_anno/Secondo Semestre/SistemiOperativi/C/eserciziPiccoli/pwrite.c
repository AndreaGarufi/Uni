/*Esercizio 7 — Scritture atomiche con pwrite
Crea un file di 10 blocchi da 100 byte ciascuno (dimensione totale 1000 byte). 
Scrivi un programma che, senza usare lseek, scrive il blocco numero n (passato da riga di comando) 
usando pwrite(fd, buffer, 100, n*100). Verifica che i blocchi finiscano nella posizione corretta 
lanciando il programma più volte con n diversi.*/


//file da 1K creato con truncate -s 1000 blocchi.txt
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    if(argc != 4){
        perror("Errore nel numero di parametri devi avviarmi con <Nome-file.txt> <numero> <testo>");
        exit(EXIT_FAILURE);
    }

    int file1 = open(argv[1],O_RDWR);
    if(file1 < 0){
        perror("Errore nell'apertura del file.");
        exit(EXIT_FAILURE);
    }else{
        printf("\nFile aperto correttamente.\n");
    }

    int numero = atoi(argv[2]);
    int offset = numero * 100;
    pwrite(file1,argv[3],sizeof(argv[3]),offset);
    close(file1);

}