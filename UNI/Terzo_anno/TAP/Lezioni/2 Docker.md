### **Cosa è Docker:**
**Docker** è una piattaforma open source che permette di impacchettare un'applicazione e tutto ciò di cui ha bisogno per funzionare (codice, librerie, dipendenze, file di configurazione) all'interno di un'unità autonoma e standardizzata chiamata **container**.
![[Pasted image 20261003103607.png|481]]

**A cosa serve?**
Risolve il classico problema dei programmatori: _"Sul mio computer funziona, ma sul server o sul computer del collega no!"_.
Garantisce che il software si comporti esattamente nello stesso modo ovunque venga eseguito: sul computer di sviluppo, su un server in cloud o su macchine con sistemi operativi diversi.

##### I concetti chiave
- **Immagine (Image):** Il modello di sola lettura, simile alla ricetta o al file di installazione dell'applicazione.
- **Container:** L'istanza in esecuzione dell'immagine. È l'ambiente isolato e leggero in cui gira effettivamente il programma.
- **Dockerfile:** Il file di testo con le istruzioni dettagliate per creare l'immagine.

##### Cosa è un container?
Un container è una unita standardizzata di software che contiene il codice e tutte le sue dipendenze (librerie ecc...) cosi le applicazioni possono girare in qualsiasi ambiente


##### Docker vs Macchine Virtuali (VM)
A differenza delle macchine virtuali classiche (come VirtualBox o VMware), i container non emulano un intero sistema operativo:
- **Condividono il kernel del sistema operativo host**, occupando solo pochi megabyte anziché gigabyte.
- **Si avviano in frazioni di secondo**, senza dover caricare un intero sistema operativo da zero.
- **Consumano meno risorse** (RAM e CPU), permettendo di eseguire decine di servizi sullo stesso computer senza rallentarlo.

I container sono un'astrazione a livello di applicazione che raggruppa codice e dipendenze insieme. Più container possono essere eseguiti sulla stessa macchina e condividere il kernel del sistema operativo con altri container, ciascuno dei quali gira come processo isolato nello spazio utente. I container occupano meno spazio rispetto alle VM (le immagini dei container hanno in genere una dimensione di decine di MB)

Le macchine virtuali (VM) sono un'astrazione dell'hardware fisico. L'hypervisor consente a più VM di essere eseguite su un'unica macchina.
Ogni VM include una copia completa di un sistema operativo, l'applicazione, i file binari e le librerie necessarie, occupando decine di GB. Le VM possono inoltre essere lente ad avviarsi.

![[Pasted image 20261003173834.png]]

Possiamo chiaramente intendere che usare i container sia nettamente migliore in termini di utilizzo risorse.

**OCI**
I container sono utili pe tutto quello che abbiamo detto prima, ma c'è una cosa che è fondamentale: **sono uno standard**. Infatti è stato creato il Open Container Initiative (OCI) ovvero uno standard nato per semplificare l'ecosistema dei container ed evitare monopoli o altri problemi. 

- Definisce come deve essere strutturato il file dell'immagine (i layer del filesystem, i metadati, le impostazioni di avvio).
- Definisce le regole con cui il software avvia, gestisce il ciclo di vita (start, stop, pause) e isola un container sul sistema operativo.
- Descrive il protocollo standard con cui le immagini vengono caricate (`push`) e scaricate (`pull`) dai server remoti (i cosiddetti _registry_).

### Approfondiamo Docker
Su Docker le immagini diventano containers quando sono eseguite sul Docker Engine.

![[Pasted image 20261003175438.png]]

- ***Client***
  È l'interfaccia con cui interagiamo noi, tipicamente da terminale (la CLI di Docker).
- ***DOCKER_HOST***
  È la macchina (il tuo PC o un server remoto) su cui gira Docker. Contiene:
   - **Docker daemon (`dockerd`):** Il processo in background che ascolta i comandi del client e gestisce la creazione, l'esecuzione e il monitoraggio di immagini e container.
   - **Images:** Il magazzino locale dove risiedono le immagini scaricate o create (nel disegno si vedono Ubuntu e Redis).
   - **Containers:** Le istanze vive e in esecuzione create a partire da quelle immagini (i container blu con il logo dell'applicazione).
- ***Registry***
  E' un catalogo remoto su internet (es. Docker Hub) che raccoglie e distribuisce immagini preconfigurate

**Ma a cosa serve un container?**
Come vedremo ci sono moltissimi container, ad esempio c'è quello di ubuntu che non contiene un intero kernel ubuntu ma un terminale con privilegi da root o anche la struttura standard delle directory Linux, una shell per interagire, i comandi base di sistema GNU, la libreria C standard di Ubuntu e il gestore pacchetti. *In questo caso cosa me ne faccio di questo container?*
Ad esempio se devo usare lo standard POSIX che non è presente in maniera nativa su windows posso programmare il codice su windows e poi farlo funzionare dentro il container ubuntu.
In pratica è un mini-filesystem Ubuntu pronto per farti installare solo i pacchetti strettamente necessari al tuo progetto.

