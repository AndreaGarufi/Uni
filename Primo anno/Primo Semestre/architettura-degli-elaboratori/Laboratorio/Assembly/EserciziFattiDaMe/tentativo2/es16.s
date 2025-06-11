          ;Moltiplicare i numeri 9,3
          ;sommo  il 9 3 volte in un ciclo
numa      equ     9
numb      equ     3
risultato fill    4

          mov     r1,#numa
          mov     r2,#numb

ciclo     add     r3,r3,r1
          subs    r2,r2,#1
          bgt     ciclo

          mov     r10,#risultato
          str     r3,[r10]
          end
