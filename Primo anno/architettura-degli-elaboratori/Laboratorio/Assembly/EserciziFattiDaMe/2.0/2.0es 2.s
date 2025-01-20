          ;effettua due operazione 9+1 , 9-1 e salva il risultato in memoria

num1      dcd     9
num2      dcd     1

risultato fill    8 ;riservo 8 byte perché devo salvare 2 numeri (int = 4 byte)

          mov     r1,#num1
          ldr     r1,[r1]

          mov     r2,#num2
          ldr     r2,[r2]

          add     r3,r1,r2
          sub     r4,r1,r2

          mov     r10,#risultato
          str     r3,[r10] ;salvi il contenuto di r3 nel valore puntato da r10
          str     r4,[r10,#4] ;salvi il contenuto di r3 nel valore puntato da r10 spostato di 4 byte
          end