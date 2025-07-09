#include <iostream>

using namespace std;

template <typename T>
class List;

template <typename T>
class Node{
    public:
    Node(int d,Node<T> *p):dato(d),next(p){}
    friend class List<T>;

    private:
    int dato;
    Node<T> *next;
};

template <typename T>
class List{
    public:
    List():head(nullptr){}
    void insert(int d);
    void print();
    private:
    Node<T> *head;
};

template <typename T>
void List<T>::print(){
    Node<T> *current = head;

    while(current != nullptr){
        cout << current->dato << " ";
        current = current->next;
    }
    cout <<endl;
}

template <typename T>
void List<T>::insert(int d){
    head = new Node<T>(d,head);
}

class Bst;
class BstNode{
    public:
    BstNode():dato(0),left(0),right(0),padre(0){}
    friend class Bst;
    private:
    int dato;

    BstNode *left;
    BstNode *right;
    BstNode *padre;   
};

class Bst{
    public:
    Bst():root(nullptr){}
    void insert(int d);
    void printRicorsiva();
<<<<<<< HEAD
    void print(BstNode *r);
    void eliminaAlbero(BstNode *r);
    ~Bst(){
        eliminaAlbero(root);
    }
=======
    
>>>>>>> origin/main

    private:
    void print(BstNode *r);
    BstNode *root;
};

void Bst::eliminaAlbero(BstNode *r){
    if(r != nullptr){
    eliminaAlbero(r->left);
    eliminaAlbero(r->right);
    delete r;
    }
}

void Bst::printRicorsiva(){
    print(root);
    cout <<endl;
}

void Bst::print(BstNode *r){
    if(r != nullptr){
        print(r->left);
        cout << r->dato << " ";
        print(r->right);
    }
}   

void Bst::insert(int d){
    BstNode *x = root;
    BstNode *y = nullptr;    

    while(x != nullptr){
        y = x;

        if(d > x->dato){
            x = x->right;
        }else{
            x = x->left;
        }
    }

    BstNode *newNode = new BstNode();
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->padre = y;
    newNode->dato = d;

    if(y == nullptr){
        root = newNode;
    }else if(y->dato > newNode->dato){
        y->left = newNode;
    }else{
        y->right = newNode;
    }

}

int main(){

    List<int> lista;
    lista.insert(10);
    lista.insert(11);
    lista.insert(12);
    lista.insert(13);
    lista.insert(14);
    lista.insert(15);
    lista.print();


    Bst albero;

    albero.insert(10);
    albero.insert(11);
    albero.insert(12);
    albero.insert(13);
    albero.insert(14);
    albero.insert(15);
    albero.printRicorsiva();

    return 0;
}