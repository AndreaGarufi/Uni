lista     dcd     1,2,3,4,5,6,7,8,9,10
contatore equ     10
risultato fill    4

          mov     r1,#lista
          mov     r2,#contatore

ciclo     ldr     r3,[r1] ;carico in r3 il valore dell'indirizzo di r1
          cmp     r3,#5 ;comparo con il 5 per vedere se è maggiore
          bgt     maggiore ;se il risultato di prima è maggiore di 0 (numeri da 6 in su) salta a maggiore
          add     r1,r1,#4
          subs    r2,r2,#1
          bgt     ciclo
          b       salva

maggiore  and     r4,r3,#1 ;faccio l'and tra il numero corrente e 1 per vedere se è dispari (comparo l'ultimo bit del numero che se è pari è 0 altrimenti e 1)
          cmp     r4,#0 ;comparo il risultato dell'and con 1 (fa una sottrazione implicita) se è uguale a 0 (1-1) salta a somma altriemnti va sotto
          bgt     somma ;branch_if_equal_to_0
          add     r1,r1,#4 ;mi sposto all'altro numero
          subs    r2,r2,#1 ;decremento il contatore
          bgt     ciclo
          b       salva


somma     add     r5,r5,#1 ;aumento di 1 il contatore
          add     r1,r1,#4 ;mi spoto al prossimo numero
          subs    r2,r2,#1 ;decremento il contatore
          bgt     ciclo

salva     mov     r10,#risultato
          str     r5,[r10] ;salvo in memoria
          end