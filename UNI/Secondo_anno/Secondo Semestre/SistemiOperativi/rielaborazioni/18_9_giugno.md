#### Gestione dei blocchi liberi 
Anche per il file system è importante gestire i blocchi liberi in memoria, abbiamo 2 modalità:
- *Bitmap*
  Relativamente piccola, è conservata nel disco, ma può essere portata in RAM a fine di velocizzarne l’utilizzo. La *bitmap non è altro che un array di bit* in cui il valore di ciascun bit mappa direttamente lo stato del blocco corrispondente: 0 vuoto, 1 pieno.
- *Liste concatenate*
  Un’enorme lista concatenata di nodi contenenti indirizzi a blocchi liberi. Richiede più spazio, ma la struttura è unificata, sfrutta blocchi liberi in memoria. E' interessante osservare come la lista dei blocchi liberi si accorcia quando vengono utilizzati blocchi. Un blocco viene sottratto? La lista viene accorciata, liberando spazio sul disco.

---
#### Controlli di consistenza
Crash di sistema e problemi a livello hardware possono creare incoerenze all'interno del file system e lavorare su un file system incoerente può causare molti danni (come ad esempio la scrittura su blocchi allocati anziché quelli liberi ecc...), vediamo delle strategie per individuare le incongruenze.

- Possiamo effettuare dei *controlli sui blocchi* confrontando la bitmap con i blocchi effettivamente allocati, se ci sono delle incongruenze le troviamo.
- Possiamo effettuare dei *controlli sui riferimenti agli i-node*, dentro ogni i-node è presente un campo contenente il numero di riferimenti ad esso. Il controllo di consistenza scorrerà l’intero albero del file system tenendo conto dei riferimenti di ogni i-node. 
	  • Se il numero di volte in cui un i-node è stato individuato nel file system è zero, il contatore deve essere a zero, e quindi l’i-node non è ancora stato allocato. 
	  • Altrimenti, il numero di riferimenti deve coincidere con quello contato.

---
#### Journaling
L’idea è la seguente: un file system qualsiasi può essere corredato con un journal, un log. Il log tiene conto di tutte le operazioni sui meta-dati (ovvero prima di fare qualsiasi modifica, scrive nel log quello che vuole fare). In caso di ripristino a seguito di un crash si ripetono tutte le operazioni contenute nel file di log.
Quando crei, elimini o sposti un file, il sistema operativo deve fare diverse operazioni atomiche (ovvero che devono riuscire tutte o nessuna). Per esempio, per scrivere un file occorre:
1. Trovare un blocco libero nella bitmap (o lista).
2. Aggiornare l'i-node del file con i nuovi puntatori.
3. Scrivere i dati nel blocco.

Se il computer subisce un crash a metà del punto 2, il file system si trova in uno **stato inconsistente**. Senza journal, al riavvio il sistema deve scansionare l'_intero_ disco alla ricerca di incongruenze. Su dischi moderni da diversi Terabyte, questo processo richiederebbe ore ma, usando il journal (log), può vedere quali operazioni sono state fatte e riprende/sistema da li.

---
#### Cache sul disco
Per migliorare le prestazioni dei dischi si usa una cache del disco. La cache del disco contiene i dati che sono stati letti di recente e, in alcuni casi, aree di dati adiacenti a cui è probabile che si acceda in seguito (un po' come il prefetching cache per la CPU). E' una soluzione totalmente software, infatti questa cache è in realtà una piccola zona della RAM libera (anche se nelle moderne memorie di massa spesso è presente una piccola cache fisica che si occupa di questo).

Il sistema operativo per gestire questa "cache" implementa una tabella hash (che ha complessità bassa dato il suo funzionamento) applicando il meccanismo di *LRU -> least recently used* per spostare i dati che non servono via dalla cache in modo da fare spazio ad altri dati più utili.
![[Pasted image 20260610200411.png|496]]

---
#### Scheduling del disco
Serve alla gestione della coda delle richieste di I/O su disco. Si può mandare al controller del disco solo una richiesta alla volta. Il nostro obiettivo è massimizzare il numero di richieste in unità di tempo (throughput), minimizzando il tempo medio d’accesso. Ogni richiesta ha un costo: questo dipende da varie circostanze. Per questo motivo, si possono stabilire delle politiche di selezione per la prossima richiesta da effettuare.
- *FIFO*
- *Tempo di posizionamento*
- *Latenza di rotazione*

Vedremo varie politiche di scheduling su uno specifico esempio:
- lista delle richieste in ordine di arrivo e per # di cilindro: 98, 183, 37, 122, 14, 124, 65, 67 
- posizione iniziale della testina: cilindro 53

> [!example] **Cos'è un cilindro e come funziona la richiesta**
Immagina un disco fisso come una pila di vinili che girano velocemente. Ogni "vinile" (piatto) è suddiviso in cerchi concentrici chiamati **tracce**. L'insieme delle tracce che si trovano alla stessa identica distanza dal centro su tutti i piatti sovrapposti forma un **cilindro**. Per leggere un dato, il braccio meccanico del disco deve spostare la sua **testina** verso l'interno o verso l'esterno, posizionandosi esattamente sopra il cilindro corretto.
Quando un programma (o più programmi contemporaneamente) chiede di leggere dei file, il sistema operativo traduce queste richieste in una lista di cilindri da raggiungere.
Nel nostro esempio: La testina al momento si trova ferma sul **cilindro 53**.
C'è una coda di processi in attesa. Una richiesta vuole un dato sul **cilindro 98**, un'altra sul **cilindro 183**, un'altra ancora sul **cilindro 37**, e così via

L'obbiettivo è quindi quello di muovere la testina per meno millimetri possibili in modo da ridurre il *seek time* 

##### Algoritmo FIFO
Con l'algoritmo FIFO abbiamo questo scenario:
![[Pasted image 20260610214748.png|547]]
$(98 − 53) + (183 − 98) + (183 − 37) + (122 − 37) + (122 − 14) + (124 − 14) + (124 − 65) + (67 − 65) = 640$ 
Vengono percorse 640 tracce, è un algoritmo equo ma poco efficiente.

##### Algoritmo SSTF - Shortest Seek Time First
![[Pasted image 20260610215043.png|536]]
Effettuando il calcolo escono fuori 236 tracce, in pratica si muove scegliendo il numero "più vicino" per fare meno spostamento possibile.
E' efficiente ma non è equo (starvation).

##### Scheduling per scansione
Mantiene un verso fino all’ultima richiesta in tale direzione. Le richieste sono soddisfatte o da sinistra verso destra, o da destra verso sinistra, fino a quando non ci sono richieste da poter soddisfare nel verso stabilito.
![[Pasted image 20260610215332.png|514]]
Qui abbiamo 299 tracce quindi più di SSTF ma gestisce meglio il problema della starvation.

##### Scheduling per scansione circolare
Considera le posizioni come collegate in modo circolare. Arrivato a fine disco (ovvero all’ultima richiesta soddisfacibile dal verso corrente), la testina si sposta alla richiesta più lontana dal verso opposto, ignorando qualsiasi richiesta pendente. E' uno spostamento molto veloce.
![[Pasted image 20260610215538.png|505]]Con questa sorta di effetto pac-man, si abbassa il tempo di attesa medio, in attesa di tante richieste. Il ritorno indietro è molto veloce, minimizzando il tempo di attesa nei casi peggiori.

> [!summary]
> • In situazioni ad alto carico, il sistema circolare è il migliore. 
> • A basso-medio carico, si preferisce SSTF o la scansione standard.

![[Pasted image 20260610215732.png]]

