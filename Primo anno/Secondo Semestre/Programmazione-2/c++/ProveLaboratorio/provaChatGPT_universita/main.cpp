#include <iostream>
#include <fstream>
#include <sstream>
//gli studenti raccomandati non vengono eliminati anche se sono sotto 80 punti

using namespace std;

class Studente{
    public:
    Studente(int number,string name,string surname,float points):matricola(number),nome(name),cognome(surname),punteggio(points){}

    int getMatricola(){
        return matricola;
    }
    string getNome(){
        return nome;
    }
    string getCognome(){
        return cognome;
    }
    float getPunteggio(){
        return punteggio;
    }

    virtual void stampa(){
        cout << "Matricola:" << matricola << ", Nome: " << nome << ", Cognome: " << cognome << ", Punteggio: " << punteggio <<endl; 
    }

    protected:
    int matricola;
    string nome;
    string cognome;
    float punteggio;
};
template <typename T>
class Stack;

template <typename T>
class Node;

class StudenteRaccomandato : public Studente{      
    public:
    StudenteRaccomandato(int number,string name,string surname,float points,string teacher,bool flag):Studente(number,name,surname,points),professore(teacher),controllo(flag){}
    
    template <typename T>
    friend class Node;
    template <typename T>
    friend class Stack;
    void stampa(){
        if(controllo == true){
            cout << "Matricola:" << matricola << ", Nome: " << nome << ", Cognome: " << cognome << ", Punteggio: " << punteggio << ", Raccomandazione: "<< professore <<endl; 
        }else{
            cout << "Matricola:" << matricola << ", Nome: " << nome << ", Cognome: " << cognome << ", Punteggio: " << punteggio <<endl; 
        }
    }

    private:
    string professore;
    bool controllo;
};
template <typename T>
class Node{
    public:                                                                           //next
    Node(int number,string name,string surname,float points,string teacher,bool flag, Node<T> *p):next(p){
        alunno = new StudenteRaccomandato(number,name,surname,points,teacher,flag);
    }
    friend class Stack<T>;
    ~Node(){
        delete alunno;
    }
    private:    
    StudenteRaccomandato *alunno;
    Node<T> *next;
};

template <typename T>
class Stack{
    public:
    Stack():head(nullptr),lun(0){}
    void push(int number,string name,string surname,float points,string teacher,bool flag);
    void print();
    Node<T>* pop();
    bool isEmpty(){
        if(lun == 0){
            return true;
        }else{
            return false;
        }
    }
    void leggiFile();
    void rimuoviSottoSoglia(float points);


    private:
    int lun;
    Node<T> *head;
};

template <typename T>
void Stack<T>::rimuoviSottoSoglia(float points){

    Node<T> **array = new Node<T>*[lun];
    int dim = lun;
    Node<T> *current = head;
    for(int i = 0; i < dim; i++){
        array[i] = new Node<T>(current->alunno->matricola,current->alunno->nome,current->alunno->cognome,
        current->alunno->punteggio,current->alunno->professore,current->alunno->controllo,nullptr);
        current = current->next;
        
    }
    for(int i = 0; i < dim; i++){
        pop();
    }

    for(int i = 0; i < dim; i++){
        if(array[i]->alunno->punteggio < points && array[i]->alunno->controllo != true){
            cout << endl << "Elimino: " <<endl;
            array[i]->alunno->stampa();
            delete array[i];
            array[i] = nullptr;
        }
    }

    for(int i = dim-1; i >= 0; i--){
        if(array[i] != nullptr){
            push(array[i]->alunno->matricola,array[i]->alunno->nome,array[i]->alunno->cognome,
        array[i]->alunno->punteggio,array[i]->alunno->professore,array[i]->alunno->controllo);
        }
    }
    cout <<endl;
    print();
}

template <typename T>
void Stack<T>::leggiFile(){
    ifstream file("input.txt");
    if(file.fail()){
        cout << "errore nell'apertura del file 'input.txt'" <<endl;
        exit(-1);
    }
    
    int number = 0;
    string name, surname,teacher,raccomandazione;
    float points = 0;
    bool flag = false;

    while(file >> number >> name >> surname >> points){
        raccomandazione = "";
        teacher = "";
        flag = false;

        // Usare peek per vedere se c'è altro da leggere (spazio o fine riga)
        if(file.peek() != '\n' && file.peek() != EOF){
            if(file >> raccomandazione){
                if(raccomandazione == "raccomandato"){
                    if(!(file >> teacher)){
                        teacher = "";
                    }
                    flag = true;
                } else {
                    // Se la parola non è raccomandato, allora è insegnante
                    teacher = raccomandazione;
                    raccomandazione = "";
                }
            }
        }
        push(number, name, surname, points, teacher, flag);
    }

}

template <typename T>
Node<T>* Stack<T>::pop(){
    if(isEmpty() == true){
        cout << "La pila e' gia vuota" <<endl;
        return nullptr;
    }
    Node<T> *current = head->next;
    Node<T> *nodo = head;
    delete head;
    head = current;
    lun--;
    return nodo;
}

template <typename T>
void Stack<T>::print(){
    Node<T> *current = head;

    while(current != nullptr){
        current->alunno->stampa();
        current = current->next;
    }
}

template <typename T>
void Stack<T>::push(int number,string name,string surname,float points,string teacher,bool flag){
    head = new Node<T>(number,name,surname,points,teacher,flag,head);
    lun++;
    return;
}

int main(){
    Stack<StudenteRaccomandato> pila;
    pila.leggiFile();
    pila.print();
    // cout << endl << "Rimuovo un elemento dalla pila" <<endl;
    // pila.pop();
    // pila.print();

    pila.rimuoviSottoSoglia(80);
    return 0;
}