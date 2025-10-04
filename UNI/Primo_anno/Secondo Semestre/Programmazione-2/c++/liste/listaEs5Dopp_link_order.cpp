//Una lista doppiamente linkata ordinata

#include <iostream>

using namespace std;

class List;

class Node{
    public:
    Node(int d, Node *p, Node *t):dato(d),next(p),prev(t){}
    friend class List;

    private:
    int dato;
    Node *next;
    Node *prev;
};

class List{
    public:
    List():head(nullptr){}
    void insertHead(int d);
    void print();
    Node* search(int d);
    void insertOrder(int d);
    bool rimozione(Node *x);
    private:
    Node *head;
};

void List::insertHead(int d){

    if(head == nullptr){
        head = new Node(d,head,nullptr);
    }else{
        Node *newNode = nullptr;
        newNode = new Node(d,head,nullptr);
        head->prev = newNode;
        head = newNode;
    }
}

void List::print(){
    Node *current = head;

    while(current != nullptr){

        cout << current->dato << " ";

        current = current->next;
    }
}

void List::insertOrder(int d){  //crescente

    Node *ant = head;
    Node *current = head;
    Node *newNode = nullptr;

    if(current == nullptr){ //lista vuota
        List::insertHead(d);
        return;
    }

    if(head->dato > d){      //caso inserimento in testa
        List::insertHead(d);
        return;
    }

    while(current != nullptr && current->dato < d){ //trovo la posizione
        ant = current;
        current = current->next;
    }


    newNode = new Node(d,current,ant);
    ant->next = newNode;
    if(current != nullptr){
        current->prev = newNode;
    }
    

}

Node* List::search(int d){

    Node *current = head;

    while(current != nullptr){
        if(current->dato == d){
            return current;
        }

        current = current->next;
    }

    return nullptr;
    
}

bool List::rimozione(Node *x){
    Node *current = head;
    Node *ant = head;

    if(current == nullptr){ //caso lista vuota
        return false;
    }

    if(head == x){
        head = head->next;
        head->prev = nullptr;
        delete x;
        return true;
    }

    while(current != nullptr){

        if(current == x){
            ant->next = current->next;
            if(current->next != nullptr){
                current->next->prev = ant;
            }
            return true;
            
        }

        ant = current;
        current = current->next;
    }


    return false;
}



int main(){

    List lista;

    lista.insertHead(12);
    lista.insertHead(10);
    lista.insertHead(8);
    lista.insertHead(6);
    lista.print();
    cout <<endl;
    cout << "Aggiungo 4,9,14 e ristampo" <<endl;
    lista.insertOrder(4);
    lista.insertOrder(9);
    lista.insertOrder(14);
    lista.print();

    cout << endl << "Cerco il nodo 9" <<endl;
    cout << lista.search(9);

    cout << endl << "Cerco un nodo non esistente" <<endl;
    cout << lista.search(11);

    cout <<endl;
    cout << "Elimino il 4" <<endl;
    cout << lista.rimozione(lista.search(4)) <<endl;
    lista.print();

    cout <<endl;
    cout << "Elimino il 14" <<endl;
    cout << lista.rimozione(lista.search(14)) <<endl;
    lista.print();

    cout <<endl;
    cout << "Elimino il 10" <<endl;
    cout << lista.rimozione(lista.search(10)) <<endl;
    lista.print();

    cout << "Elimino un nodo che non esiste" <<endl;
    cout << lista.rimozione(lista.search(100)) <<endl;
    lista.print();

}
