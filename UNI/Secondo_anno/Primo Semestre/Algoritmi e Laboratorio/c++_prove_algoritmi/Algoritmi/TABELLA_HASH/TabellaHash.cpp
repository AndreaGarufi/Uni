#include <iostream>

using namespace std;

class List;
class Node;
class Hash;

class Node{
    public:
    Node(int numero, Node *p = nullptr):next(p),elemento(numero){}
    friend class List;

    private:
    int elemento;

    Node *next;
};

class List{
    public:
    List():head(nullptr){}
    void insert(int numero);
    void printList();

    ~List(){}

    private:
    Node *head;
};

class Hash{

    public:
    Hash():array{NULL},dim(10),carico(0),numeroElementi(0){

        for(int i = 0; i < dim; i++){
            array[i] = new List();
        }
    }
    friend class List;
    friend class Node;
    void loadFactor();
    int hash(int k,int dim);
    void insertHASH(int k);
    void printHASH();

    private:
    List *array[10];
    int dim;
    float carico;
    int numeroElementi;

};

void List::printList(){
    int i = 0;
    Node *current = head;
    while(current != nullptr){
        cout << current->elemento <<endl;
        current = current->next;
        i++;    //contatore lista se è più di 1 allora ci sono collisioni
        cout << "------"<<i<<"------" <<endl;
    }
}

void List::insert(int numero){
    head = new Node(numero,head);
    
}

void Hash::loadFactor(){
    carico = (float) numeroElementi/dim;
    float percentuale = carico*100;
    cout << "Fattore di carico: " << percentuale <<"% " << "Dimensione Totale: " << dim << " + liste concatenate" <<endl;
}

int Hash::hash(int k,int dim){  //hashing per divisione

    int posizione = k%dim;

    return posizione;
} 

void Hash::insertHASH(int k){
    int indice = hash(k,dim);
    array[indice]->insert(k);
    numeroElementi++;
}

void Hash::printHASH(){

    for(int i = 0; i < dim; i++){

        array[i]->printList();
    }
}


int main(){

    List lista;
    /*lista.insert(10);
    lista.insert(5);
    lista.printList();*/

    Hash tabella;

    tabella.insertHASH(10);
    tabella.insertHASH(9);
    tabella.insertHASH(81);
    tabella.insertHASH(23);
    tabella.printHASH();
    tabella.loadFactor();

    //capire se ci sono collisioni e stamparle,


}