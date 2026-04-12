
### IPv4
Un indirizzo IP ha un valore gerarchico, ci aiuta già a sapere come arrivare a destinazione, un indirizzo IP quindi è un codice associato ad un dispositivo. Esistono diverse classi di indirizzi
![[Pasted image 20260407103211.png|590]]
Gli indirizzi IP a livello rete hanno una struttura gerarchica (il mac address (indirizzo macchina) non cambia mai, l'ip si - continuamente). 

Esistono degli indirizzi IP speciali:
- *0.0.0.0*: this host, è l'indirizzo della macchina quando non gli ancora stato assegnato un IP (vale solo per IPv4)
- *255.255.255.255*: indirizzo di broadcast
- *127.0.0.0 - 127.255.255.255*: indirizzi di loopback (vengono utilizzati per quando la macchina parla con se stessa)
- *10.0.0.0 - 10.255.255.255*: sono indirizzi IP privati, vengono usati all'interno delle reti locali. (questi sono quelli privati della classe B, esistono per ogni classe)

Con il passare del tempo si pensa alla spaziatura variabile, ovvero non usare la divisione (indirizzi per la rete - indirizzi per l'indirizzamento) delle classi predefinite, con la spaziatura variabile è il tecnico a decidere quanti bit usare per indirizzi e quanti per la rete, da qui nasce la *subnet-mask*

### Subnet mask
La maschera di rete con la notazione /X ci indica il primi X bit dedicati alla rete (32-X saranno quelli riservati agli indirizzi)
![[Pasted image 20260407111150.png|500]]
**Utilizzo della subnet mask**
La maschera di rete viene usata per capire se un host alla quale inviare il pacchetto si trova in questa sotto-rete e agire di conseguenza. Oltre all'indirizzo IP/maschera ogni dispositivo nella rete ha anche un indirizzo fisico chiamato MAC, questo è univoco per ogni scheda di rete. Per indirizzare a livello fisico è importante avere un modo per riuscire ad ottenere l'indirizzo MAC partendo da IP, questo viene fatto usando il protocollo ARP

### Protocollo ARP (Address Resolution Protocol)
Traduci gli indirizzi IP in MAC address

Ogni nodo della rete contiene una tabella ARP  i cui record contengono tre valori: Indirizzo IP - Indirizzo MAC - Time To Live. Il time-to-live specifica tra quanto tempo quel determinato record dovrà essere eliminato dalla tabella (20 minuti ad esempio). Distinguiamo i seguenti casi:

- *ARP sulla stessa rete*
1. Se un datagramma deve essere mandato da un host A a un host B nella stessa sottorete, A dovrà conoscere l’indirizzo MAC di quel dispositivo. 
2. Se l’indirizzo MAC è già presente nella ARP del nodo, questo manderà il datagramma senza ulteriori passaggi. 
3. Altrimenti, manderà una cosiddetta ”richiesta ARP” contenuta in un pacchetto ARP mandato all’indirizzo broadcast della rete FF-FF-FF-FF-FF-FF. 
4. Il pacchetto conterrà sia l’indirizzo IP e MAC del mittente, che l’indirizzo IP del destinatario. 
5. La richiesta broadcast verrà mandata a tutte le schede di rete della sottorete. La risposta ARP verrà mandata in modalità non-broadcast dal dispositivo con indirizzo IP uguale a quello della richiesta, verso il richiedente. La risposta ARP conterrà al suo interno l’indirizzo MAC del ricevente della richiesta, e la tabella ARP verrà aggiornata.

- *ARP su rete diversa*
Alice desidera mandare un messaggio a Bob, collegato ad una sottorete diversa. 
1. Alice manda il datagramma alla sua scheda di rete. Dovrà indicare l’indirizzo MAC dell’interfaccia del router a cui è collegato. Se l’indirizzo MAC è già presente nella tabella ARP di Alice, questo manderà il datagramma al router. 
2. Altrimenti, userà il protocollo ARP per ottenere l’indirizzo MAC. Manderà una richiesta ARP all’indirizzo broadcast della rete FF-FF-FF-FF-FF-FF, contenente l’indirizzo IP del router. Il router, riconoscendo il proprio indirizzo, risponderà con una ARP reply condividendo ad Alice il proprio indirizzo MAC. Alice memorizzerà il nuovo indirizzo MAC appena scoperto nella propria tabella ARP, e manda il proprio frame.
   ![[Pasted image 20260407161125.png|544]]

3. Il router confronta l’IP del pacchetto con la propria tabella di inoltro. Sa che il pacchetto deve essere inoltrato all’interfaccia 2, ma non conosce l’indirizzo MAC del destinatario Bob.
   ![[Pasted image 20260407161213.png|549]]

4. Il router manda la richiesta ARP, lo switch la manda in broadcast a tutti i dispositivi connessi. Bob riconosce l’indirizzo IP della richiesta ARP, e manda una risposta ARP. Il router riceverà l’indirizzo MAC di Bob, lo conserverà nella propria ARP table assieme al suo IP.
   ![[Pasted image 20260407161248.png|561]]

5. Il router avrà tutto il necessario per inoltrare il pacchetto a Bob, ed è ciò che farà.

Notiamo che, dopo aver ottenuto tutti gli indirizzi necessari, tramite protocollo ARP, per tutta la durata delle entries nella tabella ARP, l’inoltro sarà presumibilmente molto più veloce.


> [!DANGER] SICUREZZA
> Questo protocollo ha diverse criticità, lato sicurezza.

**La mancanza di Autenticazione**
Infatti quando viene mandata una richiesta ARP viene scelta la prima risposta anche se non è quella dell'interessato, questo perché non si chiedono verifiche o certificati, di conseguenza si possono avvelenare le ARP table degli altri dispositivi cambiandone l'indirizzo MAC associato all' IP e questo porta a diversi tipi di danni:
1) man-in-the-middle
2) Denial of Service (DoS)
3) Session Hijacking.

