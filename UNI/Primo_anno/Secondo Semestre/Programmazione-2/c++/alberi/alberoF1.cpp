/*🚗 Esercizio: Gestione Classifica Piloti F1 con un Albero Binario
Crea un programma in C++ che gestisca la classifica piloti di Formula 1 usando un albero binario di ricerca, 
dove ogni nodo rappresenta un pilota.

Ogni nodo deve contenere:
Nome del pilota (string)
Numero punti (int)

Funzionalità richieste:
Inserimento di un pilota (nome + punti): l’ordinamento nell’albero deve avvenire in base ai punti.
Stampa in ordine decrescente di punti (tramite una visita in-order rovesciata).
Ricerca di un pilota per nome.
Aggiornamento dei punti di un pilota.
(Opzionale) Cancellazione di un pilota.*/


#include <iostream>

using namespace std;

class BST;
class BstNode{
    public:
    BstNode(){}
    friend class BST;


    private:
    string nomePilota;
    int punti;

    BstNode *left;
    BstNode *right;
    BstNode *padre;

};

class BST{
    public:
    BST():root(nullptr){}
    void insert(string name, int d);
    void printRicorsiva();
    void print(BstNode *r);     //in order al contrario (ordine decrescente)
    bool searchRicorsiva(string name);
    bool search(BstNode *r,string name);
    void minMax();

    private:
    BstNode *root;
};

void BST::minMax(){
    BstNode *current = root;

    while(current->left != nullptr){
        current = current->left;
    }
    cout << "l'ultimo in classifica e': " << current->nomePilota <<endl;

    current = root;

    while(current->right != nullptr){
        current = current->right;
    }
    cout << "Il primo in classifica e': " << current->nomePilota <<endl;
    return;
}

bool BST::search(BstNode *r,string name){
    if(r != nullptr){
        if(r->nomePilota == name){
            return true;
        }else{
            if(r != nullptr){
            return search(r->left,name) || search(r->right,name);
            }
        }   
    }
    return false;
}

bool BST::searchRicorsiva(string name){
    if(search(root,name)){
        cout << "Pilota trovato" <<endl;
        return true;
    }else{
        cout << "Pilota non trovato" <<endl;
        return false;
    }

}

void BST::printRicorsiva(){
    print(root);
}

void BST::print(BstNode *r){
    if(r != nullptr){
        print(r->right);
        cout << "Nome: " << r->nomePilota << ", Punti: " << r->punti <<endl;
        print(r->left);
    }
}

void BST::insert(string name, int d){
    BstNode *x = root;
    BstNode *y = nullptr;

    while(x != nullptr){
        y = x;

        if(d > x->punti){
            x = x->right;
        }else{
            x = x->left;
        }
    }

    BstNode *newNode = new BstNode();
    newNode->nomePilota = name;
    newNode->punti = d;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->padre = y;

    if(y == nullptr){
        root = newNode;
    }else if(d > y->punti){
        y->right = newNode;
    }else{
        y->left = newNode;
    }
}

int main(){

    BST albero;
    
    albero.insert("Lewis Hamilton",39);
    albero.insert("Max Verstappen",69);
    albero.insert("Charles Leclerc",51);
    albero.insert("Lando Norris",101);
    albero.insert("Oscar Piastri",113);
    albero.insert("Carlos Sainz",28);
    albero.insert("Andrea Kimi Antonelli",55);
    albero.insert("Yuki Tsunoda",13);
    albero.printRicorsiva();

    albero.searchRicorsiva("Andrea Kimi Antonelli");
    albero.minMax();
    return 0;
}