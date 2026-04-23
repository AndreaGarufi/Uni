#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Device;
class Application;
class Segment;
class Transport;

class nodo {
public:
    nodo(int d, nodo* p=nullptr) : data(d), next(p) {}
    
    friend class Coda;
    private:
    int data;
    nodo* next;
};


class Coda{
    private:
        nodo* head;
        nodo* tail;

    public:
        Coda(){
            head = tail = nullptr;
        }


        void stampa(){
            nodo* current = head;
            while(current != nullptr){
                cout << current->data << endl;
                current = current->next;
            }
        }

        void enqueue(int data){
            nodo* newnode = new nodo(data,nullptr);
            if(tail == nullptr){
                head = tail = newnode;
            } else {
                tail->next = newnode;
                tail = newnode;
            }
        }

        int dequeue(){
            if(head != nullptr){
                int data = head->data;
                nodo* tmp = head;
                head = head->next;
                if(head == nullptr){
                    tail = nullptr;
                }
                delete tmp;
                return data;
            } else{
                cout << "coda vuota" << endl;
                return -1;
            }
        }
};

class Segment{
    public:
    Segment(string segmento):segment(segmento){}
    friend class Transport;

    void stampaSegmento(){
        cout << segment;
    }

    private:
    string segment;
};

class Transport{
    public:
    Transport(){
        this->segmentSize = 5;
    }

    void segment(string parola);

    private:
    int segmentSize;
    vector<Segment> segmenti;

};

void Transport::segment(string parola){

    cout << parola << " FUNZIONE SEGMENTO" << endl;

    for(int i = 0;i < parola.length();i = i + segmentSize){
        cout <<"ENTRA" <<endl;
        string segmento = parola.substr(i, segmentSize); 
        segmenti.push_back(Segment(segmento));

    }
cout <<"ENTRA" <<endl;
    for(int i = 0; i < segmenti.size(); i++){
cout <<"ENTRA" <<endl;
        segmenti[i].stampaSegmento();
    }

}

class Application{

    public:
    Application(){}
    friend class Transport;


    void send(string parola);

    void receive();

    private:
    string message;
    Transport frammento;

};

void Application::send(string parola){
    cout << parola << " FUNZIONE SEND" <<endl;
    frammento.segment(parola);

}

void Application::receive(){

}

class Device{
    public:
    Device(){
        this->messaggio = '0';
    }
    friend class Application;

    void mandaMessaggio(string parola){
        
        ciao.send(parola);
    }
    private:
    string messaggio;
    Application ciao;
};




int main(){

    /*Coda coda;
    coda.enqueue(10);
    coda.stampa();*/



    Device A;
    string parola;
    cout << "Manda un messaggio... ";
    cin >> parola;
    A.mandaMessaggio(parola);

    return 0;
}