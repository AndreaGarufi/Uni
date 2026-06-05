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

Il parametro ==int domain== specifica la famiglia di protocolli che vuoi usare, ne esistono molti e sono implementati nella libreria `sys/socket.h`
- Usa `PF_INET` per UDP, TCP e altri protocolli.

Per il parametro ==int type== sono definiti 5 valori, tutti iniziano con "`SOCK_`" il più comune è `SOCK_STREAM` che indica che vogliamo usare una stream socket e quindi TCP, se usassimo `SOCK_DGRAM` vogliamo usare una datagram socket e quindi UDP.

Nel parametro ==int protocol== noi andremo ad inserire sempre "0".

---

#### Il Problema del linguaggio C
Funzioni come `bind()`, `connect()` e `accept()` devono poter accettare **qualsiasi tipo di indirizzo** (IPv4, IPv6, Unix Local, ecc.). Tuttavia, il C non supporta il polimorfismo o l'ereditarietà: una funzione non può accettare tipi di dato diversi nello stesso parametro
Per risolvere questo limite, gli ingegneri di Berkeley hanno creato la **`struct sockaddr`** (definita in `<sys/socket.h>`). Che è una sorta di prototipo generale, poi esistono varie specifiche.
![[Pasted image 20260605120517.png|515]]
Usiamo la struttura specifica per IPv4: **`struct sockaddr_in`** (che ha i campi comodi `sin_port` e `sin_addr`
![[Pasted image 20260605120045.png|717]]
I campi più importanti sono sin_family, sin_addr e sin_port.
Immaginiamo di voler scrivere un client che richieda l'ora esatta ad un server, vogliamo usare TCP/IP quindi dobbiamo specificare `AF_INET` nel campo `sin_family` -> `sa.sin_family = AF_INET;`

---
#### Network byte order

Dobbiamo considerare anche il problema dell'endianess, alcuni computer usano il little altri il big endian quindi i dati devono essere convertiti seguendo il network byte order prima di essere spediti. Oppure possono essere mandati come stringa perché le stringhe vengono sempre codificate in ASCII quindi non sono interessate dall'endianess.

- *Seguire il network byte order*
  - **`h`** = **Host** (il tuo computer)
  - **`to`** = **to** (verso)
  - **`n`** = **Network** (la rete Internet)
  - **`s` / `l`** = **Short** (16 bit) / **Long** (32 bit)

`Htonl` si usa per convertire gli indirizzi IPv4 (essendo numeri da 32 bit)
`Htons` si usa per convertire le porte (essendo numeri da 16 bit)

- *Inviare una stringa*
  - si usa `inet_addr` -> `sa.sin_addr.s_addr = inet_addr("193.204.114.105");` 

---

#### Funzione connect()
Quando un client ha creato la socket deve connettersi con una macchina remota su una porta specifica. Usa connect().

`int connect(int s, const struct sockaddr *name, socklen_t namelen);`

Il parametro ==int s== è il valore di ritorno della funzione socket()
Il parametro ==const struct sockaddr * name== è il puntatore alla struttura sockaddr
Il parametro ==socklen_t namelen== riguarda il numero di byte all'interno di sockaddr (il secondo parametro)

*Se la connect() ha avuto successo ritorna 0 altrimenti ritorna -1* e salva il valore di errore all'interno di *errno*

---

#### Socket lato server e funzione bind()
Il server solitamente aspetta che qualche client lo contatti, ci sono 65535 porte ma di solito un server processa le richieste che arrivano solo su una di queste, usiamo le socket per dire a quale porta vogliamo essere contattati. Per questo si usa la funzione bind().

`int bind(int s, const struct sockaddr *addr, socklen_t addrlen);`

Il parametro ==int s== è il valore di ritorno della funzione socket()
Il parametro ==const struct sockaddr * addr== è il puntatore alla struttura sockaddr
Il parametro ==socklen_t namelen== riguarda il numero di byte all'interno di sockaddr (il secondo parametro)
*Se la bind() ha avuto successo ritorna 0 altrimenti ritorna -1* 

La funzione `bind()` serve quindi a **legare** (assegnare) un indirizzo IP e un numero di porta al socket che hai creato.

Oltre a specificare la porta all'interno dell'indirizzo (`addr`), il server può includere il proprio indirizzo IP. Tuttavia, può semplicemente utilizzare la costante simbolica **`INADDR_ANY`** per indicare che servirà tutte le richieste dirette alla porta specificata, indipendentemente da quale sia il suo indirizzo IP. Questo simbolo, insieme a diversi altri simili, è dichiarato nel file `<netinet/in.h>`.

>[!example] 
>Se nel codice inserisci un IP specifico, il tuo server accetterà connessioni **solo** da quella specifica rete.
Usando invece **`INADDR_ANY`**, dici al sistema operativo: _"Non mi importa da quale scheda di rete arrivi la richiesta (Wi-Fi, cavo Ethernet o locale), se qualcuno bussa alla porta 8080, tu passami la connessione"_. È il modo standard per rendere un server accessibile da ovunque.

#### Funzione listen()
Il server garantisce l'ascolto su quella porta tramite la funzione `listen`. Più precisamente **Cambia lo stato del socket:** Dice al sistema operativo che quel socket non è più un socket normale (attivo, che avvia connessioni), ma diventa un socket **passivo** (che può solo ricevere chiamate).

`int listen(int s, int backlog);`

Il parametro ==int s== è il valore di ritorno della funzione socket()
Il parametro ==backlog== è un numero interno che definisce la lunghezza massima della coda delle connessioni in attesa

#### Funzione accept()
Il server accetta la connessione tramite la funzione accept().
Nota che questa volta `addrlen` è un **puntatore**. Questo è necessario perché in questo caso è la socket che compila `addr`, ovvero la struttura `sockaddr_in`. Il valore di ritorno è un intero. Infatti, la `accept` restituisce una **nuova socket**. Userai questa nuova socket per comunicare con il client. Cosa succede alla vecchia socket? Continua a rimanere in ascolto per ulteriori richieste (ricordi la variabile `backlog` che abbiamo passato alla `listen()`  finché non la chiudiamo.

`int accept(int s, struct sockaddr *addr, socklen_t *addrlen);`

Il parametro ==int s== è il valore di ritorno della funzione socket().
Il parametro ==const struct sockaddr * addr== è il puntatore alla struttura sockaddr.
Il parametro ==socklen_t * addrlen== è un **puntatore a un intero** che rappresenta la dimensione della struttura dell'indirizzo.
- **Come funziona:** Viene passato "per riferimento" (usando l'operatore `&`, es. `&addr_len`).
- **A cosa serve:** È un parametro di _Input/Output_ (chiamato anche _Value-Result_).
    - **In Input:** Dice al sistema operativo quanto spazio massimo ha a disposizione nella struttura `addr` che gli stiamo passando.
    - **In Output:** Poiché è la `accept()` che compila la struttura con i dati del client che si è appena connesso, prima di terminare la funzione **sovrascrive** questa variabile inserendo il numero esatto di byte che ha realmente utilizzato per scrivere l'indirizzo del client

Se la funzione accept() ritorna un numero intero $\ge 0$ (Successo): Rappresenta un **nuovo File Descriptor** (ovvero una nuova socket di connessione). Altrimenti ritorna -1


