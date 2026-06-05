**Andrea Garufi 2025/2026 (Appunti misti)**

# Sistemi operativi
## **INTRODUZIONE**
Ci saranno una serie di concetti base e non molto approfonditi, andremo ad approfondirli successivamente.
**Definizioni**
- Un moderno calcolatore è formato da: uno o più processori, memoria centrale, dischi, stampanti e altre periferiche I/O. Per gestire tutte le componenti hardware serve uno strato intermedio software: il **Sistema Operativo.**

- I processi sono dei programmi che una volta mandati in esecuzione diventano un'entità attiva. Nei sistemi multiprogrammati troviamo più processi. 
  *-Programma: entità statica*
  *-Processo: entità dinamica*
  *-Multiprogrammazione: capacità del sistema operativo di gestire più processi.*

- Qualunque elaboratore che ha delle risorse da gestire ha un sistema operativo, anche se non interagiamo direttamente con esso ma con delle applicazioni.

- Il SO può essere visto da due punti di vista. Punto di vista basso (hardware) quindi il SO è un gestore di risorse; punto di vista alto(utente) chi utilizza un dispositivo che in realtà interagisce con le applicazioni.

- I processi lavorano in spazi separati tra di loro, il Sistema Operativo agisce come un'entità separata e superiore che arbitra l'accesso alle risorse.

#### Modalità di esecuzione (User-Kernel)
![[Pasted image 20260525170145.png|428]]

Abbiamo 2 modalità di esecuzione:
1. **Kernel Mode** (Supervisor Mode): I programmi che girano in questa modalità (quali OS, driver e ulteriori software molto specifici), possono accedere alle risorse hardware senza particolari vincoli. E' meno restrittiva, ma da grandi poteri derivano grandi responsabilità: un crash in modalità Kernel può far fallire l’intero sistema.
   Questi sono i suoi poteri (e doveri):
   - *Manipolazione diretta della memoria* (allocazione, protezione, mappatura degli indirizzi fisici)
   - *Accesso diretto all'hardware e ai registri di controllo*
   - *Gestione delle interruzioni e delle eccezioni*
   - *Configurazione della MMU* (Memory Management Unit)
   - *Efficienza del sistema*: consente di gestire più richieste contemporaneamente senza colli di bottiglia.
   - *Isolamento dei conflitti*: processi che competono per le stesse risorse vengono arbitrati dal kernel, evitando stati inconsistenti o deadlock.

Il kernel è il cuore del SO è viene caricato all'avvio del computer in RAM


2. **User Mode**: È una modalità *non privilegiata*. (non può riprogrammare il controller della memoria o accedere direttamente al disco). E' la modalità con cui vengono eseguiti tutti i software sopra il sistema operativo. Questa modalità offre privilegi limitati al programma, il quale potrà accedere esclusivamente alla memoria ad esso dedicata, e non permette l’accesso a risorse hardware. A tale scopo, tramite delle *chiamate di sistema (system call) e il meccanismo di trap*, un programma può chiedere l’intervento dell’sistema operativo, che eseguirà istruzioni in modalità Kernel. Un crash in modalità utente non mette a rischio il resto del sistema.

È importante non cadere nell'errore di credere che _tutto_ il codice eseguito in modalità utente sia completamente estraneo al kernel.

---

#### System call
*Una system call è il meccanismo fondamentale tramite cui un programma in esecuzione (user mode) richiede un servizio al kernel del sistema operativo, che opera con privilegi elevati (kernel mode).*

![[Pasted image 20260527123500.png|555]]
Questo avviene grazie al meccanismo di **TRAP**: quando avviene una system call la CPU passa dalla user mode alla kernel mode, quando la system call è finita attraverso al RETURN la CPU torna in user mode

I programmi normali (excel, word, chrome) girano in user mode, quindi non possono accedere direttamente all'hardware o a risorse sensibili, per questo fanno le system call

Una system call avviene quando ad esempio un processo deve accedere ad un file, quando si alloca memoria o quando si deve accedere all'hardware

Il passaggio da modalità utente a modalità kernel e ritorno avviene in maniera trasparente per l'utente finale (l'utente non se ne accorge), ma è un meccanismo fondamentale per garantire la **sicurezza e l'integrità del sistema**.

---

#### Il concetto di astrazione
Il sistema operativo astrae l’interfaccia, usa l’hardware e offre ai programmi applicativi una propria interfaccia che sia ad alto livello, più comoda da gestire.

Uno dei concetti chiave nell'architettura dei sistemi operativi è quello di **astrazione**. Il kernel opera a un livello di programmazione molto basso, a stretto contatto con l'hardware. Operazioni che sembrano banali nascondono in realtà una complessità considerevole.

L'obiettivo dell'astrazione non è **nasconderle**. Il kernel espone all'utente (e ai programmi applicativi) un'interfaccia semplificata — un insieme di istruzioni ad alto livello — che permette di eseguire operazioni complesse senza dover conoscere i dettagli implementativi dell'hardware sottostante. Questo rende il sistema più usabile e portabile.

---

#### CPU e memorie virtuali
Posso avere una o più CPU, nel caso più semplice ne abbiamo una sola, sappiamo che si possono eseguire più processi contemporaneamente e questo può essere visto in tanti modi, ma anche come un’astrazione in cui il Sistema Operativo crea delle **CPU** **VIRTUALI**. Fa credere ad ogni processo di avere una propria CPU ma in realtà sta gestendo le $n$ CPU virtuali con l’unica fisica che ha. Questo viene chiamato **time sharing.**

La **Memoria Virtuale** è un'astrazione fondamentale fornita dal Sistema Operativo che permette a ogni processo di operare in un ambiente di lavoro isolato e apparentemente illimitato.
![[Pasted image 20260525170242.png|439]]

- **Approccio Bottom-Up:** Il SO è un **Resource Manager**. Gestisce la complessità dei segnali elettrici e dei registri hardware, offrendo in cambio un'interfaccia pulita (File, Processi).
- Gestire una risorsa significa arbitrare i conflitti(più processi potrebbero voler accedere ad uno stesso file), fornirne un utilizzo ordinato e coordinato.

---

#### Multiplexing
Un sistema operativo moderno deve essere in grado di gestire:
- **Più programmi in esecuzione contemporanea 
- **Più utenti connessi simultaneamente**

Per farlo in maniera ordinata e controllata, si ricorre al concetto di **Multiplexing**.
Strategie di gestione

1. *MULTIPLEXING NEL TEMPO*: Si usa per risorse che non possono essere divise fisicamente (CPU). Passare da un processo P1 , all’altro P2, significa che il SO deve fare sia un lavoro di salvataggio (i dati dell’unica CPU fisica che ho) che di ripristino(ricaricare gli stessi valori lasciati nei registri della CPU, sostituire P2 con P1).

Il multiplexing nel tempo permette di creare CPU virtuali.

1. *MULTIPLEXING NELLO SPAZIO*: Si usa per risorse che possono essere spezzettate (RAM). Rientra in questo caso tutto quello che riguarda gli spazi di memoria da gestire. Diversi processi occupano contemporaneamente porzioni differenti della risorsa, il Sistema Operativo divide la RAM in blocchi e li assegna ai processi dove c'è spazio, garantendo l'**isolamento**.

Il multiplexing nello spazio permette di creare l’astrazione della memoria virtuale.

> [!info] **Perché il multiplexing è fondamentale?**
Senza multiplexing, ogni processo dovrebbe attendere che tutti gli altri terminino prima di poter ottenere l'uso della CPU o della memoria. I sistemi moderni sarebbero di fatto inutilizzabili.

---

#### Processi
Mentre il "programma" è un'entità passiva (un file memorizzato su disco), il "processo" è un'**entità attiva** che possiede risorse assegnate dal sistema operativo per poter completare il suo compito.

---

#### Thread
Sono una suddivisione in sottoprocessi **dentro lo stesso processo** che agiscono in parallelo. Condividono lo stesso spazio di memoria (stesse variabili, stessi file aperti) ma hanno registri e stack separati.

In un programma multi-thread: il primo thread esegue una procedura , il secondo un’ altra ecc.. ma tutto questo avviene nello stesso ambiente.

#### Flusso di Esecuzione (Execution Flow) e context switch
Il **flusso di esecuzione** descrive la sequenza ordinata di istruzioni che la CPU elabora per portare a termine un programma. In un sistema multiprogrammato, questo flusso non è lineare: il sistema operativo può interrompere l'esecuzione di un processo (tramite un'**interruzione** o allo scadere del suo _time slice_), salvarne lo stato nel **PCB** (Process Control Block), e riprendere l'esecuzione di un altro processo dallo stesso punto in cui era stato sospeso.

Questo meccanismo, noto come **context switch**, è ciò che rende possibile l'esecuzione parallela apparente su un singolo processore.

---

#### Il Computer
![[Pasted image 20260525170307.png|517]]

Un calcolatore (in maniera generica o astratta)è caratterizzato dalla presenza di una o più CPU, ogni CPU è collegata alle periferiche tramite BUS, solitamente specializzati, che ottimizzano la comunicazione tra CPU e le varie componenti periferiche dell’hardware.

---

#### Processore
E l’unità di elaborazione centrale (Central Processing Unit). Presenta un insieme di registri che possono contenere dei dati.

A livello generale:
- Preleva dalla RAM la prossima istruzione da eseguire;
- La decodifica, capendo qual è la sua semantica e gli operandi necessari;
- Nel momento in cui viene decodificata poi viene eseguita con operazioni logiche, aritmetica o altro…

Per la CPU la **RAM** funge da memoria primaria ad alta velocità per i dati e le istruzioni in uso. Per accelerare ulteriormente l’accesso, utilizza anche la **cache**, posizionata vicinissima al processore.

Dei registri generici della CPU ce ne occorrono un numero limitato, di appoggio per i dati provenienti dalle varie operazioni svolte nella CPU; ma ci sono anche dei “registri specifici” per la gestione del ciclo fetch, decode ed execute si chiamano UNIT.

Il **Program Counter** è un registro che indica alla CPU qual è l’indirizzo della prossima istruzione da eseguire. Il ciclo inizia proprio con l’istruzione localizzata esattamente nel PC.

##### Stack e stack pointer
**Le esecuzioni effettuate nella CPU vengono affiancate da una struttura esterna, lo stack.**
Lo stack di esecuzione di un programma è gestito come se fosse una pila, push e pop sempre sulla testa. In questa memoria di appoggio si allocano variabili e vengono inserite nello stack tramite una push, questo fa si che quando la procedura che aveva allocato una variabile finisce vengono fatti dei pop che deallocano quelle locazioni di memoria allocate dalla procedura.
Alla fine della procedura, lo stack sa quanti elementi deve deallocare e quali sono i valori di ritorno.

Tutto questo funziona anche per le funzioni ricorsive, infatti si utilizza uno stack per darle vita. Per crearlo, devo avere spazio in memoria e un puntatore alla testa(memorizzato nello **Stack Pointer**).

Lo **Stack Pointer (SP)** è un registro speciale della CPU che contiene l'indirizzo di memoria dell'ultimo elemento inserito nello stack.

>[!warning] Le allocazioni di memoria dinamica (la malloc in C) non vengono fatte nello stack ma nello heap

##### PSW - Program Status Word
Il **PSW** (Program Status Word) è un registro che contiene informazioni relative a istruzioni di controllo, flag condizionali, modalità di esecuzione della CPU
Il **PSW** è un registro che racchiude lo stato istantaneo del processore. Quando si verifica un evento inaspettato o una richiesta esterna, il contenuto del PSW viene salvato, permettendo al processo interrotto di riprendere l'esecuzione esattamente da dove si era fermato.

PSW è quindi il registro che permette il **Context Switch** (cambio di contesto):

---

#### Definizioni:
- Gli utenti del sistema operativo sono i processi;

- Le librerie sono raccolte di codice già scritto e riutilizzabile che possiamo utilizzare, ad esempio anziché andare a costruirsi una struttura dati (heap, pila, lista ecc...) possiamo usare questi sistemi già pronti che altri hanno già creato in precedenza (il vantaggio oltre al tempo risparmiato e ad avere un minor numero di errori è che le istruzioni di libreria sono ottimizzate in modo da avere una complessità il più bassa possibile) 

- L' **interrupt hardware** è simile ad un operazione di TRAP ma differisce per il fatto che l'interrupt è mandato dall'hardware (anziché dal software con la system call), gli interrupt sono un meccanismo che permette di notificare qualcosa alla CPU, interrompe quindi quello che sta facendo in quel momento per eseguire la routine associata all'interrupt (è questo ad esempio il motivo per cui la freccia del mouse è sempre fluida senza mai bloccarsi anche quando il computer è sotto sforzo, perché il mouse lancia un interrupt e si fa riservare un piccolo spazio di esecuzione per essere eseguito senza problemi). La CPU salva il minimo indispensabile per tornare a riprendere quello che stava facendo prima (salvataggio del contesto quindi Program Counter, PSW ecc...) in modo simile alla TRAP, la CPU riprende il suo lavoro. In generale un interrupt non deve procurare problemi, tutto poi deve continuare normalmente.

---

#### Ottimizzazione dei processi nella CPU 
##### Multithreading
Tra i vari meccanismi possiamo trovare il **multithreading**, si riferisce all' ottimizzazione di una CPU. Questo escamotage prevede di implementare un doppio contesto di esecuzione all'interno dello stesso core. 
L'idea è: nel ciclo di decode e execute ci sono tempi morti(quando la CPU deve accedere a locazioni della RAM), nei registri vengono caricati i set di valori associati a due diversi processi: se ho il processo P1 che implica un certo numero di cicli affinché un suo fetch venga concluso, nel tempo morto verranno eseguiti degli step del P2. Sembra una complicazione, ma permette di lavorare su processi diversi in modo più efficace, *ma questa soluzione non è parallelismo*, non ce una doppia CPU, il multithreading viene effettuato sullo stesso core. in un dato istante si attenziona o uno o l'altro processo. Il sistema operativo deve però capire che l' ALU è sempre la stessa evitando di portare a utilizzi strani della risorsa, evitando quindi di bloccare i processi.  

##### Multiprocessori e multicore
Un altro sistema sono i **multiprocessori** (*da notare NON multicore*) in cui aggiungo più CPU in modo da poter *parallelizzare* certi processi, accoppiando al multithreading e ad una buona pipeline si può migliorare molto la velocità di esecuzione. Questa scelta è stata fatta perché non si riesce a espandere all'infinito la cache o i registri ne si riescono ad aumentare troppo i GigaHertz della CPU, perché si va incontro a consumi elevati e problemi di surriscaldamento (al massimo si può arrivare sui 5.5/6 GHz).
Diverso è il discorso del **multicore** in cui anziché avere ad esempio 4 CPU distinte montate sulla scheda madre abbiamo più core (e quindi più ALU) all'interno della stessa CPU, soluzione utilizzata in moltissimi scenari consumer, a differenza invece dei data center che spesso usano anche la tecnica del multiprocessori

---

#### Memorie
*Memorie che possiamo trovare, dalla più piccola e veloce alla più grande e lenta:*
- *Registri*: memoria velocissima riesce a stare al passo della CPU è molto piccola (nell'ordine di pochi byte) e contiene i dati che servono ai processi per poter essere eseguiti, si trova dentro la CPU
- *Cache*: memoria anch'essa piccola e veloce posizionata dentro la CPU, a differenza dei registri la cache è più capiente (siamo nell'ordine dei Megabyte, le più grandi arrivano sui 100 mega circa) ma anche più lenta dei registri, restando comunque la seconda memoria in termini di velocità e dimensione, la cache è divisa in 3 livelli: L1, L2, L3 rispettivamente il più veloce, quello nella media e il più lento, lo scopo principale della cache è evitare in ogni modo che durante la fase di fetch si debba passare per la RAM (cosa che comunque ogni tanto succede) in modo da evitare bottleneck, utilizzando le linee di cache da 64 byte ciascuna (ovvero quando si prendono dei dati dalla RAM si prendono anche i successivi, perché è molto probabile che quei dati saranno utili a breve, quindi il dato prelevato va nei registri mentre quelli successivi aspettano nella cache: cache hit quando quei dati sono serviti veramente e si è risparmiato tempo, cache miss quando quei dati non sono serviti e bisogna andare di nuovo nella RAM)
- *RAM*: memoria principale dell'architettura di Von Neumann, è veloce anche se molto meno di cache e registri ma in compenso è più capiente (ordine di Gigabyte) qui risiedono i dati che servono ai processi per poter essere eseguiti.
- **RAM, cache e registri sono memorie volativi ovvero quando il PC viene spento si svuota di tutti i lori dati**
- *Memoria di massa*: questa memoria comprende vari dispositivi, dischi ottici, hard disk, SSD, pen drive ecc..., sono memorie lente rispetto a quelle volatili ma con diverse velocità in base al dispositivo in uso (SSD è più veloce di HDD), sono memorie usate per immagazzinare i dati, quindi sono **non volatili** ovvero quando il computer si spegne non perdono il loro contenuto.
- ![[Pasted image 20260311194821.png|544]]

---

#### Dispositivi di I/O
Si individuano 2 componenti:
- controller -> interfaccia per il SO
- dispositivo in se

Ad esempio la scheda video è un controller per lo schermo. Un controller è quindi un mini calcolatore dotato di una propria unità di elaborazione e una memoria (le scheda video hanno un chip che esegue calcoli e una propria VRAM), usiamo l'esempio di un Hard Disk:
Il controller dell' HDD è fisicamente collegato al disco, il controller si occupa di pilotare il motorino del disco e permette di inviare comandi (motore spento o acceso ad esempio), la CPU da se non riesce a comandare questo controllore, ha quindi bisogno di un driver proprietario, sviluppato dall'azienda dell'HDD che permetta di far dialogare bene SO, CPU e controllore con la periferica.
Quando un controller sta lavorando (ad esempio per cercare un file in un HDD), la CPU deve aspettare che arrivi il risultato, ma anziché stare ferma svolge altri compiti, sarà quindi un interrupt mandato dal controller che segnalerà alla CPU che il dispositivo ha fornito la sua risposta 

---

#### Tipologie di sistemi operativi
![[Pasted image 20260525170924.png|414]]
Gli ambiti in cui si può sviluppare un sistema operativo sono molteplici e per questo esistono varie tipologie di SO: 

- *MAINFRAME*: Si distinguono perché gestiscono risorse più abbondanti, dati enormi. Calcolatori che hanno capacità di gestire risorse con ordini di grandezza molto grandi in cui lo storage, la capacità di calcolo e la memoria sono grandi. Sono storicamente legati a Job non interattivi dove il sistema elabora grandi quantità di transazioni senza l'intervento costante dell'utente. 
  - *SERVER*: Evoluzione dei mainframe in ottica di rete. Si sottolinea la necessità di gestire un sistema con capacità sopra la media rispetto ad un personal computer. Devono gestire servizi specifici (web, mail, database) forniti a più utenti, si crea multi utenza. Tali sistemi devono garantire non solo la multi utenza ma anche la reattività, un sistema che deve essere interattivo e reattivo rispetto all'utente. 

- *PERSONAL COMPUTER*: Il SO per eccellenza che punta sull'interattività. Deve massimizzare l'esperienza utente. Parliamo di sistemi multiprogrammati con interfacce grafiche (GUI) complesse. Qui l'algoritmo di scheduling è fondamentale: deve dare l'illusione all'utente che tutti i processi (browser, musica, editor di testo) stiano girando perfettamente in contemporanea. 

- *PALMARI/ SMARTPHONE*: Simili a PC ma hanno dei vincoli. Caratterizzati da sistema interattivo(processi con interfaccia grafica GUI) multiprogrammato quasi sempre mono utente. La gestione da parte del sistema operativo nello sfruttamento delle risorse è necessario soprattutto quando incontriamo problemi derivanti anche da app (ES: risparmio energetico). L'interattività esasperata dal touch screen richiede tempi di risposta più rapidi, necessita di un ulteriore grado di interattività. 

- *SISTEMI EMBEDDED (INTEGRATI)*: Hanno analogie con i personal computer. Si tratta di sistemi che troviamo a casa (ES: vecchie tv, router, stampanti ecc...). La struttura interna è quella di un calcolatore con la presenza di più processi , troviamo un SO simile a quello dei computer, in cui la differenza principale è che sono sistemi SEMI-CHIUSI: non sono progettati per installare qualsiasi app (come un PC), ma per eseguire un set di processi predefinito e prevedibile. Alcuni hanno anche risorse limitate da gestire con pochi KB o MB di memoria. 

