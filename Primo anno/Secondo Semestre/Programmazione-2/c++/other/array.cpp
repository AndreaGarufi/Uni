#include <iostream>
using namespace std;

int main(){
    
    const int n = 3;
    int array[n];
    
    for(int i = 0; i < n; i++){
        cout << "Inserire un numero: ";
        cin >> array[i];
        cout << array[i] << endl;
    }
   
    
    return 0;
}