#include <stdio.h>
int main(){

int r=0;
int q=0;

printf("sommatoria di 1/i, con i che va da q fino ad r.\n\n");

printf(" inserisci q ");
scanf("%d",& q);

printf("\n inserisci r ");
scanf("%d",& r);


while(q >= r){
printf("il valore di q deve essere minore di r : ");
printf("reinserisci q ");
scanf("%d",& q);

printf("reinserisci r ");
scanf("%d",& r);

while(q <= 0){
    printf("Il numero q non e' positivo, inserisci un altro numero: ");
    scanf("%d",& q);

}
printf("Valore di q Accettato \n");

while(r <= 0){
    printf("Il numero r non e' positivo, inserisci un altro numero: ");
    scanf("%d",& r);
}
printf("Valore di r Accettato \n");

}

float somma = 0;                                //codice che si può usare anche per sommatorie di array o matrici ecc...
while(q <= r){                                       

somma = somma + (1.0/q);

q++;
}
printf("La sommatoria e' %f", somma);                //
                               
}