Nell'algebra booleana ogni valore può assumere solo 2 valori: 0(falso) e 1(vero)

Le **3 principali** operazioni sono:
**Somma Logica OR**
**Prodotto Logico AND**
**Negazione NOT**
ciascuna prende in ingresso 1 o più variabili binarie e restituisce un'altra variabile binaria


**OR**
restituisce 1 solo se almeno un ingresso è 1
si denota con "+" o "v"
![[Pasted image 20241123105217.png|300]]

TAVOLA DI VERITA
![[Pasted image 20241123105233.png|200]]

![[Pasted image 20241123105322.png|600]]



**AND**
restituisce 1 solo se tutti i valori in ingresso sono 1
si denota con “·” o “∧”
![[Pasted image 20241123105645.png|300]]

TAVOLA DI VERITA
![[Pasted image 20241123105702.png|200]]

![[Pasted image 20241123105720.png|600]]

**NOT**
restituisce 1 se l'ingresso è 0 (fa l'opposto del valore iniziale)
si denota con “¯" o “¬”
![[Pasted image 20241123105905.png|300]]

TAVOLA DI VERITA
![[Pasted image 20241123105925.png|200]]


ALTRE PROPRIETA
![[Pasted image 20241123110007.png]]


![[Pasted image 20241123141833.png]]

**GLI OPERATORI HANNO DELLE PRECENDENZE SECONDO CUI VANNO ESEGUITE LE OPERAZIONI:**
**NOT = 1
AND = 2
OR = 3**
Quindi in un'espressione vanno prima eseguite le negazioni, poi gli and e poi gli or
Per forzare la precedenza di un operatore si possono usare le parentesi


●**Mintermine**: funzione a n variabili che vale 1 solo per una specifica configurazione delle variabili
 ●**Maxtermine**: funzione a n variabili che vale 0 solo per una specifica configurazione delle variabili

**Forma minima**
●**Una espressione si dice in forma minima quando non esiste nessun altra espressione equivalente con un costo inferiore**
●**il criterio di costo dei LETTERALI**: il costo di un espressione è dato dal numero di comparse di variabili nell’espressione stessa 
●**Un’espressione in forma minima è più semplice ed economica da realizzare come circuito rispetto alle altre forme** 

![[Pasted image 20241123142757.png|400]]


I circuiti che compongono AND NOT OR sono chiamano **porte**, una rete di porte logiche è una **rete combinatoria** 

Ecco come si rappresentano queste porte logiche
![[Pasted image 20241124091802.png]]

**Grazie alla proprietà associativa AND e OR possono essere estese a più di 2 ingressi:**
![[Pasted image 20241124091932.png]]


Un altro operatore logico importante è lo **XOR** (OR esclusivo) che restituisce 1 solo se le entrate 1 sono dispari, e si denota con “⊕” 
TABELLA DI VERITA
![[Pasted image 20241124092839.png|200]]
Questa è la sua porta logica:
![[Pasted image 20241124092921.png|350]]


Altre 2 porte logiche di largo uso sono **NAND** e **NOR** (ovvero AND e OR negati)
si denotano con   (NOR) "↓"     (NAND)"↑"
TABELLA DI VERITA 
![[Pasted image 20241124093430.png|200]]

![[Pasted image 20241124093451.png|450]]


●**NAND e NOR sono porte UNIVERSALI**: Si può realizzare una qualsiasi funzione combinatoria con reti logiche di soli NAND o soli NOR

**NAND e NOR godono della proprietà commutativa ma non di quella associativa**
per questo la porta NAND a più ingressi si visualizza così:
![[Pasted image 20241124094027.png]]

