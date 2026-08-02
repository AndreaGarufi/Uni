#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){

    int fileId = open("destinazione.txt",O_RDWR);
    lseek(fileId,0,SEEK_SET);

    int standardOutput = dup(STDOUT_FILENO); // mi salvo il backup di stdout
    dup2(fileId, STDOUT_FILENO); // l'id di stdout diventa quello del file
    printf("\n Sto scrivendo nel file usando printf \n"); // scrivo sul file
    fflush(stdout); // forzo la scrittura reale nel file 
    dup2(standardOutput, STDOUT_FILENO); // resetto stdout con il riferimento salvato
    printf("\n Sto scrivendo nella console \n"); //scrivo nella console
    fflush(stdout);

    int numero = 10;
    standardOutput = dup(STDOUT_FILENO);
    dup2(fileId,STDOUT_FILENO);
    lseek(fileId,100,SEEK_CUR);
    printf("Scrivo nel file il numero: %d",numero);
    fflush(stdout);
    dup2(standardOutput, STDOUT_FILENO); // resetto stdout con il riferimento salvato
    printf("\nRitorno sulla console \n"); //scrivo nella console

}