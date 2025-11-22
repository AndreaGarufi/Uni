**Nuova Prova in itinere D: Acquisizione, CFA e Interpolazione del Colore**

**a) Acquisizione e Bayer Pattern.**

Descrivere come i sensori 2D array (come i CCD) acquisiscono la luce e la trasformano in impulso elettrico nelle macchine fotografiche digitali. Spiegare il ruolo e la composizione del **Bayer Pattern** come Color Filter Array (CFA). Specificare il rapporto R:G:B del Bayer Pattern e motivare il perché privilegi il canale verde.

**b) Color Interpolation (Demosaicking) e Replication.**

Definire cosa si intende per **Color Interpolation** e perché tale processo è necessario per ottenere un'immagine a colori da una matrice di dati grezzi (formato "raw"). Spiegare perché l'algoritmo di _Color Interpolation_ è anche chiamato algoritmo di **demosaicking**. Descrivere il metodo di interpolazione a **Replication** (o _Nearest-neighbor interpolation_).

**c) Confronto di Interpolazioni per Immagini.**

Nel contesto dello _zooming_, confrontare l'interpolazione **Bilineare** e quella **Bicubica** in termini di complessità (numero di pixel utilizzati per la stima) e di risultato sulla qualità dell'immagine. Indicare quale delle due tecniche è generalmente lo standard nei programmi commerciali di editing.

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