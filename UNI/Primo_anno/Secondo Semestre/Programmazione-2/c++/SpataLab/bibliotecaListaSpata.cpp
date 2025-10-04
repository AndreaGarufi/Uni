/*Gestione di una lista di libri in una Biblioteca
    Crea un programma in c++ utilizzando la programmazione orientata agli oggetti
    per gestire una lista collegata di libri in una biblioteca
    Requisiti:
    Definisci una classe Book con i seguenti attributi
    Titolo string
    Autore string
    Anno int
    Definisci una classe BookList che implementa una lista collegata semplice per gestire i libri
    Metodo addBook(const Book&) aggiunge un libro
    Metodo removeBook(const string title)
    Metodo displaybooks()
    Metodo findBook(); cerca un libro per titolo e ne stampa i dettagli*/


#include <iostream>

using namespace std;

class BookList;

class Book{
    public:
    Book(string title,string autor,int ann,Book *p): titolo(title),autore(autor),anno(ann),next(p){}

    friend class BookList;

    private:
    string titolo;
    string autore;
    int anno;

    Book *next;
};

class BookList{

    public:
    BookList():head(nullptr){}
    void insertHead(string title,string autor,int ann);
    void printList();
    bool removeBook(const string title);
    void findBook(const string title);

    private:
    Book *head;

};

void BookList::insertHead(string title,string autor,int ann){

    head = new Book(title,autor,ann,head);
}

void BookList::printList(){
    cout << "Dati Libri" << endl;

    Book *current = head;

    while(current != nullptr){
        cout << current->titolo << " " << current->autore << " " << current->anno <<endl;

        current = current->next;
    }
}

bool BookList::removeBook(const string title){
    cout << "Rimuovo il nodo" <<endl;

    Book *current = head;
    Book *ant = head;

    while(current != nullptr){

        if(current->titolo == title){
            ant->next = current->next;
            delete current;
            this->printList();
            return true;
        }

        ant = current;
        current = current->next;
    }
    cout << "Libro non trovato" <<endl;
    return false;
}

void BookList::findBook(const string title){
    cout << "Cerco " << title << "..." <<endl;

    Book *current = head;

    while(current != nullptr){
        if(current->titolo == title){
            cout << current->titolo << " " << current->autore << " " << current->anno <<endl;
            return;
        }
        current = current->next;
    }
    cout << "Libro non trovato" <<endl;
    return;

}

int main(){

    BookList lista;

    string title;
    string autor;
    int ann;

    cout << "Inserisci i dati di un libro: " << endl;
    cout << "Titolo" <<endl;
    getline(cin,title);
    cout << "Autore" <<endl;
    getline(cin,autor);
    cout << "Anno" <<endl;
    cin >> ann;
    lista.insertHead(title,autor,ann);

    cout << "Inserisco un altro libro: " <<endl;

    title = "Harry Potter";
    autor = "J.K. Rowling";
    ann = 1995;
    lista.insertHead(title,autor,ann);
    lista.printList();

    cin.ignore();
    cout << "Inserisci il titolo da cercare: " <<endl;
    getline(cin,title);
    lista.findBook(title);
    lista.printList();

    cout << endl;
    cout << "Inserisci il titolo da eliminare: " <<endl;
    getline(cin,title);
    lista.removeBook(title);

}