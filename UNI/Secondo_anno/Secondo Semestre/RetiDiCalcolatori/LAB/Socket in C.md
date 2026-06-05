Per scambiare messaggi tra processi (i nostri software) potremmo usare un file, ad esempio un file di testo, questa è una soluzione che tecnicamente può funzionare ma che porta a enormi problemi di accesso concorrente e dipendenze. Allora potremmo usare dei protocolli di rete per scambiare messaggi tra processi in modo da evitare queste problematiche, questo sono le *socket*.
*Ci sono 2 tipologie principali di socket*
- Stream socket
  Queste socket sono usate per comunicare come uno stream di byte in cui possiamo scrivere o leggere da uno stream nello stesso ordine in cui sono stati mandati. La frammentazione dei dati nello stream o la gestione di pacchetti persi saranno gestite direttamente dalla socket in base al protocollo utilizzato. *Le stream socket solitamente usano TCP.*
- Datagram socket
  Se non abbiamo bisogno di tutti i servizi offerti dalle stream socket (gestione dei pacchetti persi, congestion control, riordinamento ecc...) perché magari abbiamo bisogno di velocità allora possiamo usare le datagram socket, queste socket inviano dati senza le funzionalità delle stream socket. *Le datagram socket solitamente utilizzano UDP.*
  
![[Pasted image 20260605113248.png|580]]

*Le socket sono gestite tramite uno standard chiamato Berkeley (BSD socket)* e questo standard sostanzialmente è una libreria scritta in C. Ogni altro linguaggio di programmazione si basa su questa libreria applicando delle traduzioni opportune per farla funzionare.

Questo è il funzionamento teorico di una socket:
![[Pasted image 20260605113846.png|717]]

---

#### Funzione Socket()
Solitamente si comunica tra client e server e la funzione comune tra i 2 è *socket()*
- `int socket(int domain, int type, int protocol);`

La funzione `socket()` restituisce un **numero intero**, esattamente come fa la funzione `open()` quando si apre un file di testo sul disco.
- Questo numero intero è chiamato **File Descriptor (FD)**.
- Rappresenta l'indice (un "ticket") all'interno di una tabella interna del Sistema Operativo chiamata _Tabella dei File Aperti_.
- È possibile comunicare in rete usando le funzioni standard di lettura e scrittura dei file di sistema (`read()` e `write()`), invece di quelle specifiche per le socket (`recv()` e `send()`)

Il parametro **int domain** specifica la famiglia di protocolli che vuoi usare, ne esistono molti e sono implementati nella libreria `sys/socket.h`
- Usa `PF_INET` per UDP, TCP e altri protocolli.

Per il parametro **int type** sono definiti 5 valori, tutti iniziano con "`SOCK_`" il più comune è `SOCK_STREAM` che indica che vogliamo usare una stream socket e quindi TCP, se usassimo `SOCK_DGRAM` vogliamo usare una datagram socket e quindi UDP.

Nel parametro **int protocol** noi andremo ad inserire sempre "0".

---

#### Il Problema del linguaggio C
Funzioni come `bind()`, `connect()` e `accept()` devono poter accettare **qualsiasi tipo di indirizzo** (IPv4, IPv6, Unix Local, ecc.). Tuttavia, il C non supporta il polimorfismo o l'ereditarietà: una funzione non può accettare tipi di dato diversi nello stesso parametro
Per risolvere questo limite, gli ingegneri di Berkeley hanno creato la **`struct sockaddr`** (definita in `<sys/socket.h>`). Che è una sorta di prototipo generale, poi esistono varie specifiche.
![[Pasted image 20260605120517.png|515]]
Usiamo la struttura specifica per IPv4: **`struct sockaddr_in`** (che ha i campi comodi `sin_port` e `sin_addr`
![[Pasted image 20260605120045.png|717]]
I campi più importanti sono sin_family, sin_addr e sin_port.
Immaginiamo di voler scrivere un client che richieda l'ora esatta ad un server, vogliamo usare TCP/IP quindi dobbiamo specificare `AF_INET` nel campo `sin_family` -> `sa.sin_family = AF_INET;`

