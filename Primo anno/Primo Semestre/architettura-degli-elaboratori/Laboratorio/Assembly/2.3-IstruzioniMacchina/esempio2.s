          ;       somma di N elementi tramite registri usando la funzione "somma"

lista     dcd     1,2,3,4,5,6,7,8,9,10
dim       equ     10
risultato fill    4

          mov     r1,#dim ;carico la costante dim (cioè 10)
          mov     r2,#lista ;carico l'indirizzo del primo numero nella lista
          bl      somma ;chiamo la funzione (subroutine) "somma"
          mov     r1,#risultato
          str     r3,[r1] ;salvo il risultato
          end     ;fine programma


somma     mov     r3,#0 ; clear di r3
ciclo     subs    r1,r1,#1 ;entro nel ciclo e decremento il contatore
          blt     esci ;salta a "esci" se l'operazione precedente è minore di 0 (controlla i flag N e V)
          ldr     r4,[r2],#4 ;carica in r4 l'indirizzo puntato da r2 e al ciclo successivo si sposterà di 4 byte (1 numero successivo)
          add     r3,r3,r4 ;fa la somma
          b       ciclo ;salta incondizionatamente a ciclo


esci      mov     pc,lr ;ritorno al chiamante della funzione somma (bl somma [riga 9])



