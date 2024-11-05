## **SCAMBIO DI NUMERI**
Per scambiare 2 numeri ho bisogno di una terza variabile temporanea:
![[Pasted image 20241011134142.png|300]]



Stampa le prime n+1 potenze del numero 2



## **BUBBLE SORT PER ORDINARE GLI ELEMENTI DI UN ARRAY**

La Figura 6.15 ordina i valori negli elementi di un array a di 10 elementi (riga 10) in ordine crescente. La tecnica che usiamo è chiamata bubble sort (letteralmente “ordinamento a bolle”) o sinking sort (letteralmente “ordinamento per affondamento”), perché i valori più piccoli sal- gono verso la cima dell’array a poco a poco “come bolle”, come le bolle d’aria che si formano nell’acqua, mentre i valori più grandi scendono verso il fondo dell’array. La tecnica consiste nell’effettuare diverse passate lungo l’array. A ogni passata vengono confrontate le successive coppie di elementi (l’elemento 0 e l’elemento 1, poi l’elemento 1 e l’elemento 2, ecc.). Se una coppia è in ordine crescente (o se i valori sono identici), si lasciano i valori come sono. Se una coppia è in ordine decrescente, i valori vengono scambiati nell’array.

1 // Fig. 6.15: fig06_15.c 
2 // Ordinare i valori di un array in ordine crescente. 
3 #include <stdio.h> 
4 #define SIZE 10 
5 
6 // la funzione main inizia l'esecuzione del programma 
7 int main(void) 
8 { 
9 // inizializza a 10 int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37}; 
11 
12 puts("Data items in original order"); 
13  
14 // stampa l'array originario 
15 for (size_t i = 0; i < SIZE; ++i) { 
16 printf("%4d", a[i]); 
17 } 
18 
19 // bubble sort 
20 // ciclo per il numero di passate 
21 for (unsigned int pass = 1; pass < SIZE; ++pass) { 
22 
23 // ciclo per il numero di confronti a ogni passata 
24 for (size_t i = 0; i < SIZE – 1; ++i) { 
25 
26 // confronta due elementi adiacenti e scambiali se il primo 
27 // elemento e' maggiore del secondo elemento 
28 if (a[i] > a[i + 1]) { 
29 int hold = a[i]; 
30 a[i] = a[i + 1]; 
31 a[i + 1] = hold; 
32 } 
33 } 
34 } 
35 
36 puts("\nData items in ascending order"); 
37 
38 // stampa l'array ordinato 
39 for (size_t i = 0; i < SIZE; ++i) { 
40 printf("%4d", a[i]); 
41 } 
42 
43 puts(""); 
44 }

(STAMPA DELL'ESERCIZIO)
![[Pasted image 20241105114445.png]]
Figura 6.15 Ordinare i valori di un array in ordine crescente. Dapprima il programma confronta a[0] e a[1], poi a[1] e a[2], quindi a[2] e a[3], e così via, finché completa la passata confrontando a[8] e a[9]. Benché vi siano 10 elementi, sono eseguiti solo nove confronti. Per via del modo in cui sono fatti i successivi confronti, un valore grande si può muovere in giù lungo l’array di molte posizioni in una singola passata, ma un valore piccolo si può muovere in su solo di una posizione. Alla prima passata è garantito che il valore più grande scenda giù fino all’elemento che sta al fondo dell’array, a[9]. Alla seconda passata è garantito che il secondo valore più grande scenda giù fino ad a[8]. Alla nona passata il nono valore più grande scende fino ad a[1]. Questo lascia il valore più piccolo in a[0], così, pur essendovi dieci elementi, sono necessari solo nove passate per ordinare l’array.

L’ordinamento è eseguito dai cicli annidati for (righe 21–34). Se è necessario uno scambio, questo è eseguito con le tre assegnazioni
![[Pasted image 20241105114703.png]]
dove la variabile extra hold memorizza temporaneamente uno dei due valori da scambiare. Lo scambio non può essere eseguito con le sole due assegnazioni
![[Pasted image 20241105114731.png]]
Se, ad esempio, a[i] è 7 e a[i + 1] è 5, dopo la prima assegnazione entrambi i valori saranno 5 e il valore 7 sarà perduto. Da qui la necessità di una variabile extra hold. Il principale pregio del bubble sort consiste nella facilità di programmarlo. Tuttavia, esso opera lentamente, poiché ogni scambio sposta un elemento solo di una posizione verso la sua destina- zione finale. Questo risulta evidente quando si ordinano array grandi. Negli esercizi esamineremo versioni più efficienti del bubble sort. Sono state sviluppate tecniche di ordinamento di gran lunga più efficienti del bubble sort. Analizzeremo altri algoritmi nell’Appendice D. I corsi più avanzati di informatica analizzano più approfonditamente l’ordinamento e la ricerca di elementi in array.

## **INVERTIRE I NUMERI USANDO ARRAY**
![[Pasted image 20241105120250.png]]
in pratica scorro l'array al contrario e lo stampo