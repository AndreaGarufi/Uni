/*Obiettivo: Creare una rubrica che memorizzi oggetti generici (es. contatti, aziende, ecc.) usando template.

Struttura del programma:

Una classe Rubrica che:
Usa un array dinamico per memorizzare elementi
Permette di aggiungere, stampare e cercare un elemento
Contiene:
nome, telefono, email*/

#include <iostream>
#include <windows.h>

using namespace std;

class Rubrica{
    public:
        void stampa(){
            if(nome != ""){
                cout << "Nome contatto " << nome << endl;
                cout << "Telefono " << telefono << endl;
                cout << "Email " << email << endl;
                cout << endl;
            }else{
                return;
            }
            
        }

        bool cerca(string key){
            cout << "Cercando...\n" << endl;
            Sleep(500);
            if(nome == key){
                cout << "Elemento trovato" << endl;
                stampa();
                return true;
            }else{
                return false;
            }
        }

        bool controlla(){
            if(nome == ""){
                return true;
            }else{
                return false;
            }
        }

        void aggiungi(string n,string t, string e){
            int numero = 0;
            cout << "Vuoi salvare il numero? premi 0 per salvare o un altro numero per annullare " << endl;
            cin >> numero;
            cin.ignore();
            if(numero == 0){
                nome = n;
                telefono = t;
                email = e;
                cout << "Contatto salvato " << endl;
            }else{
                return;
            }
            
        }

        bool elimina(string key){
            if(nome == key){
                nome = "";
                telefono = "";
                email = "";
                return true;
            }
            return false;
        }

    private:
        string nome;
        string telefono;
        string email;
};  

int main(){

    int dimensione = 1;
    int operazione = 0;
    int controllo = 0;
    string nomeCognome,emailNome;
    string Ntelefono;
    string eliminato;
    
    Rubrica *array = new Rubrica[dimensione];

    cout << "RUBRICA TELEFONICA" << endl;
    
    do{
        cout << "Inserisci 1 per Stampare tutti i contatti, 2 per cercare un contatto, 3 per aggiungere un nuovo contatto o 4 per eliminarlo. Inserisci -1 per uscire" << endl;
        cin >> operazione;
        cin.ignore();
        system("cls");
        switch(operazione){
            case 1: cout << "Stampa la lista dei contatti" << endl;
                    for(int i = 0; i < dimensione; i++){
                        array[i].stampa();
                    }
                break;

            case 2: cout << "Cerca un contatto" << endl;
                    cout << "Inserisci il nome da cercare" << endl;
                    getline(cin,nomeCognome);
                    for(int i = 0; i < dimensione;i++){
                        if(array[i].cerca(nomeCognome) == true){
                            break;
                        }else{
                            if(i == dimensione-1){
                                cout << "Contatto non trovato" <<endl;
                            }
                        }
                    }
                break;

            case 3: cout << "Aggiungi un contatto" << endl;
                    cout << "Inserisci il nome del contatto... ";
                    nomeCognome = "";
                    getline(cin,nomeCognome);
                    cout << "Inserisci il telefono... ";
                    getline(cin,Ntelefono);
                    cout << "Inserisci l'email del contatto... ";
                    getline(cin,emailNome);

                    controllo = 0;
                    for(int i = 0; i < dimensione; i++){
                        if(array[i].controlla() == true){       //se il nome è vuoto inserisco i dati altrimenti non faccio nulla e continuo a ciclare
                            if(i == dimensione-1){
                                controllo = 1;
                            }
                            array[i].aggiungi(nomeCognome,Ntelefono,emailNome);
                            break;
                        }
                    }
                    if(controllo == 1){ //se finisco lo spazio nella rubrica crea un nuovo array copia il vecchio nel nuovo e il vecchio punta al nuovo
                        dimensione = dimensione*2;
                        if(dimensione > 100){
                            dimensione = 100;
                        }
                        Rubrica *arrayAppoggio = new Rubrica[dimensione];
                        for(int i = 0; i < dimensione/2; i++){
                            arrayAppoggio[i] = array[i]; 
                        }
                        delete[] array;
                        array = arrayAppoggio;

                    }
                break;

            case 4: cout << "Elimina contatto"<< endl;
                    cout << "inserisci il nome del contatto da eliminare" << endl;
                    getline(cin,eliminato);
                    for(int i = 0; i < dimensione; i++){
                        if(array[i].elimina(eliminato) == true){
                            cout << "Contatto eliminato" << endl;
                            break;
                        }
                    }
                    
                break;

            default : if(operazione != -1){
                cout << "Inserisci il numero corretto" << endl;
            }
        }

    }while(operazione != -1);

}