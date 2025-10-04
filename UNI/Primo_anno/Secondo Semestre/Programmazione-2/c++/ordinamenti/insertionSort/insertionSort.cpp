#include <iostream>

using namespace std;

void insertionSort(int a[],int dim){

    for (int i = 1; i < len; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }

}


int main(){
int array[8] = {42, 57, 14, 40, 96, 19, 8, 68};

    cout << "Stampa array non ordinato" <<endl;
    for(int i = 0; i < 8; i++){
        cout << array[i] << " ";
    }
    cout <<endl;

    cout << "Stampa array ordinato tramite InsertionSort" <<endl;
    insertionSort(array,8);
    for(int i = 0; i < 8; i++){
        cout << array[i] << " ";
    }
    cout <<endl;
}