Abbiamo visto alcuni comandi e modi di fare le query ma se dovessimo agire anche in scrittura sul database? o crearlo? Ecco:

### **CREARE IL DATABESE: CREATE SCHEMA**
`CREATE SCHEMA Nome AUTHORIZATION Utente`
`Definizioni`

crea il database chiamato Nome, mentre Utente è l'amministratore del database, le definizioni creano gli altri elementi

### **DISTRUGGERE IL DATABESE: DROP SCHEMA**
`DROP SCHEMA Nome [RESTRICT | CASCADE]`
Cancella la base di dati chiamata Nome, e posso scegliere tra 2 opzioni:
- RESTRICT -> non distrugge il database se non è vuoto
- CASCADE -> rimuove automaticamente tutti i dati nel database

### **CREARE TABELLE: CREATE TABLE**
`CREATE TABLE Nome`
Definisce uno schema di relazione e ne crea un'istanza vuota 
vanno specificati attributi domini e vincoli

`CREATE TABLE Nome (Attributo Tipo[Vincolo {,Vincolo}]` 
`{,Attributo Tipo[Vincolo {,Vincolo}]}` 
`[,VincoloDiTabella {, VincoloDiTabella}])` 

Ad ogni attributo va dato un dominio o tipo:
• CHAR(n) stringhe di lunghezza n 
• VARCHAR(n) stringhe di lunghezza variabile con al massimo n caratteri 
• INTEGER interi 
• REAL reali 
• NUMERIC (p,s) p cifre di cui s decimali 
• FLOAT(p) es. 0.17E16 
• DATE,TIME per date ed ore

Normalmente i domini si inseriscono quando di crea una tabella ma per comodità si può creare un dominio "standard" che poi posso riusare anche il altre tabelle anziché riscriverle

**CREATE DOMAIN**
definisce un dominio (semplice), utilizzabile in definizioni di relazioni, anche con vincoli e valori di default

**Esempio**
`CREATE DOMAIN eta_valida AS INT`
    `CHECK (VALUE BETWEEN 18 AND 99);`

`CREATE TABLE Studenti (`
    `Matricola INT PRIMARY KEY,`
    `Nome VARCHAR(30) NOT NULL,`
    `Eta eta_valida`
`);`

`CREATE TABLE Docenti (`
    `ID INT PRIMARY KEY,`
    `Nome VARCHAR(30),`
    `Eta eta_valida`
`);`

### **VINCOLI DI INTEGRITA': NELLA STESSA TABELLA O TRA TABELLE**
Riguardano i valori ammissibili degli attributi di una tupla
Ne abbiamo 2 tipi: 
1) Vincoli intrarelazionali 
   nell’ambito della stessa relazione
2) Vincoli Referenziali (o Interrelazionali) 
   tra 2 o più relazioni

I vincoli vengono controllati durante le 3 possibili operazioni di modifica in SQL ovvero INSERT,DELETE e UPDATE
Devono essere sempre soddisfatti altrimenti la transazione fallisce

Servono a migliorare la qualità dei dati, a gestire con ordine la base di dati e anche per ottimizzare il sistema

**VINCOLI INTRARELAZIONALI**
sono:
• NOT NULL 
• UNIQUE definisce chiavi 
• PRIMARY KEY: chiave primaria (una sola, implica NOT NULL) 
• CHECK

PRIMARY KEY serve a definire una chiave primaria all'interno della tabella, implica NOT NULL e che non ci siano duplicati

**Esempio**
`CREATE TABLE Impiegato(` 
`Matricola CHAR(6) PRIMARY KEY,` 
`Nome CHAR(20) NOT NULL,` 
`Cognome CHAR(20) NOT NULL`
`UNIQUE (Nome, Cognome)`

UNIQUE indica che gli attributi Nome e Cognome siano sempre di versi (dalla parola appunto unici) 

**VINCOLI INTERRELAZIONALI**
sono:
• REFERENCES e FOREIGN KEY servono insieme per creare un vincolo di integrità referenziale

- `FOREIGN KEY` → _dichiara la colonna locale come chiave esterna_
    
- `REFERENCES` → _specifica dove punta quella chiave esterna

