#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T> 
class List;

template <typename T>
ostream& operator<<(ostream& stream, const List<T>& list);

template <typename T>
class Node{

    public:
    Node(T d, Node *p):dato(d), next(p){}
    friend class List<T>;
    friend ostream& operator<< <T>(ostream& stream, const List<T>& list);
    private:
    T dato;
    Node<T> *next;
};

template <typename T>
class List{

    public:
    List():head(nullptr){}
    friend ostream& operator<< <T>(ostream& stream, const List<T>& list);
    void inserimentoTesta(T d);
    Node<T>* search(T d);
    bool rimozione(Node<T>* p);
    void inserimento(T d,Node<T>* p);

    private:
    Node<T> *head;

};

template <typename T>
void List<T>::inserimentoTesta(T d){
    head = new Node<T>(d,head);
}

template <typename T>
Node<T>* List<T>::search(T d){

Node<T> *controllo = head;
    while(controllo != nullptr){

        if(controllo->dato == d){
            return controllo;
        }

        controllo = controllo->next;
    }
    return nullptr;
}

template <typename T>
bool List<T>::rimozione(Node<T>* p){
    Node<T>* controllo = head;
    Node<T>* ant = head;

    while(controllo != nullptr){
        if(controllo == p){
            ant->next = controllo->next;
            delete controllo;
            return true;
        }
        ant = controllo;
        controllo = controllo->next;
    }
    return false;
}

template <typename T>
void List<T>::inserimento(T d,Node<T>* p){

    Node<T>* newNode = new Node(d,p->next);
    p->next = newNode;

}

template <typename T>
ostream& operator<<(ostream& stream, const List<T>& list){

    stream << "Gli elementi della lista sono: ";
    Node<T> *p = list.head;
    while(p != nullptr){
        stream << p->dato << ", ";  
        p = p->next;
    }
    stream <<endl;
    return stream;
}



int main(){

    List<int> lista;
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
    cout << lista.rimozione(lista.search(n)) <<endl;
    cout << lista;

}