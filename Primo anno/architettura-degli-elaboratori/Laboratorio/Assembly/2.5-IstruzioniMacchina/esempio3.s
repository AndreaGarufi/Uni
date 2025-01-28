          ;Moltiplicare i numeri 9 x 3
;Questo programma moltiplica il 9 x 3 sommando 9 3 volte
costanteA equ     9
costanteB equ     3
risultato fill    4

          mov     r3,#0 ; risultato della moltiplicazione
          mov     r1,#costanteA ;9
          mov     r2,#costanteB ;3

ciclo     subs    r2,r2,#1  ;decremento il 3
          blt     esci  ;se è minore di 0 esco
          add     r3,r3,r1  ;sommo il 9 (3 volte cosi faccio 9x3)
          b       ciclo

esci      mov     r1,#risultato 
          str     r3,[r1]   ;salvo il risultato


