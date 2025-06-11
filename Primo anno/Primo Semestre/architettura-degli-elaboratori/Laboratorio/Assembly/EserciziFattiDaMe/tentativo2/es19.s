          ;Data   la lista [-10,4,23,50,0,40,10,7] sommare i numeri pari e salvare il risultato in memoria.

lista     dcd     -10,4,23,50,0,40,10,7
contatore equ     8
risultato fill    4

          mov     r1,#lista
          mov     r2,#contatore
          mov     r3,#0 ;registro somma

ciclo     ldr     r4,[r1] ;carico il numero in r4
          and     r5,r4,#1 ;faccio l'and per vedere se è pari
          cmp     r5,#0 ;comparo con lo 0
          beq     sommaPari ;branch_if_equal_to_0
          add     r1,r1,#4 ;mi sposto
          subs    r2,r2,#1;decremento
          bgt     ciclo ;branch_if_greater_than_0
          b       salva


sommaPari 
          add     r3,r3,r4 ;qui faccio la somma, mi sposto,decremento e salto a ciclo altriemnti vado a salva
          add     r1,r1,#4
          subs    r2,r2,#1
          bgt     ciclo


salva     mov     r10,#risultato
          str     r3,[r10]
          end
