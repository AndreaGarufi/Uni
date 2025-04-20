//Una lista concatenata ordinata

#include <iostream>

using namespace std;

class List;
ostream& operator<<(ostream& stream, const List& list);

class Node{
    public:
        Node(int d,Node *p):dato(d),next(p){}
        friend class List;
        friend ostream& operator<<(ostream& stream, const List& list);

    private:
        int dato;
        Node *next;
};

class List{
    public:
        List():head(nullptr){}
        friend ostream& operator<<(ostream& stream, const List& list);
        void inOrdinato(int d);
    
    private:
        Node *head;
};

void List::inOrdinato(int d){   //crescente

    Node *newNode = nullptr;
    Node *controllo = head;
    Node *ant = head;
     
    if(head == nullptr){        //caso lista vuota
        head = new Node(d,head);
        return;
    }

    if(head->dato > d){         //gestisco caso della testa (d è più piccolo della testa (diventa la nuova testa))
    newNode = new Node(d,head);
    head = newNode;
    return;
    }

    while(controllo != nullptr && controllo->dato < d){
        ant = controllo;
        controllo = controllo->next;
    }

    // inserimento tra ant e controllo (che può anche essere nullptr, cioè fine lista)
    newNode = new Node(d,controllo);
    ant->next = newNode;

    return;
}


ostream& operator<<(ostream& stream, const List& list){ //è importante mettere il riferimento & perche altrimenti faccio una copia

    stream << "Gli elementi della lista sono: ";
    Node *p = list.head;
    while(p != nullptr){
        stream << p->dato << ", ";  
        p = p->next;
    }
    stream <<endl;
    return stream;
}

int main(){

    List lista;

    lista.inOrdinato(10);
    lista.inOrdinato(8);
    lista.inOrdinato(7);
    lista.inOrdinato(5);
    lista.inOrdinato(1);
    cout << lista;

    
}