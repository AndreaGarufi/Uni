# **Introduzione**
##### Cosa è l'IoT?
E' un ecosistema dove qualcosa ha le capacità di condividere le proprie informazioni, permette quindi di connettersi e condividere informazioni in rete e anche su internet.

---
##### Come è formato un oggetto IoT?
Un oggetto completo è formato da:
![[Pasted image 20261016192725.png|628]]

Quindi: sensori,motori,controller(CPU),antenna che può comunicare in rete

![[Pasted image 20261016192850.png|667]]

---
##### Architettura IoT![[Pasted image 20261016192959.png|667]]

---
##### Sfide dell'Iot
![[Pasted image 20261016193127.png|663]]

---
##### Come scegliere un microcontrollore
Ogni applicazione Iot ha bisogno di risorse, sta a chi crea il progetto implementarlo su un microcontrollore adatto a svolgere quel determinato compito.
Vanno considerate varie cose:
- Consumi elettrici
- Potenza
- Memoria
- Pin di I/O
- Architettura
- Dimensioni
- Ecc...

---
##### Programmazione microcontrollore Arduino
Noi programmeremo un "NANO ESP32".
Il requisito minimo per far si che un programma possa funzionare su questa scheda è che ci siano almeno 2 funzioni: 
- void setup()
- void loop()

La setup si esegue una volta sola all'avvio del programma, ed è usata per inizializzare tutte le varie componenti del programma.
La loop si esegue in continuazione dall'inizio fino alla fine e ricomincia, fino a che il microcontrollore è acceso. Qui si inseriscono tutte le operazioni che il microntrollore deve eseguire.

**Esempio di codice**
```
int sensorPin = A1; //define pin A1 (analog pin)
int ledPin = 2; //define pin 2 (digital pin)
int sensorValue; //create variable for storing readings

  
//void setup is for configurations on start up

void setup() {

    Serial.begin(9600); //initialize serial communication
    pinMode(ledPin, OUTPUT); //define ledPin as an output

}

void loop() {

    sensorValue = analogRead(sensorPin); // do a sensor reading
    Serial.print("Sensor value is: "); //print a message to the serial monitor
    Serial.println(sensorValue); //print the value to the serial monitor

    //check if sensorValue is below 200

    if(sensorValue < 200) {
        digitalWrite(ledPin, HIGH); //if it is, turn on the LED on pin 2.
    }
    //if sensorValue is above 200, turn off the LED
    else{
        digitalWrite(ledPin, LOW);

    }

}
```


# **Connettività IoT**
Ad oggi ci sono vari modi e protocolli per far comunicare dispositivi IoT sta al programmatore scegliere quelli più adatti per un corretto funzionamento del sistema.
![[Pasted image 20261016194622.png|668]]

Ovviamente le comunicazioni IoT sono per il 99% wireless.

Possiamo quindi categorizzare le reti wireless:
- WLAN -> Wireless Local Area Network
- WSAN -> Wireless Sensor Area Network
- LPWAN -> Low Power Wireless Personal Area Network

Queste differiscono per bandwith, raggio di copertura e consumi energetici.

Uno dei primi protocolli IoT wireless fu RFID.

##### RFID (Radio Frequency IDentification)
Sfrutta le onde radio per identificare e leggere dati da un "tag" senza un contatto fisico o una visuale diretta.
![[Pasted image 20261016195142.png]]

> [! abstract] Un tag *passivo* non ha batteria o trasmettitore, è il lettore che provvede a fornire energia e canale di comunicazione.

**Comunicazione con dispositivo RFID**
- **Power Up**: Il lettore emette un'onda portante continua. L'antenna del tag raccoglie energia (raddrizzatore + condensatore) e il chip si sveglia. 
- **Comando**: Il lettore modula la portante con brevi pause (ASK) per inviare i comandi: Il lettore parla per primo (Reader Talks First).
- **Riposta**: Il tag *non trasmette mai*: modifica il proprio carico (HF) o la quantità di segnale che riflette (retrodiffusione UHF / UHF backscatter).
- **Decodifica**: Il lettore rileva queste piccolissime variazioni, demodula, controlla il CRC e passa i dati all'host.

> [! abstract] Poiché il tag risponde solo quando interrogato, non necessita di **alcun oscillatore, trasmettitore o batteria**: ecco perché un tag passivo costa solo pochi centesimi

