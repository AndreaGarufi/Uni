/*- Inversione degli elementi di un array di interi
- Dato un array di interi contare il numero di elementi pari e il numero di elementi dispari 
- trovare il minimo e il massimo in un array di interi e scambiarli di posizione*/
#include <stdio.h>

int inversione_array(int a[],int n);   //prototipo di funzione
int conta_pari_dispari(int a[],int n);  //prototipo di funzione
int massimo_minimo(int a[],int n);


int main(){

   int array1 [10] = {1,2,3,4,5,6,7,8,9,10};
   int array2 [6] = {2,5,7,9,1,5};
   int array3 [5] = {10,7,2,3,1};



   printf("Stampa array 1\n");
   for(int i = 0;i < 10; i++){
      printf("%d ",array1[i]);
   }

   printf("\nStampa array 1 invertito\n");
   printf("%d", inversione_array(array1, 10));

   printf("\n\nStampa array2\n");
   for(int i = 0;i < 6; i++){
      printf("%d ",array2[i]);
   }

   printf("\nStampa numero di pari e numero di dispari\n");
   printf("",conta_pari_dispari(array2,6));

   printf("\n\nStampa array3\n");
   for(int i = 0;i < 5; i++){
      printf("%d ",array3[i]);
   }
   printf("\nMassimo-Minimo dell'array3");
   printf("",massimo_minimo(array3,5));
   

}

int inversione_array(int a[],int n){      //funzione che inverte l'array

   for(int i = n-1; i >= 0; i--){

      printf("%d ",a[i]);
   }

}

int conta_pari_dispari(int a[],int n){    //funzione che conta i valori pari e dispari
   int pari = 0,dispari = 0;
   for(int i = 0; i < n; i++){

      if(a[i] % 2 == 0){
         pari++;
      }else{
         dispari++;
      }
   }

   printf("i numeri pari sono %d",pari);
   printf("\ni numeri dispari sono %d",dispari);

}

int massimo_minimo(int a[],int n){
   int massimo = a[0], minimo = a[0];
   int indiceMassimo = 0, indiceMinimo = 0;

   for (int i = 0; i < n; i++) {
    if (a[i] > massimo) {
        massimo = a[i];
        indiceMassimo = i;
    }
    if (a[i] < minimo) {
        minimo = a[i];
         indiceMinimo = i;
    }
    
   }

   printf("\nIl minimo e': %d",minimo);
   printf("\nIl massimo e': %d",massimo);

   int temporaneo = a[indiceMassimo];
   a[indiceMassimo] = a[indiceMinimo];
   a[indiceMinimo] = temporaneo;

   printf("\nScambio di posizione tra massimo e minimo\n");
   printf("\nStampa dell'array3 con massimo e minimo invertiti: \n");

   for(int i = 0; i < n; i++){

      printf("%d ",a[i]);
   }

}
