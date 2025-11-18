Dobbiamo capire come è fatta la luce e il colore 

Sir Isaac Newton scoprì che se si fa passare un raggio di luce attraverso un prisma di vetro si riesce a scomporre la luce in tutte le sue varie lunghezze d'onda
![[Pasted image 20251105145301.png]]

Noi percepiamo solo le frequenze che appartengono alla luce visibile ma la luce non è solo questo anzi:
![[Pasted image 20251105145453.png]]

I colori sono legati alla lunghezza d'onda

![[Pasted image 20251105145633.png]]

Per comodità lo spettro del visibile è diviso in sei regioni: violetto, blu, verde, giallo, arancio e rosso

Le bande di colore non sono tutte della stessa grandezza e degradano in quelle limitrofe

Noi percepiamo il colore in base alla lunghezza d'onda che l'oggetto riflette, se rifletto le lunghezze d'onda relative al rosso vedremo l'oggetto come rosso, se le assorbe tutte lo vediamo come bianco al contrario come nero

**Per descrivere la luce bastano queste 3 grandezze**
- Radianza
  cioè la quantità di luce emessa dalla sorgente luminosa
- Luminanza
  cioè la misure dell’energia percepita dall’utente
- Brillantezza
  è un valore soggettivo che indica la sensazione di colore


**Non esiste una misura per misurare il colore perché è soggettivo e dipende da molti fattori che influenzano l'osservatore**

Differenze di sorgenti luminose:
luce solare, lampade ad incandescenza, neon,… 

Differenze di osservatore:
sensibilità, vista,… 

Differenze di dimensioni:
Effetto area = colori che ricoprono vaste superfici appaiono più luminosi e vivaci 

Differenze di sfondo:
Effetto contrasto = colori appaiono più cupi se lo è sfondo scuro 

Differenze di direzione:
Caratteristiche direzionali di alcune vernici costanza degli angoli di osservazione e di illuminazione


Qualsiasi luce di spettro complesso può essere ottenuta come “somma” di tre luci monocromatiche agenti simultaneamente.
La CIE, partendo dall’ipotesi che tutti i colori possono essere valutati in termini di tre componenti pure, ha scelto le tre radiazioni primarie in modo che le lunghezze d’onda siano il più possibile distanziate nello spettro. 
- Rosso 700.0 nm 
- Verde 546.1 nm 
- Blu 435.8 nm

Questo è lo standard imposto dalla CIE nel 1931 anche se misurazioni sperimentali nel 64 hanno modificato leggermente i valori:
- Blue = 445 nm
- Verde = 535 nm
- Rosso = 575 nm


**Stabdard CIE**
![[Pasted image 20251105155551.png|600]]

 Se $x$ è la quantità di rosso 
 Se $y$ è la quantità di verde 
 $z$ è la quantità di blu ottenuta come $z = 1- (x + y)$


**Diagramma cromatico CIE**
![[Pasted image 20251105155746.png]]

Unendo due colori con una linea, tutti i colori nella linea sono quelli ottenibili mischiando i due colori. 
Unendo un colore con il bianco si ottengono tutti le tonalità di quel colore

Unendo tre colori con un triangolo, tutti i colori lungo il bordo e nel triangolo sono quelli ottenibili mischiando quei tre colori

**RGB**
 Unendo R G e B si ottiene un triangolo che contiene tutti i colori che si possono produrre. 
 Da notare che il triangolo non copre tutta l’area, quindi non tutti i colori si ottengono unendo R G e B

**SPAZIO CIE xyz**
I valori del tristimolo necessari a formare un colore possono essere determinati attraverso formule matematiche, ad esempio il diagramma di cromaticità CIE che mostra la composizione di un colore in funzione di x e y mentre il corrispondente valore di z è calcolato direttamente dalla $z = 1 - (x+y)$ 
x è la quantità di rosso
y è la quantità di verde
z è la quantità del blu
Il diagramma di cromaticità CIE 1931, è solo una "fetta" di uno spazio più completo, lo spazio dei colori CIE 1931 al quale si assegnano le coordinate XYZ

