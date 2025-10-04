//Vogliamo un algoritmo che operi la conversione di un numero da una rappresentazione in base B alla rappresentazione in base 10.
#include <stdio.h>
#include <math.h>
int main(){

int base = 0,risultato = 0,posizione = 0;

printf("inserisci la base di numerazione: (tra 2 e 16)\n");
scanf("%d",&base);

printf("quante cifre ha il tuo numero? \n");
scanf("%d",&posizione);

int arrayNumero [posizione];


printf("Inserisci il tuo numero: (Inserisci una cifra e premi invio per inserire l'altra cifra) \n");
for(int i = 0; i < posizione; i++){             //inserimento numeri da tastiera nell array
    scanf("%d",&arrayNumero[i]);

}
printf("Stampa del numero inserito: \n");
for (int i = 0; i < posizione; i++) {           //stampa array
    printf("%d ", arrayNumero[i]);
}
//printf("\nInversione del vettore: \n");
for(int i = posizione - 1 ; i >= 0; i--){            //inverte il vettore
    //printf("%d ", arrayNumero[i]);

}
int j = 0;                                                      //variabile contatore per l'esponente
for(int i = posizione - 1; i >= 0; i--){

    risultato = risultato + (arrayNumero[i] * pow(base,j));     //formula per la conversione in decimale
j++;
}
printf("\nIl risultato convertito in decimale e' %d",risultato);





//COMPLETA QUANDO SAPRAI USARE I VETTORI




}