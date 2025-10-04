#include <iostream>
//preso n compreso tra 1 e 10 intero implementare un while e un for dove: nel while si stampa (prima di 100) tutti i valori di n sommando ogni volta n = n +10

using namespace std;

int main(){

    int n = 0;

    cout << "Inserisci n" << endl;
    do{ 
        cin >> n;

    }while(n < 1 || n > 10);

    cout << "Questo e' il while" << endl;

    while (n < 100){
        n = n +10;
        
    }
    cout << n;
    n = 0;
    cout << "Questo e' il for" << endl;

    for(int i = 0; n < 100; i++){
        n = n + 10;
        
    }
    cout << n;
}