/*(Lancio di una moneta) Scrivete un programma che simuli il lancio di una moneta.
Per ogni lancio della moneta il programma deve stampare Heads (testa) o Tails (croce). Fate lanciare al programma
la moneta: 100 volte e contate il numero di volte in cui compare ogni lato della moneta. Stampate i risultati.
Il programma deve chiamare una funzione separata flip che non riceve alcun argomento e restituisce 0 per croce e 1
per testa. Se il programma simula in maniera realistica il fancio della moneta, allora ogni lato della moneta
deve comparire approssimativamente la meta delle volte, per un totale di approssimativamente 50 teste e 50 croci.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){

    srand(time(NULL));

    long int lancio = 0, puntiCroce = 0, puntiTesta = 0,n = 0;
    printf("Quante volte vuoi lanciare ? \n");
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        lancio = rand() % 2;

        if(lancio == 0){

            printf("Heads ");
            puntiTesta = puntiTesta + 1;
        }else{

            printf("Tails ");
            puntiCroce = puntiCroce + 1;
        }
    }

printf(" \nPUNTI TESTA = %d",puntiTesta);
printf(" PUNTI CROCE = %d",puntiCroce);
printf(" LANCI TOT = %d",(int) puntiCroce + puntiTesta);


}