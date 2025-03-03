//black Jack (aggiungi credito e scommessa)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
#include <stdbool.h>

int gioca = 1;

int bank(FILE *ptr);
int conto(FILE *ptr);
int gioco(FILE *ptr,int soldi);
int chiamataGiocatore(FILE *ptr, int soldi, int scommessa);
int banco(FILE *ptr, int soldi, int scommessa);
int vincita(FILE *ptr, int soldi, int scommessa);

int carteBanco = 0,cartePlayer = 0,i = 0,j = 0,k = 0,cartaNascosta = 0,y = 0,secondaCarta = 0;
bool win = false,counter = false,x = false,condizione = false,doppia = false;   //dal punto di vista del player quindi se è true vince il player
char chiama;

int main(){
    //system("color 9F");
    srand(time(NULL));

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);                            //serve per cambiare i colori dei testi
    DWORD dwMode = 0;

    if (GetConsoleMode(hOut, &dwMode)) {
        SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    } else {
        printf("Il terminale non supporta ANSI.\n");
    }                                                                      //fino a qui (fatto da chatgpt)

    FILE *filePtr = NULL;
    int soldi = 0;



    printf("\033[43m");
    printf("\nBLACKJACK\n");
    printf("\033[0m");

    while(gioca != -1){

        printf("\n\033[32m"); 
        printf("\nPremi 1 per giocare, -1 per uscire o 5 per aprire il conto:\n");
        printf("\n\033[0m"); 
        scanf("%d",&gioca);
        if(gioca == 1){
            soldi = bank(filePtr);   
            gioco(filePtr,soldi);
        }else if(gioca == 5){
            soldi = conto(filePtr);
        }
        if(gioca != 1 && gioca != 5){
            printf("Inserisci il numero giusto\n");
        }        

        doppia = false;
        condizione = false;
        x = false;
        win = false;
        k = 0; //serve per far spawnare la seconda carta solo una volta
        y = 0; //serve per far spawnare la seconda carta solo una volta
        cartePlayer = 0;
        carteBanco = 0;
    
    }

}
int bank(FILE *ptr){
    int soldi = 0;
    ptr = fopen("conto.txt","a+");
    fscanf(ptr,"%d",&soldi);
    return soldi;
}

int conto(FILE *ptr){
    printf("Banca BlackJack\n");
    int soldi = 0;
    int conto = 0;
    int scelta = 0;

    ptr = fopen("conto.txt","a+");
    fscanf(ptr,"%d",&soldi);
    conto = soldi;

    if(soldi != 0){
        printf("Conto attuale --> %d\n",soldi);
    }else{
        printf("Conto vuoto\n");
    }
    printf("Premi 6 per visualizzare il conto, 7 per resettare il conto, premi 8 per aggiungere soldi oppure -1 per uscire:\n");
    
    do{
        scanf("%d",&scelta);
        switch(scelta){
            case -1: printf("Exit");
                return 0;
                break;
            case 6: printf("Visualizza conto --> ");
                    ptr = fopen("conto.txt","r");
                    fscanf(ptr,"%d",&soldi);
                    printf("%d\n",soldi);
                break;
            case 7: printf("Conto azzerato\n");
                    ptr = fopen("conto.txt","w+");
                break;
            case 8: printf("Quanti soldi vuoi aggiungere? --> ");
                    scanf("%d",&soldi);    
                    if(soldi != 0){
                        soldi = conto + soldi;
                        ptr = fopen("conto.txt","w+");
                    }
                    fprintf(ptr,"%d",soldi);
                    printf("Conto aggiornato\n");
                break;
            default: printf("Inserisci un numero valido\n");
        }        
    }while(scelta != 6 && scelta != 7 && scelta != 8);

    fclose(ptr);
    system("PAUSE");
    return soldi;
}

