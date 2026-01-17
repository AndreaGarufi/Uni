
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

**INIZIO ARGOMENTI PROVA IN ITINERE 2**
Un operatore $F: V\rightarrow W$ si dice lineare se per ogni coppia di vettori $v_1,v_2$ in $V$ e per ogni coppia di numeri reali $a,b$ si ha che:
$$F(a*v_1 + b*v_2) = a*F(v_1)+b*F(v_2)$$

Per indicare l' operazione di convoluzione si usa la notazione:
$$g = f ⊛h$$
La convoluzione è commutativa:
$$f⊛h = h ⊛f$$
La convoluzione è associativa:
$$(f⊛h)⊛h_1 = f⊛(h⊛h_1)$$


Applicare un kernel $h$ di dimensioni s x t ad un immagine se gli indici del kernel sono disposti in modo da avere gli indici (0,0) al centro:
![[Pasted image 20260115211945.png|600]]

Applicare un kernel $h$ di dimensioni s x t ad un immagine se gli indici del kernel sono disposti partendo da 1 fino ad arrivare a s e t:
![[Pasted image 20260115212028.png]]

Applicare un filtro lineare e shift invariante ad una immagine è equivalente a calcolare la convoluzione del kernel del filtro con l’immagine.

Esempi di operatori locali:
- Mediano -> È un filtro non lineare che fornisce in uscita il valore mediano dell’intorno del pixel
  
- Minimo e massimo -> preso un intorno mxn di pixel si sostituiscono tutti i valori di questi pixel con il valore minimo/massimo rilevato in quell'intorno

- N-box o di media-> Sono definiti da kernel N x N con ogni elemento pari a $1/N^2$, sfocano le immagini

- N-binomiale o filtri gaussiani -> smussano meno vigorosamente degli N-box

Formula rumore gaussiano bianco:
$$
p(z) = \frac{1}{\sqrt{2\pi}\sigma} e^{-(z-\bar{z})^2/2\sigma^2}
$$

Per rimuovere i 2 tipi di rumori solitamente si usano i filtri di media e mediano, quelli mediani funzionano meglio

Kernel notevoli: lati orizzontali
![[Pasted image 20260115213123.png|500]]

Kernel notevoli: lati verticali
![[Pasted image 20260115213153.png|500]]

Formula magnitudo:
$$
magnitudo = \sqrt{sobel_x^2 + sobel_y^2}
$$

Kernel notevole: laplaciano
![[Pasted image 20260115213308.png|500|300]]


Formula Trasformata di Fourier (da immagine a frequenza)
$$
F(u,v) = \frac{1}{MN} \sum_{x=0}^{M-1} \sum_{y=0}^{N-1} f(x,y) e^{-i 2\pi (\frac{ux}{M} + \frac{vy}{N})} \quad \text{per } u=0,\dots,M-1,\ v=0,\dots,N-1
$$

Formula Antirasformata di Fourier (da frequenza a immagine)
$$
f(x,y) = \sum_{u=0}^{M-1} \sum_{v=0}^{N-1} F(u,v) e^{i 2\pi (\frac{ux}{M} + \frac{vy}{N})} \quad \text{per } x=0,\dots,M-1,\ y=0,\dots,N-1
$$

Formula di Eulero
$e^{ix} = cos(x) + i*sen(x)$      e        $e ^{-ix} = cos(x) - i*sen(x)$

Formula spettro della trasformata
$$
|F(u,v)| = \sqrt{R^2(u,v) + I^2(u,v)}
$$

Formula angolo di fase
$$
\phi(u,v) = \tan^{-1} \left[ \frac{I(u,v)}{R(u,v)} \right]
$$

Formula potenza spettrale
$$
P(u,v) = |F(u,v)|^2 = R^2(u,v) + I^2(u,v)
$$

Quando si visualizza a schermo lo spettro di Fourier, come immagine di intensità, non si riescono a visualizzare le parti meno luminose, quindi si usa una compressione di tipo logaritmico che permette di visualizzarle:
$D(u,v)=c log(1+ F(u,v))$


Proprietà di separabilità della DFT 2-D
   $$
F(u,v) = \frac{1}{M} \sum_{x=0}^{M-1} k(x,v) e^{\frac{-i 2\pi ux}{M}}
$$

Dove:

