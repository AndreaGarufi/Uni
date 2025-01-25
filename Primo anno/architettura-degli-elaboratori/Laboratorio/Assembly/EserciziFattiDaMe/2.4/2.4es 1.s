          ;Data   la lista [1,2,3,4,5,6,7,8,9,10] moltiplicazione ogni elemento x2.

lista     dcd     1,2,3,4,5,6,7,8,9,10
contatore dcd     10

          mov     r1,#lista
          mov     r2,#contatore
          ldr     r2,[r2]

ciclo     subs    r2,r2,#1
          blt     esci
          ldr     r3,[r1]
          lsl     r3,r3,#1
          str     r3,[r1]
          add     r1,r1,#4
          b       ciclo

esci      end

