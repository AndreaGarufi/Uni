#include <stdio.h>
#include <math.h>
int main(){
    
float raggioCerchio = 0;

float diametro = 0, circonferenza = 0, area = 0;

const float piGreco = 3.14159;


printf("Inserisci il valore del raggio ");
scanf("%f",&raggioCerchio);

diametro = raggioCerchio * 2;
printf(" il diametro e' %f",diametro);

circonferenza = 2 * piGreco * raggioCerchio;
printf(" La circonferenza e' %f",circonferenza);

area = piGreco * (raggioCerchio * raggioCerchio);
printf(" l' area e' %f",area);
}
