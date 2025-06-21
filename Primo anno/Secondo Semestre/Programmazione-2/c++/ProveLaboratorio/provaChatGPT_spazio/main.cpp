#include <iostream>
#include <fstream>
using namespace std;

class Astronauta{
    public:
    Astronauta(int code, string name, string nation, float hour):id(code),nome(name),nazione(nation),oreVolo(hour){}

    int getId(){
        return id;
    }
    string getNome(){
        return nome;
    }
    string getNazione(){
        return nazione;
    }
    float getOre(){
        return oreVolo;
    }

    virtual void stampa(){
        cout << "CodiceID:" << id << ", Nome: " << nome << ", nazionalita': " << nazione << ", Ore di volo: " << oreVolo <<endl; 
    }

    protected:
    int id;
    string nome;
    string nazione;
    float oreVolo;
};
class Coda;
class AstronautaPremiato;
class Bonus{
    public:
    Bonus():valore(0),ente(""){}
    friend class AstronautaPremiato;
    friend class Coda;
    private:
    int valore;
    string ente;
};

class AstronautaPremiato : public Astronauta{       //nodo
    public:                                                                                                               //next
    AstronautaPremiato(int code, string name, string nation, float hour, bool flag, int val,string istitution, AstronautaPremiato *p):Astronauta(code,name,nation,hour),controllo(flag),next(p){
            premio = new Bonus();
            premio->valore = val;
            premio->ente = istitution;  


    }
    friend class Coda;

    int getValoreBonus(){
        return premio->valore;
    }

    void stampa(){
        if(controllo == true){
            cout << "CodiceID:" << id << ", Nome: " << nome << ", nazionalita': " << nazione << ", Ore di volo: " << oreVolo << ", Bonus: " << premio->valore << ", Ente: " << premio->ente <<endl;     
        }else{
            cout << "CodiceID:" << id << ", Nome: " << nome << ", nazionalita': " << nazione << ", Ore di volo: " << oreVolo <<endl;            
        }
    }

    
    ~AstronautaPremiato(){
        if(premio != nullptr){
            delete premio; 
        }
    }

    private:
    bool controllo;
    Bonus *premio;

    AstronautaPremiato *next;
};

class Coda{
    public:
    Coda():head(nullptr),lun(0){}
    void enQueue(int code, string name, string nation, float hour, bool flag, int val,string istitution);
    void print();
    void deQueue();
    void checkCoda();
    void TOTBonus();
    void printFile();

    ~Coda(){
        while(lun != 0){
            deQueue();
        }
    }

    private:
    int lun;
    AstronautaPremiato *head;
};

void Coda::printFile(){
    fstream file ("outputCODA.txt",ios::out);
    if(file.fail()){
        cout << "Errore nell'apertura del file 'outputCODA.txt'" <<endl;
        exit(-1);
    }
    AstronautaPremiato *current = head;
    while(current != nullptr){
        file << current->id;
        file << " ";
        file << current->nome;
        file << " ";
        file << current->nazione;
        file << " ";
        file << current->oreVolo;
        file << " ";
        file << current->premio->valore;
        file << " ";
        file << current->premio->ente;
        file << " ";
        file <<endl;

        current = current->next;
    }
}

void Coda::TOTBonus(){
    int somma = 0;
    AstronautaPremiato *current = head;
    while(current != nullptr){
        somma = somma + current->premio->valore;
        current = current->next;
    }
    cout << "IL totale dei premi Bonus e': " << somma <<endl;
}

void Coda::checkCoda(){
    AstronautaPremiato **array = new AstronautaPremiato*[lun];
    AstronautaPremiato *current = head;

    for(int i = 0; i < lun; i++){   //copio la coda nell array
        array[i] = new AstronautaPremiato(current->id,current->nome,current->nazione,current->oreVolo,current->controllo,
            current->premio->valore,current->premio->ente,nullptr);
            current = current->next;
    }

    int dim = lun;
    for(int i = 0; i < dim; i++){   //elimino la coda
        deQueue();
    }

    for(int i = 0; i < dim; i++){
        if(array[i]->oreVolo < 1000){
            delete array[i];
            array[i] = nullptr;
        }else{
            enQueue(array[i]->id,array[i]->nome,array[i]->nazione,array[i]->oreVolo,array[i]->controllo,
                array[i]->premio->valore,array[i]->premio->ente);
        }
    }

    for(int i = 0; i < dim; i++){
        delete array[i];
    }
    delete[] array;
    return;
}

void Coda::deQueue(){
    if(head == nullptr){
        return;
    }
    AstronautaPremiato *current = head->next;
    delete head;
    head = current;
    lun--;
    return;
}

void Coda::print(){
    AstronautaPremiato *current = head;
    while(current != nullptr){
        current->stampa();
        current = current->next;
    }
}

