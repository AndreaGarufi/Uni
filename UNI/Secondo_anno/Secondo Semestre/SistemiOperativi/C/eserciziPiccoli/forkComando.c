/*Esercizio 13 — Mini shell (fork + exec)
Scrivi un programma che fa fork(). 
Il figlio esegue il comando ls -l usando execlp("ls", "ls", "-l", NULL). 
Il padre aspetta con wait() che il figlio finisca, poi stampa "comando terminato".*/

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
        execlp("ls","ls","-l",NULL);
    } else {
        // ===== ramo eseguito SOLO dal padre (pid > 0) =====
        int status;
        wait(&status);
        printf("Comando Terminato, exit code: %d\n",
            WEXITSTATUS(status));
    }
        
}