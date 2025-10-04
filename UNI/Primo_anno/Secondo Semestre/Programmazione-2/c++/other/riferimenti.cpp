#include <iostream>
using namespace std;

int scambiaR(int& a, int& b){       //si scambiano
    int temp = a;
    a = b;
    b = temp;
    return a,b;
}

int scambia(int a, int b){
    int temp = a;
    a = b;
    b = temp;
    //cout << "X = " << a << " Y = " << b << endl;    //si scambiano solo dentro questa funzione
    return a,b;
    
}

int main(){

    int x = 3;
    int y = 4;

    cout << "X = " << x << " Y = " << y << endl;
    scambiaR(x,y);
    cout << "X = " << x << " Y = " << y << endl;

    scambia(x,y);   //qui lo scambio nonm funziona perché non ho passatro i riferimenti ma ho passato normalmente per valore
    cout << "X = " << x << " Y = " << y << endl;


}