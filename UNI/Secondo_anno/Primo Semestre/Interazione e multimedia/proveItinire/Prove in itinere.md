Prova in itinere A: Trasformazioni Affini e Interpolazione

**a) Cosa si intende per _Forward mapping_ e _Inverse mapping_?**

Spiegare in cosa differiscono i due approcci di mappatura quando si applica una trasformazione affine a un'immagine.

RISPOSTA:
Il forward mapping si applica quando ho bisogno di usare una trasformazione affine (shear, rotazione,scaling ecc... . Inoltre una trasformazione affine è sostanzialmente una ricalcolo delle coordinate di un pixel nella posizione v,w , usando una matrice affine T e avendo quindi come output le nuove coordinate x,y del pixel), quindi per trovare le coordinate nuove $[x,y,1]$ applicherò questa formula: $[v,w,1] *T$.
Questa operazione potrebbe creare dei "buchi" all'interno dell'immagine e per risolvere questo problema si ricorre all'inverse mapping che elimina i "buchi" dall'immagine: si applica su $[x,y,1] * inversa(T)$ 

**b) A cosa serve l'interpolazione nel contesto delle trasformazioni affini?**

Definire il concetto di interpolazione e spiegare quali problemi si presentano (ad esempio, ai bordi dell'immagine) quando essa non viene applicata correttamente durante le trasformazioni. Citare tre diversi tipi di interpolazione utilizzati nell'elaborazione delle immagini.

RISPOSTA:
Alcune trasformazioni affini hanno bisogno di interpolare l'immagine affinché la trasformazione vada a buon fine, è il caso dello zooming, infatti se ad esempio zoommo in 2x la mia immagine m x n diventerà 2m x 2n quindi sarà il doppio e avrò il quadruplo dei pixel, quindi se zoommo e non faccio nulla avrò dei pixel vuoti nell'immagine. E' qui che interviene l'interpolazione che non aggiunge informazione all'immagine ma si limita a ricostruire dei dati sulla base di quelli esistenti, ne esistono di diverse tipologie:
nearest Neighbor (replication) è la più semplice ma anche quella meno efficace e al pixel da ricostruire applica il valore del pixel più vicino

bilinear che è più complessa della replication ma ha un effetto migliore, per ogni pixel da ricostruire assegna l'intensità dei 4 pixel più vicini ad esso
la formula è $v(x,y) = ax + by + cxy + d$ 

bicubic la più complessa ed assegna l'intensità al pixel da ricostruire in base a quella dei 16 pixel più vicini
la formula è $v(x,y) = Σ_{i = 0}^{3}Σ_{j = 0}^{3} a_{ij} (X^iY^i)$ 

Esistono alcuni punti critici come i bordi dell'immagine infatti se mi trovo al bordo e uso un algoritmo bilineare o bicubico potrei non avere i 4 o i 16 pixel più vicini su cui stimare l'intensità del pixel in esame, le soluzioni sono 2 : o non si fa niente o si interpola con i pixel a disposizione anche se in minor numero

**c) Matrice di trasformazione combinata.**

Nelle trasformazioni affini, le operazioni possono essere combinate moltiplicando le matrici corrispondenti. Scrivere la matrice risultante dalla combinazione di una Traslazione con uno Scaling , se la traslazione è definita da e lo scaling è definito da e .

--------------------------------------------------------------------------------

Prova in itinere B: Campionamento e Aliasing

**a) Definizione di Nyquist rate e Teorema di Shannon.**

Definire il _Nyquist rate_ e spiegare il _Teorema del campionamento di Shannon_. Secondo il teorema, cosa è necessario per ricostruire fedelmente il segnale?

**b) Il fenomeno dell'Aliasing.**

Descrivere in dettaglio cosa succede quando un segnale viene campionato ad una frequenza inferiore al Nyquist rate, definendo il fenomeno dell'_aliasing_. Spiegare in che modo un campionamento troppo basso può stravolgere un segnale, facendo riferimento alla perdita di dettagli e all'introduzione di nuovi dettagli.

**c) Esempio di applicazione del Nyquist rate.**

Se si analizza un quadro di 500 pixel di dimensione e si vuole garantire che il dettaglio massimo (il tratto più fine) misuri 5 pixel, calcolare il numero massimo di campioni che si dovrebbero prelevare per preservare tale dettaglio, e determinare qual è il Nyquist rate.

--------------------------------------------------------------------------------

Prova in itinere C: Rappresentazione Raster e Quantizzazione

**a) Rappresentazione di un'immagine digitale e convenzioni.**

Definire come viene rappresentata un'immagine digitale _raster_. Specificare le convenzioni utilizzate per contare le righe e le colonne di questa rappresentazione e dove è posta l'origine delle coordinate.

**b) Tipologie di Immagini e Bit per Pixel.**

Descrivere le tre principali tipologie di immagini (Bianco/nero, Scala di grigio, A colori) in base alla profondità di bit e al range di valori che un pixel può assumere in posizione . Spiegare inoltre in che modo il valore di una cella della matrice viene tradotto in colore (pixel).

**c) Quantizzazione Uniforme.**

Spiegare a cosa serve il processo di _quantizzazione_. Se un segnale analogico viene quantizzato, e si vuole portare un range di ingresso da livelli () ad un range di uscita di livelli () con quantizzazione uniforme, utilizzare la formula per calcolare il livello in uscita corrispondente a un livello di ingresso .