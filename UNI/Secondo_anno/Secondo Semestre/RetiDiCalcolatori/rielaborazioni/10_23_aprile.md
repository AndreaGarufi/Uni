
Continuo di [[9_9_aprile]]
![[Pasted image 20260424085243.png]]
Come possiamo vedere l'header IPv6 è più grande di quello di IPv4 in termini di byte ma è 
molto più semplice, la dimensione maggiorata è dovuta ai 2 campi contenenti l'IP dato che l'indirizzo IPv6 è composto da 128 bit anziché i 32 di IPv4

In IPv6 il campo hop limit sostituisce il time to live (TTL) ed è 255, lo stesso numero del time to live di IPv4, non è stato alzato perché gli hop sono i salti tra router quindi se un pacchetto deve fare 255 salti è già tantissimo,anche troppo, quindi un numero più alto non ha senso

**Comunicazione tra reti IPv4 e IPv6**
Si può comunicare tra IPv4 e IPv6 tramite incapsulamento, perché IPv4 non è compatibile con IPv6, quindi prendo il pacchetto IPv4 e lo incapsulo dentro un pacchetto IPv6 cosi che questo possa viaggiare in una rete IPv6 o viceversa. Questo meccanismo si chiama *tunneling*

**NOVITA' assoluta di IPv6**: gli header opzionali 
Anziché mettere tutti i possibili header come in IPv4 che rallentano il lavoro dei router (perché li devono analizzare tutti) se servono alcuni header specifici questi vengono aggiunti in coda al campo "next header"
![[Pasted image 20260423113101.png|571]]

**DHCP 6**
C'è anche il DHCP 6 che è migliore perché usando questi indirizzi non devo mandare una DHCP request in broadcast da anonimo ma questi server funzionano in multicast cioè: il client manda una richiesta solo ai server che gestiscono pacchetti DHCPv6 anziché mandarli in broadcast, questo riduce la congestione in rete.

**Firewall**
Un firewall serve a bloccare il traffico malevolo che vuole attaccare una rete e lo fa attraverso una serie di regole impostate dall'amministratore in base alla priorità di protezione.

Queste regole chiamate regole di routing sono basate su:
• Indirizzi IP e porte di origine e destinazione. 
• Protocolli (TCP, UDP, ICMP...). 
• Stato della connessione. 
• Contenuto del pacchetto, in firewall con ispezione profonda. I firewall posso operare a livello di rete, di trasporto e/o al livello applicativo, a seconda delle esigenze di controllo

Abbiamo 2 tipi firewall:
- Firewall software -> che bloccano il pacchetto all'entrata (è comunque possibile attaccare, ma meglio di niente)
- Firewall hardware -> dispositivo esterno che fa solo questo
Questa è una possibile disposizione di firewall hardware.
![[Pasted image 20260423115050.png|604]]
La zona interna al cerchio è nascosta al mondo esterno, mentre per fare quel firewall uso router che mi filtrano i pacchetti e anche un dispositivo che può leggere pacchetti fino al livello application. (Esempio pratico: arriva un pacchetto con dentro un eseguibile, l'application gateway lo vede e scarta il pacchetto).

La soluzione sopra è molto costosa, se voglio risparmiare opto per un firewall software e basta.


**DMZ** **(Demilitarized Zone)**
Nella DMZ tipicamente metto dei server e metto delle regole di firewalling sia per uscire che per entrare, in base ai server la dentro imposto queste regole (ad esempio la comunicazione può arrivare solo alla porta 80 oppure entrano solo richieste HTTP ecc...)


**Algoritmi di routing**
Si ragiona per grafi pesati, ma bisogna stabilire il peso e sopratutto non è scontato conoscere già il grafo.

Per stabilire il peso si usano diverse metriche (non ha specificato quali, forse il numero di hop)
![[Pasted image 20260423123136.png|517]]

Se non conosciamo il grafo si deve fare una visita (algoritmi) e si guarda ogni cosa, l'algoritmo di si chiama flooding,

Se non conosciamo il grafo si deve fare una visita (algoritmi) e si guarda ogni cosa, l'algoritmo usato di si chiama **flooding**

**Algoritmo di Flooding -> flooding vuol dire inondato**
Un nodo manda un pacchetto ai vicini e i vicini lo mandano ai loro vicini e cosi via...
![[Pasted image 20260423123348.png|585]]
Il problema è che si crea un circolo vizioso e si inonda la rete
![[Pasted image 20260423123425.png]]

Un primo metodo per risolvere questo problema è ricordarsi di aver già mandato quel pacchetto e quindi se lo ricevono di nuovo lo scartano

seconda soluzione dopo un tot di hop (esempio 10) ogni router si ferma e non invia più i pacchetti

Il flooding ha un vantaggio: trova la strada migliore perché trova ogni strada possibile 

ha nominato STP spannig tree protocol
in pratica serve trovare un albero per rappresentare questa rete quindi si organizza un torneo in cui i nodi a 2 a 2 si sfidano per chi ha il MAC ADDRESS più piccolo o più alto in questo modo l'informazione del vincitore si propaga a tutti e abbiamo un albero, questa cosa è implementata in STP

**Soluzioni al problema**

1) Un primo metodo per risolvere questo problema è ricordarsi di aver già mandato quel pacchetto e quindi se i router lo ricevono di nuovo lo scartano

2) Seconda soluzione dopo un tot di hop (esempio 10) ogni router si ferma e non invia più i pacchetti


**Il flooding ha un vantaggio: trova la strada migliore perché trova ogni strada possibile** 

(ha nominato STP spannig tree protocol
in pratica serve trovare un albero per rappresentare questa rete quindi si organizza un torneo in cui i nodi a 2 a 2 si sfidano per chi ha il MAC ADDRESS più piccolo o più alto in questo modo l'informazione del vincitore si propaga a tutti e abbiamo un albero, questa cosa è implementata in STP)

*Vantaggi di flooding*
- trova la strada per la destinazione se esiste
- trova la migliore
*Contro:* 
- crea una quantità gigante di pacchetti duplicati anche se la situazione può essere controllata

**Distance Vectors**
E' stato il primo algoritmo di routing.

**Distance Vectors**
E' stato il primo algoritmo di routing ed è basato sull'idea dell'algoritmo di *Bellman-Ford*.
Ogni nodo conosce sicuramente i suoi vicini e ha una tabella in cui le colonne sono le uscite del nodo e le righe sono le possibili destinazioni
![[Pasted image 20260423124824.png]]Sono il nodo E e uso l'uscita A per arrivare ad A -> peso 1
Sono il nodo E e uso l'uscita D per andare a C -> peso 4

Perché si chiama distance vectors? (Ne dobbiamo parlare all'esame)

