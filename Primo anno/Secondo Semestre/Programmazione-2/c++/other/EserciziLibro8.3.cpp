#include <iostream>
#include <new>
using namespace std;

void memoryLeak(){
    cout << "memoria insufficente" <<endl;
    exit(-1);
}

int main(){

    set_new_handler(memoryLeak);
    long int dimensione = 0;
    int numero = 0;
    cout << "Inserire la dimensione da allocare... " << endl;
    cin >> dimensione;
    
     
    int *arrayD = new int[dimensione];
    cout << "Allocazione blocco numero: " << arrayD << endl;
    
    cout << "inserisci un numero da mettere negli array ";
    cin >> numero;
    for(int j = 0; j < dimensione; j++){
        
        arrayD[j] = numero;
        cout << arrayD[j] << " ";
    }
    int somma = 0;
    for(int i = 0; i < dimensione; i++){
        somma = somma + arrayD[i];
    }
    cout << "La somma e' " << somma << endl;
}