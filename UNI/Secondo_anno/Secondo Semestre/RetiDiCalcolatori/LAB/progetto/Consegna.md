progettare una soluzione software, utilizzando il tuo linguaggio orientato agli oggetti preferito, per provare a implementare ogni livello del modello TCP/IP ed emulare due nodi come processi o thread separati, in cui ciascuno possiede un'istanza dello stack per comunicare, ad esempio inviando una stringa.

- **▸** Progetta una classe _Application_ (estendibile o astratta).
    
- **▸** Progetta una classe _Transport_ che prenda i dati dall'applicazione, li segmenti e crei oggetti della classe _Segment_ (utilizzando magari una dimensione massima del segmento?).
    
- **▸** Progetta una classe _Internetwork_ che crei oggetti della classe _Packet_ a partire dai segmenti.
    
- **▸** Infine, crea una classe _NetworkAccess_ che crei oggetti della classe _Frame_ contenenti i pacchetti e inserisca questi frame in una Memoria Condivisa (Stack).
    
- **▸** Devi creare una classe _Device_ in cui ciascun dispositivo abbia un'istanza per ogni livello, utilizzata per incapsulare e decapsulare le PDU (Protocol Data Unit).
    
- **▸** L'istanza _NetworkAccess_ deve verificare la presenza di nuovi frame nella Memoria Condivisa.
    
- **▸** La Memoria Condivisa funge da Media Access Controller (MAC).
    
- **▸** Ogni livello è connesso in qualche modo, forse tramite riferimenti o puntatori?

![[Pasted image 20260422182756.png]]
