Prova in itinere A: Trasformazioni Affini e Interpolazione

**a) Cosa si intende per _Forward mapping_ e _Inverse mapping_?**

Spiegare in cosa differiscono i due approcci di mappatura quando si applica una trasformazione affine a un'immagine. Specificare quale dei due metodi è comunemente utilizzato da MATLAB e perché.

**b) A cosa serve l'interpolazione nel contesto delle trasformazioni affini?**

Definire il concetto di interpolazione e spiegare quali problemi si presentano (ad esempio, ai bordi dell'immagine) quando essa non viene applicata correttamente durante le trasformazioni. Citare tre diversi tipi di interpolazione utilizzati nell'elaborazione delle immagini.

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