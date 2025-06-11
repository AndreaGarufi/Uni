          ;Data   la lista [30,10,23,1,17,8,19,10] sommare tutti i numeri compresi tra 10 e 20.

lista     dcd     30,10,23,1,17,8,19,10
contatore equ     8
risultato fill    4

          mov     r1,#lista
          mov     r2,#contatore

ciclo     ldr     r3,[r1] ;inzia il ciclo: carico in r3, il valore dell'indirizzo di r1
          cmp     r3,#10 ;comparo per vedere se è più piccolo di 10
          blt     avanti ;branch_if_lower_than_0_to avanti
          cmp     r3,#20 ;comparo per vedere se è più grande di 10
          bgt     avanti ;branch_if_greater_than_0_to avanti
          add     r4,r4,r3 ;se rispetta le condizioni sommo i numeri
          add     r1,r1,#4 ;mi sposto al prossimo numero
          subs    r2,r2,#1 ;decremento
          bgt     ciclo ;branch_if_greater_than_0
          b       salva



avanti    add     r1,r1,#4 ;qui vado avanti al prossimo numero
          subs    r2,r2,#1
          bgt     ciclo

salva     mov     r10,#risultato ;qui salvo
          str     r4,[r10]
