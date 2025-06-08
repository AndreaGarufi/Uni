          ;Data   la lista 1,24,12,8,10,1,4,21,3,1,5,1
          ;trovareil valore 10 e salvare in memoria l’indirizzo corrispondente.
          ;Se     non viene trovato salvare -1.


lista     dcd     1,24,12,8,10,1,4,21,3,1,5,1
contatore equ     12
risultato fill    4

          mov     r1,#lista ;metto l'indirizzo della lista in r1
          mov     r2,#contatore ;metto in contatore in r2



ciclo     ldr     r3,[r1]   ;inizia il ciclo: metto dentro r3 il valore dell'indirizzo contenuto in r1
          cmp     r3,#10    ;comparo con il 10
          beq     salva     ;branch_if_equal_to_0
          add     r1,r1,#4  ;mi sposto al prossimo numero
          subs    r2,r2,#1  ;decremento il contatore
          bgt     ciclo     ;barnch_if_greter_than_0
          mov     r1,#-1    ;in caso non ci sia il 10 ritorno -1


salva     mov     r10,#risultato    
          str     r1,[r10]  ;salvo  L'INDIRIZZO in cui si trova il 10 all'indirizzo puntato da r10
          end