int gioco(FILE *ptr,int soldi){
    int scommessa = 0;  

    cartePlayer = 0;
    carteBanco = 0;
    chiama = '\0';

    if(soldi == 0){
        printf("\npartita senza scommessa\n");
        }else{
            ptr = fopen("conto.txt","r");
            fscanf(ptr,"%d",&soldi);
            fclose(ptr);
            printf("\nSaldo --> %d",soldi);
            printf("\nSCOMMESSA: quanto vuoi scommettere? --> ");
            scanf("%d",&scommessa);
            soldi = soldi - scommessa;
            printf("Nuovo saldo --> %d\n",soldi);
            ptr = fopen("conto.txt","w+");
            fprintf(ptr,"%d",soldi);
            fclose(ptr);
        }//AGGIORNARE I SOLDI DOPO LA VINCITA

        do{

            chiamataGiocatore(ptr,soldi,scommessa);
            if(k < 1){ 
                banco(ptr,soldi,scommessa);  //viene chiamata la seconda carta solo la prima volta
                if(condizione == true){
                    break;
                }
            }

            if(cartePlayer > 21 || carteBanco > 21){
                break;
            }
            if(win == true){
                break;
            }
            puts("");
            printf("Vuoi chiamare ancora? premi s per chiamare o premi n per uscire: ");
            scanf(" %c",&chiama);
        }while(chiama == 'S' || chiama == 's');


        if(chiama == 'n' || chiama == 'N' || cartePlayer == 21){
            counter = true;
        }
        if(counter == true){
            printf("\nLa carta nascosta del banco era: %d",cartaNascosta);
            counter = false;
            x = true;
        }
        
        if(chiama == 'n' || chiama == 'N' || cartePlayer == 21){
            while(carteBanco < 17){
                banco(ptr,soldi,scommessa);
            }
            if(carteBanco >= 17 && carteBanco < 21){
                if(carteBanco >= cartePlayer){
                    win = false;//player perde
                    vincita(ptr,soldi,scommessa);
                }else{
                    win = true; //player vince
                    vincita(ptr,soldi,scommessa);
                }
                
            }
            
        }
    return 0;

}

int vincita(FILE *ptr, int soldi, int scommessa){

    if(win == true){
        printf("\n\033[43m");
        printf("\nHAI VINTO\n");
        printf("\033[0m");

        int guadagno = scommessa * 2;
        soldi = soldi + guadagno;
        ptr = fopen("conto.txt","w+");
        fprintf(ptr,"%d",soldi);
        fclose(ptr);

        printf("\n\033[43m");
        printf("\nVINCITA = %d \nNuovo bilancio %d\n",guadagno,soldi);
        printf("\033[0m");

    }else{
        printf("\n\033[43m");
        printf("\nHAI PERSO\n");
        printf("\033[0m");
    }
}

int chiamataGiocatore(FILE *ptr, int soldi, int scommessa){
    y++;
    int scelta = 0;
    j = 0;
    j = 1 + rand() %10;     //carte del player

    if(j == 1){
        if(cartePlayer == 10){
            j = 11;
            }else if(cartePlayer > 10){
                j = 1;
            }else{
                printf("ASSO! scegli: se vale 1 o 11\n");
                scanf("%d",&scelta);
                j = scelta;            
            }

    }

    cartePlayer = cartePlayer + j;
    printf("\nCARTA = %d ",j);
    printf("\033[33m");
    printf("PLAYER = %d \n",cartePlayer);
    printf("\n\033[0m");

    if(y == 1){
        secondaCarta = 1 + rand() %10;
        if(secondaCarta == 1 || secondaCarta == 10 && j == 1 || j == 10){
            doppia = true;  //nel caso il player facesse 21 con le prime 2 carte deve vencire 1.5 x anziche 1x
        }
        printf("\nSECONDA CARTA = %d ",secondaCarta);
        cartePlayer = cartePlayer + secondaCarta;
        printf("\033[33m");
        printf("PLAYER = %d \n",cartePlayer);
        printf("\n\033[0m");
    }


    if(cartePlayer > 21){
        win = false;    //player perde
        vincita(ptr,soldi,scommessa);
        
    }if(cartePlayer == 21){
        win = true;     //player fa 21 ma bisogna vedere se il banco fa 21, ricorda che il banco deve girare le carte fino a che non ha almeno 17
        return 0;
    }    

    return 0;
}

int banco(FILE *ptr, int soldi, int scommessa){
    k ++;
    i = 0;
    i = 1 + rand() %10;     //carte del banco
    if(k == 1){
        cartaNascosta = 1 + rand() %10; //carta iniziale nascosta

        if(cartaNascosta == 1 && i == 10 || i == 1 && cartaNascosta == 10){
            win = false; //banco vince
            condizione = true; //serve per farlo uscire dal while in "gioco()"
            if(i == 10){
                printf("\nIl banco ha fatto 21! %d + asso",i);
            }else if(i == 1){
                printf("\nIl banco ha fatto 21! asso + %d",cartaNascosta);
            }   
            vincita(ptr,soldi,scommessa);              
            return 0;
        }        
    }
    if(x == true){
        carteBanco = carteBanco + cartaNascosta;
        printf("\n\033[96m");   
        printf("\nBANCO = %d \n",carteBanco);
        printf("\n\033[0m");
        x = false;

        if(carteBanco == 17){
            return 0;
        }
    }
    carteBanco = carteBanco + i;
    printf("\nCARTA = %d ",i);
    printf("\033[96m"); 
    printf("BANCO = %d \n",carteBanco);
    printf("\n\033[0m"); 

    if(carteBanco > 21){
        win = true;     //player vince
        vincita(ptr,soldi,scommessa);

    }if(carteBanco == 21){
        win = false;    //player perde
        vincita(ptr,soldi,scommessa);
    }

    return 0;
    
}