          ;Data   la lista
          ;1,24,12,8,10,1,4,21,3,1,5,1
          ;contareil numero di volte che compare in memoria il valore 1 e salvare il risultato in memoria.

lista     dcd     1,24,12,8,10,1,4,21,3,1,5,1
contatore dcd     12
risultato fill    4

          mov     r1,#lista
          mov     r2,#contatore
          ldr     r2,[r2]   ;carico il valore puntato da r2 in r2 (12)
          mov     r4,#0     ;inizializzo a 0 r4 (dove inserirò le occorrenze di 1)
          subs    r2,r2,#1  ;decremento il contatore di 1 perché altrimenti non faccio il giusto numero di cicli
ciclo     ldr     r3,[r1],#4    ;si chiama post-incremento quindi alla prima esecuzione carico il valore puntato da r1 (1) e dal secondo passaggio in poi mi sposto di 4 byte
          cmp     r3,#1     ;comparo il valore corrente con 1, se è 1 vado a found e incremento il contatore delle occorrenze
          beq     found
          subs    r2,r2,#1  ;decremento il contatore prima di passare al prossimo elemento
          bgt     ciclo ;se il contatore è > 0 va a ciclo

          mov     r10,#risultato    
          str     r4,[r10]          ;qui salvo il valore di r4 dentro risultato

          end   ;fine


found     add     r4,r4,#1  ;se sono qui vuol dire che il numero corrente è 1 e incremento r4 di 1
          b       ciclo     ;b mi fa tornare incondizionatamente a ciclo

