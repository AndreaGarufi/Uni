/*Classe base: Prodotto
Contiene:

int codice
double prezzo
string nome

Metodi richiesti:
Costruttore di default e con parametri
Getter
Metodo void leggi() per inserire i dati
funzione print() per stampare i dettagli

Sottoclassi:

ProdottoAlimentare
string dataScadenza (formato "gg/mm/aaaa")
Metodo bool èValido() che controlla se la data è ancora valida rispetto alla data attuale.

ProdottoTecnologico
int anniGaranzia
Metodo bool inGaranzia() che restituisce true se il prodotto è stato venduto meno di anniGaranzia fa.

Classe: Venditore
Contiene:
int codiceVenditore
array prodotti
Distruttore per la deallocazione dinamica
Metodi:
aggiungiProdotto(Prodotto*)
double calcolaTotale()
double calcolaValoreNonScaduto()
void stampa()

Classe: Magazzino
Contiene:
array venditori
Metodi:
aggiungiVenditore()
void stampaTutti()
void ordinaPerTotaleVendite()
double valoreTotaleMagazzino()

main():
Almeno 3 venditori con almeno 5 prodotti ciascuno (di tipo misto: alimentari e tecnologici)
Menu per:
Aggiungere venditore
Stampare info su venditori e prodotti
Stampare valore totale
Ordinare per valore vendite
Uscire
*/

#include <iostream>

using namespace std;

class Venditore;

class Prodotto{
    public:
    Prodotto(int code, double price, string name):codice(code),nome(name),prezzo(price){}
    friend class Venditore;

    Prodotto* leggi(int code, double price, string name){
        Prodotto *ptr = new Prodotto(code,price,name);
        cout << "Aggiunto" <<endl;
        return ptr;
    }

    virtual void print(){
        cout << "Codice: " << codice <<endl;
        cout << "Nome: " << nome <<endl;
        cout << "Prezzo: " << prezzo <<endl;
    }

    protected:
    int codice;
    string nome;
    double prezzo;
};

class ProdottoAlimentare : public Prodotto{
    public:
    ProdottoAlimentare(int code, double price, string name,int scad):Prodotto(code,price,name),dataScadenza(scad){}

    Prodotto* leggi(int code, double price, string name,int scad){
        Prodotto *ptr = new ProdottoAlimentare(code,price,name,scad);
        cout << "Aggiunto" <<endl;
        return ptr;
    }

    void print(){
        cout << "PRODOTTO ALIMENTARE" <<endl;        
        cout << "Codice: " << codice <<endl;
        cout << "Nome: " << nome <<endl;
        cout << "Prezzo: " << prezzo <<endl;
        cout << "Scadenza: " << dataScadenza <<endl;
        cout <<endl;
    }

    bool Valido(){

        if(dataScadenza < 2025){
            return true;
        }else{
            cout << "Scaduto" <<endl;
            return false;
        }
    }

    private:
    int dataScadenza;

};

class ProdottoTecnologico : public Prodotto{
    public:
    ProdottoTecnologico(int code, double price, string name,int garan):Prodotto(code,price,name),anniGaranzia(garan){}

    Prodotto* leggi(int code, double price, string name, int garan){
        Prodotto *ptr = new ProdottoTecnologico(code,price,name,garan);
        cout << "Aggiunto" <<endl;
        return ptr;
    }

    void print(){
        cout << "PRODOTTO TECNOLOGICO" <<endl;
        cout << "Codice: " << codice <<endl;
        cout << "Nome: " << nome <<endl;
        cout << "Prezzo: " << prezzo <<endl;
        cout << "Garanzia: " << anniGaranzia <<endl;
        cout <<endl;
    }

    bool inGaranzia(int data){
        int temp = 2025 - data;
        if(temp < anniGaranzia){
            return true;
        }else{
            cout << "Garanzia scaduta" <<endl;
            return false;
        }
    }

    private:
    int anniGaranzia;

};

class Venditore{
    public:
    Venditore():codiceVenditore(0),array(nullptr),lun(0){}
    ~Venditore(){}

    Prodotto** aggiungiProdotto(Prodotto *p){
        
        Prodotto **newArray = new Prodotto*[lun+1];

        for(int i = 0; i < lun; i++){   //copio i vecchi elementi
            newArray[i] = array[i];
        }

        newArray[lun] = p;

        delete[] array;
        array = newArray;
        lun++;
        return array;
    }

    void printVenditore(){
        for(int i = 0; i < lun; i++){
            array[i]->print();
        }
        cout <<endl;
    }

    double calcolaTotale(){
        double somma = 0;
        for(int i = 0; i < lun; i++){
            somma = somma + array[i]->prezzo;
        }
        return somma;
    }

    private:
    int codiceVenditore;
    int lun;
    Prodotto **array;
};

class Magazzino{
    public:
    Magazzino():array(nullptr),lun(0){}
    ~Magazzino(){}

    void aggiungiVenditore(Venditore *p){

        Venditore **newArray = new Venditore*[lun+1];

        for(int i = 0; i < lun; i++){   //copio i vecchi elementi
            newArray[i] = array[i];
            cout << "Venditore numero: " << i <<endl;
        }

        newArray[lun] = p;

        delete[] array;
        array = newArray;
        lun++;

    }
    void stampaTutti(){

        for(int i = 0; i < lun; i++){
            array[i]->printVenditore();
        }
        cout <<endl;
    }

    double valoreTotaleMagazzino(){

        return 0;

    }

    private:
    int lun;
    Venditore **array;
};


int main(){

    Venditore dati;

    //ProdottoAlimentare *ptr = new ProdottoAlimentare(123,45,"Pasta",2027);
    //dati.aggiungiProdotto(ptr);
    //ProdottoTecnologico *ptr1 = new ProdottoTecnologico(555,100,"PC",5);
    //dati.aggiungiProdotto(ptr1);
    //dati.printVenditore();

    ProdottoTecnologico a(0,0,"",0);
    //dati.aggiungiProdotto(a.leggi(777,1000,"Calcolatrice",10));

    ProdottoAlimentare b(0,0,"",0);
    //dati.aggiungiProdotto(b.leggi(1,1,"Pomodoro",2025));

    //dati.aggiungiProdotto(b.leggi(99,10,"Biscotti",2026));
    //dati.printVenditore();
    //cout << "Il totale degli elementi hanno il prezzo di: " << dati.calcolaTotale() <<endl;

    //questo è un solo venditore, creare un array di venditori e la classe magazzino

    Magazzino venditori;

    Venditore *ptr = new Venditore();
    ptr->aggiungiProdotto(a.leggi(777,1000,"Calcolatrice",10));
    venditori.aggiungiVenditore(ptr);

    ptr->aggiungiProdotto(b.leggi(111,10,"ricotta",2025));
    venditori.aggiungiVenditore(ptr);


    venditori.stampaTutti();


    return 0;
}
