#include <iostream>

using namespace std;
class Queue;
class Patient{          //sarà il nodo della coda
    public:                                         //next
    Patient(int code,string name,string condition,Patient *p):id(code),nome(name),condizioneMedica(condition),next(p){}
    Patient(){}
    friend class Queue;
    int getId(){
        return id;
    }
    void setId(int code){
        id = code;
        return;
    }

    string getNome(){
        return nome;
    }
    void setNome(string name){
        nome = name;
        return;
    }

    string getCondizioneMedica(){
        return condizioneMedica;
    }
    void setCondizioneMedica(string condition){
        condizioneMedica = condition;
        return;
    }

    void print(){
        cout << "Nome paziente: " << nome << ", id paziente: " << id << ", condizione medica: " << condizioneMedica <<endl;
    }

    private:
    int id;
    string nome;
    string condizioneMedica;

    Patient *next;
};

class Queue{
    public:
    Queue():head(nullptr){}

    void enQueue(int code,string name,string condition);    //inserisco in testa e levo in coda cosi facendo gestisco una coda
    void deQueue();
    void printCoda();
    bool isEmpty(){
        if(head == nullptr){
            cout << "La coda e' vuota" << endl;
            return true;
        }else{
            cout << "La coda non e' vuota" << endl;
            return false;
        }
    }

    private:
    Patient *head;
};

void Queue::enQueue(int code,string name,string condition){
    head = new Patient(code,name,condition,head);
    return;
}

void Queue::deQueue(){

    if(isEmpty() == true){
        cout << "ESCO" <<endl;
        return;
    }

    Patient *current = head;
    Patient *ant = nullptr;
    while(current->next != nullptr){
        ant = current;
        current = current->next;
    }
    current->print();

    if(ant != nullptr){
        ant->next = nullptr;
    }else{
        head = nullptr;
    }

    delete current;
    return;
}

void Queue::printCoda(){
    Patient *current = head;

    while(current != nullptr){
        current->print();
        current = current->next;
    }
    return;
}

int main(){

    Queue coda;

    coda.enQueue(143,"Alferdo","malato");
    coda.enQueue(555,"Niko Pandetta","scimunito");
    coda.enQueue(777,"Melo","pazzo");
    coda.printCoda();
    //coda.isEmpty();

    cout <<endl;
    cout << endl << "Rimuovo Alferdo, lo stampo e ristampo la coda" <<endl;
    coda.deQueue();
    cout <<endl;
    cout << "Coda" <<endl;
    coda.printCoda();
    cout <<endl;
    cout << "Rimuovo tutti i pazienti" <<endl;
    coda.deQueue();
    coda.deQueue();
    coda.deQueue();
    
    cout << endl << "Reinserisco..." <<endl;
    coda.enQueue(143,"Alferdo","malato");
    coda.enQueue(555,"Niko Pandetta","scimunito");
    coda.enQueue(777,"Melo","pazzo");
    cout << "Inserisco un paziente raccomandato e stampo" <<endl;
    return 0;
}