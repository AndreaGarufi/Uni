In IPv6 il campo hop limit è 255, lo stesso numero del time to live di IPv4, non è stato alzato perché gli hop sono i salti tra router quindi se un pacchetto deve fare 255 salti è già tantissimo, quindi un numero più alto non ha senso

si può comunicare tra IPv4 e IPv6 tramite incapsulamento, perché IPv4 non è compatibile con IPv6, quindi prendo il pacchetto IPv4 e lo incapsulo dentro un pacchetto IPv6 cosi che questo possa viaggiare in una rete IPv6 o viceversa

NOVITA' assoluta di IPv6 gli header opzionali 
![[Pasted image 20260423113101.png|571]]

C'è anche il DHCP 6 che è migliore perché usando questi indirizzi non devo mandare una DHCP request in broadcast da anonimo ma (capire perché non ho sentito)

**Firewall**

2 tipi 
- firewall software -> che bloccano il pacchetto all'entrata (è comunque possibile attaccare, ma meglio di niente)
- firewall hardware -> dispositivo esterno che fa solo questo

Questa è la soluzione di firewall hardware.
![[Pasted image 20260423115050.png|604]]
La zona interna al cerchio è nascosta al mondo esterno, mentre per fare quel firewall uso router che mi filtrano i pacchetti e anche un dispositivo che può leggere pacchetti fino al livello application. (Esempio pratico: arriva un pacchetto con dentro un eseguibile, l'application gateway lo vede e scarta il pacchetto)


ho capito che la rete la zona con il cerchio è isolata al mondo esterno (NON sta parlando di DMZ)

La soluzione sopra è molto costosa, se voglio risparmiare opto per un firewall software e basta



**DMZ**
Nella DMZ tipicamente metto dei server e metto delle regole di firewalling sia per uscire che per entrare, in base ai server la dentro imposto queste regole (ad esempio la comunicazione può arrivare solo alla porta 80 oppure entrano solo richieste HTTP ecc...)


**Algoritmi di routing**
Si ragiona per grafi pesati, ma bisogna stabilire il peso e sopratutto non è scontato conoscere già il grafo.

Per stabilire il peso si usano diverse metriche (non ha specificato quali, forse il numero di hop)
![[Pasted image 20260423123136.png|517]]

Se non conosciamo il grafo si deve fare una visita (algoritmi) e si guarda ogni cosa, l'algoritmo di si chiama flooding,

Un nodo manda un pacchetto ai vicini e i vicini lo mandano ai loro vicini e cosi via...
![[Pasted image 20260423123348.png|585]]
Il problema è che si crea un circolo vizioso e si inonda la rete
![[Pasted image 20260423123425.png]]

Un primo metodo per risolvere questo problema è ricordarsi di aver già mandato quel pacchetto e quindi se lo ricevono di nuovo lo scartano

seconda soluzione dopo un tot di hop (esempio 10) ogni router si ferma e non invia più i pacchetti

Il flooding ha un vantaggio: trova la strada migliore perché trova ogni strada possibile 

ha nominato STP spannig tree protocol
in pratica serve trovare un albero per rappresentare questa rete quindi si organizza un torneo in cui i nodi a 2 a 2 si sfidano per chi ha il MAC ADDRESS più piccolo o più alto in questo modo l'informazione del vincitore si propaga a tutti e abbiamo un albero, questa cosa è implementata in STP

*Vantaggi di flooding*
- trova la strada per la destinazione se esiste
- trova la migliore
*Contro:* 
- crea una quantità gigante di pacchetti duplicati anche se la situazione può essere controllata

**Distance Vectors**
E' stato il primo algoritmo di routing.
Ogni nodo conosce sicuramente i suoi vicini e ha una tabella in cui le colonne sono le uscite del nodo e le righe sono le possibili destinazioni
![[Pasted image 20260423124824.png]]Sono il nodo E e uso l'uscita A per arrivare ad A -> peso 1
Sono il nodo E e uso l'uscita D per andare a C -> peso 4

Perché si chiama distance vectors? (Ne dobbiamo parlare all'esame)

