//esercizio per familiarizzare con le classi

#include <iostream>

using namespace std;

class persona{
    public:

    persona(){
        nome = "Andrea Garufi";
        eta = 19;
    }
    void stampaDati(){

        cout << "Stampa dei dati" << endl;
        cout << nome << " " << eta << endl;
    }

    void cambiaEta(int n){

        cout << "Cambio dell'eta'" << endl;
        eta = n;
    }

    void cambiaNome(string n){

        cout << "Cambio del nome" << endl;
        nome = n;
    }

    private:
    string nome;
    int eta;

};


int main(){

persona dati;
int etaNuova = 0;
string nomeNuovo;

dati.stampaDati();

cout << "Inserisci la nuova eta'" << endl;
cin >> etaNuova;
cin.ignore();
dati.cambiaEta(etaNuova);
dati.stampaDati();

cout << "Inserisci il nuovo nome" << endl;
getline(cin, nomeNuovo);

dati.cambiaNome(nomeNuovo);
dati.stampaDati();
}