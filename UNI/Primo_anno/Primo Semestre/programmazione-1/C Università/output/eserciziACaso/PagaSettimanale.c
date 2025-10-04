/*4.28 (Calcolo della paga settimanale)
Un'azienda paga i suoi impiegati come manager (che ricevono una retribuzione fissa settimanale), 
come lavoratori a ore (che ricevono una paga fissa all'ora per le prime 40 ore e "una volta e mezza" (
cioè 1,5 volte la loro paga all'ora ) per lo straordinario), 
lavoratori con provvigione (che ricevono $250 più il 5,7% delle loro vendite settimanali lorde) o 
lavoratori a cottimo (che ricevono una quantità fissa di denaro per ogni articolo che producono; 
ogni lavoratore a cottimo di questa azienda lavora esclusivamente su un solo tipo di articolo).

Scrivete un programma per calcolare la paga settimanale di ogni impiegato. 
Non conoscete in anticipo il numero degli impiegati. 
Ogni tipo di impiegato ha il proprio codice paga: i manager hanno il codice paga 1, i lavoratori a ore il 2, i lavoratori a provvigione il 3 
e i lavoratori a cottimo il 4. Usate uno switch per calcolare la paga di ogni impiegato in base al codice paga di quell’impiegato.

All'interno dello switch, richiedete all'utente (ossia, all'impiegato che si occupa dei libri paga) 
di inserire i dati appropriati necessari al vostro programma per calcolare la paga di ogni impiegato in base al suo codice paga.
(Nota: potete inserire valori di tipo double usando lo specificatore di conversione %lf con scanf.)*/

//ho un while per inserire i dipendenti e dentor il while c'è lo switch

#include <stdio.h>

int main(){

    int codice = 0;

    const int MENAGERPAGA = 500;
    const int LAVORATOREPAGA = 20;
    const int PROVVIGIONEPAGA = 250;
    const int COTTIMOPAGA = 35;
    int ore = 0,orePaga = 0,sett = 0,produzione = 0,pagatotCottimo = 0;
    float pagaStraordinario = 0,pagatotOre = 0,pagatotProvvigione,pagaLorda = 0,vendite = 0;

    while(codice != 5){

        printf("\nInserisci il codice lavoratore\n");

        scanf("%d",&codice);

        switch(codice){

            case 1: printf("MENAGER\n");

                printf("Inserisci le settimane di lavoro ");
                scanf("%d",&sett);

                sett = sett * MENAGERPAGA;
                                
                printf("la paga del menager e': %d\n",sett);


            break;

            case 2: printf("LAVORATORI A ORE\n");  

                printf("inserisci il monteore del lavoratore: \n");
                scanf("%d",&orePaga);

                ore = orePaga - 40;

                if(ore > 0){

                    pagaStraordinario = (LAVORATOREPAGA *1.5) * ore; 

                    printf("ore straordinario: %.2f --",pagaStraordinario);
                }
                pagatotOre = (LAVORATOREPAGA * 40) + pagaStraordinario;

                printf(" La paga TOTALE e': %.2f",pagatotOre);
 
            break;

            case 3: printf("LAVORATORI A PROVVIGIONE\n");

                printf("Inserisci il totale delle vendite lorde\n");
                scanf("%f",&vendite);

                pagaLorda = (5.7 / 100) * vendite;
                pagatotProvvigione = PROVVIGIONEPAGA + pagaLorda;

                printf(" La paga TOTALE e': %.2f",pagatotProvvigione);

                
            break;

            case 4: printf("LAVORATORI A COTTIMO\n");

                printf("Inserisci il totale degli articoli prodotti\n");
                scanf("%d",&produzione);

                pagatotCottimo = COTTIMOPAGA * produzione;

                printf(" La paga TOTALE e': %d",pagatotCottimo);


                
            break;  

            default: printf("Inserisci un numero valido\n");
            break;          
        }



        
    }


}

