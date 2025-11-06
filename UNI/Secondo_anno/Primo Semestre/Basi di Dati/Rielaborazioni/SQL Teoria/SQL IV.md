### **VISTE**
Sono delle **tabelle ausiliarie** create "al volo" e vengono utilizzate per semplificare query, riorganizzare schemi e altro. 

Sintassi
`CREATE VIEW NomeVista [“(” Attributo {,Attributo} “)”] AS Query-Select`

crea una view chiamata NomeVista con vari attributi e questa vista va riempita con i risultati di Query-select 

**Esempio**
`CREATE VIEW MediaVoti (Matricola,Media) AS SELECT Matricola, AVG(Voto) FROM Esami GROUP BY Matricola`

**Con le view semplifico query complesse:**
Ad esempio NON possiamo scrivere:
`SELECT AVG(COUNT(*)) FROM AGENTI GROUP BY ZONE`
Perche count deve agire su un attributo, ma possiamo fare:

`CREATE VIEW AgPerZona (Zona,NumAg) AS 
`SELECT Zona,COUNT(*) FROM AGENTI GROUP BY Zona

`SELECT AVG(NumAg) FROM AgPerZona`

ho creato la vista che contiene il numero di agenti e la zona e poi faccio una seconda query che prende la media del numero agenti direttamente dalla vista

Le view possono essere usate come tabelle e possono anche essere cancellate come le tabelle:
`DROP (TABLE | VIEW) Nome [RESTRICT|CASCADE]`
La distruzione di una view non altera le tabelle su cui si basa

### **AGGIORNAMENTO DELLA VIEW**
• In genere una VIEW definita su una singola tabella è modificabile se gli attributi della VIEW contengono la chiave primaria (e altre chiavi) 
• In genere VIEW definite su più tabelle non sono aggiornabili – Alcuni DBMS, come discusso prima, lo permettono nel caso certe condizioni, molto restrittive, siano rispettate 
• VIEW che usano funzioni di aggregazione non sono aggiornabili 
• PRINCIPIO di base per l’aggiornamento delle VIEW: – Ogni riga ed ogni colonna della VIEW deve corrispondere ad una ed una sola riga ed una ed una sola colonna della tabella base

(visualizza esempi di query con le view nel PowerPoint 8 SQL IV [[8 lezione10_SQL_IV.pdf]] a pag 17-20)

L'algebra relazionale è molto potente e completa tutta via ci sono alcune operazioni che non possono essere fatte come ad esempio somme medie ecc...


