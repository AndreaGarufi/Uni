       ;       Data la lista [1,2,3,4,5,6,7,8,9,10]
       ;sommaretutti i numeri pari e minori di 8 e
       ;salvareil risultato in memoria.

lista  dcd     1,2,3,4,5,6,7,8,9,10
dim    equ     10
ris    fill    4

       mov     r1,#lista ;carico l'indirizzo del primo elemento della lista
       mov     r2,#dim ;carico il valore della costante (10)
       mov     r3,#0 ;inizializzo a 0
ciclo  subs    r2,r2,#1 ;decremento il contatore e inizio il ciclo
       blt     esci ;se il risultato precedente è minore di 0 salta ad esci
       ldr     r4,[r1],#4 ;carico il primo elemento e al prossimo ciclo si sposterà di 4 byte
       and     r5,r4,#1 ;and logico con 1 per vedere se il numero è pari o dispari
       cmp     r5,#1 ;compara il valore dell'and (0 o 1) con 1 per vedere se è pari
       beq     ciclo ;se il risultato precedente è uguale a 0 salta a ciclo (se è un numero dispari quindi)
       cmp     r4,#8 ;se sono qui il numero è pari e devo controllare se è maggiore di 8
       bge     ciclo ;salta a ciclo se il risultato precedente è maggiore o uguale a 0 (quindi 8 > numero)
       add     r3,r3,r4 ;altrimenti sommo il numero agli altri
       b       ciclo ;salto incondizionatamente a ciclo
esci   mov     r1,#ris
       str     r3,[r1] ;salvo il risultato

