           ;       somma di N numeri utilizzando la pila

lista      dcd     1,2,3,4,5,6,7,8,9,10
dim        equ     10
risultato  fill    4

           mov     r1,#dim ;carico in r1 la costante dim (cioé 10)
           stmfd   sp!,{r1} ;carico sul SP r1 (cioé 10)
           mov     r1,#lista ;carico su r1 l'indirizzo del primo numero della lista (cioé 1)
           stmfd   sp!,{r1} ;carico sul SP r1 cioé l'indirizzo di 1
           bl      sommatoria ;chiamo sommatoria
           ldmfd   sp!,{r3}
           mov     r1,#risultato
           str     r3,[r1]
           end

sommatoria stmfd   sp!,{r1,r2,r3,r4} ;carico sul SP i valori di r1,r2,r3,r4 (cioé di nuovo l'indirizzo di 1 e poi tre 0 (gli altri registri sono vuoti))
           ldr     r1,[sp,#16] ;indirizzo CHIARIRE QUESTE 2 RIGHE
           ldr     r2,[sp,#20] ;dimensione FDFD
           mov     r3,#0
ciclo      subs    r2,r2,#1
           blt     esci
           ldr     r4,[r1],#4
           add     r3,r3,r4
           b       ciclo
esci       str     r3,[sp,#16]
           ldmfd   sp!,{r1,r2,r3,r4}
           mov     pc,lr