**Esempio**
`CREATE TABLE Infrazioni(` 
`Codice CHAR(6) NOT NULL PRIMARY KEY,` 
`Data DATE NOT NULL,` 
`Vigile INTEGER NOT NULL REFERENCES Vigili(Matricola),` 
`Provincia CHAR(2),` 
`Numero CHAR(6) ,` 
`FOREIGN KEY(Provincia, Numero)` 
`REFERENCES Auto(Provincia, Numero) )`

##### 🔹 1. `Vigile INTEGER NOT NULL REFERENCES Vigili(Matricola)`
Qui è usata la **forma abbreviata**:
- la colonna `Vigile` è la **chiave esterna**,
- e punta alla colonna `Matricola` della tabella `Vigili`.
👉 Significa: ogni valore in `Infrazioni.Vigile` deve già esistere in `Vigili.Matricola`

##### 🔹 2. `FOREIGN KEY (Provincia, Numero) REFERENCES Auto(Provincia, Numero)`
Qui è usata la **forma estesa**, necessaria perché la chiave esterna è **composta** (due colonne).
- insieme, `Provincia` e `Numero` identificano un’auto, 
- il vincolo impone che quei due valori esistano nella tabella `Auto`.
👉 Significa: ogni infrazione deve riferirsi a un’auto già registrata.

**Esempio di vincoli errati e poi corretti**
![[Pasted image 20251102153832.png|400]]
Ogni bordo contornato è un vincolo errato o omesso:
<font color="#a5a5a5">bordo grigio</font> -> manca il vincolo che matricola sia una primary key che quindi è univoca
<font color="#00b050">bordo verde</font> -> manca la referenziazione e la foreign key che indica che la matricola in esami debba esistere anche in studenti
<font color="#0070c0">bordo blu</font> -> manca il vincolo che implica che per avere la lode bisogna avere voto = 30
<font color="#974806">bordo marrone</font> -> manca il vincolo che implica che il voto sia compreso tra 18 e 30

Versione corretta

`CREATE TABLE Esami(` 
`Studente CHAR(6),` 
`Corso INTEGER,` 
`Voto INTEGER NOT NULL CHECK (Voto >= 18 AND Voto <= 30)` 
`Lode INTEGER NOT NULL DEFAULT 0,` 
`CHECK ((Lode = 0) OR (Voto = 30 AND Lode = 1)), PRIMARY KEY (Studente, Corso),` 
`FOREIGN KEY (Studente) REFERENCES Studenti(Matricola),` 
`FOREIGN KEY (Corso) REFERENCES Corsi(Corso) )`


**VINCOLI SU UNA N-UPLA**
- NOT NULL -> di default se l'attributo è primary key
- CHECK condizione -> controlla che una condizione sia vera (anche per attributi diversi della stessa n-upla)
- DEFAULT(Costante | NULL) -> applica di default una costante o NULL alla tupla dell'attributo

### **AZIONI PER VINCOLI SU CHIAVI ESTERNE**
- ON DELETE NO ACTION
  Rifiuta l'operazione quando si chiama delete
- ON DELETE CASCADE
  Cancella tutte le n-uple con valori della chiave esterna corrispondenti alla chiave primaria delle n- uple cancellate
- ON DELETE SET NULL 
  Assegna il valore NULL agli attributi della chiave esterna

### **MODIFICHE DEGLI SCHEMI**
- ALTER DOMAIN 
- ALTER TABLE 
- DROP DOMAIN 
- DROP TABLE



### **OPERAZIONI SUI DATI**
- Interrogazione (lettura)
  SELECT
- Modifica (scrittura)
  INSERT, DELETE, UPDATE

INSERT
Sintassi
`INSERT INTO Tabella [“(”Attributo {,Attributo}“)”]VALUES“(”Valore {,Valore} “)”`
**Esempio**
`INSERT INTO Esami (NomeEsame, Voto)`
`VALUES ('DB1', 27);`

DELETE
Sintassi
`DELETE FROM Tabella WHERE Condizione`
**Esempio**
`DELETE FROM Esami WHERE Matricola = 123456`

UPDATE
Sintassi
`UPDATE Tabella SET Attributo = Espr {,Attributo = Espr} WHERE Condizione`
**Esempio**
`UPDATE Aule SET Aula = 126 WHERE Aula = 3` 



