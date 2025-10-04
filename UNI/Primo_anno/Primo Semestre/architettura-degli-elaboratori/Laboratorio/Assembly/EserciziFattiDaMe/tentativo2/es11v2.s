          ;Data   la lista [1,2,3,4,5,6,7,8,9,10] contare tutti i numeri dispari e maggiori di 5 e salvare il risultato in memoria


lista     dcd     1,2,3,4,5,6,7,8,9,10
contatore equ     10
risultato fill    4

          mov     r1,#lista
          mov     r2,#contatore

ciclo     ldr     r3,[r1]
          cmp     r3,#5
          bgt     maggiore
          add     r1,r1,#4
          subs    r2,r2,#1
          bgt     ciclo
          b       salva


maggiore  and     r4,r3,#1
          cmp     r4,#1
          beq     conta
          add     r1,r1,#4
          subs    r2,r2,#1
          bgt     ciclo
          b       salva


conta     add     r5,r5,#1
          add     r1,r1,#4
          subs    r2,r2,#1
          bgt     ciclo
          b       salva


salva     mov     r10,#risultato
          str     r5,[r10]
          end