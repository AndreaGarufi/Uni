**Andrea Garufi 2025/2026**

# Reti di calcolatori

## PROTOCOL HEADERS

I protocolli di rete sono delle regole che definiscono il formato, e lʼordine, la  
semantica e la  
sintassi dei ”messaggi” mandati e ricevuti tra entità interconnesse tramite la  
rete, ovvero le azioni per un servizio. Garantire che i protocolli vengano  
utilizzati dai dispositivi è una condizione necessaria per permetterne la  
comunicazione.

Un protocollo serve a risolvere i problemi.

## SEGNALI

Trasmissione del segnale

Quando si trasmette un segnale ne arriva un altro. A livello fisico si genera un  
segnale elettrico/elettromagnetico ma a destinazione arriva un qualcosa di  
diverso, avviene una distorsione. Ciò che arriva a destinazione dipende dalla  
distanza (attenuazione).

![[Pasted image 20260520184318.png]]



È molto vantaggioso passare ai bit ( da 0 a 1 perché si passa per forza dal  
mezzo) perché il sistema diventa “comprensibile”.
- **Assenza di comunicazione**: rispetto alla sequenza di bit, se il segnale non cambia mai il sistema capisce che cʼè unʼinterruzione nella comunicazione.
- **Cause di degradazione**: Oltre alla distanza, il segnale è influenzato da interferenze elettromagnetiche, rumore termico e attenuazione del mezzo.
- **Codifica Binaria**: Un esempio semplice di interpretazione è associare un segnale alto al valore logico 1 e un segnale basso al valore 0.

## PROBLEMI

Per ridurre al minimo gli errori di comunicazione, è necessario istituire almeno  
due canali distinti e separati: uno per la trasmissione in uscita e uno per la  
ricezione in entrata. Non è fisicamente possibile trasmettere e ricevere  
contemporaneamente sullo stesso canale senza che i segnali si sovrappongano  
e interferiscano tra loro.

Lʼobiettivo è offrire un canale virtuale che sia affidabile e senza errori, questo  
nella realtà viene costruito su un canali fisici che però presentano limiti e  
problemi.

Tipi di canali:
- Simplex: La comunicazione è unidirezionale. Si ha unʼinformazione ma non il feedback di ritorno). ES: telecomando e proiettore, uno trasmette e lʼlatro riceve senza feedback.
- Half-duplex:La comunicazione è bidirezionale, ma uno alla volta. ES: le radio che trasmettono o ricevono.
- Full-duplex: Si può trasmettere e ricevere contemporaneamente.

Gestione della trasmissione e del flusso

- Si deve regolare il flusso dei dati attraverso un protocollo; (controllo dei flussi)
- Bisogna determinare il percorso migliore per far arrivare il messaggio a destinazione; (routing)
- Lʼordine di arrivo dei messaggi deve essere uguale allʼinvio. Se i messaggi seguono strade diverse potrebbero arrivare in ordine diverso, in questo caso è necessario ordinarli in seguito, si dovrebbe assegnare un numero di sequenza anche se occupa spazio. (sequenziamento)
- I messaggi non possono avere una lunghezza arbitraria: se uso un sistema a dimensione fissa potrei sprecare spazio anche se più semplice da gestire, se non è a dimensione fissa è più efficiente ma devo trovare un modo per avvisare che la comunicazione è terminata.
  
  Ci sono due modi per avvisare che la comunicazione è terminata:
1. Si usano sequenza di bit o variazioni elettriche per far capire che non cʼè più  
    segnali.
2. Si inserisce un campo allʼinizio del messaggio che dichiara quanti byte seguono.

Per trasmettere grandi quantità di dati, i protocolli non inviano un unico blocco  
monolitico, ma scompongono l'informazione in unità elementari chiamate  
**pacchetti**.


- **Divisione informazioni**: Ogni pacchetto è composto da una porzione di dati reali (payload) e da un'intestazione (header) che contiene le informazioni di controllo e routing.
- **Vantaggi della suddivisione**:
	- **Condivisione della banda**: Più flussi di dati possono coesistere contemporaneamente senza che uno solo monopolizzi la rete.
	- **Eliminazione delle dipendenze**: Ogni pacchetto può percorrere strade diverse; se uno viene perso, si ritrasmette solo quello e non l'intera comunicazione.
	- **Riduzione della latenza**: Il destinatario può iniziare a elaborare i primi pacchetti mentre gli altri sono ancora in transito.


## TIPI DI COMUNICAZIONE

La comunicazione può essere divisa in due categorie principali basate sulle  
modalità di connessione e sulla garanzia di consegna:


1. CONNECTION-LESS E CONNECTION-ORIENTED
- *Connection-less*: Non richiede una fase preliminare, ogni messaggio è indipendente e non serve una connessione potente per mandare un messaggio.
- *Connection-Oriented*: Serve stabilire una connessione potente. Si sviluppa in tre fasi: Apertura, Comunicazione e Chiusura. Apertura: si stabilisce la connessione. Comunicazione: scambio dei dati. Chiusura: il protocollo deve gestire la fine della sessione. 
  
  **Meccanismo di Acknowledgment ACK**: In questi sistemi, il mittente si aspetta   una risposta di conferma per ogni pacchetto inviato. Rimane in attesa finché non riceve l'ACK o finché non scade un timeout che segnala la perdita del pacchetto.

2. AFFIDABILE E NON AFFIDABILE
- *Affidabile*: Si implementano dei meccanismi per garantire la consegna corretta.

- *Non Affidabile*: Il trasmettitore invia i dati “contro un muro”, ma non sa se lʼinformazione è arrivata o è andata persa, il ricevente non ha modo di segnalare le anomalie.


Se si scambia la stessa informazione si deve fare in modo di riconoscere e  
capire che si tratta dello stesso tipo di informazione:

- *Cronometro*: io mando un messaggio, attivo un cronometro e se non arriva in tempo la risposta rimando la stessa informazione. Se il tempo del cronometro è troppo breve rischio di trasmettere inutilmente ,se troppo lungo resto bloccato in attesa di risposta.
- *Riconoscimento dei duplicati*: Si deve associare la risposta al messaggio, per poter distinguere se un messaggio ricevuto è unʼinformazione nuova o una copia di una precedente già arrivata. Ogni risposta deve essere legata univocamente al suo messaggio tramite numeri di sequenza. Senza questa si rischia di scambiare le risposte.


*RFC (request for comment)*: serve per standardizzare un protocollo, tutto ciò  
che riguarda con la comunicazione ha un RFC, ogni RFC ha un codice numerico  
associato.

## TIPI DI SERVIZI
Abbiamo quindi 4 combinazioni:

| TIPO | AFFIDABILE | NON AFFIDABILE |
| :--- | :--- | :--- |
| **Orientata alla connessione** | È il massimo della sicurezza | Connessione senza garanzie. Si stabilisce un canale ma se si perde un pezzo non si recupera |
| **Non Orientata** | Si ha una "ricevuta" di ritorno per ogni messaggio. | Non si ha una conferma di arrivo. |

**Modello OSI e TCP/IP**

**Modello OSI Composto da 7 livelli**. È importante notare che alcuni dispositivi (come i ripetitori fisici) operano solo al livello fisico e non "vedono" i bit, ma solo i segnali elettromagnetici.
**Stack TCP/IP Si concentra su 4 livelli principali**: 
1) Application
2) Transport
3) Network
4) Data Link Layer
5) Physical Layer

## TYPES OF NETWORKS
Ci sono diversi tipi di reti:

1) Point to point :
- Simplex: Uno parla, l'altro ascolta (es. telecomando).
- Half-duplex: Uno alla volta (serve un protocollo per i turni).
- Full-duplex: Ognuno trasmette quando vuole su canali separati.

2) Broadcast (shared bus): esiste un unico canale di comunicazione che viene condiviso da tutte le macchine connesse alla rete.
- Shared bus: Tutti ascoltano e tutti possono parlare. Il problema principale è la collisione del segnale, dove i segnali si sovrappongono e diventano indistinguibili.
- Ring: Le macchine sono separate; ognuna legge, elabora e riscrive il segnale per la successiva (ormai non si usa più).
- Star: C'è un concentratore centrale che riceve e riproduce i segnali per le macchine ai capi.
la differenza tra gli ultimi due è di affidabilità.
Il problema del broadcast è la collisione del segnale.

![[Pasted image 20260520185959.png|325]]
**Divisione delle reti in base alla loro dimensione:**
Dalla più piccola alla più grande:
1) PAN Personal area network): rete locale
2) MAN Metropolitan area network): raggiungono velocità elevate.
3) WAN Wide area network): reti ad ampia area.



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



**FTP - File Transfer Protocol**
FTP lavora sulle porte 20 e 21, la 20 è usata per il passaggio dei dati e la 21 per i controlli/comandi

**Bidirezionale:** Lavora in entrambe le direzioni; permette sia di caricare (upload) che di scaricare (download) informazioni e file.

**Sicurezza**
- *Accesso*: Richiede quasi sempre un'autenticazione tramite username e password.
- *Sicurezza*: È un protocollo non criptato. Tutto il traffico, comprese le credenziali di accesso, viaggia "in chiaro" sulla rete

**L'Architettura a "Doppio Canale"**
A differenza dell'HTTP, l'FTP utilizza due connessioni separate per comunicare:

- *Canale di Controllo (Comandi):* Viene aperto sulla **Porta 21**. Serve esclusivamente per inviare i comandi (es. login, richiesta di un file, cambio cartella) e ricevere le risposte del server.
- *Canale Dati:* Viene aperto sulla **porta 20** **solo quando serve** (quando si richiede il trasferimento effettivo di un file o la lista dei file in una cartella) e viene chiuso appena il trasferimento finisce.

**Il vantaggio dei due canali:** Poiché sono separati, il canale di controllo rimane sempre libero e reattivo. Se il trasferimento di un file molto grande si blocca sul canale dati, puoi usare il canale di controllo per dire al server "lascia perdere" (abortire l'operazione) e ricominciare, senza far crollare l'intera connessione

![[Pasted image 20260316111025.png|451]]
Il client apre una richiesta di connessione sulla sua porta (1742) il server apre la connessione sulla porta 21 e manda una ACK, dopo di ciò sulla la porta 20 apre la data connection per il client sulla porta 1742 (per il client) infine il client manda un ACK e da qui comincia lo scambio di file.


**Differenza tra stateless e stateful**

**Stateful**
**Come funziona:** Il sistema (di solito un server) "ricorda" chi è l'utente e cosa ha fatto nelle richieste precedenti. Crea una vera e propria **sessione** continua.
Ad esempio: Il protocollo **FTP** (che abbiamo appena visto: fai il login e la connessione rimane aperta in attesa dei tuoi comandi).
- Le vecchie telefonate tradizionali.
- I server dei videogiochi multiplayer online.

**Stateless**
**Come funziona:** Ogni singola richiesta (o messaggio) inviata dal client al server è completamente **indipendente** e isolata dalle altre. Il server elabora la richiesta, invia la risposta e poi se ne dimentica all'istante.
Ad esempio: Il protocollo **HTTP** (quello su cui si basa il web).
- Le API REST (usate dalle app sui nostri smartphone per comunicare con i server).



**HTTP**

HTTP nasce perché verso gli anni 90 si aveva bisogno di contattare un server in modo da recuperare documenti pubblici (si dovevano visualizzare le pagine dei siti web in pratica), quindi era inutile usare un protocollo come FTP (stateful), si può invece usare un protocollo *stateless* per migliorare e velocizzare i processi.

L'idea è quella di aprire una connessione TCP con il server e richiedere un documento che verrà così erogato del server.
![[Pasted image 20260316111955.png|361]]

Quindi il client manda una richiesta di connessione TCP e il server approva sulla porta 80 mandando un messaggio di ACK poi il client richiedere un determinato file e il server lo eroga

HTTP è quindi stateless, ovvero il server non mantiene informazioni sulle richieste passate

**Come è formata una pagina web**
Una pagina web è formata da un insieme di oggetti (che possono anche essere contenuti su diversi web servers), un oggetto può essere un file HTML, un immagine JPEG, un file audio ecc..., quindi una pagina web è composta da un file base HTML che include vari oggetti ognuno reperibile tramite un URL (Uniform Resource Locator) 
Ad esempio: www.someschool.edu/someDept/pic.gif


![[Pasted image 20260316120341.png|455]]
Il messaggio si divide in tre blocchi principali:

**Request Line (Riga di richiesta)**
È la primissima riga del messaggio e contiene i "comandi" fondamentali. È composta da:
- **method (metodo):** Indica l'azione che il client vuole che il server esegua. I più famosi sono **GET** (usato per richiedere una risorsa, come una pagina web o un'immagine) e **POST** (usato per inviare dati al server, come quando compili un modulo di login).
- **sp (space):** Un semplice spazio vuoto che fa da separatore.
- **URL:** Il percorso specifico della risorsa richiesta sul server (ad esempio `/index.html` o `/immagini/logo.png`).
- **version:** La versione del protocollo HTTP utilizzata (di solito `HTTP/1.1` o `HTTP/2`).
- **cr lf (Carriage Return & Line Feed):** Sono i caratteri di "ritorno a capo". Indicano al server che la riga di richiesta è finita.