Scopo di un modello del colore (o spazio dei colori o sistema dei colori) è di consentirne la specificazione dei colori con modalità standardizzate, che fanno normalmente riferimento ad un sistema di coordinate 3-D

I modelli del colore più utilizzati in image processing sono vari ad esempio:
- RGB
- CMY
- YUV
- HSI

**CIE $L^*a^*b^*$**
Il principale difetto del sistema CIE (e di tutti i modelli del colore da esso derivati mediante trasformazioni lineari o non lineari di coordinate) è che esso non è dotato di uniformità percettiva
In altre parole, dati due colori C1 e C2, consideriamone le distanze ∆C, rispettivamente, dal colore C3 = C1 + ∆C e dal colore C4 = C2 + ∆C. Supponendo che le due distanze siano quantitativamente uguali, sarebbe desiderabile che i due colori C3 e C4 fossero percepiti come ugualmente distanti da C1 e C2. Dato che il sistema non è percettivamente uniforme, in generale le due distanze, benché uguali, saranno percepite come differenti

Nel 1976 la CIE ha standardizzato 2 spazi di colore che avessero uniformità percettiva
- CIE $L^*a^*b*$
- CIE $L^*u^*v^*$ 

**FORMULE**
Attraverso delle formule si può passare a spazi di colore differenti, queste sono quelle per passare da CIE $XYZ$ a CIE $L^*a^*b*$ 
![[Pasted image 20251110094521.png]]


La **metrica CIELAB** è percettivamente uniforme e:
$L^*$ rappresenta la **luminanza**
$a^*$ e $b^*$ rappresentano la **crominanza**
Nello spazio CIELAB le differenze di colore sono definite come distanza tra due punti dello spazio L* a* b*

Uguali differenze corrispondono a uguali differenze di percezione. 
Questo è un pregio di questo sistema

• Delta E=1 accettato nell’industria dei cosmetici 
• Delta E=0,01 accettato nella Ferrari

![[Pasted image 20251110095300.png|600]]
Questo è lo spazio CIELAB in cui abbiamo le 3 coordinate:
$L^*$ è la luminosità (0 nero, 100 bianco)
$a^*$ e $b^*$ = coordinate di cromaticità 


**Modello LCh**
Il modello di colore LCh è uno **spazio di colore cilindrico** derivato dal più noto spazio **CIELAB**.

In pratica, rappresenta i colori in modo più intuitivo per l’occhio umano, usando tre componenti:

- **C (Chroma)**: indica l’intensità o la saturazione del colore (quanto è “vivo” o “spento”).
    
- **H (Hue)**: rappresenta la tonalità, cioè il tipo di colore percepito (rosso, verde, blu, ecc.), espresso in gradi da 0° a 360°.
    
- **L (Lightness)**: misura la luminosità, da 0 (nero) a 100 (bianco).
    

Rispetto a RGB o LAB, il modello CHL/LCh è **più vicino alla percezione umana**, perché separa chiaramente la componente luminosa da quella cromatica. Per questo motivo è spesso usato in grafica, fotografia e design per modificare i colori in modo naturale (ad esempio schiarendo senza alterare la tonalità)
![[Pasted image 20251110120611.png|650]]



**BIANCO E NERO**
Le coordinate del nero matematico sono $X = 0, Y = 0, Z = 0$
Il nero matematico però in natura non esiste perché ogni oggetto rifletterà almeno un po' di luce
- In media il fattore di riflessione di una misurazione di un oggetto nero è nell'ordine di qualche punto percentuale (2-4%)
- Il nero più nero è quello del velluto nero

Per quanto riguarda il bianco, quello equienergetico (teorico) le sue coordinate sono $X = 1, Y = 1, Z = 1$
Nella realtà il bianco dipende dalla luce che illumina l'oggetto, per esempio una lampadina o il sole producono un bianco diverso

### **SPAZI DI COLORE**
In natura raramente si vedono colori puri, quasi sempre si tratta di un miscuglio di più lunghezze d'onda di radiazione luminosa
- Il nostro cervello non è uno spettrometro, spettri differenti producono sensazioni cromatiche uguali
- Manteniamo la stessa percezione del colore anche se la luce che lo illumina cambia


