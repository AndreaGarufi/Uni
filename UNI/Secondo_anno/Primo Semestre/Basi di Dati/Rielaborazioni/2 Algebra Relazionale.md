Da cosa è composta?

• Un set di operatori che 
	– Sono definiti sulle relazioni (relazione = tabella)
	– Producono come risultato una relazione 

• Gli operatori possono essere combinati per formare espressioni complesse

• **Gli operatori primitivi dell’Algebra Relazionale sono**:
	1) Ridenominazione; 
	2) Unione; 
	3) Differenza; 
	4) Proiezione; 
	5) Restrizione (o Selezione); 
	6) Prodotto. 

• **I simboli**: 
	• R,S,... denotano relazioni, 
	• A, B,…attributi 
	• X,Y,…insiemi di attributi


### **RIDENOMINAZIONE**
![[Pasted image 20251003191612.png]]

Uso il delta che è l'operatore di ridenominazione, per sostanzialmente rinominare *Codice Studente* con *matricola* all'interno della relazione *STUDENTE*


### **UNIONE DIFFERENZA E INTERSEZIONE**
Le relazioni sono come gli insiemi quindi possiamo applicare gli operatori su insiemi, **il risultato deve essere un set omogeneo di n-uple quindi li applichiamo solo su relazioni con gli stessi attributi** 

Siano R ed S relazioni dello stesso tipo allora
![[Pasted image 20251003192611.png|400]]



**Esempio** **UNIONE**
![[Pasted image 20251003193339.png]]
prendo istanze degli attributi comuni e non comuni 1 sola volta

**Esempio INTERSEZIONE** 
![[Pasted image 20251003193442.png]]
prendo istanze degli attributi comuni a entrambi 1 sola volta

**Esempio DIFFERENZA** 
![[Pasted image 20251003193539.png]]
tolgo le istanze comuni a tutti e 2

Posso ovviamente combinare varie operazioni

### **PROIEZIONE**
Prende tutte le n-uple da un sottoinsieme di attributi, in pratica sceglie tutti dati da alcune colonne scelte

**Definizione:**
– Sia R una relazione e siano $A_1$, $A_2$,…, $A_n$ alcuni suoi attributi allora: 
𝜋$𝐴_1$,$𝐴_2$…,$𝐴_𝑛$$(R)$ = {𝑡 $[𝐴_1, 𝐴_2 … , 𝐴_𝑆]$ | 𝑡 ∈ 𝑅}

La cardinalità della proiezione può essere minore di R nel caso di duplicati

**Esempio PROIEZIONE**
![[Pasted image 20251004103710.png]]


### **RESTRIZIONE O SELEZIONE**
Prende alcune t-uple da tutti gli attributi

**Definizione**
Sia R una relazione allora:

𝜎𝜆 (𝑅) = {𝑡|𝑡 ∈ 𝑅 ∧ 𝜆 𝑡 = TRUE}
(operatore selezione su R = t dove t appartiene a R AND "formula proposizionale generica sugli attributi di R" quando sono vere)

(dove 𝜆 è una formula proposizionale costruita a partire dagli atomi A 𝜃 B e utilizzando i connettivi proposizionali ∧,∨, ∼ 
– A e B sono attributi di R o costanti e 𝜃 = {=,<, >, ≠, ≤, ≥})
![[Pasted image 20251004105159.png]]

### **PRODOTTO CARTESIANO**
Sia R una relazione con attributi e S un'altra relazione con attributi diversi (infatti l'intersezione tra attributi deve essere vuota)
Allora si pone:
𝑅 × 𝑆 = {𝑡$u$|𝑡 ∈ 𝑅 ∧ $u$ ∈ 𝑆}

**Esempio PRODOTTO CARTESIANO**
![[Pasted image 20251004105644.png]]

### **JOIN (GIUNZIONE)**
**L’operatore più importante dell’algebra relazionale** 
• Permette di combinare t-uple da relazioni diverse basandosi sui valori degli attributi

• Fondamentalmente due tipi (più qualche variante): 
1) Natural JOIN 
2) Theta JOIN

**NATURAL JOIN**
Sia R con attributi $XY$ ed S con attributi $YZ$ 
• 𝑅 ⋈ 𝑆 e’ una relazione di attributi $XYZ$ costituita da tutte le n-uple t tali che $t[XY]$ ∈ 𝑅  e $t[YZ]$∈ 𝑆 
• Quindi:
𝑅 ⋈ 𝑆 = {𝑡|$t[XY]$ ∈ 𝑅 e $t[YZ]$ ∈ 𝑆}

**Cioè: le n-uple del risultato sono ottenute combinando le n-uple di R e S che hanno gli stessi valori negli attributi con lo stesso nome** 
**Esempio NATURAL JOIN**
![[Pasted image 20251004113858.png]]

![[Pasted image 20251004114041.png]]


**THETA-JOIN e EQUI-JOIN**
Estensione del NATURAL JOIN
• Viene specificato un predicato per la selezione delle n-uple 
• E’ un operatore derivato:
𝑅 ⋈$_𝐹$ 𝑆 = 𝜎𝐹 (𝑅 × 𝑆)

Quando $F$ è una congiunzione di uguaglianze si parla di equi-JOIN altrimenti theta-JOIN
**Esempio EQUI-JOIN**
![[Pasted image 20251004114513.png]]

**Definizione**
![[Pasted image 20251004114718.png]]



### **QUERY**
