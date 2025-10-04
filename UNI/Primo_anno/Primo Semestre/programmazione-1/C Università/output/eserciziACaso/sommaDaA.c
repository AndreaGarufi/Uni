/*Scrivere una funzione C che riceve come parametro un array di interi, la sua dimensione e due
indici h e k e restituisce la somma degli elementi dell’array memorizzati nelle posizioni da h a k.*/

#include <stdio.h>
int somma(int a[], int n, int h, int k);
int main(){

int array[10] = {1,2,3,4,5,6,7,8,9,10};
int indice1 = 3,indice2 = 8;   //da 4 a 9

printf("",somma(array,10,indice1,indice2));

}

int somma(int a[], int n, int h, int k){
int somma = 0;
for(int i = h; i <= k; i++){

    somma = somma + a[i];

}
printf("La somma dall'indice h a k e': %d",somma);




}




