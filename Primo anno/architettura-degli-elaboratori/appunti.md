
Bus 
l'architettura di un calcolatore è di tipo master-slave processore(master), memoria, I/O (slave)
e vedono il BUS come un veicolo perché da li passano bit, i bus servono a far comunicare le varie parti del PC.

un operazione che trasporta bit dalla CPU alla memoria(SCRITTURA- WRITE)
al contrario invece è READ/ LETTURA

il BUS è scomponibile in 3 sottoinsiemi (LINEE) -AddressBUS, DataBUS, ControlBUS

CBUS ha una linea che specifica(controlla) la direzione (CPU--I/O oppure I/O CPU) 
ha un altra linea per specificare il verso del trasferimento (WRITE/READ) 

DBUS da qui passano i dati da trasferire.

ABUS porta i dati all'indirizzo di memoria corretto

STARVATION (morte dei processi per mancanza di accesso alle risorse)

Ci sono dei processi sincroni e a-sincroni, i primi collaborano con altri processi e i processi devo essere "sincronizzati" perché ad esempio uno e propedeutico per l'altro (si devono mettere d'accordo). Quelli a-sincroni lavorano da soli e non hanno bisogno di collaborare con nessuno.

le CPU vanno a diversi GHz mentre i bus al massimo a alcune centinaia di MHz (bottleneck)
la linea wait del CBUS indica il trasferimento completato (1) o in corso (0), infatti il trasferimento dei dati da CPU a memoria è più lento dei tempi di operazione della CPU.

dal comando read al momento in cui il dato è disponibile e viene letto, questo tempo è detto "latenza" 

sulla linea I/O-mem troviamo 1 se il trasferimento riguarda CPU e I/O, se troviamo 0 trasferimento da CPU a memoria (se sulla linea READ/WRITE troviamo 1 abbiamo un operazione di lettura, se troviamo 0 è scrittura)

la quantità di linee di ABUS e DBUS dipendono dall'architettura della CPU (64 bit 64 linee, 32 bit 32 linee)

la dimensione del DBUS rappresenta il grado di parallelismo del processore ovvero la massima quantità di dati che è in grado di elaborare in un solo trasferimento di bus

la dimensione dell ABUS specifica la quantita di memoria raggiungibile dai programmi. 2 elevato al numero di linee dell ABUS (32 bit 2^32 linee 4 GB di RAM al massimo ciascun processo) 

**(**esame)** se ho un architettura a 32 bit (32 linee di ABUS) ognuno dei 4 processi può indirizzare 4 gb di RAM? si 4 gb massimo (2^32) ogni processo

(esempio di BUS : PCI Express)

Il chipset è formato da northBridge (dedicato ala connesione memoria-CPU)e southBridge (CPU-I/O)

(le immagini sono matrici ogni pixel è un elemento della matrice) la risoluzione indica la grandezza della matrice 1920x1080 è la matrice del full HD, 1 per il bianco e nero, per i colori abbiamo bisogno di 3 matrici (red,green,blue(RGB))

le schede video hanno migliaia di core perchè si puo parallelizzare (a-sincrono)tutto, ogni processo prende una piccola parte della matrice e ogni processo utilizza un core della GPU (a differenza della CPU che esegue anche processi sincroni ).




