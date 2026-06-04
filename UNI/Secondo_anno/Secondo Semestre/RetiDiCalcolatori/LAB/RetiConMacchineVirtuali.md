#### Connessione punto a punto
Dati due host, nodo1 e nodo2 creare una connessione punto a punto
*Quando si clona un host assicurarsi di inserire l'opzione "Genera nuovi indirizzi MAC per tutte le schede di rete".*
![[Pasted image 20260604180445.png|574]]
La prima cosa da fare è andare su impostazioni del nodo nella vm e abilitare
la scheda di rete e cambiare da "Connessa a: Nat " a "Connessa a: Rete Interna"
questo bisogna farlo per entrambi i nodi, e mettere il nome della scheda uguale
per entrambi (IMPORTANTE) per far capire che entrambi i nodi hanno lo stesso cavo, come nome useremo "cavo1".
![[Pasted image 20260604180312.png]]
Stessa cosa sul nodo2

**COMANDI per connessione punto a punto:**
*ip a* = ti permette di vedere ip (internet protocol) della macchina
*ip addr add 192.168.56.3/24 dev eth0* = ti permette di settare un ip momentaneo
*ping -c 3 192.168.52.2* (il numero dopo -c indica quanti pacchetti inviare, così invia 3 pacchetti)
*ip addr del 192.168.56.2/24 dev eth0* per eliminare un ip
*ip link set eth0 down/up* per chiudere o aprire la porta

---

#### Rete con switch
*ATTIVARE LA MODALITA' PROMISCUA IN TUTTE LE MACCHINE, SI ATTIVA DA VIRTUAL BOX NELLA SEZIONE RETE.*
Dati 3 host, nodo1, nodo2 e switch creare una connessione tra nodo1 e nodo2 usando cavi diversi (quindi schede di rete con nome diverso). Utilizzare lo switch per fare da tramite tra nodo1 e nodo2.

Cloniamo un nodo e diamogli il nome "switch".

Adesso cambiamo la scheda di rete del nodo2 e la chiamiamo cavo2 (quella del
nodo1 va rinominata cavo1). Se adesso provassimo la connessione punto a punto non funzionerebbe.
Lo switch dovrà avere due schede di rete attivate, quindi una la nominiamo cavo1 (per il nodo 1) e l'altra cavo 2 (per il nodo 2). 
![[Pasted image 20260604180624.png|459]]
![[Pasted image 20260604180643.png|459]]
Stabiliamo per convenzione che: eth0 = cavo1 ed eth1 = cavo2. (eth0 e eth1 non rappresentano i nomi delle schede di rete, su linux questo è proprio il comando da usare.)
Avviamo le macchine e settiamo gli ip soltanto per i nodi, lo switch non necessita di ip.

**Vediamo i procedimenti:**
	Nodo1 = ip addr add 192.168.1.2/24 dev eth0
	Nodo2 = ip addr add 192.168.1.3/24 dev eth0
*Adesso* creo un bridge per far comunicare i 2 host.
	Switch = ip link add br0 type bridge
*In questo modo le schede di rete ora fanno parte dello switch (diventano slave).*
	Switch = ip link set eth0 master br0
	Switch = ip link set eth1 master br0
*Settiamo le schede in modalità promiscua.*
	Switch = ip link set eth0 promisc on
	Switch = ip link set eth1 promisc on
Attivare la modalità promiscua è fondamentale per non far scartare i pacchetti che non sono indirizzati al suo MAC.
*Mi assicuro che tutto sia attivo.*
	Switch = ip link set br0 up
	Switch = ip link set eth0 up
	Switch = ip link set eth1 up

*E adesso nodo1 fa il ping su nodo2.*

---

