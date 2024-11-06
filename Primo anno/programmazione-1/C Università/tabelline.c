//Tabella di Moltiplicazione: Genera e stampa la tabella di moltiplicazione per un numero fornito dall'utente.

#include <stdio.h>
int main(){

int numero = 0;
int tabellina = 0;
printf("Insersci il nuemro da cui calcolare la tabellina: \n");
scanf("%d",&numero);

for(int i=1;i<=10;i++){
tabellina = 0;
tabellina = numero * i;
printf("\nTabellina = %d",tabellina);

}




}