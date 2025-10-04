![[Pasted image 20241229113429.png]]

---

### **1. NR EQU 5**
- **Tipo:** Definizione di Costante (Assembler Directive).
- **Spiegazione:** Definisce una costante simbolica chiamata `NR` con valore 5. Viene utilizzata per rendere il codice più leggibile.

---

### **2. LIST DCD 1,2,3,5**
- **Tipo:** Dichiarazione di Dati (Assembler Directive).
- **Spiegazione:** Alloca in memoria una lista di valori costanti (1, 2, 3, 5). Il simbolo `LIST` punta all'inizio della lista.

---

### **3. ADD R1, R2, R3**
- **Tipo:** Istruzione Aritmetica.
- **Spiegazione:** Somma i valori contenuti nei registri `R2` e `R3`, memorizzando il risultato in `R1`.

---

### **4. ADDS R1, R2, R3**
- **Tipo:** Istruzione Aritmetica con aggiornamento dello Status Processor (PS).
- **Spiegazione:** Come `ADD`, ma aggiorna i flag di stato (Zero, Carry, Overflow, Negative) in base al risultato.

---

### **5. SUB R1, R2, R3**
- **Tipo:** Istruzione Aritmetica.
- **Spiegazione:** Sottrae il valore del registro `R3` da `R2` e memorizza il risultato in `R1`.

---

### **6. SUBS R1, R2, R3**
- **Tipo:** Istruzione Aritmetica con aggiornamento dello Status Processor (PS).
- **Spiegazione:** Come `SUB`, ma aggiorna i flag di stato in base al risultato.

---

### **7. LDR R1, [R3]**
- **Tipo:** Operazione di Load (Caricamento da Memoria).
- **Spiegazione:** Carica il valore memorizzato all'indirizzo puntato da `R3` e lo salva nel registro `R1`.

---

### **8. LDR R1, [R3,#5]**
- **Tipo:** Operazione di Load con Spiazzamento.
- **Spiegazione:** Carica in `R1` il valore memorizzato all'indirizzo calcolato come `R3 + 5`.

---

### **9. STR R1, [R3]**
- **Tipo:** Operazione di Store (Memorizzazione in Memoria).
- **Spiegazione:** Scrive il valore di `R1` nell'indirizzo puntato da `R3`.

---

### **10. STR R1, [R3,#5]**
- **Tipo:** Operazione di Store con Spiazzamento.
- **Spiegazione:** Scrive il valore di `R1` nell'indirizzo calcolato come `R3 + 5`.

---

### **11. NR FILL 4**
- **Tipo:** Assembler Directive.
- **Spiegazione:** Riserva 4 byte di spazio vuoto nella memoria.

---

### **12. MOV R1, #NR**
- **Tipo:** Istruzione di Move.
- **Spiegazione:** Copia il valore della costante `NR` nel registro `R1`.

---

### **13. CMP R1, [R2,#5]**
- **Tipo:** Istruzione di Confronto.
- **Spiegazione:** Confronta il valore di `R1` con il valore caricato dall'indirizzo `R2 + 5` e aggiorna il flag Z e N. (esegue una sottrazione implicita senza salvare il risultato)

- - **Flag Z (Zero):**
    - **Set (1):** Se il risultato della sottrazione è **zero** (gli operandi sono uguali).
    - **Cleared (0):** Se il risultato della sottrazione è **diverso da zero**.

