          ;Data   la lista
          ;1,24,12,8,10,1,4,21,3,1,5,1
          ;trovareil valore 10 e salvare in memoria l’indirizzo corrispondente. Se non viene trovato
          ;salvare-1.

lista     dcd     1,24,12,8,10,1,4,21,3,1,5,1
contatore dcd     12
risultato fill    4

          mov     r1,#contatore
          ldr     r1,[r1]
          mov     r2,#lista

ciclo     ldr     r3,[r2] ;carico il numero in r3
          cmp     r3,#10 ;confronta il contenuto di r3 (numero corrente) con 10 se corrisponde setterà Z a 1
          beq     found ;controlla se Z è 1, se si andra a found altrimenti niente
          add     r2,r2,#4 ; mi sposto nella lista
          subs    r1,r1,#1 ;decremento il contatore
          bgt     ciclo ;se r1 non è 0 o minore va a ciclo e continua

          mov     r10,#risultato
          mov     r2,#-1 ;10 non trovato quindi ritorno -1
          str     r2,[r10]
          end

found     mov     r10,#risultato
          str     r2,[r10] ;10 trovato quindi ritorno l'indirizzo
          end
