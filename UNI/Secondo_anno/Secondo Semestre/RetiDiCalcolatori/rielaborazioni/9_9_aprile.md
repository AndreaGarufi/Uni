
### RARP (protocollo obsoleto per ottenere un indirizzo IP)
la macchina conosce il suo indirizzo mac e invia una richiesta broadcast per avere un indirizzo IP 
![[Pasted image 20260409104223.png|500]]

### Comunicazione in LAN usando ARP
![[Pasted image 20260409105101.png|500]]

L'obiettivo di questa procedura è permettere a un host mittente di capire se il destinatario si trova nella sua stessa rete locale o in una rete esterna, in modo da sapere a chi consegnare fisicamente il pacchetto dati, e si fa un AND per capirlo

- **Fase 1**:  prima di inviare qualsiasi richiesta ARP, il mittente deve fare un calcolo matematico usando la sua Subnet Mask:
	1. *Trova la propria rete:* Esegue un'operazione bit a bit (`AND` logico) tra il proprio IP Sorgente e la Subnet Mask. Il risultato è l'indirizzo della rete a cui appartiene.
	2. *Stima la rete del destinatario*: Esegue la stessa operazione `AND` tra l'IP di Destinazione e la propria Subnet Mask.
	3. Il Confronto (`= ?`): Se i due risultati coincidono, le macchine sono sulla stessa rete. Se differiscono, il destinatario si trova su una rete remota.
- **Fase 2:** In base al risultato del confronto precedente, il mittente si comporta in due modi distinti:
	- **Caso A: Stessa rete (Destinazione Locale)**
	    - Il pacchetto non deve uscire dalla rete (non serve il router).
	    - Il mittente invia una richiesta **ARP in broadcast** chiedendo: _"Qual è l'indirizzo MAC associato a questo IP di destinazione?"_.
	    - L'host destinatario risponde fornendo il proprio MAC address, permettendo al mittente di recapitargli il frame direttamente.
	- **Caso B: Reti diverse (Destinazione Remota)**
	    - Il mittente sa di non poter raggiungere il destinatario direttamente. Deve affidare il pacchetto al **Default Gateway** (il Router), che farà da postino per le reti esterne.
	    - Il mittente invia una richiesta **ARP in broadcast**, ma questa volta chiede: _"Qual è l'indirizzo MAC del mio Default Gateway?"_ (Attenzione: non cerca il MAC del destinatario finale).
	    - Il router risponde con il proprio MAC address. Il mittente invia il frame al router, che si occuperà di instradarlo verso la destinazione finale.


### DHCP - Dynamic Host Configuration Protocol (attuale)
Questo protocollo serve per assegnare in modo dinamico un indirizzo IP ad ogni dispositivo nella rete. In una qualsiasi rete abbiamo un DHCP server che assegna indirizzi in tutta la rete. Nello specifico viene fatta in questo modo:
![[Pasted image 20260409105901.png|500]]
Il client manda una DHCP discover in broadcast presentandosi con l'indirizzo IP di base che è 0.0.0.0, il server DHCP riceve questo messaggio e manda una DHCP offer al client, in cui comunica quale sarà l'indirizzo e per quanto tempo quell'indirizzo può essere usato, se il client accetta manda una DHCP request e il server risponde con una DHCP ACK da questo momento fino allo scadere del timer il client può usare quell'indirizzo IP
(Nelle reti domestiche solitamente è il router di casa a fare anche da DHCP)

### NAT - Network address translation
Tutti i dispositivi in una rete locale condividono un singolo indirizzo IP su internet, questo lo fanno grazie al NAT, un servizio offerto dal router che ci permette di tradurre degli indirizzi privati (dei dispositivi interni della rete) in indirizzi pubblici (usati in internet)
![[Pasted image 20260409115653.png|500]]
Quindi i messaggi al router arrivano tutti allo stesso IP sarà poi il router a mandarli agli host giusti

![[Pasted image 20260409121123.png|500]]

