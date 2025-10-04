          ;Data   la lista [1,2,3,4,5,6,7,8,9,10]
          ;dimezzare tutti gli elementi. (sono divisioni intere)

lista     dcd     1,2,3,4,5,6,7,8,9,10              ;programma uguale a quello della moltiplicazione
contatore dcd     10

          mov     r1,#lista
          mov     r2,#contatore
          ldr     r2,[r2]

ciclo     subs    r2,r2,#1
          blt     esci
          ldr     r3,[r1]
          lsr     r3,r3,#1          ;l'unica differenza uso lsr anziché lsl perché cosi divido
          str     r3,[r1]
          add     r1,r1,#4
          b       ciclo


esci      end