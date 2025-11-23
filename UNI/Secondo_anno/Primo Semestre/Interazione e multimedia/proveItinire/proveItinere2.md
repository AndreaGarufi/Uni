**Nuova Prova in itinere D: Acquisizione, CFA e Interpolazione del Colore**

**a) Acquisizione e Bayer Pattern.**

Descrivere come i sensori 2D array (come i CCD) acquisiscono la luce e la trasformano in impulso elettrico nelle macchine fotografiche digitali. Spiegare il ruolo e la composizione del **Bayer Pattern** come Color Filter Array (CFA). Specificare il rapporto R:G:B del Bayer Pattern e motivare il perché privilegi il canale verde.

RISPOSTA:
I sensori CCD sono sensibili alla luce e quando colpiti da un raggio si attivano mandando un segnale elettrico che poi deve essere digitalizzato
i sensori sono disposti a matrice e ogni sensore sarà sensibile al rosso al verde o al blu. Quando l'immagine deve essere salvata in memoria si procede salvando la prima colonna della matrice, tutte le altre colonne vengono "shiftate" a sinistra per essere ad una ad una salvate. Il bayer pattern è una tecnica che serve a gestire in maniera corretta la resa dei colori per l'immagine, in particolare i sensori sono disposti a matrice in modo che alcuni percepiscano il rosso altri il blu e altri il verde secondo questo rapporto RGB -> 1:2:1 ovvero il verde è predominante perché per l'occhio umano è più importante rispetto a rosso e blu. in questa maniere per ricavare gli altri colori si usa la color interpolation

**b) Color Interpolation (Demosaicking) e Replication.**

Definire cosa si intende per **Color Interpolation** e perché tale processo è necessario per ottenere un'immagine a colori da una matrice di dati grezzi (formato "raw"). Spiegare perché l'algoritmo di _Color Interpolation_ è anche chiamato algoritmo di **demosaicking**. Descrivere il metodo di interpolazione a **Replication** (o _Nearest-neighbor interpolation_).

La color interpolation così come quella "normale" per le operazioni affini su immagini, non crea nuova informazione ma si limita a ricavare il colore in base ai pixel vicini, infatti un immagine in bayer pattern (salvata in formato raw) sarà una matrice che non conterrà una terna di colori per ogni pixel della matrice ma ne conterrà solo uno, sta alla color interpolation ricavare le altre 2 componenti della terna mancanti per ogni pixel, esistono vari algoritmi come la replication o il bilinear o bicubic.
La replication stima le altre 2 componenti della terna di un dato pixel in base ai pixel vicini ad esempio se mi trovo in un pixel verde circondato da altri pixel rossi e blu allora probabilmente anche il pixel che ha catturato solo il verde dovrà anche avere componenti di rosso e blu
La color interpolation si chiama demosacking perché un immagine in bayer patter sembra un mosaico e la color interpolation la trasforma nell'immagine più simile all'oggetto originale

**c) Confronto di Interpolazioni per Immagini.**

Nel contesto dello _zooming_, confrontare l'interpolazione **Bilineare** e quella **Bicubica** in termini di complessità (numero di pixel utilizzati per la stima) e di risultato sulla qualità dell'immagine. Indicare quale delle due tecniche è generalmente lo standard nei programmi commerciali di editing.

Lo standard è la bicubica. Nel contesto di uno zooming ad esempio 2x avrò il quadruplo dei pixel rispetto alla foto originale, l'interpolazione deve ricostruire l'immagine basandosi sui pixel che ha a disposizione, esistono vari algoritmi come la replication il bilinear e il bicubic, gli ultimi 2 funzionano in maniera simile ma cambia la loro resa e complessità, infatti il bilinar interpola un pixel basandosi sui 4 pixel più vicini ad esso mentre il bicubic lo fa basandosi sui 16 pixel più vicini, si evince che il bilinear abbia una resa meno precisa rispetto al bicubic ma che sia anche più leggero a livello computazionale. I punti critici per entrambi gli algoritmi sono i bordi dell'immagine perché al bordo potrei non avere sufficenti pixel per interpolare correttamente, quindi le soluzioni sono 2: non fare nessuna interpolazione ai bordi o farla con i pochi pixel a disposizione

--------------------------------------------------------------------------------

**Nuova Prova in itinere E: Modello Lente Sottile e Ottica**

**a) Pinhole Model e Point Spread Function (PSF).**

Spiegare il modello teorico del **Pinhole** (foro con spillo) utilizzato per comprendere la formazione dell'immagine nell'occhio. Descrivere cosa succede quando un punto luminoso attraversa un _pinhole reale_ invece di uno ideale. Definire la **Point Spread Function (PSF)** e spiegare brevemente cosa implica il **Principio di sovrapposizione** in questo contesto.

**b) Equazione della Lente Sottile.**

Scrivere l'equazione che lega la distanza dell’oggetto (_u_), la distanza dell’immagine (_v_) e la lunghezza focale (_f_) per una lente sottile. Spiegare in che modo questa equazione si applica alla messa a fuoco in una macchina fotografica (movimento del piano dei sensori) e in che modo si applica all'occhio umano (cristallino).

**c) Calcolo della Magnificazione.**

La **magnificazione** _m_ è data dal rapporto _v_/_u_. Un ingegnere sta progettando un sistema ottico in cui un oggetto è posto a una distanza _u_=5 cm e l'immagine è formata a _v_=10 cm.

1. Calcolare il fattore di magnificazione _m_.

2. Utilizzando l'equazione della lente sottile, determinare la lunghezza focale _f_ del sistema.

3. Se lo stesso sistema ottico (con la stessa _f_) viene usato per focalizzare un nuovo oggetto a una distanza _u_′=50 cm, a quale distanza _v_′ si formerà l'immagine? (Suggerimento: 1/_u_+1/_v_=1/_f_).

--------------------------------------------------------------------------------

**Nuova Prova in itinere F: Rappresentazioni Visive e Modelli di Colore**

**a) Immagini, Percezione e Illusioni Ottiche.**

Citando le fonti, spiegare il **ruolo culturale** delle immagini e perché la comunicazione visuale è considerata la forma più immediata ed efficace di comunicazione. Descrivere due fenomeni percettivi, le **Bande di Mach** e il **Contrasto Simultaneo**, e spiegare cosa dimostrano tali fenomeni riguardo alla luminosità percepita rispetto all'intensità emessa.

**b) Modello HSV/HSI.**

Descrivere il modello di colore **HSV** (Hue, Saturation, Value). Spiegare cosa rappresenta ciascuna delle tre componenti (H, S, V) e specificare il principale vantaggio percepito (PRO) e lo svantaggio (CONTRO) di questo modello rispetto a modelli basati sull'hardware come RGB.

**c) Sintesi Additiva (RGB) vs. Sottrattiva (CMY).**

Descrivere la **Sintesi Additiva** (RGB) e la **Sintesi Sottrattiva** (CMY). Spiegare come si ottiene il bianco e il nero in ciascuno dei due modelli (partendo dai tre colori primari) e in quali contesti di applicazione vengono utilizzati rispettivamente (es. schermi vs. stampa). Spiegare perché nel modello CMYK viene spesso utilizzato un quarto inchiostro (K).