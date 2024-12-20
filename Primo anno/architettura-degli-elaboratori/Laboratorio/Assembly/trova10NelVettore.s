          ;trovareil valore 10 della lista seguente
          ;1,24,12,8,10,1,4,21,3,1,5,1
          ;una    volta trovato salvare l'indirizzo in memoria
          ;se     non si trova il 10 salvare -1

lista     dcd     1,24,12,8,1,1,4,21,3,1,5,1
dim       dcd     12
risultato fill    4
costante  equ     10 ; variabile

          mov     r1,#dim
          ldr     r1,[r1]

          mov     r2,#lista

ciclo     ldr     r3,[r2]
          cmp     r3,#costante ;o anche r3,#10 senza dichiarare la variabile

          beq     found ;etichetta found (la posso chiamare come voglio cosi come ciclo)
          add     r2,r2,#4
          subs    r1,r1,#1
          bgt     ciclo
          mov     r10,#risultato
          mov     r2,#-1
          str     r2,[r10]
          end


found     mov     r10,#risultato
          str     r2,[r10]


