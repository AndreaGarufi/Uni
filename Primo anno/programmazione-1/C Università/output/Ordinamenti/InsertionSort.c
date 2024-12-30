#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

void insertionSort(int a[], int dim);

int main(){

    srand(time(NULL));

    int array[10] = {0};
    puts("\narray non ordinato\n");

    for(int i = 0; i < 10; i++){

        array[i] = rand() %40;
        printf("%d ",array[i]);
    }
    insertionSort(array,10);
}
void insertionSort(int a[], int dim){

    for(int i = 1; i < dim; i++){           //controllo il secondo elemento(non ho da controllare il primo) 
        int moveItem = i;
        int insert = a[i];          //elemento corrente

        while(moveItem > 0 && a[moveItem - 1] > insert){    //controlla la posizione corrente con il precedente, in caso li scambia, e decrementa la posizione corrente, e continua nel ciclo finche le condizioni sono vere in questo modo scorre tutti i precedenti e li sostituisce
            a[moveItem] = a[moveItem - 1];
            moveItem--;
        }
        a[moveItem] = insert;
    }
    puts("\narray ordinato\n");

    for(int i = 0; i < dim; i++){
        printf("%d ",a[i]);
    }

}