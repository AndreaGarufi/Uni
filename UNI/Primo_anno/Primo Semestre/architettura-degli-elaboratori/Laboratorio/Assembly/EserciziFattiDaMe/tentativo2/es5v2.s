lista     dcd     1,20,20,20, 2,18,30,27, 3,22,26,28
numero    equ     12
risultato fill    12

          mov     r1,#lista
          mov     r2,#numero

          mov     r5,#0
          mov     r6,#0
          mov     r7,#0

ciclo     add     r1,r1,#4
          ldr     r3,[r1]
          add     r5,r5,r3
          sub     r2,r2,#1
          add     r1,r1,#4

          ldr     r3,[r1]
          add     r6,r6,r3
          sub     r2,r2,#1
          add     r1,r1,#4
          ldr     r3,[r1]
          add     r7,r7,r3
          sub     r2,r2,#1

          add     r1,r1,#4
          subs    r2,r2,#1
          bgt     ciclo

          mov     r10,#risultato
          str     r5,[r10]

          add     r10,r10,#4
          str     r6,[r10]
          add     r10,r10,#4
          str     r7,[r10]
          end
