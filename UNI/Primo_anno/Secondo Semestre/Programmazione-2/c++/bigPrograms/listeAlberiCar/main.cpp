//dati nel file input.txt organizzati nel seguente modo: marca modello velocitaMassima prezzo(milioni)
//dati nel file circuito.txt organizzati nel seguente modo: marca modello circuito pilota tempo (in float cioè secondi totali per compiere il giro)
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//zona albero//
class Bst;
class BstNode{
    public:
    BstNode():marca(""),modello(""),velocita(0),prezzo(0){}
    friend class Bst;

    private:
    string marca;
    string modello;
    int velocita;
    float prezzo;

    BstNode *padre;
    BstNode *left;
    BstNode *right;

};

class Bst{
    public:
    Bst():root(nullptr){}


    void preleva();
    void insert(string brand, string model, int speed, float price);    //richiamerò questa funzione dentro preleva cosi leggo una riga e creo il nodo
    void printRicorsiva(bool flag);
    void print(BstNode *r, ostream &out);
    BstNode* search(int speed);
    void cancellazione(BstNode *z);
    void trapianta(BstNode *u, BstNode *v);
    BstNode* minimo(BstNode *r);

    void min();
    void max();

    private:
    BstNode *root;
};
//fine zona albero//

void Bst::min(){

    BstNode *current = root;

    while(current->left != nullptr){
        current = current->left;
    }
    cout << "la macchina con la velocita' massima piu' bassa e': ";
    cout << endl << "Marca: " << current->marca << ", Modello: " << current->modello << ", Velocita' massima: " << current->velocita << ", Prezzo (milioni): " << current->prezzo <<endl;
    return;
    
}

void Bst::max(){

    BstNode *current = root;

    while(current->right != nullptr){
        current = current->right;
    }
    cout << "la macchina con la velocita' massima piu' alta e': ";
    cout << endl << "Marca: " << current->marca << ", Modello: " << current->modello << ", Velocita' massima: " << current->velocita << ", Prezzo (milioni): " << current->prezzo <<endl;
    return;

}

/////////////////////cancellazione////////////////////////
BstNode* Bst::minimo(BstNode *r){
    BstNode *current = r;

    while(current->left != nullptr){
        current = current->left;
    }
    return current;

}

void Bst::trapianta(BstNode *u, BstNode *v){
    if(u->padre == nullptr){
        root = v;
    }else if(u = u->padre->left){
        u->padre->left = v;
    }else{
        u->padre->right = v;
    }
    if(v != nullptr){
        v->padre = u->padre;
    }
}

void Bst::cancellazione(BstNode *z){

    BstNode *y = nullptr;
    if(z->left == nullptr){
        trapianta(z,z->right);
    }else if(z->right == nullptr){
        trapianta(z,z->left);
    }else{
        y = minimo(z->right);
        if(y->padre != z){
            trapianta(y,y->right);
            y->right = z->right;
            y->right->padre = y;
        }
        trapianta(z,y);
        y->left = z->left;
        y->left->padre = y;
    }

    return;
}
/////////////////////cancellazione////////////////////////

BstNode* Bst::search(int speed){
    BstNode *current = root;

    while(current != nullptr && current->velocita != speed){
        if(current->velocita > speed){
            current = current->left;
        }else{
            current = current->right;
        }
    }
    if(current == nullptr){
        cout << "Elemento non trovato" <<endl;
        return nullptr;
    }
    cout << "Elemento trovato" <<endl;
    return current;
}

void Bst::printRicorsiva(bool flag){

    if(flag == false){
        ofstream file("output.txt",ios::out);
        if(file.is_open()){
            print(root,file);
        }
    }else{
        print(root,cout);
    }

    
    cout <<endl;
    return;
}

void Bst::print(BstNode *r, ostream &out){
    if(r != nullptr){
    print(r->left,out);
    out << endl << "Marca: " << r->marca << ", Modello: " << r->modello << ", Velocita' massima: " << r->velocita << ", Prezzo (milioni): " << r->prezzo <<endl;
    print(r->right, out);
    }
    return;
}

void Bst::preleva(){

    fstream file("input.txt", ios::in);
    if(file.fail()){
        cout << "Errore nell'apertura del file 'input.txt'" <<endl;
        exit(-1);
    }

    string riga;
    while(getline(file,riga)){
        string brand,model;
        int speed = 0;
        float price = 0;

        istringstream iss(riga);
        iss >> brand >> model >> speed >> price;
        insert(brand,model,speed,price);
    }

}

