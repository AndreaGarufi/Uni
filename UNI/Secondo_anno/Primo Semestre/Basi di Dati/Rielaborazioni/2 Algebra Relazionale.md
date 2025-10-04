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

ciao