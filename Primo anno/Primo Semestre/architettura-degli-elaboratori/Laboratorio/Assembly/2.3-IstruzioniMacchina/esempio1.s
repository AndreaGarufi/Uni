lista      dcd     10 ;alloca spazio per in memoria per il 10
costante   equ     30 ;definisce la costante 30

           mov     r1,#lista ;carica l'indirizzo della lista
           ldr     r1,[r1] ;carica il 10
           bl      sommatoria ;chiama la funzione "sommatoria"
           mov     r3,#1 ;mette 1 in r3 dopo essere ritornato dalla funzione
           end

sommatoria add     r1,r1,#costante ;somma ad r1 la costante (30) e mette il risultato in r1
           mov     pc,lr ;istruzione per il rientro dalla funzione