- *SISTEMI REAL TIME*: Qui non conta solo cosa fa il sistema, ma quando lo fa. La correttezza del sistema dipende dal rispetto dei tempi (deadline). Hanno un compito ben specifico (es. macchinari industriali ,robot, catena di lavoro/ assemblaggio) è un sistema multiprogrammato ma hanno peculiarità in termini di esigenze, già il nome ne specifica l'esigenza (reattività in tempo reale), può essere considerato un sistema vicino all'interattività ma in realtà si basa sulle tempistiche di reazione dei processi (es. sensore che monitora posizione) per cui deve scattare una reazione ben precisa. I sistemi interattivi non sempre permettono di reagire nei momenti in cui serve, se questo accade su sistemi real time non si soddisfano le garanzie premesse e si può andare incontro a problemi non accettabili, non ci sono tolleranze rispetto alla reattività. possiamo fare un a distinzione tra due tipi di di sistemi real-time: 

| TIPO           | DESCRIZIONE                                                                            | ESEMPIO                                         |
| -------------- | -------------------------------------------------------------------------------------- | ----------------------------------------------- |
| HARD REAL-TIME | Le deadline e le<br>condizioni/reazioni sono<br>imprescindibili.                       | airbag, ABS, sistemi di razzi spaziali e aerei. |
| SOFT REAL-TIME | Le scadenze sono importanti<br>ma dei ritardi occasionali<br>possono essere tollerati. | lettore multimediale.                           |

A differenza dei sistemi desktop che usano lo scheduling in cui il SO da e toglie CPU quasi in continuazione ai processi, molti sistemi Real Time usano un approccio collaborativo: il processo usa la CPU per il tempo strettamente necessario e poi la rilascia volontariamente. 

---

## **Struttura di un sistema operativo**

![[Pasted image 20260525170942.png|488]]
I sistemi operativi moderni sono programmi software molto complessi e grossi che richiedono una struttura rigorosa. 

A volte si parte da una base cercando di adattarla ai nuovi scopi. In generale dal punto di vista di sviluppo manutenibilità e possibilità di aggiungere funzionalità senza bug diventa complicato da gestire a lungo termine. 

**Alcune possibili strutture per un SO** 
- Monolitici 
- A livelli (o a strati) 
- Microkernel 
- A Moduli 
- Macchine virtuali 
Vediamole una ad una.
---

#### SISTEMI MONOLITICI 
Tutto il SO è eseguito in modalità kernel. (Il kernel  di Linux è monolitico)
Nei sistemi monolitici, il Kernel è un unico, enorme file binario. Dal punto di vista del codice: 

- Non ci sono barriere: ogni funzione può chiamare qualsiasi altra funzione senza restrizioni. 
- Le strutture dati (come la tabella dei processi o la gestione della memoria)sono condivise globalmente all'interno del kernel. 

Questa mancanza di isolamento creava disorganizzazione sui primi sistemi (Un bug nel driver di una tastiera può corrompere la memoria del file system, causando un crash totale).  La disorganizzazione portava a : 

- Difficoltà di Sviluppo: Se si deve aggiungere una funzionalità, si rischia di rompere involontariamente qualcosa di apparentemente non correlato. 

UNIX originale: Sebbene più strutturato, aveva "tutto dentro" il kernel (gestione file, driver, scheduling). 

Inizialmente (es. MS-DOS), non c'era protezione hardware: un'applicazione poteva scrivere direttamente sui registri del disco. Con l'avvento di processori più avanzati, si è introdotta la separazione fisica: 

- User Mode: Dove girano le app (browser, editor). Hanno privilegi limitati. 
- Kernel Mode: Dove risiede il monolite. Ha controllo totale sull'hardware. 

- System Calls: L'interfaccia delle system call funge da unico "ponte" sicuro tra l'utente e il monolite. 

| PRO                                                                                           | CONTRO                                                                                |
| :-------------------------------------------------------------------------------------------- | :------------------------------------------------------------------------------------ |
| **Velocità:** Non c'è overhead per passare messaggi tra componenti; le chiamate sono dirette. | **Instabilità:** Un errore in un punto qualsiasi fa crollare tutto il sistema.        |
| **Efficienza:** Minor uso di memoria per la gestione della comunicazione interna.             | **Rigidità:** Difficile da aggiornare o modificare senza ricompilare l'intero kernel. |

---


#### STRUTTURA A LIVELLI (O A STRATI) 
![[Pasted image 20260531221210.png|211]]
Un’organizzazione gerarchica, in cui ogni livello implementa funzioni impiegando quelle fornite dal livello inferiore. Potrebbe avere problemi di performance a causa delle numerose chiamate implicite del sistema a livelli. Tuttavia, semplifica la programmazione, in quanto ogni livello si dovrà interfacciare solo con il livello inferiore e superiore. *Principio di singola responsabilità*.

Un sistema a strati è un'astrazione in cui si lavora in ogni livello con delle esigenze ben precise. Usare gli strati permette di facilitare la fase di testing di ognuno di essi. 

Un protocollo deve essere progettato con finalità precise, deve basarsi anche sullo strato sottostante ( ES: in reti, TCP si basa anche sullo strato sottostante). Perché ogni livello nasconde la complessità di quello inferiore e offre servizi a quello superiore. ( ES: un livello basso gestisce l'hardware, ma lo strato superiore "vede" solo CPU virtuali (grazie al time sharing). Lo strato superiore non sa come la CPU venga divisa, sa solo che ne ha una a disposizione.) 

Creiamo una serie di strati dove il più in basso è quello che già conosciamo ovvero l'hardware, sopra troviamo SO che può essere formato da uno o piu strati. Gli strati interni a SO sono astrazioni che servono come servizio agli strati che gli stanno sopra, ma che devono basare i servizi sullo strato sottostante. 

*Questa suddivisione a strati permette di facilitare l'implementazione del SO.* 
Due vantaggi sono la modularità e il parallelismo: 

- Puoi testare lo Strato 1 subito dopo averlo scritto. Se funziona, sai che eventuali bug futuri saranno nello Strato 2 o superiore. 

- Sviluppo in parallelo: persone differenti possono lavorare su strati diversi, purché le interfacce (le "promesse" di cosa fa ogni strato) siano ben definite. 

L'idea alla base del sistema a strati è che ogni livello offra un'interfaccia pulita a quello superiore, nascondendo i dettagli implementativi. 

- Esempio della Memoria Virtuale: Lo strato della gestione memoria offre ai livelli superiori l'illusione di avere uno spazio di indirizzamento potenzialmente infinito. 

- Se la RAM fisica finisce, il sistema sposta i dati meno usati sul disco (swapping). Gli strati superiori non "vedono" questo movimento; per loro, la memoria è semplicemente disponibile. Questa trasparenza permette di cambiare la tecnologia del disco (es. passare da HDD a SSD) senza dover riscrivere le applicazioni o gli strati più alti. 

Non si possono disporre gli strati a piacimento; l'ordine è dettato dalle necessità operative. Lo strato del "Driver del Disco" deve trovarsi necessariamente sotto quello della memoria. Se un processo scrive su disco, la chiamata è spesso bloccante. Se lo strato di gestione della CPU (lo scheduler) fosse posizionato sopra quello del disco in modo errato, rischieremmo che l'intero sistema si fermi in attesa di un'operazione di I/O, rendendo impossibile gestire altri processi. 

**La struttura ad anelli** è concettualmente simile a quella a strati, ma introduce una differenza fondamentale: la protezione hardware. Mentre nella stratificazione semplice l'ordine è solo organizzativo, qui l'architettura è rappresentata da cerchi concentrici dove l'hardware occupa l'anello centrale (il più protetto). 
La differenza cruciale risiede nel momento in cui il codice viene eseguito: 

- *Nei sistemi a strati classici:* L'organizzazione serve a progettare meglio il software, ma una volta in esecuzione, tutto il kernel gira spesso in un unico spazio di memoria. Se un bug colpisce uno strato, può corrompere i dati di tutti gli altri perché non c'è una barriera fisica: il sistema "crolla" proprio come nei sistemi monolitici. 

- *Nel modello ad Anelli*: L'isolamento avviene a runtime. Ogni anello definisce un'"area di pertinenza" con privilegi decrescenti man mano che ci si allontana dal centro. Un bug in un anello esterno è confinato e non può accedere o danneggiare direttamente le strutture dati degli anelli più interni (più critici). 

Per richiedere un servizio a un anello più interno (protetto), il processo deve generare una "trap". Questo rende il sistema solido: è fisicamente impossibile per un pezzo di codice "saltare"  senza un controllo preventivo. 

Rimane il problema di definire esattamente l'ordine di precedenza. Ogni passaggio tra anelli richiede cicli di CPU per salvare lo stato, verificare i privilegi e cambiare i registri del processore. Questo overhead è molto più pesante rispetto a una semplice struttura a strati software, rendendo il sistema più lento. 

|Struttura a strati|Struttura ad anelli|
|---|---|
|Un bug può propagarsi a<br>tutto il kernel.|Un bug viene isolato<br>allʼanello corrente.|

---

#### MICROKERNEL 
L'idea centrale è avere un kernel più piccolo rispetto alla concezione generale. Si mantiene nel "nucleo" solo ciò che è strettamente fondamentale per far funzionare la macchina delegando il più possibile al livello utente. 

**Interprocess Communication** 
Poiché i servizi sono frammentati e isolati, il compito principale del microkernel diventa la comunicazione. Il kernel fornisce un'infrastruttura di meccanismi che permette ai processi di comunicare tra loro e con il kernel stesso. Questo avviene tramite richieste tra pari o messaggi che vanno al kernel, permettendo a componenti separati di collaborare come se fossero un unico sistema. 

| Vantaggi                                                                                                                                                                                                               | Contro                                                                                                                                                                 |
| ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Tutto ciò che gira nel microkernel è"micro",<br>quindi è molto più semplice da scrivere e<br>gestire rispetto a un kernel normale(proprio<br>come è più facile scrivere un singolo livello in<br>un sistema a strati). | Far passare tutte le comunicazioni tra il<br>microkernel e i vari servizi attraverso lo<br>scambio di messaggi rappresenta una<br>forma di overhead.                   |
| I singoli servizi sono istanziati dentro<br>processi isolati. Ad esempio, si possono<br>incapsulare i driver in processi utente<br>separati. Se un driver fallisce, il resto del<br>sistema rimane protetto.           | Questo continuo scambio di dati rende il<br>sistema meno scattante rispetto a un<br>sistema monolitico dove tutto avviene<br>internamente senza comunicazione esterna. |

---

#### STRUTTURA A MODULI
Linux e macOS usano una struttura a moduli.

Scrivere un Sistema Operativo in termini di moduli, alla base è simile al microkernel, ci sono parti inscindibili al kernel e poi una serie di funzionalità pensate in termini di moduli(molto vicino alla prog. ad oggetti), questi moduli possono invocare i servizi offerti da altri moduli in modo libero ma organizzato vincolato da interfacce. 

> [!note] 
> Un oggetto è qualcosa di simile ad un servizio: ha i suoi metodi, interfaccia con cui gli altri oggetti possono usare i servizi offerti

Lo scheduler è a sua volta un modulo (lo scheduler sceglie i processi da far eseguire per massimizzare il troughput). 

*Una delle caratteristiche fondamentali è caricamento on demand*: ho un kernel minimale che manca di tante funzionalità e allʼoccorrenza metto le funzionalità che necessito. Oppure posso caricare più scheduler o fare switch da uno all'altro. Il cuore della differenza tra Microkernel e Moduli: lo spazio di memoria e i privilegi. 

*Differenze tra microkernel e moduli*
- Nel Microkernel, i servizi (driver, file system) girano in User Mode. Per comunicare con il kernel devono usare il Message Passing, che è lento perché richiede continui cambi di contesto (context switch). 
- Nel Sistema a Moduli, i moduli vengono caricati e girano in Kernel Mode. Sono parte integrante del "corpo" del kernel. 

- Vantaggio: La comunicazione tra moduli è una semplice chiamata a funzione (overhead zero). 

- Svantaggio: un bug in un modulo ha privilegi totali e può tirare giù l'intero sistema (Kernel Panic). Se ce un bug in un modulo può mandare in crash in sistema. 

I sistemi moderni sono dei veri e propri ibridi che cercano di prendere il meglio da ogni mondo: la velocità del monolite, la pulizia del design ad oggetti dei moduli e la sicurezza del microkernel implementando una struttura a livelli. 

>[!example] **LINUX**
Linux nasce come kernel monolitico, ma la sua evoluzione lo ha reso estremamente sofisticato. Internamente, la sua forza è la struttura a moduli. Immaginiamo il cuore di Linux come una base minima che può espandersi: se si collega una nuova periferica, il kernel carica un "modulo" (un pezzetto di codice che gira con pieni privilegi hardware) senza dover riavviare. È un design simile alla programmazione ad oggetti: ogni modulo è isolato, ha la sua interfaccia e comunica con gli altri in modo efficiente (overhead zero). 
Tuttavia, Linux "ruba" un'idea al microkernel per aumentare la stabilità: l'esternalizzazione. Alcune funzioni che un tempo stavano nel cuore del sistema oggi girano in modalità utente. Un esempio classico è la gestione della stampa o alcuni file system: se il driver della stampante va in crash, cade il servizio, ma il computer non si blocca. In questo senso, Linux si comporta "un po' come un microkernel". 

> [!example] MACOS
> MacOS porta questo concetto ancora più in là. Il suo cuore è esplicitamente un ibrido. Utilizza una base microkernel (Mach) per gestire i compiti fondamentali, ma vi incolla sopra una parte monolitica per garantire le prestazioni. Come Linux, anche MacOS usa i moduli, che permettono di aggiungere funzionalità che girano con privilegi massimi, pur mantenendo una struttura interna molto ordinata. 

---

#### MACCHINE VIRTUALI
Non è un tema recente, è nato insieme ai primi calcolatori, sono ritornate in auge da circa 10 anni e utilizzate per: 
Istanziare una o più istanze virtuali, e dentro posso far girare un intero sistema operativo, mi permette un'istanza di Linux su macchina virtuale ospitata in una macchina reale windows o viceversa…. le combinazioni sono varie. 

*Perché?* 
Può essere un modo alternativo per usare più sistemi operativi contemporaneamente. Allʼoccorrenza faccio partire quello che mi serve, uso 
windows ma ho una macchina virtuale e lancio un' istanza di Linux dentro windows. *Ci sono utilizzi più seri:* 
- per testare un programma su più sistemi operativi
- sviluppo di sistemi operativi, gira tutto su macchine virtuali è più comodo; 
- altri impieghi sul tema della sicurezza: 

La virtualizzazione viene gestita dagli hypervisor. 
Esistono due tipi di Hypervisor: 
1. *Tipo 1*. Girano direttamente sull’hardware della macchina, ma uno dei sistemi operativi fa da host, monitorando gli altri. Microsoft Hyper-V e VMware sono due esempi. 
2. *Tipo 2*. L' OS virtualizzato è un processo di un OS host. VirtualBox è un esempio. 

 I primi hanno dei vantaggi in termini di prestazioni e in termini di sicurezza. Nel tipo 2 aumenta il rischio di virtual machine escape

---

## **Processi e thread**
#### Processi
###### Definizione di processo
Il processo è un istanza di un programma in memoria, ogni processo ha il proprio spazio di indirizzamento, il processo è composto dalle seguenti:
- *codice*(text nell'img): il codice eseguibile
- *dati*: strutture statiche che hanno valore (ci sono le variabili inizializzate sin dall'avvio del programma) si trova vicino al codice perché anche questi dati vengono caricati in memoria insieme al codice
- *stack*: una struttura di supporto al processo, in pratica una memoria che gestisce le chiamate a funzione e la gestione delle variabili statiche
- *heap*: memoria dinamica in cui vengono allocate le variabili dinamiche (classi, oggetti, malloc, new).

![[Pasted image 20260317180000.png|283]]
> [!TIP]
> Usiamo lo heap perché quando si ha un ritorno di una funzione nello stack tutte le variabili allocate vengono eliminate questo non succede con le cose allocate nello heap, che restano fisse fino a quando il programmatore non le elimina o il processo si chiude

Per ogni processo abbiamo un **Process Control Block** dove sono contenuti diversi metadati, tutti i **PCB** si trovano dentro *una tabella dei processi* (nella realtà non è una tabella ma spesso è un albero rosso nero) ognuno è identificato univocamente. Tra i metadati troviamo diverse informazioni come lo stato del processo, i file aperti, la copia dei valori che deve usare nei registri(quando viene eseguito questi valori vengono caricati nei registri), processi imparentati e allarmi pendenti(interrupt/segnali)

**Pseudo-Parallelismo dei processi**
![[Pasted image 20260319153905.png|622]]
Se si dispone di una sola CPU questa può elaborare un solo processo alla volta, anche se poi nell'uso quotidiano i processi da eseguire sono molti di più, allora la CPU crea delle CPU virtuali usate per dare l'idea che ogni processo abbia la sua CPU personale, questo si chiama *pseudo-parallelismo* perché appunto da l'idea di parallelizzare i processi quando in realtà non lo fa, semplicemente li esegue in maniera ottimizzata saltando da processo a processo in base a dipendenze e altro, questo comunque ne migliora la velocità di esecuzione globale. Un ragionamento simile vale anche per altre risorse, in generale il processo ha l'impressione di avere CPU e memoria (virtualmente) infinite.

##### Creazione e terminazione dei processi
**Creazione di un processo processo**: Ogni processo ha un PID che è un codice univoco. *La creazione di un processo può avvenire in 4 principali circostanze:*
1) All'avvio del sistema (boot).
2) Da parte di un processo padre (fork,exec,ecc...).
3) Per azione dell'utente.
4) Inizio di un job nei sistemi batch.

Approfondiamo il punto 2:
- **sdoppiamento del padre**: 
	- usando fork un comando UNIX che crea un nuovo processo clonando il padre
	- usando exec un comando UNIX che esegue un programma all'interno dello spazio di indirizzamento del processo chiamante, in pratica cancella tutte le informazioni del processo chiamante e inizializza al suo interno il nuovo processo (non crea un nuovo processo, semplicemente libera lo spazio usato da quello chiamante e in quello spazio vuoto esegue il processo nuovo)
- **nuovo processo**: usando CreateProcess, un comando specifico per windows che prende 10 argomenti e crea un nuova entità con PID (Process ID) diverso.


**Terminazione del processo**: esistono diversi modi per terminare un processo:
- *Uscita normale*: exit o ExitProcess, è il processo stesso che chiede al sistema operativo di voler terminare
- *Uscita su errore*: il programma riconosce che c'è un errore e termina volontariamente.
- *Terminato da un altro processo*: kill (UNIX) o TerminateProcess (windows) da parte di un altro processo (ad esempio quando chiudiamo una finestra con la X della GUI). Abbiamo soft-kill e hard-kill: il primo manda un segnale di terminazione, hard kill invece uccide "senza pietà" (ad esempio il termina attività del gestione attività)

##### Ciclo di vita di un processo
![[Pasted image 20260317162204.png|500]]
1. **new**: il processo viene inizializzato
2. **ready**: il processo è pronto ad essere eseguito dalla CPU, viene messo in una *coda dei processi* è il sistema operativo (scheduler in particolare) a scegliere quale processo in fase di ready eseguire
3. **running**: Il processo che si trova nella coda dei processi viene scelto dal sistema operativo e viene eseguito 
4. **blocked**: il processo in stato di running esegue una chiamata di input/output molto lenta (system call), il processo è bloccato perché sta aspettando la risposta di questa chiamata, quello che succede praticamente è che il sistema operativo lo tira fuori dalla coda dei processi a causa di questa cosa quest'ultimo entra nello stato di blocked, appena la chiamata di sistema rientra il processo diventa ready.
5. **terminated**: il processo ha finito, tutte le sue risorse sono state liberate.

**Tempo di CPU per ogni processo e prelazione**
Se un processo non effettua operazioni di I/O rischia di monopolizzare la CPU. Per evitare che questo accada esiste la **prelazione**: un'operazione tramite la quale il Sistema Operativo sposta il processo dallo stato di _running_ a quello di _ready_. Questo avviene quando il processo ha esaurito la quantità massima di tempo CPU che gli era stata assegnata, ed è innescato direttamente tramite un *interrupt*.

Quando cambia il processo in esecuzione parliamo di cambio di contesto di esecuzione (context switch), questo viene fatto dall'operazione di **dispatch** gestita dal dispacher che è quell'unità del SO che gestisce il controllo della CPU da parte dei processi consegnandolo al processo che deve essere eseguito, lo scheduler invece è l'algoritmo che si occupa di scegliere quale processo deve essere eseguito

