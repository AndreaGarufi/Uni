//Conversione di Valute: Crea un programma che converta una somma di denaro da una valuta a un'altra (es. euro in dollari).
#include <math.h>
#include <stdio.h>
int main(){
//tutti i tassi di cambio sono in base all euro (es. 1 euro = 1.08 dollari)
    const float dollaro = 1.08,coronaCeca = 25.37,dollaroGiamaicano = 171.18,rubloRusso = 10.71, wonSudCoreano = 1499.27,sterlinaBritannica = 0.83,yenGiapponese = 165.96; 

    int numero = 0;
    float euro = 0,soldiConvertiti = 0;
    printf("Converti i tuoi euro in valute di altri paesi.\n");
    printf(" Seleziona 1 per Dollaro Statunitense \n Seleziona 2 per Corona Ceca \n Seleziona 3 per Dollaro Giamaicano \n Seleziona 4 per Rublo Russo \n Seleziona 5 per Won Sud Coreano \n Seleziona 6 per Sterlina Britannica \n Seleziona 7 per Yen Giapponese\n ");
    scanf("%d",&numero);

    printf("Inserisci gli euro che vuoi convertire: ");
    scanf("%f",&euro);
    printf("\n");

    

        switch(numero) {
            case 1 : printf("Soldi convertiti DOLLARO STATUNITENSE: %.2f", (float)euro*dollaro);
            break;
            case 2 : printf("Soldi convertiti CORONA CECA: %.2f", (float)euro*coronaCeca);
            break;
            case 3 : printf("Soldi convertiti DOLLARO GIAMAICANO: %.2f", (float)euro*dollaroGiamaicano);
            break;
            case 4 : printf("Soldi convertiti RUBLO RUSSO: %.2f", (float)euro*rubloRusso);
            break;
            case 5 : printf("Soldi convertiti WON SUD COREANO: %.2f", (float)euro*wonSudCoreano);
            break;
            case 6 : printf("Soldi convertiti STERLINA BRITANNICA: %.2f", (float)euro*sterlinaBritannica);
            break;
            case 7 : printf("Soldi convertiti YEN: %.2f", (float)euro*yenGiapponese);
            break;
            default : printf("Inserisci un nuemro valido");
                      
    }

    
 

}