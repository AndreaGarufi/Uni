          ;calcolare la somma nell array escludendo i numeri negativi e i numeri in posizione pari
          ;l'indirizzo dell array è memorizzato in ARR
          ;la     lunghezza in LUNG

ARR       dcd     10,20,4,-6,-7,8,1,9
LUNG      dcd     8
risultato fill    4

          mov     r1,#ARR
          mov     r2,#LUNG
          ldr     r2,[r2]
          mov     r5,#0 ;registro per la somma dei numeri
          mov     r7,#0 ;registro per la posizione

ciclo     ldr     r3,[r1] ;carico il numero
          and     r4,r7,#1 ;and per capire se la posizione è pari o dispari
          cmp     r4,#1 ;comparo e se il risultato è minore di 0 va ad avanti (posizione pari va ad avanti)
          blt     avanti
          cmp     r3,#0 ;comparo r3 con 0 per vedere se è nugativo, (n - 0 = n quindi se n è negativo con blt salto ad avanti)
          blt     avanti
          add     r5,r5,r3 ;altrimenti sommo in r5 e mi sposto al prossimo numero, aumento di 1 la posizione e decremento il ciclo
          add     r1,r1,#4
          add     r7,r7,#1
          subs    r2,r2,#1
          bgt     ciclo
          b       salva


avanti    add     r1,r1,#4 ;qui mi sposto, aumento di 1 la posizioen e decremento
          add     r7,r7,#1
          subs    r2,r2,#1
          bgt     ciclo



salva     mov     r10,#risultato ;qui salvo la somma
          str     r5,[r10]
          end

