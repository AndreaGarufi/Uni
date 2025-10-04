          ;Data   la sequenza di numeri 1,2,3,4,5,6,7,8 :
          ;I.     sommare a tutti i numeri la costante 10;
          ;II.    sommare i numeri ottenuti;
          ;III.   salvare il valore della somma in memoria

lista     dcd     1,2,3,4,5,6,7,8

dim       dcd     8

risultato fill    4

          mov     r1,#dim
          ldr     r1,[r1]

          mov     r2,#lista ;carico l'indirizzo del primo numero nella lista
ciclo     ldr     r3,[r2] ;in r3 carichi il valore puntato da r2 (primo numero della lista)

          add     r3,r3,#10 ; al valore corrente salvo 10
          add     r4,r4,r3 ;continene le somme dei numeri nella lista
          add     r2,r2,#4 ;mi sposto al prossimo numero della lista (uso r2 perché li ci sono gli indirizzi dei numeri e mi sposto di 4 byte)
          subs    r1,r1,#1 ;decremento il contatore di 1
          bgt     ciclo
          mov     r7,#risultato
          str     r4,[r7]