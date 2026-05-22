### **Ottimizzazioni usate per risparmiare RAM**
**Copy-on-write**
E' un ottimizzazione software fatta dal SO che permette di risparmiare memoria in situazioni in cui processi diversi hanno delle pagine che hanno lo stesso contenuto.
Utilizzando la *fork* il processo P1 si clona in P2 (cambia solo il PID il resto è uguale) anziché duplicare le pagine usate dal processo P1 (che sono già in RAM), faccio puntare l'indice delle pagine di P2 a quelle di P1 in questo modo risparmio RAM.
In pratica entrambi i processi accedono alla stessa area di memoria.

**Problema**
Il problema sorge quando un processo vuole modificare una entry della pagina. Ad esempio se P2 modifica anche solo un bit della pagina, questa cambierà anche per P1 (perché usano lo stesso frame in RAM), questo accade perché è il sistema operativo che fa questa ottimizzazione, dal punto di vista dei processi loro hanno dei frame diversi. Quindi questo discorso regge finché le pagine si usano solo in lettura. Se uno dei 2 processi vuole fare una modifica il SO deve gestire questa cosa facendo un duplicato della parte che deve essere cambiata. 
Ad esempio: immaginiamo 3 pagine A, B e C, P2 vuole modificare pagina C e allora il SO duplica la pagina C così che P2 possa cambiare la pagina C e P1 usa la vecchia copia,vedi figura.
![[Pasted image 20260519153106.png|405]]
*Come fa il sistema operativo a sapere che P2 deve effettuare modifiche alla pagina C?*

Il SO per gestire questo problema, modifica artificiosamente la maschera dei permessi di P1 e P2, rendendo le pagine in sola lettura, cosi che se un processo deve scrivere su quelle pagine infrange i permessi e *viene generata una eccezione dalla MMU*, il sistema operativo se ne accorge ma sa che quel processo in realtà non sta facendo niente di male e quindi non lo killa, anzi gli crea la copia che dicevamo prima, essendo quella pagina copiata i permessi possono essere reimpostati (sia per la pagina che usa P1 sia per quella di P2), tanto ormai quella è una normale pagina solo per P2, sto comunque risparmiando RAM perché le pagine A e B sono ancora "condivise" 

