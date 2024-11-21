#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generaMatrice();

int sommaMatrici();

int moltiplicaMatrici();

int trasposta();


int matrice1[100][100] = {{0}};
int matrice2[100][100] = {{0}};

int matriceRand[100][100] = {{0}};
int matriceSomma[100][100] = {{0}};
int matriceMolt[100][100] = {{0}};

int valore = 0,scelta = 0;

int main(){

    srand(time(NULL));

    




    printf("OPERAZIONI CON LE MATRICI\n Cosa vuoi fare?\n (0)genera una matrice | (1)somma tra matrici | (2)moltiplicazione tra matrici | (3)matrice trasposta | (5)exit\n");


    while(scelta != 5){

        printf("\nInserisci la scelta --> ");
        scanf("%d",&scelta);

        for(int i = 0; i < 100; i++){               //reinizializzo le matrici a 0 ogni volta

            for(int j = 0; j < 100; j++){

                matrice1[i][j] = 0;
                matrice2[i][j] = 0;
                matriceRand[i][j] = 0;
                matriceSomma[i][j] = 0;
                matriceMolt[i][j] = 0;
            
            }
        }

        switch(scelta){

            case 0: generaMatrice();
                break;
            case 1: sommaMatrici();
                break;
            case 2: moltiplicaMatrici();
                break;

            case 3: trasposta();
                break;                

            default: printf("Inserisci un numero valido");
                break;

        } 

    }
    

}
int generaMatrice(){

    int riga = 0,colonna = 0;

    printf("GENERAZIONE MATRICE\n");

    printf("Inserisci le dimensioni della matrice:(es. 5 7): ");
    scanf("%d %d",&riga,&colonna);

    for(int i = 0; i < riga; i++){

        for(int j = 0; j < colonna;j++){

            matriceRand[i][j] = rand() % 99;
        } 
    }

    for(int i = 0; i < riga; i++){

        for(int j = 0; j < colonna;j++){

            printf("%2d ",matriceRand[i][j]);
        } 
        puts("");
    }

    return 0;

}

int sommaMatrici(){
    
    int riga1 = 0,colonna1 = 0,riga2 = 0,colonna2 = 0;

    printf("SOMMA DI 2 MATRICI\n\n(ricorda che per sommare 2 matrici queste devono essere uguali come dimensione)\n");

    do{

        printf("Inserisci le dimensioni della prima matrice:(es. 5 7): ");
        scanf("%d %d",&riga1,&colonna1);

        printf("Inserisci le dimensioni della seconda matrice:(es. 7 5): ");
        scanf("%d %d",&riga2,&colonna2);

    }while(riga1 != riga2 || colonna1 != colonna2);


    printf("Inserisci la prima matrice: %d x %d \n",riga1,colonna1);


    for(int i = 0; i < riga1; i++){

        for(int j = 0; j < colonna1; j++){

            scanf("%d",&valore);

            matrice1[i][j] = valore;

        }
    puts("");
    }

    

    valore = 0;

    printf("Inserisci la seconda matrice: %d x %d \n",riga2,colonna2);


    for(int i = 0; i < riga2; i++){

        for(int j = 0; j < colonna2; j++){

            scanf("%d",&valore);

            matrice2[i][j] = valore;

        }
    puts("");
    }


    printf("\n\nSTAMPA MATRICE 1\n\n");

    for(int i = 0; i < riga1; i++){

        for(int j = 0; j < colonna1; j++){

            printf("%2d ",matrice1[i][j]);
        }
    puts("");
    }

    printf("\nSTAMPA MATRICE 2\n\n");

    for(int i = 0; i < riga2; i++){

        for(int j = 0; j < colonna2; j++){

            printf("%2d ",matrice2[i][j]);
        }
    puts("");
    }

    printf("\nSTAMPA MATRICE SOMMATA\n");

    for(int i = 0; i < riga1; i++){

            for(int j = 0; j < colonna1; j++){

                matriceSomma[i][j] = matrice1[i][j] + matrice2[i][j];
                printf("%2d ",matriceSomma[i][j]);
            }
            puts("");
        }
    return 0;
}//end function

int moltiplicaMatrici(){


    int riga1 = 0,colonna1 = 0,riga2 = 0,colonna2 = 0;

    printf("MOLTIPLICAZIONE DI 2 MATRICI\n\n(ricorda che per poterle moltiplicare il numero delle righe della prima matrice devono essere uguali al numero delle colonne della seconda)\n\n");

    do{
        printf("Inserisci le dimensioni della prima matrice:(es. 5 7): ");
        scanf("%d %d",&riga1,&colonna1);

        printf("Inserisci le dimensioni della seconda matrice:(es. 7 5): ");
        scanf("%d %d",&riga2,&colonna2);   

    }while(riga1 != colonna2);
    

    printf("Inserisci la prima matrice: %d x %d \n",riga1,colonna1);


    for(int i = 0; i < riga1; i++){

        for(int j = 0; j < colonna1; j++){

            scanf("%d",&valore);

            matrice1[i][j] = valore;

        }
    puts("");
    }

    valore = 0;

    printf("Inserisci la seconda matrice:  %d x %d \n",riga2,colonna2);


    for(int i = 0; i < riga2; i++){

        for(int j = 0; j < colonna2; j++){

            scanf("%d",&valore);

            matrice2[i][j] = valore;

        }
    puts("");
    }

    printf("STAMPA MATRICE 1\n\n");

    for(int i = 0; i < riga1; i++){

        for(int j = 0; j < colonna1; j++){

            printf("%2d ",matrice1[i][j]);
        }
    puts("");
    }

    printf("\nSTAMPA MATRICE 2\n\n");

    for(int i = 0; i < riga2; i++){

        for(int j = 0; j < colonna2; j++){

            printf("%2d ",matrice2[i][j]);
        }
    puts("");
    }

    printf("\nSTAMPA MATRICE MOLTIPLICATA\n");

     
    for (int i = 0; i < riga1; i++) {               //studia meglio questo codice
        for (int j = 0; j < colonna2; j++) {
            for (int k = 0; k < colonna1; k++) { // colonna1 == riga2
                matriceMolt[i][j] = matriceMolt[i][j] + (matrice1[i][k] * matrice2[k][j]);

            }
        }
    }

    for (int i = 0; i < riga1; i++) {
        for (int j = 0; j < colonna2; j++) {
            printf("%2d ", matriceMolt[i][j]);
        }
        puts("");
    }

    return 0;
}//end function

int trasposta(){

    int riga = 0,colonna = 0;

    printf("TRASPOSTA DI UNA MATRICE\n");

        printf("Inserisci le dimensioni della matrice:(es. 5 7): ");
        scanf("%d %d",&riga,&colonna);

    printf("Inserisci la matrice: %d x %d \n",riga,colonna);


    for(int i = 0; i < riga; i++){

        for(int j = 0; j < colonna; j++){

            scanf("%d",&valore);

            matrice1[i][j] = valore;

        }
    puts("");
    }

    printf("\n\nSTAMPA MATRICE\n\n");

    for(int i = 0; i < riga; i++){

        for(int j = 0; j < colonna; j++){

            printf("%2d ",matrice1[i][j]);
        }
    puts("");
    }

    printf("\n\nSTAMPA MATRICE TRASPOSTA\n\n");

    return 0;
}