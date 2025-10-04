/*Chieda all'utente di inserire due numeri interi.
Utilizzi una funzione per calcolare la somma dei due numeri, passando i numeri alla funzione tramite puntatori.
Stampi la somma calcolata.*/

#include <stdio.h>

void somma(int *ptr1, int *ptr2);

int main(){

    int numero1 = 5;
    int numero2 = 10;

    somma(&numero1,&numero2);

    printf("La somma e': %d ",numero1);
}
void somma(int *ptr1, int *ptr2){

    *ptr1 = *ptr1 + *ptr2;
}