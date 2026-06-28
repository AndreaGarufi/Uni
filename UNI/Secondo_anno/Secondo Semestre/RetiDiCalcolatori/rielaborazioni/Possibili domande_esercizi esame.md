---

---

>[!TIP] Gli argomenti delle domande le prende dal syllabus (in pratica può chiedere tutto quello che è scritto li)


**Domande teoriche**

---
*Differenza tra routing e forwarding?*
**Definizioni:**
- *Routing* -> il processo di selezione e definizione di cammini per i pacchetti all'interno o tra reti.
- *Forwarding* -> Consiste nell'inoltro effettivo dei pacchetti
---
*Perché si chiama distance vectors?* 
Ogni router mantiene e comunica una lista (un **vettore**) che contiene due informazioni fondamentali per ogni nodo della rete:
1. **Distanza (Distance):** Il costo stimato (metrica) per raggiungere una specifica destinazione.
    
2. **Direzione/Vettore (Vector):** L'interfaccia di uscita o il router adiacente (next-hop) da utilizzare per inoltrare il pacchetto lungo il percorso scelto.
---


**Esercizi**
*Un amministratore di rete sbaglia la configurazione della maschera di rete in un host: che succede?*
(Le maschere di rete servono a un host per capire che percorso seguire)
Definiamo lo scenario:
![[SmartSelect_20260527_103308_Samsung Notes.jpg]]
Abbiamo l'host C che ha una maschera di rete sbagliata: immaginiamo di avere indirizzi del tipo: 1.1.1.0/24
La maschera quindi è /24 cioè con i primi 24 bit per la rete e gli altri 8 per gli host (in questo caso avremo un massimo di 255-2 indirizzi disponibili per gli host).
Ci sono 2 scenari in cui la maschera può essere sbagliata: aggiungiamo un bit (/25) o togliamo un bit (/23)
*Scenario 1 (/25)*
- *Caso 1:*
  ![[SmartSelect_20260527_104458_Samsung Notes.jpg|502]]
  - L'host C avendo solo 7 bit per gli host (/25) potrà vedere al più gli indirizzi che vanno da 0 a 127 perché $2^7 = 128$ quindi vede solo 128 indirizzi diversi
  - L'host A invece ne vede 256 (da 0 a 255) perché ha 8 bit riservati agli host
  - Il router ha indirizzo 1.1.1.254, in questa situazione quindi l'host C non vedrà il router e potrà comunicare solo con A perché si trova entro il range di indirizzi che lui vede.
    
    Va detto che in questo caso probabilmente il sistema avrebbe avvisato di un errore dato che nella configurazione dell'host C si sarebbe impostata la maschera con 7 bit e il default gateway (router) con l'indirizzo .254, e questo avrebbe portato ad un errore dato che per l'host C quell'indirizzo non può esistere.
- *Caso 2*
  Se l'host A ha indirizzo .254 e il router .3 l'host C vedrà il router e se vorrà comunicare con A dovrà passare dal router, questo perché l'host C crederà che A sia in un altra rete quando invece si trova nella sua. Questo può portare a traffico inutile mandato verso il router, che potrebbe evitare di spedire quei frame (perché C potrebbe mandarli direttamente ad A senza passare dal router se lo vedesse) e in più qui il sistema non genererà errori perché nel default gateway dell'host C il router è visibile. 
  - Va detto che se il router dispone di IDS (Intrusion Detection System) probabilmente quest'ultimo bloccherà il frame mandato dall'host C credendolo un qualche tipo di attacco (perché per lui non ha senso che C mandi un frame al router anziché mandarlo direttamente ad A)

*Scenario 2 (/23)*
Abbiamo solo un caso. Qui gli indirizzi vanno da 1.1.0.0 a 1.1.1.255 per l'host C perché avrà una maschera che gli darà 512 indirizzi (9 bit $2^9 = 512$), in questa configurazione C potrà raggiungere tutti gli indirizzi della sua rete 1.1.1.0 (sia host A che router senza problemi) ma crederà di essere in una rete anche con gli indirizzi 1.1.0.0 (quando in realtà saranno una rete diversa), C tenterà quindi di comunicare con questi ultimi senza successo e C penserà che la LAN abbia dei problemi

