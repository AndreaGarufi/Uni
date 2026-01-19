Con il termine compressione dati si indica la tecnica di elaborazione dati che, attuata a mezzo di opportuni algoritmi, permette la riduzione della quantità di bit necessari alla rappresentazione in forma digitale di una informazione
La compressione riduce la dimensione del file e anche la quantità di banda necessaria per una generica trasmissione dati

Un dato è ridondante quando all'interno di un file esso è irrilevante o ripetuto

Dal momento che la maggior parte degli array di intensità 2-D sono relazionati spazialmente (per es. ciascun pixel è simile ai pixel del suo intorno, o dipende da esso), l’informazione è replicata inutilmente nei pixel correlati
In una sequenza video, i pixel correlati temporalmente (per es. simili o dipendenti dai pixel dei frame vicini) rappresentano anch'essi un’informazione duplicata
Spesso i dati contengono informazioni ignorate dal sistema sensoriale umano.E’ ridondante nel senso che non viene utilizzata

**Algoritmo di compressione**
Un algoritmo di compressione è una tecnica che elimina la ridondanza di informazione dai dati e consente un risparmio di memoria 
![[Pasted image 20260109113503.png|400]]
Lo possiamo riassumere così

La compressione è basata sul tipo di dati (audio,immagini,video ecc...) e sul *tipo di compressione* ovvero:
- **lossless** (reversibile), cioè senza perdita di informazione
- **lossy** (irreversibile), cioè con una perdita di informazione

**Criterio per una buona compressione di tipo lossless**
Cercare di raggiungere il limite teorico per la compressione senza perdita che viene fornito dal primo teorema di Shannon, ma prima vediamo altre nozioni importanti:
**Frequenza**
Sia data una sequenza S di N caratteri tratti da un alfabeto di M possibili caratteri: $a_1 ,…,a_M$. Sia $f_i$ la frequenza del carattere $a_i$ cioè:
$f_i = (\#occorrenze\,\,\, a_i)/N$
**Entropia**
Definiamo entropia E della sequenza di dati S la quantità media di informazione associata ad un singolo simbolo nella sequenza S:
- Se un simbolo è molto prevedibile, porta poca informazione.
    
- Se un simbolo è totalmente inaspettato, porta molta informazione
Questa è la formula:
$$E = - \sum f_i \log_2(f_i)$$
- $f_i$: rappresenta la **frequenza** (o probabilità) con cui appare il simbolo $i$-esimo nella sequenza.
    
- $\log_2$: si usa il logaritmo in base 2 perché l'informazione si misura solitamente in **bit**.
    
- Il segno meno ($-$) serve a rendere il risultato positivo (poiché il logaritmo di una frazione è negativo)

Un concetto fondamentale è:
- **Più incertezza = Più entropia:** Se non hai idea di quale simbolo uscirà dopo, l'entropia è alta. Se la sequenza è monotona (es. "AAAAA"), l'entropia è quasi zero perché non c'è sorpresa.
    
- **Il caso massimo (Equiprobabilità):** L'entropia è massima quando tutti i simboli hanno la stessa probabilità di apparire

**Teorema di Shannon**
«per una sorgente discreta e a memoria zero, il bit rate minimo è pari all'entropia della sorgente» 
I dati possono essere rappresentati senza perdere informazione (lossless) usando almeno un numero di bit pari a: $N*E$ 
Dove N è il numero di caratteri mentre E è l’entropia

Shannon ci dice il numero minimo di bit ma non ci dice come trovarli, ci serve quindi un algoritmo che permetta di codificare i nostri caratteri usando esattamente il numero di bit ricavati con il teorema di Shannon

**Un algoritmo che fa ciò è stato proposto da Huffman**
David Huffman ha proposto un semplice algoritmo greedy che permette di ottenere un “dizionario” (cioè una tabella carattere- codifica_binaria) per una compressione quasi ottimale dei dati cioè pari al limite di Shannon con un eccesso di al più qualche bit
**Proprietà**
-  Si tratta di codifica a lunghezza variabile che associa a simboli meno frequenti i codici più lunghi e a simboli più frequenti i codici più corti. 
- Si tratta di una codifica in cui nessun codice è prefisso di altri codici. 
- È una codifica ottimale perché tende al limite imposto dal teorema di Shannon
**Come funziona in breve**
- È un algoritmo iterativo. Ad ogni iterazione si scelgono i due nodi con frequenza più bassa. 
- Questi due nodi vengono collegati per formare un sottoalbero la cui frequenza del nodo padre è la somma delle frequenze dei due nodi. 
- Se ci fossero più nodi con peso minimo se ne scelgono solo due. 
- Se c’è un solo nodo con frequenza più bassa si seleziona tale nodo e poi si prende da seconda frequenza più bassa e si seleziona un nodo con quella frequenza
- Si deve creare un albero binario bilanciato.
- Al termine delle iterazioni la radice avrà peso 1. 
- Si etichetteranno i rami a sinistra con codice 1 e quelli a destra con codice 0.
- Il codice che si forma procedendo dalla radice alla foglia è il codice abbinato al carattere presente nella foglia stessa

C'è un esempio ben fatto nel power point [[11 Lez 13 compressione 2024-25.pdf|11 compressione]] dalla slide numero 22 alla 26

Dopo l'algoritmo avremo ottenuto la codifica che ci interessa, servirà un altro po di memoria per memorizzare la tabella che contiene la codifica
L'algoritmo di Huffman è usato nei seguenti standard di compressione: CCITT, JBIG2, JPEG, MPEG-1,2,4

**Altri algoritmi LOSS LESS**
**Run Lenght Encoding**
![[Pasted image 20260109150043.png]]
![[Pasted image 20260109150057.png]]

**Codifica Differenziale**
![[Pasted image 20260109150419.png]]
+3,+1,+6,-4,0,-22 ...
Si dimostra sperimentalmente che per le immagini la sequenza delle differenze ha una entropia minore di quella dei valori originali e quindi richiede meno bit per essere memorizzata

**Compressione Lossy**
Si parla di compressione LOSSY quando i dati possono essere trasformati in modo da essere memorizzati con risparmio di memoria ma con perdita di informazione. *Tale tipo di compressione produce un maggiore risparmio di memoria!*

- Fissata la massima distorsione accettabile l’algoritmo di compressione deve trovare la rappresentazione con il più basso numero di bit. 
- Viceversa, fissato il massimo numero di bit accettabile occorre trovare il miglior algoritmo di compressione che a parità di numero di bit mi dia la minima distorsione
![[Pasted image 20260109150736.png|400]]

L'idea della compressione lossy è: *Se “percettivamente” non è importante: buttalo via!*
- MP3 : applicano questa idea al caso del suono e della musica; 
- JPEG : applicano questa idea alle immagini fisse (still images) 
- MPEG, AVI, DVX etc: applicano questa idea alle sequenze di immagini (filmati)

Ovviamente una volta buttata via l’informazione non può essere ricostruita esattamente: si tratta di compressione IRREVERSIBILE

Noi vedremo soltanto:
1) Un algoritmo di requantization;
2) Il JPEG

