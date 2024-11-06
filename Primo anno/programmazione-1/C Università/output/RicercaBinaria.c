#include <stdio.h>

int binary_search(const int a[], int chiave, int low, int high); //prototipo di funzione

int main(){

int vettore[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};          //vettore

int key = 0;

printf("Inserisci il numero da cercare: \n");
scanf("%d",&key);

int risultato = binary_search(vettore , key , 0 , 10-1);        //salva il risultato il valore che ritorna da questa chiamata di funzione

if(risultato != -1){

    printf("il valore %d e' stato trovato nella posizione : %d",key,risultato);

}else{
    printf("valore non trovato");
}

}

int binary_search(const int a[], int chiave, int low, int high){            //funzione

    while(low <= high){

        int centro = (low + high) / 2;
        if(a[centro] == chiave){
            return centro;
        }else if(a[centro] > chiave){
            high = centro - 1;
        }else{
            low = centro + 1;}
        }
        return -1;
    }