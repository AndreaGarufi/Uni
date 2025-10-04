/*🏎️ Esercizio: Lista di Pit Stop di una Gara di Formula 1
Crea un programma in C++ che gestisca una lista dei pit stop effettuati da un singolo pilota durante una gara.

📋 Ogni nodo della lista contiene:
Giro in cui è stato fatto il pit stop (int)
Tipo di gomma montata (string: "Soft", "Medium", "Hard")
Durata del pit stop in secondi (float)

🔧 Funzionalità richieste:
Inserisci un nuovo pit stop (in fondo alla lista).
Visualizza tutti i pit stop effettuati.
Calcola la media della durata dei pit stop.
Conta quante volte è stato montato un certo tipo di gomma (richiesto dall’utente).
Elimina l’ultimo pit stop (per esempio in caso di errore di inserimento).*/

#include <iostream>
#include <iomanip>
using namespace std;

class List;
class Node{
    public:
    Node(int lap,string wheel, float time, Node *p):giro(lap),gomma(wheel),tempo(time),next(p){}
    friend class List;

    private:
    int giro;
    string gomma;
    float tempo;

    Node *next;
};

class List{
    public:
    List():head(nullptr){}
    void insert(int lap, string wheel, float time);
    void print();
    void mediaTime();
    void rimuovi();

    ~List(){}

    private:
    Node *head;
};

void List::rimuovi(){
    Node *current = head;
    Node *ant = nullptr;

    while(current->next != nullptr){
        ant = current;
        current = current->next;
    }
    delete current;
    ant->next = nullptr;
    return;
}

void List::mediaTime(){
    float somma = 0;
    float media = 0;

    Node *current = head;
    int i = 0,j = 0,k = 0,h = 0;
    while(current != nullptr){
        somma = somma + current->tempo;

        if(current->gomma == "Hard"){
            j++;
        }else if(current->gomma == "Soft"){
            k++;
        }else{
            h++;
        }

        current = current->next;
        i++;
    }
    media = somma/i;
    cout << "La media dei time dei Pit Stop e': " << setprecision(3) << media << endl;

    cout << "la conta delle mescole e': HARD -> " << j << ", MEDIUM -> " << h << ", SOFT -> " << k << endl; 
    return;
}

void List::print(){
    Node *current = head;

    while(current != nullptr){
        cout << "Giro: " << current->giro << ", mescola " << current->gomma << ", tempo " << current->tempo <<endl;
        current = current->next;
    }
}

void List::insert(int lap, string wheel, float time){
    if(wheel != "Hard" && wheel != "Soft" && wheel != "Medium"){
        cout << "Mescola non valida" <<endl;
        return;
    }
    if(head == nullptr){
        head = new Node(lap,wheel,time,nullptr);
        return;
    }
    Node *current = head;

    while(current->next != nullptr){
        current = current->next;
    }
    Node *newNode = new Node(lap,wheel,time,nullptr);
    current->next = newNode;
    return;
}

int main(){
    List lista;

    cout << "Inserisco vari Pit Stop" <<endl;

    lista.insert(45,"Hard",2.2);
    lista.insert(41,"Soft",2.5);
    lista.insert(20,"Medium",3.0);
    lista.insert(18,"Medium",2.6);
    lista.insert(60,"Soft",2.1);
    lista.insert(31,"Hard",2.0);
    lista.insert(30,"Hard",2.0);
    lista.insert(53,"Soft",2.2);
    lista.insert(58,"Medium",2.3);
    lista.print();
    cout <<endl;
    lista.mediaTime();
    cout <<endl;
    cout << "Rimuovo l'ultimo Pit Stop" <<endl;
    lista.rimuovi();
    lista.print();
    cout <<endl;
    lista.mediaTime();

    return 0;
}