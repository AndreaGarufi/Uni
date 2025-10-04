          ;Data   la sequenza di numeri 1,2,3,4,5,6,7,8 :
          ;sommare a tutti i numeri la costante 10;
          ;sommare i numeri ottenuti;
          ;salvare il valore della somma in memoria.

lista     dcd     1,2,3,4,5,6,7,8 ;carico la lista in memoria
dim       dcd     8 ;carico anche la lunghezza della lista
risultato fill    4 ;spazio per il risultato

          mov     r1,#dim   ;metto in r1,indirizzo di dim
          ldr     r1,[r1]   ;carico in r1 il valore dell'indirizzo puntato da r1
          mov     r2,#lista ;metto in r2 l'indirizzo di lista
          mov     r3,#0     ;inizializzo a 0
ciclo     ldr     r4,[r2]   ;inzia il ciclo: carico in r4,  il valore dell'indirizzo puntato da r2
          add     r4,r4,#10 ;sommo 10
          add     r3,r3,r4  ;sommo i numeri tra loro
          add     r2,r2,#4  ;mi sposto di 1 numero nella lista
          subs    r1,r1,#1  ;sottraggo 1 al contatore
          bgt     ciclo     ;branch_if_greater_than_0 

          mov     r7,#risultato ;metto in r7 l'indirizzo di risultato
          str     r3,[r7]       ;salvo r3 all'indirizzo puntato da r7
          end
