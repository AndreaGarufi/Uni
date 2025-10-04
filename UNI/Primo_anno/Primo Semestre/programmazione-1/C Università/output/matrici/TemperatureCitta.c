#include <stdio.h>
#include <stdbool.h>
void mediaTemp(int a[], int dim, bool x);

int main(){

    int arrayTemp [2][7] = {{0}};    //0 siracusa 1 catania 
    int temperature = 0;
    bool citta1 = true;
    bool citta2 = false;


    for(int i = 0; i < 2 ; i++){

       for(int j = 0 ; j < 7; j++){

        printf("\nInserisci le temperature per le citta' ");
        scanf("%d",&temperature);
        arrayTemp[i][j] = temperature;

       } 
    }

    printf("Stampa valori temperature: \n");
    printf("\n-----------------------------------\n");



    for(int i = 0; i < 2 ; i++){
        if(i == 0){
            printf("Siracusa: ");
            citta1 = true;
        }else{
            printf("Catania:  ");

            citta2 = false;
        }
       for(int j = 0 ; j < 7; j++){
        printf("%d ",arrayTemp[i][j]);

       }
        printf("\n");
       }
    printf("\n-----------------------------------\n");

    printf("\nStampa media valori Siracusa: \n");
    mediaTemp(arrayTemp[0],7,citta1);

    printf("\n\n-----------------------------------\n");

    printf("\nStampa media valori Catania: \n");
    mediaTemp(arrayTemp[1],7,citta2);
 
    printf("\n\n-----------------------------------\n");

}

void mediaTemp(int a[],int dim, bool x){

    float media = 0;
    int somma = 0;
    if(x == true){
    
        for(int i = 0; i < dim; i++){
            somma = somma + a[i];
        }
        media = (float) somma / dim;
        printf("la media e': %.2f ",media);

    }else{
   
        for(int i = 0; i < dim; i++){
            somma = somma + a[i];
        }
        media =  (float) somma / dim;
        printf("la media e': %.2f ",media); 
    }

 
}



