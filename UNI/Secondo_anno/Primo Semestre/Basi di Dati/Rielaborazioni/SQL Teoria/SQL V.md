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