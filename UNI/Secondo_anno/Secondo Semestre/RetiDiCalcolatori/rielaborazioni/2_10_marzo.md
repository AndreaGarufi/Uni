lezione 10 marzo
### Evoluzione e Struttura delle reti

- **Arpanet:** Rappresenta il primo sistema di reti.
    
- **Topologia:** Il sistema telefonico tradizionale è strutturato ad **albero** (un solo percorso possibile), mentre le reti moderne sono dei **grafi**, dove la maggiore connessione permette l'esistenza di più percorsi.
    
- **Comunicazione a pacchetto:** L'idea fondamentale è suddividere la comunicazione in pacchetti, ognuno dei quali deve scegliere la strada migliore per avanzare nella rete.

## 2. Paradigma Client-Server

L'approccio principale della comunicazione in rete prevede due ruoli distinti:

|**Caratteristica**|**Server**|**Client**|
|---|---|---|
|**Stato**|Sempre attivo (Always-on)|Può connettersi a intermittenza|
|**Indirizzo IP**|Permanente (Statico)|Spesso dinamico|
|**Iniziativa**|In attesa di contatto (Standby)|Inizia la comunicazione|
|**Posizione**|Spesso in Data Center per scalabilità|Dispositivi utente|

> [!info] **Nota:** I client non comunicano direttamente tra loro in questo modello. Esempi tipici sono i protocolli HTTP, IMAP e FTP.

## 3. Processi e Comunicazione Interprocesso

I processi sono programmi in esecuzione dotati di dati e stack di sistema.

- **Nello stesso host:** Due processi comunicano tramite **IPC (Inter-process communication)** definita dal sistema operativo.
    
- **In host differenti:** Comunicano scambiandosi **messaggi**. Questo scambio permette la sincronizzazione tra i processi.
    
- **Identificazione:** Ogni processo è identificato dal kernel tramite un **Process ID** e, in rete, tramite una **Porta (Port)**.

## 4. Architettura Peer-to-Peer (P2P)

A differenza del modello client-server, qui non esiste un server sempre attivo:

- **Comunicazione Diretta:** I sistemi terminali comunicano direttamente tra loro.
    
- **Intercambiabilità:** Ogni peer richiede servizi e ne fornisce a sua volta ad altri.
    
- **Auto-scalabilità:** Nuovi peer portano nuova capacità di servizio, oltre a nuove richieste.
    
- **Svantaggi:** Gestione complessa e connessioni intermittenti con IP variabili.


## 5. Porte e Sicurezza

Le porte sono fondamentali per indirizzare i dati al processo corretto in ascolto. Sono divise in tre gruppi:

1. **Well Known Ports (0-1023):** Riservate a servizi di sistema e richiedono privilegi di amministratore.
    
2. **Registered Ports (1024-49151):** Assegnate dall'ICANN per usi specifici.
    
3. **Dynamic/Private Ports (49152-65535):** Utilizzabili liberamente.
    

Esempi di Porte Standardizzate:

- **FTP:** 20 (dati), 21 (controllo)
    
- **SSH:** 22
    
- **HTTP:** 80 / **HTTPS:** 443
    
- **DNS:** 53 (TCP/UDP)
    

> **Sicurezza:** Per evitare attacchi, si può cambiare la porta di default (es. SSH) o usare il **Port Knocking**, una tecnica che tiene le porte chiuse finché non viene ricevuta una sequenza segreta di tentativi di connessione.

## 6. Analisi del Protocollo Telnet

Telnet è un protocollo per l'accesso remoto che opera in chiaro, rendendolo pericoloso per la trasmissione di password.

**Diagramma della sessione (Scenario Host A e Host B):**

![[Pasted image 20260520193409.png|403]]

1. **Invio:** L'utente su Host A digita 'C'. Host A invia un pacchetto con $Seq=42$, $ACK=79$ e $Data='C'$.
    
2. **Eco e Piggybacking:** Host B riceve 'C', lo elabora e risponde con un unico pacchetto che contiene sia la conferma (ACK) sia il dato di ritorno (Eco). Parametri: $Seq=79$, $ACK=43$ (conferma ricezione del byte 42), $Data='C'$.
    
3. **Conferma Finale:** Host A riceve l'eco e conferma a Host B la ricezione del byte 79 inviando un pacchetto di solo ACK con $Seq=43$ e $ACK=80$.
    

**Vantaggio del Piggybacking:** Unire l'ACK e il dato nello stesso pacchetto riduce il traffico di rete e il carico computazionale.