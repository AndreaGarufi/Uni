# **Introduzione**
##### Cosa è l'IoT?
E' un ecosistema dove qualcosa ha le capacità di condividere le proprie informazioni, permette quindi di connettersi e condividere informazioni in rete e anche su internet.

---
##### Come è formato un oggetto IoT?
Un oggetto completo è formato da:
![[Pasted image 20261016192725.png|628]]

Quindi: sensori,motori,controller(CPU),antenna che puo comunicare in rete

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

