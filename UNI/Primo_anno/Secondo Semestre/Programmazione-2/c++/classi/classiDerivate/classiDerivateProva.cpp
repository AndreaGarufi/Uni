//classe derivata

#include <iostream>

using namespace std;

class vehicle{
    public:
    vehicle():speed(0),status(false){}
    void setStatus(){
        status = true;
        cout << "In movimento" <<endl;
    }
    void setSpeed(float s){
        speed = s;
        cout << "Velocita' settata" <<endl;
    }

    void setFuel(int f){
        fuel = f;
        cout << "Rifornito" << endl;
    }

    protected:
    float speed;
    bool status;
    int fuel;
};

class derivateCar: public vehicle{
    public:
    derivateCar():vehicle(){}

};

int main(){

vehicle dati;

float s = 0;
bool t = false;
int f = 0;
cout << "Oggetto veicolo" <<endl;
cout << "Avvio veicolo" <<endl;

cout << "Inserisci la velocita'" <<endl;
cin >> s;

dati.setStatus();
dati.setSpeed(s);

derivateCar dato;
cout << "Oggetto car" <<endl;
cout << "Avvio car" <<endl;

cout << "Inserisci la velocita'" <<endl;
cin >> s;
cout << "Inserisci il carburante" <<endl;
cin >> f;

dato.setStatus();
dato.setSpeed(s);
dato.setFuel(f);

}