num1   dcd     100; riserva spazio in memoria e mette 100 dentro
num2   dcd     231; riserva spazio in memoria e mette 231 dentro
       mov     r1,#10 ;tramite modo immediato mette 10 dentro r1
       mov     r2,#30 ;tramite modo immediato mette 30 dentro r1
       mov     r3,r2 ;inserisce il valore di r2 (30) dentro r3
       mov     r2,#3 ;inserisce 3 dentro r2
       add     r4,r1,r2 ;somma r1 ed r2 e lo mette in r4
       sub     r4,r1,r2 ;sottrae r1-r2 e lo mette in r4

       mov     r1,#num1 ;inserisce l'indirizzo di num1 in r1
       ldr     r2,[r1] ;tramite modo indiretto carica il valore puntato da r1 in r2 (come i puntatori di c)

       mov     r3,#num2 ;inserisce l'indirizzo di num2 in r3
       ldr     r4,[r3] ;tramite modo indiretto carica il valore puntato da r3 in r4 (come i puntatori di c)

       mov     r6,#31 ;dentro r6 mette 31
       str     r6,[r1] ;salva il contenuto di r6 e lo mette nell'indirizzo puntato da r1




