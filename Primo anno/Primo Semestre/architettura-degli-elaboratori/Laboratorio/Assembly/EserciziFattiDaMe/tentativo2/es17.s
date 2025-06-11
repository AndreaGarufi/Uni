          ;       Eseguire la divisione 231 / 13
          ;e      salvare il risultato e il resto


numa      equ     231
numb      equ     13
risultato fill    8

          mov     r1,#numa
          mov     r2,#numb
          mov     r3,#0

ciclo     cmp     r1,r2 ;comparo il numero con il 13 cosi vedo se posso ancora fare sottrazioni (inizia con 231 poi continua sempre con numeri più piccoli)
          blt     esci ;se r1 è più piccolo di 13 esco (quello che resta di r1 è il resto della divisione)
          sub     r1,r1,r2 ;altrimenti vado qui e sottraggo a r1,r1-13
          add     r3,r3,#1 ;aumento il contatore del risultato (quante volte ci sta il 13 nel 231)
          b       ciclo ;salto a ciclo



esci      mov     r10,#risultato
          str     r3,[r10] ;risultato della divisione

          add     r10,r10,#4
          str     r1,[r10] ;resto della divisione
          end
