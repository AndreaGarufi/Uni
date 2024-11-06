//calcolare la media di 10 voti di una classe.

#include <stdio.h>
int main(){

    int counter = 0;
    float voto = 0;
    float media = 0,mediaFinita = 0;

    printf("Inserisci i voti degli alunni (10) \n");

    for(counter=0; counter < 10; counter++){

        scanf("%f",&voto);
        media = media + voto;
        
    }

    mediaFinita = media / 10;

    printf("La media e' %.2f",mediaFinita);
}