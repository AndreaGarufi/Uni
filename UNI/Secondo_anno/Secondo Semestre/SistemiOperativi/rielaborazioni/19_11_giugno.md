#### Sistemi RAID - Redundant Arrays of Inexpensive Disks
Invece di avere tanti dischi separati, il sistema operativo ne vede **uno solo, grande e unico** (chiamato disco logico o virtuale). Dietro le quinte, però, questo unico disco è gestito da più dischi fisici reali che lavorano insieme.

##### Stripe
I dati relativi ad un file vengono distribuiti su più dischi: questa procedura è detta *striping*. Gli stripe sono multipli del blocco, di medio-grandi dimensioni. Le stripe sono distribuite sui vari dischi in maniera casuale.
- *Rischi*
  Usare più dischi fisici per distribuire un volume logico, significa rendere i dati molto sensibili ai guasti di uno dei dischi coinvolti: i sistemi raid aggiungono ridondanza per ottenere migliore affidabilità.
- *Aumento delle prestazioni*
  Le richieste al disco virtuale, sono distribuite parallelamente ai dischi effettivi sottostanti. Questi opereranno in parallelo.
- *Guasti*
  Un guasto su un disco qualsiasi, si propaga sul volume logico RAID: aumentando la ridondanza dei dati, migliora l’affidabilità. Esistono inoltre meccanismi di sostituzione dei dischi tramite dischi di riserva (prima dei guasti non fanno parte del sistema RAID).

---
#### Livelli di RAID
##### RAID 0 - striping - tipo di stripe: blocco
Effettua striping in modalità round-robin. Ottiene prestazioni ottimali tramite un approccio semplice e con letture di grandi volumi.

>[!Help] ROUND ROBIN
>In generale le risorse disponibili vengono suddivise in parti uguali e distribuite ai vari richiedenti **a rotazione**, senza fare favoritismi o guardare alle priorità.

Questi sistemi non hanno ridondanza quindi sono vulnerabili alle rotture dei dischi.
![[Pasted image 20260611183404.png|423]]

##### RAID 1 - mirroring - tipo di stripe: blocco
Gli stripe vengono duplicati creando delle copie esatte dei file:
*Vantaggi*
- Ridondanza e conseguente tolleranza ai guasti.
- Velocità in lettura aumentata (essendoci delle copie esatte posso leggere in parallelo 2 parti dello stesso file e poi unirle e leggere così nella metà del tempo)
*Svantaggi*
- In scrittura non ottengo nessun vantaggio perché scrivo in parallelo sui 2 dischi tutto il file (in uno il file e nell'altro la copia) e sono limitato dalla velocità del disco più lento

![[Pasted image 20260611184017.png|608]]

##### RAID 2 - stripping a livello bit con ECC - tipo di stripe: bit
Lavora sulle word applicando un codice di correzione degli errori ECC. Può correggere singoli bit di errore tramite i codici di hamming. Un esempio? 4 bit con 3 bit di ridondanza. Distribuendo i 7 bit su 7 dischi differenti, e gestendo opportunatamente la sincronia delle rotazioni dei dischi, si ottiene una forte fault tollerance, resistenza ai guasti.
*Guastato un disco, se ne fa un altro. Tramite gli altri 6 dischi, è possibile ricostruire l’informazione nel disco perso, qualsiasi esso sia.*
![[Pasted image 20260611184212.png|598]]

##### RAID 3 - striping a livello di bit con bit di parità - tipo di stripe: bit
Guastato un disco, fortunatamente, è facile stabilire il valore dei bit persi basandosi sul valore di parità. Offre gli stessi benefici del RAID 2 a costo minore. Serve ancora sincronia tra i dischi. 
![[Pasted image 20260611184323.png|464]]

##### RAID 4 - striping a livello di bit con XOR sull’ultimo disco - tipo di stripe: blocco
E' basato sul RAID 0 ma l’ultimo disco contiene solo ridondanza: lo XOR dei bit degli strip. Il disco di ridondanza è molto usato rispetto agli altri dischi del sistema e questo è un problema.
![[Pasted image 20260611184452.png|468]]

##### RAID 5 - striping a livello di bit con informazioni di parità distribuite - tipo di stripe: blocco
Risolve il problema relativo all’uso maggiore del quinto disco. Ogni scrittura su un disco, in RAID 4, richiede una scrittura fissa sul quinto disco. Distribuendo le informazioni di parità, distribuiamo il carico di lavoro, con analoga resistenza ai guasti e performance. RAID 5 risolve l’unica problematica di RAID 4.
![[Pasted image 20260611184644.png|442]]

---
#### Solid State Disk - SSD
Sono dispositivi basati su memorie flash. Usano tecnologie NAND, con architetture più simili alle RAM, ma dalla natura non volatile. Offrono letture molto veloci, grazie all’assenza di parti meccaniche. Per questo motivo, gli SSD ignorano i meccanismi di scheduling del disco, questi vengono inibiti, in quanto innecessari: basta un approccio FIFO per ottenere prestazioni ottimali.

**Guasti**
Gli SSD si usurano ad ogni operazione di cancellazione. Ogni riscrittura di (parte di) un blocco avviene previa cancellazione dell’intero blocco. Definiamo blocco come un’unità di cancellazione. Un blocco è composto da pagine, definite come unità di allocazione. Le letture sono effettuate su pagine, le cancellazioni sono sugli interi blocchi. Per aggiornare un’informazione di una pagina, va effettuata la cancellazione e riscrittura dell’intero blocco.
Per evitare un usura eccessiva degli SSD, si implementano file system che ottimizzano la cancellazione dei blocchi in modo da minimizzare il deterioramento.