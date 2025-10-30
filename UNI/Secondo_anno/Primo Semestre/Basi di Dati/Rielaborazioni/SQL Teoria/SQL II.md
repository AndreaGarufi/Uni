Riassumiamo la sintassi della SELECT:
![[Pasted image 20251030161432.png|700]]


Facciamo un esempio:
![[Pasted image 20251030162023.png]]

Creare una query che restituisca: nome, matricola, voto minimo, voto massimo, voto medio per gli studenti che hanno dato più di 8 materie


`SQL SELECT studenti.nome,studenti.matricola AVG(voto),MIN(voto),MAX(voto)
`FROM studenti, esami
`WHERE studenti.matricola = esami.matricola
`GROUP BY studenti.nome,studenti.matricola
`HAVING COUNT(*) > 8`

Letteralmente prendo nome matricola AVG MIN MAX dove la matricola di studenti combacia con quella di esami, ordino per nome e matricola quello che trovo e poi quando conto tutto deve essere > 8.


**SOTTOSELECT**
Per semplificare le query si possono fare delle sottoselect
-  un modo è quello di scrivere la condizione `WHERE 'operatore' (sottoselect)`
   La sottoselect è importante che abbia come risultato un solo elemento oppure che sia vuota altrimenti questa tipologia di confronti non avrebbe senso
   **Esempio**
   `SELECT Nome, Reddito FROM Persone WHERE Nome = ( SELECT Padre FROM Paternita WHERE Figlio = 'Franco')`
- Il altri tipi di confronti posso anche utilizzare ANY e ALL
  • ANY (sottoselect): il predicato è vero se almeno uno dei valori restituiti da Query soddisfano la condizione 
  • ALL (sottoselect): il predicato è vero se tutti i valori restituiti dalla Query soddisfano la condizione
  • {NOT} EXIST (sottoselect): Il predicato è vero se la SelectQuery restituisce almeno una tupla
  • {NOT} IN (sottoselect): 
  **Esempi**
  `WHERE Prezzo > ANY (SELECT Prezzo FROM Prodotti WHERE Categoria = 'B')`
  `WHERE Prezzo > ALL (SELECT Prezzo FROM Prodotti WHERE Categoria = 'B')`
  `WHERE Città IN (SELECT Città FROM Filiali)`
  `WHERE EXISTS (SELECT * FROM Ordini O WHERE O.IDCliente = C.IDCliente)`

Le sottoquery non possono contenere operatori insiemistici come l'unione (si fa alla fine in caso)

**REGOLE DI VISIBILITA'**
- Non è possibile fare riferimenti a variabili definite in blocchi più interni
- Se un nome di variabile è omesso, si assume riferimento alla variabile più “vicina”
- In un blocco si può fare riferimento a variabili definite in blocchi più esterni
- La query più interna può usare variabili della query esterna 
- L’interrogazione interna viene eseguita una volta per ciascuna ennupla dell’interrogazione esterna

