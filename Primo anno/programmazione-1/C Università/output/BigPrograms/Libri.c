/*Consegna dell'esercizio:
Scrivi un programma in C che gestisca un piccolo database di libri utilizzando una struttura. Ogni libro deve contenere le seguenti informazioni:

Titolo del libro (stringa).
Nome dell'autore (stringa).
Anno di pubblicazione (intero).
Prezzo del libro (valore in virgola mobile).
Il programma deve:

Consentire all'utente di inserire i dati di un massimo di 100 libri.
Stampare l'elenco dei libri in ordine alfabetico in base al titolo.
Permettere di cercare un libro per titolo e visualizzarne i dettagli.
Calcolare il costo totale dei libri inseriti.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void dati(char *a[], char *autore[], int anno[], float prezzo[]);
void stampaAlfabetico(char *libro[], char *autore[], int anno[], float prezzo[]);
void cercaLibro(char *libro[], char *autore[], int anno[], float prezzo[], char key[], int dim);

typedef struct {
    char *nome[100];

    char *autore[100];

    int anno[100];

    float prezzo[100];
}libriStr;

int quantita = 0;

int main(){

    libriStr datiLibro;
    char chiave[50];

    int operazione = 0;
    
    do{
        printf("\nInserisci 1 per aggiungere un libro, 2 per stampare l'elenco dei libri in ordine alfabetico, 3 per cercare un libro, -1 per uscire -> ");
        scanf("%d",&operazione);
        switch(operazione){

            case 1: dati(datiLibro.nome,datiLibro.autore,datiLibro.anno,datiLibro.prezzo);
                    operazione = 0;
                    break;
            case 2: stampaAlfabetico(datiLibro.nome,datiLibro.autore,datiLibro.anno,datiLibro.prezzo);
                    operazione = 0;
                    break;
            case 3: printf("Inserisci il libro da cercare -> ");
                    scanf(" %[^\n]",chiave);
                    chiave[0] = toupper(chiave[0]);
                    cercaLibro(datiLibro.nome,datiLibro.autore,datiLibro.anno,datiLibro.prezzo,chiave,50);
                    operazione = 0;
                    break;
            default: printf("inserisci un numero valido\n");
                    
                    break;
        }        
    }while(operazione != -1);

            
    /*printf("\nPROVA\n");
    for(int i = 0; i < quantita;i++){       //stampa delle stringhe + con gli altri dati
        printf("\nNome Libro: %s \nNome Autore: %s \nAnno Pubblicazione: %d \nPrezzo: %.2f" ,datiLibro.nome[i],datiLibro.autore[i],datiLibro.anno[i],datiLibro.prezzo[i]);
        puts("");
    } */       
    
   
    printf("\n\nfine");
}
void dati(char *libro[], char *autore[], int anno[], float prezzo[]){   //qui passa per riferimento

    printf("\nDATI LIBRI\n");

    int nuoviLibri = 0;

    printf("Quanti libri vuoi inserire? -> ");
    scanf("%d",&nuoviLibri);

    if (quantita + nuoviLibri > 100) {
        printf("Errore: Non c'è spazio sufficiente per inserire tutti i libri. Puoi aggiungere massimo %d libri.\n", 100 - quantita);
        return;
    }    

    char tempLibro[50] = {0};
    char tempAutore[50] = {0};
    
    
    for(int i = 0; i < nuoviLibri; i++){
        printf("Inserisci i dati del libro numero %d :\nNome Libro -> ",i+1);
        scanf(" %[^\n]",tempLibro); //nome libro

        printf("\nNome Autore -> ");
        scanf(" %[^\n]",tempAutore); // nome autore

        printf("\nAnno Pubblicazione -> ");    
        scanf("%d",&anno[quantita]); // Anno Pubblicazione

        printf("\nPrezzo -> ");    
        scanf("%f",&prezzo[quantita]); // Prezzo

        puts("");
            

        libro[quantita] = malloc(strlen(tempLibro) + 1);
        autore[quantita] = malloc(strlen(tempAutore) + 1);
        if(libro[quantita] == NULL || autore[quantita] == NULL){
            printf("Abbiamo superato i Ghilowatt");
        }else{
            strcpy(libro[quantita],tempLibro);
            strcpy(autore[quantita],tempAutore);
        }
        
        libro[quantita][0] = toupper(libro[quantita][0]); //scrive la prima lettera maiuscola
        autore[quantita][0] = toupper(autore[quantita][0]);
        quantita++;

    }

    for(int i = 0; i < quantita;i++){       //stampa delle stringhe + con gli altri dati
        
        printf("\nNome Libro: %s \nNome Autore: %s \nAnno Pubblicazione: %d \nPrezzo: %.2f" ,libro[i],autore[i],anno[i],prezzo[i]);
        puts("");
    }
    

}

void stampaAlfabetico(char *libro[], char *autore[], int anno[], float prezzo[]){


    printf("\nSTAMPA IN ORDINE ALFABETICO\n");//orario 16:16

    //bubble sort 

    for(int i = 0; i < quantita; i++){

        for(int j = 0;j < quantita - 1; j++){

            if((int)libro[j][0] > (int)libro[j + 1][0]){

                char *temp = libro[j];              
                libro[j] = libro[j + 1];        //scambio stringhe libri
                libro[j + 1] = temp;

                char *tempAutore = autore[j];
                autore[j] = autore[j + 1];          //scambio stringhe autori
                autore[j + 1] = tempAutore;

                int tempAnno = anno[j];
                anno[j] = anno[j + 1];
                anno[j + 1] = tempAnno;

                float tempPrezzo = prezzo[j];
                prezzo[j] = prezzo[j + 1];
                prezzo[j + 1] = tempPrezzo;                

            }
        }

    }
    for(int i = 0;i < quantita; i++){
        printf("\nNome Libro %s \nNome Autore %s \nAnno Pubblicazione %d \nPrezzo(EUR) %.2f \n",libro[i],autore[i],anno[i],prezzo[i]);
    }
}

void cercaLibro(char *libro[], char *autore[], int anno[], float prezzo[], char key[], int dim){
    printf("\nCERCA LIBRO\n");

    printf("chiave : %s ",key);
    int g = 0;
    for(int i = 0; i < quantita; i++){

        if(strcmp(key,libro[i]) == 0){
            printf("-> Corrispondenza trovata: stampa dettagli: \n");
            printf("\nNome Libro %s \nNome Autore %s \nAnno Pubblicazione %d \nPrezzo(EUR) %.2f \n",libro[i],autore[i],anno[i],prezzo[i]);
            break;
        }else{
            g++;
        }
    }
    if(g == quantita){
        printf("-> Nessuna corrispondenza trovata.\n");
    }






}

//SISTEMA IL FATTO CHE SE INSERISCO 2 LIBRI VENGONO INSERITI E STAMPATI GIUSTI, SE INSERISCO UN TERZO LIBRO E LO STAMPO/CERCO I LIBRI VECCHI SI ELIMINANO
//trovato problema: si sovrascrivono
//forse serve un altro ciclo for nell'inserimento dati libri