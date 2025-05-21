//crea una classe pila usando un array
#include <iostream>

using namespace std;

class Stack{
    public:
    Stack():top(0){}

    void print(){
        for(int i = 0; i < top; i++){
            cout << array[i] << " ";
        }
    }

    void push(int d);
    void pop();

    private:
    static const int numero = 10;   //chiedere il perche di questo static;
    int array[numero];
    int top;

};

void Stack::push(int d){

    if(top == numero){
        cout << "La pila e' piena" <<endl;
        return;
    }
    array[top] = d;
    top++;
    return;
    
}

void Stack::pop(){
    if(top == 0){
        cout << "La pila e' vuota" <<endl;
        return;
    }
    top--;
    array[top] = 0;
    
    return;
}

int main(){

    Stack dati;

    dati.push(1);
    dati.push(2);
    dati.push(3);
    dati.push(4);
    dati.push(5);
    dati.push(6);
    dati.push(7);
    dati.push(8);
    dati.push(9);
    dati.push(10);
    dati.push(11);
    dati.print();

    cout << endl;

    dati.pop();
    dati.pop();
    dati.pop();
    dati.pop();
    dati.pop();
    dati.print();

    cout << endl;
    cout << "Elimino tutto" << endl;
    dati.pop();
    dati.pop();
    dati.pop();
    dati.pop();
    dati.pop();
    dati.pop();

    return 0;
}