$$
k(x,v) = \left[ \frac{1}{N} \sum_{y=0}^{N-1} f(x,y) e^{\frac{-i 2\pi vy}{N}} \right]
$$
Il principale vantaggio delle proprietà di separabilità è che la 𝐹(𝑢, 𝑣) può essere ottenuta applicando in due passi successivi la trasformata 1-D

Proprietà valor medio:
Il valore della trasformata nell’origine, cioè nel punto (u,v)=(0,0) è dato da:
$$
F(0,0) = \frac{1}{N \times N} \sum_{x=0}^{N-1} \sum_{y=0}^{N-1} f(x,y) 
\qquad 
\bar{f}(x,y) = \frac{1}{N \times N} F(0,0)
$$
- **A sinistra:** Viene calcolato $F(0,0)$. Solitamente nella teoria standard della DFT (Discrete Fourier Transform), $F(0,0)$ è la semplice somma di tutti i pixel. In questa specifica slide, però, sembra essere già normalizzato (diviso per $N \times N$).
    
- **A destra:** Viene definita $\bar{f}(x,y)$, ovvero la **media** (indicata dalla barra sopra la f), in funzione di $F(0,0)$.


Fast Fourier Transform (DFT ottimizzata)
$$
F(u) = \frac{1}{N} \sum_{x=0}^{N-1} f(x) \exp [ -i 2\pi ux / N ]
$$

Teorema convoluzione:
La trasformata della convoluzione di due segnali nel dominio spaziale equivale al prodotto delle trasformate dei due segnali.

che significa anche:
La convoluzione di due segnali nel dominio spaziale equivale all’antitrasformata del prodotto delle trasformate dei due segnali.

Formula convoluzione nel *dominio spaziale*:
$$
g(x,y) = f(x,y) \circledast h(x,y) = \frac{1}{MN} \sum_{m=0}^{M-1} \sum_{n=0}^{N-1} f(m,n)h(x-m, y-n)
$$
ad un immagine f viene applicato un kernel h

l'equivalente operazione nel *dominio delle frequenze*, moltiplicazione tra trasformate di Fourier
$$
G(u,v) = F(u,v)H(u,v)
$$
moltiplicazione tra antitrasformate di Fourier
$$
g(x,y) = F^{-1} \{ F(u,v)H(u,v) \}
$$


Filtri low-pass nel dominio della frequenza
![[Pasted image 20260115215316.png]]

Filtri high-pass nel dominio della frequenza
![[Pasted image 20260115215341.png]]

Filtri band reject nel dominio della frequenza
![[Pasted image 20260115215436.png]]


Compressione:
Formula frequenza carattere $a_i$:
$f_i = (\# occorrenze \,\,\,a_i )/N$

Formula entropia:
$E = - \sum f_i \log_2(f_i)\,\,\,\,i ∈ S$

Teorema di Shannon
I dati possono essere rappresentati senza perdere informazione (lossless) usando almeno un numero di bit pari a: $N*E$
Dove N è il numero di caratteri mentre E è l’entropia. 


Formula Trasformata Discreta del Coseno DCT
$$
F(u,v) = \frac{2}{N} \left[ \sum_{x=0}^{N-1} \sum_{y=0}^{N-1} C(u)C(v)f(x,y) \cos \frac{(2x+1)u\pi}{2N} \cos \frac{(2y+1)v\pi}{2N} \right]
$$
Formula antitrasformata
$$
f(x,y) = \frac{2}{N} \left[ \sum_{u=0}^{N-1} \sum_{v=0}^{N-1} C(u)C(v)F(u,v) \cos \frac{(2x+1)u\pi}{2N} \cos \frac{(2y+1)v\pi}{2N} \right]
$$
Dove:

$$
C(u) = \begin{cases} 
\frac{1}{\sqrt{2}} & \text{per } u = 0 \\
1 & \text{altrimenti}
\end{cases}
$$
$$
C(v) = \begin{cases} 
\frac{1}{\sqrt{2}} & \text{per } v = 0 \\
1 & \text{altrimenti}
\end{cases}
$$

Formula quantizzazione (JPEG)
$$F_{quantizzato}= round(F/Q)$$
dove F e un numero e Q e un fattore di quantizzazione


Formula codice grey
$$
\begin{aligned}
g_i &= a_i \oplus a_{i+1} & 0 \le i \le m-2 \\
g_{m-1} &= a_{m-1}
\end{aligned}
$$
dove ⊕ denota l'operatore di XOR (or esclusivo)

