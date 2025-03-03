          ;       Data la lista [1,2,3,4,5,6,7,8,9,10]
          ;contare tutti i numeri dispari e
          ;maggiori di 5 e salvare il risultato in memoria.

lista     dcd     1,2,3,4,5,6,7,8,9,10
dim       equ     10
risultato fill    4

          mov     r1,#lista
          mov     r2,#dim
          mov     r3,#0 ; contatore
ciclo     subs    r2,r2,#1
          blt     esci
          ldr     r4,[r1],#4
          ;verifico se è pari
          and     r5,r4,#1  ;confronterà il bit meno significativo con 1 e se il risultato è 1 il numero è dispari altrimenti pari
          cmp     r5,#0 ;compara r5 (risultato dell'and) con 0 
          beq     ciclo ;salta se il risultato precedente è 0 (cmp r5,#0) (in pratica saltera solo se il numero è pari (perché a me servono i numeri dispari))
          cmp     r4,#5 ;arriva qui se il numero è dispari e lo compara con 5 per vedere se è maggiore oppure no
          ble     ciclo ;se è minore di 5 salta a ciclo e va avanti con i numeri
          add     r3,r3,#1  ;se è maggiore di 5 non avrà saltato e quindi incremento r3 per contare i numeri
          b       ciclo ;salto a ciclo per continuare con i numeri
esci      mov     r1,#risultato
          str     r3,[r1]   ;salvo r3