**Header Lines (Intestazioni)**

Dopo la riga di richiesta ci possono essere diverse righe di intestazione (gli _headers_). Servono a passare informazioni aggiuntive al server.

- Ogni riga è composta da una coppia: un **header field name** (il nome del campo, ad esempio `Host`, `User-Agent` o `Accept-Language`) e il suo **value** (il valore, ad esempio `www.google.it`, `Mozilla/5.0...` o `it-IT`).
- Ogni riga si chiude con il solito ritorno a capo (`cr lf`).

**Il dettaglio cruciale:** Guarda subito sotto l'ultima riga di header. C'è una riga formata **solo da `cr lf`** (un ritorno a capo a vuoto). Questa riga vuota è obbligatoria e serve come "separatore": dice al server che le intestazioni sono finite e che tutto ciò che viene dopo è il corpo del messaggio.

**Entity Body (Corpo del messaggio)**

È la parte finale che contiene il "carico utile" (payload) dei dati veri e propri che stai inviando al server.

- **Se usi il metodo GET:** Di solito l'entity body è completamente **vuoto**, perché stai solo chiedendo informazioni, non ne stai inviando (i parametri viaggiano nell'URL).
- **Se usi il metodo POST:** L'entity body conterrà i dati effettivi. Ad esempio, se stai caricando un file o hai scritto un commento su un forum, il testo del commento o i byte del file viaggeranno all'interno di questo blocco.


![[Pasted image 20260316120919.png|417]]
L'HTTP response è identica alla request.


![[Pasted image 20260316121005.png|473]]


**Cookie**
Siti web e client browser usano i cookies per mantenere degli stati anche dopo la connessione (HTTP è stateless quindi non ha stati)
L'uso può essere ad esempio quello di identificare un utente sul sito dopo che accede per la prima volta, oppure per restare loggati in un sito anche dopo la chiusura, senza dover inserire ogni volta username e password.

I cookie sono sicuri perché non contengono codice eseguibile sul computer ma si limitano a raccogliere informazioni, sull'utente (ci possono essere dei rischi per quanto riguarda la privacy)


**Versioni HTTP**
Nel tempo si sono susseguiti vari aggiornamenti di questo protocollo, infatti un tempo si apriva la connessione usando un solo canale in cui veniva mandato tutto, creando rallentamenti ed errori, poi si è aggiunta una pipeline che spedisce ogni oggetto usando un canale diverso, in questo modo per siti molto grandi se un canale non ha ancora finito di mandare il suo oggetto nel frattempo gli altri sono già arrivati e l'utente può comunque vedere qualcosa del sito.
In seguito sono stati aggiunti vari protocolli per la sicurezza

i protocolli sono retrocompatibili. Un protocollo si dice **retrocompatibile** (o _backward compatible_) quando una versione più recente o aggiornata è in grado di interagire correttamente con versioni precedenti dello stesso protocollo, o di gestire dati e dispositivi basati su standard più vecchi.


**Wireshark**: programma  che serve per vedere il traffico di rete

abbiamo fatto delle prove in localhost praticamente abbiamo aperto un pagina web e abbiamo analizzato tutte le informazioni che vengono inviate al login (con username e password) vediamo che il server risponde con il Token di sessione, rubare il token di sessione è alla base del phishing

Ci sono due modi per risolvere questo problema:
- Usare HTTPS
- Refreshare il token di sessione spesso (così anche se rubato si ha poco tempo per usarlo)

**Proxy Server** 
serve per mascherare l'ip di un servizio sulla rete, è un server intermedio che permette di controllare, filtrare e mascherare il traffico da parte di uno o più client. Nello specifico:
1. I client mandano le richieste al proxy. 
2. Il proxy le invia al server destinazione. 
3. Il server riceve la richiesta del proxy. 
4. Il server invia la risposta al proxy. 
5. Il proxy invia la risposta del server al client originale.

I proxy sono utili anche per monitorare il traffico di rete da parte degli host che lo usano.
Avendo una cache interna alcune volte può rispondere con una pagina vecchia
![[Pasted image 20260317102439.png|500]]


**SMTP(Simple Mail Transfer Protocol)**: questo è il protocollo utilizzato per lo scambio di posta elettronica, in specifico si occupa di trasferire le mail dal server mittente a quello destinazione. Usa la porta 25 su TCP 
![[Pasted image 20260318113052.png]]

Noi quindi usiamo SMTP per mandare la mail al nostro server di posta che (anche lui usando SMTP) la invierà al server di posta del destinatario che leggera questa mail usando o POP o IMAP

La @ nella mail viene inserita per distinguere il nome utente dal server di destinazione 
Di seguito quello che accade veramente:
![[Pasted image 20260317103141.png|500]]
L'immagine mostra perfettamente la natura "botta e risposta" del protocollo SMTP, basato su comandi testuali chiari (come `HELO`, `MAIL FROM`, `RCPT TO`) e codici di stato standardizzati. In questo scenario, l'email è stata autorizzata per Jones e Brown, ma la consegna a Green è fallita a causa di un indirizzo inesistente.

Il client che si connette al server viene chiamato **user-agent**: si collega al server di posta e ci permette di interagire con le nostre mail, questo può essere fatto anche tramite SMPT ma è molto più conveniente usare **POP3** e **IMAP**

**POP3(Post Office Protocol)**: scarica le mail dal server e ci permette la visualizzazione anche offline (cancella le mail dal server di posta)
**IMAP**: ci permette la visualizzazione delle mail senza scaricarle, è più semplice ma non ci permette di visualizzare le mail se siamo offline,  usando questo protocollo ovviamente le mail non vengono cancellate dal server di posta (Google ha tutte le nostre email nei suoi database)

| **Caratteristica**                           | **POP3**       | **IMAP**                        |
| -------------------------------------------- | -------------- | ------------------------------- |
| Dove è definito il protocollo?               | RFC 1939       | RFC 2060                        |
| Quale porta TCP viene utilizzata?            | 110            | 143                             |
| Dove sono memorizzate le e-mail?             | PC dell'utente | Server                          |
| Come vengono lette le e-mail?                | Offline        | Online                          |
| Tempo di connessione richiesto?              | Poco           | Molto                           |
| Uso delle risorse del server?                | Minimo         | Esteso                          |
| Caselle di posta multiple?                   | No             | Sì                              |
| Chi esegue il backup delle caselle di posta? | Utente         | ISP (Provider)                  |
| Adatto per utenti mobile?                    | No             | Sì                              |
| Controllo utente sui download?               | Poco           | Elevato                         |
| Download parziale dei messaggi?              | No             | Sì                              |
| Le quote disco sono un problema?             | No             | Potrebbero diventarlo nel tempo |
| Semplice da implementare?                    | Sì             | No                              |
| Supporto diffuso?                            | Sì             | In crescita                     |
**Mail di SPAM**: lo spam di mail nasce dalla famosa azienda spam che un giorno per pubblicizzare il suo prodotto ha inviato un sacco di mail contemporaneamente.



**DNS (Domain Name System)**
Gli indirizzi IP identificano in maniera univoca gli host in rete e la loro locazione: la struttura di un indirizzo IP, fornisce infatti informazioni sulla struttura della rete e la posizione dell’host all’interno di essa. Gli IP non sono facili da ricordare, per un umano, in quanto costituiti esclusivamente da caratteri numerici. 
Gli hostname nascono con lo scopo di associare un nome a un IP: diventa però necessario introdurre un meccanismo che permetta la traduzione degli hostname in indirizzi IP. Nasce così il DNS

l'associazione nome-indirizzoIP *(hostname)* viene risolta usando il protocollo DNS.
![[Pasted image 20260317110722.png|500]]

**Una panoramica sui dominii**
#### 1. Root Domain (.)

È il livello più alto della gerarchia.  
Non si vede normalmente negli indirizzi (è implicito alla fine, es: *google.com.*).

#### 2. Top-Level Domain (TLD)

Sono i domini di primo livello e si trovano subito sotto il root.
Esempi: .com .it .us .edu ecc...

#### 3. Second-Level Domain (SLD)

È solitamente il nome scelto dall’organizzazione o dal proprietario del sito.

Esempi:

- *google.com* → “google” è il secondo livello
    
- *unict.it* → “unict” è il secondo livello

#### 4. Sottodomini (Third-Level e oltre)

Sono livelli aggiuntivi sotto il secondo livello.

Esempi:

- `www.google.com`
    
- `mail.google.com`
    
- `api.service.example.com`


**web.dmi.unict.it.**
Qui abbiamo il . che è root, .it che è TDL, unict è SDL, e poi abbiamo i third-level e oltre (.dmi e web)

**Funzionamento DNS**
![[Pasted image 20260317111310.png|500]]
Questi sono i passaggi che fa un dispositivo per risolvere un nome in un indirizzo IP.
Il client manda una richiesta al suo DNS server locale con l'indirizzo da cercare, il DNS server locale non sa direttamente dove trovare questo indirizzo quindi si appoggia a altri DNS server, inizia quindi dal *root DNS server*, che contiene e risponde con l'indirizzo del server da raggiungere per risolvere gli indirizzi *Top-Level Domain* (ovvero .it .us .fr .com .org ecc...), quindi il DNS server locale si rivolge al *TDL DNS server* che contiene e risponde con il dominio di secondo livello (.youtube .netflix .unict ecc...) da qui il DNS locale si rivolge all'ultimo DNS del percorso chiamato *authoritative DNS server* che contiene l'ultima associazione indirizzo IP-dominio


