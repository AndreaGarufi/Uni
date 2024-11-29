#include <stdio.h>

void swap(int *n,int *n1){

    int temp = *n;

    *n = *n1;

    *n1 = temp;

}


int main(){


    int a = 1, b = 2;


    scanf("%d",&a);

    scanf("%d",&b);

    swap(&a,&b);

    printf("\nnu1 scambio %d",a);
    printf("\nnu2 scambio %d",b);

/*Scrivi un programma che:

Chieda all'utente di inserire 5 numeri interi in un array.
Calcoli la somma dei numeri nell'array utilizzando un puntatore per scorrere gli elementi.
Stampi la somma finale.*/




}