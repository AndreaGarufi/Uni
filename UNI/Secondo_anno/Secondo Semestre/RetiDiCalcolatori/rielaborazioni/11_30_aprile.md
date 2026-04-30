Continuo [[10_23_aprile.pdf]]
Nei sistemi che usano il distance vectors, ogni nodo è indipendente dagli altri, quindi non è un sistema centralizzato, un sistema centralizzato è più semplice da gestire perché c'è un singolo nodo che comanda/gestisce tutti gli altri ma se questo nodo "capo" viene a mancare per un guasto o un attacco la rete non funzionerà più bene. Nei sistemi decentralizzati (come quelli che implementano il distance vectors) ogni nodo conosce solo i suoi vicini diretti e conosce le informazioni che questi gli passano (cioè il vettore delle distanze)

**Problema del Distance Vectors**
Uno dei problemi più importanti del distance vectors è che le false notizie si propagano dato che il nodo conosce le informazioni che i suoi vicini gli passano, ma se quelle informazioni sono false verranno prese per vere

**RIP e problema della distanza**
Questo protocollo è stato implementato nel protocollo RIP, in cui la distanza veniva misurata attraverso i salti (hop), 1 distanza = 1 hop, senza tener conto della distanza fisica nella realtà o della larghezza di banda di quel collegamento 
Esempio: potrebbero esserci 2 router che abbiano stessa distanza per il nodo (1 hop) ma uno si trova a 1 km l'altro a 10 metri.

**Protocollo LINK STATE ROUTING**
Questo protocollo usa un idea diversa (nel distance vectors si usava Bellman-Ford), qui si usa l'algoritmo di Dijkstra.
L'obbietti di questo protocollo è avere una conoscenza completa della rete da parte di ogni nodo.

**Problemi di LSR**
problema slide 175

![[Pasted image 20260430093905.png|481]]


*LSR può lavorare su reti piccole e medio-grandi ma non conviene più su reti grandissime, perché la matrice di adiacenza cresce sempre più quando aumenta il numero di nodi.*

Per questo motivo internet o comunque reti giganti sono divise in AS -> Autonomus system, gestite e amministrate da enti come ISP (Internet Services Provider) come TIM Vodafone e altri, ma anche grandi aziende come Google hanno il loro AS. Un AS può essere grande come un intera nazione.

![[Pasted image 20260430094927.png]]




Siamo passati al **DATA LINK LAYER**

Il DLL si occupa di trasformare il segnale in bit e i bit in segnale, si occupa anche degli errori, raggruppa i bit per creare i frame

// non so se è giusto
Nel canale ho solo 2 modi per comunicare: acceso spento, come comunico? Devo creare un protocollo
byte staffing -> soluzione che si usava molto tempo fa ora non più
//
ho smesso di prendere appunti





