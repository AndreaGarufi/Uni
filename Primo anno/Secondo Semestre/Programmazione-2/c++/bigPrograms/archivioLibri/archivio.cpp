/*Esercitazione  
* Scrivi un programma in C++ che permetta di gestire un archivio di libri.  
Il programma deve permettere di:  
• Definire una struttura Libro con i seguenti campi:  
titalo (stringa)  
autore (stringa)  
annoPubblicazione (intero)  
prezzo (float)  
genere (array di caratteri di lunghezza massima 20)  
• Gestire un array di libri (massimo 100) e permettere di:  
‣ Aggiungere nuovi libri,  
• Visualizzare tuttf 1 libri presenti nell'archivio,  
• Cercare un lbro per titolo e restituire le sue informazioni, 
‣ Gestire input e output da file:  
‣ Salvare t'archivio in un file di testo (archivio.txt)  
‣ Caricare j dati dal file all'avvio del programma*/


// Scrivere un programma in C++ per gestire un archivio di libri

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Libro {
    string titolo;
    string autore;
    int annoPubblicazione;
    float prezzo;
    char genere[21];

    void stampa() {
        
        cout << "Titolo: " << titolo << endl;
        cout << "Autore: " << autore << endl;
        cout << "Anno di pubblicazione: " << annoPubblicazione << endl;
        cout << "Prezzo: " << prezzo << endl;
        cout << "Genere: " << genere << endl;
        
    }   
};

const int MAX_LIBRI = 20;
Libro archivio[MAX_LIBRI];
int num_libri = 0;

bool InserisciLibro(Libro* libro); 
void StampaLibri();
void CercaLibro();
void MemorizzaArchivio();
void CaricadaFile();

int main() {
    int scelta;
    do {
        cout <<endl;
        cout << "1. Inserisci un libro" << endl;
        cout << "2. Stampa tutti i libri dell'archivio" << endl;
        cout << "3. Cerca un libro per titolo" << endl;
        cout << "4. Memorizza l'archivio su file" << endl;
        cout << "5. Carica libri da file" << endl;
        cout << "0. Termina il programma" << endl;
        cout << "Scegli l'operazione: ";
        cin >> scelta;
        cout <<endl;
        cin.get(); 

        Libro libro;
        string titolo;
        switch (scelta)
        {
        case 1:
            cout << "Inserisci il titolo: ";
            getline(cin, libro.titolo);
            cout << "Inserisci l'autore: ";
            getline(cin, libro.autore);
            cout << "Inserisci l'anno di pubblicazione: ";
            cin >> libro.annoPubblicazione;
            cin.get();
            cout << "Inserisci il prezzo: ";
            cin >> libro.prezzo;
            cin.get();
            cout << "Inserisci il genere: ";
            cin.getline(libro.genere, 21);
            if (InserisciLibro(&libro)== false)
                cout << "Archivio pieno" << endl;
            break;
        case 2:
            StampaLibri();
            break;
        case 3:
            CercaLibro();
            break;
        case 4:
            cout << "Memorizzo l'archivio su file" << endl;
            MemorizzaArchivio();
            break;
        case 5:
            cout << "Carico i libri da file" << endl;
            CaricadaFile();
            break;    
        default:
            cout << "Scelta non valida" << endl;
        }


    } while(scelta != 0);

    cout << "A presto" << endl;
    return 0;
}

bool InserisciLibro(Libro* libro) {
    if (num_libri >= MAX_LIBRI) 
        return false;
    archivio[num_libri].titolo = libro->titolo;
    archivio[num_libri].autore = libro->autore;
    archivio[num_libri].annoPubblicazione = libro->annoPubblicazione;
    archivio[num_libri].prezzo = libro->prezzo;
    strcpy(archivio[num_libri].genere, libro->genere); 
    num_libri++;
    return true;
}
    
void StampaLibri() {
    for (int i = 0; i < num_libri; i++) {
        archivio[i].stampa();
    }
}

void CercaLibro() {
    string titoloChiave;
    cout << "che libro vuoi cercare? Insersci il titolo: ";
    cin >> titoloChiave;

    for(int i = 0; i < num_libri;i++){
        if(archivio[i].titolo == titoloChiave){
            cout << "LIBRO TROVATO" << endl;
            archivio[i].stampa();
        }else{
            cout << "LIBRO NON TROVATO" << endl;
            return;
        }
    }
}

void MemorizzaArchivio() {
    fstream file("archivio.txt", ios::out);
    if (file.fail()) {
        cout << "Errore nel file" << endl;
        return;
    }
    file << num_libri << endl;
    for (int i = 0; i < num_libri; i++) {
        file << archivio[i].titolo << endl;
        file << archivio[i].autore << endl;
        file << archivio[i].annoPubblicazione << endl;
        file << archivio[i].prezzo << endl;
        file << archivio[i].genere << endl;
    }
    file.close();
}

void CaricadaFile(){            
    string titolo;
    ifstream file("libri.txt");
    if (file.fail()) {
        cout << "Errore nel file" << endl;
        return;
    }else{
        cout << "File aperto correttamente" << endl;
    }
    file >> num_libri;
    file.get();
    for (int i = 0; i < num_libri; i++) { 
        getline (file,archivio[i].titolo);  
        getline (file,archivio[i].autore);
        file >> archivio[i].annoPubblicazione;
        file.get();
        file >> archivio[i].prezzo;
        file.get();
        file.getline (archivio[i].genere,21);
    }
    cout << "LIBRI CARICATI" <<endl;
    cout << archivio[0].titolo <<endl;

    file.close();

}
