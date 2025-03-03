/*Definire una struttura chiamata Studente che contenga:

Il nome dello studente (una stringa).
L'età dello studente (un intero).
Il voto dello studente (un valore in virgola mobile).
Permettere all'utente di inserire i dati di più studenti, inclusi nome, età e voto. Il numero massimo di studenti è 50.

Calcolare e stampare:

La media dei voti di tutti gli studenti.
L'elenco completo degli studenti con i dati inseriti.

utilizza una funzione per questo:
Calcolare la media dei voti.


Input/output del programma:
L'utente deve poter scegliere il numero di studenti da inserire.
Tutti i dati degli studenti devono essere visualizzati in output con una formattazione leggibile*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome[50];

    int eta[50];

    float voto[50];
}votoStr;

void media(float v[],int dimv);

int main(){
    int studenti = 0;


    printf("Quanti studenti vuoi inserire? ");
    scanf("%d",&studenti);

    votoStr studente;   //variabile id tipo votoStr
    for(int i = 0; i < 50;i++){
        studente.voto[i] = 0;
    }

    char temp[50];
    int eta = 0;
    float voto = 0;
    for(int i = 0; i < studenti; i++){
        
        printf("Inserisci il nome dello studente numero %d: ", i+1);
        scanf(" %[^\n]",temp); //salvo il nome dentro l'array temp (non so perche scanf è di questo colore ma questa cosa serve a fargli prendere tutti i caratteri fino a quando non si preme invio (serve cosi legge lo spazio))

        studente.nome[i] = malloc(strlen(temp) + 1); //assegno, con malloc, all'array di puntatori *nome[50] la lunghezza del nome inserito + 1 (che sarebbe '\0')
        if(studente.nome[i] != NULL){
            strcpy(studente.nome[i], temp);
            
            printf("Inserisci l'eta ");
            scanf("%d",&eta);
            studente.eta[i] = eta;
            printf("Inserisci il voto ");
            scanf("%f",&voto);
            studente.voto[i] = voto;            


        }else{
            printf("Abbiamo superato i Ghilowatt");
            exit(-1);
        }

    }

    for(int i = 0; i < studenti;i++){       //stampa delle stringhe + con gli altri dati
        printf("\nNome %s ,eta' %d ,voto %.2f",studente.nome[i], studente.eta[i], studente.voto[i]);
    }

    puts("");

    media(studente.voto,50);


}
void media(float v[],int dimv){        //*n[] vettore con i nomi, v[] vettore con i voti
    float somma = 0;
    float media = 0;
    int g = 0;
    for(int i = 0;i < dimv; i++){

        somma = somma + v[i];
        if(v[i] != 0){
            g++;    //contatore
        }

    }
    media = somma / g;

    printf("La media dei voti di tutti gli studenti e': %.2f",media); 

}