void Bst::insert(string brand, string model, int speed, float price){   //ordino per velocita

    BstNode *x = root;
    BstNode *y = nullptr;    //tiene conto del padre

    //individuo la posizione in cui inserire il nodo
    while(x != nullptr){
        y = x;
        if(x->velocita < speed){
            x = x->right;
        }else{
            x = x->left;
        }
    }

    //creazione nodo
    BstNode *newNode = new BstNode;
    newNode->velocita = speed;
    newNode->marca = brand;
    newNode->modello = model;
    newNode->prezzo = price;

    newNode->right = nullptr;
    newNode->left = nullptr;
    newNode->padre = y;

    //gestione del padre
    if(y == nullptr){           //gestisco il padre del nodo appena creato
        root = newNode;         //se il padre è null newNode è la radice
    }else if(speed < y->velocita){      //qui decido se newNode deve essere figlio destro o sinistro
        y->left = newNode;
    }else{
        y->right = newNode;
    }
    
    return;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////

class List;
class Node{
    public:       //next
    Node(string brand,string model, string circuit, string pilot, float time,Node *p):marca(brand),modello(model),circuito(circuit),pilota(pilot),tempo(time),next(p){}
    friend class List;

    private:
    string marca;
    string modello;
    string circuito;
    string pilota;
    float tempo;

    Node *next;
};

class List{
    public:
    List():head(nullptr){}
    void print(bool flag);
    void insertOrder(string brand,string model, string circuit, string pilot, float time);
    void prelevaFile();
    Node *maxTempo();
    bool remove(Node *x);

    private:

    Node *head;

};

bool List::remove(Node *x){

    Node *current = head;
    Node *ant = head;

    if(current == nullptr){
        cout << "Lista vuota" <<endl;
        return false;
    }

    if(current == x){       //caso testa
        head = current->next;
        delete current;
        return true;
    }

    while(current != nullptr && current != x){  //trovo la posizione da eliminare
        ant = current;
        current = current->next;
    }

    if(current == nullptr){
        cout << "Nodo non trovato" <<endl;
        return false;
    }

    ant->next = current->next;
    delete current;
    return true;
}

Node* List::maxTempo(){
    Node *current = head;

    while(current->next != nullptr){
        current = current->next;
    }
    return current;
}

void List::prelevaFile(){
    fstream file("circuito.txt", ios::in);
    if(file.fail()){
        cout << "Errore nell'apertura del file 'circuito.txt'" <<endl;
        exit(-1);
    }

    string riga;
    while(getline(file,riga)){
        string brand,model,circuit,pilot;
        float time = 0;

        istringstream iss(riga);
        
        iss >> brand >> model >> circuit >> pilot >> time;
        insertOrder(brand,model,circuit,pilot,time);
    }
    return;
}

void List::insertOrder(string brand,string model, string circuit, string pilot, float time){
    
    Node *current = head;
    Node *ant = head;
    Node *newNode = nullptr;

    if(head == nullptr){
        head = new Node(brand,model,circuit,pilot,time,head);
        return;
    }

    if(head->tempo > time){
        newNode = new Node(brand,model,circuit,pilot,time,head);
        head = newNode;
        return;
    }

    while(current != nullptr && current->tempo < time){
        ant = current;
        current = current->next;
    }

    newNode = new Node(brand,model,circuit,pilot,time,current);
    ant->next = newNode;
    return;
}

void List::print(bool flag){
    Node *current = head;

    if(flag == false){
        while(current != nullptr){  //formatta bene il tempo
            int minuti = current->tempo / 60;
            int secondi = (int)current->tempo % 60;
            int millisecondi = (current->tempo - (int)current->tempo) * 1000;
            cout << endl << "Marca: " << current->marca << ", Modello: " << current->modello << ", Circuito: " << current->circuito 
            << ", pilota: " << current->pilota << ", Tempo: " << minuti << "." << secondi << "." << millisecondi <<endl;

            current = current->next;
        }
    }else{
        fstream file("salvaTempi.txt",ios::out);
        if(file.fail()){
            cout << "Errore nell'apertura del file 'salvaTempi.txt'" <<endl;
            exit(-1);
        }
        ostream& out = file;
        while(current != nullptr){  //formatta bene il tempo
            int minuti = current->tempo / 60;
            int secondi = (int)current->tempo % 60;
            int millisecondi = (current->tempo - (int)current->tempo) * 1000;
            out << endl << "Marca: " << current->marca << ", Modello: " << current->modello << ", Circuito: " << current->circuito 
            << ", pilota: " << current->pilota << ", Tempo: " << minuti << "." << secondi << "." << millisecondi <<endl;            current = current->next;
        }
    }


    return;
}

int main(){

    /////////////////inzio alberi////////////////////
    Bst prova;
    prova.preleva();
    prova.printRicorsiva(true);
    cout << prova.search(400);
    cout <<endl;
    prova.min();
    cout <<endl;
    prova.max();
    cout <<endl;

    cout << "Elimino (per poi reinserire) la Porche 911-GT3-RS:" << endl;
    prova.cancellazione(prova.search(330));
    prova.printRicorsiva(true);

    cout << endl << "Reinserisco..." <<endl;
    prova.insert("Porche","911-GT3-RS",330,0.5);
    prova.printRicorsiva(false);
    cout << endl << "Salvo nel file..." <<endl;
    ////////////////fine alberi//////////////////////

    /////////////////inzio liste////////////////////
    List lista;
    cout <<endl;
    cout << "Stampo i tempi delle macchine sui vari circuiti" <<endl;
    lista.prelevaFile();
    lista.print(false);

    cout << "Elimino il giro piu' lento " <<endl;
    cout << lista.remove(lista.maxTempo());

    cout << endl;
    cout << "Salvo nel file..." <<endl;
    lista.print(true);
    ////////////////fine liste//////////////////////

    return 0;
}