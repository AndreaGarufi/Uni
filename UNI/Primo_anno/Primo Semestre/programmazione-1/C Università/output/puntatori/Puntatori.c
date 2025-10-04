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

}