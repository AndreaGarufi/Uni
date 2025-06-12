          ;Data   la lista [-10,4,23,50,0,40,10,7] trovare il minimo e salvare il risultato in memoria

lista     dcd     4,23,50,-10,0,40,10,7
contatore equ     8
risultato fill    4

          mov     r1,#lista
          mov     r2,#contatore
          ldr     r3,[r1] ;carico il primo numero in r3 (fungerà da minimo provvisorio)
          add     r1,r1,#4 ;sposto l'indirizzo al prossimo numero
          sub     r2,r2,#1 ;sottraggo il contatore

ciclo     ldr     r4,[r1] ;carico il numero in r4
          cmp     r4,r3 ;comparo r4 con r3 per vedere qual è il più grande (r3 è il minimo che ho trovato fin'ora)
          blt     minimo ;branch_if_lower_than_0 salta a minimo quando r4 è più piccolo di r3
          add     r1,r1,#4 ;altrimenti sposto l'indirizzo al prossimo numero
          subs    r2,r2,#1 ;decremento il contatore
          bgt     ciclo ;branch_if_greater_than_0 to ciclo
          b       salva



minimo    mov     r3,r4 ;metto in r3 il numero dentro r4 cosi salvo il nuovo minimo
          add     r1,r1,#4 ;sposto l'indirizzo al prossimo numero
          subs    r2,r2,#1 ;decremento
          bgt     ciclo ;branch_if_greater_than_0 to ciclo

salva     mov     r10,#risultato ;salvo il minimo
          str     r3,[r10]
          end