| **Caratteristica**     | **Scheduler (CPU Scheduler)**                                        | **Dispatcher**                                                 |
| ---------------------- | -------------------------------------------------------------------- | -------------------------------------------------------------- |
| **Compito principale** | **Seleziona** un processo dalla _Ready Queue_.                       | Effettua il **Context Switch** (cambio di contesto).           |
| **Obiettivo**          | Massimizzare l'efficienza (Throughput, Turnaround time).             | Minimizzare la **Dispatch Latency**. (tempo di context switch) |

##### Tabella dei processi
All'interno della tabella dei processi troviamo vari PCB, in un PCB come dicevamo prima troviamo le seguenti informazioni
![[Pasted image 20260317165352.png|267]]
Queste informazioni vengono usate in diversi modi, sopratutto nella gestione degli interrupt per il cambio di contesto. 

##### Code e accodamento
Di seguito la gestione delle code all'interno della CPU durante l'esecuzione dei processi
![[Pasted image 20260317170122.png|500]]
Vediamo che per ogni caso abbiamo una coda:
- I/O queue/request: la coda di tutti i processi blocked a causa di operazoni di input/output
- time slice expired: la coda di tutti quei processi che "consumano" tutta la time slice
- fork a child: qua troviamo tutti i processi che hanno bisogno di tempo per forkarsi 
vediamo che tutto converge nella coda dei processi ready, da qui il sistema operativo pesca il processo da eseguire

---

#### Thread
All'interno di un processo si possono avere più flussi di esecuzione, questi flussi sono i thread (lightweight processes). 
Ad esempio se ho il processo di brave browser ci sarà un thread che gestisce la visualizzazione delle pagine, un altro che gestisce l'animazione della barra di ricerca.
Questo implica che la nostra CPU è formata da più CPU virtuali. Usare i thread ha dei benefici sopratutto durante lo stato "blocked" infatti al posto di bloccare tutto il processo si blocca solo lo specifico thread che fa l'operazione I/O.
![[Pasted image 20260317173027.png|500]]
Di seguito la differenza tra uso e non uso di thread
![[Pasted image 20260317174247.png|500]]
Come possiamo notare un Thread è caratterizzato da:
- Program Counter, registri, stack, stato
e poi condivide tutto il resto con gli altri thread, nell'immagine vediamo che sia il codice, i dati e i file vengono condivisi. La condivisione dei dati crea dei bug se il programmatore non è molto abile nella programmazione concorrente

> [!TIP] Vita del thread
> Possiamo dire che i thread vivono dentro lo stesso processo, in pratica condivido lo spazio di indirizzamento del processo.

**Tabella dei thread**: Ovviamente esiste una tabella dei thread che viene usata dalla CPU per quando ne esegue uno piuttosto che un'altro (questa tabella contiene una specie di PCB), quando passo da un thread ad un altro sto parlando di cambio del contesto di esecuzione, questa operazione è più efficace nei thread piuttosto che nei processi, questo perché lo spazio di indirizzamento è in comune.
**Stati**: sono praticamente uguali a quelli dei processi (Running, Ready, Blocked)
**Operazioni**: sui thread possiamo fare diverse operazioni necessarie per gestirli
- *thread_create*: un thread ne crea un altro;
- *thread_exit*: il thread chiamante termina;
- *thread_join*: un thread si sincronizza con la fine di un altro thread, questa cosa è utile in alcuni casi.
- *thread_yield*: il thread chiamante rilascia volontariamente la CPU.

> [!tip] Riassumendo: le CPU di oggi hanno più core fisici, dove vengono eseguiti più processi/thread all'interno di ogni singolo core (contest switch) quindi ad oggi si sfrutta il parallelismo puro (tra core) e lo pseudo-parallelismo (all'interno di ogni singolo core).


##### Multicore programming
![[Pasted image 20260321133728.png|498]]
Programmare pensando ad un sistema multi thread, ci permette di non cambiare nulla quando arriviamo in uno scenario multicore, nella pratica non cambia nulla, i thread vengono divisi sui vari core.

**Problemi della programmazione multicore**
Scrivere programmi multi-core non è banale, dobbiamo stare attenti alle seguenti cose:
- **Separazione dei task**: per task intendiamo i compiti che la nostra CPU deve eseguire, è importante che questi vengano individuati e resi parallelizzabili, a grandi linee abbiamo un task per thread. Ha senso creare un thread per task pesanti.
- **Bilanciamento**: cioè la giusta suddivisione del lavoro tra i thread e i core 
- **Suddivisione dei dati**: ognuno di questi task avrà bisogno di strutture dati che possono essere anche comuni (può capitare anche che più thread lavorano sulla stessa struttura dati) 
- **Dipendenza dei dati**: visto che i dati possono essere condivisi tra i vari thread ci possono essere delle dipendenze tra un task (e quindi un thread) ed un altro, è importante tenere a mente questo dettaglio per cercare di creare thread indipendenti quando possibile.
- **Test e debugging**: Ci possono essere diversi problemi quando si parla di processi multicore. Dato lo stesso input si possono avere output diversi questo perché ci possono essere problemi dovuti a come i thread vengono gestiti dallo scheduler, questo ovviamente non va bene, il debugging e i test servono a cercare questo tipo di problemi.

