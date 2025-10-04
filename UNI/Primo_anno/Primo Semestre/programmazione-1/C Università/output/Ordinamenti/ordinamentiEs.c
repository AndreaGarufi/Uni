#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void bubbleSort(int dim);
void insertionSort(int dim);
void selectionSort(int dim);

int main(){
    srand(time(NULL));
    int numero = 0;
    int operazione = 0;

    printf("Quanti elementi casuali vuoi nel tuo array?\n");
    scanf("%d",&numero);

    printf("\nChe ordinamento vuoi fare? 1 -> bubble sort, 2-> insertion sort, 3-> selection sort, -1 per uscire\n");
    
    do{
        scanf("%d",&operazione);
        switch(operazione){
            case 1: printf("BUBBLE SORT\n");
            bubbleSort(numero);
            break;
            case 2: printf("INSERTION SORT\n");
            insertionSort(numero);
            break;
            case 3: printf("SELECTION SORT\n");
            selectionSort(numero);
            break;
            default: if(operazione != -1){
                printf("Inserisci il numero giusto");
                break;
            }else{
                break;
            }
            
        }        
    }while(operazione != -1);
    
}

void bubbleSort(int dim){

    int *a = (int*)malloc(sizeof(int) * dim);

    printf("Stampa vettore NON ORDINATO\n");
    for(int i = 0; i < dim; i++){
        a[i] = rand() % 99;
        printf("%d ",a[i]);
    }
    //bubble sort
    for(int i = 0; i < dim; i++){

        for(int j = 0; j < dim - 1; j++){
            if (a[j] > a[j + 1]){
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("\nStampa vettore ORDINATO\n");
    for(int i = 0; i < dim; i++){
        printf("%d ",a[i]);
    }

    free(a);
}

void insertionSort(int dim){

    int *a = (int*)malloc(sizeof(int) * dim);

    printf("Stampa vettore NON ORDINATO\n");
    for(int i = 0; i < dim; i++){
        a[i] = rand() % 99;
        printf("%d ",a[i]);
    }

    for(int i = 1; i < dim; i++){
        int posizione = i;
        int elemento = a[i];

        while(posizione > 0 && a[posizione - 1] > elemento){
            a[posizione]  = a[posizione - 1];
            posizione--;
        }
        a[posizione] = elemento;
    }

    printf("\nStampa vettore ORDINATO\n");
    for(int i = 0; i < dim; i++){
        printf("%d ",a[i]);
    }

    free(a);
}

void selectionSort(int dim){

    int *a = (int*)malloc(sizeof(int) * dim);
    printf("Stampa vettore NON ORDINATO\n");
    for(int i = 0; i < dim; i++){
        a[i] = rand() % 99;
        printf("%d ",a[i]);
    }

    for(int i = 0; i < dim -1; i++){                      
        int minimo = i;                                 
        for(int j = i + 1; j < dim; j++){
            if(a[j] < a[minimo]){
                minimo = j;
            }
        }
        int temp = a[i];                                    
        a[i] = a[minimo];                                  
        a[minimo] = temp;
    }

    printf("\nStampa vettore ORDINATO\n");
    for(int i = 0; i < dim; i++){
        printf("%d ",a[i]);
    }

    free(a);
}