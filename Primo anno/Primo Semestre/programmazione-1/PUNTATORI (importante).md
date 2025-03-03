CAPITOLO 7 LIBRO PAG 286

![[Pasted image 20241107223747.png]]
DEFINIZIONE  ![[Pasted image 20241107224314.png|200]]
cosi dichiaro un puntatore che punta all'indirizzo di memoria di una variabile intera



in questo modo sto dischiarando un puntatore e poi una variabile di tipo intero
![[Pasted image 20241107224346.png|200]]


**ASSEGANZIONE DI UN INDIRIZZO AD UN PUNTATO**
![[Pasted image 20241107224713.png]]


![[Pasted image 20241112141743.png]]

Posso riferirmi all'area puntata dal puntatore per modificare il valore della variabile a cui punta.
A = 2;
(asterisco)Aptr = 4 
printf A --> 4
I puntatori sono variabili che possono contenere solo indirizzi di memoria.

![[Pasted image 20241112143059.png]]
in questo modo passo un parametro per riferimento e nel main la variabile c effettivamente cambia il suo valore.


![[Pasted image 20241112144455.png]]

VALORI PRINTATI

000000DA233FF89C 
000000DA233FF89C 
7 
7 
000000DA233FF890

aptr = aptr +1; cosi incremento di 4 byte (4 per int, 8 per double ecc...) si usa per muoversi all'interno di un array (perché il nome dell'array è gia un indirizzo di memoria (il primo elemento) e quindi se mi sposto di 4 byte arrivo al secondo elemento( se l'array è un int))


*aptr = *aptr +1;       cosi incrementa l'indirizzo di memoria a cui punta 

![[Pasted image 20241112145632.png]]
(chiedere a chat cosa fa di preciso)


- Senza `*`, `puntatore + i` rappresenta l’indirizzo di memoria dell'elemento, quindi stampa un numero che rappresenta solo la posizione in memoria (non il valore in quella posizione).
- Con `*`, accedi al contenuto di quella posizione di memoria, ottenendo il **valore effettivo** che vuoi stampare.