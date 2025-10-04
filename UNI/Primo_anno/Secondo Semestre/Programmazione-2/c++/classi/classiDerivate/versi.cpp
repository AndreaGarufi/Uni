/*🔧 Esercizio: Animali e versi
Implementa una classe base Animale con una funzione virtuale verso(). 
Poi crea due classi derivate: Cane e Gatto, che ridefiniscono il metodo verso() per stampare il verso corrispondente.

🎯 Obiettivo:
Usare una funzione virtuale

Usare classi derivate

Creare un array di puntatori alla classe base per invocare i metodi polimorficamente*/


#include <iostream>

using namespace std;

class Animale{
    public:
    Animale(){}
    virtual void verso(){
        cout << "Verso Generico" <<endl;
    }
};

class Cane : public Animale{
    public:
    Cane(){}
    void verso() override {
        cout << "Bau" <<endl;
    }
};

class Gatto : public Animale{
    public:
    void verso() override {
        cout << "Miao" <<endl;
    }
};

int main(){
    Animale **array = new Animale*[2];

    array[0] = new Cane();
    array[0]->verso();

    array[1] = new Gatto();
    array[1]->verso();
}