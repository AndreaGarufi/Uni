**Controllo dell'accesso**
In SQL è possibile specificare per ogni utente i **privilegi** che può avere, ovvero le operazioni che può fare e a quali dati può accedere, il creatore di una risorsa ha tutti i permessi per operare su di essa.

• Un privilegio è caratterizzato da: 
• la risorsa cui si riferisce 
• l'utente che concede il privilegio 
• l'utente che riceve il privilegio 
• l'azione che viene permessa 
• la trasmissibilità del privilegio

Concessione e revoca dei privilegi
**GRANT E REVOKE**

- concessione di privilegi
  `grant < Privileges | all privileges > on Resource to Users [ with grant option ]`
  
  letteralmente: concedi < privilegio | tutti i privilegi > sulla risorsa X agli utenti Y 
  grant option specifica se il privilegio può essere trasmesso ad altri utenti

- revoca di privilegi
  `revoke Privileges on Resource from Users [ restrict | cascade ]` 
  
  letteralmente: revoca i privilegi sulla risorsa X all'utente Y 
  restrict revoca solo a lui
  cascade revoca a tutti quelli che lo hanno direttamente o indirettamente ricevuto da lui

**Gestione**
La gestione delle autorizzazioni deve “nascondere” gli elementi cui un utente non può accedere, senza sospetti

Come faccio ad autorizzare un utente a vedere solo alcune ennuple di una tabella?
creo una vista con quello che può vedere e gli do il permesso di vedere quella vista

Esiste una estensione di SQL 1999 che fa:
Concetto di ruolo, cui si associano privilegi (anche articolati), poi concessi agli utenti attribuendo il ruolo (tipo i ruoli di discord nel server)

**TRANSAZIONI**
Una transazione è un insieme di operazioni indivisibile (atomiche), che o si fanno per interno o non si fanno per nulla, ad esempio:

trasferimento di fondi da un conto A ad un conto B: o si fanno il prelevamento da A e il versamento su B o nessuno dei due 

Per quanto riguarda i vincoli, devono essere rispettati dalla transazione, in pratica questo p quello che succede:
parte la transazione e continua anche se ci sono dei vincoli non soddisfatti, se alla fine della transazione i vincoli restano ancora insoddisfatti allora la transazione viene per intero annullata (abortita)

L'effetto di transazioni concorrenti deve essere **coerente** (ad esempio "equivalente" all'esecuzione separata) 
• se due assegni emessi sullo stesso conto corrente vengono incassati contemporaneamente si deve evitare di trascurarne uno 

I risultati delle transazioni sono durevoli, ovvero dopo che una è stata conclusa ne resta traccia in modo definitivo.


**Come inizia una transazione** 
Una transazione inizia subito dopo la connessione al database oppure quando ne finisce una
Possiamo concludere le transazioni come *commit* o *rollback*
- commit(work) -> Le operazioni specificate vengono eseguite sulla base di dati
- rollback(work) -> si decide di non eseguire le operazioni 

Molti sistemi prevedono un sistema di autocommit in cui ogni operazione forma una transazione

**Esempio di transazione in SQL**
`start transaction (opzionale)` 
`update ContoCorrente` 
`set Saldo = Saldo – 10` 
`where NumeroConto = 12345 ;` 
`update ContoCorrente` 
`set Saldo = Saldo + 10` 
`where NumeroConto = 55555 ;` 
`commit work;` 


**BASI DI DATI ATTIVE**
**TRIGGER**

• Paradigma: Evento-Condizione-Azione 
	• Quando un evento si verifica 
	• Se la condizione è vera 
	• Allora l’azione è eseguita

Abbiamo:
**Evento**
Di solito una modifica dello stato del database: insert, delete, update ecc...
Stato trigger: attivato

**Condizione**
E' un predicato che identifica se l'azione del trigger deve essere eseguita
Stato trigger: considerato

**Azione**
Una sequenza di update SQL o una procedura
Stato trigger: eseguito

I DBMS forniscono tutti i componenti necessari. Basta integrarli

• Ogni trigger è caratterizzato da: 
	• nome 
	• target (tabella controllata) 
	• modalità (before o after) 
	• evento (insert, delete o update) 
	• granularità (statement-level o row-level) 
	• alias dei valori o tabelle di transizione 
	• azione 
	• timestamp di creazione


