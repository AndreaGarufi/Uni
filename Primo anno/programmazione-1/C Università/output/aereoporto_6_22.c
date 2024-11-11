/*(Sistema di prenotazione per compagnie aeree).
 Una piccola compagnia aerea ha appena acquistato un computer per il suo nuovo sistema automatico di prenotazione. 
 Il presidente vi ha chiesto di programmare il nuovo sistema. 
 Scriverete un programma per assegnare i posti su ogni volo dell’unico aereo della compagnia (capacità: 10 posti). 
 Il vostro programma deve stampare il seguente menu di alternative: 
 Please type 1 for "first class" Please type 2 for "economy" Se la persona scrive 1, allora il vostro programma deve assegnare un posto in prima classe 
 (posti da 1 a 5). Se la persona scrive 2, allora il vostro programma deve assegnare un posto in classe economy (posti da 6 a 10). 
 Il vostro programma deve quindi stampare una carta d’imbarco indicante il numero del posto della persona e se questo si trova in prima classe o 
 in classe economy. Usate un array unidimensionale per rappresentare la mappa dei posti dell’aereo. 
 Inizializzate tutti gli elementi dell’array a 0 per indicare che tutti i posti sono vuoti. 
 Quando ogni posto viene assegnato, ponete l’elemento corrispondente dell’array a 1 per indicare che il posto non è più disponibile. 
 Il vostro programma, naturalmente, non deve mai assegnare un posto che è già stato assegnato. 
 Quando la prima classe è piena, il vostro programma deve domandare alla persona se è disposta ad accettare un posto in classe economy (e viceversa).
 Se lo è, assegnate il posto appropriato; se non lo è, stampate il messaggio "Next flight leaves in 3 hours."   PAG 279*/

//PROGRAMMA FINITO

#include <stdio.h>
#include <stdlib.h>

void prima_classe(int a[], int dim);
void seconda_classe(int a[], int dim);

int postoAssegnato = 0,numeroPosto = 0,posti = 0;     //variabili globali per la funzione prima_classe 
int postoAssegnato2 = 0,numeroPosto2 = 0, posti2 = 0;
int arrayPosti[10] = {0};   // array per tenere conto dei posti occupati
int main(){

    
    int numero = 0;
    char yes;

    
    

    do{
        
        if(postoAssegnato == 5 && postoAssegnato2 == 5){

        printf("Sorry, we are full, netx flyth leaves in 3 hours ");
        system("PAUSE");
        }

        printf("Type 1 for first class, or type 2 for economy class: \n");

        scanf("%d",&numero);

        while(numero != 1 && numero != 2){               //finche numero è diverso da 1 e da 2 lo fa reinserire
            
            printf("\nInserisci un numero valido\n");
            scanf("%d",&numero);
            
        }
        
        while(numero == 1 || numero == 2){              //finche numero è  = 1 oppure = 2 entra nel while e poi nel giusto if richiamando la funzione

            if(numero == 1){
                prima_classe(arrayPosti,10);
                numero = 0;
            }else{
                seconda_classe(arrayPosti,10);
                numero = 0;
            }
        }
        printf("\nDo you want to take other tickets? \nPress Y to continue: ");     //finchè inserisco Y continuo ad inserire numeri
        scanf(" %c", &yes);

    }while( yes == 'Y' || yes == 'y');
    printf("Exit...");
    system("PAUSE");
}

void prima_classe(int a[], int dim){                                                        //funzione prima classe

    char scelta = 0;

    printf("\nFIRST CLASS\n");

    
    for(int i = 0; i < (dim / 2); i++){                                                   //scorre tutti gli elementi dallo 0 al 4 (5 elementi)

        if(a[i] == 0){                                                                  //se l'elemento a[i] è vuoto assegna il posto e esce dal ciclo for 
            a[i] = 1;
            numeroPosto = i+1;
            postoAssegnato++;
            break;
        }
        if(postoAssegnato == 5){ 

        printf("FIRST CLASS FULL ");
        if(postoAssegnato2 == 5){
            printf("Sorry, we are full, next flyth leaves in 3 hours ");
        }else{
        printf("\ndo you want to take a sit in SECOND CLASS? press Y to consent: ");
        scanf(" %c",&scelta);
        if(scelta == 'Y' || scelta == 'y'){
            
            seconda_classe(arrayPosti,10);
            return;
        }
        }
    }
    
    }//end for

    printf("Occuped sits: %d \n",postoAssegnato);
    
        printf("\nPosto asseganto al numero: %d",numeroPosto);

        posti = (dim/2) - postoAssegnato;
        if(posti < 0){
            posti = 0;
        }
        printf("\nI posti disponibili sono: %d",posti);

        for(int i = 0; i < (dim/2); i++){       //prova
            printf("\n %35d ",a[i]);
        } 
 
    

}

void seconda_classe(int a[], int dim){                                                        //funzione seconda classe

    char scelta;

    printf("\nSECOND CLASS\n");

    for(int i = 5; i <= dim; i++){

        if(a[i] == 0){

            a[i] = 1;
            postoAssegnato2 ++;
            numeroPosto2 = i+1;
            break;
        }
        if(postoAssegnato2 == 5){

        printf("SECOND CLASS FULL");
        if(postoAssegnato == 5){
            printf("Sorry, we are full, next flyth leaves in 3 hours ");
        }else{
        printf("\ndo you want to take a sit in FIRST CLASS? press Y to consent: ");
        scanf(" %c",&scelta);
        if(scelta == 'Y' || scelta == 'y'){
        
            prima_classe(arrayPosti,10);
            return;
        }
        }   
    }
    }//end for
    
    printf("\nPosto asseganto al numero: %d",numeroPosto2);

    posti2 = 5 - postoAssegnato2;
    if(posti2 < 0){
        posti2 = 0;
    }
        printf("\nI posti disponibili sono: %d",posti2);

        for(int i = 5; i < 10; i++){       //prova
            printf("\n %d ",a[i]);
        }
    
}