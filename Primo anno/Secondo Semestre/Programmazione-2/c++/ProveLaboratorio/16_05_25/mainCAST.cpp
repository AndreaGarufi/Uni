//versione del progreamma con dynamic cast in modo da scegliere studente o studente borsista
#include <iostream>

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

    protected:
    int matricola;
    string nome;
    string cognome;
    float media;
};
class StudenteBorsista;
class BorsaDiStudio{
    public:
    BorsaDiStudio(int import,int duration):importo(0),durata(0){}
    friend class StudenteBorsista;
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
    private:
    BorsaDiStudio *borsa;
};

class Node{
    public:                                                                     //next
    Node(int number,string name,string surname,float m,int import, int duration,Node *p):next(p){
        alunno = new StudenteBorsista(number,name,surname,m,import,duration);
    }

    private:
    Studente *alunno;
    Node *next;
};

class Stack{
    public:
    Stack():head(nullptr){}
    
    private:
    Node *head;
};

int main(){


    return 0;
}