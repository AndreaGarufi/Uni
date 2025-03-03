/*(Lancio dei dadi) Scrivete un programma che simuli il lancio di due dadi. 
Il programma deve usare due volte rand per lanciare, rispettivamente, il primo dado e il secondo dado. 
Poi deve calcolare la somma dei due valori. 
[Nota: poiché ogni dado può mostrare sulla faccia superiore un valore intero da 1 a 6, 
la somma dei due valori varierà allora da 2 a 12, con 7 che è la somma più frequente e 2 e 12 che sono le somme meno frequenti.] 
La Figura 6.24 mostra 36 possibili combinazioni dei due dadi. Il vostro programma deve lanciare i due dadi 36.000 volte. 
Usate un array unidimensionale per annotare il numero delle volte in cui compare ogni possibile somma. Stampate i risultati in un formato tabellare. 
Stabilite inoltre se i totali sono ragionevoli; cioè, vi sono sei modi di ottenere un risultato 7, così, approssimativamente,
un sesto di tutti i lanci deve avere come somma 7.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){

srand(time(NULL));
int array[13] = {0};

for(int i = 0; i < 36000; i++){

    int dado1 = 1 +rand() % 6;
    int dado2 = 1 + rand() % 6;

    int somma = dado1 + dado2;
    array[somma]++;
}
for(int i = 0; i < 13; i++){

printf("%d ",array[i]);


}



}