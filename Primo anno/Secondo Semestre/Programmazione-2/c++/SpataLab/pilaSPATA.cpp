/*
    Scrivere una funzione copia pila che copia il contenuto di una pila in un'altra
    La funzione deve avere due argomenti di tipo pila, uno per la pila sorgente e un altro per la pila destinazione
*/

#include <iostream>

using namespace std;

class Node{
    public:
    Node(int d,Node *p):dato(d),next(p){}
    friend class Stack;

    private:
    int dato;
    Node *next;
};


class Stack{
    public:
    Stack():head(nullptr),lun(0){}
    void push(int d);
    void pop();
    void print();
    int getLun(){
        return lun;
    }
    void creaPila2(int dim);
    void copiaPila(Stack& pila1, Stack& pila2);

    private:
    Node *head;
    int lun;
};

void Stack::push(int d){

    head = new Node(d,head);
    lun++;
    return;

}

void Stack::pop(){

    Node *current = head;
    head = current->next;
    delete current;
    lun--;
    return;

}

void Stack::print(){
    Node *current = head;

    while(current != nullptr){
        cout << current->dato << " ";
        current = current->next;
    }

}

void Stack::creaPila2(int dim){

    for(int i = 0; i < dim; i++){
        head = new Node(0,head);
    }
    return;

}

void Stack::copiaPila(Stack& pila1, Stack& pila2){

    Node *currentPila1 = pila1.head;
    Node *currentPila2 = pila2.head;

    while(currentPila1 != nullptr){

        currentPila2->dato = currentPila1->dato;

        currentPila2 = currentPila2->next;
        currentPila1 = currentPila1->next;
    }
    
}


int main(){
    Stack pila;

    cout << "Funzione push" <<endl;
    pila.push(5);
    pila.push(4);
    pila.push(3);
    pila.push(2);
    pila.push(1);
    pila.print();

    cout << endl << "Funzione pop" <<endl;
    pila.pop();
    pila.pop();
    pila.print();

    cout << endl << "Funzione push" <<endl;
    pila.push(2);
    pila.push(1);
    pila.print();

    cout << endl <<"Copio la pila" <<endl;

    Stack pila2;
    int dim = pila.getLun();
    pila2.creaPila2(dim);
    pila2.copiaPila(pila,pila2);

    cout << "Stampo le 2 pile:" << endl << "Pila1 -> ";
    pila.print();
    cout << "Pila2 -> ";
    pila2.print();

    return 0;
}