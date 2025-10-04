**I circuiti integrati rappresentano le variabili binarie usando livelli di tensione distinti (0,1)**, il livello di tensione TEORICO per lo 0 è 0 , per 1 può variare da 1,8 a 3,3 o 5 Volt in base alla macchina in uso, la soglia di separazione distingue lo 0 dall' 1(**es. in un sistema a 5 volt se la tensione è sotto 1,5 volt viene interpretato come 0 oltre i 3,5 volt è 1**) le tensioni che si avvicinano alla tensione di soglia possono portare problemi,  la soglia intermedia è la banda vietata (quella tensione non viene considerata)

**COSA E' UN TRANSISTOR (o transistore)** -> **esame**
sono semiconduttori fondamentali nei circuiti integrati e sono utilizzati per amplificare o commutare segnali elettronici, semiconduttori come il silicio, drogati con impurità per creare zone positive e negative.
A seconda della tensione in ingresso possono trovarsi nella condizione di conduzione o interdizione.
La tecnologia più utilizzata è il **MOS (transistore a metallo-ossido- semiconduttore )**


●Valori tipici di tensione per tecnologia MOS: 
● $V_{cc}$ = 5 Volt, $V_{soglia}$ = 2.5 Volt 
● $V_{cc}$ = 3.3 Volt, $V_{soglia}$ = 1.5 Volt

sopra la  $V_{soglia}$ è considerato 1 sotto è considerato 0
(●Per evitare l’incertezza data dal rumore del circuito, tutti i valori prossimi alla tensione di soglia non vengo presi in considerazione (banda vietata))

**esistono 2 tipi di transistor (che non sono MOS [solo il MOSFET {derivato di FET} è MOS])**
BJT  (bipolare)
FET (transistor a effetto di campo)

**Differenze** 
nei BJT il flusso della corrente è controllato dalla corrente di base
nei FET è controllata dalla tensione applicata alla porta (gate)

**I transistor funzionano come interruttori, bloccando il flusso di corrente o amplificandolo.**
**la miniaturizzazione dei transistor ha permesso di far avere miliardi di dispositivi nelle CPU, questi dispositivi rendono possibile la creazione di CPU sempre più veloci e potenti**

**TRANSISTORI MOS**
sono dispositivi semiconduttori ampiamente utilizzati nei circuiti integrati per la loro resistenza e versatilità:
●A seconda della tensione in ingresso nella Base il transistore collegherà o meno la Sorgente al Pozzo
schema MOS

![[Pasted image 20241209113431.png|400]]

La porta si può chiamare anche gate

**Esistono 2 tipi di transistori MOS: 
NMOS e PMOS**

●**Nei transistori NMOS:** 
●Tensione di base alta = conduzione 
●Tensione di base bassa = interdizione 
●Sorgente collegata alla massa 

●**Nei transistori PMOS:** 
●Tensione di base alta = interdizione
●Tensione di base bassa = conduzione 
●Sorgente collegata all’alimentazione

Attraverso i transistor **NMOS si può creare una porta NOT**, dove per una tensione in ingresso (gate) si ottiene una tensione 0 al pozzo 

Posso anche **creare una porta NOR** **collegando 2 NMOS in parallelo.**
produce 1 solo quando tutti gli ingressi sono bassi se c'è almeno 1 ingresso alto ci sarà 0 in uscita.
I NOR si usano principalmente nelle memorie 
(le memorie possono essere fatte da NOR o da NAND, NAND è più veloce)

**si può creare una porta NAND attraverso 2 NMOS collegati in serie**.
produce 0 se tutti gli ingressi sono alti, altrimenti produrrà 1. I NAND si usano nelle memorie

**Una nuova tecnologia è la CMOS (complementary MOS)**
dove si uniscono NMOS e PMOS in modo da massimizzare l'efficienza e ridurre i consumi. Infatti CMOS è alla base delle nuove architetture.
Si ottiene collegando in serie NMOS e PMOS

**Vantaggi:**
●Consumo di potenza ridotto (consumo solo in fase di commutazione) 

●Potenza elettrica dissipata proporzionale alla frequenza di commutazione 

●Transistori MOS hanno dimensioni molto ridotte (componenti con miliardi di transistori integrati) 

●Piccole dimensioni = alta frequenza massima di commutazione (nell’ordine dei GigaHertz)


![[Pasted image 20241209144036.png]]


**fan-in** è il numero massimo di segnali in ingresso che la porta può gestire 
**fan-out** è il numero massimo di segnali in uscita che una porta logica può alimentare senza compromettere i risultati ottenuti

Ovviamente non si possono collegare più uscite ad uno stesso ingresso, altrimenti si verificherebbero corto circuiti o comunque non si potrebbero distinguere i valori degli ingressi

Le porte logiche collegate in circuiti si chiamano circuiti integrati.
I circuiti integrati sono piastrine in silicio contenute in un involucro protettivo a cui sono attaccati dei pin.

●**Esistono 4 tipi di circuiti integrati a seconda della scala di integrazione:** 
●**SSI** (piccola): poche porte logiche 
●**MSI** (media): addizionatore, sottrattore, singoli registri, multiplatore, etc. 
●**LSI** (grande): ALU, banco di registri, piccoli processori 
●**VLSI** (molto grande): memorie molto capaci, processori potenti

porta **tri-state** è una porta che può assumere 3 stati 
- Accesso
- Spento
- Alta impedenza
Quando il circuito è in alta impedenza la porta è come se fosse disconnessa(circuito aperto), in questo modo più dispositivi possono condividere più linee di bus senza interferire tra di loro.

Circuito integrato: CI in italiano sono dispositivi elettronici che combinano diversi componenti elettronici (resistenze, diodi, transistor, ecc.) questa tecnologia permette di creare dei circuiti di dimensioni ridotte e molto efficienti. I circuiti integrati sono di 3 tipi:
- Analogico
- Digitale
- Mixed
Chiaramente la funzione d'onda generata da questi circuiti cambia. Esistono vari tipi di circuiti integrati a seconda della scala di integrazione (guarda slide 18)

il **decodificatore** è un circuito logico che prende un input un segnale e lo decodifica in segnali di uscita leggibili da altre componenti

il multiplatore è un circuito digitale che seleziona uno tra i diversi ingressi e lo invia in uscita, basandosi sui segnali di controllo che gli arrivano, ciò permette a più fonti di condividere la stessa linea di connessione

