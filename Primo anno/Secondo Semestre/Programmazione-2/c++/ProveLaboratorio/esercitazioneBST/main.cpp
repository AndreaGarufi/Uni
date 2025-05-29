//BST
#include <iostream>

using namespace std;

class Studente{ //sara il mio nodo (class BstNode)

    public:
    Studente(int numero,string name, string surname,float m): matricola(numero),nome(name),cognome(surname),media(m){}
    Studente():matricola(0),nome(""),cognome(""),media(0){}
    friend class Bst;

    int getMatricola(){
        return matricola;
    }
    string getNome(){
        return nome;
    }
    string getCognome(){
        return cognome;
    }
    float getMedia(){
        return media;
    }

    void stampa(){
        cout << matricola << ": " << nome << " " <<cognome<< " " << media <<endl;
    }

    private:
    int matricola;
    string nome;
    string cognome;
    float media;

    Studente *padre;     //zona albero
    Studente *left;
    Studente *right;
};

class Bst{
    public:
    Bst():root(nullptr){}
    

    private:
    Studente *root;
};



int main(){

    return 0;
}