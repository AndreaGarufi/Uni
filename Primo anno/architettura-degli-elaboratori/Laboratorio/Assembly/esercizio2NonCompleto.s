          ;sommarei numeri 9 + 1 e 9 - 1 e salvare in memoria il risultato

numa      equ     9
numb      equ     1


risultati fill    8 ;alloca 8 byte per i risultati
          ;leggiamo i dati
          mov     r1,#numa

          mov     r2,#numb

          ;facciamo le operazioni
          add     r3,r1,r2

          sub     r4,r1,r2


          ;salviamo il risultato in memoria
          mov     r5,#risultati
          str     r3,[r5]
          str     r4,[r5,#4] ;indirizzamento con spiazzamento (mi sposto di #4 byte nel registro cosi salvo il secondo valore)

          end