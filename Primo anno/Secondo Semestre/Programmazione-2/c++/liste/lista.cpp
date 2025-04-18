#include <iostream>
#include <fstream>

using namespace std;

class List;
ostream& operator<<(ostream& stream, const List& list); 

class Node{     //classe del singolo nodo
    public:
        Node(int d, Node *p = nullptr): dato(d), next(p){}  //costruttore: inizializzo dato e next con d e p
        friend class List;  //dico che la classe List è amica della class Node cosi puo accedere ai suoi membri privati
        friend ostream& operator<<(ostream& stream, const List& list); //anche qui l'operator << è amico di Node

    private:
        int dato;       //variabili dentro il nodo
        Node *next;
};


class List{
    
    public:
        List() : head(nullptr){}    //costruttore: (inizializzo head a NULL)
        List& InsertHead(int d);
        void Insert(int d, Node *p);
        Node* Search(int d);
        bool Remove(int d);

        friend ostream& operator<<(ostream& stream, const List& list); 


    private:
        Node *head;
};

bool List:: Remove(int d){
    Node *ant = nullptr;    //nodo precedente
    Node *cur = head;        //nodo corrente

    while(cur != nullptr){
        if(d == cur->dato){
            break;
        }
        ant = cur;          //li sposto tutti e 2 finche non trovo il nodo da cancellare
        cur = cur->next;
    }

    if(cur == nullptr){ //caso lista vuota
        return false;
    }
    if(ant == nullptr){ //caso in cui devo eliminare il primo elemento della lista oppure ho un solo nodo
        head = cur->next;
    }else{                      //tutti gli altri casi
        ant->next = cur->next;
    }

    delete cur;

    return true;
    
}

Node* List::Search(int d){

    Node *p = head;
    while(p != nullptr){
        if(p->dato == d){
            return p;
        }
        p = p->next;
    }
    return nullptr;

}

List& List::InsertHead(int d){
    head = new Node(d,head);
    return *this;
}

void List::Insert(int d, Node *p){
    Node *n = new Node(d,p->next);
    p->next = n;
}

//operator che formatta la stampa in maniera personalizzata
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
    cout << lista <<endl;
    lista.InsertHead(3).InsertHead(7).InsertHead(10);
    cout << lista << endl;
    cout << "Il puntatore al nodo 3 e':" << lista.Search(3) <<endl;

    cout << "Inserisco un elemento dopo il 7: " << endl;
    lista.Insert(99, lista.Search(7));  //aggiunge il valore 99 dopo il valore 7

    cout << "Elemento 3 rimosso: " << lista.Remove(3) << endl;
    cout << lista << endl;
    cout << "Elemento 3 RIrimosso: " << lista.Remove(3) << endl;

    return 0;
}