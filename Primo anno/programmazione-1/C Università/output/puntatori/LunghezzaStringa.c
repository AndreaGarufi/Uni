/*Chieda all'utente di inserire una stringa.
Calcoli manualmente la lunghezza della stringa usando un puntatore, senza utilizzare la funzione strlen().
Stampi la lunghezza calcolata.*/

#include <stdio.h>
int main(){

    char string[] = "CicloFor";
    char *stringPtr = string;
    int g = 0;

    printf("Lunghezza della stringa");

    while(*stringPtr != '\0'){
        stringPtr++;
        g++;
    }

    printf("\nLa lunghezza della stringa e' %d ",g);

}