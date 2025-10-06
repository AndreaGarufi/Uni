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
