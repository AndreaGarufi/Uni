//esercizio per familiarizzare con le classi

#include <iostream>

using namespace std;

class ContoBancario{
    public:

        ContoBancario(){
            saldo = 0;
        }

        void deposita(double n){
            cout << "Deposita nel Conto" <<endl;

            saldo = n;
            return;
        }

        void preleva(double n){
            cout << "Preleva dal Conto" <<endl;
            if(saldo == 0){
                cout << "Il conto e' vuoto" << endl;
                return;
            }
            if(saldo >= n){
                saldo = saldo-n;
                return;
            }else{
                cout << "Credito insufficiente" << endl;
                return;
            }
            
        }

        void mostraConto(){
            cout << "Saldo = " << saldo;
            return;
        }

    private:

    double saldo;
};



int main(){

    double soldi = 0;
    ContoBancario dati;
    int operazione = 0;


    do{
        cout << "\nInserisci 1 per depositare, 2 per prelevare, 3 per mostrare il conto\n" << endl;
        cin >> operazione;
        cin.ignore();
        system("cls");
        switch(operazione){
            case 1:
                cout << "Quanto vuoi depositare?" << endl;
                cin >> soldi;
                dati.deposita(soldi);
                soldi = 0;
                break;

            case 2:
                cout << "Quanto vuoi prelevare?" << endl;
                cin >> soldi;
                dati.preleva(soldi);
                soldi = 0;
                break;  
                
            case 3:
                cout << "Mostra Conto" << endl;
                dati.mostraConto();
                break; 

                default:
                if(operazione == -1){
                    cout << "Uscita";
                    exit(-1);
                }else{
                    cout << "Inserisci un numero corretto" << endl;
                }
                
                    
                    break;
            }
    }while(operazione != -1);
    


}