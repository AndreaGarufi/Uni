          ;Data   la lista [10,20,12,12,5,1,5,1] contare tutti i numeri diversi da 1 e 10

lista     dcd     10,20,12,12,5,1,5,10
contatore equ     8
risultato fill    4

          mov     r1,#lista
          mov     r2,#contatore

ciclo     ldr     r3,[r1] ;inizia il ciclo: carico in r3 il primo numero
          cmp     r3,#10 ;comparo con il 10 per vederese è uguale
          beq     avanti ;branch_if_equal_to_0 (se il risultato di prima era 0 salta ad avanti dove mi sposto al prossimo numero)
          cmp     r3,#1 ;comparo con l' 1 per vedere se è uguale
          beq     avanti ;branch_if_equal_to_0 (se il risultato di prima era 0 salta ad avanti dove mi sposto al prossimo numero)
          add     r4,r4,#1 ;qui aumento il contatore dei numeri diversi da 10 e 1
          add     r1,r1,#4 ;mi sospoto e continuo il ciclo se ci sono ancora numeri
          subs    r2,r2,#1
          bgt     ciclo
          b       salva


avanti    add     r1,r1,#4 ;qui va se i numeri sono uguali a 1 o 10: mi sposto al prossimo numero e torno a ciclo
          subs    r2,r2,#1
          bgt     ciclo



salva     mov     r10,#risultato ;qui salvo il contatore in memoria
          str     r4,[r10]
          end