In pratica il DNS è un database distribuito in tutto il mondo, viene gestito come un albero, questo albero ha 13 radici e non una, questo è dovuto al fatto che esistono *13 DNS server root*, anche se ovviamente sono distribuiti in centinaia di macchine fisiche. In pratica ogni dispositivo sa raggiungere un server che conosce più indirizzi di lui se l'indirizzo cercato non viene trovato(fino ad arrivare al server destinazione).
![[Pasted image 20260317111642.png|500]]
è un protocollo molto scalabile, in quanto la maggior parte delle richieste vengono risolte a livello basso (grazie alle cache) e quasi mai al root level. Banalmente se noi cerchiamo google.it su rete UNICT il server dell'ateneo sa risolvere l'indirizzo IP a livello 1 perché è salvato sulla sua cache di sistema essendo un link molto usato.

Esistono due tipi di server DNS in un'azienda:
- **Primario**: Qui risiedono i dati ufficiali (l'admin modifica qui i record del DNS DB)
- **Secondario**: Se il server primario dovesse andare offline, il server secondario continuerà a rispondere alle richieste degli utenti, garantendo che il sito web rimanga raggiungibile.
Il processo di aggiornamento è semplice: 
- Aggiorno i record nel Primario
- Vengono aggiornati in automatico anche i record nel secondario
![[Pasted image 20260317112427.png|500]]

**Fuori contesto**: posso mettermi in mezzo alla comunicazione tra due PC diventando un *man in the middle* e riuscendo a catturare tutti i dati che vanno da A a B 


Esistono anche dei protocolli utilizzati per la diagnostica, uno di quelli più utilizzati è **SNPM (Simple Network Management Protocol)**, non ci interessa in modo reale come funziona, dobbiamo solo sapere che esiste e per cosa viene utilizzato (ha solo detto il nome praticamente).


---

Siamo passati a [[3 - Transport_N.pdf]]

Nello stack abbiamo diversi layer:
- **Datalink layer**: comunicazione fisica tra gli host
- **Network layer**: comunicazione logica tra gli host
- **Trasport layer**: comunicazione logica tra i processi (usando IP e porta)

Il trasporto a livello trasport viene fatto usando: 
- il **multiplexing** (sorgente): è il processo con cui un host incapsula i frammenti di dati provenienti da uno o più sockets in segmenti del transport layer utilizzando opportuni header.
- il **demultiplexing** (destinazione): Consiste nella consegna dei segmenti al socket corretto e quindi al processo corretto.

Per fare queste cose vengono utilizzati due protocolli (uno o l'altro):
- **RDT(Reliable Data Transfer)**: affidabile e lento, **TCP**(Trasmission Control Protocol) è la sua implementazione più famosa. Viene diviso in diverse versioni dal nostro libro per farci capire come si è arrivati storicamente a TCP, esiste una singola versione.
- **UDP**: inaffidabile ma molto veloce


**UDP(User Datagram Protocol)**: offre un servizio "best effort". Visto che non garantisce l'arrivo dei dati è un protocollo molto semplice, non viene stabilita una connessione reale tra sorgente e destinazione, grazie a queste caratteristiche è molto veloce.
- UDP è di tipo *connectionless* 
- L’header del protocollo UDP occupa 8 byte. 2 byte per la porta del mittente, 2 per la porta del destinatario, 2 per la lunghezza del messaggio (header UDP + dati) e 2 per il checksum. Per confronto l’header del protocollo TCP occupa dai 20 ai 60 byte:
- E' un meccanismo che consente di rilevare errori di trasmissione. Questi errori spesso consistono in bit-flip, che possono stravolgere del tutto il significato dei dati trasmessi. Detto ciò, la verifica consiste nel calcolo di un checksum, in italiano somma di controllo, sia al mittente (che la inserirà nel frame) che al destinatario. La somma è calcolata in virtù dei dati contenuti nel frame. Se le due somme non dovessero coincidere, il pacchetto sarà da considerarsi fallato, e verrà scartato (questo Checksum vale anche per TCP).
![[Pasted image 20260317122348.png|398]]

*Il canale di comunicazione però è per sua stessa natura fisica inaffidabile, quindi certi pacchetti possono andare persi, ecco che si ricorre a RDT per una comunicazione affidabile*

**RDT** 
Riesce a rendere affidabile qualcosa di inaffidabile, lo fa pagando in termini di velocità. Il nostro libro ha creato delle versioni per farci capire come si è arrivati alla versione finale:
![[Pasted image 20260317123845.png|500]]
Osserviamo in breve le caratteristiche dei vari RDT prima di studiarne le FSM al dettaglio:  
- *1.0.*: Non include nessun meccanismo effettivo, ma fa da base per le versioni successive. 
- *2.0.*: Gestisce i pacchetti corrotti tramite segnali di ACK/NAK, ma non gestisce ACK e NAK corrotti.
- *2.1.*: Gestisce gli errori sul backward channel (un canale usato per l'invio di ACK/NAK).
- *2.2.*: Si elimina il simbolo dedicato NAK, utilizzando in maniera differente gli ACK (ottimizzazione)
- *3.0.*: Tutte le precedenti versioni gestiscono solo pacchetti corrotti. Con questa versione, si verifica anche la perdita dei pacchetti, introducendo il meccanismo di time-out.


Di seguito la versione 3
![[Pasted image 20260317125005.png|500]]



### Throughput
il throughput è un indice della capacità di trasmissione in un canale di comunicazione, più è alto più dati si possono far passare in quel canale:
$$ Throughput = \frac{Numero\,\,\,di\,\,\,bit\,\,\,(o\,\,\,byte)\,\,\,trasmessi\,\,\,con\,\,\,successo}{ tempo\,\,\,impiegato}$$
![[Pasted image 20260319101419.png|500]]
Consideriamo un canale con *Bandwidth* pari 10 Mbps ovvero: $$BW = 10 \text{ Mbps } = 10^7 \text{ bit per secondo }$$da questo ne traiamo che:
- in $1 s \rightarrow 10000000 \; bits$
- in $0.1  \micro s \rightarrow 1 \; bits$
Se volessimo inviare un Frame di $1500$ bytes ovvero $12000$ bits impieghiamo: 
$$T_{\mathrm{frame}} = \frac{\text{Dimensione del frame (in bit)}}{\text{Bandwidth (in bit/s)}}$$
Ad esempio per noi il tempo di frame sarebbe di 1.2 millisecondi

il nostro segnale si deve propagare da $A$  a $B$, quindi dobbiamo mettere in considerazione anche il tempo di propagazione del segnale, di seguito in dettaglio:
$$T_{\mathrm{propagazione}} = \frac{\text{Spazio di trasmissione}}{\text{Velocità di trasmissione}}$$

Con questa informazione possiamo calcolare anche il numero di bit che possono stare contemporaneamente nel canale:
$$\text{Bandwidth (in bit/s)} \cdot T_{\mathrm{propagazione}}(\text{in s})$$

| $T_{frame}$                                                             | $T_{propagazione}$                                                                        |
| ----------------------------------------------------------------------- | ----------------------------------------------------------------------------------------- |
| Il tempo impiegato<br>dal PC per immettere<br>tutto il frame nel canale | Il tempo impiegato <br>dai dati per percorrere<br>tutto il canale fino a <br>destinazione |


Date tutte queste informazioni possiamo calcolare il **throughput teorico** che è:
$$T = T_{\text{frame}} + T_{\text{propagazione}}$$
Quindi il **throughput teorico** sarebbe il tempo impiegato per immettere tutti i dati + quello per percorrere il canale fino a destinazione

Per calcolare il **throughput reale** dobbiamo considerare il tempo di $ACK$ e il tempo di $RTT$(Round-Trip Time) ovvero il tempo di andata e ritorno (quindi il $T_{propagazione}$ dell'andata + quello del ritorno dell' ACK), la formula diventa:
$$T = T_{\text{frame}} + RTT + T_{\text{elaborazione}} + T_{\text{ACK}}$$
$$T_{ACK} = \frac{\text{Dimensione dell'ACK (in bit)}}{\text{Bandwidth (in bit/s)}}$$
il tempo di elaborazione è un tempo teorico (molto piccolo) che introduciamo perché il computer B dopo aver ricevuto un messaggio lo legge e crea un messaggio di ACK e lo fa nel tempo di elaborazione che è piccolo ma non 0

$RTT$ lo dà l'esercizio
![[Pasted image 20260319105431.png|500]]

In questa maniera la reale velocità del canale non è molto alta, si decide quindi di implementare un meccanismo di pipeline...

La modalità pipeline ci consente di aumentare il throughput di una rete. Invece di inviare un singolo frame ne inviamo $n$ e aspettiamo $n$ $ACK$, capiamo subito che è molto importante gestire i casi in cui il frame si rovina e l'ACK di risposta non arriva, usiamo principalmente questi due algoritmi:
- **Go-Back-N (GBN)**: *Se si perde un pacchetto, si rimanda tutto da quel punto in poi.*
	* **Finestra di invio:** Il mittente può inviare fino a $N$ pacchetti senza aspettare conferma (ACK).
	* **Ricezione:** Il destinatario accetta i pacchetti solo in ordine rigoroso. Se arriva un pacchetto fuori sequenza, lo scarta.
	* **Gestione degli errori:** Se il pacchetto $3$ va perso nel canale, il destinatario ignorerà i pacchetti $4$, $5$, ecc. Quando il timer del mittente scade per il pacchetto $3,$ il mittente ritrasmette il pacchetto $3$ e tutti i pacchetti successivi già inviati (torna indietro a N).
- **Selective repeat**:  *Se si perde un pacchetto, si rimanda SOLO quello perso.*
	* **Finestra di invio:** Simile al GBN, il mittente invia fino a $N$ pacchetti senza aspettare l'ACK.
	* **Ricezione:** Il destinatario accetta i pacchetti fuori ordine e li **salva in un buffer**, inviando un ACK individuale per ogni pacchetto ricevuto correttamente.
	* **Gestione degli errori:** Se il pacchetto $3$ va perso ma il $4$ e il $5$ arrivano, il destinatario memorizza $4$ e $5$. Quando scade il timer del mittente per il pacchetto $3$, il mittente ritrasmette solo e unicamente il pacchetto $3$.

Usando la pipeline si riesce ad aumentare la quantità di dati trasmessi.



**Rumore**: dobbiamo mettere in considerazione anche il rumore, ovvero il disturbo al nostro segnale durante la sua trasmissione. 

Meme tra TCP e UDP
![[Pasted image 20260319110552.png|407]]

---
### TCP
Nella ricostruzione delle versioni di TCP si dice ci siano 4 versioni, ma non è vero è una sola quella del 1981. Il TCP ha diverse funzionalità (feature):

- Indirizzamento/Multiplexing
- Creazione, Gestione e Terminazione della Connessione
- Gestione e Impacchettamento dei Dati
- Trasferimento Dati
- Fornitura di Servizi di Affidabilità e Qualità della Trasmissione
- Fornitura di Funzionalità di Controllo del Flusso e Prevenzione della Congestione

L'ultima è quella sulla quale stanno lavorando i ricercatori, per migliorarla. Ci sono delle cose a cui TCP non provvede: 
- Non offre sicurezza 
- Non garantisce una comunicazione 
- Non mantiene i confini del messaggio (*message boundaries*), queste servono per riuscire ad interpretare e ricostruire messaggi.

Di seguito la struttura del pacchetto TCP:
![[Pasted image 20260319115102.png|647]]

Troviamo diverse informazioni:
- **Destinatione e Source Port**
  
- **Sequence Number:** Campo di 32 bit che indica il numero di sequenza del primo byte dei dati contenuti nel segmento TCP.
  _Esempio pratico:_ Supponiamo che tu debba inviare 500 byte di dati. Il pacchetto parte con un Sequence Number impostato a `1000`. Questo significa che il pacchetto contiene i byte che vanno dal numero `1000` al `1499`.
  
- **Acknowledgment Number (ACK):** Campo di 32 bit che indica il numero di sequenza del prossimo byte che il ricevitore si aspetta di ricevere (conferma cumulativa).
  _Esempio pratico:_ Il destinatario riceve il tuo pacchetto con i byte dal `1000` al `1499`. Per dirti che è andato tutto bene, ti manda indietro un messaggio con l'ACK impostato a `1500`. Ti sta letteralmente dicendo: "Perfetto, ho tutto fino al 1499. Ora sto aspettando che mi mandi il byte 1500".
  
- **TCP header length (chiamato anche Data Offset):** Questo campo indica quanto è lungo l'intero header TCP. È fondamentale perché serve a dire al computer ricevente: "L'header finisce qui, da questo punto in poi iniziano i dati veri e propri (il payload)".
  
- **Spazio grigio (Reserved):** Sono bit "messi da parte" per sviluppi futuri del protocollo. Attualmente vengono impostati a zero e ignorati
  
- **Flag** Quella fila di lettere in verticale rappresenta i Flag, ovvero dei piccoli interruttori di 1 bit che indicano lo stato del pacchetto o danno istruzioni speciali.

- **Window size (Dimensione della finestra):** È il cuore del _controllo di flusso_ che avevamo menzionato prima. Indica quanti byte il computer ricevente è in grado di accettare in quel momento. Se il ricevente è sovraccarico, abbasserà questo valore per dire al mittente: "Rallenta, non ho più spazio in memoria!"

- **Checksum:** È un valore matematico di controllo per la correzione degli errori

- - **Urgent pointer (Puntatore urgente):** Viene letto solo se il flag **URG** è attivo. Indica esattamente a quale byte finiscono i dati urgenti all'interno del pacchetto.


Tutto questo rende TCP affidabile ma non molto veloce, tuttavia anche il througput è un fattore da tenere in considerazione, per analizzarlo dobbiamo analizzare una serie di parametri:
- **MSS(Maximum Segment Size)**: Indica la dimensione massima dei dati che possono essere inviati in un singolo segmento TCP
- **MTU(Maximum Tramission Unit)**: -> $MSS+$$Header TCP+$$HeaderIP$ 

Un'altro dato importante è RTT(Round Trip Time), questo tempo viene continuamente stimato in questo modo:
- Per ogni comunicazione viene misurato il tempo che trascorre tra l'invio del pacchetto e il ritorno di un ipotetico ACK
- Viene fatta la media di tutti i tempi salvati
è importante che RTT siano stimato bene perché:
- RTT troppo lungo: si ha una reazione troppo lenta alla perdita di pacchetti
- RTT troppo corto: gli ACK potrebbero non arrivare in tempo
il calcolo del RTT viene fatto ad ogni invio di pacchetto, in modo che TCP sappia quanto aspettare. Il tipo di media che viene usata si chiama: **Exponential Weighted Moving Average**.  (Moving perché si muove un valore avanti ad ogni pacchetto)


**Deviazione standard RTT**
Abbiamo detto che il tempo RTT viene calcolato attraverso una media dei vari tempi che si sono registrati, ma non sempre i tempi registrati sono tutti simili tra loro (es. 1 ms, 1.12 ms, 1.09 ms) potrebbero infatti esserci oscillazioni molto grandi tra i vari tempi misurati, (es. 1 ms, 0.3 ms, 3 ms) quindi il calcolo della deviazione standard RTT è proprio il calcolo di queste oscillazioni molto grandi:
$$Dev RTT = (1 − β) · Dev RTT + β · |Sample RTT − Estimated RTT|$$
Un valore tipico di $β$ è $\frac{1}{4} = 0.25$
Dove:
- β è un peso fissato (0.25 di solito)
- Sample RTT è il tempo misurato con l'ultimo pacchetto inviato
- Estimated RTT è il tempo storico (ovvero la media fino a quel momento)


A differenza dei modelli teorici RDT (che prevedono un timer per ogni singolo pacchetto), TCP riduce la complessità del sistema utilizzando **un solo timer di ritrasmissione globale**.

Funziona in questo modo: quando TCP riceve un ACK che conferma un pacchetto, resetta il timer. Se ci sono altri dati già inviati ma non ancora confermati, il timer viene immediatamente riavviato per monitorare il segmento "più vecchio" ancora in volo (ad esempio, il segmento successivo _n+1_ in attesa di ACK).


Per adattarsi alle condizioni della rete, TCP calcola dinamicamente il timer di ritrasmissione attraverso questi 4 passaggi:
1. **SampleRTT (Campione):** Misurazione del tempo effettivo trascorso tra l'invio di un singolo segmento e la ricezione del suo ACK.
2. **EstimatedRTT (Tempo stimato):** Media mobile ponderata dei campioni precedenti. Serve a "smussare" i picchi e le anomalie temporanee della rete.
3. **DevRTT (Deviazione):** Calcolo della variabilità del RTT. Funge da margine di sicurezza per evitare timeout prematuri.
4. **RTO (Retransmission Timeout):** Il timer effettivo da utilizzare, calcolato come la somma del tempo stimato più il margine di sicurezza $$EstimatedRTT + 4 * DevRTT$$
la formula dell'RTO è progettata per essere prudente, il timer finale calcolato risulta spesso **molto lungo**. Se un pacchetto viene perso, aspettare la scadenza di questo timer causa un lungo periodo di inattività e rallenta la trasmissione. Per mettere una pezza a questo problema di latenza, TCP utilizza un meccanismo chiamato **Fast Retransmit** (Ritrasmissione Rapida):
- Se il ricevitore rileva un "buco" nei pacchetti, continua a mandare ACK con il numero del pacchetto mancante.
- Se il mittente riceve **3 ACK duplicati** di fila, deduce con certezza che il pacchetto successivo è andato perso.
- A questo punto il mittente **ritrasmette immediatamente il pacchetto**, senza aspettare che il lungo timer RTO scada.

###### Timer RTT
è importante che il timer venga stimato nel modo corretto, perché:
- Se troppo piccolo: i pacchetti non arrivano in tempo
- Se troppo lungo: si ha una reazione lenta alla perdita di pacchetti

Come stimiamo RTT?
- *Sample RTT*: il tempo trascorso tra l'invio del pacchetto e la ricezione dell'ACK, basandoci su questo andiamo a calcolare *Estimated RTT* come di seguito: 
- *Estimated RTT*: $$\text{Estimated\_RTT}_n = (1-\alpha)*\text{Estimated\_RTT}_{n-1} + \alpha * \text{Sample\_RTT}_n$$
  il valore tipico di $\alpha$ è $0.125$

Ovvero il tempo RTT stimato dopo l'arrivo del pacchetto numero $n$ viene calcolato usando il tempo stimato precedente e RTT dell'ultimo pacchetto arrivato

La natura variabile del RTT ci porta a voler tener conto anche della deviazione standard dei valori (come già visto nella scorsa lezione)
$$\text{DevRTT} = (1-\beta) \cdot \text{DevRTT} + \beta \cdot |\text{SampleRTT} - \text{EstimatedRTT}|$$
Usando questo valore andiamo a calcolare il tempo massimo di ritrasmissione **RTO(Retransmission TimeOut)** come di seguito: 
$$RTO = \text{EstimatedRTT} + 4 * DevRTT$$

Nonostante RDT stabilisca che ad un pacchetto venga associato un timer, TCP riduce la complessità di gestione gestendo esclusivamente un timer alla volta. Dopo la ricezione dell'ACK dell'n-esimo pacchetto, il timer per il segmento n + 1 non ancora acknowledged viene avviato. 

Per ridurre il tempo di attesa nasce la tecnica **Fast Retransmit**: se il reciver manda tre ACK consecutivi per lo stesso pacchetto mancante (ovvero l’ACK dell’ultimo pacchetto consegnato con successo), viene attivata istantaneamente la ritrasmissione del pacchetto corrente.

###### Controllo del flusso
 
Cosa succede se il ricevitore non è abbastanza veloce a riceve i pacchetti? 
Semplicemente viene usato un campo del pacchetto ACK chiamato *receive window* dove viene specificato dal mittente lo spazio massimo disponibile. ![[Pasted image 20260324103826.png|500]]
Per gestire in modo ottimale questa finestra usiamo un algoritmo detto *Nagle Algorithm* che sarebbe questo:

```
if available_data > 0 then
    if window_size ≥ MSS & available_data ≥ MSS then
        send_a_MSS_segment
    else
        if waiting_for_an_ack == true then
            enqueue_data /* until an acknowledge is received */
        else
            send_data
        end if
    end if
end if
```
Questo algoritmo si comporta in modo diverso in base alla rete in cui si trova:
- In reti con un basso RTT, questo algoritmo invia piccoli pacchetti con alta frequenza
- In reti con un alto RTT, i dati vengono bufferizzati e inviati in grandi pacchetti
Alcune volte per avere una forte reattività il sistema operativo disabilita questo algoritmo


###### Apertura della connessione
La connessione TCP funziona con il 3-way-handshake, ma prima di vederlo capiamo anche perché il 2 non viene utilizzato.

*2-way-handshake*
Inizialmente si era pensato di stabilire una connessione usando questo metodo che si ispira un po' al modo di fare umano, ma questa metodologia nel mondo dei computer può causare problemi di Half-connection

1) A manda una richiesta di connessione a B
2) B manda un ACK e apre la connessione
3) A riceve l'ACK e partecipa alla connessione

*e se l'ACK si perde?*

1) A manda una richiesta di connessione a B
2) B manda un ACK e apre la connessione
3) L'ACK si perde o A crasha, B rimane così con una connessione aperta ma inutilizzabile


