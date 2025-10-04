       ;       Data la lista [1,2,3,4,5,6,7,8,9,10] moltiplicazione
       ;       ogni elemento x2.

lista  dcd     1,2,3,4,5,6,7,8,9,10
dim    equ     10

       mov     r1,#lista
       mov     r2,#dim
ciclo  subs    r2,r2,#1     ;decrementa il contatore
       blt     esci         ;se è minore di 0 salta ad "esci"
       ldr     r3,[r1]      ;carico in r3 il valore puntato da r1
       lsl     r3,r3,#1     ;equivale a fare una moltiplicazione per 2^1 (se ci fosse stato #2 era 2^2 e cosi via)
       str     r3,[r1]      ;salvo il contenuto di r3 dentro il valore puntato da r1 (aggiorno la lista con i nuovi valori)
       add     r1,r1,#4     ;mi sposto di un numero
       b       ciclo

esci   end
