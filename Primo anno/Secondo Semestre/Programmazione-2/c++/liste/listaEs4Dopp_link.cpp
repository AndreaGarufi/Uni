//Una lista doppiamente linkata

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class List;

class Node{
    public:     //next                  //prev
    Node(int d,Node *p = nullptr, Node *t = nullptr):dato(d),next(p),prev(t){}
    friend class List;

    private:
    int dato;
    Node *next;
    Node *prev;

};

class List{
    public:
    List():head(nullptr){}

    void inHead(int d);
    void printList();
    Node* search(int d);
    bool remove(Node *x);

    private:
    Node *head;

};

void List::inHead(int d){

    if(head == nullptr){    //lista vuota
        head = new Node(d,head,nullptr);
    }else{
        Node *newNode = new Node(d,head,nullptr);
        head->prev = newNode;
        head = newNode;
    }
    return;

}

void List::printList(){

    Node *current = head;

    while(current != nullptr){

        cout << current->dato << " ";

        current = current->next;
    }
    return;

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

bool List::remove(Node *x){

    Node *current = head;
    Node *ant = head;

    if(current == nullptr){ //caso lista vuota
        return false;
    }

    if(current->prev == nullptr && current == x){  //caso eliminazione in testa
        head = current->next;
        head->prev = nullptr;
        delete current;
        return true;
    }

    while(current != nullptr){

        if(current == x){
            if(current->next == nullptr){
                ant->next = nullptr;
                delete current;
                return true;
            }
            ant->next = current->next;
            current->next->prev = current->prev;
            delete current;
            return true;
        }

        ant = current;
        current = current->next;
    }
    return false;

}


int main(){

    List lista;
    srand(time(0));
    cout << "Inserisco dei valori nella lista doppiamente linkata" <<endl;

    for(int i = 0; i < 7;i++){
        int numero = rand()% 11 + 2;
        lista.inHead(numero);
    }

    lista.printList();

    cout <<endl;
    cout << "Cerco il numero 6 nella lista e ritorno il puntatore se questo elemento esiste " <<endl;
    cout << lista.search(6) <<endl;

    if(lista.search(6) != nullptr){
        cout << "Elimino il nodo cercato " <<endl;
        cout << lista.remove(lista.search(6));
    }
    cout <<endl;
    lista.printList();



}