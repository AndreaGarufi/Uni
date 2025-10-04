#include <iostream>
using namespace std;

int main(){

    int *arrayDinamico = new int[10];

    for(int i = 0; i < 10; i++){
        arrayDinamico[i] = 1;
        cout << " " <<arrayDinamico[i];
    }

    delete [] arrayDinamico;
}