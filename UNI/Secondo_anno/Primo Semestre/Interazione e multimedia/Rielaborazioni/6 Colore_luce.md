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


