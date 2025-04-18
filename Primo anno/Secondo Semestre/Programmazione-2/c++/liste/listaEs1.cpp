//Una lista concatenata di interi

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class List;
ostream& operator<<(ostream& stream, const List& list);

class Node{
    public:
        Node(int d,Node *p = nullptr): dato(d),next(p){}
        friend ostream& operator<<(ostream& stream, const List& list);
        friend class List;
    private:
    int dato;
    Node *next;
};

class List{
    public:
    List():head(nullptr){}
    friend ostream& operator<<(ostream& stream, const List& list);
    void inserimentoTesta(int d);
    Node* search(int d);
    void inserimento(int d, Node *p);
    bool rimozione(int d);
    private:
    Node *head;
};

void List::inserimentoTesta(int d){
    head = new Node(d,head);
}

Node* List::search(int d){

    Node *controllo = head;

    while(controllo != nullptr){
        if(controllo->dato == d){
            return controllo;
        }
        controllo = controllo->next;
    }
    return nullptr;
}

void List::inserimento(int d, Node *p){

    Node *n = new Node(d,p->next);
    p->next = n;
}

bool List::rimozione(int d){
    Node *controllo = head;
    Node *ant = nullptr;

    while(controllo != nullptr){

        if(controllo->dato == d){
            ant->next = controllo->next;
            delete controllo;
            return true;
        }
        ant = controllo;
        controllo = controllo->next;
    }
    return false;
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
    int n = 0;

    srand(time(0));
    int numero = rand()% 11 + 2;

    for(int i = 0;i < numero; i++){
        lista.inserimentoTesta(i);
    }
    cout << lista;

    cout <<endl << "Quale nodo vuoi cercare?" <<endl;
    cin >> n;
    cout << "Il puntatore e': " <<lista.search(n) <<endl;

    if(lista.search(n) != nullptr){
        cout << "Inserisco il numero 99" <<endl;
        lista.inserimento(99,lista.search(n));
        cout << lista;
    }
    
    cout << "Quale numero vuoi rimuovere? " <<endl;
    cin >> n;
    cout << "Rimozione nodo contenente " << n <<endl;
    cout << lista.rimozione(n) <<endl;
    cout << lista;
}