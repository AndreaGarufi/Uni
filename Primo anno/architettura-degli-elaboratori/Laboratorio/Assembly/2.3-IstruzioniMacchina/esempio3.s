           ;       somma di N numeri utilizzando la pila

lista      dcd     1,2,3,4,5,6,7,8,9,10
dim        equ     10
risultato  fill    4

           mov     r1,#dim
           stmfd   sp!,{r1}
           mov     r1,#lista
           stmfd   sp!,{r1}
           bl      sommatoria
           ldmfd   sp!,{r3}
           mov     r1,#risultato
           str     r3,[r1]
           end

sommatoria stmfd   sp!,{r1,r2,r3,r4}
           ldr     r1,[sp,#16] ;indirizzo
           ldr     r2,[sp,#20] ;dimensione
           mov     r3,#0
ciclo      subs    r2,r2,#1
           blt     esci
           ldr     r4,[r1],#4
           add     r3,r3,r4
           b       ciclo
esci       str     r3,[sp,#16]
           ldmfd   sp!,{r1,r2,r3,r4}
           mov     pc,lr



