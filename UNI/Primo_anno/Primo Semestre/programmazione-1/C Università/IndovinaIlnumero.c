#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    srand(time(NULL));
    int guess = 0,numero = 0;
    char lettera;
    
    do
    {
        printf("ho generato un numero tra 1 e 1000: indovinalo. \n");

        numero = 1 + rand() % 1000;

        printf("Inserisci il numero: \n");
        scanf("%d",&guess);

        if(guess > numero){

                printf("Sbagliato, riprova: piu' basso\n");
            }else{
                printf("Sbagliato, riprova: piu' alto\n");
            }
        

        while(guess != numero){

            printf("Renserisci il numero: \n");
            scanf("%d",&guess);

            if(guess > numero){

                printf("Sbagliato, riprova: piu' basso\n");
            }else{
                printf("Sbagliato, riprova: piu' alto\n");
            }

        }

        printf("Bravo, hai indovinato: il numero era %d \n",numero);

        printf("premi y per giocare ancora, altrimenti premi n : \n");
        scanf(" %c", &lettera);

    } while (lettera == 'y');
}
