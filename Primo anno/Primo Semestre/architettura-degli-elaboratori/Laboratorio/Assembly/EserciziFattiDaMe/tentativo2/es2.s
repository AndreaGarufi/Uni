          ;Effettua le due operazioni: 9 + 1 e 9 – 1 e salvare in memoria il risultato

risultato fill    8

numa      dcd     9

          mov     r1,#numa ;muovo in r1 l'indirizzo in cui si trova numa
          ldr     r2,[r1] ;carico in r2 il valore contenuto in r1 (cioè l'indirizzo di memoria in cui c'è il 9)

          add     r3,r2,#1 ;sommo 9+1
          sub     r4,r2,#1 ;sottraggo 9-1

          mov     r10,#risultato ;metto in r10 l'indirizzo di risultato
          str     r3,[r10] ;salvo il valore di r3
          add     r10,r10,#4 ;mi sposto di 4 byte (un intero) in r10 cosi salvo anche l'altro numero
          str     r4,[r10] ;salvo il valore di r3
          end     ;fine programma

