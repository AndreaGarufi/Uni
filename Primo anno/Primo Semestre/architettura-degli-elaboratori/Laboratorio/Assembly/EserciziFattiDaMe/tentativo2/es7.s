          ;Data   la lista 1,24,12,8,10,1,4,21,3,1,5,1
          ;contareil numero di volte che compare in memoria il valore 1 e salvare il risultato in memoria.

lista     dcd     1,24,12,8,10,1,4,21,3,1,5,1
contatore equ     12
risultato fill    4

          mov     r1,#lista ;metto in r1 l'indirizzo della lista
          mov     r2,#contatore ;metto in r2 il contatore

ciclo     ldr     r3,[r1] ;carico in r1 il primo numero della lista
          cmp     r3,#1 ;comparo r3 con 1
          beq     trovato ;branch_if_equal_to_0

          add     r1,r1,#4 ;se non è 1 va qui, in cui mi sposto al prossimo numero
          subs    r2,r2,#1 ;decremento il contatore di 1
          bgt     ciclo ;branch_if_greater_than_0

          mov     r10,#risultato ;metto in r10 l'indirizzo di risultato
          str     r4,[r10] ;salvo r4 all'indirizzo puntato da r10
          end

trovato   add     r4,r4,#1 ;aumento il contatore degli 1 presenti
          add     r1,r1,#4 ;mi sposto al prossimo numero
          b       ciclo ;salto incondizionatamente a ciclo

