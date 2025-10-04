//esercizio per familiarizzare con le classi

#include <iostream>
#include <fstream>
using namespace std;

class ContoBancario{
    public:

        ContoBancario(){
            saldo = 0;
        }

        void deposita(double n){
            cout << "Deposita nel Conto" <<endl;
            double saldoTemp = 0;
            saldo = n;

            fstream file("Conto.txt", ios::in);
            if (file.fail()) {
                cout << "Errore nel file" << endl;
                exit(-1);
            }
            file >> saldoTemp;
            file.close();

            file.open("Conto.txt", ios::out);
            if (file.fail()) {
                cout << "Errore nel file" << endl;
                exit(-1);
            }
            saldo = saldo + saldoTemp;
            file << saldo << endl;
            file.close();
            return;
        }

        void preleva(double n){
            cout << "Preleva dal Conto" <<endl;
            double saldoTemp = 0;

            fstream file("Conto.txt", ios::in);
            if (file.fail()) {
                cout << "Errore nel file" << endl;
                exit(-1);
            }
            file >> saldoTemp;
            file.close();

            if(saldoTemp == 0){
                cout << "Il deposito e' vuoto" << endl;
                return;
            }

            if(saldoTemp >= n){
                saldoTemp = saldoTemp-n;
                file.open("Conto.txt", ios::out);
                if (file.fail()) {
                    cout << "Errore nel file" << endl;
                    exit(-1);
                }
                file << saldoTemp;
                file.close();
                return;
            }else{
                cout << "Credito insufficiente" << endl;
                return;
            }
            
        }

        void mostraConto(){

            fstream file("Conto.txt", ios::in);
            if (file.fail()) {
                cout << "Errore nel file" << endl;
                exit(-1);
            }
            file >> saldo;
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