> [!caution] Cosa si intende con "il tag non trasmette mai"?
> **Il tag riflette/modifica il segnale (Backscatter):** Il tag si limita a cambiare le sue proprietà elettriche interne (modifica l'impedenza/carico del suo circuito). L'onda si riflette quindi cambiata rispetto a quando è stata inviata e da li si ottengono informazioni.

I tag non sono solo passivi, in alcuni casi possono disporre di batterie:
- *Tag passivi*: 
  - L'energia viene trasmessa dal reader 
  - Vita pressoché illimitata (almeno fino a quando il materiale di è composto non si degrada)
  - Costo bassissimo
  - Esempi: Badge, NFC stickers 

- *Semi-Passivi*:
  - Hanno una batteria che serve solo ad alimentare il chip interno e vari sensori
  - Sono senza trasmettitore, quindi rispondono tramite backScatter


- *Attivi*:
  - Hanno batteria e anche il loro trasmettitore

Range e costi aumentano dal all'alto verso il basso.

---
##### Tipologie di RFID
- Read-only -> i dati vengono impressi al momento della costruzione e possono solo essere letti.
- WORM -> Write Once Read Many. Quindi si scrive dentro il dispositivo e quest'ultimo si blocca permettendo solo letture.
- Read/Write -> Questi RFID sono riprogrammabili.

![[Pasted image 20261017095258.png|414]] In Byte...


![[Pasted image 20261017095412.png|720]]


Vediamo un esempio di come funziona la tecnlogia mifare RFID:

##### RFID MIFARE
![[Pasted image 20261017101528.png|720]]

Questa è la struttura di un RFID di questo tipo. 
Abbiamo 16 settori divisi ognuno in 4 blocchi, ogni blocco contiene 16 byte, quindi un totale di 1024 byte di capienza, anche se non tutti sono utilizzabili, infatti sono solo 752 quelli usabili, questo perché il primo blocco del primo settore è riservato al costruttore per inserire i dati del tag e alla fine di ogni settore c'è un blocco chiamato trailer che contiene informazioni riguardanti quello specifico settore, quindi a conti fatti abbiamo 3 blocchi utilizzabili per 15 settori e 2 blocchi per il primo.

![[Pasted image 20261017102402.png]]

Per quanto riguarda il *block 0* abbiamo: 
- UID che contiene l'identificativo unico della scheda e occupa 4 byte
- BCC che è un byte di checksum
- SAK che indica la tipologia di MIFARE, occupa un byte
- ATQA Answare To reQuest A, occupa 2 byte ed è il comando che lancia il tag al lettore
- Manufacturer data sono dati del produttore, lotto marca ecc...

Per quanto riguarda il *sector trailer* abbiamo: 
- Key A è una chiave segreta usata per l'identificazione, occupa 6 byte
- Access bits occupano 3 byte e definiscono le condizioni di accesso (lettura/scrittura) per tutti e 4 i blocchi del settore. Bisogna stare attenti a impostarli correttamente.
- GPB byte generico per utilizzo di sistema
- Key B chiave segreta B opzionale di 6 byte

Di fabbrica i valori della chiavi sono sempre FF FF FF FF FF FF, vanno modificati dal programmatore.

Le chiavi servono ai lettori RFID per autenticarsi e poter accedere ad un determinato settore.

Per quanto riguarda il i *data block* abbiamo 16 byte liberi in cui si possono scrivere dei dati.

![[Pasted image 20261017111737.png]]

Questa è la configurazione degli access bits che gestiscono i permessi per ogni blocco, ad ogni blocco "b" vengono associati 3 bits le cui combinazini ne stabiliscono i permessi, ogni bit viene salvato 2 volte (una volta normale e una volta in forma negativa) questo viene fatto per ridondanza e sicurezza, al momento della lettura, se non corrispondono il blocco viene o il settore viene bloccato per sempre.

![[Pasted image 20261017112004.png]]

Bisogna stare attenti a dare i valori agli access bits perche se impostati ad esempio tutti a 1 non si avranno più i permessi ne di lettura ne di scrittura, e il blocco verrà perso per sempre.

Vediamo un esempio di codice:
```
#include ude <iot_board.h>
#include <Adafruit_PN532.h>
Adafruit_PN532 nfc(-1, -1, &Wire);    // I2C, IRQ and RST not wired

void setup() {
  IoTBoard::init_serial();
  IoTBoard::init_display();           // Wire.begin(A4, A5)
  nfc.begin();
  uint32_t v = nfc.getFirmwareVersion();       // cmd 0x02
  if (!v) { Serial.println("No PN532"); while (true) delay(1000); }
  Serial.printf("PN5%02X fw %u.%u\n", (v >> 24) & 0xFF,
                (v >> 16) & 0xFF, (v >> 8) & 0xFF);
  nfc.SAMConfig();                             // cmd 0x14
  nfc.setPassiveActivationRetries(0x10);       // do not wait forever

}

void loop() {

  uint8_t uid[7], len;
  if (!nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &len))
    return;                                    // cmd 0x4A
  Serial.print("UID:");
  
  for (uint8_t i = 0; i < len; i++) Serial.printf(" %02X", uid[i]);
  Serial.println(len == 4 ? "  Classic?" : "  NTAG?");
  delay(1000);

}

uint8_t keyA[6] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };  // factory
const uint8_t BLOCK = 4;                 // sector 1, block 0

void loop() {

  uint8_t uid[7], len, buf[16];
  if (!nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &len))
    return;
  if (len != 4) return;                  // Classic: 4-byte UID
  // 1) authenticate the sector: keyNumber 0 = Key A, 1 = Key B
  if (!nfc.mifareclassic_AuthenticateBlock(uid, len, BLOCK, 0, keyA)) {
    Serial.println("Auth failed: wrong key?");
    return;
  }

  // 2) write 16 bytes, then read them back

  uint8_t data[16] = "Hello UNICT IoT";  // 15 chars + '\0'
  if (nfc.mifareclassic_WriteDataBlock(BLOCK, data) &&
      nfc.mifareclassic_ReadDataBlock(BLOCK, buf)) {
    for (uint8_t i = 0; i < 16; i++) Serial.printf("%02X ", buf[i]);
    Serial.println();

  }
  delay(2000);

}
```


---
##### Tecnologia NFC (Near Field Communication)
L'NFC è l'evoluzione di High Frequency RFID. Possiamo quindi dire che NFC sia un sottoinsieme di RFID.
- NFC funziona ad una frequenza di **13.56 MHz**.
- A differenza degli RFID normali, un dispositivo NFC può essere un reader, un tag o tutti e 2 (ad esempio lo smartphone).
![[Pasted image 20261021164630.png|341]]

- Il range di comunicazione così piccolo non è un problema ma bensì una feature.

**Possibili utilizzi**
- Un telefono può leggere/scrivere un tag NFC passivo.
- Card Emulation, ovvero un dispositivo come un telefono può emulare il comportamento del tag di una carta di credito (pagamenti contactless).
- 2 dispositivi NFC possono scambiarsi dei dati.

**Tipologie di comunicazione NFC**

2 dispositivi NFC possono comunicare in 2 modalità diverse in base alla tipologia di tag:
- *Comunicazione Passiva*
  Solo un dispositivo è dotato di alimentazione propria e il tag passivo comunica tramite "load modulation" ovvero per comunicare assorbe più o meno energia (fornita dal reader) e quindi ne riflette di più o di meno (se assorbe di più rifletterà di meno e quindi magari è uno 0).
- *Comunicazione Attiva*
  Entrambi i dispositivi sono dotati di alimentazione propria e quindi ognuno emette onde elettromagnetiche per comunicare, quando uno comunica l'altro sta in ricezione e viceversa.

**Standard di NFC**
![[Pasted image 20261021170257.png|720]]


---

##### Il frame NFC -> NDEF (NFC Data Exchange Format)
Analizziamo l'immagine:
![[Pasted image 20261021170738.png|606]]

NDEF message -> non è altro che il messaggio che contiene vari record
Ora analizziamo la struttura del record:
- *Header 1 Byte* -> un byte di controllo che contiene vari flag al suo interno:
  - *MB* -> message begin: vale 1 se è il primo record del messaggio
  - *ME* -> message end: vale 1 se è l'ultimo record del messaggio
  - *CF* -> chunk flag: vale 1 se il payload del messaggio è frammentato in più record consecutivi
  - *SR* -> short record: se vale 1 il campo payload length è di solo 1 byte
  - *IL* -> ID length present: Se vale 1, segnala che il campo ID LENGTH (e il successivo campo ID) è presente nel record.
  - *TNF* -> Type Name Format: bit che specificano come interpretare la struttura del campo TYPE
- *Type length 1 Byte* -> indica la lunghezza in byte del campo type
- *Payload length 1 o 4 Byte* -> indica la dimensione del payload
- *ID length 0 o 1 byte* -> è presente solo se il campo IL è 1
- *Type* -> Definisce il tipo di dati contenuti (es. "U" per URI/URL, "T" per testo formattato, oppure tipi MIME come text/vcard)
- *ID* -> Identificatore univoco del record (utilizzato per correlare record multipli)
- *Payload* -> i dati effettivi

---
##### Struttura interna di un tag NFC
I tag RFID erano organizzati in settori e blocchi, i tag NFC sono organizzati in pagine, ogni pagina è composta da 4 byte.
![[Pasted image 20261021172457.png]]

Le pagine disponibili iniziano dalla 3 perche le altre sono riservate dal costruttore per inserire i propri dati.

---
![[Pasted image 20261021172745.png|655]]

---

##### WLAN (Wireless LAN)
La comunicazione wireless è half duplex e volendo è anche broadcast, usando (l'aria) un canale condiviso.

Una *WLAN* connette in maniera wireless e quindi usando le onde radio i device all'interno di una certa area come una stanza, una casa, un ufficio. Per accedere ad internet una WLAN utilizza un gateway (solitamente un router come quello di casa).

L'IEEE 802.11 è lo standard internazionale che definisce come devono essere organizzate le comunicazione wireless a corto raggio.

![[Pasted image 20261021174135.png|535]]

![[Pasted image 20261021174204.png|333]]


**Tipologie di reti WLAN**
![[Pasted image 20261021174300.png|177]]
I client parlano tra di loro solo attraverso l'access point (normale rete casalinga o di ufficio).

![[Pasted image 20261021174351.png|180]]
I dispositivi parlano direttamente tra di loro.

![[Pasted image 20261021174453.png|183]]
Gli access point sono connessi tra loro in maniera wireless anziché con un cavo.

![[Pasted image 20261021174528.png|185]]
Ogni nodo inoltra i frame per gli altri.

**Versioni di WI-FI**
![[Pasted image 20261021174746.png|720]]

**Banda WI-FI a 2.4 GHz**
![[Pasted image 20261021223041.png|598]]

**Spettro complessivo**: La banda va da $2400\text{ MHz}$ a $2483.5\text{ MHz}$

Lo spettro è diviso in 13 canali (14 per il Giappone), e la spaziatura tra ogni canale dista 5 MHz, il segnale emanato non è una singola linea che ricade precisamente al centro di ogni canale (canale 1, canale 2 ecc...) ma ha un ampiezza più grande, circa 20-22 MHz, per questo motivo i canali si sovrappongono tra loro creando interferenze tra di loro, è opportuno quindi scegliere dai canali che non si sovrappongono (dalla figura notiamo che il canale 3 si sovrappone dal canale 1 fino al quasi al 6) l'unica combo di canali che non si sovrappongono tra loro sono l'1 il 6 e l'11. 

La frequenza a 2.4 GHz è condivisa tra più standard perché è una frequenza libera, banalmente questa banda è la stessa del Bluetooth di Zigbee o dei forni a microonde.

---

##### CSMA/CA (Carrier Sense Multiple Access with Collision Avoidance)
A differenza delle reti cablate Ethernet che usano **CSMA/CD** (Collision _Detection_), nel wireless un'antenna **non può ascoltare l'aria mentre sta trasmettendo**. Poiché il segnale inviato localmente oscurerebbe qualsiasi segnale in arrivo, le collisioni sull'etere risultano "invisibili" per chi trasmette.

Non potendo rilevare le collisioni al volo, il protocollo deve fare di tutto per **evitarle preventivamente** (_Collision Avoidance_):
Analizziamo la time line del protocollo:
![[Pasted image 20261021224838.png]]

- **Listen first (Carrier Sense)**: Il mittente ascolta prima il canale per verificare se sia libero.
- **Attesa DIFS e Random Backoff**: Se il canale è o è diventato libero, non trasmette subito ma attende un intervallo prefissato (DIFS) più un tempo casuale (backoff).
- **ACK obbligatorio**: Per ogni frame unicast inviato correttamente, il ricevente deve restituire un riscontro (**ACK**) dopo un intervallo chiamato **SIFS**. Se il mittente non riceve l'ACK, presuppone che ci sia stata una collisione o una perdita di segnale e pianifica un reinvio.

*Come funziona il timer di backoff?*
Si sceglie un intervallo che va da 0 a $CW$ (Contention Window), il contatore viene decrementato solo fino a quando il canale è libero, se viene rilevato come occupato il time si blocca, e riprenderà solo quando il canale si libera di nuovo. Ad ogni fallimento di trasmissione (mancata ricezione di un ACK), la finestra di contesa $CW$ raddoppia, questo riduce di molto la probabilità che 2 nodi trasmettano di nuovo nello stesso istante.
**Priorità dell'ACK ($\text{SIFS} < \text{DIFS}$)**: Poiché l'intervallo SIFS è **più corto** dell'intervallo DIFS, il ricevente ha la garanzia di poter inviare l'ACK senza essere interrotto da altre stazioni che vogliono iniziare una nuova trasmissione (le quali devono aspettare almeno DIFS).

*Questo protocollo (come praticamente tutto nelle comunicazione wireless) confida nel fatto che la probabilità di scontri si abbassi, quindi va un po' a fortuna*

---
##### Problema del nodo nascosto (hidden node)
![[Pasted image 20261021225507.png|375]]
Come vediamo dall'immagine sia il nodo A che il nodo C hanno nel raggio di comunicazione l'access point ma non l'altro nodo.
Quando devono comunicare utilizzano CSMA/CA, quindi partono dall'ascoltare il canale e dato che non si "sentono tra loro" crederanno che il canale sia vuoto, se comunicano nello stesso istante collidono.

*Soluzione: meccanismo RTS/CTS*
Per evitare queste collisioni "invisibili", si introduce una handshake di prenotazione del canale:

- RTS (Request To Send): il nodo A prima di parlare manda un pacchetto RTS all'access point, per chiedere se può comunicare,
- CTS (Clear To Send): se l'AP è disponibile manda un' ACK chiamato CTS, e dato che AP raggiunge sia A che C, C noterà questo pacchetto CTS (C sa che non ha mandato lui RTS) quindi non comunicherà. (ricordiamo che il mezzo non è cablato ma è l'aria quindi le onde si propagano a 360 gradi).

- Ogni frame (inclusi RTS e CTS) contiene un campo **Duration** che specifica per quanto tempo il canale rimarrà occupato per completare lo scambio di dati.
- Quando C intercetta il CTS trasmesso dall'AP, legge questo valore e imposta un timer interno chiamato *NAV (Network Allocation Vector)*.
- Durante tutta la durata del NAV, C starà in silenzio facendo quello che viene chiamato Virtual Sense Carrier.
![[Pasted image 20261021230103.png|490]]

Il sistema RTS/CTS implica una certa quantità di over-head (messaggi in più in questo caso), quindi non è sempre conveniente, infatti *quando si devono scambiare piccoli frame questo sistema non viene usato,* *conviene invece usarlo quando il frame da mandare o comunque il messaggio è più grande*, perché stare sicuri di evitare collisioni in questo caso è più conveniente anche aggiungendo over-head.

---
##### Frame WI-FI
![[Pasted image 20261023190112.png|720]]

L'Header del frame Wi-Fi può variare da 24 a 36 Byte.

- *FC* -> Frame Control 2 Byte: contiene i metadati fondamentali per il controllo del frame (sotto le specifiche).
- *DUR* -> Duration 2 Byte: specifica il tempo in microsecondi necessario per riservare il canale wireless. Viene usato dalle altre stazioni per aggiornare il NAV del CSMA/CA.
- *Address 1,2,3* -> 6 Byte ciascuno: tre indirizzi MAC obbligatori (es. Receiver Address, Transmitter Address, BSSID/Source Address).
- *Seq* -> Sequence Control 2 Byte: gestisce il numero di sequenza del frame e il frammento, per riordinare i pacchetti e rilevare duplicati.
- *Address 4* -> 6 Byte: utilizzato principalmente nei collegamenti bridge wireless quando sia la sorgente originale che la destinazione finale sono al di fuori dell'AP trasmettitore/ricevitore.
- *QoS* -> 2 Byte e *HT* -> 4 byte: entrambi opzionali, campi aggiunti negli standard più recenti (802.11e/n/ac/ax) per la gestione della qualità del servizio (priorità del traffico) e per funzionalità ad alto rendimento (High Throughput).
- *Frame Body* -> 0-2304 Byte: è il payload.
- *FCS* -> Frame Check Sequence 4 Byte: Codice di controllo della ridondanza ciclica (CRC-32) per rilevare eventuali errori di trasmissione sul canale radio.

Dettaglio del campo FC:
- **Protocol**: Versione del protocollo 802.11.
- **Type (2 bit)** & **Subtype (4 bit)**: Identificano in modo univoco il tipo preciso di frame.
- **To DS / From DS**: Flag che indicano se il frame è diretto a o proviene dal _Distribution System_ (la rete cablata dietro l'Access Point).
- **More frag**: Indica se il frame corrente è seguito da altri frammenti.
- **Retry**: Impostato a `1` se il frame è una ritrasmissione di un frame precedente non confermato.
- **Pwr mgt**: Stato di gestione dell'energia (Power Save) del dispositivo.
- **More data**: Rileva se l'AP ha ulteriori frame memorizzati nel buffer per una stazione in modalità risparmio energetico.
- **Protected**: Indica se il payload è crittografato (es. WPA2/WPA3).
- **+HTC**: Segnala la presenza del campo opzionale High Throughput Control nell'header.

Vediamo il campo Type:
![[Pasted image 20261023192110.png]]

- Management -> Usati per la gestione e l'esplorazione della rete.
- Control -> Usati per coordinare l'accesso al canale e confermare la ricezione.
- Data -> Usati per il trasporto effettivo del traffico utente.

---
##### Connessione di un client ad un access point (AP)
La connessione si divide in 4 fasi:
1) *Discovery*: individuazione della rete -> può avvenire in maniera attiva o passiva
   - Passive scan: la station ascolta i frame di beacon mandati periodicamente dagli AP, che contengono informazioni come SSID, parametri di sicurezza ecc...
   - Active scan: la station invia un frame di *Probe request* per cercare delle reti e l'AP risponde con una *Probe response* contenente i dettagli della rete
   
2) *Auth + association*: autenticazione e associazione -> si compone di 2 fasi
   - Autenticazione: La Station invia un frame di _Authentication (Open System)_ e l'AP risponde con _Authentication: success_. Nelle reti moderne con WPA2/WPA3 questa è un'autenticazione puramente formale (a sistema aperto).
   - Associazione: La Station invia una *Association Request* specificando capacità e parametri di sicurezza. L'AP accetta inviando un'*Association Response* e assegnando alla Station un AID (Association Identifier).
   - NON viene ancora usata alcuna password

3) *Key Handshake*: Scambio delle chiavi di cifratura -> viene eseguito un *4-way handshake* (previsto negli standard WPA2 e WPA3). Durante questo scambio di messaggi, il client e l'AP derivano in modo sicuro le chiavi di sessione crittografiche per cifrare il traffico. **Nota importante:** Solo al termine con successo di questo handshake l'AP inizia a inoltrare i frame dati reali del client.

> [! question] Nota sulla password
> La password non viene mai inviata nell'etere ma si effettuano dei calcoli matematici in cui una delle componenti è la password e da li l'AP riesce a capire se la station che si vuole connettere ha la password giusta, in sostanza la password serve alle station e agli AP per generare dei messaggi/calcoli, la password resta "in locale" su ogni dispositivo

4) *IP*: a questo punto tramite servizio DHCP la station ottiene un indirizzo IP e lo stack TCP/IP è completamente funzionante.


