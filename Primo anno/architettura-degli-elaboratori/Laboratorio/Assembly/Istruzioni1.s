       ;ESEMPI ISTRUZIONI
       ;LOAD   R1,LOC
       ;ADD    R1,15
       ;ADD    R2, R1,R1
       ;STORE  R2,LOC
       ;MOV    R3,R2
       ;SUBTRACT R4,R2,R1

       ;SOMMA

       ;LOAD   R1,A
       ;LOAD   R2,B
       ;ADD    R3,R1,R2
       ;STORE  R3,C

num1   DCD     100
num2   DCD     231

       MOV     R1,#10
       MOV     R2,#30
       MOV     R3,R2
       ADD     R4,R1,R2
       SUB     R4,R1,R2

       MOV     R1,#num1
       LDR     R2,[r1]

       MOV     R3,#num2
       LDR     R4,[R3]

       MOV     R6,#31
       ;STR    R3,[R6] per qualche motivo non funziona