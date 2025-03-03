#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *selectionSort(int *y,int dim);

int main(){
    srand(time(NULL));

    int dim = 9 + rand() % 20;
    
    int *Y = selectionSort(Y,dim);

    printf("\nStampa array ordinato\n");
    for(int i = 0; i < dim; i++){
        printf("%d ",Y[i]);
    }

}

int *selectionSort(int *y,int dim){

    printf("\nStampa array ordinato non ordinato\n");

    y = malloc(sizeof(int) * dim);

    for(int i = 0; i < dim; i++){
        y[i] = 1 + rand() % 9;
        printf("%d ",y[i]);
    }    

    for(int i = 0; i < dim-1; i++){
        int minimo = i;
        for(int j = i+1; j < dim; j++){
            if(y[j] < y[minimo]){
                minimo = j;
            }
        }
        int temp = y[i];
        y[i] = y[minimo];
        y[minimo] = temp;
    }


    return y;
}