Esempio di una tipica connessione:
![[Pasted image 20261024121436.png|472]]

---
##### Sicurezza Wi-Fi
![[Pasted image 20261024121540.png]]

---
##### Il Wi-Fi per l'IoT
**Punti di forza**
- Implementazione della comunicazione IP che quindi permette in maniera facile e veloce di comunicare su internet
- L'infrastruttura è già diffusissima
- Alto throughput, per quello che serve all'IoT almeno  

**Punti di debolezza**
- Power: le radio/antenne consumano molta energia e dato che molto spesso i dispositivi IoT sono a batteria è un problema 
- Un AP può gestire un numero limitato di dispositivi
- Il dispositivo ha bisogno di tutte le credenziali (*provisioning*) e fornirle non è immediato, possono essergli date in vari modi, tramite connessione bluetooth con un altro dispositivo che le ha, tramite portale web, tramite qr code ecc...

---
##### Wi-Fi su ESP32
Vediamo ora dal punto di vista pratico come connettere l'ESP32 al Wi-Fi:
![[Pasted image 20261024122552.png]]

Un ESP32 può lavorare come station che quindi vuole connettersi, come AP o entrambi.

Vediamo come collegare l'ESP32 come station ad un AP utilizzando la libreria WiFi.h:
Ci sono delle funzioni come:
- `bool mode(wifi_mode_t mode);` a cui possiamo fornire come parametro la modalità di utilizzo della board: 
  - `WIFI_OFF` per disattivare l'antenna wifi
  -  `WIFI_STA` per usare la board come station
  - `WIFI_AP` per usare la board come AP
  - `WIFI_AP_STA` per usare la board sia come AP che come station

