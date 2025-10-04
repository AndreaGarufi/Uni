/*Scrivere una funzione C che riceve come parametro un array di double e la sua dimensione e
restituisce la media degli elementi presenti nell'array.*/

#include <stdio.h>

double media(double a[], int n);

int main(){

double array[10] = {1,2,3,4,5,6,7,8,9,10};
double mediatot = 0;

mediatot = media(array, 10);
printf("la media e': %f",mediatot);


}

double media(double a[], int n){

double media = 0,somma = 0;

for(int i = 0; i < n; i++){
somma = somma + a[i];

}

media = somma / n;

return media;

}
