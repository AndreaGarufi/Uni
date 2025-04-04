#include <iostream>

#include "pila.h"

using namespace std;

int main()
{
    Pila<int> pila_interi;      //<int> questo è il tipo che sto passando al template (potrei mettere float char ecc...)
    
  
    pila_interi.Push(1);
    pila_interi.Push(2);
    pila_interi.Push(3);
    pila_interi.Push(4);
    pila_interi.Push(5);
    pila_interi.Push(6);
    pila_interi.Push(7);
    pila_interi.Push(8);
    pila_interi.Push(9);
    cout << "Elementi estratti dalla pila: " << endl;
    
    for(int i = 0; i < 9;i++){
        cout << pila_interi.Pop() << endl;
    }
 }