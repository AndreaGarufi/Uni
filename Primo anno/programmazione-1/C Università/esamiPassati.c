/*scrivere un programma che permetta di riassumere gli esiti degli esami passati di una classe. Il programma permette di inserire 10 esiti.
Ciascun esito può essere pari a 1 (passed) o 2 (failed). Il programma stampa il numero di studenti che hanno passato gli esami e il numero di studenti che non hanno passato l'esame.
se il numero di studenti che hanno passato l'esame è superiore a 8, il programma stampa "bonus to instructor"*/

#include <stdio.h>
int main(){

int esito = 0, passed = 0, failed = 0,i = 0;

printf("inserisci i 10 esiti: \n");

for (i=0;i<10;i++){

    printf("1 = passed, 2 = failed: \n");
    scanf("%d",&esito);

    if(esito == 1){
        passed = passed + esito;
    }
    if(esito == 2){
        failed = failed + (esito / 2);
    }
    if(esito != 1 && esito != 2){               //se inserisco un numero che non è ne 1 ne 2 mi fa reinserire il nuemro e decremento i, cosi il for la incrementa ed è come se non fossi andato avanti nel ciclo avendo sempre la i che non cambia di numero
        printf("reinserisci il numero \n");
        i--;
    }
}

printf("alunni che hanno passato l'esame: %d \n",passed);

printf("alunni che non hanno passato l'esame: %d \n",failed);
 
}