Vediamo le 3 modelli di thread:
###### Thread a livello utente
![[Pasted image 20260321134253.png|203]]
Le linee a zig-zag sono i thread generati dal programma in user mode (es. Excel) che confluiscono in un unico punto verso il kernel, *questo sta a indicare che il kernel non ha la minima idea di cosa sono questi thread lui li considera un unico processo*, quindi il programma usa una libreria che crea e gestisce una sua personale tabella dei thread (come se fosse un mini sistema operativo integrato)
*PRO*:
- scheduling personalizzato: il programma può scegliere le priorità tra i thread senza dover sottostare allo scheduler del sistema operativo
- il dispatching non richiede trap nel kernel: il cambio di thread è velocissimo perché il programma fa tutto nella user mode, senza dover passare alla kernel mode
*CONTRO*: 
- chiamate bloccanti:
	- *Chiamate di sistema bloccanti:* Quando un thread richiede un'operazione di I/O, l'operazione viene passata al kernel (trap). Dato che il sistema operativo vede e gestisce solo il processo nel suo insieme, mette in stato di attesa (_blocked_) l'intero processo finché l'operazione di I/O non è completata. Di conseguenza, tutti gli altri thread a livello utente si bloccano inevitabilmente, anche se avessero istruzioni pronte da eseguire e non dipendono da quel dato.
	- *Page fault:* Se un thread tenta di accedere a una variabile o a un'istruzione che si trova in un'area di memoria non attualmente caricata nella memoria RAM (ad esempio perché è stata spostata nell'area di swap su disco), si genera un'eccezione hardware chiamata _page fault_. Il sistema operativo deve intervenire per leggere la pagina mancante dal disco. Essendo un'operazione molto lenta, il kernel sospende l'esecuzione dell'intero processo. Pertanto, anche se gli altri thread del processo avessero tutte le loro pagine già pronte in RAM e potessero continuare a lavorare, vengono bloccati tutti fino al completamento del caricamento della pagina richiesta.
- nessun vero parallelismo tra i processi
- non si ha possibilità di prelazione, ovvero c'è la possibilità che la CPU o in generale una risorsa non venga rilasciata

Per gestire i thread a questo livello devo praticamente fare sempre le stesse cose, ma lo devo fare in maniera manuale a livello utente. Più precisamente il programmatore va a scrivere tutto il ciclo vitale di un thread e quando si può usando thread_yield il thread rilascia l'utilizzo della CPU ad un altro thread (dello stesso processo)

Questo modello viene chiamato modello "1 a molti"

###### Thread a livello kernel
Il kernel gestisce i thread, conosce che cosa sono i thread e sa che dentro ogni processo ci possono essere più thread, ovviamente il kernel deve essere affidabile nelle gestione dei thread, le chiamate di sistema sono analoghe a quelle usate a livello utente. Si ha un unica tabella dei thread a livello kernel.
*PRO*:
- Un thread con chiamata bloccante non va ad intralciare gli altri, come succede a livello user, proprio perché il kernel li può vedere.
- La prelazione è disponibile, quindi in caso di thread a livello kernel che occupano all'infinito una risorsa possono essere killati
*CONTRO*:
- Si ha un cambio di contesto più lento, perché il kernel va a gestire tutti i thread e non solo quelli di uno specifico processo (richiede trap)
- Creazione e distruzione più costose (il numero di thread kernel è tipicamente limitato, è importante riciclarli)

Il riciclo dei thread ci evita di utilizzare le chiamate thread_create e thread_delete in questo modo si risparmia molto tempo.

Con questo tipo di gestione il nostro sistema operativo vede tutto come thread anche un processo che thread non ne ha.

Questo modello viene chiamato modello "1 a 1"

###### Modello ibrido
Questo modello mira a combinare i punti di forza dell'approccio a livello utente (efficienza e flessibilità) con quelli dell'approccio a livello kernel (vero parallelismo), mitigando i difetti di entrambi.

In pratica, il sistema effettua un **multiplexing** di numerosi thread a livello utente su un numero limitato (uguale o inferiore) di thread a livello kernel.
- **Livello Utente:** Il programmatore, tramite la libreria, può creare tutti i thread necessari per la logica dell'applicazione. Il _context switch_ tra questi thread rimane rapido perché avviene nello spazio utente.
- **Livello Kernel:** Il sistema operativo fornisce e gestisce un pool di thread a livello kernel, assegnandoli ai processori fisici disponibili. La libreria di runtime si occupa poi di mappare dinamicamente i thread utente sui thread kernel liberi.
**Il grande vantaggio:** In questo modo, se un thread utente effettua una chiamata di sistema bloccante o subisce un _page fault_, il sistema operativo blocca solo il thread kernel associato in quel preciso momento. Gli altri thread a livello utente possono continuare la loro esecuzione appoggiandosi ai restanti thread a livello kernel disponibili.
![[Pasted image 20260319163244.png|500]]

###### Nei nostri sistemi operativi
Tutti i sistemi operativi moderni supportano thread a livello kernel, anche supporto a livello utente tramite diverse librerie: 
- green threads su Solaris
- GNU portable thread su UNIX
- fiber su windows
Esistono anche delle librerie di accesso ai thread, che ci aiutano ad interagire allo stesso modo con quest'ultimi indipendentemente dal sistema operativo usato

---

## **Comunicazione fra processi**
Gestire in maniera opportuna la comunicazione tra $n$ processi, è fondamentale per ottenere sistemi reattivi, veloci e performanti.
Spesso i processi hanno bisogno di cooperare, abbiamo diversi modi per fare ciò:
- **Pipe**: è il modello più semplice che permette di mettere comunicazione più processi. Sfrutta i canali di input/output per far comunicare i processi:  *cmd1 | cmd2 | cmd3* . Con questa sintassi da terminale, vengono messi in comunicazione l’output del cmd1 con l’input del cmd2, e analogamente, l’output del cmd2 nell'input del cmd3. Naturalmente questi tre aspetti sono isolati, ma in questo modo è possibile concatenare più processi.
- **IPC (Inter Process Communication)**: dei processi con il proprio spazio di indirizzamento riescono a comunicare grazie a dei segmenti di memoria condivisa, questo permette la comunicazione tra processi in modo efficiente.

**Possono verificarsi i seguenti problemi:**
- come scambiarsi i dati
- accavallamento delle operazioni su dati comuni
- coordinamento tra le operazioni

**Race condition**
**Esempio:** Supponiamo di avere due processi P1 e P2 che aggiornano una variabile intera condivisa *x*. Entrambi eseguono un ciclo `for` che incrementa *x* di uno (`x = x + 1`) per 100 iterazioni ciascuno.

L'istruzione `x = x + 1` non è atomica: il processore la scompone in tre passi distinti:
1. **Leggi** il valore di *x* dalla memoria
2. **Incrementa** il valore nel registro
3. **Scrivi** il nuovo valore in memoria

Il problema nasce quando i due processi si intersecano in mezzo a questi passi:
- *x* = 0
- P1 legge x → ottiene 0
- P2 legge x → ottiene 0 *(prima che P1 abbia scritto!)*
- P1 incrementa → 0+1 = 1, scrive x = 1
- P2 incrementa → 0+1 = 1, scrive x = 1

Risultato: *x* vale 1 invece di 2 — un incremento è andato perso. Questo può ripetersi in qualsiasi iterazione, quindi al termine delle 100 iterazioni di entrambi i processi, il valore finale di *x* potrebbe essere molto inferiore a 200. Questo fenomeno prende il nome di **race condition** (corsa critica). Un altro esempio è quello dell'accredito di denaro sul conto bancario.


**Sezioni critiche:** Per evitare le race condition, il programmatore deve garantire che i processi non accedano simultaneamente alla stessa risorsa condivisa. La porzione di codice in cui avviene questo accesso è detta *sezione critica*, e deve essere eseguita in mutua esclusione: un solo processo alla volta può trovarsi al suo interno.

*Per avere una buona soluzione dobbiamo rispettare queste quattro condizioni:*
1. mutua esclusione nell'accesso alle sezioni critiche
2. nessuna assunzione sulla velocità di esecuzione o sul numero di CPU
3. nessun processo fuori dalla propria sezione critica può bloccare un altro processo
4. nessun processo dovrebbe restare all'infinito in attesa di entrare nella propria sezione critica
Di seguito il dettaglio di quello che succede realmente 
![[Pasted image 20260319175036.png|500]]

Ci sono diverse soluzioni a questo problema, come:
- Disabilitare gli interrupt -> quindi anche il meccanismo di prelazione permette di evitare che l'esecuzione di una sezione critica di un processo venga interrotta.
- Variabili di lock -> si usa una variabile booleana per capire se la sezione critica è vuota o no.
- Alternanza stretta -> (o _strict alternation_) è un algoritmo software elementare utilizzato per garantire la **mutua esclusione** tra due processi concorrenti che devono accedere alla **sezione critica**. Il meccanismo si basa su un'unica variabile globale condivisa, tipicamente un intero chiamato `turno`, che indica esplicitamente quale processo ha il diritto di entrare nella propria sezione critica.
  ![[Pasted image 20260319175721.png|500]]

- Un altro algoritmo per avere mutua esclusione tra i processi che accedono alle risorse è *l'algoritmo di Peterson*

**Algoritmo di Peterson**
![[Pasted image 20260325174914.png|665]]
Riusciamo a gestire N processi, abbiamo una variabile turn che prende il valore del processo scelto per entrare nella sezione critica

- **Istruzioni TSL e XCHG per garantire mutua esclusione**
 
L'istruzione `TSL (REGISTER, LOCK)` compie due azioni allo stesso tempo:

1. Legge il valore attuale della variabile `LOCK` e lo copia nel registro.
    
2. Scrive un valore `!= 0` nella variabile `LOCK`.

**Come si usa:**
- Il processo chiama `TSL`.
    
- Se il registro riceve `1`, significa che qualcuno è dentro la sezione critica; il processo esegue quindi il ciclo di _wait_ finché `LOCK` non diventa `0`.
    
- All'uscita, il processo imposta `LOCK = 0`.


Tutte queste soluzioni fanno **spin lock**
Lo "spin lock" è una soluzione adottata in sistemi multicore e anziché mandare un processo in fase di attesa, resta attivo nella CPU anche se non produce lavoro utile, potrebbe sembrare contro intuitivo ma conviene dato che mettere un processo nella fase di wait (o ready) e poi riattivarlo (running) costa (solitamente) molto più tempo e risorse. E' spesso usato anche per sincronizzare tra loro i processi. Questa soluzione su sistemi single-core è da evitare a tutti i costi perché non è più conveniente

---

#### Problemi tra processi: sleep, wake up e semafori
*Problema dell'inversione di priorità*
E' un problema che si verifica quando un processo a bassa priorità viene eseguito bloccandone un altro con una priorità più alta.
Esempio:
Per capire il problema, immaginiamo un sistema con tre processi:
- **Processo H (High):** Priorità massima.
- **Processo M (Medium):** Priorità media.    
- **Processo L (Low):** Priorità minima.

Ecco la sequenza degli eventi:
1. **L inizia:** Il Processo L è in esecuzione e acquisisce un lock per entrare in una sezione critica.
2. **H si sveglia:** Il Processo H diventa pronto per l'esecuzione. Essendo ad altissima priorità, il sistema operativo blocca L e fa partire H.
3. **H si blocca:** H tenta di accedere alla stessa risorsa condivisa di L. Trova il lock occupato (perché L ce l'ha ancora in mano) e quindi H viene messo in stato di attesa (wait/sleep) finché L non rilascia la risorsa. Fin qui tutto bene: è normale che H aspetti chi ha il lock. Il controllo torna a L affinché finisca in fretta.
4. **M entra in scena (Il Disastro):** Mentre L cerca di finire il suo lavoro nella sezione critica per liberare H, si sveglia il Processo M. M ha una priorità _maggiore_ di L e _non gli serve_ quel lock. Il sistema operativo, vedendo che M > L, toglie la CPU a L e la dà a M.
5. **Il paradosso:** M inizia a fare i suoi calcoli per tutto il tempo che vuole. L non può andare avanti per liberare il lock. H (il processo più importante di tutti) è fermo ad aspettare L, ma di fatto **è bloccato da M**.

**Soluzione:** dare la possibilità al processo di bloccarsi in modo passivo (rimozione dai processi pronti) usando le primitive **sleep** e **wake up**
Il processo in questo momento si trova nello stato di running e chiama:
- *Sleep* -> mette il processo chiamante in modalità blocked, potrà usare la CPU solo quando sarà risvegliato
  ![[Pasted image 20260327121226.png|405]]
- *Wake up* -> sveglia il processo facendolo tornare nello stato di ready

> [!ATTENTION]
> Il processo dopo la wake up non si ritrova subito nello stato di running ma verrà inserito nello stato di ready quindi dovrà aspettare prima di avere di nuovo la CPU

---

#### Problema del produttore consumatore - spesso si trova al laboratorio
Questo problema descrive un produttore che produce *item*, un consumatore che consuma questi *item* e un buffer di memoria condivisa tra i 2 (uno mette e l'altro toglie).
Vediamo questo codice:
```
# Definizione del Produttore (inserisce un item in loop)
function producer()
    while (true) do
        item = produce_item()
        if (count == N) sleep()  //se il buffer è pieno si ferma
        insert_item(item)
        count = count + 1
        if (count == 1)
            wakeup(consumer)

# Definizione del Consumatore (consuma un item in loop)
function consumer()
    while (true) do
        if (count == 0) sleep()  //se il buffer è vuoto si ferma
        item = remove_item()
        count = count - 1
        if (count == N - 1)
            wakeup(producer)
        consume_item(item)
```
Il problema in questo codice sta nel fatto che i 2 processi potrebbero entrare nello stesso tempo all'interno della variabile *count* e cambiarne il valore nello stesso momento, causando problemi e non avendo così la *mutua esclusione*, si può arrivare anche al deadlock se entrambi i processi si mettono in sleep nello stesso momento aspettandosi a vicenda

**Soluzione:** generalizzando il concetto di sleep e wake up otteniamo i *semafori*.
Un semaforo è composto da:
- una variabile *S*: che non può mai diventare negativa
- funzioni *wait* e *signal*: queste due operazioni incrementano/decrementano la variabile S. Se si prova ad effettuare il *wait* sul semaforo a 0 l'operazione diventa bloccante
Per il corretto funzionamento, bisogna fare in modo che *down* e *up* siano atomiche, per evitare problemi con race condition sul semaforo.

Esistono diversi **tipi di semaforo**: 
- **Numerico**: S assume valori tra 1 e N, e si presta a problemi di conteggio delle risorse, bloccando il thread quando questo esaurisce la risorsa
- **Mutex**: è un semaforo in cui S assume valori tra 0 e 1, usato come flag per garantire la mutua esclusione
- Alcuni sistemi operativi gestiscono anche i **Futex** (fast mutex) che gestiscono in maniera migliore *down* e *up*, che normalemente sono delle chiamate di sistema qui sono gestite a livello utente migliorandone le performance

Soluzione per il problema di produttore-consumatore
![[Pasted image 20260327123503.png|612]]

Tra i [[UNI/Secondo_anno/Secondo Semestre/SistemiOperativi/PDF_LEZIONI/5_19_marzo.pdf|Thread utente]] che fanno riferimento ad un unico processo, modello *1 a molti*, i mutex si possono usare in modo efficiente facendo uso di TSL (o XCHG)

---

#### Mutex e thread utente
Tra i [[UNI/Secondo_anno/Secondo Semestre/SistemiOperativi/PDF_LEZIONI/5_19_marzo.pdf|Thread utente]] che fanno riferimento ad un unico processo, modello *1 a molti*, i mutex si possono usare in modo efficiente con TSL (o XCHG)

> [!CITE]
> **Ricordiamo**:
> - **TSL (Test and Set Lock):** È un'istruzione hardware che esegue due operazioni contemporaneamente e in modo indivisibile: **legge** il valore di una locazione di memoria (il "lock") copiandolo in un registro della CPU, e subito dopo **imposta** (scrive) quella stessa locazione di memoria a un valore non nullo (solitamente `1`, per indicare che la risorsa è "occupata").
>     - _A cosa serve:_ Se il valore letto era `0`, il processo capisce che il lucchetto era libero, lo ha appena chiuso a chiave (`1`) ed entra nella sua sezione critica. Se il valore letto era `1`, sa che qualcun altro è già dentro e continua a ciclare (Spinlock) finché non si libera.
> - **XCHG (Exchange)** _(nota: spesso la troverai scritta `XCHG` invece di `XHCG`, tipica delle CPU x86)_: È un'istruzione hardware alternativa al TSL che **scambia** (exchange) in modo atomico il contenuto di un registro della CPU con il contenuto di una locazione di memoria.
>     - _A cosa serve:_ Il meccanismo è simile al TSL. Un processo mette il valore `1` in un suo registro interno e poi esegue la `XCHG` con la variabile di lock in memoria. Dopo lo scambio, il processo controlla il suo registro: se c'è uno `0`, significa che ha "rubato" lo zero alla memoria lasciandoci un `1` (ha acquisito il lock). Se c'è un `1`, il lock era già preso e deve riprovare.
> 
> ![[Pasted image 20260326155928.png|500]]

L'implementazione di queste due istruzioni cambia e andremo ad usare delle primitive introdotte precedentemente (thread_yield)
![[Pasted image 20260326160339.png|500]]

**FUTEX (Fast Userspace Mutex)** 
Garantiscono prestazioni eccellenti riducendo drasticamente le costose chiamate di sistema      (_system call_). L'idea chiave è tentare di gestire il lock interamente in modalità utente. Si compongono di due elementi:
- **Libreria utente:** Tenta di acquisire il lock usando istruzioni hardware atomiche (come le TSL o XCHG viste prima). Se il lock è libero, lo prende e ritorna istantaneamente. Non essendoci chiamate al sistema operativo, l'operazione è velocissima.
- **Servizio kernel:** Interviene **solo** in caso di contesa. Se la libreria utente trova il lock già occupato, effettua una chiamata a sistema per chiedere al kernel di bloccare il processo (mettendolo in _sleep_) e accodarlo finché la risorsa non si libera.

#### Monitor
Sono delle astrazioni di alto livello disponibili su alcuni linguaggi, che offrono una gestione semplice della mutua esclusione, che sollevano il programmatore della responsabilità di usare bene i mutex.

> [!TIP]
> I semafori sono universali non essendo legate al linguaggio di programmazione, sono delle chiamate a sistema a differenza dei monitor che sono dei costrutti di più alto livello.

Quando i linguaggi di programmazione introducono i monitor molto spesso integrano anche una gestione autonoma dei thread, per garantire la sincronizzazione il monitor crea una variabile condizione sulla quale esercita i *wait* e *signal* (simili a sleep e wake up)

Di seguito la soluzione dei produttori-consumatori ma usando i monitor
![[Pasted image 20260326172735.png|703]]

#### Scambio messaggi tra processi
Questo approccio utilizza due primitive ad alto livello fornite dal sistema operativo: **`send(destination,message)`** e **`receive(source,message)`**.
I concetti chiave da ricordare sono tre:
- **Sincronizzazione implicita (Blocchi):** La `receive` è tipicamente _bloccante_: se non ci sono messaggi da leggere, il processo si mette in attesa. Anche la `send` può esserlo: se assumiamo che ci sia un **buffer** di appoggio con capienza finita _N_, e questo buffer è pieno, chi spedisce si blocca finché non si libera spazio.
- **Indirizzamento:** Può essere **diretto** (il mittente specifica il PID esatto del processo destinatario) oppure indiretto tramite una **mailbox** (una "cassetta della posta" condivisa da cui i processi pescano i messaggi).
- **Scalabilità:** Il grande vantaggio di questo approccio è che non richiede memoria condivisa. Per questo motivo è facilmente estendibile a sistemi distribuiti, permettendo a processi su computer diversi di comunicare via rete (ad esempio usando le librerie **MPI**).
![[Pasted image 20260326174634.png]]

**Il Codice (Produttore-Consumatore):** risolvere il problema del Bounded-Buffer in questo modo è elegantissimo. Il _producer_ impacchetta il dato e fa una `send`; il _consumer_ fa una `receive` e lo estrae. Tutta la complessità dei semafori visti in precedenza qui è gestita "dietro le quinte" dal sistema di messaggistica del sistema operativo!

---

#### Problema dei 5 filosofi
Ciascuno di questi filosofi può mangiare o può pensare, per mangiare richiede due forchette (risorse), le forchette sono una per ogni filosofo e sono tutte condivise. Per risolvere questo problema abbiamo diverse soluzioni.
![[Pasted image 20260413150630.png|250]]

###### Soluzioni generali
1. **Soluzione 1**:
```
int N=5 
function philosopher(int i) 
	think() 
	take_fork(i) 
	take_fork((i+1) mod N) 
	eat() 
	put_fork(i) 
	put_fork((i+1) mod N)
```
Questa procedura non è esente da difetti. Se tutti i filosofi diventano affamati nello stesso identico momento e afferrano contemporaneamente la prima forchetta, il sistema si blocca in una situazione di stallo definitivo (*deadlock*), in quanto nessuno di loro avrà mai a disposizione la seconda forchetta necessaria per mangiare.

- **Soluzione 2:** Per evitare lo stallo, si può prevedere che un filosofo, qualora non riesca a prendere la seconda forchetta, rilasci la prima e attenda un tempo prestabilito prima di riprovare. Sebbene eviti il _deadlock_, questa strategia introduce un nuovo problema: se i filosofi agiscono in perfetta sincronia, aspetteranno tutti lo stesso numero di secondi per poi riattivarsi e bloccarsi di nuovo simultaneamente. Il sistema entra in un ciclo infinito di azioni a vuoto.

- **Soluzione 3:** Questa soluzione è identica alla precedente, ma introduce un tempo di attesa casuale (_random_) anziché fisso. È un approccio semplice ma molto efficace: l'attesa casuale rompe la simmetria e la sincronia tra i filosofi, risolvendo di fatto il problema che creava la soluzione precedente.

- **Soluzione 4:** La soluzione più elegante e robusta prevede l'utilizzo di primitive di sincronizzazione, come un semaforo o un monitor.

###### Codice usando un semaforo mutex
Di seguito lo pseudocodice della soluzione usando un semaforo mutex
![[Pasted image 20260409155222.png|700]]
1. Inizializzazione e Variabili Globali :
   In questa sezione vengono definiti i parametri del sistema:
	- **Stati:** Ogni filosofo può essere in uno di tre stati: `THINKING` (pensa), `HUNGRY` (vorrebbe mangiare) o `EATING` (possiede le forchette e mangia).
	- **Semaforo `mutex`:** Garantisce l'**esclusione mutua** quando si accede o si modifica l'array degli stati.
	- **Semafori `s[N]`:** Un semaforo per ogni filosofo. Vengono usati per "bloccare" un filosofo se le forchette non sono disponibili.
2. Funzione `philosopher`:
   Rappresenta il **ciclo di vita infinito** di ogni singolo processo (filosofo). È strutturato in una sequenza logica: il filosofo pensa, cerca di prendere le forchette (`take_forks`), mangia e infine le posa (`put_forks`) per ricominciare il ciclo.
3. Funzioni di Gestione Forchette:
	- **`take_forks(i)`:** Il filosofo dichiara di avere fame e prova a mangiare chiamando `test(i)`. Se i vicini non stanno mangiando, passa a `EATING`. Altrimenti, si blocca sull'istruzione `down(s[i])` finché un vicino non lo "sveglia".
	- **`put_forks(i)`:** Dopo aver mangiato, il filosofo torna a pensare. Fondamentalmente, chiama `test` sui suoi vicini (`left` e `right`) per vedere se la sua azione di posare le forchette permette a uno di loro (che era in attesa) di iniziare a mangiare.
  4. Logica di Controllo e Vicinato (In basso)
	- **`left` / `right`:** Funzioni matematiche (usando l'operatore modulo N) per identificare correttamente i vicini in un tavolo circolare.
	- **`test(i)`:** È il cuore della logica. Verifica se il filosofo i è affamato e se **entrambi** i suoi vicini non stanno mangiando. Se queste condizioni sono vere, lo stato diventa `EATING` e viene inviato un segnale (`up`) al semaforo del filosofo per sbloccarlo.

###### Codice usando un monitor 
![[Pasted image 20260409161642.png|679]]
Questa è un implementazione è molto simile a quella fatta con il semaforo l'unica differenza è che qui sarà il sistema operativo a garantire l'accesso singolo al filosofo grazie al monitor e quindi alla gestione degli stati

---

#### Problema dei lettori-scrittori
Questo problema riguarda processi o thread che devono accedere ad una stessa risorsa.
Abbiamo i lettori che hanno solamente bisogno di leggere i dati in quella locazione e gli scrittori che invece sovrascrivono quei dati: si capisce quindi che la sincronizzazione tra questi processi sia fondamentale per evitare problemi.

**Soluzione basata sui semafori**
![[Pasted image 20260415130950.png|635]]
*Problema*
Il problema in questa soluzione è che i lettori hanno priorità assoluta e gli scrittori potrebbero non entrare mai perché mentre un lettore sta già leggendo ne potrebbe entrare un altro aumentando rc di 1 e quindi quando il primo ha finito di leggere rc sarà ancora 1 (perché era 2) e a questo punto il ciclo potrebbe continuare se entra un altro lettore, questo perché i lettori possono entrare in continuazione bloccando la risorsa per gli scrittori praticamente all'infinito 

**Soluzione basata sui monitor**
![[Pasted image 20260415133134.png|717]]

Questa soluzione funziona perché sia lettori che scrittori gestiscono bene l'uso della risorsa senza dare priorità solo ad uno o solo all'altro

## **Scheduling**
La scelta di quali processi va avviato viene fatta dallo scheduler, in pratica sceglie dalla coda dei processi pronti. Quindi lo scheduler entra in gioco alla terminazione o creazione di un processo, quando ci sono degli interrupt o si verificano chiamate bloccanti come l' I/O
Per fare ciò i processi si dividono in due tipi:
- processi *CPU bounded*: un processo che usa principalmente la CPU 
- processi *I/O bounded*: un processo che fa principalmente operazioni di input/output
quello che fa lo scheduler generalmente è inserire tutti i processi I/O bound dentro la CPU in modo da avviare tutte le operazioni di I/O che sono lente, mentre aspetta una risposta avvia i processi CPU bounded, una volta che questi sono finiti riprende l'esecuzione dei processi I/O bounded che a quel punto avranno quasi sicuramente finito

---

CPU BURST -> indica il tempo in cui la CPU è impegnata a fare i calcoli di un processo 
![[Pasted image 20260417163007.png|421]]

La parte vuota significa che sta aspettando il risultato di un operazione di I/O quindi magari la CPU va a svolgere altri compiti di altri processi

---

#### Obiettivi degli algoritmi di scheduling
Tutti gli scheduler hanno almeno questo obbiettivo in comune:
- Equità nell'assegnamento della CPU 

Definiamo diversi ambienti: batch, interattivi e real-time, questo perché in base allo scopo che devono perseguire i sistemi operativi si differenziano tra loro quindi lo farà anche lo scheduler:

1) I sistemi *Batch* sono sistemi progettati per svolgere un grande lavoro in blocco senza molta interazione con l'utente: ad esempio un super computer che elabora una simulazione, gli vengono forniti tutti i dati e il computer parte a svolgere il suo lavoro
2) I sistemi *Interattivi* sono quelli più comuni e devono interagire molto con l'utente (botta e risposta) sono i sistemi operativi dei cellulari o dei personal computer
3) I sistemi *Real-time* sono sistemi che non hanno molta interazione con l'utente e la caratteristica principale e la velocità e il rispetto delle scadenze temporali: ad esempio il sistema che gestisce tutti i controlli elettronici di un auto come l'ABS che deve rispondere in maniera tempestiva oppure il pilota automatico di un aereo
 
 ● Obiettivi tipici dei sistemi batch: 
 - massimizzare il throughput (o produttività); 
 - minimizzare il tempo di turnaround (o tempo di completamento); 
 - minimizzare il tempo di attesa; 
 
 ● Obiettivi tipici dei sistemi interattivi:
 - minimizzare il tempo di risposta; 
 
 ● Obiettivi tipici dei sistemi real-time: 
 - rispetto delle scadenze; 
 - prevedibilità.

> [!TIP] Ricordiamo
> **Preemptive** = Il sistema operativo può interrompere a metà un processo in esecuzione per dare la CPU a qualcun altro.
> **Non-preemptive** = Una volta che un processo ottiene l'uso della CPU, se la tiene stretta finché non ha finito.

#### Scheduling nei sistemi batch
Abbiamo diversi algoritmi che vengono usati nei sistemi batch:
- **FCFS**(First-come first-served) - non preemptive: il primo che arriva è il primo che viene servito, praticamente una coda FIFO molto semplice ma non troppo utile

- **SJF**(Shortest job first) - non preemptive: presuppone la conoscenza del tempo impiegato da ogni lavoro (viene eseguito il job che ha durata minore) - si riduce il tempo minimo di attesa, ma resta comunque non ottimale

- **SRTN**(Shortest Remaing Time Next) - preemptive: È la versione "preemptive" del SJF. Se un processo lungo sta girando e all'improvviso arriva un processo cortissimo, il sistema ferma quello lungo per sbrigare subito quello corto.

(I numeri di arrivo e durata sono "quanti di tempo")
![[Pasted image 20260417165309.png|627]]
Basandoci su questi esempi vediamo che SRTN è il più efficiente perché confrontando i tempi di arrivo e il restante tempo di completamento decide quale processo eseguire essendo preemptive può bloccare l'esecuzione di un processo per eseguirne un altro, questo unito alla caratteristica di SJF (cioè shortest job first) lo rendono il migliore

---

#### Scheduling nei sistemi interattivi
Anche qui abbiamo diversi algoritmi per ottimizzare questo scheduling, uno di questi è: 
##### Scheduling round robin
Questa è una versione con prelazione del FCFS, che si basa sullo gestire il tutto in un quanto di tempo

Questa versione funziona in base a dei quanti di tempo o time slice che di solito hanno una durata di 20-50ms
In sostanza ogni processo può occupare la CPU per un time slice appena finisce il tempo il processo verrà messo in fondo alla coda (FCFS usa una coda FIFO) e viene eseguito il processo successivo, se il processo completa il suo lavoro prima della fine del quanto di tempo allora libererà la CPU e inizierà l'esecuzione di un altro processo, se un processo esegue una chiamata bloccante anche lui verrà rimesso in fondo alla coda
![[Pasted image 20260417175441.png|551]]

> [!EXAMPLE] Esempio:
> Immagina di avere in background un rendering video pesantissimo e in primo piano Word, dove tu stai digitando. Se non ci fosse il Round Robin, il tuo clic sulla tastiera rimarrebbe bloccato ad aspettare per minuti interi che il video finisca di calcolare. Con il Round Robin, il rendering video lavora per (ad esempio) 20 millisecondi, poi viene sbattuto in fondo alla fila; tocca a Word, che elabora la tua lettera in 1 millisecondo e rilascia la CPU, poi tocca di nuovo al video, ecc.


##### Scheduling a priorità
**Concetto di Priorità**
Introduciamo il concetto di **priorità**: si assegna la CPU al processo di priorità più alta. Viene così creata una **coda di priorità**.
- I processi a priorità bassa possono essere eseguiti se nella coda non ci sono processi a priorità più alta.
- La **prelazione** può essere applicata a questo meccanismo: se un processo ad alta priorità entra in coda ma la CPU è assegnata a un processo a bassa priorità, qui avviene la prelazione.

Abbiamo 2 tipi di priorità:
- **Priorità statiche**: Dovute a fattori esterni come utenti admin.
- **Priorità dinamiche**: Il sistema può decidere di cambiare la priorità a determinati processi. Come per esempio lo scheduler decide di dare priorità ai processi **I/O bounded** invece che ai **CPU bounded**. Appena la risposta I/O arriva, i processi I/O bounded che erano bloccati tornano in coda pronti e sono con priorità alta.

Per capire se un processo è I/O o CPU bounded bisogna osservare come usano il loro **quanto di tempo Q**. Il processo I/O di solito si blocca prima perché aspetta un device di I/O, mentre quello CPU se lo prende tutto.

*Potrei quindi pensare di mappare la priorità sull'uso di un unico quanto di tempo: se un processo usa tutto il Q allora avrà priorità minima, meno Q usa più priorità avrà.*

$$P(prio) = Q - Q_{usato}$$
_(Quantizzato a valori interi minimi)_

La priorità qui è dinamica poiché se un processo cambia l'uso di Q avrà priorità diversa.

- Un altro modo sarebbe sfruttare il **SJF** facendo una stima della durata dei processi e assegnando più priorità a durata minore e meno priorità a durata maggiore.

- *Nei sistemi interattivi è meglio applicare la prelazione.*

**Starvation**
La **starvation** si presenta quando non posso mai garantire a un processo in coda (bassa priorità) l'uso immediato della CPU.
Per risolvere questo problema posso usare l'**aging**: esso aumenta temporaneamente la priorità dei processi che trascorrono troppo tempo nella coda dei processi pronti; più tempo aspetta, più aumenta di priorità. Dopo che viene eseguito, la priorità torna a quella di base.

---
##### Scheduling a Code Multiple
Potremmo usare un sistema di **scheduling a code multiple**: avrò una coda per ogni livello di priorità, in ogni coda avrò processi della stessa priorità.

Bisogna avere due scheduling diversi che scelgono quale processo far eseguire:
1. **Scheduling verticale**: Viene scelta la prima coda non vuota dall'alto (priorità dall'alto al basso).

2. **Scheduling orizzontale**: Scelta la coda, bisogna scegliere un processo tra quelli (insieme di uguale priorità). Utilizzo un algoritmo visto in precedenza come il **Round Robin (FIFO)**. Potrei avere diversi algoritmi di scheduling per ogni coda, potrei anche applicare $RR(Q)$ con Q variabile da un livello all'altro.
![[Pasted image 20260419113959.png|435]]

Metto a priorità alta processi I/O bounded e  bassa quelli CPU bounded in mezzo processi misti.

Avrò quanti di tempo più piccoli nelle priorità alte dato che ci sono processi I/O bounded e rendono il sistema più reattivo, e nelle priorità basse un quanto più grande.

> **Nota visiva (piramide delle code):**
> 
> - $Q_1 \leftarrow Prio 4$ (Vertice)
>    
> - $Q_2 \leftarrow Prio 3$
>    
> - $Q_3 \leftarrow Prio 2$
>    
> - $Q_4 \leftarrow Prio 1$ (Base)
>    
> - La durata Q aumenta scendendo verso il basso.
>    
> - Posso assegnare a $Q_4$ un quanto infinitamente grande o un FCFS.
>    

Per evitare la starvation posso realizzare un **up/down grade** della priorità in base all'uso del suo quanto di tempo. Potrei fare una media su come il processo usa il suo Q: se lo usa tutto, Q è troppo piccolo, quindi è CPU bounded e allora scenderà di un livello.

Un altro modo è cambiare lo scheduling verticale assegnando un tempo T a un ciclo. Per ogni livello verrà assegnata una percentuale di T a ogni coda di priorità. Se una coda è vuota la percentuale di T sarà minore.

---
##### SPN Shortest Process Next
Applico lo **SJF** ai processi interattivi. In questi sistemi devo però capire la durata del prossimo burst di CPU (ovvero il momento in cui la CPU lavora su un processo). Posso fare delle stime dei burst precedenti di quel processo dato che il burst di un processo è simile ai burst di quelli precedenti.

**CPU Burst**: Durata del tempo da quando il processo riceve la CPU a quando si blocca per I/O o timeout.

Questo sistema è senza quanti di tempo.
$S =$ Stima (do più valore ai valori recenti)

$$S_{n+1} = a S_n + (1-a) T_n$$

- $S_n$: Vecchia stima
- $T_n$: Ultima misurazione

Così la nuova stima considera l'ultima misurazione e la vecchia stima dando un determinato peso a $T_n$ e $S_n$. Il peso viene dato proprio da $a$ che rappresenta una costante $0<a<1$ che in base al suo valore scelto si sceglie se far valere di più la vecchia stima o l'ultima misurazione.
(es $a = 0.5$ in questo caso avrò che $S_n$ e $T_n$  avranno lo stesso peso)

