          ;       somma di N elementi tramite registri

lista     dcd     1,2,3,4,5,6,7,8,9,10
dim       equ     10
risultato fill    4

          mov     r1,#dim
          mov     r2,#lista
          bl      somma
          mov     r1,#risultato
          str     r3,[r1]
          end

somma     stmfd   sp!,{r4}
          mov     r3,#0 ; clear
ciclo     subs    r1,r1,#1
          blt     esci
          ldr     r4,[r2],#4
          add     r3,r3,r4
          b       ciclo

esci      ldmfd   sp!,{r4}
          mov     pc,lr



