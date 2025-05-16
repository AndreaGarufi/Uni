/*Definire una semplice classe Rettangolo. 
Successivamente definire: 
- Una lista di rettangoli con un metodo per aggiungere rettangoli 
e un metodo che prende in input due valori 
numerici, ed elimina dalla lista tutti i rettangoli con area 
compresa tra i due valori forniti dall’utente*/


#include <iostream>

using namespace std;

class List;
class Rettangolo{   

    public:                   //next
    Rettangolo(float a,Rettangolo *p):area(a),next(p){}
    friend class List;

    private:
    float area;
    Rettangolo *next;

};


class List{
    public:
    List():head(nullptr){}
    void inTesta(int l,int h);
    void print();
    bool rimuovi(float a,float b);

    private:
    Rettangolo *head;

};

void List::inTesta(int l,int h){
    float A = l*h;
    head = new Rettangolo(A,head);
    return;
}

void List::print(){
    Rettangolo *current = head;

    while(current != nullptr){
        cout << current->area <<endl;
        current = current->next;
    }
    return;

}

bool List::rimuovi(float a,float b){
    Rettangolo *current = head;
    Rettangolo *prev = nullptr;

    while (current != nullptr) {
        if (current->area >= a && current->area <= b) { //elimino
            // Nodo da rimuovere
            Rettangolo* toDelete = current;
            if (prev == nullptr) {
                // Primo nodo (caso di eliminare la testa)
                head = current->next;
            } else {
                prev->next = current->next;
            }
            current = current->next;
            delete toDelete;
        } else {
            // scorro avanti normalemente perche non devo eliminare niente
            prev = current;
            current = current->next;
        }
    }

    return true;
}

int main(){

    List lista;
    int l = 5;
    int h = 10;

    lista.inTesta(l,h);
    l++;
    h++;
    lista.inTesta(l,h);
    l++;
    h++;
    lista.inTesta(l,h);
    l++;
    h++;
    lista.inTesta(l,h);
    lista.print();

    cout <<endl;

    lista.rimuovi(66,84);
    lista.print();




    return 0;
}