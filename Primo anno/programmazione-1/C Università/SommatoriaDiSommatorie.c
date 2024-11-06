#include <stdio.h>
int main(){

int i = 1,k = 0, j = 1;


float somma = 0;

printf("sommatoria con i che va da 1 a k di sommatoria di 1/i+j con j che va da 1 a i.\n\n");

printf("\n inserisci k ");
scanf("%d",& k);

while(i <= k){

                         
while(j <= i){                                       

somma = somma + (1.0/(i+j));

j++;
}
i++;
}
printf("La sommatoria e' %f", somma);
















}