- `wl_status_t begin(parametri)` inizia tutta la fase per una connessione con un AP che abbiamo visto prima, la libreria fornisce diversi prototipi per questa funzione tramite overload degli operatori di C++, quella che useremo di più sarà:
  - `wl_status_t begin(const char* ssid, const char* passphrase);` a cui passiamo SSID e password della rete a cui connettersi

- `WiFi.status()` restituisce lo stato della connessione, utile quando utilizzata insieme alla costante `WL_CONNECTED` che è true se la station è associata ed ha ottenuto un IP, come in questo esempio:
  - `while (WiFi.status() != WL_CONNECTED && millis() - t0 < 15000) delay(250);` ovvero finché il valore di `WiFi.status()` è diverso da quello di `WL_CONNECTED` resta nel ciclo.

>[! abstract] Buone pratiche di programmazione
> - Negli esercizi spesso inseriremo manualmente nel codice SSID e password da fornire alla funzione begin, ma nei casi reali si usa il provisioning, ovvero si utilizzano vari metodi per fornire tutto il necessario (vedi sopra punti di forza e debolezze del wifi per IoT)
> - Bisogna sempre usare un timeout in modo da non bloccare il flusso di esecuzione all'infinito in caso di credenziali errate o impossibilità a connettersi

- `WiFi.disconnet()`


**Eventi WiFi**
Gli **eventi Wi-Fi** sono notifiche generate dall'ESP32 per avvisare il programma quando cambia lo stato della connessione o della radio Wi-Fi.
Invece di obbligare il programma ad attendere o a fare _polling_ continuo nel `loop()` (ovvero controllare continuamente se la rete è connessa o disconnessa), l'ESP32 avvisa l'applicazione **solo quando si verifica un cambiamento**.
C'è un elenco di eventi wifi:
![[Pasted image 20261024142635.png|265]]

La funzione gestore dell'evento viene eseguita nel task di sistema dedicato al Wi-Fi (in un thread separato). (ESP32 può fare multiprogrammazione perché è dual-core)
È quindi importante far si che l'evento triggheri una funzione il più ottimizzata possibile e che non faccia un lavoro troppo grande per evitare rallentamenti o blocchi.

Vediamo un esempio di codice per connettersi ad un AP utilizzando gli eventi:
```
#include <WiFi.h>

const char *ssid = " Galaxy S21 5G";
const char *password = "campobasso12345";

void onWiFi(WiFiEvent_t event, WiFiEventInfo_t info) {
  switch (event) {
    case ARDUINO_EVENT_WIFI_STA_CONNECTED:
      Serial.println("Associated to the AP");
      break;
    case ARDUINO_EVENT_WIFI_STA_GOT_IP:
      Serial.print("IP: ");
      Serial.println(IPAddress(info.got_ip.ip_info.ip.addr));
      break;
    case ARDUINO_EVENT_WIFI_STA_DISCONNECTED:
      Serial.printf("Link lost, reason %d\n",
                    info.wifi_sta_disconnected.reason);
      break;                      // auto-reconnect is on
    default:
      break;
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.onEvent(onWiFi);           // un handler per tutti gli eventi
  WiFi.begin(ssid, password);     // attesa non bloccante: gli eventi ci notificheranno lo stato
}

void loop() {

}
```

Elenco di eventi WiFi triggherabili su ESP32 tramite la funzione onEvent()
![[Pasted image 20261024143600.png|720]]

---
##### Range di connettività
Quando si parla di IoT la distanza dall'access point non deve essere eccessiva, altrimenti la rete rallenta troppo e si perdono pacchetti.
È utile seguire questa tabella:
![[Pasted image 20261024143945.png|262]]

Con la ESP32 possiamo fare uno scan delle reti per vedere il valore di dBm, e quindi sapere se il segnale sarà buono o no. Vediamo il codice per farlo:

```
#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();               // scansione soltanto, non effettua la connessione[cite: 2]

  int numeroReti = WiFi.scanNetworks(); // scansione attiva su tutti i canali[cite: 2]
  Serial.printf("%d reti trovate\n", numeroReti);

  for (int i = 0; i < numeroReti; i++) {
    Serial.printf("%-20s ch %2d %4d dBm %s\n",
      WiFi.SSID(i).c_str(), 
      (int)WiFi.channel(i),
      (int)WiFi.RSSI(i),
      WiFi.encryptionType(i) == WIFI_AUTH_OPEN ? "open" : "secured");
  }

  WiFi.scanDelete();               // libera la memoria con la lista dei risultati[cite: 2]
}

void loop() {

}
```

---
##### Connettività tramite softAP (Software Access Point)
L'ESP32 può lavorare anche da AP tramite solo una configurazione software, non necessita quindi di un hardware dedicato per farlo.

Vediamo un pezzo di codice che lo rende AP:
```
#include <iot_board.h>
#include <WiFi.h>

void setup() {
  // IoTBoard::init_serial();
  WiFi.mode(WIFI_AP);
  
  // Parametri: ssid, password, channel, hidden, max clients
  WiFi.softAP("IoTBoard-42", "iot-lab-2026", 6, 0, 4);
  
  Serial.print("AP address: ");
  Serial.println(WiFi.softAPIP());   // Indirizzo IP di default del SoftAP: 192.168.4.1
}

void loop() {
  // Stampa il numero di client attualmente connessi alla rete SoftAP
  Serial.printf("Clients: %d\n", WiFi.softAPgetStationNum());
  delay(5000);
}
```
Parametri in dettaglio della funzione `WiFi.softAP("IoTBoard-42", "iot-lab-2026", 6, 0, 4);`
![[Pasted image 20261024150445.png|249]]

(Basta aggiungere un web server sulla porta 80 e abbiamo un portale di configurazione, il metodo classico per dare ad un device IoT le credenziali del wifi di casa.)

---
# **Reti Wi-Fi - MESH su ESP32**
I dispositivi hanno antenne Wi-Fi che per costruzione e funzionamento fisico hanno una portata limitata a delle decine di metri al massimo. In una configurazione sensoristica reale i dispositivi potrebbero essere messi distanti dall'access point più vicino, è utile pensare quindi ad una tipologia di collegamento chiamato MESH che collega i dispositivi tra loro e all'AP:
![[Pasted image 20261030123953.png]]