**Requantization**
- Si tratta molto semplicemente di una riduzione del numero di livelli disponibili in modo da risparmiare bit per pixel. 
- La si realizza “dimenticando” n bit meno significativi per canale. 
- Per esempio: RED: da 8 bit si conservano solo i 4 più significativi; 
- GREEN: da 8 bit si conservano solo i 6 più significativi; 
- BLUE: da 8 bit a si conservano solo i 2 più significativi. 
- Si risparmia così il 50% dei bit inizialmente necessario! In più: se ci sono meno simboli … la compressione LZW o Huffman è più efficiente!
- *Ma c'è una forte perdita di qualità*
![[Pasted image 20260109180154.png]]

**Lo standard JPEG**
Passi fondamentali della codifica JPEG:
1) Pre-processing: 
   i. Color Transform (RGB → $YC_b C_r$); 
   ii. Sottocampionamento della crominanza 
   iii. Suddivisione della immagine in sottoimmagini. 
2) Trasformazione: 
   i. Discrete Cosine Transform; 
   ii. Quantization; 
3) Codifica: 
   i. DC Coefficient Encoding; 
   ii. Zig-zag ordering of AC Coefficients; 
   iii. Entropy Coding (Huffman).

**Pre-processing**
Iniziamo con il *color transform (i)* appunto dallo spazio RGB a $YC_b C_r$
Applichiamo la formula:
![[Pasted image 20260109180653.png|400]]

*sottocampionamento della crominanza (ii)*
In questo modo abbiamo un canale separato $Y$ per la luminanza e possiamo sfruttarlo a nostro vantaggio, infatti l'occhio umano è più sensibile alla luminanza che alla crominanza quindi JPEG conserva tutta la luminanza ma campiona i 2 valori di crominanza, scegliendo 1 valore per ogni 4 per $C_b$ e $C_r$
 Questa operazione è lossy ed è irreversibile