*3-way-handshake*
Questo è il metodo scelto da TCP per funzionare correttamente
![[Pasted image 20260325104738.png|606]]
TCP è un protocollo di connessione full-duplex.
Quindi il client manda una richiesta di connessione (vuole aprire il canale) al server, il server manda un ACK in cui accetta la connessione e contemporaneamente chieda al client di aprire il suo canale verso di lui (full-duplex) e allora il client manda un altro ACK per indicare che l'ACK precedente è stato ricevuto e la connessione funziona.
Eventuali problemi di ACK non ricevuti si risolvono rimandando gli ACK precedenti (in caso non fossero arrivati) per un numero di tentativi limitato, se non si ha successo si interrompe la connessione

###### Chiusura della connessione con 4-way-handshake (2x2 handshake)
Per chiudere la connessione TCP usa un doppio 2-way-handshake in questo modo:
![[Pasted image 20260325110513.png|621]]
Il client quindi manda un messaggio con FINbit = 1 questo significa che non ha altri dati da inviare, il server manda un ACK (per dire che ha capito), dopo se il server ha ancora dati da trasmettere li trasmette (perché è il client che non ne deve inviare più), appena finisce il serve manda anche lui un FINbit = 1, il client manda un ACK per dire che ha ricevuto tutto e si chiude la connessione


###### Controllo di congestione
La gestione delle trasmissioni è fondamentale per evitare non solo di sovraccaricare i receiver (eventualità gestita tramite il controllo del flusso), ma anche per evitare il sovraccarico della rete, con conseguente congestione. Il protocollo TCP gode di meccanismi per gestire la congestione, per ridurre la velocità di trasmissione e minimizzare i danni della congestione.

Abbiamo 3 scenari:

