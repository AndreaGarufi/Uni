#include <stdio.h>
int main(){


float BMI = 0, peso = 0, altezza = 0;

printf("Inserisci il tuo peso per calcolare il BMI \n");
scanf("%f",&peso);

printf("\nadesso inserisci l'altezza ");
scanf("%f",&altezza);

BMI = peso / (altezza * altezza);

printf("\nil tuo BMI e' %f \n", BMI);

printf(" VALORI DEL BMI Sottopeso: meno di 18.5 \n Normale: tra 18.5 e 24.9 \n Sovrappeso: tra 25 e 29.9 \n Obeso: 30 e oltre" );

}
    