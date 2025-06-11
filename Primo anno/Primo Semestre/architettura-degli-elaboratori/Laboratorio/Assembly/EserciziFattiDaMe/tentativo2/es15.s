          ;Data   la sequenza di numeri 1,2,3,4,5,6,7,8 :
          ;1.     sommare i numeri di posizione pari.
          ;2.     sottrarre i numeri in posizione dispari
          ;3.     salvare i due risultati in memoria

lista     dcd     1,2,3,4,5,6,7,8
contatore equ     8
risultato fill    8

          mov     r1,#lista
          mov     r2,#contatore

          mov     r7,#0 ;r7 lo uso come indice dell'array per capire posizione pari o dispari (parte da 0)
          mov     r8,#0 ;sommo i pari
          mov     r9,#0 ;sottraggo i dispari

ciclo     ldr     r3,[r1]   ;carico il primo numero
          and     r4,r7,#1  ;faccio l'and tra la posizione e 1 (se viene 0 posizione pari altirmenti posizione dispari)
          cmp     r4,#0     ;comparo il risultato dell'and con lo 0 e se viene 0 vado in somma pari altrimenti vado sotto per sottrarre i dispari
          beq     sommaPari
          sub     r9,r9,r3 ;sommo i dispari
          add     r7,r7,#1  ;INCREMENTARE IL CONTATORE
          add     r1,r1,#4
          subs    r2,r2,#1
          bgt     ciclo
          b       salva


sommaPari add     r8,r8,r3  ;sommo i numeri pari
          add     r7,r7,#1 ;INCREMENTARE IL CONTATORE
          add     r1,r1,#4 
          subs    r2,r2,#1
          bgt     ciclo

salva     mov     r10,#risultato    
          str     r8,[r10]  

          add     r10,r10,#4
          str     r9,[r10]
          end