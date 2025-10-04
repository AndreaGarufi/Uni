#include <iostream>
using namespace std;
//dire se il numero inserito è perfetto o no, usando una funzione di nome perfetto che ritorna un bool
bool perfetto(int n);
int main(){

    int numero = 0;

    cout << "Inserisci un numero" << endl;

    cin >> numero;


    bool perf = perfetto(numero);

    if(perf == true){
        cout << "Il numero e' perfetto" << endl;
    }else{
        cout << "Il numero non e' perfetto" << endl;
    }

}

bool perfetto(int n){
    int k = 0;
    for(int i = 1; i < n; i++){

        if(n % i == 0){
           k = k + i; 
        }
    }
    if(k == n){
        return true;
    }else{
        return false;
    }


}