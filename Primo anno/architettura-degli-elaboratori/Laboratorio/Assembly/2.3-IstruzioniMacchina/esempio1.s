lista      dcd     10
costante   equ     30

           mov     r1,#lista
           ldr     r1,[r1]
           bl      sommatoria
           mov     r3,#1
           end

sommatoria add     r1,r1,#costante
           mov     pc,lr
