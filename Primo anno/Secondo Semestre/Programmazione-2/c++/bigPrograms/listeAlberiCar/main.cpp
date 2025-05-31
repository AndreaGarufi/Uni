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
    void printRicorsiva();
    void print(BstNode *r);
    BstNode* search(int speed);
    //implementa cancellazione (e dopo fai tutto sulle liste)
    private:
    BstNode *root;
};
//fine zona albero//

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

void Bst::printRicorsiva(){
    print(root);
    cout <<endl;
    return;
}

void Bst::print(BstNode *r){
    if(r != nullptr){
    print(r->left);
    cout << endl << "Marca: " << r->marca << ", Modello: " << r->modello << ", Velocita' massima: " << r->velocita << ", Prezzo (milioni): " << r->prezzo <<endl;
    print(r->right);
    }
    return;
}

void Bst::preleva(){

    fstream file("input.txt", ios::in);
    if(file.fail()){
        cout << "Errore nell'apertura del file" <<endl;
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

    Bst prova;
    prova.preleva();
    prova.printRicorsiva();
    cout << prova.search(400);
    cout <<endl;
    
    return 0;
}