#include <iostream>

using namespace std;

void bubbleSort(int a[],int dim){

    for(int i = 0; i < dim-1; i++){
        for(int j = 0; j < dim-1; j++){

            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}


int main(){

    int array[8] = {42, 57, 14, 40, 96, 19, 8, 68};

    cout << "Stampa array non ordinato" <<endl;
    for(int i = 0; i < 8; i++){
        cout << array[i] << " ";
    }
    cout <<endl;

    cout << "Stampa array ordinato tramite BubbleSort" <<endl;
    bubbleSort(array,8);
    for(int i = 0; i < 8; i++){
        cout << array[i] << " ";
    }
}