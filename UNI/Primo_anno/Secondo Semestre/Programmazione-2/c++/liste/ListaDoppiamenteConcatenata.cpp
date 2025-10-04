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
        void insertHead(int d);
        bool remove(int d);
        Node* search(int d);
        void insert(int d,Node *x);
        friend ostream& operator<<(ostream& stream, const List& list); 

    private:
        Node *head;
};

void List::insertHead(int d){

    if(head == nullptr){    //lista vuota
        head = new Node(d); //al costruttore passo solo il dato perche essendo il primo nodo next e prev saranno null
    }else{
        Node *nuovo = new Node(d,head);   //creo il nuovo nodo dicendo che il next di questo nodo è head
        head->prev = nuovo;               //il penultimo nodo punta a nuovo
        head = nuovo;                     //la nuova testa è nuovo
    }

}

bool List::remove(int d){

    Node *controllo = head;
    
    if(controllo == nullptr){   //caso lista vuota
        return false;
    }
    
    while(controllo != nullptr){
        if(controllo->data == d){   //se corrisponde elimino
            break;
        }
        controllo = controllo->next;
    }

    if(controllo->prev == nullptr){     //caso della testa
        head = controllo->next;  //qui va nell'ultimo
        if (head != nullptr){   //qui entra in ogni caso di eliminazione in testa tranne nell'ultimo
            head->prev = nullptr;
        }
    }else if(controllo->next == nullptr){   //caso ultimo nodo
        controllo->prev->next = nullptr;

    }else{  //tutti gli altri casi
        controllo->prev->next = controllo->next;
        controllo->next->prev = controllo->prev;;
    }
    delete controllo;
    return true;
}

Node* List::search(int d){

    Node *controllo = head;

    while(controllo != nullptr){
        if(controllo->data == d){
            return controllo;
        }
        controllo = controllo->next;
    }

    return nullptr;


}

void List::insert(int d,Node *x){//capire bene

    Node *p = new Node(d,x->next);
    x->next = p;
    p->prev = x;
    if (p->next != nullptr) {
        p->next->prev = p;
    }
}

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

    lista.insertHead(10);
    lista.insertHead(5);
    lista.insertHead(2);
    lista.insertHead(1);
    cout << lista;

    cout << "Elimina il 5" << endl;
    lista.remove(5);
    cout << lista;

    cout << "Elimina il 1" << endl;
    lista.remove(1);
    cout << lista;

    cout << "Elimina il 10" << endl;
    lista.remove(10);
    cout << lista;

    cout << "Elimina il 2" << endl;
    lista.remove(2);
    cout << lista;

    lista.remove(2);
    //cout << "crasha?";

    cout << "Reinserisco tutto" << endl;
    lista.insertHead(10);
    lista.insertHead(5);
    lista.insertHead(2);
    lista.insertHead(1);
    cout << lista;

    cout << "Cerca il nodo con dato 2: " << lista.search(2) <<endl;
    
    cout << "Cerca il nodo con dato 7: (inesistente) " << lista.search(7) <<endl;

    cout << "Inserimento dopo un determinato nodo: " << endl;
    lista.insert(7,lista.search(5));
    cout << lista;

}