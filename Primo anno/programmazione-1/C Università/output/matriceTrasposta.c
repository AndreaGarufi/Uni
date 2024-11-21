/*Scrivi un programma in C che:

Legga una matrice 3x3 di numeri interi inseriti dall'utente.
Calcoli e stampi la matrice trasposta.*/

#include <stdio.h>

int main(){

int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
int temp = 0;

printf("STAMPA MATRCE ORIGINARIA\n");

for(int i = 0; i < 3; i++){

    for(int j = 0;j < 3;j++){

        printf("%d ",a[i][j]);
    }
    printf("\n");
}

temp = a[0][1];

a[0][1] = a[1][0];

a[1][0] = temp;

temp = 0;

temp = a[0][2];

a[0][2] = a[2][0];

a[2][0] = temp;

temp = 0;

temp = a[1][2];

a[1][2] = a[2][1];

a[2][1] = temp;



printf("STAMPA MATRCE TRASPOSTA\n");

for(int i = 0; i < 3; i++){

    for(int j = 0;j < 3;j++){

        printf("%d ",a[i][j]);

    }
    printf("\n");

}


}