Lo “spettro” di un illuminante è il diagramma dei contributi di energia che esso apporta per ciascuna differente lunghezza d’onda

Spettri diversi possono produrre colori eguali: coppie di spettri con questa reciproca proprietà si chiamano *metameri.*
![[Pasted image 20251110195406.png]]

Lo spettro tratteggiato e quello continuo producono (nel cervello) il medesimo colore!


**Modello del pittore**
Basi fisiche
![[Pasted image 20251111142826.png]]

La lunghezza d'onda in cui si ha il picco da il colore percepito

Il rapporto (epicco-emedia)/(epicco+emedia) è la SATURAZIONE, cioè quanto il colore è puro. Meno luce bianca equivale ad un maggiore valore del rapporto.

emedia è proporzionale al contenuto energetico della radiazione: essa può essere considerata una misura della “luminosità” di una radiazione (detto anche VALORE). Esso da un contributo “bianco” al colore percepito

![[Pasted image 20251111143017.png]]

Unendo geometricamente tutti i vari triangoli dei vari colori otterremo il modello **HSV**

**Spazio HSV (oppure HSI)**

- H = hue (colore); copre tutti i colori ordinati in sequenza

- S = saturazione; da un minimo (centro) pari al bianco puro ad un massimo (periferia) colore puro

- V = valore o luminosità; da un minimo (nessuna energia emessa) ad un massimo


**SINTESI ADDITIVA**
I colori vengono creati a partire dai 3 colori primari rosso, verde, blu (RGB) infatti unendo i vari colori in uno schema a cerchi possiamo ottenere il bianco, il giallo, il magenta e il ciano, questo è alla base degli schermi di monitor e TV
![[Pasted image 20251111143757.png|350]]

2 colori si dicono complementari quando la loro somma da il bianco
il magenta è complementare del verde, il giallo del blu e il ciano del rosso

Quindi questo metodo somma vari colori per ottenere gli altri, ma esiste anche un altro modo per creare i colori:

**SINTESI SOTTRATTIVA**
Abbiamo un Filtro Ottico Colorato = mezzo a facce piane e parallele che attraversato dalla luce bianca ne assorbe selettivamente una porzione

Il filtro assume il colore prodotto dalla radiazione complementare di quella che viene assorbita come accade alle sostanze colorate

Sovrapponendo tre filtri di colore giallo (Y), magenta (M) e ciano (C) su un visore luminoso bianco si ottengono i colori per sintesi sottrattiva
![[Pasted image 20251111144157.png|300]]
Sovrapponendo tutti e tre i filtri viene assorbita tutta la radiazione visibile per cui si ottiene il Nero (K). Sovrapponendo due filtri si ottiene il colore corrispondente alla componente luminosa che non viene assorbita da nessuno dei due

(in breve Sintesi Sottrattiva = aggiunge un filtro viene “sottratta” una componente che modifica il colore della luce)

Su questo metodo si basano la stampa a colori e le foto a colori
Infatti le stampanti usano inchiostri tipicamente ciano, magenta e giallo che impressi su una superficie riflettente come la carta, quando la luce li colpisce, assorbono selettivamente delle lunghezze d'onda e noi percepiamo quella riflessa

I 2 diagrammi in breve:
![[Pasted image 20251111153035.png|500]]



**COLORI PRIMARI E SECONDARI**

Nel modello RGB il rosso il verde e il blu sono i colori primari, unendoli non si possono creare tutti i colori ma solo Magenta M, Giallo Y e Ciano C che sono i colori secondari
Il modello RGB può essere descritto da un cubo

**PRO**:
- Facile da usare e implementare in software e hardware
- E' uno standard

**CONTRO**:
- percettivamente poco comodo: difficile capire guardando un colore in natura in quale proporzione vi contribuiscano l’R, il G e il B

Esempi di come funziona l'RGB:
![[Pasted image 20251111154101.png]]

Il giallo è formato da rosso e verde ma niente blu, e infatti in R e G i Simpson sono chiari mentre in B sono scuri perché non c'è blu nel giallo

**RIEPILOGANDO**
- Le rappresentazioni dei colori nello spazio RGB (o CMY il duale) non sempre sono le più convenienti

