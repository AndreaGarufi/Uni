
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


##### Allocazioni con nodi indice
**Approccio collegato**
Gli i-node sono delle strutture dati associate ad un file. Gli i-node devono contenere le informazioni per tracciare le sequenze dei blocchi che compongono i file. La loro strategia è:
L'i-node è diviso in righe in cui ogni riga mi da la locazione di un nodo nella lista (blocco), se il file è piccolo e entra dentro l'i-node possono eseguire un accesso diretto (controllo direttamente la riga nell'i-node che mi interessa e so dove trovare il blocco), in alternativa posso estendere l'i-node.
SISTEMARE
**Approccio multilivello**

**Approccio ibrido**

---

#### Implementazione della directory
