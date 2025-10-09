### **JOIN INCOMPLETI**

Nel caso in cui alcuni valori tra gli attributi comuni non coincidono e si chiamo **dangling n-uple** 
![[Pasted image 20251006212314.png]]


**JOIN vuoti, un caso estremo**
Potrebbe anche succedere che nessuna n-upla trovi il corrispettivo
![[Pasted image 20251006212446.png]]

**L’altro caso estremo del JOIN**
Ogni n-upla di R$_1$ si combina con ogni n-upla di R$_2$
![[Pasted image 20251006212632.png]]

La cardinalità del risultato è il prodotto delle cardinalità 


### **OUTER JOIN (Giunzione esterna)**
• Una variante del JOIN per mantenere nel risultato le n-uple che non partecipano al JOIN 
• Gli attributi delle dangling n-uple vengono riempiti con NULL
(in pratica la JOIN normale prende le t-uple comuni ad un attributo specificato mentre la outer JOIN prende tutte le t-uple anche se non sono comuni a quelle non comuni scrive NULL)

• Tre varianti:
1) **Left**: solo dangling n-uple del primo operando 
2) **Right**: solo dangling n-uple del secondo operando 
3) **Full**: n-uple da entrambi gli operandi

**Definizione**
• Siano R ed S definite sugli insiemi di attributi XY e YZ rispettivamente.
$R \,\mathrel{\stackrel{\leftrightarrow}{\bowtie}}\, S =(R \bowtie S) \cup\bigl((R - \pi_{XY}(R \bowtie S)) \times \{Z = NULL\}\bigr) \cup\bigl(\{X = NULL\} \times (S - \pi_{YZ}(R \bowtie S))\bigr)$

**Altre Giunzioni Esterne**
Nelle giunzioni esterne sinistre e destre si aggiungono solo le parti sinistre e destre. • Siano R ed S definite sugli insiemi di attributi XY e YZ rispettivamente

**Definizione outer join sinistra**
$R \;\;\mathrel{\stackrel{\leftarrow}{\bowtie}}\;\; S = (R \Join S) \;\cup\;\big((R - \pi_{XY}(R \Join S)) \times \{Z = NULL\}\big)$

**Definizione outer join destra**
$R  \;\;\mathrel{\stackrel{\rightarrow}{\bowtie}}\;\; S = (R \Join S) \cup \big((S - \pi_{YZ}(R \Join S)) \times \{X = NULL\}\big)$

**Esempi di tutte e 3**
![[Pasted image 20251007094923.png]]


**Proprietà del JOIN**
- Commutativo: 𝑅 ⋈ 𝑆 = 𝑆 ⋈ 𝑅
- Associativo: (𝑅 ⋈ 𝑆) ⋈ 𝑇 = 𝑅 ⋈ (𝑆 ⋈ 𝑇)

cosi possiamo costruire sequenze senza ambiguità

**Esempio di JOIN multipli**
![[Pasted image 20251007095253.png]]

**Prodotto cartesiano a partire dal JOIN**
• Il JOIN è definito anche se non ci sono attributi comuni fra le relazioni 
• **In questo caso, non essendoci vincoli sulle tuple da selezionare, vengono selezionate tutte le tuple dalle relazioni del JOIN e quindi otteniamo un prodotto cartesiano**


**Esempio di prodotto cartesiano generato dal JOIN**
![[Pasted image 20251007095513.png]]


**Intersezione a partire dalla Natural Join**
Date due relazioni definite sulla stessa lista di attributi, allora il natural join coincide con l’intersezione delle due relazioni

### **SEMI-JOIN**
• Siano R con attributi XY ed S con attributi YZ 
• 𝑅 ⋉ 𝑆 è una relazione di attributi XY costituita da tutte le n-uple di R che partecipano a 𝑅 ⋈ 𝑆. 
![[Pasted image 20251007154527.png]]


### **UNIONE ESTERNA**
Siano R ed S due relazioni definite sugli insiemi di attributi XY e YZ allora:
• L’unione esterna
$R \overset{\leftrightarrow}{\cup} S = R \times \{Z = NULL\} \cup \{X = NULL\} \times S$
• si ottiene estendendo le due tabelle con le colonne dell’altra con valori nulli e si fa l’unione
![[Pasted image 20251007155027.png]]


### **SELEZIONE CON VALORI NULLI**
Questa è la tabella
![[Pasted image 20251007155909.png]]


questa è la query
![[Pasted image 20251007155934.png]]

Prenderà solo il 45 perche il 35 è minore di 40 e l'altro campo è NULL quindi non verrà preso, infatti:

𝜎𝐸ta>30(𝑃ersone) ∪ 𝜎𝐸ta≤30(𝑃ersone) ≠ 𝑃ersone
è diverso perché se ci sono campi NULL non verranno presi, quindi la tabella sarà diversa da Persone (che invece contiene campi NULL)

Per riferirsi ai valori nulli esistono forme apposite di condizioni: **IS NULL/ IS NOT NULL** 
Quindi: 
![[Pasted image 20251007160746.png|500]]

**Esempio**
![[Pasted image 20251007160829.png|500]]



### **QUOZIENTE**
Divisione: Siano XY gli attributi di R ed Y quelli di S, allora
𝑅 ÷ 𝑆 = {𝑤|𝑤 × 𝑆 ⊆ 𝑅}

La divisione serve a rispondere a query del tipo: trova TUTTE le n-uple di R associate a TUTTE le n-uple di S
![[Pasted image 20251009144502.png]]


### **Viste (relazioni derivate)**
Una vista è la tabella virtuale che si forma quando faccio una query

• Rappresentazioni diverse per gli stessi dati (schema esterno)

• Relazioni derivate: – relazioni il cui contenuto è funzione del contenuto di altre relazioni (definito per mezzo di interrogazioni) 
• Relazioni di base: contenuto autonomo – Le relazioni derivate possono essere definite su altre derivate

**Esempio**
![[Pasted image 20251009145510.png]]


Due tipi di relazioni derivate: – **viste materializzate** – **relazioni virtuali (o viste)** 

**Viste materializzate**
• relazioni derivate memorizzate nella base di dati – vantaggi: • immediatamente disponibili per le interrogazioni 
– **svantaggi**: 
• ridondanti 
• appesantiscono gli aggiornamenti 
• sono raramente supportate dai DBMS

• **Relazioni virtuali (o viste)**: 
– sono supportate dai DBMS (tutti) 
– una interrogazione su una vista viene eseguita "ricalcolando" la vista

**Viste come strumento di programmazione**
![[Pasted image 20251009145935.png]]

