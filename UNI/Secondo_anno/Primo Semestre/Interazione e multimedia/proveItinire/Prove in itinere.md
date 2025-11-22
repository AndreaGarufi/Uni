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

RISPOSTA:
Il nyquist rate è la più alta frequenza del segnale moltiplicata per 2:
Ad esempio se la frequenza più alta nel segnale è 100hz il nyquist rate è 200hz

non capisco se sia giusta oppure no
(Si supponga avere un segnale analogico, se è costante allora la frequenza più alta è 1, altrimenti si divide in 2 parti creando 2 intervalli più piccoli, se negli intervalli il segnale si può considerare approssimativamente costante allora non devo creare altri intervalli altrimenti continuerò a dividere in intervalli più piccoli finché non otterrò intervalli talmente piccoli che potrò considerare il segnale come costante, sia N il numero degli intervalli allora 2N è il nyquist rate.)


Il teorema di shannon dice che per poter ricostruire il segnale fedelmente devo campionare con una frequenza pari o superiore al nyquist rate

**b) Il fenomeno dell'Aliasing.**

Descrivere in dettaglio cosa succede quando un segnale viene campionato ad una frequenza inferiore al Nyquist rate, definendo il fenomeno dell'_aliasing_. Spiegare in che modo un campionamento troppo basso può stravolgere un segnale, facendo riferimento alla perdita di dettagli e all'introduzione di nuovi dettagli.

RISPOSTA:
Se non si segue il teorema di shannon e si campiona ad una frequenza minore del nyquist rate si possono avere 2 problemi:
1) La perdita di informazione e la conseguente eccessiva approssimazione del segnale
2) La comparsa di artefatti falsi, ovvero l'aggiunta di informazione che però nel segnale originale non era presente, qui si parla di aliasing

**c) Esempio di applicazione del Nyquist rate.**

Se si analizza un quadro di 500 pixel di dimensione e si vuole garantire che il dettaglio massimo (il tratto più fine) misuri 5 pixel, calcolare il numero massimo di campioni che si dovrebbero prelevare per preservare tale dettaglio, e determinare qual è il Nyquist rate.

Se ho un immagine di 500 pixel e il tratto più fine da preservare è 5px posso campionare al suo nyquist rate ovvero 500/5 = 100 -> 200px quindi campionando a 200px o più (preferibilmente di più se si vuole avere una resa maggiore) posso ricreare l'immagine in maniera molto simile all'originale, se invece campionassi ad una frequenza più bassa come ad esempio 80 o 100 px avrei come output un immagine con perdita di dati e possibile presenta di aliasing

--------------------------------------------------------------------------------

Prova in itinere C: Rappresentazione Raster e Quantizzazione

**a) Rappresentazione di un'immagine digitale e convenzioni.**

Definire come viene rappresentata un'immagine digitale _raster_. Specificare le convenzioni utilizzate per contare le righe e le colonne di questa rappresentazione e dove è posta l'origine delle coordinate.

Un immagine digitale raster è rappresentata con i pixel, questa immagine può essere rappresentata con una matrice in cui ogni indice $a_{ij}$ corrisponde ad un pixel. L'origine delle coordinate è posta nell'angolo in alto a sinistra della matrice. Si differenziano dalle immagini vettoriali perché queste ultime anziche usare i pixel usano delle formule matematiche per "disegnare" l'immagine, questo ha dei pro e dei contro, ad esempio quando si zoomma un immagine vettoriale questa non si sfoca a differenza di quelle raster, ma le immagini raster sono più adatte a rispecchiare immagini "reali"

**b) Tipologie di Immagini e Bit per Pixel.**

Descrivere le tre principali tipologie di immagini (Bianco/nero, Scala di grigio, A colori) in base alla profondità di bit e al range di valori che un pixel può assumere in posizione . Spiegare inoltre in che modo il valore di una cella della matrice viene tradotto in colore (pixel).

**c) Quantizzazione Uniforme.**

Spiegare a cosa serve il processo di _quantizzazione_. Se un segnale analogico viene quantizzato, e si vuole portare un range di ingresso da livelli (256) ad un range di uscita di livelli (8) con quantizzazione uniforme, utilizzare la formula per calcolare il livello in uscita corrispondente a un livello di ingresso .

Un segnale misurato da un sensore è un segnale analogico che per definizione è composto da numeri reali che se vogliamo rappresentare digitalmente devono essere rappresentati come numeri discreti. Supponiamo di avere un segnale nell'intervallo chiuso (a,b), allora si stabilisce un certo numero di "livelli" che sono dei numeri compresi nell'intervallo (t0 ,t1, t2, tn) tali che:
$t_0 <= a < t_1 < t_2 .... t_n <= b$ , per ogni numero y letto dal sensore verrà collocato verso il livello corrispondente seguendo questa logica: $t_k <= y <t_k+1$ in questo modo sto approssimando i numeri reali letti dal sensore in base ai livelli che ho assegnato all'intervallo (più livelli uso meno devo approssimare e più informazione riesco a preservare) , esistono 2 modi di quantizzare:
1) quantizzazione uniforme 
2) quantizzazione non uniforme

la formula per la quantizzazione uniforme è 
$L' = \frac{L * K}{N}$

dove L' è il numero in uscita
L è il numero in entrata
K è il numero di livelli in uscita
N è il numero di livelli in entrata

mentre per la quantizzazione uniforme è tutto uguale tranne una funzione:
$L' = \frac{f(L) * K}{f(N)}$
dove f() è una funzione ad esempio il logaritmo 

calcoliamo:
livelli in ingresso = 256
livelli in uscita = 8
matrice 
0   100
50 200

applico la formula della quantizzazione uniforme:
$L' = \frac{0 * 8}{256} = 0$
$L' = \frac{100 * 8}{256} = 3.125$
$L' = \frac{50 * 8}{256} = 1.56$
$L' = \frac{200 * 8}{256} = 6.25$
adesso tengo solo la parte intera:
la matrice che ottengo è
0 3
1 6


