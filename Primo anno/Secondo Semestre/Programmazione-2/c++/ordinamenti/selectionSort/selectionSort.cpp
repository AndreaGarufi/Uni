#include <iostream>

using namespace std;

void selectionSort(int a[],int dim){
    
    for(int i = 0; i < dim; i++){
        int minimo = i;
        for(int j = i+1; j < dim; j++){
            if(a[minimo] > a[j]){
                minimo = j;
            }
        }
        int temp = a[i];
        a[i] = a[minimo];
        a[minimo] = temp;
    }
}

int main(){
    int array[8] = {42, 57, 14, 40, 96, 19, 8, 68};

    cout << "Stampa array non ordinato" <<endl;
    for(int i = 0; i < 8; i++){
        cout << array[i] << " ";
    }
    cout <<endl;

    cout << "Stampa array ordinato tramite SelectionSort" <<endl;
    selectionSort(array,8);
    for(int i = 0; i < 8; i++){
            cout << array[i] << " ";
        }
    cout <<endl;
}