//dati nel file organizzati nel seguente modo: marca modello velocitaMassima prezzo(milioni)
#include <iostream>
#include <fstream>

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

    private:
    BstNode *root;
};
//fine zona albero//

void Bst::preleva(){

    fstream file("input.txt", ios::in);
    if(file.fail()){
        cout << "Errore nell'apertura del file" <<endl;
        exit(-1);
    }

    string riga;
    while(getline(file,riga)){
        //continua
    }

}

void Bst::insert(string brand, string model, int speed, float price){

}

int main(){
    
    return 0;
}