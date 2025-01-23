          ;Eseguire l'operazione 20 + 10 - 15 e salvare il risultato in memoria, usando la pila e
          ;conservando i vecchi valori contenuti nei registri.

numa      dcd     20
numb      dcd     10
numc      dcd     15

risultato fill    4

          mov     r1,#30    ;simulo una pila
          mov     r2,#15
          mov     r3,#18
          mov     r4,#19
          mov     r5,#45
          mov     r6,#23
          mov     r7,#16    ;fin qua

          stmfd   sp!,{r1,r2,r0,r3,r4,r5,r6,r7} ;salva i registri sullo stack SP

          mov     r1,#0 ;qui svolgo la somma e dopo salvo in memoria
          mov     r2,#numa
          ldr     r2,[r2]
          mov     r3,#numb
          ldr     r3,[r3]
          mov     r4,#numc
          ldr     r4,[r4]

          add     r1,r2,r3
          sub     r1,r1,r4

          mov     r10,#risultato
          str     r1,[r10] ;fin qua

          ldmfd   sp!, {r0,r1,r2,r3,r4,r5,r6,r7}    ;carica i registri dallo stack SP 
          end