Una rete mesh è una rete che si *organizza da sola* (i nodi si organizzano tra padri e figli in automatico) e si *ripara da sola* (se un link si rompe la rete lo rileva e si auto ripara risistemando l'albero).

---
Vedremo 3 protocolli mesh.

---
##### Rete ESP-MESH
![[Pasted image 20261030144015.png|442]]

Questa tipologia di protocollo mesh richiede obbligatoriamente che nella rete sia presente un AP, altrimenti la rete intera non si può formare. I dispositivi eleggono un nodo root che sarà l'unico a poter comunicare direttamente con il router, ogni altro nodo farà capo alla root, come tutte le reti mesh anche in questo protocollo la rete si ribilancia e ripara in autonomia.
Un router può gestire più reti mesh indipendenti, basta cambiare il mesh-id e il mesh-pass.

*Livelli di lavoro*
- I nodi della rete ESP-MESH lavorano al livello 2 (data link layer) e non hanno quindi un indirizzo IP, la comunicazione avviene tramite MAC address, mentre la root (che è la sola connessa all'AP) lavora fino al livello 4 dello stack TCP/IP, perché lei ottiene un indirizzo IP e instrada i pacchetti verso l'AP tramite UDP. Quindi la root arriva fino al livello 3 e 4 in comunicazione out-mesh quindi verso l'AP.

A livello implementativo andiamo a gestire il programma in base agli eventi:
![[Pasted image 20261030144628.png|390]]

> [!warning] Radio Wi-Fi
> Il protocollo ESP-MESH utilizza la radio Wi-Fi della board quindi non possiamo implementare la wifi.begin() dato che l'antenna è già occupata, se l'AP a cui la rete è collegata è connesso ad internet possiamo utilizzarlo

**Funzioni di send in ESP-MESH e altro**
![[Pasted image 20261030144957.png|720]]


Esempio:
Supponiamo di voler creare una rete mesh e far comunicare le board con un server in ascolto (del server dobbiamo fornire indirizzo IP e porta e deve essere connesso allo stesso AP delle board).

![[Pasted image 20261030183516.png]]

Questo è il percorso che farà un messaggio proveniente da un nodo delle rete mesh
- ESP-MESH utilizza *UDP* come protocollo di comunicazione 

> [!info] UDP vs TCP
> In generale per il traffico IoT è molto più utilizzato UDP rispetto a TCP proprio perché è un protocollo più leggero e più veloce

Vediamo il codice:
```
// su linux apriamo un server in ascolto sulla porta 5000 tramite il comando: nc -ul 5000
// (cambiare l'indirizzo ip nel codice con il nuovo e in caso le credenziali dell'AP a cui connettersi)

#include <iot_board.h>
//#include <WiFi.h>
#include "credentials.h"
#include <sys/socket.h>
#include <IPAddress.h>

// per connettersi alla mesh gli esp32 hanno prima bisogno di connettersi ad un AP come il router di casa o l'hotspot cellulare

//const char *SSID = "ARSLab-IoT_2G";
//const char *PASS = "arslabiot";

float tempInt = temperatureRead();
String Nome;
String Cognome;

IPAddress ipPortatile;

String array[6] = {"Archimede", "Galileo", "Oppenheimer", "bello", "brutto", "cattivo"};

void onMesh(const EspMeshEvent &e) {    // evento di tipo espmesh

  switch (e.type)   // controlla il tipo di evento, se di tipo connected, disconnected, became root o message
  {
  case EspMeshEventType::Connected:
    digitalWrite(LED_GREEN, HIGH);
    break;
  case EspMeshEventType::Disconnected:
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_YELLOW, LOW);
    break;
  case EspMeshEventType::BecameRoot:
    digitalWrite(LED_YELLOW, HIGH);
    break;
  case EspMeshEventType::Message:
    Serial.printf("From " MACSTR "\n", MAC2STR(e.from));
  default:
    break;
  }

}

void setup() {

  IoTBoard::init_serial();
  IoTBoard::init_leds();
  IoTBoard::init_display();
  ipPortatile.fromString("10.21.62.233");  // diamo l'ip che in questo momento ha il portatile alla stringa ipPortatile

  uint32_t var1 = esp_random() % 3;
  uint32_t var2 = (esp_random() % 3) + 3;

  Nome = array[var1];
  Cognome = array[var2];

  EspMeshConfig configMesh;             // raggruppiamo in un unica struct tutti i parametri per poter avviare la rete mesh
  configMesh.router_ssid = SECRET_SSID; // SSID dell'AP
  configMesh.router_pass = SECRET_PASS; // Password per connettersi ad AP
  configMesh.on_event = onMesh;         // automaticamente chiamerà la funzione onMesh sopra quando si verifica un evento mesh
  configMesh.forward_ip = ipPortatile;  // forniamo l'IP del portatile con cui comunicare
  configMesh.forward_port = 5000;       // forniamo la porta su cui comunicare

  IoTBoard::init_espmesh(configMesh);   // funzione di inizializzazione espmesh a cui passiamo configMesh

  display->clearDisplay();
  display->setCursor(0,0);
  display->display();

}

void loop() {
  espmesh->update();          // update di espmesh (stesso discorso di quando lo facciamo per i pulsanti)
  tempInt = temperatureRead();

  if(IoTBoard::runEvery(3000)) {
    String messaggio = Nome + " " + Cognome + " " + String(tempInt) + "\n";
    espmesh->sendToServer(ipPortatile, 5000, messaggio.c_str(), messaggio.length());  // noi usiamo sendToServer (UDP) perche vogliamo comunicare con il PC portatile, altrimenti se volessimo comunicare con la root avremmo fatto sendToRoot (che non prende IP e porta)
    display->clearDisplay();
    display->setCursor(0,0);
    display->print(messaggio);
    display->printf("\n");
    display->display();
  }

}
```

---
##### Painless Mesh
Questa è una libreria open source per Arduino e non è basata sul protocollo ESP-MESH.
![[Pasted image 20261030184250.png]]

Painless Mesh come protocollo di rete utilizza TCP.

>[!info] Come usare Painless Mesh su platformIO
>Bisogna andare nel platform.ini e inserire questa riga:
>lib_deps = painlessmesh/painlessMesh@^1.5.7

![[Pasted image 20261030184556.png|343]]

---
Finite le reti mesh, adesso vediamo un altro protocollo di comunicazione tra dispositivi che non crea una rete mesh per comunicare, ma utilizza solo il mac address.

---
##### ESP-NOW
Questo protocollo lavora esclusivamente a livello 2, infatti a differenza di ESP-MESH *non ha bisogno di avere una root che si connette ad un AP per funzionare*. ESP-NOW però non potrà mai andare su internet perché lavora esclusivamente al livello 2 dello stack. (l'unico modo sarebbe mandare i dati ad un server e il server li gira ad un router).

I dati viaggiano quindi in un frame speciale e vengono indirizzati tramite MAC address.
ESP-NOW è un protocollo connection less, infatti prima di inviare non effettua nessun handshake o altro.

![[Pasted image 20261030192228.png|247]]

**Topologie di comunicazione**
ESP-NOW offre 3 topologie di comunicazione:
- Punto-punto
- 1 Trasmettitore $\rightarrow$ Più Ricevitori
- Più Trasmettitori $\rightarrow$ 1 Ricevitore / Gateway

![[Pasted image 20261030192553.png|513]]

**Frame ESP-NOW**
![[Pasted image 20261030192614.png]]

Come si può vedere il frame è molto piccolo e contiene solo informazioni essenziali, questo ne favorisce a velocità e anche la distanza di comunicazione dato che con un frame piccolo le frequenze possono essere più spinte e ne migliora il raggio di comunicazione.

>[!info] ACK
>Da notare che i messaggi mandati in broadcast non richiedono ACK di conferma, mente quelli mandati in unicast si.

Vediamo un codice che fa comunicare 2 schede mandando delle stringhe:
Abbiamo quindi una parte di sender e una di receiver nello stesso programma:
![[Terzo_anno/IoT/C/ESP_NOW/src/main.cpp]]


---

![[Pasted image 20261030193018.png]]

# **Wireless Personal Area Network (WPAN)**
![[Pasted image 20261112142729.png]]

Questa tipologia di reti è centrata sulla singola persona, infatti si connettono dispositivi molto vicini tra loro, il range operativo è intorno ai 10/20 metri, il protocollo sicuramente più famoso è Bluetooth, inizialmente creato per sostituire le connessioni via cavo.

---
##### Bluetooth
![[Pasted image 20261112143046.png]]

sulle nostre ESP32 possiamo arrivare fino a BLE 5 (2016)

Il Bluetooth originale (c'è differenza con BLE (low energy)), andava a creare una *piconet*, con al più 8 nodi, la rete era organizzata tramite un sistema master/slave, in cui il dispositivo master (tecnicamente client) gestiva e organizzava i dispositivi slave (tecnicamente dei server in quanto i dispositivi collegati offrivano dei servizi), se si volevano aggiungere più di 8 dispositivi, si aveva bisogno di un dispositivo slave che facesse da bridge tra 2 piconet.
In questo sistema master slave le periferiche parlano solo tramite il nodo centrale e mai tra di loro direttamente.

![[Pasted image 20261112144219.png|505]]

**Hop sequence**
*Il dispositivo centrale decide su quali frequenze radio saltare, e con quale ritmo e tutti gli altri dispositivi lo seguono:*
Il bluetooth opera nella frequenza a 2.4GHz la stessa del wifi o di zigbee e molte altre comunicazioni, è quindi una frequenza molto affollata. Per evitare interferenze e quindi perdita di dati il bluetooth non trasmette sempre nella stessa indentaci frequenza ma cambia canale centinaia di volte al secondo seguendo un determinato ordine chiamato *Hop sequence*, la hop sequence viene calcolata dal dispositivo centrale seguendo 2 parametri unici del dispositivo: il suo mac address e il suo orologio interno (clock), questo calcolo viene effettuato utilizzando questi 2 parametri per evitare che 2 piconet vicine calcolino per sbaglio la stessa hop sequence e si disturbino a vicenda (così è praticamente impossibile).

La divisione del canale cambia tra bluetooth classic e BLE, ma in generale possiamo dire che si prende la banda 2.4GHz e la si divide in tante parti (79 canali per BC con differenze di 1MHz tra ogni canale e 40 per BLE con 2MHz di differenza).

Per ora parliamo di Bluetooth classic:
![[Pasted image 20261113180630.png|450]]

Questo è lo stack a livelli implementato dal bluetooth, come vediamo una parte è eseguita dall'hardware chiamato controller, e un altra dall'host e quindi viene eseguita dal sistema operativo in uso.

Partiamo dal basso: Controller
- *radio* -> è il livello fisico vero e proprio e gestisce la trasmissione e ricezione delle onde radio sui 79 canali di divisione e usa 2 modulazioni: GFSK -> velocità base, e DPSK -> enhanced data rate
- *baseband/link controller* -> gestisce varie cose come: il formato dei pacchetti, il controllo della potenza e la ritrasmissione automatica dei pacchetti corrotti
- *LMP (Link Menager Protocol)* -> gestisce la parte di collegamento tra 2 controller come il pairing (accoppiamento), cifratura, autenticazione, scambio di ruoli ecc...


- *HCI (host controller interface)* -> è il "ponte" standardizzato (un bus praticamente) che permette di far comunicare e inviare comandi sia all'host verso il controller che viceversa.


Ora saliamo: Host
- *L2CAP (Logica Link Control and Adaptation Protocol)* -> è il livello centrale dell'host, fa multiplexing dei protocolli e gestisce il controllo del flusso
- *SPD (Service Discovery Protocol)* -> Permette ad un dispositivo di interrogarne un altro per scoprire quali servizi offre
- *RFCOMM* -> emula una porta seriale cablata
- *AVDTP/HIDP* -> protocolli di trasporto specifici rispettivamente per lo streaming audio/video e per i dispositivi di input
- *Profili* -> definiscono come combinare i livelli sottostanti per un caso d'uso reale.
  - *SPP* -> comunicazione seriale generica
  - *HFP* -> chiamate viva-voce (es. chiamata in auto)
  - *A2DP* -> streaming audio ad alta qualità (es cuffiette)
  - *HID* -> usato per tastiere mouse controller ecc...


> [!Attention] Il dongle USB che si attacca al computer ad esempio, è solo il controller, lo stack bluetooth gira sul sistema operativo

---
##### Sicurezza del Bluetooth
- **Autenticazione:** verifica l'identità del dispositivo controllando che possieda la chiave crittografica corretta per potersi connettere (l'autenticazione non riguarda l'umano)
- **Confidenzialità**: cifra il traffico dati sul canale radio per impedire che eventuali attaccanti in ascolto possano leggere le informazioni trasmesse
- **Autorizzazione**: stabilisce i permessi di accesso, ovvero decide quale dispositivo ha il diritto di utilizzare un determinato profilo e altri permessi
- **Integrità**: garantisce che i pacchetti non siano stati modificati o manomessi durante il trasferimento wireless
- **Pairing/bonding**: è il processo in due fasi con cui i dispositivi si connettono tra loro nella piconet, il pairing genera le chiavi segrete, mentre il bonding le salva in memoria permanentemente per riconnettersi in futuro senza dover ripetere la procedura 

*Evoluzione del pairing:*
Bluetooth 1.0 e 2.0
generava una chiave partendo da un pin corto e semplice e la usava per cifrare il traffico, me era molto debole, se l'attaccante sniffava lo scambio dei pin o delle chiavi poteva risalire alla cifratura

Bluetooth 2.1
Introduceva una crittografia che non permetteva ad uno sniffer di risalire alle chiavi durante il pairing,

Bluetooth 4.1
Potenzia ulteriormente lo standard utilizzato dal 2.1

---
##### BLE - Bluetooth Low Energy
Unito al bluetooth dal 2010 (v. 4.0) è un design separato dal bluetooth classico: nuova radio, nuovo link layer e stack, studiato per dispositivi che "dormono" la maggior parte del tempo (come i sensori): 
![[Pasted image 20261115111215.png]]

> [! info] Cosa è l'advertising?
> L'advertising è il meccanismo con cui un dispositivo periferico (come esp32) trasmette periodicamente in broadcast dei pacchetti per farsi scoprire dai dispositivi circostanti


**Protocollo BLE**

![[Pasted image 20261115111440.png]]
Come detto prima Bluetooth e quindi anche BLE occupano le stesse frequenze del Wi-Fi e molti altri dispositivi
BLE suddivide l'intera frequenza in 40 canali con salti di 2MHz tra ogni canale, ne sfrutta 3 per l'advertising, quindi quando dovrà farsi scoprire userà quei canali, gli altri sono invece per comunicare dati utili durante la sessione. I canali di advertising sono posti nei gap tra i canali più usati dal wifi, infatti come mostra la figura non si sovrappongono (almeno quelli).

Il BLE supporta diverse modalità di comunicazione: 1M (standard 1Mbps), 2M (alta velocità 2Mbps) e coded con correzione degli errori per coprire "lunghe" distanze.

**Vediamo lo stack BLE**
![[Pasted image 20261115112258.png|592]]

La struttura è abbastanza simile a quella del classic ma con alcune differenze, anche qui c'è una parte gestita dal controller BLE e una dall' host, gestite da un interfaccia che permette loro di comunicare.

- *PHY* -> livello fisico cioè l'antenna che deve comunicare
- *Link Layer* -> gestisce gli stati del dispositivo: advertising, scansione, connessione ecc...

- *HCI* -> è il ponte che fa comunicare il controller con l'OS

- *L2CAP (Logical Link Control and Adaptation Protocol)* -> incapsula i dati dei livelli superiori e li instrada su canali logici fissi verso il link layer
- *SMP (Security Manager Protocol)* -> Si occupa della sicurezza gestendo pairing e chiavi crittografiche
- *ATT (Attribute Protocol)* -> definisce come i dati vengono rappresentati e scambiati sotto forma di una semplice tabella di attributi
- *GATT (Generic Attribute Profile)* -> Si appoggia su ATT e dà una struttura gerarchica ai dati organizzandoli in Servizi (Services) e Caratteristiche (Characteristics)
- *GAP (Generic Access Profile)* ->  è il livello trasversale che controlla la visibilità e le interazioni tra dispositivi: definisce i ruoli (Peripheral vs Central), gestisce l'advertising per farsi scoprire, avvia le connessioni e gestisce la privacy dell'indirizzo MAC.

- *Application* -> è il codice utente che gira dentro il dispositivi

**GAP** 
Un dispositivo BLE può assumere 4 ruoli:
1) *Broadcaster* -> solo trasmissione, non connettibile, invia pacchetti di advertising in broadcast a chiunque sia in ascolto. (es. sensori di dati ambientali)
2) *Observer* -> solo ascolto non connettibile, scansiona continuamente l'etere per catturare i pacchetti dei broadcaster senza però mai connettersi. (es. un gateway fisso che raccoglie i dati di vari sensori broadcaster)
3) *Peripheral* -> annuncia e accetta connessioni, fa advertising per farsi trovare da un altro dispositivo e connettersi. (es. cuffie bluetooth)
4) *Central* -> scansiona e avvia connessioni, cerca le periferiche nei dintorni e decide quando stabilire una connessione con esse. (es. smartphone)

