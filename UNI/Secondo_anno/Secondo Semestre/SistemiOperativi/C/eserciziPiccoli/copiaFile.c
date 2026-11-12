/*Esercizio 1 — Copia file "a mano" (mycp)
Scrivi un programma mycp sorgente destinazione che copia un file usando solo open, read, write, close (niente fopen!).

Apri la sorgente in sola lettura.
Crea/apri la destinazione in scrittura con permessi 0644 (rw-r--r-- = lettura/scrittura per il proprietario, solo lettura per gruppo e altri), troncandola se esiste già.
Copia a blocchi (es. buffer da 4096 byte) finché read non ritorna 0.
Gestisci gli errori con perror e termina con EXIT_FAILURE/EXIT_SUCCESS.*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define RWRWRW_MASK (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(){

    umask(S_IWGRP | S_IWOTH);
    
    if(creat("destinazione.txt",RWRWRW_MASK) < 0){
        perror("Errore nella creazione del file ");
        exit(EXIT_FAILURE);
    }else{
        printf("\nFile creato correttamente.\n");
    }

    int fileS = 0;
    if((fileS = open("sorgente.txt",O_RDONLY)) < 0){
        perror("Errore nell'apertura del file Sorgente");
    }else{
        printf("\nFile Sorgente aperto correttamente.\n");
    }

    int fileD = 0;
    if((fileD = open("destinazione.txt",O_WRONLY)) < 0){
        perror("Errore nell'apertura del file Destinazione");
    }else{
        printf("\nFile Destinazione aperto correttamente.\n");
    }

    char buffer[4096];
    int byteLetti = 0;

    while((byteLetti = read(fileS,buffer,sizeof(buffer))) > 0){
        printf("Copio blocchi da 4096 Byte.\n");
        write(fileD,buffer,byteLetti);
    }

    close(fileD);
    close(fileS);

}
