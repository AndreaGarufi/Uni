Un'immagine digitale raster può essere rappresentata come una matrice, quindi posso fare le stesse operazioni che faccio sulle matrici, anche se non è detto che alcune operazioni abbiano un senso logico.

- **Prodotto**
  **Useremo il prodotto puntuale** che è diverso dalla normale operazione di prodotto di matrici, infatti nel prodotto puntuale si fa il prodotto punto a punto degli elementi della matrice (infatti devono avere lo stesso numeri di righe e colonne)
  ![[Pasted image 20251024160926.png|300]]

**Neighborhood $N_p$**
![[Pasted image 20251024161051.png|500]]

**Operazioni affini**
Queste operazioni affini sono essenzialmente:
- l'identità
- la rotazione
- la traslazione
- lo scaling
- lo shear
Queste operazioni non cambiano il valore del pixel ma lo spostano
Queste operazioni si possono identificare tramite matrice o equazione
![[Pasted image 20251024161423.png|600]]
la matrice quindi è l'operazione che io andrò a fare sull'immagine,
quindi io applicherò l'operazione $T$ al pixel di coordinate $v,w$ e otterrò in output la altre coordinate $x,y$ in base all'operazione che faccio.
Questa operazione si chiama **Forward mapping**, che però può lasciare dei buchi nell'immagine di output, esiste quindi anche l' **Inverse mapping** che risolve il problema dei buchi:

**Forward mapping = $[x\,\, y\,\, 1] = [v\,\,w\,\,1]*T$**
**Inverse mapping = $[v\,\,w\,\,1] = [x\,\,y,\,\,1]*inversa(T)$**
(inserisci immagini)


