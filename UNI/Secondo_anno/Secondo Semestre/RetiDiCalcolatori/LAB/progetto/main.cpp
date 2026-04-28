#include <iostream>
#include <vector>
#include <string>
#include <optional>

using namespace std;

class Device;
class Application;
class Segment;
class Transport;
class InterNetwork;
class Packet;
class NetworkAccess;
class Frame;

class Segment{
    public:
    Segment(string segmento, int seq):segment(segmento),sequenza(seq){}
    friend class Transport;

    void stampaSegmento(){
        cout << "SEQ: " << sequenza << " Payload: " << segment <<endl;
    }

    private:
    string segment;
    int sequenza;
};

class Transport{
    public:
    Transport(){
        this->segmentSize = 5;
    }

    void segment(string parola);

    void inviaRETE();

    private:
    int segmentSize;
    vector<Segment> segmenti;

};

void Transport::segment(string parola){

    //cout << parola << " FUNZIONE SEGMENTO" << endl;
    int k = 0;
    for(int i = 0;i < parola.length();i = i + segmentSize){
        string segmento = parola.substr(i, segmentSize); 
        segmenti.push_back(Segment(segmento,k));
        k++;
    }
    /*for(int i = 0; i < segmenti.size(); i++){
        segmenti[i].stampaSegmento();
        cout <<endl;
    }*/

    inviaRETE();


}

class Packet{

    public:
    Packet(Segment frammento):payload(frammento){
        this->sourceIP = "192.168.2.5";
        this->destIP = "20.10.3.5";
    }
    friend class Segment;
    void stampaPacchetto();

    private:
    Segment payload;
    string sourceIP;
    string destIP;

};

void Packet::stampaPacchetto(){
    //cout << "FUNZIONE STAMPA PACCHETTO" <<endl;
    cout << "Source IP: " << sourceIP << " " << "Destination IP: " << destIP <<endl;
    payload.stampaSegmento();
    cout <<endl;
}

class InterNetwork{

    public:
    InterNetwork(){}
    friend class Transport;

    void riceviSegmento(Segment frammento);
    void inviaNetwork();
    void stampa();

    private:
    vector<Packet> pacchetto;

};

void InterNetwork::stampa(){

    for(int i = 0; i < pacchetto.size();i++){
        pacchetto[i].stampaPacchetto();
    }
}

void InterNetwork::riceviSegmento(Segment frammento){

    pacchetto.push_back(Packet(frammento));
    //cout << pacchetto.size();

}

void Transport::inviaRETE(){    //funziona
   //cout << "MANDIAMO I SEGMENTI";
    InterNetwork rete;

    //cout << segmenti.size();

    for(int i = 0; i < segmenti.size();i++){

        rete.riceviSegmento(segmenti[i]);
    }
    //rete.stampa();
    rete.inviaNetwork();
}

class Frame{

    public:
    Frame(Packet pacchetto):payload(pacchetto){
        this->MACsrc = "00:1A:2B:3C:4D:5E";
        this->MACdst = "AC:DE:48:00:11:22";
    }
    void stampaFrame();

    private:
    Packet payload;
    string MACsrc;
    string MACdst;
};

void Frame::stampaFrame(){
    //cout << "FUNZIONE STAMPA FRAME" <<endl;
    cout << "Source MAC: " << MACsrc << " " << "Destination MAC: " << MACdst <<endl;
    payload.stampaPacchetto();
    cout <<endl;
}

class NetworkAccess{

    public:
    NetworkAccess(){}
    friend class InterNetwork;
    friend class Packet;
    void riceviPacchetto(Packet pacchetto);
    void stampa();

    private:
    vector<Frame> frame;
};

void NetworkAccess::stampa(){

    for(int i = 0; i < frame.size();i++){
        frame[i].stampaFrame();
    }
}

void NetworkAccess::riceviPacchetto(Packet pacchetto){

    //cout << "RICEVUTO" <<endl;
    frame.push_back(Frame(pacchetto));
}


class Application{

    public:
    Application(){}
    friend class Transport;


    void send(string parola);

    optional<Frame> receive();

    private:
    string message;
    Transport frammento;

};

void Application::send(string parola){
    //cout << parola << " FUNZIONE SEND" <<endl;
    frammento.segment(parola);  //qui abbiamo diviso in segmenti
    
    //cout << "ABBIAMO FINITO"<<endl;

}

optional<Frame> Application::receive(){
    


    return nullopt;
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

    string riceviMessaggio();
    private:
    string messaggio;
    Application ciao;
};

string Device::riceviMessaggio(){

    ciao.receive();

    return "ciao";
}

class nodo {
public:
    nodo(Frame d, nodo* p=nullptr) : data(d), next(p) {}

    friend class Frame;
    friend class NetworkAccess;
    friend class Coda;
    private:
    Frame data;
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
        friend class Frame;
        friend class NetworkAccess;


        void stampa(){
            if(head == nullptr){
                exit(-1);
            }

            nodo* current = head; // Partiamo dal primo elemento
            while(current != nullptr){
                current->data.stampaFrame(); 
                current = current->next;
            }
        }

        void enqueue(Frame data){
            nodo* newnode = new nodo(data,nullptr);
            if(tail == nullptr){
                head = tail = newnode;
            } else {
                tail->next = newnode;
                tail = newnode;
            }
        }

        optional<Frame> dequeue(){
            if(head != nullptr){
                Frame data = head->data;
                nodo* tmp = head;
                head = head->next;
                if(head == nullptr){
                    tail = nullptr;
                }
                delete tmp;
                return data;
            } else{
                cout << "coda vuota" << endl;
                return nullopt;
            }
        }
};

void InterNetwork::inviaNetwork(){
    NetworkAccess internet;
    //cout << "entra ";
    //cout << pacchetto.size();
    for(int i = 0; i < pacchetto.size();i++){
        //cout << "entra"<<endl;
        internet.riceviPacchetto(pacchetto[i]);
    }
    //internet.stampa();
    Coda coda;

    for(int i = 0; i < internet.frame.size();i++){
        coda.enqueue(internet.frame[i]);

    }
    coda.stampa();
}


int main(){

    Device A;
    string parola;
    cout << "Manda un messaggio... ";
    getline(cin,parola);
    cout <<endl;
    A.mandaMessaggio(parola);

    Device B;
    B.riceviMessaggio();

    return 0;
}