**Stati del link layer**
![[Pasted image 20261115114432.png|311]]

Il chip radio transita sempre da questi 5 stati, partendo sempre dallo stato di standby, il grafico è diviso in 2 parti: a sinistra lato periferica e a destra lato centrale

*Lato periferica*:
Parte da standby e entra nella fase di advertising per farsi vedere. quando riceve un pacchetto di richiesta di connessione (CONNECT_IND) va nello stato di connection assumendo il ruolo di periferica

*Lato Centrale*:
Parte da standby e entra nella fase di scanning per trovare delle periferiche, una volta trovata una periferica, passa allo stato di initiating per preparare la connessione, invia il pacchetto CONNECT_IND e appena è accettato passa allo stato di connection in cui assume il ruolo di central

Quando la connessione termina passa di nuovo allo stato di standby

---

##### Frame di advertising di BLE
Quello in figura è il frame di advertising quindi non è la struttura classica del frame di comunicazione dati.
![[Pasted image 20261115171643.png]]

- *Preamble* -> è una sequenza fissa (0xAA) usata dal ricevitore per sincronizzare la frequenza e la temporizzazione
- *Access address* -> Valore fisso (`0x8E89BED6`) che identifica il pacchetto come un messaggio di advertising (a differenza delle connessioni attive, dove questo indirizzo è casuale).
- *Header* -> contiene informazioni di controllo, tra cui il tipo di PDU e la lunghezza del payload
- *Payload* -> suddiviso in:
  - *AdvA* -> indirizzo MAC del dispositivo che sta trasmettendo (advertiser address)
  - *AdvData* -> i dati veri e propri (nome del dispositivo, servizi offerti, dati di telemetria ecc...)
  - *CRC* -> controllo sugli errori

