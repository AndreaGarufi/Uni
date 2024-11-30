#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>

int esempiMatrice();

int generaMatrice();

int sommaMatrici();

int moltiplicaMatrici();

int trasposta();

int determinante();


int matrice1[100][100] = {{0}};
int matrice2[100][100] = {{0}};

int matriceRand[100][100] = {{0}};
int matriceSomma[100][100] = {{0}};
int matriceMolt[100][100] = {{0}};

int valore = 0,scelta = 0;

int main(){

    srand(time(NULL));


    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);                            //serve per cambiare i colori dei testi
    DWORD dwMode = 0;

    if (GetConsoleMode(hOut, &dwMode)) {
        SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    } else {
        printf("Il terminale non supporta ANSI.\n");
    }                                                                         //fino a qui (fatto da chatgpt)

   
    printf("\033[36m"); //cambia il colore del testo (se metto [46m mette uno sfondo al testo)
    printf("\nOPERAZIONI CON LE MATRICI\n Cosa vuoi fare?\n (0)esempi di matrici | (1)genera una matrice | (2)somma tra matrici | (3)moltiplicazione tra matrici | (4)matrice trasposta\n (5)determinante di una matrice | (6)exit\n");
    printf("\033[0m"); //resetta il colore

    while(scelta != 6){

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
            case 0: esempiMatrice();
                break;
            case 1: generaMatrice();
                break;
            case 2: sommaMatrici();
                break;
            case 3: moltiplicaMatrici();
                break;
            case 4: trasposta();
                break;
            case 5: determinante();        
                break;
            default: printf("Inserisci un numero valido");
                break;

        } 

    }
    
}
int esempiMatrice(){

    printf("\nUna matrice e' una tabella rettangolare di elementi ordinati in righe e colonne.\nUna matrice si dice quadrata se ha lo stesso numero di righe e colonne\n");


    printf("\nEcco degli esempi di matrici quadrate particolari:\n\n");

    printf("\033[47m\033[35m");
    printf("\nTRIANGOLARE SUPERIORE\n");
    printf("\033[0m");

       for(int i = 0; i < 4; i++){

            for(int j = 0; j < 4;j++){

            matriceRand[i][j] = rand() % 99;
            

        } 
    }

    for(int i = 0; i < 4; i++){      

        for(int j = 0; j < 4;j++){

            if(i > j){
                
                matriceRand[i][j] = 0;
                
            }

            printf("%2d ",matriceRand[i][j]);
        } 
        puts("");
    }
    printf("\033[47m\033[35m");
    printf("\nTRIANGOLARE INFERIORE\n");
    printf("\033[0m");

       for(int i = 0; i < 4; i++){

            for(int j = 0; j < 4;j++){

            matriceRand[i][j] = rand() % 99;
            

        } 
    }

    for(int i = 0; i < 4; i++){      

        for(int j = 0; j < 4;j++){

            if(i < j){
                
                matriceRand[i][j] = 0;
                
            }

            printf("%2d ",matriceRand[i][j]);
        } 
        puts("");
    }
    
    printf("\033[47m\033[35m");
    printf("\nDIAGONALE\n");
    printf("\033[0m");

       for(int i = 0; i < 4; i++){

            for(int j = 0; j < 4;j++){

            matriceRand[i][j] = 1;
            

        } 
    }

    for(int i = 0; i < 4; i++){      

        for(int j = 0; j < 4;j++){

            if(i < j || i > j){
                
                matriceRand[i][j] = 0;
                
            }

            printf("%2d ",matriceRand[i][j]);
        } 
        puts("");
    }

    printf("In questo caso visto che gli elementi della diagonale sono tutti 1 questa e' una matrice identita'\n");

    return 0;

}