- Sono disponibili altre rappresentazioni che usano componenti che sono specificatamente relazionate al criterio usato per descrivere la luminanza, la tinta e la saturazione (HSV)

- La tinta descrive che colore è presente (rosso, verde, giallo, ecc.) e può essere correlato alla lunghezza d’onda dominante della sorgente di luce

- La saturazione, invece, esprime quanto è vivo il colore (molto forte, pastello, vicino al bianco) e può essere correlato alla purezza o alla distribuzione dello spettro della sorgente

- La luminanza è la grandezza che tende a valutare la sensazione luminosa ricevuta dall'occhio, è legata quindi all’intensità della luce (quanto il colore è bianco, grigio o nero) e può essere correlata alla luminosità della sorgente

**COLORI SICURI PER IL WEB**
Si sa che 40 dei 256 colori usati tipicamente per il web, vengono processati in modo diverso da vari tipi di sistemi operativi, mentre 216 colori sono comuni alla maggior parte dei sistemi,
Questi 216 colori sono diventati gli standard di fatto dei colori sicuri, specialmente nelle applicazioni Internet. Essi vengono utilizzati quando si vuole che i colori visti dalla maggior parte delle persone siano gli stessi
Sono in RGB e il numero decimale può essere solo composto da:
00, 33, 66, 99, CC, FF
Quindi sono colori sicuri tutti quelli che in esadecimale sono scritti usando terne con questi 6 possibili lavori: ad esempio #33CCFF è sicuro mentre non lo è il colore #12A3FE

![[Pasted image 20251118161714.png]]


**Rappresentazioni luminanza-crominanza**
Gli spazi di colore che hanno una componente legata alla luminosità e le altre 2 alla crominanza sono molto importanti e sono usate per la compressione di immagini, la luminanza fornisce un immagine a scala di grigi dell'immagine, mentre la crominanza fornisce gli extra per aggiungere il colore, l'occhio umano è più sensibile alla luminanza che ai colori quindi posso usare più bit per rappresentare la luminanza e meno per la crominanza risparmiando spazio


**FAMIGLIA YUV**
La famiglia di spazi di colore YUV viene spesso utilizzata per la codifica di immagini o video analogici, tenendo separate la luminanza dalla crominanza

Tra le possibili controparti digitali degli spazi YUV troviamo gli spazi $YC_bC_r$

**Da RGB a YUV**
La luminanza Y si ottiene mediante la somma pesata:
$Y = 0.299𝑅 + 0.587𝐺 + 0.114𝐵$

Il termine crominanza è definito come la differenza tra il colore e un bianco di riferimento alla stessa luminanza opportunamente pesato
$U = 0.564(𝐵 − 𝑌) → U = −0.169𝑅 − 0.331𝐺 + 0.5𝐵$
$V = 0.713 𝑅 − 𝑌 → V = +0.5𝑅 − 0.419𝐺 − 0.081𝐵$

**Da YUV a $YC_b C_r$**
![[Pasted image 20251118163513.png]]

in questo spazio $Y$ rappresenta la luminanza, $C_b$ la crominanza del blu e $C_r$ quella del rosso


**PALETTE**
Nelle immagini io dovrei ricordare per ogni pixel il colore rosso il blu e il verde che sarebbero 8 bit + 8 bit + 8 bit = 24 bit per pixel, nelle immagini grandi formate da ad esempio 2600x2300 pixel la memoria richiesta sarebbe troppa, quindi dato che un immagine è praticamente una matrice, posso semplicemente ricondurre ogni pixel ad un indice della matrice che corrisponde al colore che rappresenta quel pixel e inoltre creo una palette di colori che uso per "ricostruire l'immagine" con i giusti colori:
![[Pasted image 20251118164443.png]]

Esistono delle palette di colore standard in base al sistema in uso, ovviamente se nell'immagine avrò più colori di quelli che la mia palette ha alcuni colori dovranno essere approssimati
**Esempio**
![[Pasted image 20251118164707.png]]![[Pasted image 20251118164719.png]]![[Pasted image 20251118164733.png]]
![[Pasted image 20251118164744.png]]

![[Pasted image 20251118164919.png]]

