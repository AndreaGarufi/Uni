          ;sommarei numeri 2,3,4,1 e salvare in memoria il risultato

numa      DCD     9
numb      DCD     1


risultato fill    4
          ;leggiamo i dati
          mov     r1,#numa
          ldr     r1,[r1]

          mov     r2,#numb
          ldr     r2,[r2]


          ;facciamo le operazioni
          add     r3,r1,r2

          sub     r4,r1,r2


          ;salviamo il risultato in memoria

          end