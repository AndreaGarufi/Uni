Ottimizzazioni usate per risparmiare RAM
**Copy-on-write**
è un ottimizzazione che permette di risparmiare memoria in situazioni in cui processi diversi hanno delle pagine che hanno lo stesso contenuto. Utilizzando la fork il processo P1 si clona in P2 (cambia solo il PID il resto è uguale) aziché duplicare le pagine usate dal processo P1 (che sono già in RAM), faccio puntare l'indice delle pagine di P2 a quelle di P1 in questo modo risparmio RAM.
**Problema**
il problema sorge quando un processo vuole modificare una entry della pagina. Ad esempio se P2 modifica anche solo un bit della pagina, questa cambiera anche per P1 (perche usano lo stesso frame in RAM), questo accade perché è il sistema oparativo che fa questa ottimizzazione, dal punto di vista dei processi loro hanno dei frame diversi. Quindi questo discorso regge finché le pagine si usano solo in lettura. Se uno dei 2 processi vuole fare una modifica il SO deve gestire questa cosa facendo un duplicato della parte che deve essere cambiata. (immaginiamo 3 pagine A B e C, P2 vuole modificare pagina C e allora il SO duplica la pagina C così che P2 possa cambiare la pagina C e P1 usa la vecchia copia,vedi figura)
![[Pasted image 20260519153106.png|456]]

Il SO per gestire queste problemi, modifica artificiosamente la maschera dei permessi di P1 e P2, rendendo le pagine in sola lettura, cosi se un processo deve scrivere su quelle pagine infrange i permessi il sistema operativo se ne accorge perché viene generata una eccezione dalla MMU, il sistema operativo sa che quel processo in realtà non sta facendo niente di male e quindi non lo killa, anzi gli crea la copia che dicevamo prima, essendo quella pagina copiata i permessi possono essere reimpostati, tanto ormai quella è una normale pagina solo per P2, sto comunque risparmiando RAM perché le pagine A e B sono ancora "condivise" 

**Zero-fill-on-demand**
distratto


**librerie condivise e file mappati**
distratto           