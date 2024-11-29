//black Jack (aggiungi credito e scommessa)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
#include <stdbool.h>

int gioca = 1;

int gioco();
int chiamataGiocatore();
int banco();
int vincita();

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
    }                                                                         //fino a qui (fatto da chatgpt)


    printf("\033[43m");
    printf("\nBLACKJACK\n");
    printf("\033[0m");

    while(gioca != -1){
        if(gioca != 1){
            printf("Inserisci il numero giusto\n");
        }
        printf("\n\033[32m"); 
        printf("\nPremi 1 per giocare, -1 per uscire:\n");
        printf("\n\033[0m"); 
        scanf("%d",&gioca);
        if(gioca == 1){
            gioco();
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
int gioco(){

    cartePlayer = 0;
    carteBanco = 0;
        
    chiama = '\0';
        do{

            chiamataGiocatore();
            if(k < 1){ 
                banco();  //viene chiamata la seconda carta solo la prima volta
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
                banco();
            }
            if(carteBanco >= 17 && carteBanco < 21){
                if(carteBanco >= cartePlayer){
                    win = false;
                    vincita();
                }else{
                    win = true;
                    vincita();
                }
                
            }
            
        }

    return 0;

}
int vincita(){

    if(win == true){
        printf("\n\033[43m");
        printf("\nHAI VINTO\n");
        printf("\033[0m");
    }else{
        printf("\n\033[43m");
        printf("\nHAI PERSO\n");
        printf("\033[0m");
    }

}
int chiamataGiocatore(){
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
        vincita();
        
    }if(cartePlayer == 21){
        win = true;     //player fa 21 ma bisogna vedere se il banco fa 21, ricorda che il banco deve girare le carte fino a che non ha almeno 17
        return 0;
    }    

    return 0;
}
int banco(){
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
            vincita();              
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
    printf("\n\033[96m"); 
    printf("\nBANCO = %d \n",carteBanco);
    printf("\n\033[0m"); 

    if(carteBanco > 21){
        win = true;     //player vince
        vincita();

    }if(carteBanco == 21){
        win = false;    //player perde
        vincita();
    }

    return 0;
    
}