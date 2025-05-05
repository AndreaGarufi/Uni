/*Crea una classe base chiamata Veicolo con una funzione virtuale descrizione(). Crea due classi derivate: Auto e Bicicletta, 
ognuna con un proprio comportamento della funzione descrizione().
Requisiti:

Veicolo:
Ha un attributo marca (di tipo string).
Ha una funzione virtuale descrizione() che restituisce una stringa generica, tipo: "Veicolo di marca [marca]".

Auto:
Deriva da Veicolo.
Ha un attributo peso.
La funzione descrizione() deve restituire una stringa che descrive l'auto, come: "Auto di marca [marca] e peso di [peso]".

Bicicletta:
Deriva da Veicolo.
Ha un attributo peso.
La funzione descrizione() deve restituire una stringa che descrive la bicicletta, come: "Bicicletta di marca [marca] e peso di [peso]".

Nel main, crea un array dinamico di puntatori a Veicolo. Riempilo con oggetti Auto e Bicicletta. 
Poi, usa la funzione virtuale descrizione() per stampare la descrizione di ogni veicolo.*/

#include <iostream>

using namespace std;

class Veicolo{
    public:
    Veicolo(){}
    virtual string descrizione(){

        cout << "Veicolo di marca [marca] e peso di [peso]" <<endl;

        return marca;
    }

    virtual ~Veicolo(){}

    private:
    string marca;
};

class Auto : public Veicolo{
    public:
    Auto(string m,int p):marca(m),peso(p){}
    string descrizione() override{

        cout << "La marca dell' auto e' " << marca << ", mentre il peso e' di " << peso << " KG "<<endl;

        return marca;
    }

    private:
    string marca;
    int peso;

};

class Bicicletta : public Veicolo{
    public:
    Bicicletta(string m,int p):marca(m),peso(p){}
    string descrizione() override{

        cout << "La marca della bicicletta e' " << marca << ", mentre il peso e' di " << peso << " KG "<<endl;

        return marca;
    }

    private:
    string marca;
    int peso;

};


int main(){

    /*Veicolo A;
    Auto B(m,p);
    B.descrizione();

    m = "Cipollini";
    p = 5;
    Bicicletta C(m,p);
    C.descrizione();*/

    Veicolo **array = new Veicolo*[2];

    string m = "Ferrari";
    int p = 1000;
    array[0] = new Auto(m,p);
    array[0]->descrizione();

    m = "Cipollini";
    p = 5;
    array[1] = new Bicicletta(m,p);
    array[1]->descrizione();

    delete[] array;
}