---
##### Altri tipi di Scheduling
- **Scheduling Garantito**: Viene stabilita una percentuale di utilizzo per ogni processo e viene fatta rispettare. Bisogna quindi fare delle promesse ai processi e vedere poi se sono state rispettate. Chi è più indietro con le promesse avrà una percentuale più alta; va a dare la CPU a chi l'ha usata di meno. Non è basato sul quanto di tempo.

- **Scheduling a Lotteria (Gambling)**: Assegno un tot numero di biglietti ai processi, estraggo un biglietto ed eseguo il processo a cui ho assegnato il biglietto. Dopo che lo estraggo brucio il biglietto. Se un processo finisce i biglietti non vedrà più la CPU. Quando i biglietti finiscono si parte da 0. I biglietti chiaramente possono essere assegnati tramite vari criteri (es processi I/O bounded assegno più biglietti rispetto che CPU bounded)

- **Scheduling Fair-Share**: In un sistema multi-utente avrò utenti con pochi processi e utenti con molti. Un sistema Fair Share dovrebbe garantire equità tra gli utenti e non solo tra i processi nei sistemi operativi.
    
    - _Esempio_: Utenti $U_1$, $U_2$. $U_1 = 4$ processi, $U_2 = 1$ processo.

    - Se il sistema è equo sui processi avrò: $U_1$ usa l'80% delle risorse, $U_2$ il 20%.

---

#### Scheduling dei Thread
**Per i thread utente:**
• Sono ignorati dallo scheduler del Kernel. 
• Possibilità di utilizzo di scheduling personalizzato

**Per i thread Kernel:**
• O si considerano i thread tutti uguali 
• O si pesa l’appartenenza a un determinato processo.

---

#### Scheduling su sistemi multicore
(Con multicore intendiamo singola CPU con più core fisici)
###### Approcci di scheduling
Abbiamo diversi modi per fare scheduling su questi tipi di dispositivi:
- *multi-elaborazione asimmetrica*: uno dei processori assume il ruolo di *master* e decide quale processore esegue un certo processo (se abbiamo 8 core 1 fa girare il software dello scheduler e fa solo quello, tutti gli altri fanno girare i processi)
	- *PRO*: Si azzerano i casi di race condition
	- *CONTRO*: Quando un singolo core deve gestire le code per molti di core, questo rallenta e li rallenta tutti
- *multi-elaborazione simmetrica*: coda unificata dei processi pronti o code separate per ogni processore/core
	- *PRO*** 
	  - Nessun collo di bottiglia: Non essendoci un processore "master", il carico di lavoro dello scheduling è distribuito.
	  - Tutti i core partecipano attivamente all'esecuzione dei processi (sia utente che di sistema), senza sprecare risorse dedicando un'intera unità solo alla gestione delle code.
	- *CONTRO*: 
	  - Problemi di race condition
	  - *Cache Affinity*: Se un processo viene sospeso e poi ripreso da un _core diverso_, i dati che aveva salvato nella memoria cache della CPU originaria diventano inutili. Ricaricare i dati dalla memoria centrale alla cache del nuovo core rallenta notevolmente l'esecuzione.

E' quindi importante che un processo riprenda e finisca la sua esecuzione nello stesso core in cui è iniziata, questo per via di come funziona la cache e il prefetching con linee di cache perché se un processo riprende l'esecuzione in un core diverso da quello di partenza si verificano ritardi dovuti all'accesso alla RAM anziché alla cache, ovviamente questo non può sempre accadere, delle volte si avranno core diversi per lo stesso processo. Infatti...

###### Politiche di scheduling
- **Predilezione Debole**: Con questo approccio, il sistema operativo cerca di fare del suo meglio per mantenere un processo sullo stesso processore su cui stava girando in precedenza, proprio per sfruttare un possibile cache hit
- **Predilezione Forte**: In questo caso, vengono impostati dei vincoli stretti. Il sistema operativo (spesso su richiesta esplicita del programmatore o dell'amministratore di sistema) garantisce che un determinato processo venga eseguito **esclusivamente** su uno specifico processore o su un gruppo limitato di processori scelti.
###### Bilanciamento del carico vs. Predilezione
- Il **bilanciamento del carico** spinge per muovere i processi da un core all'altro (migrazione) per assicurarsi che nessun processore rimanga con le mani in mano.
- La **predilezione** spinge per tenere i processi fermi esattamente dove si trovano per massimizzare l'efficienza della memoria.
Queste due politiche "remano contro" l'una all'altra. I sistemi operativi moderni (come Linux) implementano algoritmi molto complessi per trovare un compromesso.

**Migrazione guidata (push)**
Una CPU qualsiasi verifica il carico sulle code del sistema. Se una coda è più piena delle altre, il carico viene distribuito sulle altre.

**Migrazione spontanea (pull)**
Un core con presumibilmente meno-processi può autonomamente avviare un controllo sulle code degli altri core e decidere di prelevare alcuni dei processi per distribuire il carico. Va contro la predilezione, tuttavia può essere integrato un meccanismo di predilezione forte che forzi un core a occuparsi di un determinato processo o insieme di processi.

##### Cosa usano i nostri sistemi operativi
![[Pasted image 20260421161249.png|583]]


----

## **Gestione della memoria centrale**
Nelle memorie abbiamo una certa gerarchia (dalla più veloce alla più lenta), la RAM è il livello più basso che la CPU può direttamente usare:
![[Pasted image 20260422110825.png|379]]

In generale la memoria viene gestita usando degli indirizzi. Nel tempo la gestione degli indirizzi è cambiata:

- **Senza astrazione**: i programmi utilizzano direttamente gli indirizzi fisici, non venivano utilizzate strutture dati complicate quindi questa gestione andava bene, esistono diversi modelli, in base a come erano fisicamente costruiti di dispositivi (anni 60- primi anni 80)
  
  Usare gli indirizzi fisici significa scrivere direttamente nella cella numerata della memoria, se in un programma c'è un'istruzione che dice "salva questo numero all'indirizzo 2000", il processore va _letteralmente_ nella cella di memoria numero 2000 e ci scrive dentro
  ![[Pasted image 20260421165603.png]]

- **Multiprogrammazione senza astrazione**: in questo scenario, più programmi risiedono contemporaneamente nella memoria RAM. Gli indirizzi sono quelli fisici. Questo approccio introduce due problemi critici che devono essere risolti per garantire il corretto funzionamento del sistema:
	1. **Rilocazione (Relocation):** Quando un programmatore scrive un codice, non può sapere in anticipo in quale zona di memoria verrà caricato il programma. Se il codice contiene riferimenti a indirizzi assoluti (es. "vai all'indirizzo 100"), e il programma viene caricato a partire dall'indirizzo 2000, il software fallirà.
	    - **Soluzione statica:** Il _loader_ (il componente che carica il programma) modifica gli indirizzi nel codice al momento del caricamento, sommandovi l'indirizzo di base dove il programma è stato depositato.
	2. **Protezione (Protection):** In un sistema dove più processi convivono senza barriere astratte, c'è il rischio che un processo possa scrivere nell'area di memoria di un altro processo o in quella del Sistema Operativo, causano crash o furto di dati.
	    - **Soluzione (Lock & Key):** Si divide la memoria in blocchi e a ciascuno si assegna una "chiave" (un codice numerico). Il processo può accedere solo ai blocchi la cui chiave corrisponde a quella memorizzata nel suo registro di stato


- **Astrazione dello spazio di indirizzi**: per ogni processo viene specificato lo spazio di indirizzi, utilizzabile da un processo. In pratica viene fatta un'allocazione dinamica che permette ad ogni indirizzo di partire dall'indirizzo 0 rispetto al suo spazio, questo viene fatto usando:
	- *registro base*: contiene l'indirizzo fisico di partenza dove il processo è effettivamente caricato in RAM. Ogni indirizzo generato dal programma (indirizzo logico) viene sommato al valore di questo registro per ottenere l'indirizzo fisico reale. Nei sistemi moderni, questo compito di traduzione da indirizzo logico a fisico è delegato a un'unità dedicata chiamata MMU.
	- *registro limite*: definisce la dimensione massima del processo. Serve a garantire che il processo non acceda a memoria fuori dal suo intervallo consentito. La CPU verifica in tempo reale che l'indirizzo logico sia inferiore al valore nel registro limite. Se il controllo fallisce, viene generata una TRAP che passa il controllo al SO, che terminerà inevitabilmente il processo in questione. 
  Questo modello rappresenta il primo vero passo verso l'isolamento dei processi.

---

#### Swapping
Il livello di multiprogrammazione è limitato dalla dimensione della memoria centrale, da qui nascono diverse soluzioni, la prima di queste è lo *swapping*. Se viene richiesto di creare un nuovo processo ma la memoria centrale è piena, lo swapper (*scheduler di medio termine*) decide quale processo inserire nel disco (SSD o Hard Disk), in modo da liberare la memoria e poter creare il nuovo processo. 

> [!TIP]
> Quando la RAM è piena e il sistema ha bisogno di eseguire un nuovo programma, lo swapper seleziona un processo in memoria che al momento non sta facendo nulla e compie un'operazione di **swap out**, parcheggiandolo temporaneamente su un disco capiente chiamato _backing store_. Lo spazio appena liberato viene subito riutilizzato per un'operazione di **swap in**, prelevando un nuovo processo dal disco e caricandolo nella memoria centrale affinché la CPU possa eseguirlo.

Questa strategia crea delle problematiche, come i problemi delle operazioni di input/output: cosa succede se trasferiamo su disco un processo che stava aspettando la scrittura di un dato da parte dell'hardware? Il rischio è che la periferica finisca per scrivere quel dato nello stesso punto della RAM, ma che ora appartiene a un altro processo, corrompendone i dati. Per evitarlo, il sistema operativo deve ancorare in memoria i programmi impegnati in queste operazioni. 

---

#### Frammentazione interna ed esterna
C'è anche il problema di come allocare lo spazio fisico. Sebbene si possa dividere la memoria in blocchi a **dimensione fissa**, spesso si usa una **dimensione dinamica** che dà a ogni processo l'esatta memoria richiesta. 

Questo però genera il fenomeno della **frammentazione**, dalla quale distinguiamo due casi:
- *interna*: frammentazione interna al blocco assegnato ad un processo
- *esterna*: Man mano che i processi (A, B, C, D) vengono caricati, eseguiti e scaricati, la memoria si riempie di piccoli "buchi" inutilizzati. Col tempo, si arriva a un paradosso: la somma di tutti questi buchi potrebbe bastare per caricare un nuovo programma, ma siccome lo spazio non è contiguo, il sistema non sa dove metterlo. 
  ![[Pasted image 20260421173410.png|635]]

Quando la frammentazione esterna diventa critica entra in gioco la **memory compaction**: il sistema operativo entra in azione riorganizzando fisicamente l'intera RAM: sposta e "schiaccia" tutti i processi verso un'estremità della memoria per fondere tutti i piccoli buchi in un unico grande spazio libero. È una manovra risolutiva, ma molto costosa in termini di prestazioni, poiché blocca temporaneamente l'esecuzione di tutto il resto

---

#### Gestione dell'allocazione
Dopo che il SO ha deciso come gestire la memoria, ha bisogno di uno strumento pratico per farlo. Deve sapere in ogni istante, con precisione, quali parti della RAM sono libere e quali sono occupate. Qui distinguiamo due metodologie:
- La bitmap:
- Lista dei blocchi liberi e occupati:

*Bitmap*
![[Pasted image 20260530143010.png|564]]
Avrà tanti bit quanti sono i blocchi allocati e il valore del bit specifica se quel particolare blocco è allocato oppure noi (allocato si = 1, allocato no = 0).

*Liste dei blocchi liberi occupati*
Ogni elemento della lista (doppiamente concatenata) contiene al suo interno un numero di blocchi e un elemento di tipo P (per processo) o H (per hole, buco). I nodi della lista sono ordinati per indirizzo.


---

#### Memoria Virtuale e Paginazione - soluzione per la frammentazione esterna
La **Memoria Virtuale** è un'astrazione: dà l'idea a noi e al processo che l'allocazione sia contigua e che si disponga di tutta la RAM, in realtà il sistema operativo spezzetta l'allocazione di RAM per quel processo.

Questo meccanismo è la **paginazione**, che fa lavorare il processo in una memoria virtuale con indirizzi da $0$ a un tetto massimo virtuale. Questo elimina l'esigenza di avere una memoria massima o espandibile. In realtà, il pezzo di memoria dedicata al processo è composto da tante pagine della stessa dimensione.

La **memoria fisica** è divisa in blocchi della stessa dimensione della pagina (**Frame**) per facilitare l'assemblaggio della memoria virtuale.
- **Vantaggio:** Questo risolve la frammentazione esterna, perché si andranno ad evitare buchi nella RAM dato che il SO lo riempirà assegnandolo ad un processo.
- **Svantaggio:** Non risolve la frammentazione interna (più la pagina è grande, più ci sarà frammentazione interna).

Per ogni processo tengo in RAM solo alcune pagine, poiché il Sistema Operativo gestisce cosa a un determinato processo non serve in RAM, e il resto sta in disco (swap).
![[Pasted image 20260530143746.png|278]]

> [!info] **Page Fault**
> 
> Avviene quando un processo richiede l'uso di un qualcosa (strutture dati, ecc.) che attualmente si trova in disco e non in RAM. Il processo non sa che parte delle sue pagine sono in disco; se accade un _page fault_ si genera un'**eccezione** per spostare ciò che serve in RAM.

Nelle memorie virtuali abbiamo gli **indirizzi virtuali**. Questi indirizzi vengono mappati in memoria fisica. Ogni processo ha il proprio indirizzo virtuale che punta a un luogo diverso: avrò una **Tabella delle Pagine** per ogni processo che ne segna la mappatura in RAM.

- Grazie a questo metodo si può estrarre l'indirizzo fisico istantaneamente.

- Il **Bit di Presenza** serve a vedere se la pagina è o no in RAM (o in disco). Se è in RAM, devo specificare in che _frame_ si trova questa pagina.

La CPU genera un indirizzo virtuale che deve essere tradotto in indirizzo fisico dalla **MMU** (Memory Management Unit).

**E la frammentazione interna?**
La dimensione prefissata dei frame può causare ancora problemi di frammentazione interna. Sistemi operativi come Solaris gestiscono frame di dimensione variabile, minimizzando il problema. Tuttavia, tra la frammentazione interna e quella esterna, la prima rappresenta il male minore

**I processi sono protetti?**
Si perché ogni processo conosce solo i suoi indirizzi virtuali e al massimo i corrispondenti indirizzi fisici ma non conosce quelli degli altri quindi i processi sono isolati da questo punto di vista.

---
#### Il ruolo della MMU nella Traduzione
*La paginazione è gestita dalla MMU.*
L'MMU per tradurre esegue una divisione:

$$\frac{\text{Indirizzo}_{Virt}}{\text{Dim}} = \begin{cases} Q \rightarrow \text{Numero di Pagina} \\ R \rightarrow \text{Offset} \end{cases}$$
Dove:
- l'indirizzo virtuale è quello che si vuole tradurre in indirizzo fisico.
- La divisione indica il numero in byte della grandezza di ogni singola pagina.
- $Q$ - quoziente - rappresenta il **Numero di Pagina** (Page Number), ovvero in quale pagina specifica "cade" quell'indirizzo.
- $R$ - resto - rappresenta l'**Offset** (o spiazzamento) all'interno di quella specifica pagina, ovvero di quanti byte ti devi spostare dall'inizio della pagina per trovare il dato esatto.
**Esempio:**

Dati $I_V = 8196$ e $\text{Dim} = 4096$:

$$\frac{8196}{4096} = \begin{cases} 2 \text{ (Numero di Pagina)} \\ 4 \text{ (Offset)} \end{cases}$$

> [!info] **Definizione di Offset**
> 
> Distanza dall'inizio della pagina alla _word_ che sto cercando.

Dalla Tabella delle Pagine, associo il Numero di Pagina trovato al Frame. Dopodiché calcolo l'indirizzo fisico:

$$N_{FRAME} \cdot \text{DIM} + \text{OFFSET} = \text{Indirizzo Fisico}$$

---
#### Tabella delle Pagine
La tabella è una per processo e ad ogni record della tabella corrisponde una pagina di un processo. La tabella delle pagine è contenuta in RAM, e gli aspetti da curare sono 2: la velocità di consultazione e la dimensione. La tabella delle pagine è usata dall'MMU per capire quali pagine sono in RAM e quali su disco.

##### Tabella delle Pagine e PTE (Page Table Entry)

> [!info] **Page Table Entry (PTE)**
> 
> Ogni riga della tabella delle pagine è chiamata **PTE**. È il "ponte" che permette al processore di capire a quale indirizzo fisico corrisponda un indirizzo virtuale generato dal programma. Contiene una serie di campi e informazioni fondamentali gestiti in sinergia tra MMU e Sistema Operativo (SO).

 **I Campi di una PTE**

1. **Numero del Frame (Indirizzo Fisico)**
Contiene l'indirizzo fisico di base. Quando la CPU accede a un indirizzo virtuale, prende questo numero e lo concatena all'offset per calcolare l'indirizzo reale in RAM in cui si trova il dato.

2. **Bit Presente / Assente**
Indica se la pagina si trova attualmente in RAM (Frame) oppure se risiede solo su disco. Se assente, un accesso genererà un _Page Fault_.

3. **Bit di Protezione**
Definisce i diritti di accesso per quella specifica pagina: **Lettura**, **Scrittura** ed eventualmente **Esecuzione**.

- **Protezione del Codice:** Lo spazio di memoria virtuale è diviso in _Stack_ , _Heap_ e l'_Area Dati/Codice_. Spesso l'area del codice è di sola lettura. Dato che il codice non si automodifica, più istanze dello stesso programma possono condividere in memoria la stessa area di codice.
- **Perché risiede nella Tabella delle Pagine?** Perché la tabella è letta direttamente dalla **MMU**. La MMU fa da "guardia": se rileva un'operazione non consentita (es. scrittura su codice), blocca tutto e segnala un'eccezione al SO (che di norma termina il processo).
- **Prevenzione attacchi:** Evita tecniche di _Code Injection_, in cui si cerca di inserire codice malevolo in aree destinate ai dati (come Heap o Stack) per poi eseguirlo o per mandare in crash l'applicazione.

3. **Bit di Modifica (Dirty Bit)**
Segnala se la pagina in RAM è stata modificata ("sporca") rispetto alla sua copia originale salvata su disco.

- **Flusso con Page Fault:** 
	1. La CPU cerca una pagina non in RAM $\rightarrow$ si verifica un _Page Fault_.
    2. La pagina viene copiata dal disco alla RAM. La copia su disco non viene cancellata.
    3. All'inizio il Dirty Bit è a **0** (pagina pulita, identica alla copia su disco).
    4. Se il processo effettua una scrittura su quella pagina, la MMU aggiorna il Dirty Bit a **1**.

- **Gestione della "Pagina Vittima":** Quando la RAM è piena e il SO deve fare spazio spostando pagine su disco, usa questo bit per ottimizzare le operazioni:

    - _Dirty Bit = 0:_ Il SO sovrascrive semplicemente il frame in RAM senza copiare nulla su disco (risparmiando un'operazione di I/O molto lenta).
    - _Dirty Bit = 1:_ Il SO è obbligato a salvare le modifiche scrivendo la pagina su disco prima di liberare il frame.

> [!info] A volte il SO approfitta dei momenti in cui non ha operazioni pendenti (inattività della CPU) per sincronizzare le pagine sporche su disco.

5. **Bit di Referenziamento (Bit R)**
Viene impostato a **1** dalla MMU in automatico ogni volta che avviene un accesso alla pagina (sia in lettura che in scrittura).

- **Utilità:** Fornisce una sorta di _microstatistica_ sull'uso delle pagine, a costo quasi nullo per il SO.
- **Come funziona:** Il SO azzera periodicamente questi bit (es. ogni 500 ms). Se alla fine del periodo il bit è a 1, significa che il processo ha usato la pagina recentemente. Monitorando questi cicli, il SO capisce quali pagine sono usate attivamente e quali possono essere scartate in caso di necessità.

6. **Bit per Disabilitare la Cache**
Segnala che la linea di cache corrispondente a quella pagina non deve essere utilizzata, forzando la lettura direttamente dalla RAM (o dalla periferica).

7. **Bit di Validità / Allocazione**
Traccia se una determinata area dello spazio di indirizzamento è stata effettivamente allocata dal SO per il processo.

- **Espansione dinamica:** Anche se le pagine tra Heap e Stack sembrano libere e appartenenti al processo, per usarle (es. allocando vettori con `malloc`) il processo deve chiedere al SO di spostare il limite dell'Heap ("più in alto").

- **Ottimizzazione e Sicurezza:** Il SO deve sapere esattamente quali pagine sono vuote e quali allocate per ottimizzare le dimensioni delle tabelle delle pagine (che altrimenti su sistemi a 64 bit avrebbero dimensioni spropositate, es. $2^{52}$ voci).

- **Segmentation Fault:** Se la MMU rileva un accesso a un indirizzo non allocato dal SO (es. area mai richiesta dal processo), genera un'eccezione come il _Segmentation Fault_, prevenendo comportamenti imprevisti.


> [!info] **Differenza tra FRAME e PAGINA**
> 
> Un Frame corrisponde esattamente ad una pagina, solo che il frame contiene gli indirizzi fisici presenti in RAM, mentre la pagina contiene gli indirizzi logici che vede il processo. Dal punto di vista del processo lui sta lavorando su indirizzi di memoria fisici tutti contigui, ma in realtà ne ha solo l'impressione perché gli indirizzi fisici reali li conosce solo il SO, questo viene fatto per evitare il problema della frammentazione esterna 

##### Possibile esercizio d'Esame
**Input:**
- Memoria Virtuale = 4 MB
- Tabella Pagine = $2^{13}$ Voci $\implies$ Dim. Pagina Fisica = 13 bit
- Numero Frame = 8 bit

**Richiesta:**
Dimensione Memoria Fisica (RAM)?
**Svolgimento:**

Sappiamo che:
$4\text{ MB} = 2^{22}\text{ byte} \implies \text{Dimensione Indirizzo Virtuale} = 22\text{ bit}$

Calcolo dell'Offset:
$\text{Offset} = 22 - 13 = 9\text{ bit} \implies \text{Dimensione Pagina} = 2^9\text{ byte}$

Calcolo della memoria fisica (RAM):
$$2^8 \text{ (N. Frame)} \cdot 2^9 \text{ (Dim. Pagina)} = 2^{17} \text{ byte} = 128\text{ KB} \implies \text{RAM}$$

_Oppure, calcolo alternativo per la dimensione della pagina:_
$$\frac{2^{22}}{2^{13}} = 2^9 \text{ byte}$$

---

#### Tabella dei frame
Il sistema operativo tiene traccia dello stato di occupazione di ogni frame fisico attraverso la tabella dei frame, ogni record è formato in questo modo:
- *stato*: occupato/libero
- *author*: quale processo lo occupa

Questa tabella viene consultata ogni volta che viene creato un processo per creare la sua relativa tabella delle pagine e quando il processo chiede di allocare nuove pagine.

---

#### Progettazione di una tabella delle pagine
Per creare un ottima tabella delle pagine è importante curare i seguenti aspetti:
- *velocità*: la velocità di consultazione 
- *dimensione* in RAM o disco

##### Affrontiamo il problema della velocità
*Soluzione moderna*: tabella interamente residente in RAM con registro **PTBR (Page Table Base Register)** che vive anche esso in RAM - questo registro indica alla MMU quale tabella di paginazione usare in base al processo in esescuzione. In pratica in quel registro troviamo l'indirizzo fisico del primo record della tabella di paginazione. Servono due accessi alla memoria per prelevare il dato (uno al PTBR, uno al dato dopo aver calcolato il suo offset rispetto all'indirizzo PTBR), il context switch però è più veloce.

*La soluzione moderna è ottima, ma pagare due accessi alla RAM non è buono, cerchiamo una strategia migliore:*

**Translation Lookaside Buffer (TLB)**: è una memoria ultra veloce che si frappone tra l'MMU e la RAM, è praticamente una cache per l'MMU, in questa memoria troviamo gli indirizzi fisici delle pagine virtuali più frequentemente richieste dall'MMU alla RAM. 
(è simile quindi ad un prefetch tramite cache per la CPU)

Un programma userà sempre maggiormente una parte ridotta del codice, mettendo in conto questa cosa questo buffer diventa molto utile.

*Di seguito varie specifiche:*
- viene chiamata anche memoria associativa
- ha un numero ridotto di entry (registri interni) tra 64 e 1024, ognuna di queste ha le seguenti voci:
	 - numero di pagina virtuale
	 - bit per validità della voce della TLB: indica se la voce è valida (se contiene dati)
	 - codice di protezione; 
	 - dirty bit: indica se la pagina è stata modificata in RAM rispetto alla versione originale in disco
	 - numero di frame: questo insieme alla prima voce ci permette di trovare l'indirizzo fisico della pagina specificata
- la ricerca viene fatta parallelizzando su tutte le voci.
- essendo molto simile ad una cache abbiamo i concetti di TLB miss e TLB hit
- una volta che una pagina viene liberata dalla RAM il suo rispettivo bit di validità dentro la TLB deve essere modificato
- Ci consente di vincolare alcune pagine alla TLB - è uno strumento che sfrutta il sistema operativo per pagine molto importanti e richieste di frequente
- Quando faccio un context swtich faccio un flush della TLB - la prima ricerca di un processo dopo un flush sarà sempre un miss perché la TLB è vuota. 
  Per evitare il flush (è una perdita di tempo assurda se ci sono sempre gli stessi processi) andiamo ad aggiungere una voce extra detta ASID(address-space identifiers) che identifica il processo dentro la tabella TLB. In pratica adesso la ricerca viene eseguita usando la chiave (page number, ASID).
![[Pasted image 20260428161016.png|553]]
> [!isummary] Riassumendo 
> Quando la CPU ha bisogno di un indirizzo se si ha un TLB hit avrò subito a disposizione pagina e frame del processo e quindi gli indirizzi fisici, se si verifica un TLB miss la CPU dovrà reperire la pagina o in RAM o sul disco

**Quanto impatta l'utilizzo di una TLB?** Di seguito calcoli ci permettono di calcolare il tempo medio (*EAT: Effective access time*)
![[Pasted image 20260428172712.png|600]]
(nel tempo effettivo di TLB miss è 220 perché 20 + 100 per accedere alla RAM e prendere il valore di PTBR e altri 100 per prendere il dato nella giusta locazione di memoria)


##### Affrontiamo il problema della dimensione
Nei sistemi a 32 bit ogni tabella delle pagine pesa 4MB ed è una per processo. Già di per se non è una buona soluzione ma ancora è fattibile da utilizzare, ma nei sistemi a 64 bit il discorso cambia: qui dovremmo avere delle tabelle di 32 PetaByte per ogni processo. Per questo motivo nascono le *tabelle delle pagine multilivello*.

**Tabelle delle pagine multi-livello**
Il PTBR punta alla tabella di primo livello, nella tabella di primo livello troviamo dei gruppi di tabelle delle pagine. In pratica il PTRB punta ad uno dei gruppi. Dentro al record di primo livello troviamo il puntatore ad una tabella di secondo livello. Ci possono essere più livelli ma ad un certo punto si arriverà alla tabella delle pagine normale come la conosciamo.
![[Pasted image 20260428165612.png|500]]
*Vantaggio:* consumo molta meno memoria
*Svantaggio:* facciamo più accessi alla memoria quindi riduciamo la velocità

Per gestire i casi reali con 64 bit il numero di livelli aumenta (almeno 4 o 5 livelli), quindi aumenta il numero di accessi alla RAM, sulla carta questa soluzione non sembra ottima, ma realmente grazie all'utilizzo di diverse TLB lo diventa.

> [!TIP]
> Se le pagine non hanno valore (il bit di validità è a 0) non ha senso gestirle. La struttura multi-livello viene usata solo per le pagine veramente utili 


**Tabella delle pagine invertite**
Questa è un'altra soluzione nella gestione delle pagine in memoria, in pratica al posto di avere una tabella delle pagine enorme, creiamo una tabella dei frame ma con le seguenti voci:
- idprocesso (PID)
- pagina virtuale

questo ci permette di sostituire le $n$ tabelle della pagine usate per ogni processo ad una singola tabella usata per qualsiasi processo, in modo da diminuire la dimensione in RAM, dato che sono più compatte. 
**Come si trova l'indirizzo fisico?**
- La CPU genera un indirizzo logico diviso in tre parti: **pid** (chi è il processo), **p** (pagina virtuale), **d** (offset/spiazzamento).
- Si cerca nella tabella invertita la riga che contiene esattamente quella coppia `(pid, p)`.
- L'**indice `i`** di quella riga (cioè la sua posizione nella tabella) corrisponde esattamente al **numero del frame fisico** nella RAM!
- L'indirizzo fisico finale si ottiene unendo l'indice `i` trovato e l'offset `d`.

**Riassumendo le tabelle invertite**
- **Per tradurre gli indirizzi in RAM:** Si usa **UNA SINGOLA** Tabella delle Pagine Invertita per tutto il sistema. È piccola perché ha una riga sola per ogni frame _fisicamente esistente_ nella RAM (se hai 4GB di RAM, la tabella mappa solo quei 4GB, indipendentemente da quanti processi hai).
- **Per gestire i Page Fault (quando la pagina non è in RAM):** La tabella invertita mappa _solo_ quello che si trova fisicamente in RAM. Se un processo cerca una pagina che è finita sul disco fisso (Swap), la tabella invertita non la troverà. Per questo motivo, il Sistema Operativo deve comunque mantenere salvate (magari su disco) le **tabelle delle pagine classiche (una per processo)** per sapere dove andare a recuperare i dati quando avviene un page fault.

---

#### Cache: Prima o Dopo la MMU?
![[Pasted image 20260601115448.png]]
Il posizionamento della cache rispetto alla MMU determina se il sistema lavora con indirizzi fisici o virtuali, influenzando le prestazioni e la gestione del context-switch.

##### 1. Cache basata su indirizzi fisici (Posizionata dopo la MMU)
In questa configurazione, la cache si trova tra la MMU e la RAM.
- **Funzionamento:** La CPU invia una richiesta alla MMU, che effettua la traduzione da indirizzo virtuale a fisico; solo a questo punto la richiesta arriva alla cache.
- **Vantaggi:** Non è necessario azzerare (invalidare) la cache durante un context-switch. Poiché gli indirizzi fisici sono univoci per l'intero sistema, i dati del processo P1 e del processo P2 possono coesistere nella cache senza ambiguità.
- **Svantaggi:** La traduzione dell'indirizzo da parte della MMU può diventare un collo di bottiglia, rendendo l'accesso ai dati più lento (caching meno efficace in termini di velocità pura).

##### 2. Cache basata su indirizzi virtuali (Posizionata tra CPU e MMU)
In questa configurazione, la cache viene consultata direttamente utilizzando l'indirizzo virtuale generato dalla CPU.
- **Vantaggi:** Maggiore efficacia e velocità, poiché si evita il ritardo della traduzione della MMU in caso di _cache hit_.
- **Svantaggi :** Se non azzerassimo la cache al cambio di processo, P2 potrebbe accedere erroneamente ai dati di P1 (poiché entrambi usano gli stessi indirizzi virtuali locali).
- **Soluzione:** Per evitare l'azzeramento continuo, si utilizzano gli **ASID** (Address Space Identifier).

##### 3. Implementazione pratica.
Nella realtà, si adotta una combinazione delle due strategie per massimizzare le prestazioni:
- **Cache L1:** Solitamente interna alla CPU e basata su **indirizzi virtuali** per garantire la massima velocità.
- **Cache L2 (e successive):** Progettate per lavorare con **indirizzi fisici** (dietro la MMU). Sono più capienti e leggermente più lente della L1, ma non richiedono l'azzeramento al context-switch.

**Il lavoro in parallelo:**
Per ottimizzare i tempi, il sistema non attende l'esito di una componente prima di attivare l'altra:

1. Quando la CPU genera un indirizzo virtuale, inoltra contemporaneamente la richiesta alla **Cache L1** (per un riscontro immediato) e alla **MMU** (per avviare la traduzione). Se la L1 riporta un _cache miss_, la pratica di traduzione per accedere ai livelli successivi è già in corso.
2. **Scrematura tramite Offset:** Mentre la MMU traduce l'indirizzo virtuale in fisico per consultare la **Cache L2**, è possibile iniziare a lavorare. Poiché l'ultima parte dell'indirizzo (l'**offset**) è identica sia nell'indirizzo virtuale che in quello fisico, il sistema può usarla immediatamente per identificare il set di linee potenziali nella cache L2, riducendo i tempi di attesa dell'output finale della MMU.

