          ;Supponiamo che tre studenti abbiamo eseguito 3 prove ognuna con voto da 18 a 30. Sommare i voti
          ;ottenuti dagli studenti per ogni prova e salvare il risultato in memoria.
          ;Lista: 1,20,20,20, 2,18,30,27, 3,22,26,28

lista     dcd     1,20,20,20, 2,18,30,27, 3,22,26,28
risultato fill    12
contatore dcd     3

          mov     r1,#lista ;carico il primo elemento nella lista (1)
          mov     r2,#contatore
          mov     r10,#risultato

ciclo     add     r1,r1,#4  ;mi sposto di 1 nella lista perche 1,2,3 sono gli id dello studente 
          ldr     r3,[r1]   ;carico il valore puntato da r1 (20 al primo ciclo)
          add     r4,r4,r3  ;faccio la somma

          add     r1,r1,#4  ;mi sposto di 1
          ldr     r3,[r1]
          add     r5,r5,r3

          add     r1,r1,#4  ;mi sposto di 1
          ldr     r3,[r1]
          add     r6,r6,r3

          add     r1,r1,#4  ;mi devo rispostare di 1 perché altrimenti andrei a puntare al 2 (id)

          subs    r2,r2,#1 ; decremento il contatore

          bgt     ciclo ;se il contatore è minore o uguale di 0 esce dal ciclo altrimenti lo ripete

          str     r4,[r10]  ;salvo
          str     r5,[r10,#4]   ;salvo spostandomi di 4 byte
          str     r6,[r10,#8]   ;salvo spostandomi di 8 byte