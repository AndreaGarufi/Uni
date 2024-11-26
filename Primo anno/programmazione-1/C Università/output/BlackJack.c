//black Jack (aggiungi credito e scommessa)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
#include <stdbool.h>

int gioca = 0;

int gioco();
int chiamataGiocatore();
int banco();
int vincita();

int carteBanco = 0,cartePlayer = 0,i = 0,j = 0,k = 0;
bool win = false;   //dal punto di vista del player quindi se è true vince il player
char chiama;

int main(){

    srand(time(NULL));

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);                            //serve per cambiare i colori dei testi
    DWORD dwMode = 0;

    if (GetConsoleMode(hOut, &dwMode)) {
        SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    } else {
        printf("Il terminale non supporta ANSI.\n");
    }                                                                         //fino a qui (fatto da chatgpt)


    printf("\033[43m");
    printf("\nBLACK JACK\n");
    printf("\033[0m");

    while(gioca != -1){
        if(gioca != 1){
            printf("Inserisci il giusto numero\n");
        }
        printf("\nPremi 1 per giocare, -1 per uscire:\n");
        scanf("%d",&gioca);
        if(gioca == 1){
            gioco();
        }
        win = false;
        k = 0;
        cartePlayer = 0;
        carteBanco = 0;
    
    }

}
int gioco(){
    printf("MELOX\n");
    cartePlayer = 0;
    carteBanco = 0;
        
    chiama = '\0';
        do{

            chiamataGiocatore();
            if(k < 1){ 
                banco();  //viene chiamata la sua carta solo la prima volta
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
            while(carteBanco < 17){
                banco();
            }
            if(carteBanco >= 17 && carteBanco < 21){
                vincita();
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
    int scelta = 0;
    j = 0;
    j = 1 + rand() %10;     //carte del player
    
    if(j == 1){
        printf("ASSO! scegli: se vale 1 o 11\n");
        scanf("%d",&scelta);
        
        j = scelta;
    }

    cartePlayer = cartePlayer + j;
    printf("\nPLAYER = %d \n",cartePlayer);

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
    k = 1;

    i = 1 + rand() %10;     //carte del banco

    carteBanco = carteBanco + i;
    printf("\nBANCO = %d \n",carteBanco);

    if(carteBanco > 21){
        win = true;     //player vince
        vincita();

    }if(carteBanco == 21){
        win = false;    //player perde
        vincita();
    }

    return 0;

}