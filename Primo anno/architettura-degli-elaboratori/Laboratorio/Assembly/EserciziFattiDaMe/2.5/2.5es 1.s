             ;Data   la sequenza di numeri 1,2,3,4,5,6,7,8 :
             ;1.     sommare i numeri di posizione pari.
             ;2.     sottrarre i numeri in posizione dispari
             ;3.     salvare i due risultati in memoria

lista        dcd     1,2,3,4,5,6,7,8
contatore    dcd     8
risultato    fill    8

             mov     r1,#lista
             mov     r2,#contatore
             ldr     r2,[r2]

             mov     r3,#0 ;indice
             mov     r4,#0 ;somme per i numeri pari
             mov     r5,#0 ;somme per i numeri dispari

ciclo        subs    r2,r2,#1
             blt     salva
             and     r6,r3,#1
             cmp     r6,#0
             beq     sommaPari
             b       sommaDispari

sommaDispari ldr     r9,[r1],#4 ;add     r1,r1,#4 (ovviamente si puo passare al prossimo indirizzo anche così)
             sub     r5,r5,r9
             add     r3,r3,#1
             b       ciclo


sommaPari    ldr     r8,[r1],#4
             add     r4,r4,r8
             add     r3,r3,#1
             b       ciclo

salva        mov     r10,#risultato
             str     r4,[r10]
             str     r5,[r10,#4]
             end