          ;       Eseguire la divisione 231 / 13
          ;e      salvare il risultato e il resto

costanteA equ     231
costanteB equ     13
risultato fill    8

          mov     r1,#costanteA
          mov     r2,#costanteB
          mov     r3,#risultato
          mov     r4,#0
ciclo     cmp     r1,r2 ;comparo 231 e 13
          blt     esci  ;se la sottrazione viene minore di 0 esco
          subs    r1,r1,r2  ;r1-r2 e salvo in r1 (231 - 13 ecc...)
          add     r4,r4,#1  ;conto quante volte ho sottratto il 13 a 231 (cosi ottengo il resto)
          b       ciclo 

esci      str     r4,[r3]   ;salvo
          str     r1,[r3,#4];salvo nei 4 byte successivi


