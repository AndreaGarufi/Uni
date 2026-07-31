#include <stdio.h>
#include <string.h>
#include <errno.h>
int main(){
    FILE* f = fopen("Meme.txt", "r");
    if(f == NULL) perror("Errore nell'apertura del file");
    //stampo tutti i codici di errore
    for(int i = 0; i < 15; i++){
        printf("Con il codice %d sterror() ha ritornato: %s\n", i, strerror(i));
    }
    printf("\n(Sicuramente continuano i codici ma ci fermiamo qua)\n");

    return 0;
}
//ho cercato di aprire un file in lettura che non esiste per creare apposta un errore, l'errore corrispondente è No such file or directory