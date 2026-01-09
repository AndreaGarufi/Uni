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
- **Lossy** (irreversibile), cioè con una perdita di informazione

**Criterio per una buona compressione di tipo lossless**
Cercare di raggiungere il limite teorico per la compressione senza perdita che viene fornito dal primo teorema di Shannon, ma prima vediamo altre nozioni importanti:
**Frequenza**
Sia data una sequenza S di N caratteri tratti da un alfabeto di M possibili caratteri: $a_1 ,…,a_M$. Sia $f_i$ la frequenza del carattere ai cioè:
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

