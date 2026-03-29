Siamo passati al livello network [[4_Network_N.pdf]]

Possiamo immaginare la rete di connessioni tra dispositivi e tra router come un grafo in cui ogni nodo consiste in un router

**Definizioni:**
- *Routing* -> il processo di selezione e definizione di cammini per i pacchetti all'interno o tra reti.
- *Forwarding* -> Consiste nell'inoltro effettivo dei pacchetti

![[Pasted image 20260329171022.png|291]]

Un router ci instrada al router successivo, ad ogni nodo del grafo il router ci indica qual è la strada migliore per raggiungere il router (nodo) successivo

**Dividiamo il network layer in:**
- **data plane**: questo è il responsabile del vero e proprio forwarding dei pacchetti
- **control plane**: è il responsabile dell'instradamento reale dei pacchetti

In pratica quindi il data plane spedisce i pacchetti mentre il control plane li "guida" cercando il percorso migliore


**Esistono diversi modi per fare routing:**
- **Traditional Routing Algorithms**: Effettuato dai singoli router senza una visibilità globale
  *Come funziona:*
  I router "chiacchierano" tra loro usando protocolli di routing. Si scambiano informazioni su chi sono i loro vicini e su quali reti riescono a raggiungere. Unendo tutte queste informazioni parziali, ogni router si costruisce faticosamente la sua visione della rete e compila la propria tabella di routing.
  
  - *Pro:* È **estremamente resiliente**. Se un router si guasta o un cavo viene tranciato, i router vicini se ne accorgono, si scambiano nuove informazioni e calcolano percorsi alternativi. Non essendoci un server centrale, non c'è un singolo punto di vulnerabilità (_Single Point of Failure_).
  - *Contro*: Gestire reti enormi diventa complesso. Se devi cambiare una policy di rete (es. "blocca tutto il traffico in arrivo da questo IP"), devi spesso configurare i router uno per uno. Inoltre, i router devono avere CPU e memoria potenti per calcolare i percorsi continuamente.

- **Software Defined Network**: è un architettura centralizzata esterna che sa tutto della rete
  *Come funziona:*
  I router fisici o gli switch diventano dei semplici "inoltratori" di pacchetti (molto economici e veloci). A comandare è un server esterno e centralizzato chiamato **SDN Controller**. Questo controller ha una visione globale e in tempo reale di _tutta_ la rete e dice ai vari router cosa fare, programmando le loro tabelle di inoltro.
- *Pro*: **Programmabilità e agilità**. Puoi cambiare il comportamento dell'intera rete con pochi clic o tramite un software centrale, senza toccare i singoli apparati. È ideale per i grandi data center dove la flessibilità è tutto.
- *Contro*: Il controller è il "tallone d'Achille". Se il controller va offline (e non ci sono sistemi di backup robusti), l'intera rete diventa "stupida" e smette di instradare nuovi flussi di traffico. Inoltre, c'è bisogno di una connessione sicura e costante tra i router e il controller.
  
- **Virtual Circuit Service**: quando due peer devono comunicare in modo diretto si costruisce un circuito virtuale, l'inoltro dei pacchetti avviene usando questo circuito diretto. Un qualsiasi malfunzionamento tra i router implica una *riconnessione da zero*
  *Come funziona:*
  Prima di inviare anche un solo bit di dati, i due nodi devono instaurare una connessione (Fase di _Setup_). I router lungo il percorso si accordano e prenotano le risorse creando un "tubo" virtuale (il circuito). A questo circuito viene assegnato un identificativo. Quando iniziano a viaggiare i pacchetti, questi non usano più l'indirizzo IP di destinazione completo, ma solo l'identificativo del circuito.

- *Pro*: **Garanzia delle prestazioni (QoS - Quality of Service)**. Poiché le risorse sono prenotate, i ritardi sono prevedibili e i pacchetti arrivano esattamente nello stesso ordine in cui sono partiti.
- *Contro*: E' **fragile**. Se un router in mezzo al percorso si guasta, l'intero circuito crolla. I pacchetti in volo vengono persi e i nodi devono ricominciare la fase di _Setup_ da capo per costruire un nuovo circuito.

Le garanzie in termini di reliability sono affidate al livello trasporto, tramite i meccanismi vari di TCP, con una larghezza di banda sufficientemente grande, le applicazioni funzionano piuttosto bene.

**Router**
I router sono sicuramente i dispositivi più responsabili dell'instradamento e dell'inoltro, sono formati da diversi componenti. In un router, mentre il processo d’instradamento è principalmente software, le porte di ingresso, di uscita e le strutture di commutazione, sono gestite da hardware dedicato. In questo modo, è possibile ottenere le performance richieste dalla rete, operando in lassi temporali dell’ordine dei millisecondi.

