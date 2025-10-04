          ;Data   la lista 1,24,12,8,10,1,4,21,3,1,5,1 sommare i numeri maggiori (o uguali) di x con x = 10

lista     dcd     1,24,12,8,10,1,4,21,3,1,5,1
contatore equ     12
risultato fill    4

          mov     r1,#lista
          mov     r2,#contatore

ciclo     ldr     r3,[r1] ;inizia il ciclo carico in r3 il valore dell'indirizzo in r1
          cmp     r3,#10 ;comparo il numero corrente con 10
          bge     somma ;branch_if_greater_or_equal_to_0
          add     r1,r1,#4 ;mi sposto al prossimo numero
          subs    r2,r2,#1 ;decremento il contatore
          bgt     ciclo ;branch_if_greater_than_0

          mov     r10,#risultato
          str     r4,[r10] ;salvo il risultato di r4 all'indirizzo puntato da r10
          end

somma     add     r4,r4,r3 ;sommo i numeri che sono maggiori o uguali di 0
          add     r1,r1,#4 ;mi sposto al prossimo numero
          subs    r2,r2,#1 ;decremento il contatore
          bgt     ciclo ;branch_if_greater_than_0