---

#### Algoritmi di Sostituzione delle Pagine
Quando un processo richiede una pagina non presente in RAM, si verifica un **page fault**. In questo caso, il SO deve intervenire per caricare la pagina mancante dalla memoria secondaria alla memoria principale e aggiornare la tabella delle pagine.

##### Pagina Vittima
Se la RAM è già piena e non ci sono frame liberi per ospitare la nuova pagina, il SO deve scegliere una **pagina vittima** da espellere per fare spazio.
- La gestione della memoria virtuale è affidata al **Sistema Operativo**.
- Ridurre al minimo il numero di page fault futuri, controllando i costi di overhead. La logica è simile a quella delle cache: decidere quale informazione rimuovere penalizzando il meno possibile l'esecuzione.

> [!summary] L'overhead è il lavoro che deve fare la CPU per pianificare/gestire la memoria senza quindi effettuare operazioni per i processi

Vediamo degli algoritmi di sostituzione delle pagine:

##### L'Algoritmo Ottimale (OPT)
L'algoritmo **OPT** rappresenta la soluzione teorica perfetta per la sostituzione delle pagine.

- **funzionamento:** Tra tutte le pagine presenti in memoria, l'algoritmo sceglie come vittima quella che **verrà referenziata nel futuro più lontano**. Se sapessimo che una pagina non verrà consultata per molto tempo (o mai più), rimuoverla sarebbe la scelta ideale perché non genererebbe overhead immediato.
- **Vantaggi:** Garantisce il **costo minimo di overhead** e il minor numero possibile di page fault.
- **Limiti:** È un algoritmo **difficilmente realizzabile** nella pratica, poiché richiede al sistema operativo di prevedere il futuro comportamento del processo, informazione di cui il SO non dispone.
- Viene utilizzato principalmente come **termine di paragone**. Serve a valutare l'efficacia degli altri algoritmi reali confrontando le loro prestazioni con il "massimo teorico" offerto da OPT.

##### Algoritmo NRU (Not Recently Used)
L'algoritmo **NRU** è una soluzione pratica per la sostituzione delle pagine che si basa su statistiche d'uso minime raccolte tramite la tabella delle pagine e raggruppa le pagine in classi.

**I Bit di Stato**
Per funzionare, l'algoritmo utilizza due bit specifici per ogni pagina, solitamente aggiornati direttamente dall'**hardware**:
- **Bit di Referenziamento (R):** viene impostato a **1** ogni volta che la pagina viene consultata (lettura o scrittura). Il Sistema Operativo provvede ad azzerarlo periodicamente per distinguere le pagine usate di recente da quelle vecchie.
- **Bit di Modifica (M):** viene impostato a **1** quando il contenuto della pagina viene scritto (pagina "dirty").

**Classificazione delle Pagine**
L'algoritmo suddivide le pagine presenti in RAM in **4 classi** basate sulla combinazione dei bit R ed M:

|**Classe**|**Stato Bit (R, M)**|**Descrizione**|
|---|---|---|
|**Classe 0**|(0, 0)|Non referenziato, non modificato.|
|**Classe 1**|(0, 1)|Non referenziato, modificato.|
|**Classe 2**|(1, 0)|Referenziato, non modificato.|
|**Classe 3**|(1, 1)|Referenziato, modificato.|

*L'obiettivo è rimuovere una pagina che non sia stata usata recentemente.*

1. Il Sistema Operativo analizza le classi in ordine crescente, dalla **0** alla **3**.
2. Viene scelta una pagina vittima appartenente alla **classe non vuota con il numero più basso**
    - _Es:_ Se ci sono pagine nella Classe 0, se ne sceglie una casualmente tra quelle. Se la Classe 0 è vuota, si passa alla Classe 1, e così via.

Questo permette di eliminare prima le pagine che sono sia "vecchie" (non referenziate) che "pulite" (non modificate), minimizzando l'impatto sulle prestazioni del sistema.


##### Algoritmi FIFO e della Seconda Chance
Questi algoritmi si basano sul concetto di **età della pagina**, ovvero sul tempo trascorso da quando una pagina è stata caricata in RAM![[Pasted image 20260601122312.png|600]]
1. **Algoritmo First-In First-Out (FIFO)**
La logica è quella di una coda semplice: la prima pagina che entra è la prima a uscire.

- Viene rimossa sempre la pagina più vecchia (quella che si trova in "testa" alla coda).
- Basarsi solo sull'ordine di caricamento non è sempre una scelta felice. Una pagina potrebbe essere molto vecchia ma allo stesso tempo **molto usata** dal processo; rimuoverla causerebbe un immediato _page fault_, generando overhead inutile.

2. **Algoritmo della Seconda Chance**
Per migliorare il FIFO, questo algoritmo combina l'ordine temporale con le informazioni tracciate dalla MMU (il **bit di referenziamento R**). L'idea è quella di concedere una "seconda possibilità" alle pagine vecchie che sono state consultate di recente.

**Come funziona:**
1. Il sistema esamina la pagina più vecchia in testa alla coda.
2. **Se il bit di referenziamento R è uguale a 1:**
    - La pagina non viene scartata.
    - Il sistema **azzera il bit R** (lo porta a 0) e sposta la pagina in **fondo alla coda**, trattandola come se fosse stata appena caricata. Questa è la sua "seconda chance".
3. **Se il bit di referenziamento R è uguale a 0:**
    - La pagina viene scartata (vittima) poiché è sia vecchia che non utilizzata di recente.

Questo aggiustamento permette di mantenere in RAM le pagine più importanti anche se sono state caricate molto tempo fa.

##### Algoritmo dell'Orologio (Clock)
L'algoritmo **Clock** rappresenta un'evoluzione dell'algoritmo della Seconda Chance, progettata per essere implementata in modo più efficiente riducendo l'overhead dovuto allo spostamento continuo delle pagine nella coda.

**Struttura e Funzionamento**
Invece di una coda lineare, le pagine vengono organizzate in una **coda circolare** (o lista circolare).
![[Pasted image 20260601122241.png|518]]
- **Il Puntatore:** Un puntatore (simile alla lancetta di un orologio) indica la prossima pagina da esaminare, che rappresenta la "testa" della coda.
- **Logica di Scelta:** Il criterio è identico a quello della Seconda Chance, basato sul **bit di referenziamento (R)**:
    - Quando si verifica un _page fault_, il sistema controlla la pagina indicata dal puntatore.
    - **Se il bit R è a 1:** la pagina riceve una "seconda possibilità". Il bit viene **posto a 0** e il puntatore avanza alla pagina successiva (seguendo il puntatore _next_) senza rimuoverla.
    - **Se il bit R è a 0:** la pagina viene identificata come **vittima** e scartata per fare spazio alla nuova pagina.

A differenza della Seconda Chance classica, non è necessario rimuovere fisicamente la pagina dalla testa per reinserirla in coda; è sufficiente spostare il puntatore e modificare il bit, rendendo l'operazione molto più rapida a livello hardware/software.

##### Algoritmo Least Recently Used (LRU)
L'algoritmo **LRU** si basa sull'osservazione del comportamento passato del processo per cercare di prevedere le necessità future.

L'idea fondamentale è che le pagine usate più di recente hanno un'alta probabilità di essere usate ancora nel prossimo futuro. Al contrario, una pagina che non viene consultata da tempo è probabilmente meno utile e può essere rimossa senza causare overhead immediato.

**Funzionamento**
L'obiettivo è rimuovere la pagina che è stata utilizzata meno di recente. Sebbene sia un'ottima strategia teorica, la sua implementazione pratica è complessa:

- **Contatore**: Per tenere traccia dell'uso, è necessario aggiornare un contatore ogni volta che avviene un accesso alla pagina (lettura o scrittura).
- Una gestione precisa richiederebbe un contatore nella CPU e campi specifici all'interno della tabella delle pagine per memorizzare il valore del tempo di accesso.
- Data la difficoltà di implementazione hardware pura, si ricorre spesso ad algoritmi che approssimano il comportamento LRU via software, come:
    - **NFU (Not Frequently Used)**: basato sulla frequenza d'uso.
    - **Aging**: una tecnica più raffinata che simula il decadimento dell'importanza di una pagina nel tempo.

Mentre il FIFO guarda solo a quando la pagina è stata caricata, l'LRU cerca di fare la scelta migliore guardando a quando la pagina è stata effettivamente consultata l'ultima volta.

##### Algoritmo NFU (Not Frequently Used)
L'idea centrale è associare un **contatore software** a ogni voce della tabella delle pagine.

