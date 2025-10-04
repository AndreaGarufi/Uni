#include <stdio.h>
#include <stdlib.h>

int main(){
    int dim = 0;

    printf("Inseirisci il numero degli elementi dell'array\n");
    scanf("%d",&dim);

    for(int i = 0;i<dim;i++){

        int *array = (int *)malloc(sizeof(int) * dim);

        for(int i = 0; i < dim;i++){
            array[i] = rand() % 50;
            printf("%d ",array[i]);
        }
}

}