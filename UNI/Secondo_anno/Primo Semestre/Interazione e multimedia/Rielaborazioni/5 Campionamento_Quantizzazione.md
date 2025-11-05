
### **CAMPIONAMENTO**
Ogni segnale nella realtà è un segnale continuo (analogico), se dobbiamo trasportarlo in digitale abbiamo bisogno di campionarlo in un numero finito ovviamente, il valore in ogni singolo punto del segnale è un numero reale, per rappresentarlo in digitale serve prendere dei numeri discreti
![[Pasted image 20251103155017.png]]
![[Pasted image 20251103155105.png]]


**ERRORI NEL CAMPIONAMENTO**
Un campionamento troppo basso può portare a perdita di informazione andando ad approssimare troppo rispetto al dato reale oppure può portare ad una modifica del dato originale aggiungendo informazioni errate/false in questo caso si parla di aliasing

**COME SI CAMPIONA IN MODO CORRETTO?**
Per campionare in modo corretto si utilizza il **teorema di shannon** che prende in considerazione una misura chiamata **Nyquist rate**

**Nyquist rate**
Si definisce Nyquist rate il doppio della più alta frequenza in un segnale continuo e limitato

Nella pratica:
Si osservi un fenomeno che si svolge in un intervallo a…b 
• Se il fenomeno è (approx) costante durante tutto l’intervallo, la più alta frequenza del segnale è 1: il fenomeno si svolge in un unico ciclo. 
• Altrimenti si divide l’intervallo in 2 parti e si controlla per ciascun intervallino il fenomeno si mantiene (approx) costante (esso può però variare da intervallino ad intervallino). 
• Si procede in tal modo dividendo l’intervallo in 3, 4, … parti fino a trovare una suddivisione tale che entro ciascun intervallino il fenomeno sia in pratica costante. 
Sia tale suddivisione in N parti. 2xN si dice Nyquist rate del fenomeno sull’intervallo osservato

**Teorema di shannon**
Se si raccolgono campioni con frequenza più alta del Nyquist rate il segnale può essere ricostruito FEDELMENTE in ogni suo punto!

**Applicazione alle immagini**
![[Pasted image 20251103155901.png]]

Usiamo i tratti fini. Se preserviamo questi, allora abbiamo preservato anche gli altri. La nostra «frequenza più alta» è allora:
 dimensione quadro 720 pixel, dettaglio massimo 4 pixel, possiamo dividere l’intervallo in 720/4=180 tratti. 
 Il doppio di tale frequenza è il Nyquist rate: 360. Prenderemo allora solo 360 campioni e ricostruiremo con l’interpolazione bilineare l’immagine.
![[Pasted image 20251103160014.png]]

![[Pasted image 20251103160116.png]]

Se campiono sotto il Nyquist rate perdo informazione e aggiungo dettagli che non sono presenti nell'originale

**Aliasing**
 Questo fenomeno è detto frequency aliasing o semplicemente aliasing 
 Con l’aliasing le alte frequenze sono “mascherate” da basse frequenze e trattate come tali nella fase di campionamento. 
 Aliasing proviene da Alias cioè falsa identità!
![[Pasted image 20251103160410.png]]

L'aliasing esiste sempre solo che meno campioni prendo più è evidente, si può però ridurre attraverso l'anti-aliasing che smussa il segnale originale prima del campionamento

**Perdita di dettaglio**
![[Pasted image 20251103160321.png]]


### **QUANTIZZAZIONE**
 I sensori sono apparecchiature analogiche: forniscono misure di luminosità come numeri REALI. 
 È utile arrotondare tali valori e mantenerli in un certo range. 
 Tale processo si chiama QUANTIZZAZIONE

In più i sensori sono soggetti a piccoli errori dovuti all'imprecisione dei sensori o a fattori ambientali esterni al sensore

Nei CCD anche a obiettivo chiuso ci sono correnti parassite che inducono rumore dentro il dispositivo elettronico dette “dark current”

**Procedura generale**
![[Pasted image 20251103161643.png]]

![[Pasted image 20251103161659.png]]

**Quantizzazione uniforme e non uniforme**
![[Pasted image 20251103161736.png]]

La quantizzazione effettuata dagli scanner commerciali e dalla fotocamere digitali è non uniforme e logaritmica: ciò permette di assegnare più livelli nella area dei toni scuri e meno livelli nella area dei toni chiari
Questo è particolarmente importante quando si elaborano dati medici (es. radiografie)
![[Pasted image 20251103161827.png|400]]


**Effetti sulle immagini**
![[Pasted image 20251103161915.png]]

![[Pasted image 20251105144002.png]]

**Esempio di quantizzazione a 8 bit (8 livelli)**
![[Pasted image 20251105144150.png]]

![[Pasted image 20251105144234.png]]

L'esempio è analogo

Tra quantizzazione uniforme e non, la differenza è l'ampiezza dell'intervallo (come nell'immagine di prima)

