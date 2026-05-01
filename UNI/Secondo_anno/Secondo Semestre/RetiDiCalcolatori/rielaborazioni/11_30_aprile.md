Continuo [[10_23_aprile.pdf]]

**Sistemi centralizzati e decentralizzati**
Nei sistemi che usano il distance vectors, ogni nodo è indipendente e pari rispetto agli altri, si dice che è un *sistema decentralizzato*. Al contrario, un *sistema centralizzato* è più semplice da gestire perché c'è un singolo nodo che comanda/gestisce tutti gli altri ma se questo nodo "capo" viene a mancare per un guasto o un attacco, la rete non funzionerà più bene. Nei sistemi decentralizzati (come quelli che implementano il distance vectors) ogni nodo conosce solo i suoi vicini diretti e conosce le informazioni che questi gli passano (cioè il vettore delle distanze)

**Problema del Distance Vectors**
Uno dei problemi più importanti del distance vectors è che le false notizie si propagano dato che il nodo conosce le informazioni che i suoi vicini gli passano, ma se quelle informazioni sono false verranno prese per vere

**RIP e problema della distanza**
Il protocollo di distance vectors è stato implementato nel protocollo RIP, in cui la distanza veniva misurata attraverso i salti (hop), 1 distanza = 1 hop, senza tener conto della distanza fisica nella realtà o della larghezza di banda di quel collegamento 
Esempio: potrebbero esserci 2 router che hanno stessa distanza per il nodo (1 hop) ma uno si trova a 1 km l'altro a 10 metri.


**Protocollo LINK STATE ROUTING**
LSR ha sostituito il protocollo RIP.
Questo protocollo usa un idea diversa (nel distance vectors si usava Bellman-Ford), qui si usa l'algoritmo di Dijkstra.
L'obbietti di questo protocollo è avere una conoscenza completa della rete da parte di ogni nodo. Infatti qui ogni router investiga sui suoi vicini e poi manda le informazioni in multicast (quindi solo ai router) in modo che tutti possano conoscersi e determinare la via con minor costo. Il calcolo del percorso ottimale è basato sull'algoritmo di Dijkstra

LSR periodicamente manda dei pacchetti di aggiornamento sullo stato del link, questo pacchetto è chiamato Link State Packet (LSP) e contiene informazioni del tipo: mittente, interfacce attive, costo del collegamento ecc...
Queste informazioni vengono inoltrate a tutti i nodi della rete attraverso l'algoritmo di flooding, quindi il primo router manda l' LSP ai suoi vicini e questi ultimi li inoltrano ai loro vicini (tranne a quello da cui l'hanno ricevuto) si fermeranno solo quando tutti i nodi hanno ricevuto il pacchetto e tutti hanno quindi ricevuto l'aggiornamento sullo stato della rete.

Questo è utile quando ad esempio nella rete si verificano dei guasti a dei nodi o ne viene cambiata la configurazione, scambiandosi LSP i router possono aggiornarsi sulla nuova disposizione della rete

LSR è migliore di RIP anche perché considera nel calcolo della distanza e del costo anche la larghezza di banda. Ad esempio permettendo di preferire un percorso con 3 salti a 10 Gbps rispetto a uno con 1 salto a 10 Mbps.

**Problemi di LSR**
LSR non è perfetto anzi esistono diversi problemi come:
- Il maggior uso di CPU e memoria: utilizzando Dijkstra anche su reti con diversi nodi questo influisce negativamente sulle performance dei router, dato che questo algoritmo non ha una bassissima complessità
- Oscillazione delle rotte
  ![[Pasted image 20260501100725.png|369]]
  Il calcolo del costo viene fatto anche in base alla larghezza di banda disponibile in quel collegamento, quindi immaginiamo questa situazione: i 4 router sono collegati da due collegamenti che offrono le stesse prestazioni: uno ha un flusso di traffico supponiamo ad intensità 1 mentre l'altro 1+e, i router quindi calcolano che il percorso con minor costo sia quello con intensità 1 quindi cominciano a mandare pacchetti in quel collegamento, nel frattempo il collegamento che aveva intensità 1+e ora si è svuotato, i router ricalcolano i costi e cambiano di nuovo collegamento. Questo effetto si chiama *Oscillazione delle rotte*, i router tenderanno ad alternare i 2 collegamenti anziché usarli entrambi dividendo il traffico, questo porta ad un calo di prestazioni sia della rete che dei router perché questi ultimi dovendo sempre ricalcolare dijkstra avranno sempre CPU e memoria occupate e potrebbero anche perdere dei pacchetti nel frattempo.

![[Pasted image 20260430093905.png|481]]

*LSR può lavorare su reti piccole e medio-grandi ma non conviene più su reti grandissime, perché la complessità e la matrice di adiacenza di dijkstra cresce sempre più quando aumenta il numero di nodi.*

**AS: Autonomous System**
Per questo motivo internet o comunque reti giganti sono divise in AS -> Autonomous system, gestite e amministrate da enti come ISP (Internet Services Provider) come TIM Vodafone e altri, ma anche grandi aziende come Google hanno il loro AS. Un AS può essere grande come un intera nazione.

![[Pasted image 20260430094927.png]]
![[Pasted image 20260501101700.png|447]]


Siamo passati al **DATA LINK LAYER** [[5_DLL_N.pdf]]

Il DLL si occupa di trasformare il segnale in bit e i bit in segnale, si occupa anche degli errori, raggruppa i bit per creare i frame

// non so se è giusto
Nel canale ho solo 2 modi per comunicare: acceso spento, come comunico? Devo creare un protocollo
byte staffing -> soluzione che si usava molto tempo fa ora non più
//
ho smesso di prendere appunti