- **Flag N (Negative):**
    - **Set (1):** Se il bit più significativo (MSB) del risultato della sottrazione è **1**, indicando un risultato negativo (nell'aritmetica a complemento a due).
    - **Cleared (0):** Se il MSB del risultato è **0**, indicando un risultato positivo o zero.

- **Flag C (Carry)**:
    - **Set (1)**: Non c'è stato un prestito (cioè il **minuendo era maggiore o uguale al sottraendo** (10-4 -> 10 = minuendo 4 = sottraendo))
    - **Cleared (0)**: C'è stato un prestito (cioè il **minuendo era minore del sottraendo**).

- **Flag V (Overflow)**:
    - **Set (1)**: Se si verifica un overflow, cioè il risultato non può essere rappresentato correttamente nel numero di bit disponibili (ad esempio, somma di due numeri negativi che dà un numero positivo o viceversa).
    - **Cleared (0)**: Se non si verifica overflow.


---

### **14. END**
- **Tipo:** Assembler Directive.
- **Spiegazione:** Indica la fine del programma sorgente.

---

### **15. B**
- **Tipo:** Istruzione di Salto.
- **Spiegazione:** Salta incondizionatamente all'punto specificato.

---

### **16. BL**
- **Tipo:** Istruzione di Salto con Link.
- **Spiegazione:** Salta incondizionatamente all'indirizzo specificato e salva l'indirizzo di ritorno nel registro `LR` (Link Register).

---

### **17. BLE**
- **Tipo:** Istruzione di Salto Condizionato.
- **Spiegazione:** Salta se il risultato precedente era minore o uguale a zero (controllando i flag Z e N).

---

### **18. BLT**
- **Tipo:** Istruzione di Salto Condizionato.
- **Spiegazione:** Salta se il risultato precedente era minore di zero (controllando i flag N e V).

---

### **19. BGE**
- **Tipo:** Istruzione di Salto Condizionato.
- **Spiegazione:** Salta se il risultato precedente era maggiore o uguale a zero.

---

### **20. BGT**
- **Tipo:** Istruzione di Salto Condizionato.
- **Spiegazione:** Salta se il risultato precedente era maggiore di zero. (Controllando i bit di esito, quindi controlla l'istruzione che li aggiorna)

---

### **21. BEQ**
- **Tipo:** Istruzione di Salto Condizionato.
- **Spiegazione:** Salta se il risultato precedente era uguale a zero (verifica lo stato del flag Z).

### **22. STM**
- **Tipo:** Istruzione di gestione Pila (PUSH)
- **Spiegazione:** è utilizzata per salvare un insieme di registri sullo stack

| STM[codice] SP[!] {lista di registri} |
| ------------------------------------- |
- I codici sono questi:

| Codice | Significato      |
| ------ | ---------------- |
| FD     | Full descending  |
| FA     | Full ascending   |
| ED     | Empty descending |
| EA     | Empty ascending  |
- Il "**!**" serve ad aggiornare lo stack pointer **SP**
##### **Esempio**
stmfd sp!,{r1,r2,r0,r3,r4,r5,r6,r7}
- **`sp`**: Indica il registro stack pointer (puntatore allo stack).
- **`!`**: Aggiorna il valore di `sp` dopo aver memorizzato i registri (in-place update).
- **`FD`** : Lo stack cresce "verso il basso" (valori di indirizzo decrescenti) nella modalità **Full Descending**.
- **`{r1, r2, r0, ...}`**: Elenca i registri da salvare sullo stack, in ordine specificato

### **23. LDM**
- **Tipo:** Istruzione di gestione Pila (POP)
- **Spiegazione:** viene utilizzata per **caricare** (ripristinare) un insieme di registri dallo stack

| ldmfd sp!, {r0,r1,r2,r3,r4,r5,r6,r7} |
| ------------------------------------ |
- I codici sono questi:

| Codice | Significato      |
| ------ | ---------------- |
| FD     | Full descending  |
| FA     | Full ascending   |
| ED     | Empty descending |
| EA     | Empty ascending  |
- Il "**!**" serve ad aggiornare lo stack pointer **SP**
##### **Esempio**
ldmfd sp!, {r0,r1,r2,r3,r4,r5,r6,r7}
- **`sp`**: Indica il registro stack pointer (puntatore allo stack).
- **`!`**: Aggiorna il valore di `sp` dopo aver caricato i registri (in-place update).
- **`FD`**: Lo stack segue la modalità **Full Descending**, che implica che i dati vengono letti da indirizzi **crescenti** man mano che `sp` viene aggiornato.
- **`{r0, r1, r2, ...}`**: Elenca i registri che vengono caricati dallo stack, nell'ordine specificato.

### **24. AND**
- **Tipo:** Istruzione per operazioni logiche 
- **Spiegazione:** esegue l'**AND** bit a bit del contenuto di 2 registri 
**Esempio** 
**and r3,r2,r1**          r1 = 10 (1010) r2 = 41 (101001)
![[Pasted image 20250124175518.png]]

### **25. ORR**
- **Tipo:** Istruzione per operazioni logiche 
- **Spiegazione:** esegue l'**OR** bit a bit del contenuto di 2 registri 
**Esempio**
**orr r3,r2,r1**          r1 = 10 (1010) r2 = 41 (101001)

### **26. EOR** 
- **Tipo:** Istruzione per operazioni logiche 
- **Spiegazione:** esegue lo **XOR** bit a bit del contenuto di 2 registri (XOR restituisce **1** solo se i due bit sono **diversi**.)
**Esempio**
**eor r3,r2,r1**          r1 = 10 (1010) r2 = 41 (101001)

### **27. LSL** 
- **Tipo:** Istruzione per operazioni logiche 
- **Spiegazione:** Shift logico a sinistra. Scorre il contenuto di Rj a sinistra di un numero di posizioni di bit dato dall’operando contatore e pone il risultato in Ri. Gli spazi vuoti si riempiono con 0 **(equivale a fare una moltiplicazione per 2, il valore che usiamo indica l'esponente lsl r1,#1 -> sto moltiplicando per $2^1$)**

### **27. LSR** 
- **Tipo:** Istruzione per operazioni logiche 
- **Spiegazione:** Shift logico a destra. Scorre il contenuto di Rj a destra di un numero di posizioni di bit dato dall’operando contatore e pone il risultato in Ri. Gli spazi vuoti si riempiono con 0 **(equivale a fare una divisione per 2, il valore che usiamo indica l'esponente lsl r1,#1 -> sto dividendo per $2^1$)

### **28. ASR** 
- **Tipo:** Istruzione per operazioni logiche 
- **Spiegazione:** Shift aritmetico a destra. Scorre il contenuto di Rj a sinistra di un numero di posizioni di bit dato dall’operando contatore e pone il risultato in Ri. Riempie le posizioni lasciate libere con il valore del bit più significativo

### **29. ROR** 
- **Tipo:** Istruzione per operazioni logiche 
- **Spiegazione:** Rotazione verso destra

### **30. LDRB** 
- **Tipo:** Istruzione di carcicamento
- **Spiegazione:** Legge un singolo byte dalla memoria e lo registra negli 8 bit meno significativi del registro destinazione mettendo a 0 gli altri bit

### **31. STRB** 
- **Tipo:** Istruzione di salvataggio
- **Spiegazione:** Salva gli 8 bit meno significativi del registro sorgente nella locazione di memoria specificata

---

Questi comandi rappresentano un mix di direttive assembly e istruzioni ARM che coprono operazioni aritmetiche, trasferimenti di memoria, confronti, salti e gestione del flusso del programma.