Ci interessa capire quali sono i limiti della visione umana al fine di usarli nell’image processing

A noi interessa la retina che è una membrana che ricopre la parte posteriore dell'occhio:
è formata da bastoncelli e coni![[Pasted image 20251029160440.png|600]]
I coni sono circa 6/7 milione e sono concentrati nella fovea, sono responsabili della visione FOTOTICA (policroma), i bastoncelli sono invece 75/150 milioni e sono distribuiti su tutta la retina, sono poco sensibili al colore e permettono la visione SCOTOTICA (monocroma)
![[Pasted image 20251029161004.png|500]]
questa è la loro disposizione sulla retina: la linea continua sono i coni la tratteggiata i bastoncelli

 La fovea è una regione di 1,5 mm x 1,5 mm 
 Ed ha una popolazione di coni di circa 150.000 elementi per $mm^2$
 Il numero di coni nella fovea è di circa 337.500 elementi; 
 Un CCD può contenere lo stesso numero di recettori in non meno di 5 mm x 5 mm!!


**Formazione dell'immagine**
Usiamo il modello del PINHOLE, in cui si descrive l'occhio come una scatola in cui su una parate c'è una pellicola sensibile alla luce e sul lato opposto c'è un buco fatto con un ago (pin hole) 

Il raggio del foro è proporzionale alla radice quadrata della distanza (d) per la lunghezza d’onda (λ) della luce emessa.
![[Pasted image 20251029162942.png|500]]

![[Pasted image 20251029163119.png|500]]

![[Pasted image 20251029163132.png|500]]


Il pinhole però non basta, infatti già dal rinascimento si è cominciata ad usare una particolare lente chiamata lente sottile il cui diametro è di un ordine di grandezza più grande dello spessore della lente![[Pasted image 20251029163531.png|30]]

**Definizione geometrica**
Una lente sottile è definita da una proprietà geometrica importante che si può enunciare come due parti “speculari” l’una all’altra: 
a) raggi paralleli all’asse della lente sottile vengono concentrati in un unico punto detto FUOCO, posto a distanza F dalla lente; 
b) raggi che si dipartono dal FUOCO vengono ritrasmessi tutti paralleli nella direzione dell’asse della lente. 
c) una lente sottile ha due fuochi equidistanti da essa.
![[Pasted image 20251029163844.png|500]]

![[Pasted image 20251030143627.png]]
•Un oggetto puntiforme, emette raggi luminosi in ogni direzione, solo uno è parallelo all’asse ottico e la lente lo farà passare per il fuoco. 
•Solo uno passa per il fuoco e la lente lo farà passare in un raggio parallelo alla lente. •Il punto in cui i due raggi si reincontrano è il punto di formazione della immagine dell’oggetto puntiforme. 
•Si può dimostrare (per una lente ideale) che anche gli altri raggi si “reincontrano” in tale punto. 
•Se si pone il piano dei sensori più avanti o più indietro del piano che contiene l’immagine si ottiene si ottiene una immagine SFOCATA dell’oggetto originale


**Equazione della lente**
Saltando tutti i vari passaggi intermedi otteniamo l'equazione della lente sottile, che è $$\frac{1}{u}+\frac{1}{v} = \frac{1}{f}$$
Se f sono metri allora $\frac{1}{metro}$ è uguale a una diottria
- **u** → la **distanza dell’oggetto** dalla lente (di solito positiva se l’oggetto è davanti alla lente, cioè dal lato da cui arriva la luce);
    
- **v** → la **distanza dell’immagine** dalla lente (positiva se l’immagine è reale e si forma dall’altro lato della lente);
    
- **f** → la **lunghezza focale** della lente (positiva per le lenti convergenti, negativa per le divergenti).

a) In una lente “fissa” la quantità f è costante. Se la distanza dell’oggetto dalla lente, cioè u, cresce, per la relazione di cui sopra v non può che diminuire: ecco perché la messa a fuoco richiede che il piano dei sensori possa essere avvicinato o allontanato dalla lente

b) Se il piano dei sensori non può essere mosso (caso della retina umana!) l’unica cosa da fare è aggiustare la lunghezza focale (ciò fanno i muscoli che mantengono in tensione il cristallino). La variabilità della lunghezza focale della lente si misura anche essa in diottrie.

c) Se due oggetti sono a distanza u1 e u2 e entrambe queste quantità sono molto maggiori di f essi formano le loro immagini approssimativamente su un unico piano (i due valori corrispondenti v1 e v2 sono vicinissimi). Se u1 e u2 sono però differenti e comparabili (meno di 30 volte la distanza della lente) allora essi non possono essere focalizzati contemporaneamente: si manifesta il fenomeno della “profondità di campo” che risulta più accentuato se f è grande.

**Capire la magnificazione**

