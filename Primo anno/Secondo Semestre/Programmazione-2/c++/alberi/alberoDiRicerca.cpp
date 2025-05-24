#include <iostream>

using namespace std;

class Bst;
class BstNode{
    public:
    BstNode(int a, BstNode *s = nullptr, BstNode *d = nullptr,BstNode *p):dato(a),left(s),right(d),padre(p){}
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
        //completa
    }
    void insert(int d);
    void print();

    private:
    void print(BstNode *node);
    BstNode *root;
};

void Bst::insert(int d){

    BstNode *x = root;
    BstNode *y = nullptr;

    while(x != nullptr){    //questo ciclo mi trova la posizione in cui aggiungere il nodo
        y = x;

        if(d < x->dato){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    //sistema (anche costruttore)
    BstNode *newNode = new BstNode(a,nullptr,nullptr,y);


}

void Bst::print(){
    print(root);
    cout << endl;
    
}

void Bst::print(BstNode *node){
    if(node != nullptr){
        //completa
    }
}

int main(){

    Bst albero;

    albero.insert(10);
    albero.insert(11);
    albero.insert(12);
    albero.print();

    return 0;
}