int generaMatrice(){

    int riga = 0,colonna = 0;

    printf("\033[47m\033[35m");
    printf("GENERAZIONE MATRICE\n");
    printf("\033[0m");

    do{
        printf("Inserisci le dimensioni della matrice:(es. 5 7): ");
        printf("\033[0m");
        scanf("%d %d",&riga,&colonna);
    }while(riga < 0 || colonna < 0);
    
    for(int i = 0; i < riga; i++){

        for(int j = 0; j < colonna;j++){

            matriceRand[i][j] = rand() % 20;
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

    printf("\033[47m\033[35mSOMMA DI 2 MATRICI\033[0m\n\n(ricorda che per sommare 2 matrici queste devono essere uguali come dimensione)\n");

    do{

        printf("Inserisci le dimensioni della prima matrice:(es. 5 7): ");
        scanf("%d %d",&riga1,&colonna1);

        printf("Inserisci le dimensioni della seconda matrice:(es. 7 5): ");
        scanf("%d %d",&riga2,&colonna2);

    }while(riga1 != riga2 || colonna1 != colonna2 || riga1 < 0 || riga2 < 0 || colonna1 < 0 || colonna2 < 0);


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

    printf("\033[47m\033[35mMOLTIPLICAZIONE DI 2 MATRICI\033[0m\n\n(ricorda che per poterle moltiplicare il numero delle righe della prima matrice devono essere uguali al numero delle colonne della seconda)\n\n");

    do{
        printf("Inserisci le dimensioni della prima matrice:(es. 5 7): ");
        scanf("%d %d",&riga1,&colonna1);

        printf("Inserisci le dimensioni della seconda matrice:(es. 7 5): ");
        scanf("%d %d",&riga2,&colonna2);   

    }while(riga1 != colonna2 || riga1 < 0 || riga2 < 0 || colonna1 < 0 || colonna2 < 0);
    

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

    int riga = 0,colonna = 0,temp = 0;
    printf("\033[47m\033[35m");
    printf("TRASPOSTA DI UNA MATRICE\n");
    printf("\033[0m");

    do{
        printf("Inserisci le dimensioni della matrice:(es. 5 7): ");
        scanf("%d %d",&riga,&colonna);
    }while(riga < 0 || colonna < 0);


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

    for(int i = 0; i < riga;i ++){                  //calcolo matrice trasposta
        for(int j = 0; j <= colonna; j++){

            matrice2[i][j] = matrice1[j][i];
        }
    }

    printf("\n\nSTAMPA MATRICE TRASPOSTA\n\n");

    temp = colonna;      //nella matrice trasposta le rige diventano le colonne e viceversa quindi faccio questo per stamparla bene
    riga = colonna;
    colonna = temp;

    for(int i = 0; i < riga;i ++){                
        for(int j = 0; j <= colonna; j++){

            printf("%2d ",matrice2[i][j]);
        }
        puts("");
    }

    return 0;
}//end function

int determinante(){
    int riga = 0,colonna = 0,determinante = 0;
    int matriceAppoggio[100][100] = {{0}};

    printf("\033[47m\033[35m");
    printf("DETERMINANTE DI UNA MATRICE\n");
    printf("\033[0m");

    do{
        printf("Inserisci le dimensioni della matrice quadrata (massimo 3 x 3):(es. 5 7): ");
        scanf("%d %d",&riga,&colonna);
    }while(riga != colonna || riga < 0 || colonna < 0);
        

    printf("Inserisci la matrice: %d x %d \n",riga,colonna);


    for(int i = 0; i < riga; i++){

        for(int j = 0; j < colonna; j++){

            scanf("%d",&valore);

            matrice1[i][j] = valore;

        }
    puts("");
    }

    printf("STAMPA MATRICE \n");

    for(int i = 0; i < riga;i++){                
        for(int j = 0; j < colonna; j++){

            printf("%2d ",matrice1[i][j]);
        }
        puts("");
    }

    puts("");

    if(riga == 2){          //det matrice 2x2
                
        determinante = (matrice1[0][0] * matrice1[1][1]) - (matrice1[0][1] * matrice1[1][0]);
            
        
    }else{                  //det matrice 3x3
    
        for(int i = 0; i < riga;i++){
            for(int j = 0; j < colonna;j++){

                matriceAppoggio[i][j] = matrice1[i][j];
            }
        }
        matriceAppoggio[0][3] = matrice1[0][0];     //per la 3x3 uso sarrus e quindi copio le 2 prime colonne per poi fare la moltiplicazione secondo sarrus
        matriceAppoggio[0][4] = matrice1[0][1];
        matriceAppoggio[1][3] = matrice1[1][0];
        matriceAppoggio[1][4] = matrice1[1][1];
        matriceAppoggio[2][3] = matrice1[2][0];
        matriceAppoggio[2][4] = matrice1[2][1];

        determinante = (matriceAppoggio[0][0] * matriceAppoggio[1][1] * matriceAppoggio[2][2]) + (matriceAppoggio[0][1] * matriceAppoggio[1][2] * matriceAppoggio[2][3]) + (matriceAppoggio[0][2] * matriceAppoggio[1][3] * matriceAppoggio[2][4]) - (matriceAppoggio[0][4] * matriceAppoggio[1][3] * matriceAppoggio[2][2]) - (matriceAppoggio[0][3] * matriceAppoggio[1][2] * matriceAppoggio[2][1]) - (matriceAppoggio[0][2] * matriceAppoggio[1][1] * matriceAppoggio[2][0]); 

    }

    printf(" Il determinante e': %d ",determinante);

}//end function