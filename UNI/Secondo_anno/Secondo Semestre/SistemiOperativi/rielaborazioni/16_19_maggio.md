### **Ottimizzazioni usate per risparmiare RAM**
**Copy-on-write**
E' un ottimizzazione software fatta dal SO che permette di risparmiare memoria in situazioni in cui processi diversi hanno delle pagine che hanno lo stesso contenuto.
Utilizzando la *fork* il processo P1 si clona in P2 (cambia solo il PID il resto è uguale) anziché duplicare le pagine usate dal processo P1 (che sono già in RAM), faccio puntare l'indice delle pagine di P2 a quelle di P1 in questo modo risparmio RAM.
In pratica entrambi i processi accedono alla stessa area di memoria.

**Problema**
Il problema sorge quando un processo vuole modificare una entry della pagina. Ad esempio se P2 modifica anche solo un bit della pagina, questa cambierà anche per P1 (perché usano lo stesso frame in RAM), questo accade perché è il sistema operativo che fa questa ottimizzazione, dal punto di vista dei processi loro hanno dei frame diversi. Quindi questo discorso regge finché le pagine si usano solo in lettura. Se uno dei 2 processi vuole fare una modifica il SO deve gestire questa cosa facendo un duplicato della parte che deve essere cambiata. 
Ad esempio: immaginiamo 3 pagine A, B e C, P2 vuole modificare pagina C e allora il SO duplica la pagina C così che P2 possa cambiare la pagina C e P1 usa la vecchia copia,vedi figura.
![[Pasted image 20260519153106.png|405]]
*Come fa il sistema operativo a sapere che P2 deve effettuare modifiche alla pagina C?*

Il SO per gestire questo problema, modifica artificiosamente la maschera dei permessi di P1 e P2, rendendo le pagine in sola lettura, cosi che se un processo deve scrivere su quelle pagine infrange i permessi e *viene generata una eccezione dalla MMU*, il sistema operativo se ne accorge ma sa che quel processo in realtà non sta facendo niente di male e quindi non lo killa, anzi gli crea la copia che dicevamo prima, essendo quella pagina copiata i permessi possono essere reimpostati (sia per la pagina che usa P1 sia per quella di P2), tanto ormai quella è una normale pagina solo per P2, sto comunque risparmiando RAM perché le pagine A e B sono ancora "condivise" 

**Zero-fill-on-demand**
Questa è un altra ottimizzazione per consumare meno RAM e funziona così:
> [!tip] **Premessa: ** Quando ad un processo viene assegnato un frame libero di memoria il sistema operativo prima di riservarlo per lui lo azzera, cioè riempie di 0 tutti i bit di quel frame, questo viene fatto per motivi di sicurezza (magari in quel vecchio frame c'erano dei dati sensibili come password ecc...)

Quando un programma chiede nuova memoria al sistema operativo (ad esempio per l'area **BSS** delle variabili globali non inizializzate o tramite lo **Heap**), il SO non va subito a cercare frame liberi nella RAM per riempirli di zeri. Sarebbe uno spreco di tempo e RAM enorme.
- Il SO tiene sempre da parte un frame di pochi Kbyte sempre azzerato chiamato **zero page**, quindi quando un processo chiede della memoria il SO fa puntare le voci della tabella delle pagine del processo verso questa unica zero page
- Imposta i permessi in *read only* così che quando un processo vuole scrivere venga generata un eccezione (vedi sotto)
- **Risparmio** -> in questa maniera se 100 processi chiedono 1GB di RAM (senza voler scrivere subito in essa, ma la vogliono riservata) non avrò bisogno di 100 GB di RAM perché farò puntare tutti quei processi alla **zero page**
- Il problema nasce quando il processo vuole scrivere qualcosa in memoria (che lui crede sua, dal punto di vista del processo lui ha il suo frame di memoria), appena infrange il permesso di read only come per il copy-on-write l'MMU genera una eccezione quindi il processo si ferma (ma anche qui non viene killato perché il SO sa che non faceva nulla di male) e il SO prende un frame dalla sua pool di frame vuoti, lo azzera e fa puntare le pagine a quel o quei frame appena azzerati impostandogli i permessi regolari di lettura/scrittura
- Il processo riprende normalmente la sua esecuzione




**librerie condivise e file mappati**
distratto           