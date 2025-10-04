#include <iostream>

using namespace std;

class BST;
class BstNode{
    public:
    BstNode():dato(0){}
    friend class BST;

    private:
    int dato;

    BstNode *left;
    BstNode *right;
    BstNode *padre;
};

class BST{
    public:
    BST():root(nullptr){}
    void insert(int d);
    void printRicorsiva();
    void printInorder(BstNode *r);
    void printPreorder(BstNode *r);
    void printPostorder(BstNode *r);
    bool search(int d);
    void minMax();

    private:
    BstNode *root;

};

void BST::minMax(){

    BstNode *current = root;

    while(current->left != nullptr){
        current = current->left;
    }
    cout <<endl;
    cout << "Il minimo e': " << current->dato;

    current = root;

    while(current->right != nullptr){
        current = current->right;
    }
    cout << endl;
    cout << "Il massimo e': " << current->dato;
    return;

}

bool BST::search(int d){
    BstNode *current = root;

    while(current != nullptr && current->dato != d){
        if(d < current->dato){
            current = current->left;
        }else{
            current = current->right;
        }
    }
    if(current != nullptr){
        cout << "Numero trovato" <<endl;
        return true;
    }else{
        cout << "Numero non trovato" <<endl;
        return false;        
    }
}

void BST::printRicorsiva(){
    cout << "Print in order: " <<endl;
    printInorder(root);

    cout << "Print pre order: " <<endl;
    printPreorder(root);

    cout << "Print post order: " <<endl;
    printPostorder(root);
}

void BST::printInorder(BstNode*r){ //in order
    if(r != nullptr){
        printInorder(r->left);
        cout << "NUMERO " << r->dato << endl;
        printInorder(r->right);
    }
    
}

void BST::printPreorder(BstNode*r){ //in order
    if(r != nullptr){
        cout << "NUMERO " << r->dato << endl;
        printPreorder(r->left);
        printPreorder(r->right);
    }
    
}

void BST::printPostorder(BstNode*r){ //in order
    if(r != nullptr){
        printPostorder(r->left);
        printPostorder(r->right);
        cout << "NUMERO " << r->dato << endl;
    }
    
}

void BST::insert(int d){
    BstNode *x = root;      //nodo corrente
    BstNode *y = nullptr;   //padre

    while(x != nullptr){
        y = x;

        if(d > x->dato){
            x = x->right;
        }else{
            x = x->left;
        }
    }

    BstNode *newNode = new BstNode;
    newNode->dato = d;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->padre = y;

    if(newNode->padre == nullptr){
        root = newNode;
    }else if(y->dato < newNode->dato){
        y->right = newNode;
    }else{
        y->left = newNode;
    }
    return;

}

int main(){

    BST albero;

    albero.insert(10);
    albero.insert(9);
    albero.insert(11);
    albero.insert(12);
    albero.insert(1);
    albero.insert(13);
    albero.insert(15);
    albero.insert(14);
    albero.printRicorsiva();

    albero.search(10);
    albero.search(9);

    albero.minMax();
    return 0;
}




