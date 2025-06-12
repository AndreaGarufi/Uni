          ;Data   la lista [-10,4,23,50,0,40,10,7] trovare il minimo e salvare il risultato in memoria

lista     dcd     -10,4,23,50,0,40,10,7
contatore equ     8
risultato fill    4

          mov     r1,#lista
          mov     r2,#contatore
          ldr     r3,[r1]       ;carico il primo numero in r3
          add     r1,r1,#4      
          sub     r2,r2,#1

ciclo     ldr     r4,[r1]
          add     r1,r1,#4
          cmp     r4,r3
          blt     minimo
          subs    r2,r2,#1
          bgt     ciclo
          b       salva



minimo    mov     r3,r4
          subs    r2,r2,#1
          bgt     ciclo

salva     mov     r10,#risultato
          str     r3,[r10]
          end