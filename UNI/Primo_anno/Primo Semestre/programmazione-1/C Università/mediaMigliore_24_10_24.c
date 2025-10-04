

#include <stdio.h>
int main(){

    int counter = 0;
    float voto = 0;
    float media = 0,mediaFinita = 0;
    int Alunni = 0;

    puts("ciao");           // un alternativa a printf

    printf("Inserisci il numero degli alunni \n");
    scanf("%d",&Alunni);


    printf("Inserisci i voti degli alunni \n");

    for(counter=0; counter < Alunni; counter++){

        scanf("%f",&voto);
        media = media + voto;
        
    }

    mediaFinita = media / Alunni;

    printf("La media e' %.2f",mediaFinita);
}