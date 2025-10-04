/* I guidatori sono interessati al consumo offerto dalle loro automobili. Un guidatore ha tenuto traccia dei vari pieni di carburante,
 registrando i KM percorsi e i litri consumati per ciascun pieno. 
Realizzare un programma che richiede di inserire i KM percorsi e i litri consumati per ogni pieno.
 Il programma deve calcolare e stampare i KM per litro per ciascun pieno. Dopo aver processato tutte le informazioni di input,
il programma deve calcolare e stampare i KM complessivi per litro percorsi per tutti i pieni.*/

#include <stdio.h>
int main(){

float pieno = 0,KM = 0, litri = 0;
float kmSuLitro = 0;

printf("inserisci i litri del pieno e i KM fatti \n");
scanf("%d",&litri);
printf("\n");
scanf("%d",&KM);

kmSuLitro = KM / litri;

printf("I km al litro sono: %.2f", kmSuLitro);

}