/*
    Scrivere una funzione copia pila che copia il contenuto di una pila in un'altra
    La funzione deve avere due argomenti di tipo pila, uno per la pila sorgente e un altro per la pila destinazione
    SPIEGAZIONE: uso una pila d'appoggio per la copia temporanea e poi la uso per riempire di nuovo le due pile
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
    Stack():head(nullptr){}
    void push(int d);
    void pop();
    void print();

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

    

    return 0;
}