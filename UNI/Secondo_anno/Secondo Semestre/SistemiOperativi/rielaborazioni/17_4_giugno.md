
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
• *Rood directory*. La radice della directory del file system. 
• *File e directories.*


**GPT (Guide Partition Table)**
E' un modello più moderno che elimina certi limiti di dimensione legati a MBR.

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

