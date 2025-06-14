          ;Data   la lista [1,2,3,4,5,6,7,8,9,10] sommare tutti i numeri pari e minori di 8 e salvare il risultato in memoria.

lista     dcd     1,2,3,4,5,6,7,8,9,10
contatore equ     10
risultato fill    4

          mov     r1,#lista
          mov     r2,#contatore

ciclo     ldr     r3,[r1] ;inizia il ciclo carico dentro r3 il valore dell'indirizzo di r1
          cmp     r3,#8 ;comparo per vedere se è più piccolo di 8
          blt     minore ;branch_if_lower_than_0
          add     r1,r1,#4 ;mi sposto
          subs    r2,r2,#1 ;decremento
          bgt     ciclo


          mov     r10,#risultato ;zona in cui salvo
          str     r5,[r10]
          end

minore    and     r4,r3,#1 ;faccio l'and per vedere se è pari
          cmp     r4,#1 ;comparo cosi so se è pari
          blt     somma ;branch_if_lower_than_0 se è pari va a somma (per via della sottrazone implicita del cmp)
          add     r1,r1,#4
          subs    r2,r2,#1
          bgt     ciclo

          mov     r10,#risultato ;zona in cui salvo
          str     r5,[r10]
          end


somma     add     r5,r5,r3 ;sommo i numeri pari minori di 8
          add     r1,r1,#4
          subs    r2,r2,#1
          bgt     ciclo

          mov     r10,#risultato ;zona in cui salvo
          str     r5,[r10]
          end