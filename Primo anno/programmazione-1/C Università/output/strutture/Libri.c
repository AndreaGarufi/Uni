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
void stampaAlfabetico(char *libro[]);

typedef struct {
    char *nome[100];

    char *autore[100];

    int anno[100];

    float prezzo[100];
}libriStr;

int quantita = 0;

int main(){

    libriStr datiLibro;

    int operazione = 0;
    printf("Inserisci 1 per aggiungere un libro, -1 per uscire -> ");
    
    do{
        scanf("%d",&operazione);
        if(operazione == 1){
            dati(datiLibro.nome,datiLibro.autore,datiLibro.anno,datiLibro.prezzo);
        } 
    }while(operazione == 1);
    
    /*for(int i = 0; i < quantita;i++){       //stampa delle stringhe + con gli altri dati
        printf("\nNome Libro: %s \nNome Autore: %s \nAnno Pubblicazione: %d \nPrezzo: %.2f" ,datiLibro.nome[i],datiLibro.autore[i],datiLibro.anno[i],datiLibro.prezzo[i]);
        puts("");
    } */       
    
   stampaAlfabetico(datiLibro.nome);
    printf("\n\nfine");
}
void dati(char *libro[], char *autore[], int anno[], float prezzo[]){   //qui passa per riferimento

    printf("\nDATI LIBRI\n");

    printf("Qunati libri vuoi inserire? -> ");
    scanf("%d",&quantita);

    char tempLibro[50] = {0};
    char tempAutore[50] = {0};
    
    
    for(int i = 0; i < quantita; i++){
        printf("Inserisci i dati del libro numero %d :\nNome Libro -> ",i+1);
        scanf(" %[^\n]",tempLibro); //nome libro

        printf("\nNome Autore -> ");    
        scanf(" %[^\n]",tempAutore); // nome autore

        printf("\nAnno Pubblicazione -> ");    
        scanf("%d",&anno[i]); // Anno Pubblicazione

        printf("\nPrezzo -> ");    
        scanf("%f",&prezzo[i]); // Prezzo

        puts("");
        

        libro[i] = malloc(strlen(tempLibro) + 1);
        autore[i] = malloc(strlen(tempAutore) + 1);
        if(libro[i] == NULL || autore[i] == NULL){
            printf("Abbiamo superato i Ghilowatt");
        }else{
            strcpy(libro[i],tempLibro);
            strcpy(autore[i],tempAutore);
        }
    }

    for(int i = 0; i < quantita;i++){       //stampa delle stringhe + con gli altri dati
        libro[i][0] = toupper(libro[i][0]); //scrive la prima lettera maiuscola
        printf("\nNome Libro: %s \nNome Autore: %s \nAnno Pubblicazione: %d \nPrezzo: %.2f" ,libro[i],autore[i],anno[i],prezzo[i]);
        puts("");
    }
    

}

void stampaAlfabetico(char *libro[]){


    printf("STAMPA IN ORDINE ALFABETICO\n");//orario 16:16

    //bubble sort 

    for(int i = 0; i < quantita; i++){

        for(int j = 0;j < quantita - 1; j++){

            if((int)libro[j][0] > (int)libro[j + 1][0]){
                char *temp = libro[j];
                libro[j] = libro[j + 1];
                libro[j + 1] = temp;
            }
        }

    }
    for(int i = 0;i < quantita; i++){
        printf("\n %s ",libro[i]);
    }
        

}
