//versione del progreamma in modo da scegliere studente o studente borsista
#include <iostream>
#include <fstream>
using namespace std;

class Node;
class Stack;
class Studente{
    public:
    Studente(int number,string name,string surname,float m):matricola(number),nome(name),cognome(surname),media(m){}
    friend class Node;
    friend class Stack;
    int getMatricola(){
        return matricola;
    }
    string getNome(){
        return nome;
    }
    string getCognome(){
        return cognome;
    }
    float getMedia(){
        return media;
    }

    virtual void stampa(){
        cout << matricola << ": " << nome << ", " << cognome << ", " << media <<endl;
    }
    ~Studente(){}

    protected:
    int matricola;
    string nome;
    string cognome;
    float media;
};
class StudenteBorsista;
class BorsaDiStudio{
    public:
    BorsaDiStudio(int import,int duration):importo(import),durata(duration){}
    friend class StudenteBorsista;
    friend class Stack;
    private:
    int importo;
    int durata; //in mesi
};

class StudenteBorsista : public Studente{
    public:
    StudenteBorsista(int number,string name,string surname,float m,int import, int duration):Studente(number,name,surname,m){
        borsa = new BorsaDiStudio(import,duration);
    }
    friend class Node;
    friend class Stack;
    int getImportoBorsa(){
        return borsa->importo;
    }
    void stampa(){
        cout << matricola << ": " << nome << ", " << cognome << ", " << media << ", IMPORTO BORSA DI STUDIO: " << borsa->importo << ", Durata: " << borsa->durata <<endl;
    }
    ~StudenteBorsista(){
        delete borsa;
    }
    private:
    BorsaDiStudio *borsa;
};

class Node{
    public:                                                                                                                         //next
    Node(int number,string name,string surname,float m,int import, int duration, Node *p):next(p){
        if(import != 0){
            alunnoBorsista = new StudenteBorsista(number,name,surname,m,import,duration);
            alunno = nullptr;
        }else{
            alunno = new Studente(number,name,surname,m);
            alunnoBorsista = nullptr;
        }
    }
    friend class Stack;
    ~Node(){}

    private:
    StudenteBorsista *alunnoBorsista;
    Studente *alunno;
    Node *next;
};

class Stack{
    public:
    Stack():head(nullptr),lun(0){}
    void push(int number,string name,string surname,float m,int import, int duration);
    void print();
    void leggiFile();
    void check();
    void pop();
    void importo();
    private:
    int lun;
    Node *head;
};

void Stack::importo(){
    Node *current = head;
    int somma = 0;
    while(current != nullptr){
        if(current->alunno == nullptr){
            somma = somma + current->alunnoBorsista->borsa->importo;
        }
        current = current->next;
    }
    cout << endl << "La somma degli importi delle borse di studio e': " << somma <<endl;
}

void Stack::pop(){
    Node *current = head;
    head = head->next;
    delete current;
    lun--;
    return;
}

void Stack::check(){

    Studente **array = new Studente*[lun];
    int dim = lun;

    Node *current = head;
    for(int i = 0; i < dim; i++){       //copio la pila nell array
        if(current->alunno == nullptr){
            array[i] = new StudenteBorsista(current->alunnoBorsista->matricola,current->alunnoBorsista->nome,
                current->alunnoBorsista->cognome,current->alunnoBorsista->media,
                current->alunnoBorsista->borsa->importo,current->alunnoBorsista->borsa->durata);
        }else{
            array[i] = new Studente(current->alunno->matricola,current->alunno->nome,current->alunno->cognome,
                current->alunno->media);
        }
        current = current->next;
    }

    for(int i = 0; i < dim; i++){   //svuoto la pila
        pop();
    }

    for(int i = 0; i < dim; i++){
        if(array[i] != nullptr){
            if(array[i]->media < 25){
                cout << "Elimino un alunno con media inferiore a 25" <<endl;
                array[i]->stampa();
                delete array[i];
                array[i] = nullptr;   
            }            
        }
    }
    cout <<endl;
    for (int i = dim-1; i >= 0; i--) {
        if(array[i] != nullptr){
            StudenteBorsista* sb = dynamic_cast<StudenteBorsista*>(array[i]);   //fa un casting sicuro a tempo di esecuzione: controlla se l'oggetto puntato da array[i] è effettivamente un oggetto della classe derivata StudenteBorsista.🔍 In pratica:Se array[i] punta a un oggetto di tipo StudenteBorsista, allora sb sarà un puntatore valido e potrai usarlo. Se invece array[i] punta a un oggetto di tipo Studente normale, sb sarà nullptr.
            if(sb != nullptr){
                // È uno StudenteBorsista
                push(sb->matricola, sb->nome, sb->cognome, sb->media, sb->borsa->importo, sb->borsa->durata);
            }else{
                // È un normale Studente
                push(array[i]->matricola, array[i]->nome, array[i]->cognome, array[i]->media,0,0);
            }
        }
    }
}

void Stack::leggiFile(){
    ifstream file("input.txt");
    if(file.fail()){
        cout << "Errore nell'apertura del file 'input.txt'" <<endl;
        exit(-1);
    }

    int number = 0,import = 0,duration = 0;
    float m = 0;
    string name,surname;

   while(file >> number >> name >> surname >> m >> import >> duration){
        push(number,name,surname,m,import,duration);
   }
    
}

void Stack::print(){
    Node *current = head;

    while(current != nullptr){
        if(current->alunno != nullptr){
            current->alunno->stampa();
        }else{
            current->alunnoBorsista->stampa();
        }
        current = current->next;
    }
}

void Stack::push(int number,string name,string surname,float m,int import, int duration){
    head = new Node(number,name,surname,m,import,duration,head);
    lun++;
    return;
}

int main(){

    Stack pila;
    cout << "Studenti totali" <<endl;
    pila.leggiFile();
    pila.print();
    cout <<endl;
    pila.check();
    pila.print();
    pila.importo();

    return 0;
}