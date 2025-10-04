          ;Supponiamo che tre studenti abbiamo eseguito 3 prove ognuna con voto da 18 a 30.
          ;Sommarei voti ottenuti dagli studenti per ogni prova e salvare il risultato in memoria.
          ;Lista: 1,20,20,20, 2,18,30,27, 3,22,26,28
          ;il     primo numero è id allievo (da saltare) poi devo sommare il primo numero con l'altro primo numero e poi di nuovo:
          ;es     20+18+22 20+30+26 20+27+28

          ;risultato [60; 76; 75]

lista     dcd     1,20,20,20, 2,18,30,27, 3,22,26,28
numero    equ     3
risultato fill    12

          mov     r1,#lista ;metto l'insirizzo della lista in r1
          mov     r2,#numero ;metto 3 in r2
          mov     r6,#0 ;alunno 1
          mov     r7,#0 ;alunno 2
          mov     r8,#0 ;alunno 3

ciclo     add     r1,r1,#4 ;salto l'id allievo
          ldr     r3,[r1] ;carico il valore dell'indirizzo di r1 in r3
          add     r6,r6,r3 ;sommo r3 a r6

          add     r1,r1,#4 ;mi sposto di un numero
          ldr     r3,[r1] ;carico il valore dell'indirizzo di r1 in r3
          add     r7,r7,r3 ;sommo r3 a r7

          add     r1,r1,#4 ;mi sposto di un numero
          ldr     r3,[r1] ;carico il valore dell'indirizzo di r1 in r3
          add     r8,r8,r3 ;sommo r3 a r8

          add     r1,r1,#4 ;salto l'id allievo
          subs    r2,r2,#1 ;decremento il contatore
          bgt     ciclo ;branch_if_greater_than_0

          mov     r10,#risultato ;metto l'indirizzo di risultato in r10
          str     r6,[r10] ;salvo r6 all'indirizzo puntato da r10, stessa cosa sotto

          add     r10,r10,#4
          str     r7,[r10]

          add     r10,r10,#4
          str     r8,[r10]

          end