---
*Un canale di comunicazione ha queste caratteristiche:*
- Utilizza l'algoritmo di go-back-n
- Ha un ritardo di 100ms -> tempo propagazione solo andata
- La bandwidth in andata è 1Mbps
- La bandwidth al ritorno è 10Kbps
- L'intestazione del frame è di 1000bytes
- Il payload del frame è di 9000bytes           TOT frame = 10000bytes
- Il messaggio di ACK è di 100bytes

Calcolare il valore minimo della finestra tale che il troughput sia di 500Kbps
Questa è la finestra di funzionamento di go-back-n
![[SmartSelect_20260527_110943_Samsung Notes.jpg|616]]
L'host A manda 2 pacchetti prima di aspettare l'ACK, una volta che il primo ACK è arrivato ricomincia a mandare

Adesso andremo a calcolare il tempo di frame: ovvero il segmento nero.
$$T_{frame} ∝ \frac{bits}{bandwidth}$$ Andremo a calcolarlo sia per il frame che per l'ACK:
- Frame 
  $$\frac{10000\,\,x\,\,8}{10^6} = \frac{80000}{10^6} = \frac{8\,\,x\,\,10^4}{10^6} = 8\,\,x\,\,10^-2$$
- ACK
  $$\frac{100\,\,x\,\,8}{10^4} = \frac{800}{10^4} = \frac{8\,\,x\,\,10^2}{10^4} = 8\,\,x\,\,10^-2$$
Quindi per entrambi il tempo di frame è 80ms
La formula richiede il calcolo in bit quindi abbiamo moltiplicato per 8, nel frame abbiamo diviso per $10^6$ perché la bandwidth è 1Mbps mentre per l'ACK era 10Kbps quindi $10^4$

- Il tempo per inviare quindi 9000bytes di carico utile è: 80+100+80+100 ms = 360ms in bit al secondo sarebbero: $\frac{9000\,\,x\,\,8}{360\,\,x\,\,10^3} = 200000 = 200Kbps$

Adesso dobbiamo trovare la finestra minima ($N$)per avere un troughput di 500Kbps (il prof non lo ha fatto a lezione)

Per il go-back-n la formula è:$$Th = \frac{N \times \text{Bit Utili}}{RTT}$$
Dove:
- **Bit Utili** = $9000 \times 8 = 72.000 \text{ bit}$
- **RTT** = $360 \text{ ms} = 0,36 \text{ s}$
- **Th desiderato** = $500 \text{ Kbps} = 500.000 \text{ bps}$

Sostituiamo i dati:
$$500.000 = \frac{N \times \text{72.000}}{0,36}$$
Moltiplichiamo per $0,36$:
$$180.000 = N \times 72.000$$
Dividiamo per $72.000$:
$$N = \frac{180.000}{72.000} = 2,5$$
Dato che $N$ deve essere un intero avremo che $N = 3$ per avere almeno 500Kbps come troughput.

---
*Calcolo CRC*
Supponiamo che il polinomio generatore G fornito dallo standard sia 11001 e che la sequenza da controllare sia 10011011101000
Dovremo dividere la sequenza da controllare per il generatore attraverso una operazione di XOR.
> [!tip] **Regola**
> Divido la sequenza per il generatore con XOR, se il primo bit della sequenza è 1 altrimenti shifto a destra e abbasso un numero nella divisione

![[Pasted image 20260527114558.png|522]]

Gli ultimi 4 bit sono il resto, **il resto è sempre K-1 dove K è la lunghezza di G**, nel nostro caso $K = 5$ quindi il resto sarà 4 bit
Il mittente adesso dovrà solo spedire la sequenza concatenata con il resto 10011011101000-0010

---
*Dati due indirizzi indicare quale maschera dovrei usare per farle comunicare:*
>[!tip] **Regola**
>Due host comunicano direttamente (senza router) solo se la parte "Network" del loro indirizzo è identica
```
Indirizzo 1: 3.4.33.42
Indirizzo 2: 3.34.2.68
```
In questo caso la soluzione è una maschera /8 cioè solo i primi 8 bit sono della rete