- **Aggiornamento Periodico**: Il SO esamina periodicamente le pagine.
- **Somma del Bit R**: Prima che il bit di referenziamento (R) venga azzerato, il suo valore (0 o 1) viene sommato al contatore della rispettiva pagina.
- **Significato del valore**: Il contatore diventa quindi un conteggio cumulativo dei cicli di azzeramento in cui la pagina è risultata referenziata.

In caso di page fault, il SO cerca la pagina vittima basandosi sulla frequenza d'uso :
- Viene rimossa la pagina che presenta il **contatore più basso**.
- Si spera che un valore basso indichi una pagina utilizzata meno frequentemente nel tempo.

**Problemi**
Nonostante offra un criterio di scelta, guardare semplicemente al valore più basso può essere fuorviante:

- Il problema principale è che l'algoritmo può "privilegiare" erroneamente pagine che sono state utilizzate intensamente in un passato lontano, ma che ora non servono più.
- Queste pagine manterranno un contatore alto per molto tempo, occupando frame che dovrebbero essere assegnati a pagine usate meno in passato ma fondamentali nel presente (e probabilmente nel prossimo futuro).

##### Algoritmo di Aging
Invece di sommare semplicemente il bit di referenziamento, il sistema esegue un'operazione bit a bit più complessa a ogni scadenza del clock:

- **Shift a destra**: Il contatore di ogni pagina viene spostato di una posizione verso destra, scartando il bit meno significativo.
- **Inserimento del Bit R**: Il bit di referenziamento (R) attuale viene inserito nella posizione più a sinistra, diventando il **bit più significativo**.
- **Aggiornamento**: Questa operazione viene eseguita per ogni pagina sul relativo contatore software.

Il criterio di scelta rimane lo stesso: in caso di page fault, viene rimossa la pagina con il **contatore più piccolo**.

Scegliere il contatore più basso è coerente con la logica dell'algoritmo **NRU** (e LRU) per i seguenti motivi:

- Grazie allo shift a destra, il valore di un vecchio referenziamento diminuisce costantemente di peso a ogni ciclo di clock. Un bit R=1 registrato molti cicli fa varrà molto meno di un bit R=1 appena inserito nella posizione più significativa.
- Una pagina referenziata nell'ultimo ciclo avrà il bit più significativo a 1, risultando in un valore numerico molto alto. Una pagina non usata di recente avrà i bit più significativi a 0, portando a un valore numerico più piccolo.
- Scegliere il valore più piccolo significa identificare la pagina che non è stata referenziata per il maggior numero di cicli recenti, simulando così il comportamento "Not Recently Used" con una precisione più elevata.

In termini di costo, pur richiedendo operazioni di shift, l'Aging rimane una soluzione software efficiente che offre un'ottima approssimazione dell'algoritmo ottimale (OPT).

---

#### Confronto sulle prestazioni
![[Pasted image 20260510162453.png|609]]
Per confrontare l'efficacia dei diversi algoritmi di sostituzione, si utilizza come metrica principale il **numero di fault di pagina**.

##### Page Fault
Il grafico nell'immagine mostra il comportamento atteso del sistema:

- **All'aumentare del numero di frame** disponibili in RAM, il numero di page fault diminuisce progressivamente.
- Idealmente, con un numero di frame sufficiente a ospitare tutte le pagine richieste dal processo, il numero di fault tende a stabilizzarsi o ad azzerarsi (fatta eccezione per i fault iniziali necessari a caricare le pagine per la prima volta).

##### Configurazione del Test
Vengono fissate le seguenti condizioni:
- **Numero di frame:** 3 frame fisici disponibili.
- **Sequenza di accesso:** Una "sequenza compatta" di pagine virtuali: **7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1**.
    - Le ripetizioni consecutive vengono scartate nella sequenza compatta perché non genererebbero nuovi eventi rilevanti per la logica di sostituzione.

##### Applicazione dell'Algoritmo Ottimale (OPT)
L'algoritmo OPT effettua le scelte di sostituzione guardando al **futuro** anziché al passato.

1. **Fase Iniziale (Riempimento):**
    - **Accesso a 7:** La RAM è vuota. Si verifica un page fault e la pagina 7 viene inserita nel primo frame.
    - **Accesso a 0:** Page fault, la pagina 0 occupa il secondo frame.
    - **Accesso a 1:** Page fault, la pagina 1 occupa il terzo frame. Ora la RAM è piena (7, 0, 1).
2. **Sostituzione (Scelta della Vittima):**
    - **Accesso a 2:** Si verifica un page fault. Bisogna scegliere chi eliminare tra 7, 0 e 1.
    - **OPT:** Guardando il futuro della sequenza, la pagina **7** è quella che verrà richiesta più avanti nel tempo rispetto a 0 e 1. Pertanto, la pagina 7 viene scartata e sostituita dalla pagina 2.
    - Ad ogni fault, l'algoritmo analizza la sequenza futura per scartare la pagina il cui prossimo riferimento è il più lontano possibile.

In questo modo e con l'uso dell'algoritmo OPT, si ottengono complessivamente **9 fault di pagina**. Questo valore rappresenta il limite minimo (ottimale) con cui confrontare gli altri algoritmi reali.


![[Pasted image 20260516132824.png|632]]
##### Algoritmo FIFO e Anomalia di Belady
**Il confronto con l'algoritmo OPT**
Garantisce sempre il minor numero possibile di page fault. Tuttavia, FIFO presenta un comportamento che lo rende meno affidabile in certi scenari.

**L'Anomalia di Belady**
Ci si aspetta che all'aumentare della memoria RAM (ovvero dei frame disponibili), il numero di page fault diminuisca. FIFO soffre dell'**Anomalia di Belady**: un fenomeno per cui, aumentando i frame, il numero di fault di pagina può aumentare anziché scendere.

- **1 Frame**: si registrano **12 fault**.
- **2 Frame**: la situazione non cambia, restano **12 fault**.
- **3 Frame**: i fault scendono a **9**.
- **4 Frame**: **anomalia**; invece di scendere ancora, i fault **aumentano a 10**.
Il problema di fondo è che FIFO usa solo l'**età della pagina** come criterio per decidere cosa scartare. Questo non è sempre un parametro sensato: una pagina potrebbe essere in memoria da molto tempo (quindi "vecchia" per FIFO), ma essere usata spessissimo dal programma. Scartarla solo perché è arrivata per prima genera inutili page fault aggiuntivi.


![[Pasted image 20260516132853.png|602]]
##### L'Algoritmo LRU e la Proprietà di Inclusione
A differenza di FIFO, LRU si comporta molto bene anche su sequenze lunghe e **non soffre dell'Anomalia di Belady**.

**La Proprietà di Inclusione**
Il motivo per cui LRU è immune all'anomalia risiede nella **proprietà di inclusione**. Questa proprietà garantisce che, aumentando la memoria, le prestazioni non possano peggiorare.

L'insieme delle pagine caricate avendo $n$ frame è incluso in quello che si avrebbe avendo $n+1$ frame. Se aggiungiamo uno spazio, questo ospiterà una pagina in più senza stravolgere l'ordine di quelle già presenti. LRU guarda a quando le pagine sono state referenziate l'ultima volta; avere più spazio permette solo di mantenere in RAM pagine che prima sarebbero state scartate, senza alterare il pattern di utilizzo.

---

Non tutti gli algoritmi godono di questa proprietà. 
• **NFU e Aging:** Sono considerati approssimazioni di LRU e, per questo motivo, **godono della proprietà di inclusione**. 
• **Second Chance e Clock:** Sebbene cerchino di migliorare la gestione della memoria, hanno un legame stretto con FIFO. In casi limite — ad esempio quando il bit di riferimento R è uguale per tutte le pagine (tutti 0 o tutti 1) — questi algoritmi **collassano su FIFO**, soffrendo dell'Anomalia di Belady. 
• **NRU (Not Recently Used):** Anche questo algoritmo, basato sulla divisione delle pagine in 4 classi, soffre dello stesso problema. Se tutte le pagine finiscono nella stessa configurazione/classe, l'algoritmo si riduce a un semplice FIFO e può presentare l'anomalia.

![[Pasted image 20260516132923.png]]

---

#### Allocazione dei Frame
Il problema è stabilire quanti frame assegnare a ciascun processo per bilanciare l'efficienza del sistema e minimizzare l'overhead causato dai page fault.

• **Minimo Strutturale:** È il numero minimo di frame indispensabile affinché un'istruzione possa essere eseguita. Dipende dall'architettura del set di istruzioni e dai livelli di indirizzamento indiretto. Ad esempio, se un'istruzione occupa più word (pagine diverse) servono frame sufficienti a contenerli tutti contemporaneamente. 
• **Massimo:** Limite deciso dalla quantità totale di memoria libera nel sistema.

**1. Paginazione su Richiesta (Pure Demand Paging)**. In questo scenario, il sistema non assegna preventivamente alcun frame al processo. All'inizio dell'esecuzione, tutte le pagine si trovano sul disco. È l'esecuzione stessa a determinare, tramite i page fault, quali pagine devono essere portate in RAM. Si osserva tipicamente un picco iniziale di page fault che tende poi a scendere verso una situazione di "normalità". Una frequenza troppo alta di page fault è problematica a causa dell'overhead di sistema che comporta.

**2. Strategie**. Non tutti i processi hanno le stesse esigenze. Le strategie principali includono: 
• **Allocazione Equa:** Ogni processo riceve lo stesso numero di frame. 
• **Allocazione Proporzionale:** I frame vengono assegnati in base alla "taglia" (spazio di indirizzamento) del processo. 
	• $a_i = s_i/S\,\,$ x $\,\,m$  , usiamo questa formula per assegnare i frame:
	$a_i$ -> numero di frame
	$s_i$ -> dimensione del processo (spazio di indirizzamento)
	$S$ -> dimensione totale di tutti i processi nel sistema
	$m$ -> numero totale di frame disponibili (RAM libera)
• **Allocazione per Priorità:** I frame vengono distribuiti in base all'importanza del processo piuttosto che alla sua sola dimensione.

---

Queste assegnazioni non sono statiche; devono adattarsi continuamente al livello di **multiprogrammazione.** Un principio fondamentale dell'allocazione riguarda la gestione del page fault: se un processo (es. P3) causa un fault, l'algoritmo di sostituzione dovrebbe idealmente selezionare una pagina da scartare tra quelle già assegnate a quel processo stesso, per evitare di sottrarre risorse ad altri processi, ma questa non è l'unica soluzione.

#### Allocazione Locale e Globale
**Allocazione Locale**: La scelta della "vittima" da scartare ricade solo sulle pagine appartenenti allo stesso processo che ha causato il fault. Il numero di frame assegnati al processo rimane quindi lo stesso.

**Allocazione Globale**: Il sistema può scegliere la vittima tra tutte le pagine presenti in memoria, incluse quelle di altri processi.
In questo caso, un processo può "rubare" un frame a un altro per favorire la propria esecuzione.

Qualunque algoritmo di sostituzione (FIFO, LRU, ecc.) può operare in entrambe le modalità; cambia solo l'insieme di pagine (il set) preso in considerazione.

**Cosa succede se a un processo vengono assegnati troppi pochi frame?**
*Sotto il minimo strutturale*: Il processo non ha abbastanza pagine per eseguire nemmeno una singola istruzione; viene quindi sospeso e spostato su disco (swapping).

*Poco sopra il minimo* (Thrashing): Si verifica il fenomeno del thrashing, una situazione in cui il sistema passa più tempo a scambiare pagine con il disco che a eseguire codice, a causa di un numero eccessivo di page fault.

Se il thrashing si propaga tra i processi a causa di un'allocazione globale gestita male, l'intero sistema va in sovraccarico. Questo accade spesso quando il livello di multiprogrammazione è troppo elevato per la RAM disponibile.

---

#### Il Concetto di Località
Per un sistema ideale, l'allocazione dovrebbe basarsi sulle reali esigenze del processo, concetto strettamente legato alla **località**:
- **Definizione di Località:** 
  È l'insieme di informazioni (istruzioni e dati) necessarie all'esecuzione in una data fase di vita del processo.
- **Dinamicità:** La località muta nel tempo; ad esempio, il codice può passare dalla fase di inizializzazione a un ciclo di elaborazione dati differente.

Se il sistema riuscisse a identificare la dimensione della località attuale, potrebbe assegnare esattamente il numero di frame necessari per ospitarla. Garantire questo spazio permette al processo di lavorare correttamente senza thrashing.

---

#### Working Set
![[Pasted image 20260516133135.png|619]]
Il **Working Set** è un concetto fondamentale per gestire la memoria basandosi sulla **località** di un processo. Si definisce come l'insieme delle pagine referenziate da un processo durante gli ultimi (delta) accessi alla memoria.

• **Delta:** Rappresenta il numero di accessi, considerati per definire la località corrente.

Anche all'interno dello stesso processo, il Working Set non è statico; la sua taglia e il suo contenuto cambiano nel tempo a seconda della fase di esecuzione.

**Gestione del Thrashing** Conoscere il Working Set permette al sistema operativo di monitorare la salute della memoria globale: 
• **Richiesta Globale (D):** Si calcola come la somma delle dimensioni dei working set di tutti i processi attivi. 
• **Prevenzione del Thrashing:** Se la richiesta globale D supera la memoria fisica totale disponibile, il sistema entra in una situazione di sofferenza. Per prevenire il thrashing, il sistema può decidere di sospendere un processo (swapping) finché D non rientra nei limiti della capienza effettiva.

---