*Scenario 1  - due mittenti e receiver, router con buffer illimitato (irreale)*
Nell’analisi della congestione di rete, è importante conoscere dei valori, quali 
• λin, frequenza media di invio (dai mittenti). 
• λout, la frequenza di arrivo di byte al ricevente. 
• R, la capacità del collegamento condiviso.

Quando λin ≥ λout, inizia a crearsi congestione. 
Consideriamo due host mittenti A e B che inviano a due host destinatari attraverso un router intermedio, e supponiamo che il suo buffer sia illimitato (cosa che nella realtà è impossibile).
![[Pasted image 20260325111600.png|452]]

• Se λin ≤ $\frac{R}{2}$ , il router riesce ad inoltrare i pacchetti senza ritardi significativi, e λout = λin. Dividiamo R in due perché abbiamo due host che mandano. 

• Se λin aumenta fino a $\frac{R}{2}$ , il λout massimo si stabilizza su $\frac{R}{2}$. 

• Se λin > $\frac{R}{2}$, il throughput non aumenta, ma il numero di pacchetti accodati nel buffer del router cresce senza limite, aumentando il ritardo medio di trasmissione.

*Scenario 2 - due mittenti e receiver, un router con buffer limitato (reale)*
Quando il buffer di un router è pieno, alcuni pacchetti vengono scartati. Di fronte a circostanze simili, TCP prevede ritrasmissione, con conseguente aumento della latenza complessiva e riduzione della frequenza media di invio λin, in quanto vengono rimandati gli stessi pacchetti. λ′in tiene conto sia dei dati originali, che delle ritrasmissioni. Distinguiamo ora 3 casi di questo scenario.

1. *Nessuna perdita di pacchetti* *- Perfect Knowledge*. Se i sender fossero in grado di determinare in anticipo se il router ha spazio disponibile nel buffer, invierebbe un pacchetto solo quando può essere immediatamente elaborato, ottenendo λin = λ′in, λout = λin ≤ $\frac{R}{2}$ e zero latenza (perlomeno, causata dal router). 
   
2. *Ritrasmissione solo per pacchetti persi* *- Some perfect Knowledge*. I sender non conoscono lo stato del buffer, e ritrasmettono un pacchetto solo quando hanno la certezza che sia stato perso. Supponendo che λ′in =$\frac{R}{2}$ , λout < $\frac{R}{2}$ a causa delle ritrasmissioni. 
   
3. *Caso reale* *- duplicati non necessari*. I sender non conoscono lo stato del buffer, e potrebbero avere un timer di ritrasmissione troppo breve. Questo implica un utilizzo innecessario del buffer del router, della banda e delle risorse di elaborazione perché avendo un tempo troppo breve potrebbe mandare dei duplicati. Questo potrebbe addirittura portare ad un throughput di circa λout = $\frac{R}{4}$ .

![[Pasted image 20260325112006.png|717]]


*Terzo scenario - quattro mittenti, più router limitati e percorsi*
In questo scenario, quattro mittenti inviano pacchetti su percorsi composti da più collegamenti, condividendo router intermedi. Ogni host utilizza un meccanismo di ritrasmissione basato su time-out, e la rete ha buffer di dimensione finita.
![[Pasted image 20260325112535.png|586]]

Abbiamo quattro sender che inviano pacchetti in quattro percorsi con più router, e quindi più possibili percorsi. Ogni router trasmette a capacità $R$. A valori di λin piccoli, λin = λ′in, non si hanno overflow dei buffer e nemmeno ritrasmissioni. Al crescere del valore di λin, inizia il rischio di ritrasmissioni, per cui λ′in > λin.



##### TCP Fairness
TCP è un protocollo fair? Cosa intendiamo per fairness?
Si desidera che il controllo della congestione in TCP sia tale che, date $K$ connessioni attraverso la stessa rete con capacità trasmissiva $R$, la *cwnd* di ogni connessione sia $\frac{R}{K}$ in modo che ogni host abbia la stessa quantità di banda degli altri

**Dimostrazione**
Date due connessioni con pari MSS (Maximum Segment Size) e RTT (tempo di propagazione andata e ritorno) (e nessun’altra connessione attraverso il collegamento) che operano in *congestion avoidance*. Con un throughput massimo pari a R, e tenendo a mente che al crescere di uno (connessione 1 ha più spazio), diminuisce l’altro (connessione 2 ha meno spazio), il throughput in una situazione di equilibrio è pari a $\frac{R}{2}$ 
![[Pasted image 20260325114310.png|447]]
Nel punto in cui si incontrano le rette perpendicolari si ha una perfetta divisione di banda tra le 2 connessioni.

A parità di RTT e MSS, gli host in congestion avoidance crescono in maniera lineare: 1 MSS ad ogni RTT . Detto ciò, quando la somma del throughput di entrambi gli host supera R, questi si dimezzano. Con $x = throughput$ del primo host e $y = throughput$ del secondo host, e il comporta- mento di incremento lineare e divisione della finestra di congestione, il throughput delle connessioni convergerà sempre alla bisettrice x = y. In circostanze più vicine a quelle reali, le connessioni con RTT più basso ottengono un throughput maggiore a causa della velocità con cui possono ottenere la connessione. Ricordiamo che l’incremento, nella fase di congestion avoidance, avviene una volta per RTT.




## **NETWORK LAYER**

Possiamo immaginare la rete di connessioni tra dispositivi e tra router come un grafo in cui ogni nodo consiste in un router

**Definizioni:**
- *Routing* -> il processo di selezione e definizione di cammini per i pacchetti all'interno o tra reti.
- *Forwarding* -> Consiste nell'inoltro effettivo dei pacchetti
(Spesso chiesto all'esame)
![[Pasted image 20260329171022.png|291]]

Un router ci instrada al router successivo, ad ogni nodo del grafo il router ci indica qual è la strada migliore per raggiungere il router (nodo) successivo

**Dividiamo il network layer in:**
- **data plane**: questo è il responsabile del vero e proprio forwarding dei pacchetti
- **control plane**: è il responsabile dell'instradamento reale dei pacchetti

In pratica quindi il data plane spedisce i pacchetti mentre il control plane li "guida" cercando il percorso migliore


**Esistono diversi modi per fare routing:**
- **Traditional Routing Algorithms**: Effettuato dai singoli router senza una visibilità globale
  *Come funziona:*
  I router "chiacchierano" tra loro usando protocolli di routing. Si scambiano informazioni su chi sono i loro vicini e su quali reti riescono a raggiungere. Unendo tutte queste informazioni parziali, ogni router si costruisce faticosamente la sua visione della rete e compila la propria tabella di routing.
  
  - *Pro:* È **estremamente resiliente**. Se un router si guasta o un cavo viene tranciato, i router vicini se ne accorgono, si scambiano nuove informazioni e calcolano percorsi alternativi. Non essendoci un server centrale, non c'è un singolo punto di vulnerabilità (_Single Point of Failure_).
  - *Contro*: Gestire reti enormi diventa complesso. Se devi cambiare una policy di rete (es. "blocca tutto il traffico in arrivo da questo IP"), devi spesso configurare i router uno per uno. Inoltre, i router devono avere CPU e memoria potenti per calcolare i percorsi continuamente.

- **Software Defined Network**: è un architettura centralizzata esterna che sa tutto della rete
  *Come funziona:*
  I router fisici o gli switch diventano dei semplici "inoltratori" di pacchetti (molto economici e veloci). A comandare è un server esterno e centralizzato chiamato **SDN Controller**. Questo controller ha una visione globale e in tempo reale di _tutta_ la rete e dice ai vari router cosa fare, programmando le loro tabelle di inoltro.
- *Pro*: **Programmabilità e agilità**. Puoi cambiare il comportamento dell'intera rete con pochi clic o tramite un software centrale, senza toccare i singoli apparati. È ideale per i grandi data center dove la flessibilità è tutto.
- *Contro*: Il controller è il "tallone d'Achille". Se il controller va offline (e non ci sono sistemi di backup robusti), l'intera rete diventa "stupida" e smette di instradare nuovi flussi di traffico. Inoltre, c'è bisogno di una connessione sicura e costante tra i router e il controller.
  
- **Virtual Circuit Service**: quando due peer devono comunicare in modo diretto si costruisce un circuito virtuale, l'inoltro dei pacchetti avviene usando questo circuito diretto. Un qualsiasi malfunzionamento tra i router implica una *riconnessione da zero*
  *Come funziona:*
  Prima di inviare anche un solo bit di dati, i due nodi devono instaurare una connessione (Fase di _Setup_). I router lungo il percorso si accordano e prenotano le risorse creando un "tubo" virtuale (il circuito). A questo circuito viene assegnato un identificativo. Quando iniziano a viaggiare i pacchetti, questi non usano più l'indirizzo IP di destinazione completo, ma solo l'identificativo del circuito.

- *Pro*: **Garanzia delle prestazioni (QoS - Quality of Service)**. Poiché le risorse sono prenotate, i ritardi sono prevedibili e i pacchetti arrivano esattamente nello stesso ordine in cui sono partiti.
- *Contro*: E' **fragile**. Se un router in mezzo al percorso si guasta, l'intero circuito crolla. I pacchetti in volo vengono persi e i nodi devono ricominciare la fase di _Setup_ da capo per costruire un nuovo circuito.

Le garanzie in termini di reliability sono affidate al livello trasporto, tramite i meccanismi vari di TCP, con una larghezza di banda sufficientemente grande, le applicazioni funzionano piuttosto bene.

**Router**
I router sono sicuramente i dispositivi più responsabili dell'instradamento e dell'inoltro, sono formati da diversi componenti. In un router, mentre il processo d’instradamento è principalmente software, le porte di ingresso, di uscita e le strutture di commutazione, sono gestite da hardware dedicato. In questo modo, è possibile ottenere le performance richieste dalla rete, operando in lassi temporali dell’ordine dei millisecondi.

• *Porte di ingresso*. Sono le terminazioni a livello fisico per i collegamenti in ingresso al router. Inoltre, è sempre nella porta d’ingresso che si effettua la decisione di forwarding. Ogni porta contiene infatti una copia della tabella di routing. In questo caso, il termine ”porta” fa riferimento a interfacce fisiche d’input (e output), ben diversi dalle porte software dei processi e dei socket. 
• *Struttura di commutazione*. Connette fisicamente le porte d’ingresso a quelle di uscita. Una sorta di rete interna al router.
• *Porte di uscita*. Memorizzano i pacchetti che provengono dalla struttura di commutazione e li trasmettono sul collegamento d’uscita. Nei collegamenti bidirezionali, la porta d’uscita è accoppiata alla porta d’ingresso sulla stessa scheda di collegamento. 
• *Processore d’instradamento*. Esegue le funzioni del control plane.


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
3) Session Hijacking


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


![[Pasted image 20260424085243.png]]
Come possiamo vedere l'header IPv6 è più grande di quello di IPv4 in termini di byte ma è 
molto più semplice, la dimensione maggiorata è dovuta ai 2 campi contenenti l'IP dato che l'indirizzo IPv6 è composto da 128 bit anziché i 32 di IPv4

In IPv6 il campo hop limit sostituisce il time to live (TTL) ed è 255, lo stesso numero del time to live di IPv4, non è stato alzato perché gli hop sono i salti tra router quindi se un pacchetto deve fare 255 salti è già tantissimo,anche troppo, quindi un numero più alto non ha senso

