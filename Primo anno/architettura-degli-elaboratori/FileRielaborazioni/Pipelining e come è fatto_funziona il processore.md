**Il pipelining è una tecnica usata per migliorare l'efficienza della gestione delle istruzioni, le istruzioni vengono gestite in modo che ci siano più istruzioni eseguite contemporaneamente.** 
![[Pasted image 20241105221515.png]]


• Per gestire l’esecuzione in pipeline di più istruzioni, è necessario mantenere delle informazioni tra uno stadio e l’altro 

• Queste informazioni vengono mantenuti nei **buffer interstadi** 

• I buffer interstadi contengono 
	• i rispettivi registri interstadio (RA, RB, PC_Temp, etc.) 
	• Il registro IR (Per mantenere gli identificatori dei registri sorgente e destinazione) 
	• Segnali di controllo per i vari stadi

![[Pasted image 20241105221652.png|400]]

**Non sempre è possibile eseguire 5 istruzioni contemporaneamente perché si creano dei conflitti**

**TIPI DI CONFLITTI: 

### 1.  **DIPENDENZE DA DATO**
DIPENDENZE **RAW** (read after write)


cerca su chat


DIPENDENZE **WAW**

cerca su chat


DIPENDENZE **WAR**
Si verifica quando un istruzione cerca di scrivere un registro prima che un'altra abbia finito di leggere.


Esistono delle **tecniche per evitare queste dipendenze:**
**Forwarding** --> lbypassa la fase di store nei registri degli operandi
**Stallo** --> mette in attesa l'istruzione dipendente
**Riordinamento delle istruzioni** --> riordina le istruzioni in modo che non ci siano problemi di dipendenza
**Pre-fetching** --> carica le istruzioni prima **(crea collegamento a introduzione e componenti pc)** 
**Speculative execution** --> cerca di predire eventuali problemi di dipendenza e cerca di non farli accadere


### 2. **RITARDI NELL'ACCESSO ALLA MEMORIA**
### 3. **RITARDI NEI SALTI**
### 4. **LIMITI NELLE RISORSE**



