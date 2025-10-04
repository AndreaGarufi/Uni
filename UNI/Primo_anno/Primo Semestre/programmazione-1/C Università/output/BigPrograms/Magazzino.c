#include <stdio.h>
#include <stdbool.h>


void print_magazine(const int a[4][3]);             //è costante perchè tanto lo devo solo stampare e non ci opero quindi nel dubbio ho messo const

void modify_inventory(int a[4][3], int h, int k, bool i, int n);


int main(){
                            //elett.  veicoli  software  abbiglia.
    int Magazzino [4][3] = {{5,7,10},{1,2,3},{40,80,1},{50,50,50}}; //ogni numero indica la quantità di ogni articolo (es. cat elettronica: pc 5 , telefoni 7, calcolatrici 10)
    int nVettore = 0, nElemento = 0, numero = 0;
    char operazione;
    bool incremento = true;

    print_magazine(Magazzino);

    printf("\nInserisci la coordinata che indica la posizione dell'elemento nel magazzino: \n");

    printf("Categoria: ");
    scanf("%d",&nVettore);

    printf("\nElemento: ");
    scanf("%d",&nElemento);

    printf("Vuoi incrementare (+) o docrementare (-) ?\n");
    scanf(" %c",&operazione);

    if(operazione == '+'){

        incremento = true;
    }else{
        incremento = false; 
    }

    printf("Di quanto vuoi modificare il numero? \n");
    scanf("%d",&numero);

    modify_inventory(Magazzino, nVettore, nElemento, incremento, numero);

}

void modify_inventory(int a[4][3], int h, int k, bool i, int n){

    printf("INVENTARIO MODIFICATO \n");

    if(i == true){
        a[h][k] = a[h][k] + n;
    }else{
        a[h][k] = a[h][k] - n;
    }

    //printf(" %d ",a[h][k]);

    print_magazine(a);
    
}




void print_magazine(const int a[4][3]){

    printf("\nSTAMPA CONTENUTO MAGAZZINO \n");

    for(int i = 0; i < 4; i++){

        if(i == 0){
            printf("\nCAT ELETTRONICA (0) \n");

            }else if( i == 1){
                printf("\nCAT VEICOLI (1) \n");
                
                }else if(i == 2){
                    printf("\nCAT SOFTWARE (2) \n");

                    }else{
                        printf("\nCAT ABBIGLIAMENTO (3) \n");
                    }
        


        for(int j = 0; j < 3; j++){

            if(i == 0){

                if(j == 0){
                    printf("PC: %d \n",a[i][j]);

                    }else if(j == 1){
                        printf("TELEFONI: %d  \n",a[i][j]);

                    }else{
                            printf("CALCOLATRICI: %d \n",a[i][j]);                        
                        }

            }else if(i == 1){
                 
                if(j == 0){
                    printf("SF90: %d \n",a[i][j]);

                    }else if(j == 1){
                        printf("REVUELTO: %d \n",a[i][j]);

                    }else{
                            printf("P1: %d \n",a[i][j]);                        
                        }
                    }else if(i == 2){
                        
                        
                        if(j == 0){
                            printf("EXCEL: %d \n",a[i][j]);

                            }else if(j == 1){
                                printf("MINECRAFT: %d \n",a[i][j]);

                            }else{
                                    printf("GARU GPT: %d \n",a[i][j]);                        
                                }
                        }else{
                             
                        if(j == 0){
                            printf("CAPPOTTI: %d \n",a[i][j]);

                            }else if(j == 1){
                                printf("FELPE: %d \n",a[i][j]);

                            }else{
                                    printf("BUDANDE: %d \n",a[i][j]);                        
                                }
                            
                            }//end serie di if       

        }//end for colonne


    }//end for righe





}