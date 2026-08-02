/*Esercizio 5 — Editor di byte minimale
Scrivi un programma patchbyte file offset valore che apre un file esistente in lettura/scrittura e sovrascrive un singolo byte alla posizione 
offset col valore numerico passato (convertito con atoi), usando lseek + write di un solo byte.*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){

    umask(0);

    int file1 = open("destinazione.txt",O_RDWR);
    if(file1 < 0){
        perror("Errore nell'apertura del file");
        exit(EXIT_FAILURE);
    }
    int offset = 0;
    int numero = 0;
    char buffer[2];

    printf("\nInserisci l'offset -> ");
    scanf("%d",&offset);
    printf("\nInserisci un numero da mettere nel file -> ");
    scanf("%d",&numero);
    snprintf(buffer, sizeof(buffer), "%d", numero);

    lseek(file1,offset,SEEK_SET);
    write(file1,buffer,sizeof(buffer)-1);


}