        ;scrivere un programma che detrmini la posizione del numero più piccolo e il valore del numero più grande presenti nell'array,
        ;inserire i 2 valori in POSMIN e VALMAX
        ;l'indirizzo di base dell'array è memorizzato in memoria all'indirizzo ARR
        ;la     lunghezza dell'array è memorizzata in memoria all'indirizzo LUNG
        ;gli    elementi dell'array hanno lunghezza 4 byte e hanno posizioni consecutive
        ;(per   saper fare questo esercizio devi aver capito bene massimo e minimo)

ARR     dcd     -10,4,-23,50,0,40,10,70
LUNG    dcd     8
POSMIN  fill    4
VALMAX  fill    4

        mov     r1,#ARR
        mov     r2,#LUNG
        ldr     r2,[r2]
        ldr     r3,[r1]
        add     r1,r1,#4
        subs    r2,r2,#1

ciclo   ldr     r4,[r1] ;stesso algoritmo del minimo solo che blt cambia con bgt
        cmp     r4,r3
        bgt     massimo
        add     r1,r1,#4
        subs    r2,r2,#1
        bgt     ciclo
        b       salva


massimo mov     r3,r4
        add     r1,r1,#4
        subs    r2,r2,#1
        bgt     ciclo


salva   mov     r10,#VALMAX
        str     r3,[r10] ;fino a qui trovo il valore massimo

        mov     r1,#ARR ;da qui in poi la posizione del minimo
        mov     r2,#LUNG
        ldr     r2,[r2]
        mov     r8,#0 ;lo userò per la vera posizione del vero minimo
        mov     r7,#0 ;registro in cui tengo conto della posizione
        ldr     r3,[r1] ;minimo provvisorio (primo numero)
        add     r1,r1,#4
        subs    r2,r2,#1

ciclo2  ldr     r4,[r1] ;trovo il minimo ma devo anche aggiornare la posizione (uso r7)
        cmp     r4,r3
        blt     minimo
        add     r7,r7,#1
        add     r1,r1,#4
        subs    r2,r2,#1
        bgt     ciclo2
        b       salva2




minimo  mov     r3,r4 ;qui è dove trovo il nuovo minimo, ma siccome non è detto sia quello definitivo aggiorno la posizione in r7
        add     r7,r7,#1 ;pero la salvo anche in r8 cosi che se dovesse essere il vero minimo ho la sua posizione salvata in r8
        mov     r8,r7
        add     r1,r1,#4
        subs    r2,r2,#1
        bgt     ciclo2



salva2  mov     r10,#POSMIN ;salvo r8 (posizione del minimo)
        str     r8,[r10]
        end




















