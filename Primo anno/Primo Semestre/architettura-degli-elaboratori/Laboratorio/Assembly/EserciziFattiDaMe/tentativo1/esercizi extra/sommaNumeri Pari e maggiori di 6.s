          ;data   la lista 1,3,5,6,7,9,10,12 fai la somma degli elementi pari e maggiori di 6 e salvare il risultato in memoria

lista     dcd     1,3,5,6,7,9,10,12
contatore equ     8
risultato fill    4

          mov     r1,#lista

          mov     r2,#contatore

ciclo     subs    r2,r2,#1
          blt     esci
          ldr     r4,[r1],#4
          and     r5,r4,#1
          cmp     r5,#1
          bge     ciclo
          cmp     r4,#6
          ble     ciclo
          add     r3,r3,r4
          b       ciclo



esci      mov     r10,#risultato
          str     r3,[r10]