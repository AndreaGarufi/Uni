#include <iostream>

using namespace std;

class Pilota{
    public:
    Pilota(int code,string name, string team,int points):id(code),nome(name),scuderia(team),punti(points){}

    int getID(){
        return id;
    }
    
    string getNome(){
        return nome;
    }

    string getScuderia(){
        return scuderia;
    }

    int getPunti(){
        return punti;
    }

    virtual void stampa(){
        cout << "codiceID: " << id << ", nome: " << nome << ", scuderia: " << scuderia << ", punti: " << punti <<endl;
    }

    protected:
    int id;
    string nome;
    string scuderia;
    int punti;

};
class Queue;
class PilotaPremiato;
class Premio{
    public:
    Premio():valore(0),sponsor(""){}
    friend class PilotaPremiato;
    friend class Queue;
    private:
    int valore;
    string sponsor;
};

class PilotaPremiato : public Pilota{       //nodo
    public:
    PilotaPremiato(int code,string name, string team,int points,bool flag,string spon, int val,PilotaPremiato *p):Pilota(code,name,team,points),next(p),controllo(flag){
        premio = new Premio();
        if(flag == true){
            premio->valore = val;
            premio->sponsor = spon;
        }
    }
    friend class Queue;
    int get_valore_premio(){
        return premio->valore;
    }

    void stampa(){
        if(premio->valore != 0){
            cout << "codiceID: " << id << ", nome: " << nome << ", scuderia: " << scuderia << ", punti: " << punti << ", premio: "<< premio->valore << ", Sponsor: " << premio->sponsor <<endl;
        }else{
        cout << "codiceID: " << id << ", nome: " << nome << ", scuderia: " << scuderia << ", punti: " << punti <<endl;   
        }
    }

    ~PilotaPremiato(){
        delete premio;
        delete next;
    }

    private:
    bool controllo;
    Premio *premio;
    PilotaPremiato *next;
};

class Queue{
    public:
    Queue():head(nullptr),lun(0){}
    void enQueue(int code,string name, string team,int points,bool flag,string spon, int val);
    void print();
    int totPremi();
    void rimuovi();

    ~Queue(){
        delete head;
    }

    private:
    int lun;
    PilotaPremiato *head;
};

void Queue::rimuovi(){
    PilotaPremiato *current = head;
    PilotaPremiato **array = new PilotaPremiato*[lun];

    int i = 0;
    while(current != nullptr){      //trasferisco nell array
        
        array[i] = new PilotaPremiato(current->id,current->nome,current->scuderia,
        current->punti,current->controllo,current->premio->sponsor,current->premio->valore,nullptr);
        current = current->next;
        i++;
    }

    for(int j = 0; j < i; j++){
        if(array[j]->punti < 100){
            delete array[j];
            array[j] = nullptr;
        }
    }
    delete head;    //cancello tutta la coda
    lun = 0;
    head = nullptr;
    
    for(int j = 0; j < i; j++){
        if(array[j] != nullptr){
            enQueue(array[j]->id,array[j]->nome,array[j]->scuderia,
        array[j]->punti,array[j]->controllo,array[j]->premio->sponsor,array[j]->premio->valore);
        }
    }

    for(int j = 0; j < i; j++){
        delete array[j];
    }
}

int Queue::totPremi(){
    PilotaPremiato *current = head;
    int somma = 0;
    while(current != nullptr){
        somma = somma + current->get_valore_premio();
        current = current->next;
    }
    return somma;
}

void Queue::print(){
    PilotaPremiato *current = head;

    while(current != nullptr){
        current->stampa();
        current = current->next;
    }
}

void Queue::enQueue(int code,string name, string team,int points,bool flag,string spon, int val){     //gestisco una coda, inserisco in fondo
    if(head == nullptr){
        if(flag == true)    //premio
        head = new PilotaPremiato(code,name,team,points,flag,spon,val,nullptr);
        lun++;
        return;
    }

    PilotaPremiato *current = head;

    while(current->next != nullptr){    //trovo il fondo per inserire il nuovo nodo
        current = current->next;
    }

    PilotaPremiato *newNode = new PilotaPremiato(code,name,team,points,flag,spon,val,nullptr);
    current->next = newNode;
    lun++;
    return;
}

int main(){
    Queue coda;
    coda.enQueue(44,"Lewis","Mercedes",180,true,"",0); 
    coda.enQueue(1,"Max","RedBull",220,true,"RedBull Energy",100000);
    coda.enQueue(16,"Charles","Ferrari",160,true,"",0);
    coda.enQueue(4,"Lando","Mclaren",175,true,"",0);
    coda.enQueue(64,"George","Mercedes",110,true,"Petronas",50000);    
    coda.enQueue(55,"Carlos","Williams",85,true,"Shell",40000);
    coda.print();
    cout <<endl;
    cout <<endl;
    coda.rimuovi();
    cout <<endl;
    coda.print();
    cout <<endl;
    cout <<endl;
    int TOTpremi = coda.totPremi();
    cout << "Il totale dei premi conseganti e': " << TOTpremi << endl;
    return 0;
}