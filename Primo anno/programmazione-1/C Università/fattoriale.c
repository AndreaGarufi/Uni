//Scrivi un programma in C che calcoli il fattoriale di un numero intero positivo inserito dall'utente
#include <math.h>
#include <stdio.h>
int main(){

int numero = 0,i = 0,fattoriale = 1;
printf("inserisci il numero per calcolare il fattoriale: \n");
scanf("%d",&numero);

while (i < numero){

i++;
fattoriale = fattoriale * i;

}
printf("il fattoriale di %d e' : %d",numero,fattoriale);
}