La parte del PDU può essere di vari tipi:

| **PDU**             | **Codice**      | **Conn.** | **Scan.** | **Utilizzo principale**                                                                                                                                       |
| ------------------- | --------------- | --------- | --------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **ADV_IND**         | `0000`          | ✓         | ✓         | **Periferica standard:** il dispositivo è rilevabile, accetta richieste di connessione e può fornire dati aggiuntivi se interrogato.                          |
| **ADV_DIRECT_IND**  | `0001`          | ✓         | —         | **Riconnessione rapida:** indirizzato a un dispositivo specifico già noto per ristabilire velocemente una connessione (non trasmette _AdvData_).              |
| **ADV_NONCONN_IND** | `0010`          | —         | —         | **Beacon:** trasmette solo dati in broadcast senza accettare connessioni né risposte a scansioni (es. iBeacon, Eddystone).                                    |
| **ADV_SCAN_IND**    | `0110`          | —         | ✓         | **Broadcaster + dati extra:** non accetta connessioni, ma permette a uno scanner di richiedere ulteriori informazioni.                                        |
| **SCAN_REQ / RSP**  | `0011` / `0100` |           |           | **Scansione attiva:** se un dispositivo centrale invia una _SCAN_REQ_, l'advertiser risponde con una _SCAN_RSP_, ottenendo fino a **+31 Byte** extra di dati. |
| **CONNECT_IND**     | `0101`          |           |           | **Avvio connessione:** inviato dal dispositivo centrale per passare dallo stato di advertising a una connessione vera e propria.                              |

Questi pacchetti contenenti questi frame vengono inviati solo sui canali 37-38-39
Per gestire le collisioni si usa un intervallo compreso tra 20 e 10,24 ms a cui viene aggiunto un ritardo casuale tra 0 e 10 ms per evitare che 2 frame collidano se inviati da dispositivi diversi

**Extended Advertising (BLE 5.0):** Supera il limite storico dei 31 Byte di dati. Sui canali primari (37–39) viene inviato solo un piccolo pacchetto con un **puntatore** che rimanda a un canale dati secondario, dove è possibile trasmettere pacchetti molto più grandi: fino a **254 Byte per singola PDU**, concatenabili fino a **1650 Byte** complessivi.

*Entriamo nel dettaglio del campo AdvData*, quindi vediamo come vengono effettivamente formattati i dati dentro un pacchetto di advertising BLE:
Questa figura mostra il campo AdvData del programma IoT-Lamp
![[Pasted image 20261115173813.png]]

I dati non vengono mandati in un unico blocco sequenziale ma piuttosto si usa una lista sequenziale di strutture chiamate *AD structures*, ogni struttura (a livello di codice non si intende una struct C, è un altra cosa) è formata da 3 campi: 
- *Length* -> indica quanti byte seguono dopo questo campo
- *AD type* -> identifica il tipo di dato contenuto (nome del dispositivo, codice del servizio ecc...)
- *Data* -> il valore vero e proprio

Analizziamo i byte in figura sopra:
Da 0 a 2 (3 byte) c'è la prima AD structure.
Da 3 a 20 (18 byte) c'è la seconda, in questo caso il campo data è più grande (tutti i byte grigio chiaro)
Da 21 a 30 (10 byte) c'è la terza, che indica il nome del dispositivo

I valori dentro i rettangoli rappresentano il valore (scritto in decimale) dei byte, ad esempio nel byte 21 il campo length ha valore 9, indica quindi che seguiranno altri 9 byte, i valori del campo data sono valori ASCII e rappresentano la parola "IoT-Lamp".

---

Questa tabella riassume i valori più utilizzati nel campo *AD type* delle AD structures

| Type       | Nome                               | Esempio / Significato                                                                                                          |
| :--------- | :--------------------------------- | :----------------------------------------------------------------------------------------------------------------------------- |
| **`0x01`** | **Flags**                          | `02 01 06` — definisce modalità di scoperta e supporto Bluetooth.                                                              |
| **`0x03`** | **Complete list of 16-bit UUIDs**  | `03 03 0F 18` — usato per servizi standard Bluetooth SIG (es. `0x180F` = Battery Service, scritto `0F 18` in little-endian).   |
| **`0x07`** | **Complete list of 128-bit UUIDs** | Usato per servizi proprietari/custom (come quello della lampada).                                                              |
| **`0x09`** | **Complete Local Name**            | `"IoT-Lamp"` — il nome completo leggibile del dispositivo.                                                                     |
| **`0x16`** | **Service Data (16-bit UUID)**     | Permette di inviare un UUID a 16 bit seguito direttamente dal valore letto da un sensore (utile nei beacon senza connessione). |

**Regole pratiche**
- **Ordine Little-Endian:** Tutti i valori multi-byte (come gli UUID a 16 o 128 bit) vengono trasmessi partendo dal byte meno significativo (quindi invertiti rispetto a come li leggi nel codice).
- **Saturazione dei 31 Byte:** Sommando le tre strutture dell'esempio si ottiene $3 + 18 + 10 = \mathbf{31\text{ Byte}}$. Lo spazio è completamente pieno: se il nome della lampada fosse stato più lungo anche di un solo carattere, non ci sarebbe stato nello stesso pacchetto e sarebbe stato **troncato** (usando il tipo `0x08`, _Shortened Local Name_) oppure spostato nel pacchetto aggiuntivo di **Scan Response** (`SCAN_RSP`).

---

##### Gestione della batteria durante la connessione 
Vediamo come BLE gestisce il risparmio energetico durante una connessione attiva
![[Pasted image 20261115175607.png]]

4 parametri principali:
1) *Connection interval* -> 7.5 ms - 4 s è l'intervallo regolare con cui i due dispositivi si "danno appuntamento" (connection events) per scambiarsi pacchetti, viene configurato a scatti (step) di 1.25 ms
2) *Peripheral Latency* -> 0 - 499 indica quanti connection events consecutivi il peripheral può saltare (rimanendo quindi con la radio spenta) se non ha nuovi dati da inviare al central senza che la connessione venga considerata scaduta
3) *Supervision timeout* -> 100 ms - 32 s è il tempo massimo che può trascorrere senza ricevere alcun pacchetto valido prima che i dispositivi dichiarino la connessione persa
4) *Chi decide?* Central, è sempre il dispositivo central a stabilire i parametri della connessione, il peripheral può solo inviare una richiesta di modifica

> [!info] Latency e timeout (punti 2 e 3)
> la **Latency** dice _"per quanti turni puoi restare in silenzio per risparmiare batteria"_, mentre il **Supervision Timeout** dice _"dopo quanti secondi di silenzio totale do per scontato che tu sia sparito o spento e chiudo la connessione"_

Vediamo il diagramma della figura (Peripheral Latency = 3):
- Il *central* (rettangoli grigi) ad ogni scadenza del connection interval manda puntualmente un messaggio per capire se il peripheral vuole comunicare
- *Primo blocco (risparmio normale):* Il Peripheral si sveglia (primo rettangolo giallo), scambia i dati e poi tiene la **radio spenta (`radio off`)** saltando esattamente **3 eventi consecutivi** del Central, risvegliandosi al 4° appuntamento (secondo rettangolo giallo).
- *Secondo* *blocco* (`data ready: wakes up early`): Il Peripheral avrebbe diritto a saltare altri 3 eventi, ma dopo un solo evento interviene un evento esterno (es. la pressione di un pulsante o una lettura urgente di un sensore). Il Peripheral **non è obbligato ad aspettare** la fine dei 3 cicli di latenza: si sveglia subito al primo appuntamento utile (rettangolo rosso) per inviare immediatamente i dati, per poi tornare a dormire.

