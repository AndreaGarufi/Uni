          ;Data   la sequenza di numeri 1,2,3,4,5,6,7,8 :
          ;I.     sommare a tutti i numeri la costante 10
          ;II.    sommare i numeri ottenuti
          ;III.   salvare il valore della somma in memoria.


lista     dcd     1,2,3,4,5,6,7,8
contatore equ     8
risultato fill    4

          mov     r1,#lista ;carico l'indirizzo della lista
          mov     r2,#contatore

ciclo     ldr     r3,[r1]   ;carico il primo numero
          add     r3,r3,#10 ;aggiungo 10
          add     r4,r4,r3  ;faccio le somme dei numeri della lista
          add     r1,r1,#4  ;mi sposto al prossimo numero
          subs    r2,r2,#1  ;decremento
          bgt     ciclo     ;branch_if_greater_than_0 to ciclo


          mov     r10,#risultato    ;salvo
          str     r4,[r10]
          end