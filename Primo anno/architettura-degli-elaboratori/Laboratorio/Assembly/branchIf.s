          ;sommarei numeri 1 2 3 4 e salvare in memoria

lista     dcd     1,2,3,4
dim       dcd     4
risultato fill    4

          mov     r1,#dim
          ldr     r1,[r1]
          mov     r2,#lista

          mov     r4,#0
ciclo     ldr     r3,[r2]

          add     r4,r4,r3
          add     r2,r2,#4
          subs    r1,r1,#1
          bgt     ciclo ;branch if (greater than)

          mov     r7,#risultato
          str     r4,[r7]
