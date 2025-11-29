a) **Operatori Puntuali e LUT.** Definire un **operatore puntuale** nel contesto dell'elaborazione delle immagini. Spiegare in che modo un operatore puntuale può essere completamente descritto da una **Look-Up Table (LUT)** o da un grafico di trasformazione, e quale interfaccia viene universalmente utilizzata nei programmi commerciali per gestire queste operazioni.

b) **Istogramma e Caratteristiche dell'Immagine.** Definire l'**istogramma** di un'immagine a toni di grigio e spiegare come esso sia utile per comprenderne immediatamente le caratteristiche. In base all'istogramma, come si riconoscono un'immagine **sottoesposta** e un'immagine **sovraesposta**?


![[Pasted image 20251129120215.png]]



Prova in itinere H: Metriche di Qualità e Trasformazioni Affini

a) **Zooming Out (Decimazione) e Metriche di Errore.** Spiegare cosa si intende per **decimazione** di un'immagine. Descrivere due metodi possibili per effettuare lo _zooming out_ (riduzione) di un'immagine. Definire il **Peak Signal to Noise Ratio (PSNR)**, spiegando come il suo valore è correlato alla qualità di un'immagine compressa o elaborata rispetto all'originale


b) **Trasformazioni Affini: Matrici e Combinazioni.** Spiegare cosa sono le **operazioni affini** e come possono essere definite matematicamente in termini di matrici 3×3 (matrice T). Dimostrare come si possono **combinare** le trasformazioni affini (ad esempio rotazione e traslazione) per ottenere una singola matrice di trasformazione risultante.


![[Pasted image 20251129120256.png]]



Prova in itinere I: Spazi di Colore CIE e Percezione

a) **Spazio CIE XYZ e Cromaticità.** Descrivere come viene specificato un colore nello **spazio CIE XYZ**. Indicare le formule per passare dalle coordinate tridimensionali X,Y,Z alle coordinate di cromaticità bidimensionali x e y. Spiegare quale informazione sul colore è contenuta nel valore Y.

b) **Spazio L*a*b* e Distanza.** Spiegare perché il sistema CIE originale (XYZ) è stato ritenuto difettoso e come è stato risolto questo problema con l'introduzione degli spazi **CIE L*a*b*** nel 1976. Cosa significa che lo spazio L*a*b* è **percettivamente uniforme**?


![[Pasted image 20251129120339.png]]



Prova in itinere J: Operatori Puntuali e Funzioni di Trasformazione

a) **Trasformazione di Potenza (Gamma) e Controllo Contrasto.** Scrivere la formula per la **trasformazione di potenza** (o Gamma Correction) g(x,y). Spiegare in termini di γ (gamma) come si ottengono gli effetti opposti (espansione della dinamica per bassi valori di f o espansione per alti valori di f). Fornire un esempio di applicazione pratica di correzione γ in un contesto di visualizzazione (es. monitor CRT).

b) **Percezione Logaritmica e Illusioni Ottiche.** Spiegare quale fenomeno fisico e percettivo supporta l'uso di trasformazioni come quella logaritmica, facendo riferimento alla relazione tra intensità percepita e intensità incidente nell'occhio. Citare una delle **illusioni ottiche** descritte nelle fonti (ad esempio, **Bande di Mach** o **Contrasto simultaneo**) e spiegare brevemente in cosa consiste il fenomeno.

c) **Binarizzazione e Normalizzazione del Range.**

1. Spiegare in cosa consiste l'operazione di **binarizzazione** (o _thresholding_) e come viene implementata in termini di trasformazione puntuale.

2. Se un'operazione aritmetica su un'immagine (come la somma di due immagini) produce valori negativi (ad esempio, −10) o valori che superano il massimo (ad esempio, 300) in un sistema 0−255, descrivere la formula di **ri-normalizzazione** del range che si può applicare per mappare tutti i valori osservati nel range