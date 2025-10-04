#include <iostream>
using namespace std;


int main(){

    const float pigreco = 3.14;
    float raggio = 0;

    cout << "Inserisci il raggio" << endl;
    do{

        cin >> raggio;
        
    }while(raggio < 0);

    float area = 0;
    float volume = 0;

    area = pigreco * (raggio*raggio);
    cout << area << endl;

    volume = 4/3 * (pigreco * raggio * raggio * raggio);
    cout << volume << endl;

}