**Sintassi trigger**
`create trigger TriggerName`
`{ before | after }`
`{ insert | delete | update [of Column] } on TableName`
`[referencing`
    `{ [old_table [as] OldTableAlias]`
      `[new_table [as] NewTableAlias] } |`
    `{ [old [row] [as] OldTupleName]`
      `[new [row] [as] NewTupleName] }]`
`[for each { row | statement }]`
`[when Condition]`
`SQL Statements`

Tipi di eventi:
- **BEFORE**
  Il trigger è considerato e possibilmente eseguito prima dell'evento
  Normalmente questa modalità è usata quando si vuole verificare una modifica prima che essa avvenga e “modificare la modifica”
- **AFTER**
  Il trigger è considerato ed eseguito dopo l'evento
  Questa è la modalità più comune
  
**Esempio con after**
`create trigger LimitaAumenti` 
`after update of Salario on Impiegato` 
`for each row` 
`when (New.Salario > Old.Salario * 1.2)` 
`UPDATE Impiegato SET Salario = Old.Salario * 1.2` 
`WHERE Matricola = NEW.Matricola`


**Granularità degli eventi**
Abbiamo 2 modalità di agire per i trigger
- Modalità statement-level (opzione for each statement)
  Il trigger viene considerato e possibilmente eseguito solo una volta per ogni statement (comando) che lo ha attivato, indipendentemente dal numero di tuple modificato
- Modalità row-level (opzione for each row)
  Il trigger viene considerato e possibilmente eseguito una volta per ogni tupla modificata


**CLAUSOLA REFERENCING**
Questa clausola dipende dalla granularità
• Se la modalità è *row-level*, ci sono due variabili di transizione (old and new) che rappresentano il valore precedente o successivo alla modifica di una tupla 

• Se la modalità è *statement-level*, ci sono due tabelle di transizione (old table and new table) che contengono i valori precedenti e successivi delle tuple modificate dallo statement

• old e old_table non sono presenti con l’evento insert 
• new e new_table non sono presenti con l’evento delete

**Esempio di trigger row-level**
`create trigger AccountMonitor` 
`after update on Account` 
`for each row` 
`when new.Total > old.Total` 
`insert into Payments` 
`values (new.AccNumber,new.Total - old.Total)`

Letteralmente vuol dire:
crea trigger che si chiama AccountMonitor, dopo la modifica (update) su Account, per ogni riga modificata, quando new.total > old.total, inserisci in Payments i valori:(new.AccNumber,new.Total - old.Total)

**Esempio di trigger statement-level**
`create trigger FileDeletedInvoices` 
`after delete on Invoice` 
`referencing old_table as OldInvoiceSet` 
`insert into DeletedInvoices` 
`(select * from OldInvoiceSet)` 

Letteralmente vuol dire:
crea trigger che si chiama FileDeletedInvoices, dopo la cancellazione su Invoice, crea un alias (referencing) di old_table chiamato OldInvoiceSet, inserisci in DeletedInvoices (fa una select)


**TRIGGER IN CONFLITTO**
Quando ci sono più trigger associati allo stesso evento (in conflitto) i questi vengono  eseguiti così:
1) I trigger BEFORE
2) Vengono eseguite le modifiche
3) I trigger AFTER

Quando i trigger appartengono alla stessa categoria l'ordine di esecuzione è in base al loro timestamp ovvero in base a quando sono stati scritti, quelli più vecchi vengono eseguiti per primi

Altri trigger possono attivare altri trigger

**PROPRIETÀ FORMALI DEI TRIGGER**
E' importante garantire che l'interferenza tra trigger non produca comportamenti anomali:
Vi sono 3 proprietà classiche

1) Terminazione: per un qualunque stato iniziale e una qualunque transazione, si produce uno stato finale (stato quiescente)
2) Confluenza: L’esecuzione dei trigger termina e produce un unico stato finale, indipendente dall’ordine di esecuzione dei trigger
3) Univoca osservabilità: I trigger sono confluenti e producono verso l’esterno (messaggi, azioni di display) lo stesso effetto

La terminazione è la proprietà principale
**Analisi della terminazione**
Si usa il **grafo di triggering** 
- Uno nodo per ogni trigger
- Un arco dal nodo $t_i$ al nodo $t_j$ se l'esecuzione dell'azione di $t_i$ può attivare il trigger $t_j$
- Se il grafo è aciclico l'esecuzione termina
- Se il grafo ha cicli allora *può* avere problemi di terminazione (ma non è sicuro)


