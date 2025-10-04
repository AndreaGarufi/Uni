#include <stdio.h>
#include <math.h>
int main(){
float somma =0;
float somma1=0;
int i=2,j=1;


while(j <= i){
//somma = 0;
somma = somma + (1.0/(i+j));
printf("entra ");

somma1 = pow(somma,2);
j++;
}

printf(" somma %f",somma1);
}


