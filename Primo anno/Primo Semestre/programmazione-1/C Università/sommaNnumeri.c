//stampa la somma dei primi n numeri
#include <stdio.h>
int main(){

int numero = 0;
int somma = 0;
int i = 0;
int numeroContatore = 0;
printf("inserisci un numero N :\n");
scanf("%d",&numero);
numeroContatore = numero;
i = numero;
while(i > 0){

somma = somma + numeroContatore -1;

i--;
numeroContatore--;
}
somma = somma + numero;

printf("La somma dei primi %d numeri naturali e': %d",numero,somma);

}