---
*Configurazione di rete*
![[photo_5814423968692243958_y.jpg|586]]
Il prof ha fatto un albero in cui assegnava alle varie reti un tot di indirizzi.
La maschera /20 è sbagliata perché gli indirizzi non bastano per tutte le reti, serve almeno /19
![[SmartSelect_20260527_115903_Samsung Notes.jpg|454]]
(Non so altro, non so se così l'esercizio è finito o bisogna fare altro)

---
*Esercizio sul codice di Hamming*
[[RETI-COMPLETO.pdf| Copiato dalla spiegazione ed esempio CODICE DI HAMMING, in RETI-COMPLETO.pdf]]
E' composto da 2 fasi: una di creazione del messaggio e una di verifica e correzione (per il destinatario)
- **Parte 1 - creazione messaggio**
  L'obbiettivo qui è prendere i bit contenenti i dati e infarcirli con altri bit di controllo in modo che diventino resistenti agli errori
  Indicheremo con $b_r$ i bit di controllo, questi bit vanno posizionati solo negli indici che sono potenze di 2.
  Prendiamo la stringa di esempio: `xx1x001x0`
  Mettiamo in fila le posizioni da 1 a 9 e vediamo cosa c'è dentro:
	- Pos 1: **$b_1$** (bit di controllo, indicato con `x`)
	- Pos 2: **$b_2$** (bit di controllo, indicato con `x`)
	- Pos 3: $b_3 = 1$ (dato)
	- Pos 4: **$b_4$** (bit di controllo, indicato con `x`)
	- Pos 5: $b_5 = 0$ (dato)
	- Pos 6: $b_6 = 0$ (dato)
	- Pos 7: $b_7 = 1$ (dato)
	- Pos 8: **$b_8$** (bit di controllo, indicato con `x`)
	- Pos 9: $b_9 = 0$ (dato)
 
 Come troviamo il valore delle $x$? 
 La regola dice che ogni bit di controllo "sorveglia" uno specifico numero di bit:
>[!important] **REGOLA**
>Un bit di controllo in posizione $X$ sorveglia tutte e sole le posizioni che, scritte in binario, hanno un **1** nello stesso posto in cui ce l'ha la posizione $X$.
>Facciamo gli esempi concreti (usiamo 4 cifre binarie per comodità):
>- **Il bit $b_1$ (posizione 1):** In binario il numero 1 si scrive `0001`. L'uno si trova nell'**ultima cifra a destra**. Quindi $b_1$ sorveglia tutte le posizioni che in binario finiscono con 1. Quali sono i numeri che finiscono con 1 in binario? Esattamente i **numeri dispari**: 1 (`0001`), 3 (`0011`), 5 (`0101`), 7 (`0111`), 9 (`1001`), ecc.

L'operazione usata è lo *XOR* (se i bit sono uguali il risultato è 0, se sono diversi è 1
![[Pasted image 20260506124255.png|447]]

Sostituendo i valori calcolati ($b_1=0, b_2=0, b_4=1, b_8=0$) al posto delle `x` nella stringa di partenza, otteniamo il messaggio pronto per essere spedito: **`001100100`**

- **Parte 2 correzione**
![[Pasted image 20260506124528.png|319]]
Adesso il destinatario (che non sa ancora se c'è un errore) riesegue la stessa operazione di XOR di prima sugli stessi bit, i risultati trovati vanno confrontati con i bit di controllo (nelle pos. potenze di 2) e se sono uguali non ci sono errori, se sono diversi c'è un errore:
![[Pasted image 20260506124720.png]]

Per trovare il bit errato basta sommare gli indici dei bit di controllo che hanno fallito il test: in questo caso $b_2 + b_4 = b_6$ -> l'errore è in posizione 6. 
**Correzione**
Per correggere semplicemente eseguiamo un bit flip

---
*Distance vectors-Bellman-Ford*
![[Pasted image 20260628104253.png]]