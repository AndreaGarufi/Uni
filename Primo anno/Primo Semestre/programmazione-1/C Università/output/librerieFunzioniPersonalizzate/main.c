#include <stdio.h>
#include "somma.h"

int main(){

int x = 10, y = 5;
int sommaTOT = somma(x,y);

printf("SOMMA %d ",sommaTOT);

}//funziona ma bisogna avviarlo con .\programma.exe
//va compilato cosi se non c'è l'eseguibile gcc -o programma main.c somma.c
