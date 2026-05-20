### **Strutture Ethernet**
Hub e bridge sono dispositivi hardware e servono a collegare le varie sotto reti diverse, l'hub è ormai obsoleto mentre il bridge è alla base dei moderni switch

L’ormai obsoleto hub: 
• Lavora principalmente al livello fisico. 
• Ripete e rigenera il segnale su tutte le porte. 
• Il dominio di collisione tra tutti i dispositivi collegati è unico. 
• Broadcast domain unico. 

Il bridge, invece: 
• Lavora a livello data link. 
• Filtra e inoltra in base all’indirizzo MAC 
• Nel bridge ogni porta crea (idealmente) un dominio di collisione separato. 
• Broadcast domain unico.

**Switch**
E' un dispositivo che trasmette pacchetti ricevuti a uno o più dispositivi destinatari. E' più espandibile in termini di numero di porte, rispetto al bridge, e effettua operazioni di inoltro (individuare a quale interfaccia mandare il frame) e filtraggio (capire quando scartare un frame). Uno switch contiene al suo interno una switch table con record del tipo Indirizzo MAC - Interfaccia - Tempo. Il tempo viene utilizzato per stabilire quando un dispositivo non è più presente nella rete: verrà dedotto in quanto non verranno mandati più pacchetti al suo indirizzo MAC per molto tempo. Gli switch sono full duplex, senza collisioni.


### **VLAN**
Le LAN virtuali permettono di creare delle LAN logiche indipendenti sulla stessa struttura fisica.
![[Pasted image 20260520180556.png|608]]

Permette di risparmiare su costi, sulla manodopera e sulla complessità dietro il ricablaggio di una rete, per modificarne la struttura logica. Sono quindi delle vere e proprie LAN logiche separate che risiedono sopra la struttura fisica. Le LAN virtuali rimappano le tabelle di forward del bridge senza modificare la cablatura. Una porta può essere associata a una e una sola VLAN, altrimenti si riscontrerebbero collisioni.

*Scopo delle VLAN* 
• Riutilizzo dell’architettura di partenza con conseguente risparmio. 
• Flessibilità. Molto più facile spostare gli utenti tra le VLAN. • Prestazioni migliori. Isolando il broadcasting nelle VLAN, 
• Sicurezza. E' semplice isolare dei sistemi tramite le VLAN.


*VLAN basata su porte* 
Lo switch può essere partizionato logicamente in più insiemi di porte. Le porte possono essere associate a delle VLAN. Nell’header dei frame DLL è presente un identificatore di VLAN.


### **Spanning tree protocol - STP**
*Ridondanza e loop:*
Solitamente una rete è collegata seguendo una topologia che preveda ridondanza, in parole povere se un collegamento si rompe la rete continua a funzionare, magari con dei rallentamenti ma funziona. *La ridondanza di per se è una cosa buona ma è soggetta al rischio di loop*. Ad esempio:
![[Pasted image 20260520181751.png]]
Immaginiamo che in questa rete PC1 debba mandare un messaggio in broadcast, inoltra quindi il frame allo switch 1 che vedendo essere un messaggio broadcast lo invia su tutte le altre porte (tranne quella di partenza), quindi il messaggio arriva a SW2 e SW3, anche loro vedendo che si tratta di un messaggio broadcast lo invieranno a loro volta a tutti gli altri dispositivi, in questa maniera si è creato un loop in cui attraverso il meccanismo di *flooding* la rete resta inondata sempre dallo stesso pacchetto che viene di volta in volta inoltrato a tutti i dispositivi, inoltre i frame Ethernet non hanno un campo TTL (time-to-live) come i pacchetti IP . Per risolvere questo problema si è pensato di creare il protocollo STP.

*Alberi e grafi*
Una topologia di rete può essere vista come un grafo:
![[Pasted image 20260520182424.png|414]]
La differenza tra albero e grafo è che un albero è aciclico mentre un grafo normale lo può essere (come la rete in figura)

*E' un protocollo di livello 2 (Data Link) progettato per prevenire cicli (loop) infiniti in reti Ethernet dotate di collegamenti ridondanti.*
**Funzionamento**:
- STP trasforma una topologia fisica a grafo (dotata di cicli) in una **topologia logica ad albero** (senza cicli), *disabilitando selettivamente le porte ridondanti*.
- A questo punto sceglie un *root bridge* o switch capo (che funge da root dell'albero) e tutte le altre porte degli altri switch calcoleranno i costi (per mandare i frame) prendendo come riferimento lo switch capo.
- Le altre porte (quelle ridondanti) saranno accese e funzionanti ma bloccate in modo da "fare finta" che nella rete ci sia un solo collegamento ovvero quello che porta al root bridge.
- Se quel collegamento si guasta, gli altri switch ricalcoleranno il percorso più breve sbloccando un delle altre porte