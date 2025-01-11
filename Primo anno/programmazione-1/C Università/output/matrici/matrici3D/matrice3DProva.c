#include <stdio.h>
#include <stdlib.h>

int ***generazioneMatrice(int r, int c, int p);
void ***sommaMatrix(int ***matrix,int r, int c, int p);

int main(){

    int righe = 0,colonne = 0,profondita = 0;

    printf("\nInserisci le dimensioni della matrice: righe colonne e profondita' della matrice 3D \n");
    scanf("%d%d%d",&righe,&colonne,&profondita);

    //int matriceAutomatica[3][3][3] = {{{1,2,3},{1,2,3},{1,2,3}},{{1,2,3},{1,2,3},{1,2,3}},{{1,2,3},{1,2,3},{1,2,3}}};   dichiarazione automatica matrice 3D

    int ***matrice = generazioneMatrice(righe,colonne,profondita);

    printf("\nStampa della matrice Ritornata al main\n");

    for (int k = 0; k < profondita; k++) { // Profondità
        printf("Profondita %d:\n", k+1);
        for (int i = 0; i < righe; i++) { // Righe
            for (int j = 0; j < colonne; j++) { // Colonne
                printf("%d  ", matrice[i][j][k]);
            }
            printf("\n"); // Fine riga
        }
        printf("\n"); // Separatore tra livelli
    }

    sommaMatrix(matrice,righe,colonne,profondita);

    system("PAUSE");


}
int ***generazioneMatrice(int r, int c, int p){
    printf("GENERAZIONE MATRICE...");

    int ***matrix = malloc(sizeof(int**)*r);        //prima alloco le righe
    for(int i = 0; i < r; i++){
        matrix[i] = malloc(sizeof(int*)*c);         //poi le colonne

        for(int j = 0; j < c; j++){
            matrix[i][j] = malloc(sizeof(int)*p);   //infine la profondita
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            for(int k = 0; k < p; k++){
                matrix[i][j][k] = 1 + rand() % 21;
            }
        }

    }

    printf("\nStampa della matrice\n");

    for (int k = 0; k < p; k++) { // Profondità
        printf("Profondita %d:\n", k+1);
        for (int i = 0; i < r; i++) { // Righe
            for (int j = 0; j < c; j++) { // Colonne
                printf("%4d", matrix[i][j][k]);
            }
            printf("\n"); // Fine riga
        }
        printf("\n"); // Separatore tra livelli
    }

    return matrix;
}

void ***sommaMatrix(int ***matrix,int r, int c, int p){
    printf("\nSOMMA DEI NUMERI NELLA MATRICE...\n");

    int somma = 0;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            for(int k = 0; k < p; k++){
                somma = somma + matrix[i][j][k];
            }
        }
    }
    printf("\nLa somma e' -> %d\n",somma);
}