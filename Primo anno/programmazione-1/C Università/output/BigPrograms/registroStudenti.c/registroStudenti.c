/*Scrivi un programma per gestire l'inventario di un negozio. Il programma deve:

Definire una struttura Prodotto con i seguenti campi:

Nome (stringa)
Codice prodotto (intero)
Prezzo (float)
Quantità disponibile (intero)
Offrire un menu per:

Aggiungere nuovi prodotti.
Visualizzare l'inventario.
Aggiornare la quantità di un prodotto esistente.
Salvare l'inventario su un file.
Caricare l'inventario da un file.
Utilizzare un file per memorizzare i dati.*/

#include <stdio.h>
#include <stdlib.h>



typedef struct{
    char nome[50];
    int codiceProdotto;
    float prezzo;
    int quantita;
}prodotto;

int visualizza(prodotto array[100], int dim, prodotto dati); //dim indica la quantita di prodotti presenti nell'array (ogni elemento dell'array contiene una struct prodotto [con tutti i suoi dati dentro])
int aggiungi(prodotto array[100], int *dim, prodotto dati);
int aggiorna(prodotto array[100], int dim, prodotto dati);
int salva();

int main(){

    int operazione = 0;
    prodotto dati;
    prodotto arrayProdotto[100];
    int prodotti = 0;
    int *prodottiPtr = NULL;

    printf("INVENTARIO\n");

    do{
        printf("\nSeleziona:\n1 per visualizzare l'inventario\n2 per aggiungere un prodotto\n3 per aggiornare la quantita' di un prodotto esistente\n4 per salvare l'inventario su un file\n-1 per uscire\n");
        scanf("%d",&operazione);
        switch(operazione){
            case 1: visualizza(arrayProdotto,prodotti,dati);
                break;
            case 2: aggiungi(arrayProdotto,&prodotti,dati);
                //printf("\n%d\n",prodotti);
                break;
            case 3: aggiorna(arrayProdotto,prodotti,dati);
                break;
            case 4: salva();
                break;
            default: if(operazione == -1){
                printf("EXIT");
                }else{
                    printf("Inserisci un numero valido\n");
                }
                break;
        }

    }while(operazione != -1);

}

int visualizza(prodotto array[100], int dim, prodotto dati){
    int codice = 0;

    printf("\nVISUALIZZA\n");
    
    if(dim == 0){
        printf("Non ci sono prodotti\n");
    }else{
        for(int i = 0;i < dim; i++){
            printf("Nome Prodotto: %s\nCodice: %d\nPrezzo: %.2f\nQuantita': %d\n" ,dati.nome[50],dati.codiceProdotto,dati.prezzo,dati.quantita);
        }
    }
    return 0;
}

int aggiungi(prodotto array[100], int *dim, prodotto dati){

    int counter = *dim;
    printf("%d counter",counter);
    printf("\nAGGIUNGI\n");

    if(counter == 0){
        printf("Non ci sono prodotti:\nAggiungili:\n");

        printf("Inserisci il NOME PRODOTTO: --> ");
        scanf(" %[^\n]",dati.nome);     //sistemare l'inseirimento che non viene preso e sistemare il passggio di "prodotti" aka dim per riferiemnto
        counter++;
    }else{
        for(int i = 0; i < counter; i++){
            printf("Inserisci il prodotto\n");

            break;
        }
    }
    dim = &counter;
    printf("\ncontatore %d",counter);
    return 0;
}

int aggiorna(prodotto array[100], int dim, prodotto dati){
    int codice = 0;
    printf("\nAGGIORNA\n");

    for(int i = 0; i < dim;i++){

    }

    return 0;
}

int salva(){
    
    printf("\nSALVA\n");

    return 0;
}
