//crea una classe coda usando un array
#include <iostream>

using namespace std;
#define MAX 10

class Queue{
    public:
    Queue():top(0),deTop(0){}
    void enQueue(int d);
    void deQueue();
    void print();

    private:
    int top;
    int deTop;
    int array[MAX];
};

void Queue::enQueue(int d){

    if(top == MAX){
        cout << "La coda e' piena, non posso inserire: " << d <<endl;
        return;
    }
    array[top] = d;
    top++;
    return;
}

void Queue::deQueue(){
    if(deTop == MAX){
        cout << "La coda e' vuota " <<endl;
        return;
    }
    array[deTop] = 0;
    deTop++;
    return;
}

void Queue::print(){

    for(int i = deTop; i < top; i++){
        cout << array[i] << " ";
    }
}

int main(){

    Queue dati;

    dati.enQueue(1);
    dati.enQueue(2);
    dati.enQueue(3);
    dati.enQueue(4);
    dati.enQueue(5);
    dati.enQueue(6);
    dati.enQueue(7);
    dati.enQueue(8);
    dati.enQueue(9);
    dati.enQueue(10);
    dati.enQueue(11);
    dati.print();

    cout << "Svuoto la coda " << endl;

    dati.deQueue();
    dati.deQueue();
    dati.deQueue();
    dati.deQueue();
    dati.deQueue();
    dati.print();
    dati.deQueue();
    dati.deQueue();
    dati.deQueue();
    dati.deQueue();
    dati.deQueue();
    dati.deQueue();
    dati.print();

    return 0;
}