1. **Invio del datagramma (Host interno):** L'host locale con indirizzo IP 10.0.0.1 invia un datagramma verso un server esterno (IP 128.119.40.186) sulla porta 80. Il pacchetto sorgente ha come coordinate `10.0.0.1, 3345`.
2. **Traduzione e aggiornamento tabella (Router NAT):** Il router NAT riceve il pacchetto e sostituisce l'indirizzo IP e la porta sorgente privati con il proprio indirizzo IP pubblico e una porta univoca: cambia quindi da `10.0.0.1, 3345` a **`138.76.29.7, 5001`**. Contemporaneamente, memorizza questa associazione nella sua *tabella di traduzione NAT*.
3. **Arrivo della risposta (Rete esterna):** Il server remoto risponde inviando un pacchetto che ha come destinazione l'indirizzo pubblico del router: **`138.76.29.7, 5001`**.
4. **Inoltro all'host locale (Router NAT):** Il router riceve la risposta, consulta la tabella NAT e vede che la porta 5001 corrisponde all'host interno 10.0.0.1 sulla porta 3345. Sostituisce quindi l'indirizzo di destinazione e inoltra il pacchetto all'host corretto nella rete locale.


*Ma perché serve usare il NAT?*
Semplicemente prima o poi gli indirizzi IPv4 finiranno perché con il passare del tempo aumentano sempre di più i dispositivi che hanno bisogno di un indirizzo IP, quindi intanto si può tamponare con il NAT che fa usare molti meno indirizzi IPv4, per questo motivo è stato creato il protocollo IPv6

### IPv6
IPv6 implementa:
• Header più semplici. 
• Sicurezza, tramite un supporto nativo (IPsec). 
• Quality of Service migliorata. 
• Supporto a comunicazione multicast e anycast.


Campi e funzionalità rimosse
• Frammentazione e riassemblaggio. 
• Checksum dell’header rimosso. 
• TTL - Time To Live. 
• Options

Struttura del datagramma IPv6
![[Pasted image 20260413115426.png|655]]

• Version - Versione. Indica la versione di IP usata dal datagramma. 4 bit. 

• Traffic Class - Classe di traffico. Somiglia al Type of Service di IPv4. Specifica la priorità di un determinato datagramma all’interno di un flusso. VoIP manderà datagrammi di priorità più alta rispetto a SMTP. 8 bit. 

• Flow label - Etichetta di flusso. Identifica un flusso di datagrammi. 20 bit. 

• Payload length - Lunghezza del Payload. Interpretato come un unsigned int, indica il numero di byte del datagramma IPv6 a seguire dell’header di dimensione fissa. Il massimo di dati che è possibile trasportare sul payload, è di 216 − 1 = 65, 535. 16 bit. 

• Next header - Prossimo header. Specifica il tipo del prossimo header. Questo, può essere l’header del protocollo del livello di trasporto (TCP: 6, hex 0x06, UDP: 17, hex 0x11), o un header aggiuntivo (extension header ). Ognuno di questi header aggiuntivi, contiene al suo interno anche il campo next header, in modo da poter costruire, su un datagramma, una ”catena di header”. In questa catena, l’ultimo header aggiuntivo contiene al suo interno il tipo dell’header del livello di trasporto. 8 bit. Tra questi header aggiuntivi, abbiamo, ad esempio Authentication Header (AH): 51 e Encapsulating Security Payload (ESP): 60, entrambi meccanismi di IPsec. 

• Hop limit - Limite di Hop. Un numero che viene decrementato ad ogni inoltro, da parte di router, del datagramma che lo contiene. Quando questo numero diventa 0, viene cestinato. 8 bit. 

• Indirizzi. Sorgente e destinazione, entrambi a 128 bit. 

• Dati.

In breve comunque il vantaggio maggiore (e anche il motivo per cui è stato creato) è che abbiamo un numero totale di indirizzi pari a $2^{128}$ rispetto ai $2^{32}$ di IPv4

Gli indirizzi IPv6 sono scritti in esadecimale perché molto lunghi:
8000:0000:0000:000:0123:4567:89AB:CDEF
