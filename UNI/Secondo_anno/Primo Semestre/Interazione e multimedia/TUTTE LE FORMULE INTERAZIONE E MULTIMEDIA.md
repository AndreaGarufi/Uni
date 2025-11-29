
Formula per rappresentazione di immagini usando la luce incidente (i) e quella riflessa (r)
$$f(x,y) = i(x,y) r(x,y)$$

Formule delle trasformazioni affini
![[Pasted image 20251128172713.png|500]]

Forward mapping (T è la matrice affine)
$$[x y 1] = [v w 1] * T$$

Inverse mapping (T è la matrice affine)
$$[v w 1] = [x y 1] * inversa(T)$$


Formula Interpolazione Bilineare
$$v(x, y) = ax + by + cxy + d$$

Formula Interpolazione Bicubica
$$v(x,y) = \Sigma_{i=0}^{3}\Sigma_{i=0}^{3} a_{ij}x^iy^i$$

Formula del MSE
$$MSE = \frac{1}{MN} \Sigma^{M}_{x=1}\Sigma^{N}_{y=1}[I'(x,y)-I(x,y)]^2$$

Formula del PSNR
$$PSNR = 10 \log_{10} (\frac{S^2}{MSE})$$

Nell'occhio i coni sono: 6/7 milioni
I bastoncelli 75/150 milioni

Raggio foro "reale" del pinhole
$$r = \sqrt{λd}$$

Equazione lente sottile
$$\frac{1}{u} + \frac{1}{v} = \frac{1}{f}$$

Formula magnificazione
$$m = \frac{v}{u}$$
$$f =\frac{um}{(m+1)}$$

Nyquist Rate è il doppio della frequenza massima nel segnale

Formula quantizzazione uniforme
$$L' = \frac{L*K}{N}$$Formula quantizzazione NON uniforme
$$L' = \frac{f(L)*K}{f(N)}$$
oppure generalizzando:
$$L' = f(L,N,K)$$

Una quantizzazione non uniforme è quella logaritmica
$$L' = \frac{log_2\,\,L*K}{log_2\,\,N}$$

Formule per i valori del tristimolo
$$X = \int_{380}^{780} L_{e,\lambda}\,\bar{x}(\lambda)\, d\lambda
$$
$$Y = \int_{380}^{780} L_{e,\lambda}\,\bar{y}(\lambda)\, d\lambda
$$
$$Z = \int_{380}^{780} L_{e,\lambda}\,\bar{z}(\lambda)\, d\lambda
$$

Formula per trovare la z nel diagramma cromatico CIE (2D)
$$z = 1 - (x+y)$$

Formule per passare dai valori del tristimolo XYZ a xyz
$$ x = X/(X+Y+Z)$$
$$y = Y/(X+Y+Z)$$
$$z = Z/(X+Y+Z)$$

Formule per passare da CIE XYZ allo spazio colore CIELAB
$$L^* = 116\left( \frac{Y}{Y_n} \right)^{1/3} - 16
$$
$$a^* = 500\left[ \left( \frac{X}{X_n} \right)^{1/3} - \left( \frac{Y}{Y_n} \right)^{1/3} \right]
$$
$$b^* = 200\left[ \left( \frac{Y}{Y_n} \right)^{1/3} - \left( \frac{Z}{Z_n} \right)^{1/3} \right]
$$

$X_n$ , $Y_n$ e $Z_n$ definiscono il punto bianco


Formula per la distanza Euclidea (tra 2 colori in CIELAB)
$$
\Delta E^*_{ab} = \sqrt{(\Delta L^*)^2 + (\Delta a^*)^2 + (\Delta b^*)^2}
$$


Formule per chroma e hue angle in $L^*C^*h$ avendo il colore in CIELAB
$$
\begin{align}
C^* &= \sqrt{(a^*)^2 + (b^*)^2} \\
h &= \tan^{-1} \left( \frac{b^*}{a^*} \right)
\end{align}
$$

I colori sicuri per il web si esprimono esclusivamente con questi numeri esadecimali $33, 66, 99, CC, FF$


Formule per passare da RGB a YUV
$$Y = 0.299𝑅 + 0.587𝐺 + 0.114𝐵$$
$$U = −0.169𝑅 − 0.331𝐺 + 0.5𝐵$$
$$V = +0.5𝑅 − 0.419𝐺 − 0.081𝐵$$

Formule per passare da YUV a $YC_bC_r$
$$Y = 0.299𝑅 + 0.587𝐺 + 0.114𝐵$$
$$𝐶_𝑏 = 𝑈 + 128$$
$$𝐶_𝑟 = 𝑉 + 128$$

Per gli istogrammi
Per un immagine $l[m,n]$ si ha $H(k) =$ numero di pixel di valore k

Formula normalizzazione dell'istogramma (problemi di range)
$$
v_{\text{nuovo}} = 255 \cdot \frac{(v_{\text{vecchio}} - \text{min}_{\text{osservato}})}{(\text{max}_{\text{osservato}} - \text{min}_{\text{osservato}})}
$$

Algoritmo di equalizzazione
$$
p_r(r_k) = \frac{n_k}{MN}, \quad k = 0, 1, 2, \dots, L - 1
$$
$$
s_k = T(r_k) = (L - 1) \sum_{j=0}^{k} p_r(r_j) = \frac{(L - 1)}{MN} \sum_{j=0}^{k} n_j, \quad k = 0, 1, 2, \dots, L - 1
$$
![[Pasted image 20251128181257.png|500]]
![[Pasted image 20251128181224.png|500]]


Operazione generica su un immagine
$$g(x,y) = T[f(x,y)]$$
Operatori puntuali:
Negativo
$$255-f(x,y)$$
Trasformazione logaritmica
$$g(x, y) = c · log(1 + f (x, y))$$
Trasformazione di potenza
$$g(x, y) = c · (f (x, y))^γ$$

La binarizzazione sceglie un valore soglia: i pixel al di sotto diventano neri quelli al di sopra bianchi


**FINE  ARGOMENTI PROVA IN ITINERE 1**