#### Rete con Router, switch e 3 host
Qui dobbiamo solo aggiungere una scheda di rete allo switch, cioè eth2 che si collegherà con il nostro
router per poter parlare ad un nodo collegato ad un altra rete (esterna).
Quindi andiamo sulla VM nello switch->rete->scheda di rete->rete interna->cavoRouter (ovviamente da fare anche
con il nostro router, ma servirà solo eth0 ed eth1.
(ricorda di andare su rete di ogni nodo e consentire tutto su modalità promiscua)

Adesso creiamo anche il nodo3 e avviamo le nostre macchine (il nodo 3 dovrà avere solo il cavo_3, anche il router dovrà averlo ovviamente)
Dovremo ovviamente settare nuovamente gli ip del nodo1 e del nodo2 (ricordo che non si salvano, dopo vedremo come
fare).

Per lo switch ovviamente dovremo fare i comandi di prima, anche qui dobbiamo settarlo nuovamente, ma stavolta
dovremmo anche aggiungere in up la scheda eth2 responsabile della connessione con il router 
(ip link set eth2 up, ip link set eth2 master br0, ip link set eth2 promisc on)

Dopo aver fatto questi passaggi dovremo sistemare il nostro router

Comandi per il router:
	Router: ip addr flush dev eth0 per pulire magari vecchie configurazioni
	Router: ip addr add 192.168.1.254/24 dev eth0 ip per eth0
	Router: ip link set eth0 up

	Router: ip addr flush dev eth1
	Router: ip addr add 192.168.2.254/24 dev eth1 #ip per eth1
	Router: ip link set eth1 up
	
	Router: sysctl -w net.ipv4.ip_forward=1 questo serve ad abilitare l'inoltro dei pacchetti
		e a far diventare la macchina un router

	Nodo3: ip addr add 192.168.2.10/24 dev eth0
	Nodo3: ip link set up eth0
	Nodo3: ip route add default via 192.168.2.254 (Dice al nodo: "Se non sai dove mandare un pacchetto, dallo al router")

	NODO 1: ip route add default via 192.168.1.254 
	NODO 2: ip route add default via 192.168.1.254


ALTRI COMANDI POSSIBILMENTE UTILI
	ip neigh show: 		    			mostra il contenuto attuale della tabella ARP.
	ip neigh flush all:					svuota la tabella ARP.
	ip neigh add [IP] lladdr [MAC] dev [DEVICE]		Aggiunge manualmente un'associazione statica (fissa) tra un IP e un MAC address nella tabella, senza aspettare che il computer la impari da solo.
	ip neigh del [IP] lladdr [MAC] dev [DEVICE]		Elimina una specifica riga dalla tabella ARP in modo mirato, senza doverla svuotare tutta con il comando flush.
	ip neigh get [IP] dev [DEVICE]				Interroga la tabella per cercare e mostrare le informazioni di un singolo indirizzo IP specifico.


COME FACCIO IN MODO CHE ALCUNE IMPOSTAZIONI SI SALVINO ANCHE DOPO IL REBOOT? AD ESEMPIO L'IP?

Bisogna andare sul file etc/network/interfaces con il comando vi quindi vi etc/network/interfaces
e scrivere esattamente questo:
	auto lo
	iface lo inet loopback
	
	auto eth0
	iface eth0 inet static
	address 192.168.1.2
	netmask 255.255.255.0
	gateway 192.168.1.254

ovviamente ip ecc si modificano in base alle tue preferenze.
per salvare e chiudere il file premi esc e digita :wq cioè write and quite e premi invio.


COME FACCIO A COLLEGARE IL MIO PC WINDOWS AD UNA MACCHINA VIRTUALE?
Uso il protocollo ssh (secure shell protocol). Apro terminale su windows (la mia macchina) 
apro la mia vm.

Comandi:
	vm: rc-service sshd start (per avviare il servizio ssh)
	vm: ip addr show (controlliamo ip IMPORTANTE METTERE SCHEDA SOLO HOST NELLA SCHEDA DI RETE, per isolarla)
		ip trovato ed è 192.168.168.9
	
	windows: ho inserito ssh root@192.168.168.9. mi chiedeva la password di alpine che puoi modificare su alpine con il comando passwd. 

	ATTENZIONE: ho riscontrato dei problemi di sicurezza e ho dovuto inserire questo sulla vm
	vm: 	# 1. Rimuoviamo qualsiasi blocco precedente sul login di root
			sed -i 's/PermitRootLogin.*/PermitRootLogin yes/g' /etc/ssh/sshd_config
			sed -i 's/#PermitRootLogin.*/PermitRootLogin yes/g' /etc/ssh/sshd_config

		# 2. Rimuoviamo qualsiasi blocco sull'uso delle password standard
			sed -i 's/PasswordAuthentication.*/PasswordAuthentication yes/g' /etc/ssh/sshd_config
			sed -i 's/#PasswordAuthentication.*/PasswordAuthentication yes/g' /etc/ssh/sshd_config

		# 3. Forza l'aggiunta di sicurezza a fine file per essere sicuri al 100%
			echo "PermitRootLogin yes" >> /etc/ssh/sshd_config
			echo "PasswordAuthentication yes" >> /etc/ssh/sshd_config

		# 4. Riavvia il servizio SSH per applicare le modifiche
			rc-service sshd restart
	
	windows: ha funzionato e mi sono connesso, adesso per mandare file bisognerà semplicemente lasciare 
			il terminale con ssh aperto e aprire un altro terminale. Per mandare un file
			basterà scrivere file.txt root@192.168.168.9.9:/percorso/ io ho messo home
			poi chiederà la password e lo invierà.

	vm: baserà con cd home entrare nella directory home e aprire il file con cat file.txt
	

PER IL PROBLEMA ISP
	Dobbiamo creare una rete con più nodi, switch e router, così da simulare una vasta rete interna al fine
	di collegare il tutto con un router1 collegato a sua volta ad un router_isp che ha le schede di rete settate
	scheda 1 con cavo_router_1 e scheda 2 con NAT. In questo modo tutta la nostra rete interna sarà collegata con
	internet attraversando vari nodi,switch e router. Alla fine si utilizzerà il NAT, che servirà per la traduzione
	da indirizzo privato a indirizzo pubblico in entrata e uscita. 

	I COMANDI:
		sysctl -w net.ipv4.ip_forward=1

		apk add iptables
	
		iptables -t nat -A POSTROUTING -o eth1 -j MASQUERADE
	




