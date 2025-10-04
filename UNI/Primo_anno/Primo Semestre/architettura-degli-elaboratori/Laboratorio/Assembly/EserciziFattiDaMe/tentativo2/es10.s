          ;Data   la lista [1,2,3,4,5,6,7,8,9,10] dimezzare tutti gli elementi

lista     dcd     1,2,3,4,5,6,7,8,9,10
contatore equ     10

          mov     r1,#lista
          mov     r2,#contatore ;identico all'esercizio 9

ciclo     ldr     r3,[r1]
          lsr     r4,r3,#1 ;logic shitf right per dividere per 2
          str     r4,[r1]
          add     r1,r1,#4
          subs    r2,r2,#1
          bgt     ciclo
          end