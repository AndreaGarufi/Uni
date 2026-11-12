/*Esercizio 6 — Log concorrente con dup2
Scrivi un programma che apre un file di log in append (O_APPEND), 
fa un backup di STDOUT_FILENO con dup, poi con dup2 reindirizza temporaneamente lo standard output sul file di log, 
stampa un paio di righe con printf (ricordati fflush), poi ripristina lo stdout originale col backup salvato e 
stampa un'ultima riga in console per dimostrare che è tornato tutto normale.*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){

    int file1 = open("destinazione.txt",O_WRONLY | O_APPEND);
    if(file1 < 0){
        perror("Errore nell'apertura del file ");
        exit(EXIT_FAILURE);
    }else{

        printf("File aperto correttamente.\n");
    }
    
    int stdOUT = dup(STDOUT_FILENO);
    dup2(file1,STDOUT_FILENO);
    //ora il file1 corrisponde allo stdout
    printf("\nScrivo nel file in modalità append con la printf.\n");
    fflush(stdout);
    dup2(stdOUT,STDOUT_FILENO);
    printf("Tutto corretto\n");
    close(file1);


}