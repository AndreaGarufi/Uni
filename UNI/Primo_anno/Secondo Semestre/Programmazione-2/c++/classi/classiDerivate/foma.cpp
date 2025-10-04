/*Crea una classe base Forma con una funzione virtuale area(). Poi crea due classi derivate: 
Rettangolo e Cerchio, che calcolano l’area nel modo corretto.

Requisiti:

Forma deve avere una funzione area() che ritorna 0.
Rettangolo ha larghezza e altezza.
Cerchio ha raggio.
Nel main, crea un array di puntatori a Forma e riempi con oggetti Rettangolo e Cerchio.
Stampa l’area di ogni figura usando la funzione virtuale.*/

#include <iostream>

using namespace std;

class Forma{
    public:
    Forma(){}
    virtual int area(){

        return 0;
    }

    virtual ~Forma(){};
};

class Rettangolo : public Forma{
    public:
    Rettangolo(int lato, int altezza):l(lato),h(altezza){}
    int area() override{

        cout << "Area rettangolo" <<endl;
        return l*h;
    }

    private:
    int l;
    int h;
    
};

class Cerchio : public Forma{
    public:
    Cerchio(int raggio):r(raggio),p(3.14){}

    int area() override{
        
        cout << "Area cerchio" <<endl;
        return (r*r)*p;
    }

    private:
    int r;
    const float p;
};

int main(){

    /*Forma *areaMain;

    areaMain = new Rettangolo(5,10);
    cout << areaMain->area() <<endl;*/

    Forma **areaMain = new Forma*[2];

    areaMain[0] = new Rettangolo(5,10);
    cout << areaMain[0]->area() <<endl;

    areaMain[1] = new Cerchio(10);
    cout << areaMain[1]->area() <<endl;

    delete areaMain[0];
    delete areaMain[1];
    delete[] areaMain;

    return 0;
}