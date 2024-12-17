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
int aggiungi(prodotto array[100], int *dim, prodotto dati, char a[50],int *codicePtr, float *prezzoPtr, int *quantitaPtr);
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
        printf("\n\nSeleziona:\n1 per visualizzare l'inventario\n2 per aggiungere un prodotto\n3 per aggiornare la quantita' di un prodotto esistente\n4 per salvare l'inventario su un file\n-1 per uscire\n\n");
        scanf("%d",&operazione);
        switch(operazione){
            case 1: visualizza(arrayProdotto,prodotti,dati);
                break;
            case 2: prodotti = aggiungi(arrayProdotto,&prodotti,dati,dati.nome,&dati.codiceProdotto,&dati.prezzo,&dati.quantita);
                //printf("(MAIN)Codice: %d\n" ,dati.codiceProdotto);
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

    printf("\nVISUALIZZA\n");
    
    if(dim == 0){
        printf("Non ci sono prodotti\n");
    }else{
        for(int i = 0;i < dim; i++){
            printf("Nome Prodotto: %s\nCodice: %d\nPrezzo: %.2f\nQuantita': %d\n" ,dati.nome,dati.codiceProdotto,dati.prezzo,dati.quantita);
        }
    }
    return 0;
}

int aggiungi(prodotto array[100], int *dim, prodotto dati, char a[50],int *codicePtr, float *prezzoPtr, int *quantitaPtr){

    int counter = *dim;

    printf("\nAGGIUNGI\n");

    if(counter == 0){
        printf("Non ci sono prodotti:\nAggiungili:\n");

        printf("Inserisci il NOME PRODOTTO: --> ");
        scanf(" %[^\n]",a);
        for(int i = 0; i < 50; i++){
            dati.nome[i] = a[i];
        }

        printf("Inserisci il CODICE PRODOTTO --> ");
        scanf("%d",codicePtr);

        printf("Inserisci il PREZZO(EUR) --> ");
        scanf("%f",prezzoPtr);     

        printf("Inserisci la QUANTITA' --> ");
        scanf("%d",quantitaPtr);


        dati.codiceProdotto = *codicePtr;
        dati.prezzo = *prezzoPtr;
        dati.quantita = *quantitaPtr;
        
        //printf("Nome Prodotto: %s, codice: %d, prezzo %.2f, qunatita': %d" ,dati.nome,dati.codiceProdotto,dati.prezzo,dati.quantita);
        counter++;
    }else{
        for(int i = 0; i < counter; i++){           //per ora funziona solo l'inserimento di un prodotto, se ne devono inserire anche altri quindi sistema questo else

            printf("Inserisci il NOME PRODOTTO: --> ");
            scanf(" %[^\n]",a);
            for(int i = 0; i < 50; i++){
                dati.nome[i] = a[i];
            }

            printf("Inserisci il CODICE PRODOTTO --> ");
            scanf("%d",codicePtr);

            printf("Inserisci il PREZZO(EUR) --> ");
            scanf("%f",prezzoPtr);     

            printf("Inserisci la QUANTITA' --> ");
            scanf("%d",quantitaPtr);


            dati.codiceProdotto = *codicePtr;
            dati.prezzo = *prezzoPtr;
            dati.quantita = *quantitaPtr;
            
            counter++;
            break;
        }
    }

    return counter;
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
