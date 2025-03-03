//scrivete una funzione che riceva un valore intero e restituisca un numero con le sue cifre invertite, es. 7631 stampa 1367

#include <stdio.h>
#include <math.h>
int main(){

    int numero = 0,modulo = 0,quoziente = 0;


    printf("Inversione del numero inserito: ");
    scanf("%d",&numero);

    while(numero != 0){
        modulo = numero % 10;
        numero = numero / 10;
        printf("%d",modulo);
    }
    

}