//lista di interi

#include <iostream>

using namespace std;

class List;
class Node{
    public:
    Node(int d, Node *p):dato(d),next(p){}
    friend class List;

    private:
    int dato;
    Node *next;
};

class List{

    public:
    List():head(nullptr){}

    void inOrdinato(int d);
    void printList();
    bool rimozione(int d);

    private:
    Node *head;
};

void List::inOrdinato(int d){   //crescente

    Node *newNode = nullptr;
    Node *controllo = head;
    Node *ant = head;

    if(head == nullptr){    //caso in cui la lista è vuota
        head = new Node(d,head);
        return;
    }

    if(head->dato > d){     //caso in cui la testa sia più grande del dato da inserire
        head = new Node(d,head);
        return;
    }

    while(controllo != nullptr && controllo->dato < d){ //scorre finche non trovo la posizione giuista

        ant = controllo;
        controllo = controllo->next;
    }

    newNode = new Node(d,controllo);
    ant->next = newNode;
    return;

}


void List::printList(){
    cout << "Stampa della lista" <<endl;

    Node *current = head;

    while(current != nullptr){

        cout << current->dato <<endl;
        current = current->next;
    }
}

bool List::rimozione(int d){

    cout << "Rimozione" <<endl;

    Node *current = head;
    Node *ant = head;
    
    while(current != nullptr){

        if(current->dato == d){
            ant->next = current->next;
            delete current;
            return true;;
        }

        ant = current;
        current = current->next;
    }
    return false;

}


int main(){

    List lista;

    lista.inOrdinato(10);
    lista.inOrdinato(20);
    lista.inOrdinato(30);
    lista.inOrdinato(40);
    lista.inOrdinato(50);
    lista.inOrdinato(0);
    lista.printList();

    lista.rimozione(40);
    lista.printList();

}
