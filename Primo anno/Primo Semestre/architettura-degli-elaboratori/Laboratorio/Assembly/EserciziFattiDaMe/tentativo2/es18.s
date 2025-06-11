                ;Data   la lista [-10,4,23,50,0,40,10,7] trovare il minimo e salvare il risultato in memoria

lista           dcd     -10,4,23,50,0,40,10,7
dim             equ     8
risultato       fill    4

                mov     r1,#lista
                mov     r2,#dim
                ldr     r5,[r1] ;carico il primo numero
                add     r1,r1,#4;e sposto al secondo indirizzo
                subs    r2,r2,#1;decremento il contatore


ciclo           
                ldr     r6,[r1] ;carico in r6 il secondo numero
                add     r1,r1,#4 ;sposto l'indirizzo al terzo numero
                cmp     r6,r5 ;comparo il primo numero con il secondo e cosi via
                blt     aggiorna_minimo ;branch_if_lower_than_0



continua        
                subs    r2,r2,#1 ;decremento il contatore
                bgt     ciclo



                mov     r10,#risultato ;salvo
                str     r5,[r10]
                end



aggiorna_minimo 
                mov     r5,r6 ;sposto il minimo in r5
                b       continua
