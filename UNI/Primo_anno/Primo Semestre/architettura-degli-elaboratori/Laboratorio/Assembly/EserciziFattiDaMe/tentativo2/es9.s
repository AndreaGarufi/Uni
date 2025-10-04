          ;Data   la lista [1,2,3,4,5,6,7,8,9,10] moltiplicazione ogni elemento x2

lista     dcd     1,2,3,4,5,6,7,8,9,10
contatore equ     10

          mov     r2,#contatore
          mov     r1,#lista

ciclo     ldr     r3,[r1] ;carico dentro r3 il valore dell'indirizzo di r1
          lsl     r4,r3,#1 ;eseguo la moltiplicazione con logic shift left di 1 bit cosi moltiplico x2 (aggiunge uno 0 all'inizio del numero)
          str     r4,[r1] ;salvo il valore moltiplicato dentro la lista
          add     r1,r1,#4 ;mi sposto al prossimo numero
          subs    r2,r2,#1 ;decremento il contatore
          bgt     ciclo ;branch_if_greater_than_0

          end