**Zero-fill-on-demand**
Questa è un altra ottimizzazione per consumare meno RAM e funziona così:
> [!tip] **Premessa: ** Quando ad un processo viene assegnato un frame libero di memoria il sistema operativo prima di riservarlo per lui lo azzera, cioè riempie di 0 tutti i bit di quel frame, questo viene fatto per motivi di sicurezza (magari in quel vecchio frame c'erano dei dati sensibili come password ecc...)

Quando un programma chiede nuova memoria al sistema operativo (ad esempio per l'area **BSS** delle variabili globali non inizializzate o tramite lo **Heap**), il SO non va subito a cercare frame liberi nella RAM per riempirli di zeri. Sarebbe uno spreco di tempo e RAM enorme.
- Il SO tiene sempre da parte un frame di pochi Kbyte sempre azzerato chiamato **zero page**, quindi quando un processo chiede della memoria il SO fa puntare le voci della tabella delle pagine del processo verso questa unica zero page
- Imposta i permessi in *read only* così che quando un processo vuole scrivere venga generata un eccezione (vedi sotto)
- **Risparmio** -> in questa maniera se 100 processi chiedono 1GB di RAM (senza voler scrivere subito in essa, ma la vogliono riservata) non avrò bisogno di 100 GB di RAM perché farò puntare tutti quei processi alla **zero page**
- Il problema nasce quando il processo vuole scrivere qualcosa in memoria (che lui crede sua, dal punto di vista del processo lui ha il suo frame di memoria), appena infrange il permesso di read only come per il copy-on-write l'MMU genera una eccezione quindi il processo si ferma (ma anche qui non viene killato perché il SO sa che non faceva nulla di male) e il SO prende un frame dalla sua pool di frame vuoti, lo azzera e fa puntare le pagine a quel o quei frame appena azzerati impostandogli i permessi regolari di lettura/scrittura
- Il processo riprende normalmente la sua esecuzione



**librerie condivise e file mappati**
*Questi 2 a tutti gli effetti sono esempi di pagine condivise tra processi*
I programmi software usano le librerie che sono delle raccolte di funzioni.
Abbiamo 2 modi per includerle nei nostri software:
- **Linking statico**
   -  Il codice della libreria viene copiato e incollato all'interno dell'eseguibile in fase di compilazione e questo avviene per ogni file che compiliamo
   - *Svantaggio* -> se ho tanti programmi che usano la stessa libreria (magari anche una libreria di grandi dimensioni) il codice verrà copiato tante volte quanti sono i programmi quindi avrò uno spreco immenso di spazio su disco e quando li avvio anche sulla RAM
- **Linking dinamico (librerie condivise)**
  - Il programma contiene solo un "riferimento" alla libreria. Il caricamento avviene solo a **run-time** (quando lanci il programma).
  - *Vantaggi* -> La libreria viene caricata in RAM **una sola volta** dal Sistema Operativo. Tutti i processi che ne hanno bisogno punteranno allo stesso frame fisico. Inoltre se la libreria viene aggiornata non serve ricompilare tutti i programmi ma al prossimo avvio useranno direttamente quella aggiornata

**File mappati in memoria**
- **Mappatura:** Il SO riserva un intervallo di indirizzi virtuali nei processi (le pagine 1-6 nel disegno) e li collega logicamente al file sul disco.
- **Demand Paging:** Inizialmente, la RAM è vuota. Quando il Processo A prova a leggere la "pagina 3", avviene un **Page Fault**. Il SO va sul disco, legge il blocco 3 e lo carica in un frame della RAM fisica.
- **Condivisione:** Se ora anche il Processo B vuole leggere la "pagina 3", il SO vede che è già in RAM. Quindi aggiorna la tabella delle pagine del Processo B per farlo puntare allo **stesso frame** usato dal Processo A.
- **Automaticità:** Il sistema gestisce tutto da solo. Se la RAM finisce, il SO può scaricare le pagine non usate riportandole sul disco.
![[Pasted image 20260521113716.png|499]]


**Allocazione della memoria per il kernel**
Ci sono grandi differenze in base a come il SO riserva la memoria ai processi utente o al kernel.
- **Memoria Utente:** Viene gestita tramite la **paginazione**. È flessibile, ma soffre di **frammentazione interna**. Se un processo chiede 1 byte, il SO gli dà comunque un'intera pagina (solitamente 4KB), sprecando quasi tutto lo spazio rimanente.
    
- **Memoria Kernel:** Il Kernel non può permettersi questo spreco. Gestisce migliaia di piccole strutture dati (descrittori di processi, semafori) che devono essere create e distrutte continuamente. Inoltre, alcune parti del Kernel hanno bisogno di **pagine fisicamente contigue** (per interagire direttamente con l'hardware) e non possono essere paginate (cioè non possono finire nello swap su disco).

**Slab allocator (soluzione usata su linux)**
- **Slab:** È il blocco di base, composto da una o più **pagine fisicamente contigue** in RAM.
    
- **Cache:** Una cache è un insieme di uno o più Slab. La cosa fondamentale è che **ogni cache contiene solo un tipo di oggetto**. Esiste una cache specifica per i descrittori di processo, una per i file aperti, ecc. Questo garantisce che non ci sia frammentazione: se un oggetto occupa 3KB, la cache viene divisa esattamente in "slot" da 3KB.
    
- **Kernel Objects:** Sono le istanze reali delle strutture dati che il Kernel usa. Quando il Kernel ha bisogno di un nuovo oggetto, non va a chiedere RAM generica, ma va alla cache specifica e prende uno slot libero.
![[Pasted image 20260522150834.png|492]]

*In breve per evitare la frammentazione interna il SO dedica il giusto quantitativo di memoria perché sa che in ogni cache ci sarà sempre lo stesso oggetto che richiederà sempre la stessa memoria, ad esempio sa che in una cache ci saranno solo oggetti riguardanti i file aperti che peseranno tutti 3KB quindi assegna 3KB precisi*

**Gestione**
Uno slab può trovarsi in 3 stati:
1) Full -> tutti gli slot sono occupati
2) Empty -> tutti gli slot sono liberi
3) Partial -> alcuni slot occupati altri liberi
Il SO se può cerca di riempire gli slab *partial* così da ottimizzare l'uso della memoria

**Vantaggi**
I vantaggi più importanti sono sicuramente:
- L'assenza della frammentazione interna -> ogni cache è divisa in base al tipo di oggetto che dovrà ospitare
- Velocità -> anziché allocare e deallocare memoria (operazione lenta) per ogni oggetto, semplicemente lo slot all'interno della cache sarà segnato come pieno o come vuoto

> [!warning] la cache che nomino qui non è la cache usata dalla CPU (cache l1,l2,l3) ma è una ottimizzazione software che risiede in RAM

---

### **File System**
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