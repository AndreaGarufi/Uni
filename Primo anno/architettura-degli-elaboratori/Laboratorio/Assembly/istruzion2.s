num1   DCD     1,2,3,4,5,6,7,8
num2   equ     31
num3   DCD     41
       mov     r1,#num2 ;31
       mov     r2,#num3 ;0x.... (indirizzo)
       ldr     r3,[r2]
       end     ;questa è la fine del programma
       mov     r1,#100 ;questa istrtuzione non si esegue perché è dopo end