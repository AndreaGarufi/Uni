SQL = Structured Query Language

### **SELECT**
Sintassi Generale
![[Pasted image 20251027212601.png|400]]


1) La Query considera il prodotto cartesiano tra le *tabelle in tabelle*
2) Fra queste seleziona solo le righe che soddisfano la *condizione*
3) infine valuta le espressioni specificate nella target list *Attributi* (oppure `*` se si vuole prendere tutto)

La select implementa: ridenominazione, proiezione, selezione e join e ancora altro

**Scrittura comandi SQL**
- I comandi di SQL non sono *case sensitive*
- possono essere distribuiti su una o più righe
- le parole chiave non possono essere abbreviate o spezzate in 2 linee

**Espressioni Aritmetiche**
![[Pasted image 20251028151915.png|450]]


Uso degli operatori
![[Pasted image 20251028152003.png|400]]
ovviamente gli operatori hanno precedenza infatti:
![[Pasted image 20251028152046.png|450]]

Posso cambiare la precedenza degli operatori con l'uso delle parentesi

**ALIAS**
Posso rinominare delle colonne, spesso si fa per comodità o per capire meglio quello che si sta facendo, opzionalmente si può mettere la parola chiave *AS*, se l'alias ha uno spazio vanno usate le virgolette
![[Pasted image 20251028152346.png|450]]

Stessa cosa vale anche per le tabelle:
![[Pasted image 20251028152444.png|450]]

Se nelle select uso degli attributi non *univoci* tra loro devo mettere "nomeTabella"."attributo" 

**Eliminazione delle righe duplicate**
Per fare ciò si usa la parola chiave *distinct* 
![[Pasted image 20251028152824.png|390]]

### **CLAUSOLA WHERE**
La si usa per limitare le righe selezionate (è a tutti gli effetti una condizione) ![[Pasted image 20251028153058.png]]
Quindi la clausola WHERE segue FROM
A disposizione ho degli operatori di confronto:
![[Pasted image 20251028153149.png|300]]

**Esempio**
![[Pasted image 20251028153443.png|400]]

Esistono anche altri predicati di confronto li elenco e li spiego:
![[Pasted image 20251028153544.png|450]]

1) **Between...and...**
   Consente la selezione di righe in un particolare range
   **Esempio**
   ![[Pasted image 20251028154232.png|600]]
2) **In**
   Si usa per scegliere un valore di un attributo che è contenuto dentro una lista
   **Esempio**
   ![[Pasted image 20251028154350.png|600]]
3) **Like**
   Like è usato per cercare delle determinate stringhe all'interno dei valori degli attributi
   - _ -> denota un singolo carattere
   - % -> denota più caratteri
   - se si deve cercare _ o % si usa lo \
   **Esempio**![[Pasted image 20251028154526.png|600]]
   (cerca dove i valori di ename hanno A per seconda lettera)
4) **Is {not} NULL**
   Cerca gli attributi in cui i valori sono NULL o scarta a seconda se NOT è incluso o meno
   ![[Pasted image 20251028155140.png|500]]

 **Operatori Logici**
 Permettono di esprimere condizioni più elaborate e sono:
 ![[Pasted image 20251028155259.png|500]]
 **Esempio**
 ![[Pasted image 20251028155323.png|500]]

Ci sono delle regole di precedenza da rispettare:
![[Pasted image 20251028155433.png|500]]
Regole che possono essere modificate con l'uso delle parentesi


### **CLAUSOLA ORDER BY**
La clausola è inserita per ultima nelle query select e ordina le righe in maniera ascendente (ASC -> ordine di default) o discendente (DESC)
![[Pasted image 20251028155824.png]]
(Se lo voglio in ordine decrescente aggiungo DESC dopo hiredate)

Posso usare anche gli alias per ordinare
![[Pasted image 20251028155934.png|500]]



**Unione, intersezione e differenza**
La SELECT da sola non permette di fare unioni; serve un costrutto esplicito:
- UNION
- INTERSECTION
- EXCEPT

I duplicati si eliminano per mantenerli si usa ALL
**Esempio**
![[Pasted image 20251028161019.png|400]]


### **OPERATORI AGGREGATI**
Non sono rappresentabili in algebra relazionale ma sono costrutti molto utili:
– AVG -> media aritmetica
– COUNT -> conta il numero di un determinato valore
– MAX -> massimo
– MIN -> minimo
– SUM -> somma degli attributi

Possono essere usati su dati numerici tranno min e max che si possno usare su qualsiasi tipo
(solitamente si mettono dopo la select)
**Esempio**
![[Pasted image 20251028161401.png|500]]

(• `count(*)` come detto restituisce il numero di righe 
• `count(attributo)` il numero di valori di un particolare attributo non NULL)

**Osservazioni**
• Se una colonna A contiene solo valori nulli, MAX, MIN, AVG, SUM restituiscono NULL, mentre Count vale zero. 
• AVG, SUM ignorano i valori nulli

### **CLAUSOLA GROUP BY**
Divide le righe di una tabella in gruppi più piccoli
come dice il nome raggruppa per(espressione)
![[Pasted image 20251028161838.png|400]]


### **CLAUSOLA HAVING**
Restriziona il risultato
**Esempio**
![[Pasted image 20251028162219.png|500]]




Ordine di valutazione delle clausole: 
1) WHERE 
2) GROUP BY 
3) HAVING

