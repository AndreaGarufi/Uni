#include <iostream>
#include <cstring>

using namespace std;

class List;

class Node{
    public:     //next    
    Node(char a, Node *p):lettera(a),next(p){}
    friend class List;

    private:
    char lettera;
    Node *next;
};

class List{
    public:
    List():head(nullptr){}

    void aggiungi(char a);

    bool isPalindromo(string parola);

    void print();

    private:
    Node *head;
};

void List::aggiungi(char a){
    head = new Node(a,head);
    return;
}

bool List::isPalindromo(string parola){

    Node *current = head;
    int lun = 0;

    while(current != nullptr){
        lun++;
        current = current->next;
    }

    char arrayStringa[lun + 1] = {0};
    current = head;
    int j = 0;

    while(current != nullptr){

        for(int i = j; i < lun; i++){
            arrayStringa[i] = current->lettera;
            break;
        }
        j++;
        current = current->next;
    }
   
    if(strcmp(parola.c_str(), arrayStringa) == 0){
        cout << "La stringa e' palindroma" <<endl;
    }else{
        cout << "La stringa non e' palindroma" <<endl;
    }
    

    return true;
}

void List::print(){
    Node *current = head;

    while(current != nullptr){
        cout << current->lettera << " ";

        current = current->next;
    }
}

int main(){

    List lista;

    string parola;
    cout << "Inserisci una parola per controllare se e' palindroma " <<endl;
    getline(cin,parola);

    cout << "Inserisco la parola nella lista (un carattere per nodo)" <<endl;

    for(int i = 0; i < parola.length(); i++){
        lista.aggiungi(parola[i]);
    }
    lista.print();
    cout <<endl;
    lista.isPalindromo(parola);

    //continua esci dalla coda e confronta con la stringa iniziale
    return 0;
}