#include <iostream>

using namespace std;

class Bst;
class BstNode{
    public:
    BstNode(){}
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
    ~Bst(){
        Delete(root);
    }

    void insert(int d);
    int search(int d);
    int maxMin();
    void print();

    private:
    void Delete(BstNode *node);
    void print(BstNode *node);
    BstNode *root;
};

void Bst::insert(int d){

    BstNode *x = root;  //nodo corrente
    BstNode *y = nullptr;   //padre del nodo

    while(x != nullptr){    //questo ciclo mi trova la posizione in cui aggiungere il nodo
        y = x;

        if(d < x->dato){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    BstNode *newNode = new BstNode; //creo il nodo e assegno i vari dati
    newNode->dato = d;
    newNode->padre = y;
    newNode->left = nullptr;   //null perche essendo un nodo foglia non ha figli destri o sinistri
    newNode->right = nullptr;

    if(y == nullptr){
        root = newNode;
    }else if(d < y->dato){
        y->left = newNode;
    }else{
        y->right = newNode;
    }
    return;

}

int Bst::search(int d){
    BstNode *current = root;

    while(current != nullptr && current->dato != d){
        if(current->dato > d){
            current = current->left;
        }else{
            current = current->right;
        }
    }

    if(current == nullptr){
        cout << "Elemento non trovato" <<endl;
        return -1;
    }
    cout << "Elemento trovato" <<endl;
    return current->dato;
}

int Bst::maxMin(){
    BstNode *current = root;

    while(current->right != nullptr){
        current = current->right;
    }
    int max = current->dato;

    current = root;

    while(current->left != nullptr){
        current = current->left;
    }
    int min = current->dato;

    cout << "Il massimo e' " << max << ", e il minimo e' " << min <<endl;
    return max,min;
}

void Bst::print(){
    print(root);
    cout << endl;
    
}

void Bst::print(BstNode *node){
    if(node != nullptr){
        cout << "this: " << node << ", val: " << node->dato << ", padre: " << node->padre << ", left: " << node->left << ", right: " << node->right << endl;
        print(node->left);
        print(node->right);
    }
}

void Bst::Delete(BstNode *node){
    if(node != nullptr){
        Delete(node->left);
        Delete(node->right);
        delete node;
    }
}

int main(){

    Bst albero;

    albero.insert(10);
    albero.insert(11);
    albero.insert(12);
    albero.insert(7);
    albero.print();

    cout << "Cerco elementi che esistono e non esistono" <<endl;
    cout << albero.search(12) <<endl;
    cout << albero.search(11) <<endl;
    cout << albero.search(10) <<endl;
    cout << albero.search(9) <<endl;

    cout << "Stampo massimo e minimo " <<endl;
    albero.maxMin();

    return 0;
}