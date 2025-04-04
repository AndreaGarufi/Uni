#include <iostream>

using namespace std;

template <typename T>       //questa riga va messa all'inizio del file per dire al compilatore che T è un tipo generico e sostituirlo con quello chiamato

     void scambia(T &a, T &b){

        T temp;
        temp = b;
        b = a;
        a = temp;

        cout << " prima variabile " << a << " seconda variabile " << b <<endl;
    }



int main(){

    int x = 3,y = 5;
    float fX = 3.2,fY = 5.5;

    string sX = "MELOSO",sY = "MELOX";
    cout << "INT ->" << "X " << x << " Y " << y <<endl;
    cout << "scambio INT -> ";
    scambia(x,y);

    cout << endl;

    cout << "FLOAT ->" << "FX " << fX << " FY " << fY <<endl;
    cout << "scambio FLOAT -> ";
    scambia(fX,fY);

    cout << endl;

    cout << "STRING ->" << "SX " << sX << " SY " << sY <<endl;
    cout << "scambio FLOAT -> ";
    scambia(sX,sY);

    cout << x << " - " << y;


    return 0;
}