void Coda::enQueue(int code, string name, string nation, float hour, bool flag, int val,string istitution){
    if(head == nullptr){
        head = new AstronautaPremiato(code,name,nation,hour,flag,val,istitution,nullptr);
        lun++;
        return;
    }

    AstronautaPremiato *newNode = new AstronautaPremiato(code,name,nation,hour,flag,val,istitution,nullptr);
    AstronautaPremiato *current = head;

    while(current->next != nullptr){
        current = current->next;
    }
    current->next = newNode;
    lun++;
    return;
}


class BST;
class MissioneNode{
    public:
    MissioneNode():left(nullptr),right(nullptr),padre(nullptr),codiceMissione(0),nomeMissione(""),annoLancio(0){}
    friend class BST;
    private:
    int codiceMissione;
    string nomeMissione;
    int annoLancio;

    MissioneNode *left;
    MissioneNode *right;
    MissioneNode *padre;
};

class BST{
    public:
    BST():root(nullptr){}
    void insert(int id,string name,int year);
    void printRicorsiva(){
        print(root);
    }
    void print(MissioneNode *r){
        if(r != nullptr){
            print(r->left);
            cout << "ID-Missione: " << r->codiceMissione << ", Nome Missione: " << r->nomeMissione << ", Anno di lancio: " << r->annoLancio <<endl; 
            print(r->right);
        }
    }
    bool search(int code);
    void printFileBST();
    void fileRicorsivo(MissioneNode *r,fstream &file);

    private:
    MissioneNode *root;
};

void BST::fileRicorsivo(MissioneNode *r,fstream &file){
    if(r != nullptr){
       fileRicorsivo(r->left,file);
        file << r->codiceMissione;
        file << " ";
        file << r->nomeMissione;
        file << " ";
        file << r->annoLancio;
        file <<endl;
        fileRicorsivo(r->right,file);     
    }
}

void BST::printFileBST(){
    fstream file ("outputBST.txt",ios::out);
    if(file.fail()){
        cout << "Errore nell'apertura del file 'outputBST.txt'" <<endl;
        exit(-1);
    }
    MissioneNode *current = root;
    fileRicorsivo(root,file);
    return;
}

bool BST::search(int code){

    MissioneNode *current = root;

    while(current != nullptr && current->codiceMissione != code){
        if(current->codiceMissione > code){
            current = current->left;
        }else{
            current = current->right;
        }
    }

    if(current != nullptr){
        cout << "Elemento trovato" <<endl;
        cout << "ID-Missione: " << current->codiceMissione << ", Nome Missione: " << current->nomeMissione << ", Anno di lancio: " << current->annoLancio <<endl; 
    }else{
        cout << "Elemento non trovato" <<endl;
        return false;
    }
    return true;
}

void BST::insert(int id,string name,int year){
    MissioneNode *x = root;
    MissioneNode *y = nullptr;
    
    while(x != nullptr){
        y = x;

        if(id > x->codiceMissione){
            x = x->right;
        }else{
            x = x->left;
        }
    }

    MissioneNode *newNode = new MissioneNode();
    newNode->codiceMissione = id;
    newNode->nomeMissione = name;
    newNode->annoLancio = year;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->padre = y;

    if(y == nullptr){
        root = newNode;
    }else if(y->codiceMissione > newNode->codiceMissione){
        y->left = newNode;
    }else{
        y->right = newNode;
    }

}

int main(){

    Coda coda;
    coda.enQueue(1,"Neil","USA",2000.5,false,0,"");
    coda.enQueue(2,"Yuri","RUSSIA",1500.0,true,50000,"Roscosmos");
    coda.enQueue(3,"Samantha","ITA",1800.0,true,30000,"ESA");
    coda.enQueue(4,"Buzz","USA",900.0,false,0,"");
    coda.enQueue(5,"Valentina","RUSSIA",800.5,false,0,"");
    coda.enQueue(6,"Chris","CANADA",1700.0,false,0,"");
    coda.enQueue(7,"Pedro","SPAGNA",400.5,false,0,"");
    coda.enQueue(8,"Jessica","USA",2200.0,true,60000,"NASA");
    coda.print();

    cout << endl << "Elimino gli astronauti con meno di 1000 ore di volo" <<endl;
    coda.checkCoda();
    coda.print();
    coda.printFile();

    cout <<endl;
    coda.TOTBonus();

    cout << endl << "ALBERO MISSIONE" <<endl;

    BST albero;

    albero.insert(1000,"Mars Discovery",1999);
    albero.insert(1001,"Curiosity",2011);
    albero.insert(1002,"Perseverance",2020);
    albero.insert(1003,"Colony",2039);
    albero.insert(1004,"Mars Aeternum",2057);
    albero.printRicorsiva();
    cout <<endl;
    cout << "Cerco la missione 1003" <<endl;
    albero.search(1003);
    albero.printFileBST();
    return 0;
}