**Comunicazione tra reti IPv4 e IPv6**
Si può comunicare tra IPv4 e IPv6 tramite incapsulamento, perché IPv4 non è compatibile con IPv6, quindi prendo il pacchetto IPv4 e lo incapsulo dentro un pacchetto IPv6 cosi che questo possa viaggiare in una rete IPv6 o viceversa. Questo meccanismo si chiama *tunneling*

**NOVITA' assoluta di IPv6**: gli header opzionali 
Anziché mettere tutti i possibili header come in IPv4 che rallentano il lavoro dei router (perché li devono analizzare tutti) se servono alcuni header specifici questi vengono aggiunti in coda al campo "next header"
![[Pasted image 20260423113101.png|571]]

**DHCP 6**
C'è anche il DHCP 6 che è migliore perché usando questi indirizzi non devo mandare una DHCP request in broadcast da anonimo ma questi server funzionano in multicast cioè: il client manda una richiesta solo ai server che gestiscono pacchetti DHCPv6 anziché mandarli in broadcast, questo riduce la congestione in rete.

**Firewall**
Un firewall serve a bloccare il traffico malevolo che vuole attaccare una rete e lo fa attraverso una serie di regole impostate dall'amministratore in base alla priorità di protezione.

Queste regole chiamate regole di routing sono basate su:
• Indirizzi IP e porte di origine e destinazione. 
• Protocolli (TCP, UDP, ICMP...). 
• Stato della connessione. 
• Contenuto del pacchetto, in firewall con ispezione profonda. I firewall posso operare a livello di rete, di trasporto e/o al livello applicativo, a seconda delle esigenze di controllo

Abbiamo 2 tipi firewall:
- Firewall software -> che bloccano il pacchetto all'entrata (è comunque possibile attaccare, ma meglio di niente)
- Firewall hardware -> dispositivo esterno che fa solo questo
Questa è una possibile disposizione di firewall hardware.
![[Pasted image 20260423115050.png|604]]
La zona interna al cerchio è nascosta al mondo esterno, mentre per fare quel firewall uso router che mi filtrano i pacchetti e anche un dispositivo che può leggere pacchetti fino al livello application. (Esempio pratico: arriva un pacchetto con dentro un eseguibile, l'application gateway lo vede e scarta il pacchetto).

La soluzione sopra è molto costosa, se voglio risparmiare opto per un firewall software e basta.


**DMZ** **(Demilitarized Zone)**
Nella DMZ tipicamente metto dei server e metto delle regole di firewalling sia per uscire che per entrare, in base ai server la dentro imposto queste regole (ad esempio la comunicazione può arrivare solo alla porta 80 oppure entrano solo richieste HTTP ecc...)


**Algoritmi di routing**
Si ragiona per grafi pesati, ma bisogna stabilire il peso e sopratutto non è scontato conoscere già il grafo.

Per stabilire il peso si usano diverse metriche (non ha specificato quali, forse il numero di hop)
![[Pasted image 20260423123136.png|517]]

Se non conosciamo il grafo si deve fare una visita (algoritmi) e si guarda ogni cosa, l'algoritmo di si chiama flooding,

Se non conosciamo il grafo si deve fare una visita (algoritmi) e si guarda ogni cosa, l'algoritmo usato di si chiama **flooding**

**Algoritmo di Flooding -> flooding vuol dire inondato**
Un nodo manda un pacchetto ai vicini e i vicini lo mandano ai loro vicini e cosi via...
![[Pasted image 20260423123348.png|585]]
Il problema è che si crea un circolo vizioso e si inonda la rete
![[Pasted image 20260423123425.png]]

Un primo metodo per risolvere questo problema è ricordarsi di aver già mandato quel pacchetto e quindi se lo ricevono di nuovo lo scartano

seconda soluzione dopo un tot di hop (esempio 10) ogni router si ferma e non invia più i pacchetti

Il flooding ha un vantaggio: trova la strada migliore perché trova ogni strada possibile 

ha nominato STP spannig tree protocol
in pratica serve trovare un albero per rappresentare questa rete quindi si organizza un torneo in cui i nodi a 2 a 2 si sfidano per chi ha il MAC ADDRESS più piccolo o più alto in questo modo l'informazione del vincitore si propaga a tutti e abbiamo un albero, questa cosa è implementata in STP

**Soluzioni al problema**

1) Un primo metodo per risolvere questo problema è ricordarsi di aver già mandato quel pacchetto e quindi se i router lo ricevono di nuovo lo scartano

2) Seconda soluzione dopo un tot di hop (esempio 10) ogni router si ferma e non invia più i pacchetti


**Il flooding ha un vantaggio: trova la strada migliore perché trova ogni strada possibile** 

