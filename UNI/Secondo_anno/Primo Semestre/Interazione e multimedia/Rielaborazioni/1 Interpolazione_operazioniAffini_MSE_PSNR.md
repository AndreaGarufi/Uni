Un'immagine digitale raster può essere rappresentata come una matrice, quindi posso fare le stesse operazioni che faccio sulle matrici, anche se non è detto che alcune operazioni abbiano un senso logico.

- **Prodotto**
  **Useremo il prodotto puntuale** che è diverso dalla normale operazione di prodotto di matrici, infatti nel prodotto puntuale si fa il prodotto punto a punto degli elementi della matrice (infatti devono avere lo stesso numeri di righe e colonne)
  ![[Pasted image 20251024160926.png|300]]

**Neighborhood $N_p$**
![[Pasted image 20251024161051.png|500]]

### **Operazioni affini**
Queste operazioni affini sono essenzialmente:
- l'identità
- la rotazione
- la traslazione
- lo scaling
- lo shear
Queste operazioni non cambiano il valore del pixel ma lo spostano (dandogli delle nuove coordinate)
Queste operazioni si possono identificare tramite matrice o equazione
![[Pasted image 20251024161423.png|600]]
la matrice quindi è l'operazione che io andrò a fare sull'immagine,
quindi io applicherò l'operazione $T$ al pixel di coordinate $v,w$ e otterrò in output la altre coordinate $x,y$ in base all'operazione che faccio.
Questa operazione si chiama **Forward mapping**, che però può lasciare dei buchi nell'immagine di output, esiste quindi anche l' **Inverse mapping** che risolve il problema dei buchi:

**Forward mapping = $[x\,\, y\,\, 1] = [v\,\,w\,\,1]*T$**
**Inverse mapping = $[v\,\,w\,\,1] = [x\,\,y,\,\,1]*inversa(T)$**
Forward mapping (scaling)
![[Pasted image 20251024174756.png|400]]
Inverse mapping (scaling)
![[Pasted image 20251024174908.png|400]]


Le trasformazioni affini si possono combinare tra loro semplicemente moltiplicando le corrispondenti matrici


### Interpolazione
Nel corso delle trasformazioni, potrebbero esserci dei valori di pixel che non sono mai individuati dalle formule, per essi si applica un processo di interpolazione

L'interpolazione è un processo che partendo da dati reali stima i dati non conosciuti, quindi non migliora l'immagine ma si limita a stimare quali potrebbero essere i valori non conosciuti
E' il caso dello *zooming*, infatti un zoom 2x rende l'immagine grande il doppio quindi la matrice passa da $m$ x $n$  a $2m$ x $2n$ quindi il numero di pixel sarà quadruplicato quindi devo ricreare i pixel che non ho dopo aver zoommato l'immagine
![[Pasted image 20251024175609.png|400]]

Esistono vari tipi di interpolazione:
- Nearest neighbor (o replication) 
- Bilinear 
- Bicubic 
- Altri…

REPLICATION
![[Pasted image 20251024184320.png]]
Assegna a ogni pixel nuovo l'intensità del pixel più vicino, è una tecnica semplice ma aggiunge artefatti all'immagine

BILINEAR
![[Pasted image 20251024184436.png]]
Nell’ interpolazione bilineare si utilizzano i quattro pixel più vicini per stimare l’intensità da assegnare a ciascuna nuova posizione. Supponiamo che (x, y) siano le coordinate della posizione cui si deve assegnare un valore di intensità e che v(x, y) equivalga al valore dell’intensità. Per l’interpolazione bilineare il valore assegnato si ottiene mediante l’equazione

**v(x, y) = ax + by + cxy + d**
Ovviamente l'output è migliore rispetto alla replication ma è un po più costoso a livello computazionale

BICUBIC
![[Pasted image 20251024184640.png]]
L'interpolazione bicubica si ottiene utilizzando i sedici pixel più vicini al punto e il valore di intensità assegnato al punto (x,y) si ottiene attraverso l'equazione:
![[Pasted image 20251024185417.png]]
L’interpolazione bicubica è la tecnica standard utilizzata nei programmi commerciali di editing come Adobe Photoshop e Corel Photopaint (per lo meno fino alla data in cui sono state fatte le slide adesso potrebbe essere cambiato)

Come faccio però l'interpolazione ai bordi? O non faccio nulla o interpolo con i valori che ho anche se in numero minore


Esiste anche lo *zooming out* infatti se zoommo l'immagine in 0,5x ottendo un immagine più piccola di quella originale, quindi ho un processo di "decimazione"
Quindi partendo da una matrice $m$ x $n$ ottendo una matrice $\frac{m}{2}$ x $\frac{n}{2}$ 
 - metodo 1
   ogni 4 pixel se ne sceglie 1
   ![[Pasted image 20251024190136.png|400]]
- metodo 2
  di 4 pixel se ne calcola il valore medio
  ![[Pasted image 20251024190218.png|400]]




**Stima della qualità di un algoritmo**
- MSE (Mean Square Error) tale parametro serve a stimare l'errore quadratico medio tra due immagini; più tale indice è basso minore è la differenza tra le immagini.
- PSNR (Peak Signal to Noise Ratio)  parametro per misurare la qualità di un immagine compressa rispetto all'originale, dipende dalla differenza tra l’immagine codificata e quella originale. Maggiore è il suo valore maggiore sarà la “somiglianza” con l'originale

PSNR (Peak Signal to Noise Ratio)
Per calcolarlo bisogna avere sia l'immagine da valutare sia quella originale, questo algoritmo non è il migliore per valutare la qualità di un immagine ma è il più diffuso.
Per calcolare il PSNR abbiamo prima bisogno del MSE:
![[Pasted image 20251025105228.png|400]]

Poi si hanno 3 formule che sono equivalenti tra di loro:
![[Pasted image 20251025105307.png]]

MSE e PSNR sono molto usati perché semplici da calcolare, però non sempre danno un risultato fedele a quello dato dal sistema visivo umano. Infatti:
- Due immagini distorte possono avere tipi molto diversi di errori pur avendo lo stesso MSE.
- Entrambe le metriche sono fortemente influenzate anche da “impercettibili” movimenti spaziali (traslazioni,rotazioni, flipping di righe e/colonne)

