Continuo di [[Secondo_anno/Secondo Semestre/SistemiOperativi/PDF_LEZIONI/5_19_marzo.pdf|5_19_marzo]]

Un altro algoritmo per avere mutua esclusione tra i processi che accedono alle risorse è *l'algoritmo di Peterson*

**Algoritmo di Peterson**
![[Pasted image 20260325174914.png|569]]
Riusciamo a gestire N processi, abbiamo una variabile turn che prende il valore del processo scelto per entrare nella sezione critica

**Istruzioni TSL e XCHG per garantire mutua esclusione**
 
L'istruzione `TSL (REGISTER, LOCK)` compie due azioni allo stesso tempo:

1. Legge il valore attuale della variabile `LOCK` e lo copia nel registro.
    
2. Scrive un valore `!= 0` nella variabile `LOCK`.

**Come si usa:**
- Il processo chiama `TSL`.
    
- Se il registro riceve `1`, significa che qualcuno è dentro la sezione critica; il processo esegue quindi il ciclo di _wait_ finché `LOCK` non diventa `0`.
    
- All'uscita, il processo imposta `LOCK = 0`.

**Sleep e wake up**
