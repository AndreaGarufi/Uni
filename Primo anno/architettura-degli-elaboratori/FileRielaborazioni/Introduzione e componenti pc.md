
Un'**algoritmo** è un insieme finito di istruzioni usate per la risoluzione di un certo lavoro. Quest'ultimo molte volte viene definito come una particolare funzione parziale di una [[#macchina di Turing]] (Alan Turing, matematico britannico) oppure come un programma di una [[#macchina di Von Neumann]] (matematico statunitense).

Le funzioni di base di un'elaboratore possono essere riassunte in 4 macro aree:
- memorizzazione dei dati
- elaborazione dei dati
- trasferimento dei dati
- controllo.

Un'esempio di elaboratore è il **computer**, il computer è una macchina che computa ovvero che esegue un certo algoritmo (ovviamente scritto in modo che la macchina stessa lo possa interpretare). Esistono vari tipi di computer: 
- Laptop
- Server
- Desktop
- Tablet/Smartphone

Un qualsiasi computer moderno segue la seguente architettura:
# <font color="#000000">Macchina di Von Neumann</font>

![[Pasted image 20241004212308.png]]
Questo tipo di architettura viene chiamata Macchina di Von Neuman (questa è l'architettura alla quale fa riferimento la definizione di algoritmo sopracitata). Di seguito una descrizione di tutti i componenti:
- La ==**CPU**, o **Central Processing Unit**==, è l'unità centrale di elaborazione di un computer. È il componente principale che esegue le istruzioni dei programmi, gestisce le operazioni logiche e aritmetiche, e coordina il funzionamento delle altre parti del sistema. Come memoria di lavoro usa i registri e la cache. La sua velocita si misura in numero di cicli al secondo (MHz o GHz). La CPU è formata da 4 parti fondamentali:
	- il **program counter**: una locazione di memoria che contiene l'indirizzo dell'istruzione da eseguire
	- il **registro delle istruzioni**: una locazione di memoria contenente l'istruzione da eseguire
	- **ALU (Arithmetic logic unit)**: un sistema che esegue le operazioni aritmetiche e logiche
	- **CU (Control Unit)**: Il sistema di controllo gestisce il flusso di esecuzione delle istruzioni. Fa sì che ogni parte del processore faccia il suo lavoro nel momento giusto, attraverso una serie di cambiamenti di stato. 
- La ==**memoria**==, è un deposito di dati e di istruzioni da eseguire, ne esistono di 3 tipi:
	- **ROM**, o **Read Only Memory**, è una memoria di sola lettura non volatile dove si trovano tutte varie informazioni come le istruzioni usate per l'avvio del pc, o dei parametri necessari per il corretto funzionamento del dispositivo
	- **RAM**, o **Random Access Memory**, è una memoria volatile utilizzata per immagazzinare tutte quelle istruzioni che poi vengono eseguite dal processore
	- La **cache** è una memoria ad alta velocità che si trova all'interno o vicino alla CPU e viene utilizzata per immagazzinare temporaneamente i dati e le istruzioni più frequentemente utilizzate. La sua funzione principale è quella di ridurre i tempi di accesso alla RAM migliorando così le prestazioni del sistema e quindi riducendo il [[#Bottleneck]] tra CPU e RAM.
	- 
- ==**Dispositivi di input**==: come un tastiera ed un mouse
- ==**Dispositivi di output**==: come un monitor o una stampante
- ==**Memoria di massa**==: un tipo di memoria non volatile che viene usata per immagazzinare grandi file, e ovviamente molto più lenta di qualsiasi altro tipo di memoria sopracitata. La memoria di massa è fondamentale per garantire l'archiviazione stabile di software, documenti, immagini e altri dati digitali, rendendoli accessibili nel tempo. Degli esempi sono:

	- **Hard disk drive (HDD)**: basato su dischi magnetici rotanti.
	- **Solid State Drive (SSD)**: usa chip di memoria flash, più veloce e resistente rispetto agli HDD.
- ==**BUS**==, tutte queste componenti comunicano tra di loro attraverso i bus. I principali tipi di bus vengono usati per inviare dati o segnali di controllo

La macchina di von Neumann viene definita logicamente come una terna, ovvero un'insieme di 3 elementi:
- **N** = {0,1,2,3} ovvero l'insieme dei numeri naturali (l'alfabeto della macchina)
- **IS** = {ZERO, INC, SOM, SOT, MOL, DIV, UGUALE, MINORE, SALCOND, ALT} è l’Instruction Set set ovvero un'insieme di istruzioni che la macchina può usare
- **P** =  {I0, I1, I2, I3, … , I|P| – 1} è una sequenza finita di istruzioni prese dall'insieme IS, questo insieme si chiama programma
Come possiamo ben notare un programma eseguibile dalla macchina von Neumann consiste in una lista di istruzioni che devono essere eseguite dal processore. Ogni istruzione viene sottoposta al ciclo macchina ovvero una serie di passaggi impiegati per l'esecuzione dell'istruzione stessa, di seguito i passaggi appena citati:

1. **Legge il contenuto del program counter**: ovvero l'indirizzo della prossima istruzione da eseguire.

2. **Caricamento nel registro delle istruzioni (fetch)**: Il processore va a recuperare l'istruzione dalla memoria, utilizzando l'indirizzo letto da program counter. Questa istruzione viene quindi inserita nel registro delle istruzioni.

3. **Decodifica dell'istruzione**: Una volta che l'istruzione è stata caricata, il processore la decodifica, per capire di che tipo di istruzione si tratta

4. **Invio all'ALU**: Se l'istruzione richiede un'operazione aritmetica o logica, la unità logico-aritmetica (ALU) riceve l'istruzione e i dati necessari per eseguire l'operazione.

5. **Accesso ai dati**: Se l'istruzione da eseguire richiede dei dati la control unit li recupera dalla memoria. Se l'istruzione è del tipo SOM(M1, M2) ad esempio, significa che M1 e M2 sono indirizzi in memoria da cui vengono presi i dati. 

6. **Esecuzione**: L'ALU effettua l'operazione richiesta (ad esempio, somma o confronto) utilizzando i dati forniti.

7. **Memorizzazione del risultato**: Una volta ottenuto il risultato, viene registrato nella locazione di memoria specificata dall'istruzione.

8. **Aggiornamento del contatore**: Il program counter viene incrementato per puntare all'istruzione successiva.

9. **Ripetizione del ciclo**: Questo ciclo continua fino a quando non viene incontrata un'istruzione speciale che ferma o altera l'esecuzione, come un'istruzione ALT o un salto condizionato che modifica il flusso del programma. 

Il modello di elaboratore dalla quale Von Neumann prese spunto fu:
# <font color="#000000">Macchina di Turing</font>

Una **macchina di Turing (o MdT)**  è stata inventata da Alan Turing nel 1936. Questo modello è fondamentale nella teoria della computabilità e fornisce una rappresentazione astratta di come funzionano i calcolatori. Formalmente viene definita in questo modo:
![[Pasted image 20241005110025.png  |  center]]
Di seguito una descrizione di tutti i componenti:
- **Nastro:** Un'unità di memoria esterna infinita, suddivisa in celle, ogni cella contiene un simbolo oppure è vuota.
- **Testina di lettura/scrittura (TLS) :** Un dispositivo che interagisce direttamente con il nastro.
- **Unità di memoria interna:** Una struttura che memorizza lo stato interno della macchina.
- **Unità di calcolo:** Un componente che esegue le operazioni di base.
- **Unità di controllo:** Il "cervello" della macchina, che coordina le altre unità.
- **Unità di logica:** Un componente che si occupa delle operazioni logiche.
Il comportamento di una MdT può essere programmata definendo un'insieme di regole, o quintuple di questo tipo: 
- ==(stato-interno-corrente, simbolo-letto, prossimo-stato-interno, simbolo-scritto, direzione)== 
di seguito degli esempi:
- (0, A, 1, B, -) se la macchina si trova nello stato 0 e legge il simbolo A passa allo stato 1 e scrive sul nastro B e sta ferma
- (1, B, 0, A, >) se si trova nello stato 1 e legge il simbolo B passa allo stato 0 e scrive sul nastro A e si muove di una posizione a destra

È importante sottolineare come l'attenzione di Turing sia rivolta al processo di calcolo, **indipendentemente da come esso avviene fisicamente**. Una M.d.T è un dispositivo ideale, cioè indipendente da ogni sua possibile realizzazione fisica. 

Una funzione (**parziale**)si dice **Tuing-computabile** se almeno una MdT è in grado di computarla con un numero finito di passi. 

**FUNZIONE PARZIALE**
Una funzione parziale è una funzione che dato un input non necessariamente restituirà un output definito, infatti potrebbe non terminare (loop) o non essere definita
Le funzioni parziali sono importanti perché rappresentano la **computabilità reale** ovvero non tutte le funzioni che possiamo eseguire sono calcolabili in tempo finito.
Quindi le funzioni parziali sono in grado di definire sia le funzioni che terminano con successo (totali) sia quelle che non lo fanno.
##### Condizioni di finitezza 
Una MdT per essere tale deve rispettare le condizioni di finitezza che sono:
- il **numero di simboli** che usa deve essere fissato e **finito**
- il **numero di caselle** del nastro **osservabili in una volta è finito**
- è possibile **ricordare solo un numero finito di stadi precedenti**
- le operazioni che può compiere sono:
	1. Cambiare il contenuto di alcune caselle osservate
	2. Cambiare le caselle osservate
	3. Cambiare il proprio stato
	4. Osservare nuove caselle che si trovano ad una distanza prefissata dalla casella osservata
##### Macchina di Turing universale
Se supponiamo di avere una macchina di Turing senza limiti di spazio, di tempo e che non possa commettere errori quest'ultima sarà in grado di calcolare tutte le funzioni calcolabili in ogni singola macchina di Turing, questa macchina la chiamiamo **Macchina di Turing Universale (MdTU)**, inoltre deve rispettare sia la condizione di finitezza sopracitata ma anche la condizione di determinatezza spiegata di seguito
##### Condizione di determinatezza 
le azioni di una MdTU devono dipendere solo dal simbolo contenuto nella casella osservata in quell'instante e dallo "Stato mentale" corrente, cioè da quello che ricorda dei calcoli precedenti

Da tutto questo Turing formula la seguente Tesi: "*ogni funzione parziale calcolabile con un algoritmo è una funzione parziale calcolabile da una macchina di Turing.*"
(appunto per questo all'inizio si parla dell'algoritmo come una funzione parziale della macchina di Turing). Questa tesi ci dice che **ogni funzione calcolabile da un algoritmo può essere calcolata da una macchina di Turing**, poiché ogni algoritmo può essere descritto in termini di un insieme finito di regole.


# <font color="#000000">MEMORIA</font>
![[Pasted image 20241012121316.png|600]]

• **La memoria, detta normalmente memoria principale (per distinguerla da altri tipi di memorie dette secondarie), è un contenitore di celle ordinato.**

• Nelle celle di memoria vengono immesse o prelevate le istruzioni del software e i dati di input e di output. Ogni cella è ampia un byte e ogni cella possiede un indirizzo (address).

• Gli indirizzi delle celle partono da zero e l'indirizzo dell'ultima cella coincide con il numero totale di celle della memoria (meno uno, dato che gli indirizzi partono da zero).
 l'insieme di tutte le celle di una memoria è detto spazio degli indirizzi o spazio di indirizzamento della memoria.
 
(lo spazio di indirizzamento dipende dall' ABUS vedi capitolo BUS)

**La RAM (Random Access Memory) per non perdere il suo contenuto quando il pc è acceso, viene "refreshata" con un segnale elettrico** con frequenza costante.

**le celle di memoria sono dei micro condensatori infatti si chiama DRAM (Dynamic RAM)**

Per la fase di **BOOTSTRAP** (avvio) il computer ha bisogno di caricare dei dati per il corretto avviamento e questi dati sono contenuti nel **BIOS** che è una **ROM** (Read Only Memory) ovvero una memoria di sola lettura che non perde i dati allo spegnimento del computer. I programmi contenuti nelle ROM sono detti Firmware.

Esiste una tipologia di RAM **più veloce** della DRAM (questa è la RAM normale,8,16,32 GB ecc..) **chiamata SRAM (Static RAM)** che è molto più veloce ma anche più costosa, i micro condensatori vengono sostituiti dai dai micro flip-flop. **Queste sono le MEMORIE CACHE**

![[Pasted image 20241012123225.png|600]]

											(La NOR FLASH è la ROM del BIOS)






# <font color="#000000">BUS</font>
 **Il bus è l'unità di interconnessione tra i moduli del modello di von Neumann. **
 
 Esso si presenta come un fascio ordinato di linee, ognuna delle quali **può assumere il significato di un bit**, cioè di un valore binario.
 
 Si dice che i moduli processore, memoria e input/output si «affacciano» sul bus, ovvero essendovi collegati, possono impostare, prelevare o modificare i valori presenti sulle linee che lo compongono.
![[Pasted image 20241012101734.png|300]]

molta dell'attività di un calcolatore si basa sul trasferimento dati attraverso i vari componenti  attraverso i bus, **questo modello è di tipo master/slave** (processore - master , memoria, I/O  - slave)

Un operazione che **trasporta bit dalla CPU alla memoria (o I/O) si dice di WRITE** 
mentre se i bit vanno **verso la CPU** si dice che è un operazione di **READ** 


il BUS è scomponibile in **3 sottoinsiemi (LINEE)** -AddressBUS, DataBUS, ControlBUS
1. CBUS ha una linea che specifica(controlla) la direzione (CPU--I/O oppure I/O CPU) 
   ha un altra linea per specificare il verso del trasferimento (WRITE/READ) 
2. DBUS da qui passano i dati da trasferire.
3. ABUS : viene usato dalla CPU per trasmettere gli indirizzi di memoria ad altri componenti (RAM)

le **CPU vanno a diversi GHz mentre i bus al massimo a alcune centinaia di MHz** (bottleneck)
- la linea **WAIT** del CBUS indica il trasferimento completato (1) o in corso (0), infatti il trasferimento dei dati da CPU a memoria è più lento dei tempi di operazione della CPU.

| LINEA CBUS | VALORE | SIGNIFICATO              |
| ---------- | ------ | ------------------------ |
| WAIT       | 1      | trasferimento completato |
| WAIT       | 0      | trasferimento in corso   |
| I/O-MEM    | 1      | trasferimento CPU-I/O    |
| I/O-MEM    | 0      | trasferimento CPU-MEM    |
| READ/WRITE | 1      | lettura                  |
| READ/WRITE | 0      | scrittura                |

La quantità di linee di ABUS e DBUS dipendono dall'architettura della **CPU (64 bit 64 linee, 32 bit 32 linee)**
la **dimensione dell' ABUS specifica la quantità di memoria raggiungibile dai programmi.** 2 elevato al numero di linee dell' ABUS quindi un' architettura a 32 bit = $2^{32}$ indirizzi (4 GB di RAM al massimo ciascun processo) 64 bit = $2^{64}$ 

la dimensione del **DBUS** rappresenta il grado di parallelismo del processore ovvero la massima quantità di dati che è in grado di elaborare in un solo trasferimento di bus

**(**domanda d' esame)** se ho 4 processi e un architettura a 32 bit (32 linee di ABUS) ognuno dei 4 processi può indirizzare 4 gb di RAM? 
si 4 gb massimo (2^32) ogni processo

Il chipset è il termine complessivo per descrivere tutte le linee e i bus di sistema. Il chipset è formato da northBridge (dedicato alla connessione memoria-CPU)e southBridge (dedicato alla connessione CPU-I/O)


# Ulteriori informazioni:

###### <mark style="background: #D2B3FFA6;">Bottleneck</mark>

La CPU è progettata per operare a velocità estremamente elevate, elaborando milioni di istruzioni al secondo. Tuttavia, la RAM, sebbene veloce, ha tempi di accesso più lunghi quando la CPU richiede dati o istruzioni deve attendere che questi vengano recuperati dalla RAM. Questo processo di attesa genera un rallentamento, poiché la CPU rimane inattiva in attesa dei dati necessari per continuare l'elaborazione. Per mitigare questo problema, le CPU fanno uso della cache, una memoria più veloce e più vicina al processore, dove vengono conservati i dati e le istruzioni più frequentemente utilizzati. Tuttavia, anche con l'uso della cache, il bottleneck rimane una preoccupazione, specialmente in scenari di carico elevato o quando vengono eseguiti più processi contemporaneamente. In questi casi, se la RAM non è in grado di tenere il passo con le richieste della CPU, si crea un rallentamento significativo, influenzando negativamente l'efficienza complessiva del sistema. 

###### <mark style="background: #D2B3FFA6;">Il test di Turing</mark>
Turing cercò di rispondere alla domanda "can machines think?", per fare ciò formulo quello che viene chiamato test di Turing ovvero un giudice umano comunica con due interlocutori nascosti: uno è un essere umano, e l'altro è una macchina. Se il giudice non riesce a distinguere chi è la macchina e chi è l'umano basandosi solo sulle risposte fornite, allora si dice che la macchina ha **superato il test** e può essere considerata "intelligente". Fino a qualche mese fa nessuno era riuscito a superarlo tranne ChatGPT-4 di recente

###### <mark style="background: #D2B3FFA6;">Processi sincroni / a-sincroni, latenza</mark>
- **La latenza** è il tempo che il dato impiega a passare per il bus a seguito del comando READ, 
	Il comando viene lanciato (READ) - il dato pasa per il bus - il dato viene effettivamente letto dalla CPU.

- **I processi sincroni** hanno bisogno di essere "sincronizzati" perché ad esempio il primo è propedeutico per il secondo (quindi il secondo non può iniziare se ancora il primo non ha finito) questi processi vengono eseguiti dalla CPU che esegue sia processi sincroni che a-sincroni.
- **I processi a-sincroni** non hanno bisogno di essere sincronizzati perché "lavorano da soli" infatti le GPU hanno moltissimi core rispetto alle CPU proprio perché loro devono svolgere solo processi a-sincroni
(lo schermo è formato da delle matrici (1920x1080 è la matrice del full HD, quindi la risoluzione indica anche quanto è grande la matrice dello schermo) quindi ogni processo si occupa di una sottomatrice e svolge il suo compito dentro un core della scheda video, alla fine la scheda video mette insieme tutti i risultati di questi processi per avere una matrice completa e renderizzare lo schermo correttamente. (lo schermo a colori è dato da 3 matrici RED,GREEN,BLUE [RGB] ))

###### <mark style="background: #D2B3FFA6;">Memorie</mark>

- L' ultima tecnologia di **DRAM** (fino al 12/10/24) è la DDR5 uscita nel 2020.
- Le **ROM** anche se hanno l'acronimo Read Only Memory attraverso procedure speciali si possono effettuare operazioni di scrittura.