*partizione dell'immagine*
JPEG suddivide l'immagine in quadretti da 8x8 cioè 64 pixel NON sovrapposti, quadretti diversi subiranno una elaborazione differente ed è questa l'origine del problema della quadrattatura che si verifica quando le immagini compresse con JPEG vengono zoommate o stampate
![[Pasted image 20260109181651.png]]

**Shift dei livelli di grigio**
- Prima della applicazione della DCT ai 64 pixel di ciascun blocco viene sottratta una quantità pari a $2^{n-1}$, dove $2^n$ rappresenta il numero massimo di livelli di grigio dell’immagine. 
- Se il blocco considerato presenta 256 = $2^8$ possibili livelli di grigio, a ciascun pixel di tale blocco verrà sottratto un offset pari a 128 = $2^7$. 
- Con questo processo, noto come shift dei livelli di grigio, il grigio medio (128) diventa 0
Esempio
![[Pasted image 20260109181937.png|600]]

**Trasformazione**
*Trasformata discreta del coseno DCT(i)*
Il JPEG trasforma i blocchi 8 x 8 di pixel secondo un algoritmo detto DCT, è un algoritmo della famiglia delle trasformate di Fourier, 

E’ stato dimostrato che, statisticamente, tale trasformazione “*decorrela*” al massimo i dati permettendo maggiori rapporti di compressione nella fase successiva di codifica.
Decorrela in questo contesto indica che questa DCT separa i dati non rendendoli più interdipendenti, detto in breve se ho 64x64 pixel di cielo azzurro con variazioni minime ne prendo un valore medio anziche il valore di ogni singolo pixel, risparmiando spazio

*Quantizzazione(ii)*
Un vantaggio in termini di simboli da usare (e quindi in termini di lunghezza dei codici Huffman) si ottiene se si riduce il numero di “livelli” su cui i coefficienti della DCT possono variare. Tale operazione permette di rappresentare i diversi coefficienti incrementando il fattore di compressione, più precisamente avviene un processo di riduzione del numero di bit necessari per memorizzare un valore intero riducendone la precisione

Il valore F quantizzato si ottiene come :
$$F_{quantizzato} = round(F/Q)$$
dove Q è un fattore di quantizzazione, F è un numero da quantizzare.
Il valore ricostruito si ottiene moltiplicando $F_{quantizzato}$ per Q
La quantizzazione è un processo irreversibile (lossy)

Si è dimostrato che non è conveniente usare un unico fattore di quantizzazione per tutti i 64 coefficienti della DCT della luminanza, o per quantizzare i valori provenienti dalla DCT delle crominanze, quindi si utilizzano 2 fattori diversi forniti dallo standard o eventualmente uno fornito dall'utente (a cui però poi va aggiunta la tabella che deve essere trasmessa non essendo uno standard)
![[Pasted image 20260110200312.png]]

Si osservi che un fattore di compressione maggiore comporta una maggiore perdita di informazione e quindi una qualità visiva minore
L’utente del JPEG può scegliere il “grado” di quantizzazione da adottare fornendo un “quality factor” QF che va da 1 a 100. Maggiore è il QF e minore sarà la perdita di informazioni. Quindi fattore di qualità e fattore di compressione sono l’uno l’inverso dell’altro

**Effetto della quantizzazione**
![[Pasted image 20260110200422.png]]

**Codifica**
Tutti i coefficienti vengono riordinati in un vettore 64 x 1 seguendo l’ordinamento “a serpentina” (per creare lunghe run di zeri) e codificati in un altro stream
![[Pasted image 20260110200615.png|600]]

**A questo punto si hanno 2 differenti codifiche**
- I coefficienti DC, cioè quelli che stanno nella posizione (1,1) del blocco 8x8, sono codificati usando una codifica differenziale; 
- I coefficienti AC, cioè tutti gli altri del blocco, sono codificati usando una codifica run-length. 
- Le tabelle usate di seguito forniscono i codici di Huffmann ottenuti sulla base di calcoli statistici preventivi e sono fornite dallo standard

**(vedi codifiche -> [[11 Lez 13 compressione 2024-25.pdf|11 Compressione]] da slide 75 a 85)**

![[Pasted image 20260111153141.png]]
![[Pasted image 20260111153155.png]]

**Nella ricostruzione**
Si deve tornare indietro “ricostruendo” i dati originali (o le loro approssimazioni per i passi irreversibili)
A destra vediamo il blocco 8x8 di input                      A sinistra invece quello ricostruito
![[Pasted image 20260111153309.png]]
Sono diversi tra loro perché JPEG è lossy

![[Pasted image 20260111153417.png|500]]
![[Pasted image 20260111153457.png]]

![[Pasted image 20260111153521.png]]


