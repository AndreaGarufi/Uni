/*Esercizio 12 — Padre e figlio (fork + wait)
Scrivi un programma che fa fork(). Il figlio stampa il proprio PID e quello del padre (getpid/getppid), poi termina con exit(42). 
Il padre aspetta la terminazione del figlio con wait(), estrae l'exit code con la macro WEXITSTATUS e lo stampa.*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    pid_t pid = fork();

    if (pid < 0) {
        perror("Errore nella fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // ===== ramo eseguito SOLO dal figlio =====
        printf("Sono il figlio, il mio PID è %d, quello di mio padre è %d\n",
            getpid(), getppid());
        exit(42);
    } else {
        // ===== ramo eseguito SOLO dal padre (pid > 0) =====
        int status;
        wait(&status);
        printf("Il padre ha rilevato la terminazione del figlio, exit code: %d\n",
            WEXITSTATUS(status));
    }
        
}

