
#include <stdio.h>
#include <math.h>

#define SIZE 12

int main(){

int a[SIZE]={1, 3, 5, 4, 7, 2, 99, 16, 45, 67, 89, 45};

int somma = 0;
for(int i=0; i < SIZE; i++){

somma = somma + a[i];

}

printf("%d",somma);
}