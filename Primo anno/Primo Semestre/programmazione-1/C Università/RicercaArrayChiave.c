#include <stdio.h>

int linear_search(int a[],int key, size_t n);

int main(){

int array[10] = {1,2,3,4,5,6,7,8,9,10};
int chiave = 0;

printf("Inserisci il numero da cercare nel vettore: \n");
scanf("%d",&chiave);

int index = linear_search(array, chiave, 10);

if(index != -1){

    printf("il numero e' stato trovato nell'indice %d",index);
}else{
    printf("il numero non e' stato trovato");

}
}

//funzione per la ricerca lineare

int linear_search(int a[],int key, size_t n){

    for(int i = 0; i < n; i++){

        if( a[i] == key){
            return i;
        }
    }
return -1;
}
