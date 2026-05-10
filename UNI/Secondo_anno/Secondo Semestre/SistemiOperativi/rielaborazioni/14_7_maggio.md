
![[Pasted image 20260510162108.png|626]]
### Cache: Prima o Dopo la MMU?

Il posizionamento della cache rispetto alla MMU determina se il sistema lavora con indirizzi fisici o virtuali, influenzando le prestazioni e la gestione del context-switch.

### 1. Cache basata su indirizzi fisici (Posizionata dopo la MMU)

In questa configurazione, la cache si trova tra la MMU e la RAM.

- **Funzionamento:** La CPU invia una richiesta alla MMU, che effettua la traduzione da indirizzo virtuale a fisico; solo a questo punto la richiesta arriva alla cache.
- **Vantaggi:** Non è necessario azzerare (invalidare) la cache durante un context-switch. Poiché gli indirizzi fisici sono univoci per l'intero sistema, i dati del processo P1 e del processo P2 possono coesistere nella cache senza ambiguità.
- **Svantaggi:** La traduzione dell'indirizzo da parte della MMU può diventare un collo di bottiglia, rendendo l'accesso ai dati più lento (caching meno efficace in termini di velocità pura).

### 2. Cache basata su indirizzi virtuali (Posizionata tra CPU e MMU)

In questa configurazione, la cache viene consultata direttamente utilizzando l'indirizzo virtuale generato dalla CPU.

- **Vantaggi:** Maggiore efficacia e velocità, poiché si evita il ritardo della traduzione della MMU in caso di _cache hit_.
- **Svantaggi :** Se non azzerassimo la cache al cambio di processo, P2 potrebbe accedere erroneamente ai dati di P1 (poiché entrambi usano gli stessi indirizzi virtuali locali).
- **Soluzione:** Per evitare l'azzeramento continuo, si utilizzano gli **ASID** (Address Space Identifier). Etichettando ogni linea di cache con l'identificativo del processo, l'hardware può distinguere tra indirizzi virtuali identici appartenenti a processi diversi. Tuttavia, questo sistema ha un costo hardware che aumenta proporzionalmente alla dimensione della cache.

### 3. Implementazione pratica.

Nella realtà, si adotta una combinazione delle due strategie per massimizzare le prestazioni:

- **Cache L1:** Solitamente interna alla CPU e basata su **indirizzi virtuali** per garantire la massima velocità.
- **Cache L2 (e successive):** Progettate per lavorare con **indirizzi fisici** (dietro la MMU). Sono più capienti e leggermente più lente della L1, ma non richiedono l'azzeramento al context-switch.

**Il lavoro in parallelo:**

Per ottimizzare i tempi, il sistema non attende l'esito di una componente prima di attivare l'altra:

1. Quando la CPU genera un indirizzo virtuale, inoltra contemporaneamente la richiesta alla **Cache L1** (per un riscontro immediato) e alla **MMU** (per avviare la traduzione). Se la L1 riporta un _cache miss_, la pratica di traduzione per accedere ai livelli successivi è già in corso.
2. **Scrematura tramite Offset:** Mentre la MMU traduce l'indirizzo virtuale in fisico per consultare la **Cache L2**, è possibile iniziare a lavorare. Poiché l'ultima parte dell'indirizzo (l'**offset**) è identica sia nell'indirizzo virtuale che in quello fisico, il sistema può usarla immediatamente per identificare il set di linee potenziali nella cache L2, riducendo i tempi di attesa dell'output finale della MMU.


![[Pasted image 20260510162150.png|626]]
### Algoritmi di Sostituzione delle Pagine

Quando un processo richiede una pagina non presente in RAM, si verifica un **page fault**. In questo caso, il SO deve intervenire per caricare la pagina mancante dalla memoria secondaria alla memoria principale e aggiornare la tabella delle pagine.

### Pagina Vittima

Se la RAM è già piena e non ci sono frame liberi per ospitare la nuova pagina, il SO deve scegliere una **pagina vittima** da espellere per fare spazio.

