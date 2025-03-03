#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

void selectionSort(int a[], int dim);

int main(){

    srand(time(NULL));

    int array[10] = {0};
    puts("\narray non ordinato\n");

    for(int i = 0; i < 10; i++){

        array[i] = rand() %40;
        printf("%d ",array[i]);
    }
    selectionSort(array,10);
}
void selectionSort(int a[], int dim){

    for(int i = 0; i < dim -1; i++){                      
        int minimo = i;                                   //libro spiegazione pag 590
        for(int j = i + 1; j < dim; j++){
            if(a[j] < a[minimo]){
                minimo = j;
            }
        }
        int temp = a[i];                                    
        a[i] = a[minimo];                                  
        a[minimo] = temp;                                   
    }

    puts("\narray ordinato\n");

    for(int i = 0; i < dim; i++){
        printf("%d ",a[i]);
    }

}