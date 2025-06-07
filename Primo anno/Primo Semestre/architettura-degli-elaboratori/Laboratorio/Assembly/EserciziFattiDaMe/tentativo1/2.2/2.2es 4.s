          ;Data   la lista
          ;1,24,12,8,10,1,4,21,3,1,5,1
          ;sommarei numeri maggiori (o uguali) di x con x = 10


lista     dcd     1,24,12,8,10,1,4,21,3,1,5,1
contatore dcd     12
risultato fill    4

          mov     r1,#lista

          mov     r2,#contatore
          ldr     r2,[r2]
          mov     r5,#0;inizializzo a 0
ciclo     ldr     r3,[r1],#4
          cmp     r3,#10 ;compara il numero corrente con 10
          bge     sommo ;se è maggiore di 10 va a sommo (controlla se l'ultima istruzione ha come risultato 0 o maggiore di 0 in caso positivo salta)
          subs    r2,r2,#1 ;decremento il contatore
          bgt     ciclo ;se il contatore è > 0 salta a ciclo

          mov     r10,#risultato
          str     r5,[r10] ;salvo il contenuto di r5 al valore puntato da r10 (dentro risultato)
          end

sommo     add     r5,r5,r3 ;qui faccio la somma dei numeri maggiori di 10
          subs    r2,r2,#1 ;decremento il contatore
          b       ciclo ;salto incondizionatamente a 10

          end