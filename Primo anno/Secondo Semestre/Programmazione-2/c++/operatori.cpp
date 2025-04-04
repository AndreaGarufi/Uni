#include <iostream>

using namespace std;

class ora_del_giorno{
    public:
        ora_del_giorno(int o = 0, int m = 0, int s = 0) :ora(o),minuti(m),secondi(s) {};

        ora_del_giorno(const ora_del_giorno& altro){
            (*this) = altro;
        }
        void stampa() const{
            cout << ora << ": " << minuti << ": " << secondi << endl; 
        }

        ora_del_giorno& operator=(const ora_del_giorno& altro){

            cout << "Effettuo la copia di: ";
            altro.stampa();
            ora = altro.ora;
            minuti = altro.minuti;
            secondi = altro.secondi;
            return *this;
        }

        /*ora_del_giorno& operator = (int altro){   sistema
            ora = 0;
            minuti = 0;
            secondi = altro;
            while(secondi >= 60){
                
            }
        }*/

    private:
        int ora;
        int minuti;
        int secondi;
};
//in alternativa posso usare l'operatore come funzione di due parametri
//ora_del_giorno& operator=(ora_del_giorno& ora1,const  ora_del_giorno ora2)


int main(){

    ora_del_giorno a(15,27,30);
    ora_del_giorno b;
    a.stampa();
    b.stampa();
    b = a;
    b.stampa();
    

    return 0;
}