(ha nominato STP spannig tree protocol
in pratica serve trovare un albero per rappresentare questa rete quindi si organizza un torneo in cui i nodi a 2 a 2 si sfidano per chi ha il MAC ADDRESS più piccolo o più alto in questo modo l'informazione del vincitore si propaga a tutti e abbiamo un albero, questa cosa è implementata in STP)

*Vantaggi di flooding*
- trova la strada per la destinazione se esiste
- trova la migliore
*Contro:* 
- crea una quantità gigante di pacchetti duplicati anche se la situazione può essere controllata

**Distance Vectors**
E' stato il primo algoritmo di routing.

**Distance Vectors**
E' stato il primo algoritmo di routing ed è basato sull'idea dell'algoritmo di *Bellman-Ford*.
Ogni nodo conosce sicuramente i suoi vicini e ha una tabella in cui le colonne sono le uscite del nodo e le righe sono le possibili destinazioni
![[Pasted image 20260423124824.png]]Sono il nodo E e uso l'uscita A per arrivare ad A -> peso 1
Sono il nodo E e uso l'uscita D per andare a C -> peso 4

Perché si chiama distance vectors? **(Ne dobbiamo parlare all'esame)**
Ogni router mantiene e comunica una lista (un **vettore**) che contiene due informazioni fondamentali per ogni nodo della rete:
1. **Distanza (Distance):** Il costo stimato (metrica) per raggiungere una specifica destinazione.
    
2. **Direzione/Vettore (Vector):** L'interfaccia di uscita o il router adiacente (next-hop) da utilizzare per inoltrare il pacchetto lungo il percorso scelto.

**Sistemi centralizzati e decentralizzati**
Nei sistemi che usano il distance vectors, ogni nodo è indipendente e pari rispetto agli altri, si dice che è un *sistema decentralizzato*. Al contrario, un *sistema centralizzato* è più semplice da gestire perché c'è un singolo nodo che comanda/gestisce tutti gli altri ma se questo nodo "capo" viene a mancare per un guasto o un attacco, la rete non funzionerà più bene. Nei sistemi decentralizzati (come quelli che implementano il distance vectors) ogni nodo conosce solo i suoi vicini diretti e conosce le informazioni che questi gli passano (cioè il vettore delle distanze)

**Problema del Distance Vectors**
Uno dei problemi più importanti del distance vectors è che le false notizie si propagano dato che il nodo conosce le informazioni che i suoi vicini gli passano, ma se quelle informazioni sono false verranno prese per vere

**RIP e problema della distanza**
Il protocollo di distance vectors è stato implementato nel protocollo RIP, in cui la distanza veniva misurata attraverso i salti (hop), 1 distanza = 1 hop, senza tener conto della distanza fisica nella realtà o della larghezza di banda di quel collegamento 
Esempio: potrebbero esserci 2 router che hanno stessa distanza per il nodo (1 hop) ma uno si trova a 1 km l'altro a 10 metri.


**Protocollo LINK STATE ROUTING**
LSR ha sostituito il protocollo RIP.
Questo protocollo usa un idea diversa (nel distance vectors si usava Bellman-Ford), qui si usa l'algoritmo di Dijkstra.
L'obbietti di questo protocollo è avere una conoscenza completa della rete da parte di ogni nodo. Infatti qui ogni router investiga sui suoi vicini e poi manda le informazioni in multicast (quindi solo ai router) in modo che tutti possano conoscersi e determinare la via con minor costo. Il calcolo del percorso ottimale è basato sull'algoritmo di Dijkstra

LSR periodicamente manda dei pacchetti di aggiornamento sullo stato del link, questo pacchetto è chiamato Link State Packet (LSP) e contiene informazioni del tipo: mittente, interfacce attive, costo del collegamento ecc...
Queste informazioni vengono inoltrate a tutti i nodi della rete attraverso l'algoritmo di flooding, quindi il primo router manda l' LSP ai suoi vicini e questi ultimi li inoltrano ai loro vicini (tranne a quello da cui l'hanno ricevuto) si fermeranno solo quando tutti i nodi hanno ricevuto il pacchetto e tutti hanno quindi ricevuto l'aggiornamento sullo stato della rete.

Questo è utile quando ad esempio nella rete si verificano dei guasti a dei nodi o ne viene cambiata la configurazione, scambiandosi LSP i router possono aggiornarsi sulla nuova disposizione della rete

LSR è migliore di RIP anche perché considera nel calcolo della distanza e del costo anche la larghezza di banda. Ad esempio permettendo di preferire un percorso con 3 salti a 10 Gbps rispetto a uno con 1 salto a 10 Mbps.

**Problemi di LSR**
LSR non è perfetto anzi esistono diversi problemi come:
- Il maggior uso di CPU e memoria: utilizzando Dijkstra anche su reti con diversi nodi questo influisce negativamente sulle performance dei router, dato che questo algoritmo non ha una bassissima complessità
- Oscillazione delle rotte
  ![[Pasted image 20260501100725.png|369]]
  Il calcolo del costo viene fatto anche in base alla larghezza di banda disponibile in quel collegamento, quindi immaginiamo questa situazione: i 4 router sono collegati da due collegamenti che offrono le stesse prestazioni: uno ha un flusso di traffico supponiamo ad intensità 1 mentre l'altro 1+e, i router quindi calcolano che il percorso con minor costo sia quello con intensità 1 quindi cominciano a mandare pacchetti in quel collegamento, nel frattempo il collegamento che aveva intensità 1+e ora si è svuotato, i router ricalcolano i costi e cambiano di nuovo collegamento. Questo effetto si chiama *Oscillazione delle rotte*, i router tenderanno ad alternare i 2 collegamenti anziché usarli entrambi dividendo il traffico, questo porta ad un calo di prestazioni sia della rete che dei router perché questi ultimi dovendo sempre ricalcolare dijkstra avranno sempre CPU e memoria occupate e potrebbero anche perdere dei pacchetti nel frattempo.

![[Pasted image 20260430093905.png|481]]

*LSR può lavorare su reti piccole e medio-grandi ma non conviene più su reti grandissime, perché la complessità e la matrice di adiacenza di dijkstra cresce sempre più quando aumenta il numero di nodi.*

**AS: Autonomous System**
Per questo motivo internet o comunque reti giganti sono divise in AS -> Autonomous system, gestite e amministrate da enti come ISP (Internet Services Provider) come TIM Vodafone e altri, ma anche grandi aziende come Google hanno il loro AS. Un AS può essere grande come un intera nazione.

![[Pasted image 20260430094927.png]]
![[Pasted image 20260501101700.png|447]]



## **DATA LINK LAYER - DLL**

Il DLL si occupa di trasformare il segnale in bit e i bit in segnale, si occupa anche degli errori, raggruppa i bit per creare i frame

In ogni singolo host (device e router) di una rete, è implementato il Data Link Layer. Ciò avviene tramite una combinazione di hardware, software e firmware presente all’interno dei NIC (Network Interface Controller) dei dispositivi di rete. Buona parte del DLL è implementato in hardware, come il protocollo Ethernet nell’adattatore Intel 700, o il protocollo Wi-Fi nel chipset Atheros AR5006. Tuttavia, è il software a farsi ponte tra il livello di rete, e il livello fisico

**Comunicazione tra 2 Network Interface Controller**
Lato mittente: 
1. Il datagramma da trasmettere viene incapsulato in un frame del DLL. 
2. I campi d’intestazione del DLL vengono riempiti. 
3. (Se presenti) vengono stabiliti i valori dei bit nei campi per la rilevazione e correzione degli errori. 
4. Il pacchetto viene trasferito. 

Dal lato del ricevente: 
1. Il Network Interface Controller riceve l’intero frame. 
2. (Se presenti) effettua le verifiche relative ai campi di rilevazione e correzione errori. 
3. Estrae il datagramma. 
4. Manda il datagramma al livello superiore.

##### **Data Framing**
Si potrebbe pensare che usare 2 segnali per la comunicazione possa essere sufficiente, ma non è così, infatti in questo caso non è possibile stabilire se una sequenza di 0 sia una parte della comunicazione o se ci sia assenza di comunicazione, per questo motivo si utilizzano codifiche a più livelli:

**Tree level encoding**
Prevede 3 livelli di segnale: alto zero e basso.
Ci sono anche delle regole:
- prossimo bit = 0 -> nessuna transizione del segnale
- Prossimo bit = 1 e livello del segnale $\neq$ 0 -> Il segnale passa a 0.
- Prossimo bit = 1 e livello di segnale = 0 -> Il segnale passa ad un livello opposto a quello del più recente segnale diverso da 0.

![[Pasted image 20260501191132.png|717]]

Alcuni mezzi fisici come la gigabit Ethernet usano una codifica a 5 livelli che permette di inviare 2 bit per volta, *è quindi intuitivo pensare che più livelli aggiungo più la velocità della comunicazione aumenta, ed è così, però nella realtà devo tener conto del rumore intrinseco che si trova in ogni mezzo fisico reale*, ad esempio se ho un range di 5 volt (0-5 volt) è facile distinguere tra 0 e 5 (2 livelli) ma anche tra 0,1,2,3,4,5 (5 livelli) ma se volessi dividere in 1000 livelli la situazione si complica perché il la differenza tra un livello e l'altro è pochissima quindi basta anche un minimo rumore (che nella realtà è sempre presente) per generare degli errori, quindi dopo un tot di livelli smette di essere conveniente perché il canale è sempre più soggetto a errori man mano che i livelli aumentano 

**Problemi del tree level encoding**
Il tree level encoding è la base per la comunicazione ma presenta 2 problematiche:

1. **Il problema del DC-Balance (Componente Continua)**

In un mondo ideale, vorremmo che la media dei voltaggi inviati su un cavo fosse **0V**. Se la media è diversa da zero, si crea quella che chiamiamo "Componente Continua" (DC Offset).

- **Saturazione e Calore:** Se invii molti segnali positivi senza "compensarli" con quelli negativi, la linea accumula energia. Questo può surriscaldare i componenti o mandare in saturazione i trasformatori di accoppiamento che si trovano nelle schede di rete.
    
- **Spostamento della soglia:** Il ricevitore deve capire se un segnale è "alto" o "basso" confrontandolo con una media. Se la media elettrica del cavo si sposta verso l'alto a causa del mancato bilanciamento, il ricevitore potrebbe fare fatica a distinguere uno zero da un uno, perché la sua "linea di terra" di riferimento è diventata instabile.

2. **Perdita di Sincronizzazione (Clock Recovery)**
- **Il silenzio degli zeri:** Se invii una lunghissima sequenza di zeri e la tua codifica prevede che lo zero sia $0V$, il cavo rimane "piatto" per molto tempo. Senza cambiamenti di tensione (transizioni), il ricevitore non ha più riferimenti per capire dove finisce un bit e dove inizia il prossimo.

Per ovviare a questi problemi entra in gioco la codifica a blocchi:
**Codifica a blocchi**
sostituisce blocchi di bit di una determinata dimensione, con blocchi leggermente più grandi ( 4 → 5, 8 → 10), traducendo le sequenze in maniera tale da garantire un numero minimo di transizioni.

*4B5B*
Associa a blocchi di 4 bit, blocchi di 5 bit. Richiede una bandwitdh del 25% più capiente. E' utilizzata per fast Ethernet.
![[Pasted image 20260501211518.png|320]]

Esiste anche la codifica 8B10B che è molto usata in vari standard:
• PCI Express ( < 3.0 ) 
• IEEE 1394b (Firewire) 
• Serial ATA 
• Fibre Channel 
• Gigabit Ethernet (alcune versioni) 
• DisplayPort Main Link 
• DVI e HDMI
• USB 3.0



### ERROR DETECTION
**Ridondanza: elemento di base per l’error detection** 
Immaginiamo di voler trasmettere dei dati anagrafici all’interno di un generico pacchetto. Aggiungere allo stesso pacchetto un codice fiscale, mi fornisce delle informazioni si ridondanti, ma che mi permettono di individuare possibili errori di trasmissione successivamente alla comunicazione.

**Error Detection**

Nella realtà i pacchetti trasmetti contengono una sequenza di bit D (i dati) e un EDC (error detection and correction bits). L'EDC può essere una qualsiasi tecnica di controllo: CRC, Checksum, bit di parità ecc...
Una volta che il datagramma con EDC passa per il canale inaffidabile al pacchetto viene applicata la funzione inversa a quella di partenza per risalire ai dati originali e capire se ci sono stati degli errori
![[Pasted image 20260506115016.png|717]]

### ERROR CORRECTION
**Distanza Di Hamming**
Misura la distanza tra 2 code word: 
1000110
1100110
distanza = 1

*Vocabolario*
Definiamo vocabolario un insieme di codeword. Un vocabolario si dirà completo se, con $n$ bit, avrà $2^n$ codeword
![[Pasted image 20260505102514.png|429]]
In un vocabolario la distanza è misurata come il minimo tra tutte le distanze
Per comunicare si possono usare solo le code word appartenenti al vocabolario.

Se arriva questa code word: 101000 che non appartiene al vocabolario posso risalire in maniera probabilistica a capire qual'era la code word originale in base alla distanza dal vocabolario
![[Pasted image 20260505102620.png|370]]


> [!important] **Basi teoriche per poter fare rilevazione e correzione degli errori**
> 
Se abbiamo $e$ errori e vogliamo correggerli abbiamo bisogno di una distanza $d= 2e+1$ , invece per rilevarli abbiamo bisogno di una distanza $d = e+1$



>[!help] **Reminder - Formula coefficiente binomiale**
>![[Pasted image 20260506122006.png|200]]

**Formula generale per la correzione degli errori:**
![[Pasted image 20260506122115.png|717]]
![[Pasted image 20260506122130.png]]


**Codice di Hamming**
Questo algoritmo serve ad inserire dei bit di controllo prima di inviare il messaggio in modo che il destinatario possa risalire al messaggio originale in caso di errori dovuti al canale inaffidabile.

E' composto da 2 fasi: una di creazione del messaggio e una di verifica e correzione (per il destinatario)
- **Parte 1**
  L'obbiettivo qui è prendere i bit contenenti i dati e infarcirli con altri bit di controllo in modo che diventino resistenti agli errori
  Indicheremo con $b_r$ i bit di controllo, questi bit vanno posizionati solo negli indici che sono potenze di 2.
  Prendiamo la stringa di esempio: `xx1x001x0`
  Mettiamo in fila le posizioni da 1 a 9 e vediamo cosa c'è dentro:
	- Pos 1: **$b_1$** (bit di controllo, indicato con `x`)
	- Pos 2: **$b_2$** (bit di controllo, indicato con `x`)
	- Pos 3: $b_3 = 1$ (dato)
	- Pos 4: **$b_4$** (bit di controllo, indicato con `x`)
	- Pos 5: $b_5 = 0$ (dato)
	- Pos 6: $b_6 = 0$ (dato)
	- Pos 7: $b_7 = 1$ (dato)
	- Pos 8: **$b_8$** (bit di controllo, indicato con `x`)
	- Pos 9: $b_9 = 0$ (dato)
 
 Come troviamo il valore delle $x$? 
 La regola dice che ogni bit di controllo "sorveglia" uno specifico numero di bit:
>[!important] **REGOLA**
>Un bit di controllo in posizione $X$ sorveglia tutte e sole le posizioni che, scritte in binario, hanno un **1** nello stesso posto in cui ce l'ha la posizione $X$.
>Facciamo gli esempi concreti (usiamo 4 cifre binarie per comodità):
>- **Il bit $b_1$ (posizione 1):** In binario il numero 1 si scrive `0001`. L'uno si trova nell'**ultima cifra a destra**. Quindi $b_1$ sorveglia tutte le posizioni che in binario finiscono con 1. Quali sono i numeri che finiscono con 1 in binario? Esattamente i **numeri dispari**: 1 (`0001`), 3 (`0011`), 5 (`0101`), 7 (`0111`), 9 (`1001`), ecc.

L'operazione usata è lo *XOR* (se i bit sono uguali il risultato è 0, se sono diversi è 1
![[Pasted image 20260506124255.png|447]]

Sostituendo i valori calcolati ($b_1=0, b_2=0, b_4=1, b_8=0$) al posto delle `x` nella stringa di partenza, otteniamo il messaggio pronto per essere spedito: **`001100100`**

- **Parte 2**
![[Pasted image 20260506124528.png|319]]
Adesso il destinatario (che non sa ancora se c'è un errore) riesegue la stessa operazione di XOR di prima sugli stessi bit, i risultati trovati vanno confrontati con i bit di controllo (nelle pos. potenze di 2) e se sono uguali non ci sono errori, se sono diversi c'è un errore:
![[Pasted image 20260506124720.png]]

Per trovare il bit errato basta sommare gli indici dei bit di controllo che hanno fallito il test: in questo caso $b_2 + b_4 = b_6$ -> l'errore è in posizione 6. 
**Correzione**
Per correggere semplicemente eseguiamo un bit flip



### **Gestire gli accessi multipli**
In una rete, possiamo individuare due tipi di collegamento: 
*• Collegamenti punto a punto.* Sono collegamenti diretti tra trasmittente e ricevente. 
*• Collegamenti broadcast.* Sono collegamenti in cui più nodi trasmittenti e riceventi sfruttano lo stesso canale broadcast.

**Collisioni**
Quando due nodi cercano di trasmettere sullo stesso canale nello stesso istante, avviene una collisione. Le collisioni causano perdite di frame, e, in eccessiva frequenza, un generale spreco di banda. I protocolli di accesso multiplo gestiscono i canali in maniera consona per non rientrare in situazioni del genere. Esistono tre tipi principali di protocolli per l’accesso multiplo: 

• **Protocolli a suddivisione del canale**. Basati sulla suddivisione del canale in porzioni accessibili esclusivamente ad un nodo. 

• **Protocolli ad accesso casuale**. In cui l’accesso al canale avviene in maniera casuale. Il metodo in questione ammette collisioni, che verranno gestite in maniera opportuna. 

• **Protocolli a rotazione** - senza collisioni. Coordinando opportunamente l’accesso al canale, è possibile evitare le collisioni.

Iniziamo dai primi - *Protocolli a suddivisione del canale*
Abbiamo 3 protocolli diversi:
**FDMA - Frequency Division Multiple Access**. Consiste nella suddivisione dello spettro del canale in varie bande di frequenza. A ogni nodo è associata una banda fissa. Questa suddivisione limita la banda, sempre ad R/N , ma non blocca la trasmissione dei nodi. 

**TDMA - Time Division Multiple Access**. 
Supponiamo che un canale broadcast supporti N nodi, e che abbia velocità R bps. TDMA, suddividerà il tempo in intervalli di tempo, e ogni intervallo di tempo in N slot temporali. Ogni slot sarà dedicato ad un nodo: come conseguenza, ogni nodo avrà un tasso di trasmissione di R/N bps. Risolve effettivamente il problema delle collisioni, ma quando si è in uno slot temporale dedicato a un nodo che non deve trasmettere nel canale, avverrà un’attesa non necessaria. E' un protocollo equo, che previene le collisioni, ma limita la banda di ogni nodo a R/N , e porta i nodi in attesa anche quando gli altri non devono trasmettere nulla.

**CDMA - Code Division Multiple Access**. Consiste nell’associazione di un codice univoco ad ogni nodo. I dati inviati sono codificati secondo quel codice. Con codici opportuni, diventa possibile trasmettere simultaneamente dati a più nodi, e per i nodi, di interpretare in maniera corretta i bit dei dati codificati. Ogni nodo deve conoscere i codici altrui per interpretare correttamente i dati.

![[Pasted image 20260506150511.png|477]]

*Protocolli ad accesso casuale*
Ogni nodo trasmette alla massima velocità consentita (R bps), e ogni volta che avviene una collisione, i nodi ritrasmetteranno dopo un periodo di tempo casuale (random delay). Questo ritardo casuale è indipendente tra i vari nodi, e consente, con buona probabilità, di non subire ulteriori collisioni.

**Slotted ALOHA** 
• Tutti i frame contengono L bit. 
• Il tempo è suddiviso in slot L/R secondi. 
• La trasmissione del frame da parte del nodo, inizia all’inizio degli slot. • I nodi sono sincronizzati in modo che tutti sappiano quando iniziano gli slot. 
• Se in uno slot due o più frame collidono, tutti i nodi della rete rilevano l’evento prima della fine dello slot. Indichiamo $k ∈ [0, 1 − K], K ∈ N$. I nodi slotted ALOHA seguono il seguente comportamento: 
1. Quando un nodo ha un nuovo frame da spedire, attende l’inizio dello slot successivo, per poi trasmettere il frame. 
2. Se non si verifica una collisione, la trasmissione è conclusa. 
3. Se si verifica una collisione, il nodo la rileva prima del termine dello slot e ritrasmette il frame dopo k frame, fino a quando l’operazione non ha successo. k è un valore casuale minore di K. K cresce ad ogni collisione. `

E' un protocollo semplice, che consente ad ogni nodo di lavorare al massimo delle performance possibili, senza limitare i bps a priori. Inoltre, è un protocollo altamente scalabile e abbastanza decentralizzato: l’unica condizione, è che gli slot siano sincronizzati per tutti i nodi. Tuttavia, ammette collisioni e idle slots, uno spreco generale di slot e un aumento della latenza.


**Unslotted ALOHA o Pure ALOHA** 
E' una versione totalmente asincrona dello slotted ALOHA. Il nodo mittente aspetterà un tempo pari al Round Trip Time, in attesa di un ACK. Se l’ACK non arriva, il nodo intuirà che è avvenuta una collisione. In tal caso, aspetterà un quanto di tempo di durata casuale (ma inclusa in un range determinato). Le performance migliori, sono ottenute dalla versione con gli slot temporali.
![[Pasted image 20260506151256.png|597]]
E un grande prezzo da pagare quello per la completa asincronia: l’algoritmo slotted ha un throughput complessivo due volte più grande di quello unslotted. L’intuizione è banale: nella versione slotted di ALOHA, due frame possono essere mandati solo all’inizio dello slot temporale. Nella versione unslotted, i frame possono collidere anche a metà trasmissione.

**CSMA - Carrier Sense Multiple Access** 
I protocolli ALOHA, portano i nodi a decidere di trasmettere indipendentemente dall’attività degli altri nodi. *I protocolli CSMA introducono un meccanismo di rilevamento della portante del canale, per ”ascoltare” se altri nodi stanno già trasmettendo. In questo modo, i nodi trasmetteranno esclusivamente quando non rilevano alcuna trasmissione già presente nel canale.* Al contrario di ciò che si potrebbe pensare, questo protocollo non sconfigge definitivamente la problematica delle collisioni. La velocità di trasmissione (nonostante spesso sia altissima) è un fattore non trascurabile. 

1. Il nodo A trasmette all’istante $t_0$. 
2. B misura la portata del canale all’istante $t_1 > t_0$. 
3. All’istante $t_1$ i bit trasmessi da A potrebbero non essersi propagati fino a B. 
4. B trasmette. Collisione!

**CSMA-CD - Carrier Sense Multiple Acces** **con Collision Detection** 
Un miglioramento è ottenuto se si introduce un meccanismo di collision detection sopra quello di rileva- mento del carico: la scheda che avrà trasmesso un determinato frame continuerà a misurare il carico del canale. Se rileva rumore o energia di altre trasmissioni nel canale, il nodo interromperà istantaneamente la trasmissione del frame, manderà un segnale di jamming con backoff a tutti gli host, informando tutti i nodi della collisione, e attenderà un quantitativo di tempo casuale per poi ritrasmettere. Questo tempo è chiamato tempo di backoff, non è fissato (intuitivamente renderebbe inutilizzabile il protocollo), e dipende dall’algoritmo scelto dal protocollo.
![[Pasted image 20260506151900.png|565]]


**Protocollo Ethernet**
Ethernet è di gran lunga lo standard di reti cablate più diffuso al mondo, per le reti locali. Rappresenta la prima LAN ad alta velocità con vasta diffusione. E' riuscito a rimanere al passo tramite versioni via via più veloci, e mantenendo i costi delle componenti hardware non particolarmente alti. E' parte dello standard IEEE 802.3

Il formato originale del frame era:
![[Pasted image 20260512120752.png|537]]


La velocità di comunicazione dipende dal canale, più il canale sarà pervaso dal rumore minore sarà il bit-rate. Possiamo identificare il rumore come un segnale che va a disturbare il segnale presente nel cavo e che sta "trasportando" i dati, l'idea è quindi quella di creare un cavo ben schermato dai rumori esterni in modo da preservare il segnale all'interno e aumentare quindi il bit-rate. 
![[Pasted image 20260515161353.png|717]]

Prendendo come esempio i cavi il cui mezzo di trasmissione è il rame la varie categorie differiscono in velocità perché sono meglio schermati o adattati in modo da soffrire meno il rumore, ad esempio all'inizio c'era solo una guina di gomma, poi sono stati intrecciati, poi schermati con l'alluminio ecc... .

![[Pasted image 20260515161726.png|619]]
![[Pasted image 20260515161744.png|521]]


### **Strutture Ethernet**
Hub e bridge sono dispositivi hardware e servono a collegare le varie sotto reti diverse, l'hub è ormai obsoleto mentre il bridge è alla base dei moderni switch

L’ormai obsoleto hub: 
• Lavora principalmente al livello fisico. 
• Ripete e rigenera il segnale su tutte le porte. 
• Il dominio di collisione tra tutti i dispositivi collegati è unico. 
• Broadcast domain unico. 

Il bridge, invece: 
• Lavora a livello data link. 
• Filtra e inoltra in base all’indirizzo MAC 
• Nel bridge ogni porta crea (idealmente) un dominio di collisione separato. 
• Broadcast domain unico.

**Switch**
E' un dispositivo che trasmette pacchetti ricevuti a uno o più dispositivi destinatari. E' più espandibile in termini di numero di porte, rispetto al bridge, e effettua operazioni di inoltro (individuare a quale interfaccia mandare il frame) e filtraggio (capire quando scartare un frame). Uno switch contiene al suo interno una switch table con record del tipo Indirizzo MAC - Interfaccia - Tempo. Il tempo viene utilizzato per stabilire quando un dispositivo non è più presente nella rete: verrà dedotto in quanto non verranno mandati più pacchetti al suo indirizzo MAC per molto tempo. Gli switch sono full duplex, senza collisioni.


### **VLAN**
Le LAN virtuali permettono di creare delle LAN logiche indipendenti sulla stessa struttura fisica.
![[Pasted image 20260520180556.png|608]]

Permette di risparmiare su costi, sulla manodopera e sulla complessità dietro il ricablaggio di una rete, per modificarne la struttura logica. Sono quindi delle vere e proprie LAN logiche separate che risiedono sopra la struttura fisica. Le LAN virtuali rimappano le tabelle di forward del bridge senza modificare la cablatura. Una porta può essere associata a una e una sola VLAN, altrimenti si riscontrerebbero collisioni.

*Scopo delle VLAN* 
• Riutilizzo dell’architettura di partenza con conseguente risparmio. 
• Flessibilità. Molto più facile spostare gli utenti tra le VLAN. • Prestazioni migliori. Isolando il broadcasting nelle VLAN, 
• Sicurezza. E' semplice isolare dei sistemi tramite le VLAN.


*VLAN basata su porte* 
Lo switch può essere partizionato logicamente in più insiemi di porte. Le porte possono essere associate a delle VLAN. Nell’header dei frame DLL è presente un identificatore di VLAN.


### **Spanning tree protocol - STP**
*Ridondanza e loop:*
Solitamente una rete è collegata seguendo una topologia che preveda ridondanza, in parole povere se un collegamento si rompe la rete continua a funzionare, magari con dei rallentamenti ma funziona. *La ridondanza di per se è una cosa buona ma è soggetta al rischio di loop*. Ad esempio:
![[Pasted image 20260520181751.png]]
Immaginiamo che in questa rete PC1 debba mandare un messaggio in broadcast, inoltra quindi il frame allo switch 1 che vedendo essere un messaggio broadcast lo invia su tutte le altre porte (tranne quella di partenza), quindi il messaggio arriva a SW2 e SW3, anche loro vedendo che si tratta di un messaggio broadcast lo invieranno a loro volta a tutti gli altri dispositivi, in questa maniera si è creato un loop in cui attraverso il meccanismo di *flooding* la rete resta inondata sempre dallo stesso pacchetto che viene di volta in volta inoltrato a tutti i dispositivi, inoltre i frame Ethernet non hanno un campo TTL (time-to-live) come i pacchetti IP . Per risolvere questo problema si è pensato di creare il protocollo STP.

*Alberi e grafi*
Una topologia di rete può essere vista come un grafo:
![[Pasted image 20260520182424.png|414]]
La differenza tra albero e grafo è che un albero è aciclico mentre un grafo normale lo può essere (come la rete in figura)

*E' un protocollo di livello 2 (Data Link) progettato per prevenire cicli (loop) infiniti in reti Ethernet dotate di collegamenti ridondanti.*
**Funzionamento**:
- STP trasforma una topologia fisica a grafo (dotata di cicli) in una **topologia logica ad albero** (senza cicli), *disabilitando selettivamente le porte ridondanti*.
- A questo punto sceglie un *root bridge* o switch capo (che funge da root dell'albero) e tutte le altre porte degli altri switch calcoleranno i costi (per mandare i frame) prendendo come riferimento lo switch capo.
- Le altre porte (quelle ridondanti) saranno accese e funzionanti ma bloccate in modo da "fare finta" che nella rete ci sia un solo collegamento ovvero quello che porta al root bridge.
- Se quel collegamento si guasta, gli altri switch ricalcoleranno il percorso più breve sbloccando un delle altre porte