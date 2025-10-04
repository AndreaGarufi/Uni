/*
    Crea la classe listaInteri, una lista di numeri che devono essere inseriti dall'utente nel main
    Questa classe deve avere i seguenti metodi:
    - InsertHead
    - StampaLista
    - OrdinaDispari   lasciando i pari nelle posizioni originali
    - OrdinaPari    lasciando i dispari nelle posizioni originali
*/

#include <iostream>

using namespace std;

class List;

class Node{
    public:     //next
    Node(int d,Node *p):dato(d),next(p){}
    friend class List;

    private:
    int dato;
    Node *next;
};

class List{
    public:
    List():head(nullptr){}

    void insertHead(int d){
        head = new Node(d,head);
    }

    void print(){
        Node *current = head;
        while(current != nullptr){
            cout << current->dato << " ";
            current = current->next;
        }
    }

    void ordinaPari();
    void ordinaDispari();

    private:
    Node *head;
};

void List::ordinaPari(){

    Node *current = head;

    int lun = 0;

    while(current != nullptr){
        lun++;
        current = current->next;
    }

    int array[lun] = {0};
    current = head;
    int i = 0;
    while(current != nullptr){

        array[i] = current->dato;
        i++;
        current = current->next;
    }
    //selection sort solo sui numeri pari

    for(int i = 0; i < lun - 1; i++){
        if(array[i] % 2 != 0) continue;

        for(int i = 0; i < lun; i++){
            int minimo = i;
            for(int j = i + 1; j < lun; j++){
                if(array[i] % 2 == 0 && array[minimo] > array[j]){
                        minimo = j;
                    
                }
            }
            int temp = array[i];
            array[i] = array[minimo];
            array[minimo] = temp;
        }
    }

    for(int i = 0; i < lun; i++){
            cout << array[i] << " ";
        }
}

void List::ordinaDispari(){

}

int main(){
    List lista;

    int numero = 0;
    cout << "Inserisci 5 numeri" <<endl;
    for(int i = 0; i < 5; i++){
        cin >> numero;
        lista.insertHead(numero);
    }
    lista.print();
    cout << "Ordinamento tramite Selection Sort solo sui numeri pari" <<endl;
    lista.ordinaPari();

    return 0;
}