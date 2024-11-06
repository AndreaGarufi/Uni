[[Introduzione e componenti PC#**PIPELINE**|spiegazione pipeline breve]]
# Pipeline
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

### **TIPI DI CONFLITTI: 

### 1.  **DIPENDENZE DA DATO (data hazards)** 
DIPENDENZE **RAW** (read after write)
si verifica quando un’istruzione deve leggere un dato che un'istruzione precedente non ha ancora scritto

• Istruzione1: A = B + C; 
• Istruzione2: D = A + 1 

• l'Istruzione2 contiene una dipendenza RAW

DIPENDENZE **WAW** (write after write)
si verificano quando due istruzioni vogliono scrivere nello stesso registro o nella stessa posizione di memoria

DIPENDENZE **WAR** (write after read)
Si verifica quando un istruzione cerca di scrivere un registro prima che un'altra abbia finito di leggere.


Esistono delle **tecniche per evitare queste dipendenze:**

**Nop** --> è un istruzione vuota o inattiva che non esegue operazioni, occupa uno slot nel flusso delle istruzioni senza effettuare alcun calcolo o modifica nello stato del processore. è utilizzata per allineare le operazioni nella CPU . (serve per temporeggiare creando dei ritardi controllati) 

**Forwarding** --> bypassa la fase di store nei registri degli operandi (fa passare direttamente il risultato di un operazione direttamente alla istruzione successiva, quindi non fa la fase di store)
Il beneficio rispetto al NOP è che evita i ritardi (quindi migliora le performance della CPU)

**Stallo** --> mette in attesa l'istruzione dipendente

**Riordinamento delle istruzioni** --> riordina le istruzioni in modo che non ci siano problemi di dipendenza

**Pre-fetching** --> carica le istruzioni prima [[Introduzione e componenti PC#**PREFETCH**|Pre-fetching spiegazione]]

**Speculative execution** --> cerca di predire eventuali problemi di dipendenza e cerca di non farli accadere


### 2. **RITARDI NELL'ACCESSO ALLA MEMORIA**
I principali ritardi della memoria si verificano perché:

 **le memorie hanno una propria latenza costruttiva** (memory access latency) il tempo necessario ad accedere ai dati contenuti nella memoria, (influisce anche la velocità del bus)

Il problema sta nel fatto che **la CPU deve aspettare che i dati contenuti nella memoria arrivino** e quindi non può procedere rallentando la pipeline

Esistono delle **tecniche per rallentare questi ritardi:**
1) **Gerarchia della cache** --> si usano 3 livelli di cache (L1 L2 L3) dalla più veloce e vicina alla CPU alla più lenta posta sulla scheda madre.
2) **Pre-fetching** --> carica in anticipo i dati nella cache [[Introduzione e componenti PC#**PREFETCH**|Pre-fetching spiegazione]]
3) **Produrre memoria a bassa latenza** --> che siano cache o RAM più sono veloci meglio è.

### 3. **RITARDI NEI SALTI**
### 4. **LIMITI NELLE RISORSE**



