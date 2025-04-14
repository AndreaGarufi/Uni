#include <iostream>
#include <fstream>

using namespace std;

class List;

class Node{         
    public:          //next               prev
        Node(int d,Node *p = nullptr, Node *t = nullptr): data(d), next(p), prev(t){}
        friend class List;
        friend ostream& operator<<(ostream& stream, const List& list); 

    private:
        int data;
        Node *next;
        Node *prev;
};


class List{

    public:
        List() : head(nullptr) {}
        void InsertHead(int d);

        friend ostream& operator<<(ostream& stream, const List& list); 

    private:
        Node *head;
};

void List::InsertHead(int d){

    if(head == nullptr){    //lista vuota
        head = new Node(d); //al costruttore passo solo il dato perche essendo il primo nodo next e prev saranno null
    }else{
        Node *nuovo = new Node(d,head);   //creo il nuovo nodo dicendo che il next di questo nodo è head
        head->prev = nuovo;               //il precedente punta al next di nuovo
        head = nuovo;                     //la nuova testa è nuovo
    }

}

//spiegare da girlando
ostream& operator<<(ostream& stream, const List& list){ //è importante mettere il riferimento & perche altrimenti faccio una copia

    stream << "Gli elementi della lista sono: ";
    Node *ptr = list.head;
    while(ptr != nullptr){
        stream << ptr->data << ", ";  
        ptr = ptr->next;
    }
    stream <<endl;
    return stream;
}


int main(){

    List lista;

    lista.InsertHead(10);
    lista.InsertHead(5);
    lista.InsertHead(2);
    lista.InsertHead(1);
    
    cout << lista;

}