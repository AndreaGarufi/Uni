lista  dcd     10,4,1,34,5

       mov     r1,#10
       mov     r2,#41
       and     r3,r1,r2 ;faccio l'and (bit a bit) logico tra r1(10) e r2 (41) e salvo il risultato in r3
       orr     r4,r1,r2 ;faccio l'or (bit a bit) tra r1(10) e r2 (41) e salvo il risultato in r4
       eor     r5,r1,r2 ;faccio lo xor bit a bit tra r1(10) e r2 (41) e salvo il risultato in r5
       lsl     r6,r1,#3 ;eseguo uno shift logico a sinistra di 3 (sposto verso sinistra il 1010 e metto degli 0 -> 1010 000 <- 3 zeri aggiunti dopo lo shift cosi diventa 80)
       lsr     r7,r1,#3 ;eseguo uno shift logico a destra di 3 (1010 -> shifto di 3 verso destra-> 1)
       asr     r8,r1,#3 ;eseguo uno shift aritmetico a destra di 3 (si usa per preservare il segno del numero infatti sotto...)
       mov     r1,#-10 ;metto un numero negativo
       asr     r9,r1,#3 ;eseguo uno shift aritmetico a destra di 3
       ror     r10,r1,#3 ;simile allo shift logico qui è come se applicassi l'effetto pac-man quindi i bit che scorrono verso destra rientrano dall'altra parte
       mov     r1,#lista
       ldrb    r2,[r1,#1] ;legge un singolo byte e lo mette nel registro r2
       mov     r2,#32 ;mette 32 in r2
       strb    r2,[r1,#2];Salva gli 8 bit meno significativi del registro sorgente nella locazione di memoria specificata