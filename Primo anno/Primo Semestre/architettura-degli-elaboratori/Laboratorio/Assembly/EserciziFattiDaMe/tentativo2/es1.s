          ;Sommarei numeri 2,3,4,1 e salvare in memoria il risultato

risultato fill    4     ;riservo 4 byte in memoria 

          mov     r1,#2 ;metto i numeri dentro i registri come valore immediato
          mov     r2,#3
          mov     r3,#4
          mov     r4,#1

          add     r5,r1,r2      ;sommo facendo 2 somme parziali e poi metto in r7
          add     r6,r3,r4
          add     r7,r5,r6

          mov     r10,#risultato    ;metto l'indirizzo (in memoria) di risultato dentro r10
          str     r7,[r10]  ;salvo il valore di r7 dentro il valore puntato da r10