- A differenza della cache (gestita dall'hardware), la gestione della memoria virtuale è affidata al **Sistema Operativo**.
- Ridurre al minimo il numero di page fault futuri, controllando i costi di overhead. La logica è simile a quella delle cache: decidere quale informazione rimuovere penalizzando il meno possibile l'esecuzione.

### L'Algoritmo Ottimale (OPT)

L'algoritmo **OPT** rappresenta la soluzione teorica perfetta per la sostituzione delle pagine.

- **funzionamento:** Tra tutte le pagine presenti in memoria, l'algoritmo sceglie come vittima quella che **verrà referenziata nel futuro più lontano**. Se sapessimo che una pagina non verrà consultata per molto tempo (o mai più), rimuoverla sarebbe la scelta ideale perché non genererebbe overhead immediato.
- **Vantaggi:** Garantisce il **costo minimo di overhead** (il minor numero possibile di page fault).
- **Limiti:** È un algoritmo **difficilmente realizzabile** nella pratica, poiché richiede al sistema operativo di prevedere il futuro comportamento del processo, informazione di cui il SO non dispone.
- Viene utilizzato principalmente come **termine di paragone**. Serve a valutare l'efficacia degli altri algoritmi reali confrontando le loro prestazioni con il "massimo teorico" offerto da OPT.


![[Pasted image 20260510162223.png]]

### Algoritmo NRU (Not Recently Used)

L'algoritmo **NRU** è una soluzione pratica per la sostituzione delle pagine che si basa su statistiche d'uso minime raccolte tramite la tabella delle pagine.

### I Bit di Stato

Per funzionare, l'algoritmo utilizza due bit specifici per ogni pagina, solitamente aggiornati direttamente dall'**hardware**:

- **Bit di Referenziamento (R):** viene impostato a **1** ogni volta che la pagina viene consultata (lettura o scrittura). Il Sistema Operativo provvede ad azzerarlo periodicamente per distinguere le pagine usate di recente da quelle vecchie.
- **Bit di Modifica (M):** viene impostato a **1** quando il contenuto della pagina viene scritto (pagina "dirty").

### Classificazione delle Pagine

In caso di _page fault_, l'algoritmo suddivide le pagine presenti in RAM in **4 classi** basate sulla combinazione dei bit R ed M:

|**Classe**|**Stato Bit (R, M)**|**Descrizione**|
|---|---|---|
|**Classe 0**|(0, 0)|Non referenziato, non modificato.|
|**Classe 1**|(0, 1)|Non referenziato, modificato.|
|**Classe 2**|(1, 0)|Referenziato, non modificato.|
|**Classe 3**|(1, 1)|Referenziato, modificato.|

L'obiettivo è rimuovere una pagina che non sia stata usata recentemente.

1. Il Sistema Operativo analizza le classi in ordine crescente, dalla **0** alla **3**.
2. Viene scelta una pagina vittima appartenente alla **classe non vuota con il numero più basso**.
    - _Es:_ Se ci sono pagine nella Classe 0, se ne sceglie una casualmente tra quelle. Se la Classe 0 è vuota, si passa alla Classe 1, e così via.

Questo permette di eliminare prima le pagine che sono sia "vecchie" (non referenziate) che "pulite" (non modificate), minimizzando l'impatto sulle prestazioni del sistema.

![[Pasted image 20260510162253.png]]

### Algoritmi FIFO e della Seconda Chance

Questi algoritmi si basano sul concetto di **età della pagina**, ovvero sul tempo trascorso da quando una pagina è stata caricata in RAM.

### 1. Algoritmo First-In First-Out (FIFO)

La logica è quella di una coda semplice: la prima pagina che entra è la prima a uscire.

- Viene rimossa sempre la pagina più vecchia (quella che si trova in "testa" alla coda).
- Basarsi solo sull'ordine di caricamento non è sempre una scelta felice. Una pagina potrebbe essere molto vecchia ma allo stesso tempo **molto usata** dal processo; rimuoverla causerebbe un immediato _page fault_, generando overhead inutile.

### 2. Algoritmo della Seconda Chance

Per migliorare il FIFO, questo algoritmo combina l'ordine temporale con le informazioni tracciate dalla MMU (il **bit di referenziamento R**). L'idea è quella di concedere una "seconda possibilità" alle pagine vecchie che sono state consultate di recente.

**Come funziona:**

1. Il sistema esamina la pagina più vecchia in testa alla coda.
2. **Se il bit di referenziamento R è uguale a 1:**
    - La pagina non viene scartata.
    - Il sistema **azzera il bit R** (lo porta a 0) e sposta la pagina in **fondo alla coda**, trattandola come se fosse stata appena caricata. Questa è la sua "seconda chance".
3. **Se il bit di referenziamento R è uguale a 0:**
    - La pagina viene scartata (vittima) poiché è sia vecchia che non utilizzata di recente.

**Esempio:**

- La pagina **A** è la più vecchia (caricata al tempo 0).
- Invece di rimuoverla subito come farebbe il FIFO , il sistema controlla il suo bit R.
- Se R=1, **A** viene spostata alla fine della coda e il suo bit R viene azzerato. La ricerca della vittima prosegue quindi con la pagina **B**.

Questo aggiustamento permette di mantenere in RAM le pagine più importanti (frequentemente accedute) anche se sono state caricate molto tempo fa.


![[Pasted image 20260510162316.png]]

### Algoritmo dell'Orologio (Clock)

L'algoritmo **Clock** rappresenta un'evoluzione dell'algoritmo della Seconda Chance, progettata per essere implementata in modo più efficiente riducendo l'overhead dovuto allo spostamento continuo delle pagine nella coda.

### Struttura e Funzionamento

Invece di una coda lineare, le pagine vengono organizzate in una **coda circolare** (o lista circolare).

- **Il Puntatore:** Un puntatore (simile alla lancetta di un orologio) indica la prossima pagina da esaminare, che rappresenta la "testa" della coda.
- **Logica di Scelta:** Il criterio è identico a quello della Seconda Chance, basato sul **bit di referenziamento (R)**:
    - Quando si verifica un _page fault_, il sistema controlla la pagina indicata dal puntatore.
    - **Se il bit R è a 1:** la pagina riceve una "seconda possibilità". Il bit viene **posto a 0** e il puntatore avanza alla pagina successiva (seguendo il puntatore _next_) senza rimuoverla.
    - **Se il bit R è a 0:** la pagina viene identificata come **vittima** e scartata per fare spazio alla nuova pagina.

A differenza della Seconda Chance classica, non è necessario rimuovere fisicamente la pagina dalla testa per reinserirla in coda; è sufficiente spostare il puntatore e modificare il bit, rendendo l'operazione molto più rapida a livello hardware/software.

### Esempio

Nell'immagine, il puntatore "next victim" punta a una pagina con bit R=1. Secondo la logica dell'algoritmo, quel bit viene azzerato (portato a 0) e il puntatore scorre verso il basso finché non incontra la prima pagina che ha già il bit R=0, che sarà effettivamente rimossa.


![[Pasted image 20260510162336.png]]

### Algoritmo Least Recently Used (LRU)

L'algoritmo **LRU** si basa sull'osservazione del comportamento passato del processo per cercare di prevedere le necessità future.

L'idea fondamentale è che le pagine usate più di recente hanno un'alta probabilità di essere usate ancora nel prossimo futuro. Al contrario, una pagina che non viene consultata da tempo è probabilmente meno utile e può essere rimossa senza causare overhead immediato.

### Funzionamento

L'obiettivo è rimuovere la pagina che è stata utilizzata meno di recente. Sebbene sia un'ottima strategia teorica, la sua implementazione pratica è complessa:

- **Contatore**: Per tenere traccia dell'uso, è necessario aggiornare un contatore ogni volta che avviene un accesso alla pagina (lettura o scrittura).
- Una gestione precisa richiederebbe un contatore nella CPU e campi specifici all'interno della tabella delle pagine per memorizzare il valore del tempo di accesso.
- Data la difficoltà di implementazione hardware pura, si ricorre spesso ad algoritmi che approssimano il comportamento LRU via software, come:
    - **NFU (Not Frequently Used)**: basato sulla frequenza d'uso.
    - **Aging**: una tecnica più raffinata che simula il decadimento dell'importanza di una pagina nel tempo.

Mentre il FIFO guarda solo a quando la pagina è stata caricata, l'LRU cerca di fare la scelta migliore guardando a quando la pagina è stata effettivamente consultata l'ultima volta.


![[Pasted image 20260510162404.png]]
### Algoritmo NFU (Not Frequently Used)

### Funzionamento del Contatore

L'idea centrale è associare un **contatore software** a ogni voce della tabella delle pagine.

- **Aggiornamento Periodico**: Il SO esamina periodicamente le pagine.
- **Somma del Bit R**: Prima che il bit di referenziamento (R) venga azzerato, il suo valore (0 o 1) viene sommato al contatore della rispettiva pagina.
- **Significato del valore**: Il contatore diventa quindi un conteggio cumulativo dei cicli di azzeramento in cui la pagina è risultata referenziata.

In caso di page fault, il SO cerca la pagina vittima basandosi sulla frequenza d'uso :

- Viene rimossa la pagina che presenta il **contatore più basso**.
- Si spera che un valore basso indichi una pagina utilizzata meno frequentemente nel tempo.

### Problemi

Nonostante offra un criterio di scelta, guardare semplicemente al valore più basso può essere fuorviante:

- Il problema principale è che l'algoritmo può "privilegiare" erroneamente pagine che sono state utilizzate intensamente in un passato lontano, ma che ora non servono più.
- Queste pagine manterranno un contatore alto per molto tempo, occupando frame che dovrebbero essere assegnati a pagine usate meno in passato ma fondamentali nel presente (e probabilmente nel prossimo futuro).


![[Pasted image 20260510162434.png]]

### Algoritmo di Aging

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


![[Pasted image 20260510162453.png]]

### Prestazioni

Per confrontare l'efficacia dei diversi algoritmi di sostituzione, si utilizza come metrica principale il **numero di fault di pagina**.

### Page Fault

Il grafico nell'immagine mostra il comportamento atteso del sistema:

- **All'aumentare del numero di frame** disponibili in RAM, il numero di page fault diminuisce progressivamente.
- Idealmente, con un numero di frame sufficiente a ospitare tutte le pagine richieste dal processo, il numero di fault tende a stabilizzarsi o ad azzerarsi (fatta eccezione per i fault iniziali necessari a caricare le pagine per la prima volta).

### Configurazione del Test

Vengono fissate le seguenti condizioni:

- **Numero di frame:** 3 frame fisici disponibili.
- **Sequenza di accesso:** Una "sequenza compatta" di pagine virtuali: **7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1**.
    - Le ripetizioni consecutive vengono scartate nella sequenza compatta perché non genererebbero nuovi eventi rilevanti per la logica di sostituzione.

### Applicazione dell'Algoritmo Ottimale (OPT)

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
