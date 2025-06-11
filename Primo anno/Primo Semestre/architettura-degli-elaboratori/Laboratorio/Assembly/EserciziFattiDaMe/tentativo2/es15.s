;Data la sequenza di numeri 1,2,3,4,5,6,7,8 : 
;1. sommare i numeri di posizione pari. 
;2. sottrarre i numeri in posizione dispari 
;3. salvare i due risultati in memoria

lista dcd 1,2,3,4,5,6,7,8
contatore equ 8
risultato fill 8

mov r1,#lista
mov r2,#contatore

mov r7,#0   ;r7 lo uso come indice dell'array per capire posizione pari o dispari (parte da 0)
mov r8,#0   ;sommo i pari
mov r9,#0   ;sottraggo i dispari




