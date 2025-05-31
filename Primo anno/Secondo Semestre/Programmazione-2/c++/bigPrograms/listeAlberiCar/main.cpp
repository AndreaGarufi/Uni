//dati nel file organizzati nel seguente modo: marca modello velocitaMassima prezzo(milioni)
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//zona albero//
class Bst;
class BstNode{
    public:
    BstNode():marca(""),modello(""),velocita(0),prezzo(0){}
    friend class Bst;

    private:
    string marca;
    string modello;
    int velocita;
    float prezzo;

    BstNode *padre;
    BstNode *left;
    BstNode *right;

};

class Bst{
    public:
    Bst():root(nullptr){}


    void preleva();
    void insert(string brand, string model, int speed, float price);    //richiamerò questa funzione dentro preleva cosi leggo una riga e creo il nodo
    void printRicorsiva(bool flag);
    void print(BstNode *r, ostream &out);
    BstNode* search(int speed);
    void cancellazione(BstNode *z);
    void trapianta(BstNode *u, BstNode *v);
    BstNode* minimo(BstNode *r);
    //void salvaFile();

    void min();
    void max();

    private:
    BstNode *root;
};
//fine zona albero//

/*void Bst::salvaFile(){
    fstream file("output.txt",ios::out);
    if(file.file()){
        cout << "Errore nell'apertura del file 'output.txt'" <<endl;
        exit(-1);
    }

    file << printRicorsiva();
    file.close();

}*/

void Bst::min(){

    BstNode *current = root;

    while(current->left != nullptr){
        current = current->left;
    }
    cout << "la macchina con la velocita' massima piu' bassa e': ";
    cout << endl << "Marca: " << current->marca << ", Modello: " << current->modello << ", Velocita' massima: " << current->velocita << ", Prezzo (milioni): " << current->prezzo <<endl;
    return;
    
}

void Bst::max(){

    BstNode *current = root;

    while(current->right != nullptr){
        current = current->right;
    }
    cout << "la macchina con la velocita' massima piu' alta e': ";
    cout << endl << "Marca: " << current->marca << ", Modello: " << current->modello << ", Velocita' massima: " << current->velocita << ", Prezzo (milioni): " << current->prezzo <<endl;
    return;

}

/////////////////////cancellazione////////////////////////
BstNode* Bst::minimo(BstNode *r){
    BstNode *current = r;

    while(current->left != nullptr){
        current = current->left;
    }
    return current;

}

void Bst::trapianta(BstNode *u, BstNode *v){
    if(u->padre == nullptr){
        root = v;
    }else if(u = u->padre->left){
        u->padre->left = v;
    }else{
        u->padre->right = v;
    }
    if(v != nullptr){
        v->padre = u->padre;
    }
}

void Bst::cancellazione(BstNode *z){

    BstNode *y = nullptr;
    if(z->left == nullptr){
        trapianta(z,z->right);
    }else if(z->right == nullptr){
        trapianta(z,z->left);
    }else{
        y = minimo(z->right);
        if(y->padre != z){
            trapianta(y,y->right);
            y->right = z->right;
            y->right->padre = y;
        }
        trapianta(z,y);
        y->left = z->left;
        y->left->padre = y;
    }

    return;
}
/////////////////////cancellazione////////////////////////

BstNode* Bst::search(int speed){
    BstNode *current = root;

    while(current != nullptr && current->velocita != speed){
        if(current->velocita > speed){
            current = current->left;
        }else{
            current = current->right;
        }
    }
    if(current == nullptr){
        cout << "Elemento non trovato" <<endl;
        return nullptr;
    }
    cout << "Elemento trovato" <<endl;
    return current;
}

void Bst::printRicorsiva(bool flag){

    if(flag == false){
        ofstream file("output.txt",ios::out);
        if(file.is_open()){
            print(root,file);
        }
    }else{
        print(root,cout);
    }

    
    cout <<endl;
    return;
}

void Bst::print(BstNode *r, ostream &out){
    if(r != nullptr){
    print(r->left,out);
    out << endl << "Marca: " << r->marca << ", Modello: " << r->modello << ", Velocita' massima: " << r->velocita << ", Prezzo (milioni): " << r->prezzo <<endl;
    print(r->right, out);
    }
    return;
}

void Bst::preleva(){

    fstream file("input.txt", ios::in);
    if(file.fail()){
        cout << "Errore nell'apertura del file 'input.txt'" <<endl;
        exit(-1);
    }

    string riga;
    while(getline(file,riga)){
        string brand,model;
        int speed = 0;
        float price = 0;

        istringstream iss(riga);
        iss >> brand >> model >> speed >> price;
        insert(brand,model,speed,price);
    }

}

void Bst::insert(string brand, string model, int speed, float price){   //ordino per velocita

    BstNode *x = root;
    BstNode *y = nullptr;    //tiene conto del padre

    //individuo la posizione in cui inserire il nodo
    while(x != nullptr){
        y = x;
        if(x->velocita < speed){
            x = x->right;
        }else{
            x = x->left;
        }
    }

    //creazione nodo
    BstNode *newNode = new BstNode;
    newNode->velocita = speed;
    newNode->marca = brand;
    newNode->modello = model;
    newNode->prezzo = price;

    newNode->right = nullptr;
    newNode->left = nullptr;
    newNode->padre = y;

    //gestione del padre
    if(y == nullptr){           //gestisco il padre del nodo appena creato
        root = newNode;         //se il padre è null newNode è la radice
    }else if(speed < y->velocita){      //qui decido se newNode deve essere figlio destro o sinistro
        y->left = newNode;
    }else{
        y->right = newNode;
    }
    
    return;

}

int main(){

    /////////////////inzio alberi////////////////////
    Bst prova;
    prova.preleva();
    prova.printRicorsiva(true);
    cout << prova.search(400);
    cout <<endl;
    prova.min();
    cout <<endl;
    prova.max();
    cout <<endl;

    cout << "Elimino (per poi reinserire) la Porche 911-GT3-RS:" << endl;
    prova.cancellazione(prova.search(330));
    prova.printRicorsiva(true);

    cout << endl << "Reinserisco..." <<endl;
    prova.insert("Porche","911-GT3-RS",330,0.5);
    prova.printRicorsiva(false);
    cout << endl << "Salvo nel file..." <<endl;
    ////////////////fine alberi//////////////////////


    
    
    return 0;
}