**Compromesso reale**
Scegliere piccoli intervalli permette di avere poca latenza ma frequenti sveglie per la radio che consumerà quindi più energia, intervalli lunghi, invece permettono di tener spenta la radio per più tempo e quindi consumare di meno, ma aumenta la latenza (consumi nell'ordine dei µs).

>[!warning] Vincolo di stabilità
>Per evitare che il Peripheral venga disconnesso per errore mentre sta legittimamente dormendo durante i suoi cicli di latenza, il _Supervision Timeout_ deve rispettare la formula: $$\text{timeout} > (1 + \text{latency}) \times \text{interval} \times 2$$
Il x 2 finale è messo per tollerare almeno la perdita di un pacchetto per via di interferenze (comuni nella comunicazione wireless)

---
**Struttura profilo GATT**
GATT è il modo in cui un server BLE (che sono le periferiche di solito) organizza e memorizza i dati in una tabella di attributi.
![[Pasted image 20261115184739.png]]

Ogni riga della tabella rappresenta un singolo attributo, composto da 4 elementi principali:
- *Handle* -> indirizzo a 16 bit univoco assegnato dal server GATT per indentificare ogni riga della tabella
- *Type (UUID)* -> identifica che cosa è quell'attributo (l'inizio di un servizio, la dichiarazione di una caratteristica ecc...)
- *Permissions* -> definiscono le regole di accesso al livello ATT (lettura/scrittura, crittografia o autenticazione)
- *Value* -> il dato grezzo memorizzato in quella riga

---

**Struttura protocollo ATT**
ATT è il meccanismo di messaggistica a livello applicativo con cui un **GATT client** (es. lo smartphone) e un **GATT server** (es. il dispositivo IoT) leggono, scrivono e ricevono aggiornamenti sugli attributi visti nelle slide precedenti.
![[Pasted image 20261116121340.png|434]]

Il client manda una richiesta di lettura passando il codice che indentifica il battery level, il server risponde restituendola,
Il client invia Write Request (0x12) per scrivere 01 00 nell'handle 0x0004 (abilitazione notifiche, CCCD), il server risponde con una write response che conferma l'avvenuta scrittura, ora che il CCCD è attivo, quando la batteria scende al 89%, il server invia autonomamente una Notification sull'handle 0x0003. Il client non invia alcuna risposta a livello ATT. A questo punto il client manda una write command, comando simile alla write precedente ma che non richiede risposta poi Il server invia una Indication per un dato critico che richiede garanzia di consegna applicativa e il client è obbligato a dare conferma di ricezione

![[Pasted image 20261116122506.png|345]]

---
**Connessioni multiple**
A partire dalla versione **Bluetooth 4.1**, un singolo dispositivo BLE non è più vincolato a un solo collegamento: può mantenere **più connessioni simultanee** e persino ricoprire **ruoli diversi allo stesso tempo** (ad esempio agire contemporaneamente da _Central_ verso un sensore e da _Peripheral_ verso uno smartphone).

Tuttavia, nella pratica, i dispositivi **Peripheral semplici** (come un sensore a batteria) **interrompono l'advertising non appena si connettono** a un Central, scegliendo deliberatamente di servire un solo dispositivo alla volta per semplicità e risparmio energetico.

---
##### Pairing BLE
Approfondiamo il pairing BLE ovvero il processo crittografico con cui due dispositivi già connessi stabiliscono un canale cifrato si autenticano e si scambiano le chiavi per le connessioni future.

Le 3 fasi del pairing:
1) *Feature exchange*: i 2 dispositivi si scambiano in chiaro i pacchetti di pairing request e response, negoziano le capacità di input/output e altre informazioni sulla sicurezza che possono offrire alla connessione e infine concordano la dimensione massima della chiave e quali chiavi distribuirsi al termine della procedura
2) *Key generation*: **BLE Legacy (BLE 4.0):** Usa una chiave temporanea (**TK**, _Temporary Key_ — impostata a 0, a un PIN a 6 cifre o a un segreto OOB) per derivare una **STK** (_Short Term Key_) con cui cifrare temporaneamente la connessione. **BLE Secure Connections (BLE 4.2+):** utilizza uno scambio di chiavi crittografiche (utilizzando un algoritmo di nome ECDHP P-256) per generare delle chiavi long term
3) *key distribution*: a questo punto il canale è ormai cifrato e i dispositivi si scambiano le chiavi: LTK (long term key) usata per ri-cifrare istantaneamente la connessione nelle sessioni successive senza dover rifare il pairing, IRK (identity resolving key) permette di risolvere gli indirizzi MAC casuali privati usati dal BLE per evitare il tracciamento fisico del dispositivo. (Per non far tracciare i dispositivi, questi ultimi utilizzano dei MAC address che non sono i loro reali e che cambiano ogni tot di tempo).

Il salvataggio permanente di queste chiavi nella memoria dei dispositivi prende il nome di *bonding*

**4 modelli di associazione:**
In base alle **IO capabilities** scambiate nella Fase 1 (es. se entrambi i dispositivi hanno uno schermo, se uno ha solo un tastierino o se entrambi sono privi di interfaccia come un sensore IoT), lo stack BLE sceglie automaticamente uno di questi 4 metodi per autenticarsi:
- *Just works* -> Nessuna interazione richiesta all'utente. Usato quando almeno uno dei dispositivi non ha né schermo né tastiera (es. auricolari o sensori). **Non offre protezione contro attacchi MITM** durante lo scambio iniziale.
- *Numeric comparison* -> (BLE 4.2+) Entrambi i dispositivi hanno un display; mostrano lo stesso codice a 6 cifre e l'utente deve confermare su entrambi che i numeri coincidono.
- *Passkey entry* -> Un dispositivo mostra un codice a 6 cifre sul display e l'utente lo digita sulla tastiera dell'altro dispositivo.
- *Out of band (OOB)* -> Le informazioni crittografiche vengono scambiate su un canale fisico alternativo e ravvicinato (es. avvicinando i dispositivi tramite **NFC** o scansionando un QR code).

> [!warning] Vulnerabilità
> - **Vulnerabilità di LE Legacy:** Il vecchio meccanismo di pairing introduzione con BLE 4.0 è crittograficamente compromesso. Se un attaccante intercetta (_sniffing_) i pacchetti radio durante la fase di pairing Legacy, tool noti come **crackle** (2013) riescono a forzare (_brute-force_) la chiave temporanea `TK` in pochi secondi e decifrare tutto il traffico successivo.
- Per qualsiasi applicazione moderna è quindi indispensabile abilitare **LE Secure Connections (SC)**.

![[Pasted image 20261116151435.png]]

---

Vediamo uno schema della logica di implementazione di BLE sulla nostra NANO ESP32-S3 con la libreria di unict:
![[Pasted image 20261116151706.png]]

---

Esempio di codice di una lampada IoT (il codice ha i commenti):
![[Terzo_anno/IoT/C/IoT_lamp/src/main.cpp]]

In questo codice c'è una così detta caratteristica, è l'unita fondamentale che contiene un singolo dato scambiato tra 2 dispositivi (possiamo vederla come una variabile scambiata via radio), *come si inserisce nella gerarchia BLE?*
- **Server BLE (`Garufi's-Lamp`)**: È l'intero dispositivo (l'ESP32).
- **Servizio (`SERVICE_UUID`)**: È una cartella logica che raggruppa funzioni correlate. Qui rappresenta l'intera "Lampada". Se la scheda avesse anche un sensore di temperatura, potresti creare un secondo servizio separato per quello.
- **Caratteristica (`LED_UUID`)**: È il singolo dato dentro la cartella. Nel tuo codice c'è una sola caratteristica, che contiene lo stato del LED (`"on"` oppure `"off"`). Se la lampada fosse RGB, avresti ad esempio una caratteristica per l'accensione e una seconda caratteristica per il colore.

Nel codice, `ledChar` è un oggetto che racchiude tre elementi principali:
- **UUID (`LED_UUID`)**: Il codice univoco che la identifica, così il telefono sa che scrivendo lì dentro sta comandando proprio quel LED e non qualcos'altro.
- **Valore (_Value_)**: Il dato vero e proprio memorizzato al suo interno in quel momento (nel tuo codice è una stringa di testo: `"on"` o `"off"`).
- **Proprietà (_Properties_)**: I "permessi" che stabiliscono cosa può fare il telefono con quel dato. Nel `setup()` li hai definiti così:
    - `PROPERTY_READ`: Il telefono può _leggere_ il valore attuale.
    - `PROPERTY_WRITE`: Il telefono può _sovrascrivere_ il valore (inviando `"on"` o `"off"`).
    - `PROPERTY_NOTIFY`: L'ESP32 può _avvisare automaticamente_ il telefono appena il valore cambia (utile quando premi il pulsante fisico sulla scheda).

---
