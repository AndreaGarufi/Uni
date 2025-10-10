#include <iostream>
using namespace std;

int sommaDispari(int n){
    while(n > 0){
        if(n%2 != 0){
            return n+sommaDispari(n-1);
        }else{
            n--;
        }
    }
    return n;
}

int sommaDispari2(int n){
    if(n ==0){
        return 0;
    }else{
        return (2*n-1) + sommaDispari2(n-1);
    }

}

int main(){

cout << sommaDispari(10);
cout << endl;
cout << sommaDispari2(10);
}