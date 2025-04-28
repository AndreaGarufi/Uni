/*Implementa una classe chiamata bankAccount che rappresenti un semplice conto bancario.
    La classe deve permettere di:

    -Creare un conto cpn un nome del proprietario e un saldo iniziale
    - Depositare denaro
    - Prelevare denaro (solo se ci sono abbastanza fondi)
    - Visualizzare il saldo attuale
    - Stampare le informazioni del conto
    Specifiche della classe
    privati:
    string ownerName
    double balance
    pubblici:
    Costruttore per inizzializzare il conto con nome e saldo iniziale
    void deposit(double amount) Deposita denaro
    void withdraw(double amount) Preleva denaro
    dobule getBalance() Restituisce il saldo attuale
    void printAccountInfo() Stampare le informazioni del conto*/
#include <iostream>

using namespace std;

class BankAccount{
    public:
    BankAccount(string proprietario, double bilancio):ownerName(proprietario),balance(bilancio){}

    void deposit(double amount){//aggiunge denaro
        cout << "Deposito " << amount <<endl;
        balance = amount;
    } 

    void withdraw(double amount){   //preleva se possibile

        if(balance >= amount){
            balance = balance - amount;
            cout << "Prelevo " << amount <<endl;
        }else{
            cout << "Bilancio insufficiente" <<endl;
        }


    } 

    double getBalance(){    //restituisce il saldo iniziale
        cout << "Il bilancio e' :" << balance <<endl;
        return balance;
    } 

    void printAccountInfo(){
        cout << "Nome Account: " << ownerName <<endl;
    }
    private:
    string ownerName;
    double balance;

};


int main(){

    string nome;

    cout << "Inserisci il nome del proprietario" <<endl;
    cin >> nome;

    BankAccount dati(nome,0);
    
    dati.deposit(500);
    dati.getBalance();

    dati.withdraw(300);

    dati.printAccountInfo();

    dati.withdraw(1000);

}