Tracciare il working set in maniera puntuale è complesso (simile a quanto accade per l'algoritmo LRU). 
• **Interrupt periodici:** Il sistema controlla lo stato delle pagine a intervalli regolari. 
• **Bit di referenziamento (R):** Si utilizza il bit R per capire se una pagina è stata toccata recentemente. 
• **Log della "storia di R":** Viene conservato uno storico dell'utilizzo dei bit R per ricostruire quali pagine appartengono effettivamente alla finestra Delta stabilita.

---

#### Page Fault Frequency
![[Pasted image 20260516133157.png|632]]
Questo è un altro modello per prevenire il thrashing:
Mentre il _Working Set_ cerca di prevedere di quali pagine un processo avrà bisogno, la **PFF** guarda cosa sta succedendo realmente "sul campo" misurando la frequenza dei page fault.

1. **Il grafico in alto a destra: Controllo Dinamico**
Il concetto fondamentale qui è l'uso di due soglie (limite) per regolare il numero di frame assegnati a un processo:

- **Upper Bound (Soglia superiore):** Se la frequenza dei page fault supera questo limite, significa che il processo sta faticando troppo perché ha pochi frame a disposizione. Il sistema operativo reagisce **aumentando il numero di frame** assegnati a quel processo.
- **Lower Bound (Soglia inferiore):** Se la frequenza scende sotto questo limite, significa che il processo ha fin troppa memoria (più di quanta ne usi realmente). Il sistema operativo può quindi **togliere frame** al processo per darli ad altri che ne hanno più bisogno.
- **Zona centrale:** È l'area di stabilità ottimale.

 2. **Il grafico in basso: Relazione con il Working Set**
Questo grafico mostra la frequenza dei page fault vari nel tempo in relazione alle fasi di esecuzione del programma:

- **I picchi:** Coincidono con l'inizio di una nuova fase del programma (un nuovo _Working Set_). Quando il processo cambia località (ad esempio passa da una funzione di calcolo a una di stampa), ha bisogno di nuove pagine che non sono in RAM, causando un'impennata di page fault.
- **Le valli:** Una volta che le pagine necessarie per la fase attuale sono state caricate in memoria (il _Working Set_ è "stabile"), la frequenza dei page fault crolla quasi a zero.

---

#### Politica di pulitura
Come abbiamo visto, quando una pagina viene portata in RAM, il sistema deve gestire non solo la sua presenza, ma anche il suo stato (come il **bit di modifica)** per ottimizzare le prestazioni.

Il meccanismo di gestione dei page fault è molto più efficiente se il sistema riesce a garantire la presenza di **frame liberi** pronti all'uso. Si aprono quindi due scenari:
1. Esiste almeno un frame libero. La richiesta di caricamento dal disco al frame può procedere immediatamente.
2. Tutti i frame sono occupati. In questo caso, il sistema deve prima liberare un frame (scelta della vittima e eventuale scrittura su disco), rallentando notevolmente l'operazione.

Per rimanere sempre nel "caso migliore", il sistema operativo cerca di mantenere una riserva o un **pool di frame liberi**.

---

#### Il Paging Daemon
Per garantire che ci siano sempre frame disponibili senza aspettare che la memoria si esaurisca, entra in gioco il **paging daemon**.

Un processo di servizio che controlla periodicamente lo stato di occupazione globale della memoria. Utilizza gli algoritmi di sostituzione per selezionare pagine "vittime" (scelte tra i processi che non le stanno utilizzando bene) per "pulirle" (scriverla su disco) e liberare il frame. 

Possibilità di **ripescaggio:** Se un processo richiede una pagina che è stata appena messa nel pool dei liberi ma non ancora sovrascritta, il sistema può recuperarla istantaneamente senza dover accedere al disco, questo perché la vecchia pagina non è ancora stata sovrascritta nella RAM.

---

#### Dimensione della pagina

1. **Vantaggi delle Pagine Grandi**
L'utilizzo di pagine di dimensioni maggiori offre dei vantaggi:

- **Tabelle delle pagine più piccole**: ogni pagina copre una porzione più ampia dello spazio di indirizzamento, sono necessarie meno voci nella tabella, riducendo l'occupazione di memoria della tabella stessa.
- **Efficienza nell'I/O**: Il trasferimento di dati tra disco e RAM è ottimizzato. È più veloce salvare o ripristinare pochi blocchi grandi rispetto a molti blocchi piccoli.
- **Riduzione dei Page Fault**: Tende a minimizzare il numero di fault, poiché ogni caricamento porta in memoria una quantità maggiore di dati correlati, riducendo l'overhead complessivo di gestione.

2. **Vantaggi delle Pagine Piccole**
Le pagine di dimensioni ridotte permettono una gestione più granulare e precisa:

- **Minore frammentazione interna**: Si riduce lo spazio sprecato all'interno dell'ultimo frame assegnato a un processo.
- **Migliore risoluzione del Working Set**: Permette di definire con maggiore precisione quali informazioni sono realmente necessarie in RAM. Con pagine grandi, si rischia di occupare memoria con dati "inutili" che vengono consultati una sola volta ma che devono restare in RAM perché fanno parte di una pagina enorme. Questo si traduce in meno memoria sprecata.

---

#### Pagine condivise
![[Pasted image 20260516133240.png|546]]
Esistono situazioni in cui processi distinti, pur avendo spazi di indirizzamento separati e privati, hanno la necessità di condividere contenuti comuni. Questo avviene mappando diverse pagine virtuali di processi differenti sullo stesso frame di memoria fisica.

**1. Condivisione in Sola Lettura (Codice Rientrante)**
Questo scenario si verifica quando abbiamo istanze multiple dello stesso programma.
Il codice eseguibile può essere condiviso tra i processi P1,P2 e P3, le pagine virtuali ed1, ed2 ed3 di tutti e tre i processi puntano ai medesimi frame fisici (3, 4 e 6).

Ogni processo mantiene comunque il proprio stack e i propri dati privati (es. data 1, data 2), che risiedono in frame fisici separati.

**2. Condivisione in Lettura/Scrittura**
I processi possono chiedere esplicitamente al Sistema Operativo di mappare pezzi di memoria comuni per scambiarsi informazioni.
- **Memoria Condivisa:** Si crea una vera "finestra di comunicazione" tra i processi. Questo è un modello primordiale di comunicazione tra processi.
- In questo caso, i bit di protezione della tabella delle pagine abilitano anche la scrittura, permettendo ai processi di aggiornare i dati in tempo reale per coordinarsi.


- Invece di caricare più copie dello stesso codice in RAM, ne carichiamo solo una, liberando spazio per altre attività.
- Con le pagine condivise è difficile gestire la cache

#### La Tabella delle Pagine Invertita
A differenza delle tabelle standard (che hanno una voce per ogni pagina virtuale), esiste un'unica tabella per tutto il sistema che tiene traccia di cosa contiene ogni singolo frame fisico.

- La tabella contiene una voce per ogni frame della memoria RAM.
- Ogni voce indica quale processo (PID) e quale pagina virtuale specifica sono attualmente ospitati in quel frame.
- Quando la CPU genera un indirizzo virtuale, il sistema deve scansionare la tabella invertita per trovare la coppia (processo, pagina).
    - Se viene trovata una corrispondenza, si ottiene l'indice del frame e si accede alla memoria.
    - Se non c'è corrispondenza, si verifica un **page fault**.
- **Singolo Core**:
    - La tabella deve essere alterata o aggiornata a ogni **context switch** o al verificarsi di un **page fault**, aggiungendo overhead alla gestione del sistema.
- **Multi Core**:
    - La gestione diventa estremamente complessa (difficilmente gestibile).
    - Il problema principale sorge con le **pagine condivise**: poiché la tabella invertita nasce per avere una corrispondenza un frame = un processo, gestire corrispondenze un frame = più processi che lo condividono richiede soluzioni avanzate.


---

#### Ottimizzazioni usate per risparmiare RAM
##### Copy-on-write
E' un ottimizzazione software fatta dal SO che permette di risparmiare memoria in situazioni in cui processi diversi hanno delle pagine che hanno lo stesso contenuto.
Utilizzando la *fork* il processo P1 si clona in P2 (cambia solo il PID il resto è uguale) anziché duplicare le pagine usate dal processo P1 (che sono già in RAM), faccio puntare l'indice delle pagine di P2 a quelle di P1 in questo modo risparmio RAM.
In pratica entrambi i processi accedono alla stessa area di memoria.

**Problema**
Il problema sorge quando un processo vuole modificare una entry della pagina. Ad esempio se P2 modifica anche solo un bit della pagina, questa cambierà anche per P1 (perché usano lo stesso frame in RAM), questo accade perché è il sistema operativo che fa questa ottimizzazione, dal punto di vista dei processi loro hanno dei frame diversi. Quindi questo discorso regge finché le pagine si usano solo in lettura. Se uno dei 2 processi vuole fare una modifica il SO deve gestire questa cosa facendo un duplicato della parte che deve essere cambiata. 
Ad esempio: immaginiamo 3 pagine A, B e C, P2 vuole modificare pagina C e allora il SO duplica la pagina C così che P2 possa cambiare la pagina C e P1 usa la vecchia copia,vedi figura.
![[Pasted image 20260519153106.png|405]]
*Come fa il sistema operativo a sapere che P2 deve effettuare modifiche alla pagina C?*

Il SO per gestire questo problema, modifica artificiosamente la maschera dei permessi di P1 e P2, rendendo le pagine in sola lettura, cosi che se un processo deve scrivere su quelle pagine infrange i permessi e *viene generata una eccezione dalla MMU*, il sistema operativo se ne accorge ma sa che quel processo in realtà non sta facendo niente di male e quindi non lo killa, anzi gli crea la copia che dicevamo prima, essendo quella pagina copiata i permessi possono essere reimpostati (sia per la pagina che usa P1 sia per quella di P2), tanto ormai quella è una normale pagina solo per P2, sto comunque risparmiando RAM perché le pagine A e B sono ancora "condivise".

##### Zero-fill-on-demand
Questa è un altra ottimizzazione per consumare meno RAM e funziona così:
> [!tip] **Premessa: ** Quando ad un processo viene assegnato un frame libero di memoria il sistema operativo prima di riservarlo per lui lo azzera, cioè riempie di 0 tutti i bit di quel frame, questo viene fatto per motivi di sicurezza (magari in quel vecchio frame c'erano dei dati sensibili come password ecc...)

Quando un programma chiede nuova memoria al sistema operativo (ad esempio per l'area **BSS** delle variabili globali non inizializzate o tramite lo **Heap**), il SO non va subito a cercare frame liberi nella RAM per riempirli di zeri. Sarebbe uno spreco di tempo e RAM enorme.
- Il SO tiene sempre da parte un frame di pochi Kbyte sempre azzerato chiamato **zero page**, quindi quando un processo chiede della memoria il SO fa puntare le voci della tabella delle pagine del processo verso questa unica zero page.
- Imposta i permessi in *read only* così che quando un processo vuole scrivere venga generata un eccezione (vedi sotto).
- **Risparmio** -> in questa maniera se 100 processi chiedono 1GB di RAM (senza voler scrivere subito in essa, ma la vogliono riservata) non avrò bisogno di 100 GB di RAM perché farò puntare tutti quei processi alla **zero page**.
- Il problema nasce quando il processo vuole scrivere qualcosa in memoria (che lui crede sua, dal punto di vista del processo lui ha il suo frame di memoria), appena infrange il permesso di read only come per il copy-on-write l'MMU genera una eccezione quindi il processo si ferma (ma anche qui non viene killato perché il SO sa che non faceva nulla di male) e il SO prende un frame dalla sua pool di frame vuoti, lo azzera e fa puntare le pagine a quel o quei frame appena azzerati impostandogli i permessi regolari di lettura/scrittura
- Il processo riprende normalmente la sua esecuzione.

*Questi 2 a tutti gli effetti sono esempi di pagine condivise tra processi*

##### Librerie condivise
I programmi software usano le librerie che sono delle raccolte di funzioni.
Abbiamo 2 modi per includerle nei nostri software:
- **Linking statico**
   -  Il codice della libreria viene copiato e incollato all'interno dell'eseguibile in fase di compilazione e questo avviene per ogni file che compiliamo
   - *Svantaggio* -> se ho tanti programmi che usano la stessa libreria (magari anche una libreria di grandi dimensioni) il codice verrà copiato tante volte quanti sono i programmi quindi avrò uno spreco immenso di spazio su disco e quando li avvio anche sulla RAM
- **Linking dinamico (librerie condivise)**
  - Il programma contiene solo un "riferimento" alla libreria. Il caricamento avviene solo a **run-time** (quando lanci il programma).
  - *Vantaggi* -> La libreria viene caricata in RAM **una sola volta** dal Sistema Operativo. Tutti i processi che ne hanno bisogno punteranno allo stesso frame fisico. Inoltre se la libreria viene aggiornata non serve ricompilare tutti i programmi ma al prossimo avvio useranno direttamente quella aggiornata

##### File mappati in memoria
- **Mappatura:** Il SO riserva un intervallo di indirizzi virtuali nei processi (le pagine 1-6 nel disegno) e li collega logicamente al file sul disco.
- **Demand Paging:** Inizialmente, la RAM è vuota. Quando il Processo A prova a leggere la "pagina 3", avviene un **Page Fault**. Il SO va sul disco, legge il blocco 3 e lo carica in un frame della RAM fisica.
- **Condivisione:** Se ora anche il Processo B vuole leggere la "pagina 3", il SO vede che è già in RAM. Quindi aggiorna la tabella delle pagine del Processo B per farlo puntare allo **stesso frame** usato dal Processo A.
- **Automaticità:** Il sistema gestisce tutto da solo. Se la RAM finisce, il SO può scaricare le pagine non usate riportandole sul disco.
![[Pasted image 20260521113716.png|499]]

---

#### Allocazione della memoria per il kernel
Ci sono grandi differenze in base a come il SO riserva la memoria ai processi utente o al kernel.
- **Memoria Utente:** Viene gestita tramite la **paginazione**. È flessibile, ma soffre di **frammentazione interna**. Se un processo chiede 1 byte, il SO gli dà comunque un'intera pagina (solitamente 4KB), sprecando quasi tutto lo spazio rimanente.
    
- **Memoria Kernel:** Il Kernel non può permettersi questo spreco. Gestisce migliaia di piccole strutture dati (descrittori di processi, semafori) che devono essere create e distrutte continuamente. Inoltre, alcune parti del Kernel hanno bisogno di **pagine fisicamente contigue** (per interagire direttamente con l'hardware) e non possono essere paginate (cioè non possono finire nello swap su disco).

**Slab allocator (soluzione usata su linux)**
- **Slab:** È il blocco di base, composto da una o più **pagine fisicamente contigue** in RAM.
    
- **Cache:** Una cache è un insieme di uno o più Slab. La cosa fondamentale è che **ogni cache contiene solo un tipo di oggetto**. Esiste una cache specifica per i descrittori di processo, una per i file aperti, ecc. Questo garantisce che non ci sia frammentazione: se un oggetto occupa 3KB, la cache viene divisa esattamente in "slot" da 3KB.
    
- **Kernel Objects:** Sono le istanze reali delle strutture dati che il Kernel usa. Quando il Kernel ha bisogno di un nuovo oggetto, non va a chiedere RAM generica, ma va alla cache specifica e prende uno slot libero.
![[Pasted image 20260522150834.png|492]]

*In breve per evitare la frammentazione interna il SO dedica il giusto quantitativo di memoria perché sa che in ogni cache ci sarà sempre lo stesso oggetto che richiederà sempre la stessa memoria, ad esempio sa che in una cache ci saranno solo oggetti riguardanti i file aperti che peseranno tutti 3KB quindi assegna 3KB precisi.*

**Gestione**
Uno slab può trovarsi in 3 stati:
1) Full -> tutti gli slot sono occupati
2) Empty -> tutti gli slot sono liberi
3) Partial -> alcuni slot occupati altri liberi
Il SO se può cerca di riempire gli slab *partial* così da ottimizzare l'uso della memoria.

**Vantaggi**
I vantaggi più importanti sono sicuramente:
- L'assenza della frammentazione interna -> ogni cache è divisa in base al tipo di oggetto che dovrà ospitare
- Velocità -> anziché allocare e deallocare memoria (operazione lenta) per ogni oggetto, semplicemente lo slot all'interno della cache sarà segnato come pieno o come vuoto

> [!warning] la cache che nomino qui non è la cache usata dalla CPU (cache l1,l2,l3) ma è una ottimizzazione software che risiede in RAM

---

## **File System**
La gestione di grandi quantità d’informazioni, in maniera persistente e condivisa tra processi, è l’obiettivo che ci poniamo durante la progettazione di un sistema operativo.
**I File e le Directory sono astrazioni.**
Ogni File System può avere convenzioni diverse da SO a SO, come ad esempio:
- **Nomenclatura**: L'estensione finale e ciò che descrive potrebbe cambiare.
- **Tipi di file**: Potrebbero esserci file di dispositivo speciali che indirizzano una partizione o un canale audio.
	- *(Nota: I primi 2 byte di ogni file rappresentano il tipo di file).*
- **Tipi di accesso**: Come può essere aperto un file.
- **Metadati (Attributi)**: Come la maschera dei permessi, la copia di backup, e vari timestamp per l'ultima modifica o la data di creazione.


**Operazioni su File**
Non esistono solo le operazioni di `read` e `write`. Le directory hanno operazioni varie, e i link di codice hanno operazioni a parte.

> [!warning] Attenzione alla Concorrenza
> Se più processi aprono lo stesso file contemporaneamente, si possono presentare problemi simili alle **Race Condition**.

*Il sistema operativo gestisce l’accesso condiviso ai file tramite dei lock.*
**Lock sui File**
I lock sui file sono gestiti in maniera diversa per prevenire problemi di concorrenza:
- **Lock di tipo Shared (Condiviso)**: Sono lock potenzialmente condivisi, come avviene ad esempio per le operazioni di sola lettura.
- **Lock di tipo Exclusive (Esclusivo)**: Sono lock esclusivi, utilizzati per operazioni come la scrittura.

> [!info] Convenzioni dei SO
> SO diversi hanno convenzioni diverse anche sui lock (alcuni possono non supportare i lock *shared*, ma solo quelli *exclusive*).

**Modalità di applicazione del Lock**
Il lock può essere applicato in modi differenti:

1. **Mandatory Lock (Obbligatorio)**: È il SO ad applicare il lock al processo (blocca le operazioni sui lock esclusivi).
2. **Advisory Lock (Consultivo)**: Il lock viene acquisito o rilasciato dai processi stessi. Un altro processo potrebbe non preoccuparsi di verificare se vi è un lock o meno; potrebbe quindi operare sul file senza sapere se il lock è stato acquisito o meno.

---

#### Partizioni
Il disco di memoria di massa può essere visto come un insieme di blocchi chiamati partizioni. Il file system risiede su ogni partizione di memoria.

![[Pasted image 20260604152436.png]]
Il partizionamento può essere gestito in 2 modi:

**Master boot record**
E' un metodo storico e può gestire al più 4 partizioni diverse e circa 2 TeraByte di spazio, MBR è fondamentale perché contiene le istruzioni necessarie all'avvio del SO e conosce l'inizio e la fine di ogni partizione. Il disco ha quindi in memoria: 
• Al più quattro partizioni. 
• La tabella delle partizioni. 
• Il boot record. E' il primo blocco della memoria, i primi 512 byte, contenente codice di avvio della macchina. Carica il sistema operativo presente nella rispettiva partizione.

Partizionare è utile ad esempio se si vogliono avere più SO all'interno della stessa macchina.
All'interno di ogni partizione abbiamo:
• *Boot block*. Una volta sfruttato per parte del codice di avvio di ciascuno dei sistemi operativi delle partizioni. Il suo utilizzo, che ne spiegava il nome, è ormai inutilizzato. 
• *Superblock*. Contiene dei metadati relativi alla partizioni: specifica il tipo di file system, la dimensione dei cluster. Il resto della partizione sarà gestita in cluster. 
• *Free space management*. Strutture dati che si occupano di gestire lo spazio libero.
• *I-nodes.* 
• *Root directory*. La radice della directory del file system. 
• *File e directories.*


**GPT (Guide Partition Table)**
E' un modello più moderno che elimina certi limiti di dimensione legati a MBR, ad esempio può gestire molto più spazio (fino a 9.4 zettabyte e 128 partizioni massime).

---

#### Implementazione dei file da parte del SO
##### Allocazione contigua
Il modo più semplice e vecchio è l'allocazione contigua. I file così come i processi possono ingrandirsi e quindi occupare più memoria su disco o rimpicciolirsi, dato che è organizzato a blocchi si soffre di frammentazione interna, infatti se ad esempio mi servono 4 blocchi per memorizzare potrebbe succedere di dover arrotondare (magari il 4 blocco è quasi vuoto ma in 3 il file non ci entrava) e in più vanno trovati in maniera contigua su disco (il problema della frammentazione interna in questo caso è praticamente irrisolvibile).
Nell'allocazione contigua è semplice sapere dove si trova un blocco, basta sapere qual è il primo blocco del file e sapere quanti blocchi occupa. 
L'allocazione contigua soffre anche di frammentazione esterna.
![[Pasted image 20260604155354.png]]

> [!warning] Riassumendo
> L'allocazione contigua non è usabile in un sistema molto dinamico che ha bisogno di file che si ingrandiscono e rimpiccioliscono molto spesso

##### Allocazione con liste collegate (non contigua)
La soluzione ottimale dal punto di vista delle prestazioni è avere blocchi contigui in memoria, ma come abbiamo visto questo sistema è insostenibile in sistemi dinamici come quelli moderni, questa soluzione ci permette sia di allocare in maniera contigua che (se serve) allocare in maniera separata su disco.
Si utilizzano delle liste che collegano i vari blocchi del file
![[Pasted image 20260604160349.png|558]]

> [!warning] Il problema della frammentazione interna non si risolve

**Problemi**
Questa soluzione non è perfetta, ci sono 2 principali problemi:
- Il blocco deve essere diviso tra il payload (dati utili) e la parte di gestione della lista (il puntatore al next) e questo può portare a problemi: se ho blocchi da 1KB, 999 byte saranno dati e 1 byte il puntatore, e se devo leggere esattamente un 1KB di dati dal file dovrò leggere 1 blocco e un pezzo del primo, questo porta ad inefficienze dovute alla struttura e complessità della lista.
- *Problema più grave*, se devo leggere un blocco che non è il primo dovrò sempre partire dalla testa della lista e scorrerla tutta fino al nodo che contiene il mio dato (la ricerca nella lista ha complessità $O(n)$ in cui ho quindi $n$ accessi alla memoria e questo da un punto di vista prestazionale è un disastro).

Ci sono altre soluzioni non contigue che sono migliori:

##### Allocazione con liste collegate su una tabella di allocazione dei file (FAT)
L'idea è quella di avere una tabella chiamata FAT e mettergli dentro tutta la parte di gestione della lista (ovvero i puntatori a next e un end-of-file). La tabella FAT ha tante voci quanti sono i blocchi allocabili nel disco. La i-esima voce all'interno della FAT mi dice chi è la prossima riga/blocco. La FAT risiede in RAM.
![[Pasted image 20260604164525.png|282]]
La tabella si legge così, il file A inizia alla riga 4, il next si trova alla riga 7, il next successivo alla riga 2 poi alla 10 poi alla 12 dove trovo -1, quindi so che il file è finito.

> [!info] Le dimensioni della FAT sono legate alla grandezza del disco e alla grandezza del singolo blocco. Se uso blocchi grandi la FAT diventa piccola (e risparmierei RAM) ma c'è un problema: aumento molto la frammentazione interna. 


##### Allocazioni con nodi indice (i-node)
Gli *i-node* sono delle strutture dati associate ad un file. Gli i-node contengono dei metadati come permessi e dimensione (tranne il nome del file che sta nella directory) e le informazioni per tracciare le sequenze dei blocchi che compongono i file.
**Approccio collegato**
La strategia è:
L'i-node è diviso in righe in cui ogni riga mi da la locazione di un nodo nella lista (blocco), se il file è piccolo e entra dentro l'i-node possono eseguire un accesso diretto (controllo direttamente la riga nell'i-node che mi interessa e so dove trovare il blocco).
**Approccio multilivello**
Qui l'i-node può puntare a:
– *Un blocco diretto*: è un blocco effettivo del file. 
– *Un blocco indiretto singolo*: questo, punta a n blocchi del disco. 
– *Un blocco indiretto doppio*: questo, punta a n blocchi indiretti singoli. 
– *Un blocco indiretto triplo*: questo, punta a n blocchi indiretti doppi.
Questo approccio è sconveniente perché se il file è piccolo dovrò fare molti accessi prima di arrivare al blocco di dati, conveniente invece per file grandi
**Approccio ibrido**
Questo approccio mischia i 2 precedenti gestendo sia file piccoli che grandi:
- **Come funziona:** L'i-node contiene sia puntatori diretti (per l'accesso immediato) sia puntatori indiretti a più livelli (singolo, doppio, triplo).
- **Perché è ibrida:** Combina la velocità dell'accesso diretto per i file piccoli (nessun blocco d'indice intermedio da consultare) con la capacità dell'approccio multilivello per i file giganti
![[Pasted image 20260605170914.png|502]]
---

#### Implementazione delle directory
##### Dove vengono inseriti i metadati e attributi?
• In un file system FAT, i metadati sono contenuti all’interno della directory del file. 
• In un file system con i-node, i metadati sono contenuti all’interno della tabella degli i-node, tranne il nome! Il nome sta nella directory.

Tutti gli attributi hanno lunghezza fissa tranne il nome che nei sistemi moderni può essere molto lungo.

**Come gestire in maniera opportuna i nomi**
Ci sono 2 strategie:
• Strategia 1 
- *lunghezza variabile.* Il primo campo del file stabilisce la lunghezza in byte dell’entry, (o del nome, negli i-node). L’unico valore di dimensione variabile è il nome: ponendo il nome come ultimo attributo del file, diventa possibile stabilire quando inizia e quando finisce il nome. A fine nome, è presente un carattere di terminazione
  ![[Pasted image 20260605171449.png|211]]

• Strategia 2 
- *heap, suddivisione tra parte fissata e variabile.* Le parti di dimensione fissa dei record, vengono unificate in una parte di memoria. In questo modo, si evita totalmente la frammentazione esterna. Tra gli attributi, si ha un puntatore al nome del file. Le parti variabili (i nomi) si trovano in una sezione a parte, chiamata heap. Un’accozzaglia di nomi, separati da carattere di terminazione. Separare parte variabile e fissa, permette di facilitarne la gestione.
  ![[Pasted image 20260605171520.png|218]]

---
#### Condivisione di un File System tra utenti
Immaginiamo di voler condividere un file tra due o più utenti.
1. **Duplicare le FAT.**
   l'idea banale è quella di duplicare le tabelle FAT (quindi la lista) per entrambi gli utenti. Il *problema* è che se un utente aggiorna un file e alloca un nuovo blocco l'altro non ne è a conoscenza quindi la sua tabella FAT non si aggiorna e non funziona più.
2. **Usando i-node, gli hard link.** 
   All’interno di un i-node, inseriamo un contatore che tiene traccia degli utenti che hanno accesso al file. Possiamo mettere riferimenti diversi allo stesso file. Non ci sarà l’esigenza di aggiornare i metadati, in quanto questi sono situati proprio dentro l’i-node. Il nome può infatti essere diverso tra i vari utenti! Il vero *problema* (Iniquità della cancellazione): Il File System cancella i dati fisici dal disco solo quando il contatore dei collegamenti (Link Count) nell'i-node scende a 0.
   ![[Pasted image 20260605172438.png|404]]
3. **Soft link.**
   Anziché creare un hard link come prima, si crea un soft link ovvero un riferimento al *path* del file nel disco in questo modo risolviamo molti problemi: non ci sono duplicati, se un utente modifica il file il soft link funziona e il proprietario del file può decidere di eliminarlo senza alcun problema (in questo caso resta il soft link che non porta a niente ma questi link occupano poco spazio).

---
