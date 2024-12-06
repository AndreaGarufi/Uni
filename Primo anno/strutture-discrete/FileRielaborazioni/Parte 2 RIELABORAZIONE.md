**Ricordiamo gli insiemi numerici** 
N = {0, 1, 2, 3, 4, . . .} "numeri interi naturali"
Z = {. . . , −4, −3, −2, −1, 0, 1, 2, 3, 4, . . .} "numeri interi relativi" 
Q = { n m : n, m ∈ Z} "numeri razionali" 
R = {x : x razionale o irrazionale } "numeri reali" 
C = {x : x reale o immaginario } "numeri complessi" 
 
**N ⊂ Z ⊂ Q ⊂ R ⊂ C**


**Definizione assiomatica di ℕ**

se **a ∈ ℕ il suo successore** si chiama **S(a)**.
S(a) = a + 1
il **predecessore di S(a)** = a e si indica con **P(S(a))**
0 non ha un predecessore mentre tutti gli altri numeri si.

**Assioma del buon ordinamento**
S insieme non vuoto, s ∈ S
esiste un elemento minimo chiamato appunto s, quindi **s è il minimo se s ≤ t** , **per ogni t ∈ S**

**PRINCIPIO DI INDUZIONE**
Se una proprietà $P$ è posseduta da 0 e la proprietà $P$ è posseduta dal successore di ogni numero naturale che la possiede allora $P$ è posseduta da tutti i numeri ℕ

*(**NOTA** Il primo caso, si chiama caso base e, se ci si riferisce agli interi positivi, si utilizza il numero 1 al posto del numero 0.)*

Teorema 
Sia P una affermazione riguardante i numeri naturali. Se:
**(a)** **P(0) è vera**, ed inoltre 
**(b)** per ogni numero naturale n **se P(n) è vera allora è vera anche P(n + 1)** possiamo concludere che P è vera per ogni numero naturale.

**DIMOSTRAZIONE**

Ragioniamo per assurdo e partiamo dal fatto che il teorema sia falso: abbiamo quindi P(n) che è falso:
                S = {n | n ∈ ℕ, e P(n) è falsa}

S quindi non è vuoto (contiene 1 solo elemento), esiste in s un elemento minimo (<u>assioma del buon ordinamento</u>), quindi P(s) è falsa. Dalle ipotesi sappiamo che s ≠ 0 perché P(0) è vera. Dato che S ⊂ ℕ deve essere s > 0. Allora esiste un suo predecessore s - 1 ∉ S, quindi P(s-1) è vera. Ma per la regola sappiamo che P vale anche per i successori di un numero, quindi anche per s, in questo modo abbiamo una contraddizione.

        (cosi è spiegato semplice come si dimostra per induzione)

![[Pasted image 20241130201548.png|400]]


**Facciamo degli esempi.** (esempi del secondo e terzo esercizio)
![[Pasted image 20241130194603.png]]
**Principio di induzione : esempio 2** ($P$(A) è l'insieme delle parti di A, ovvero tutti i suoi sotto insiemi)

Dimostriamo per induzione che dato un insieme finito A allora |$P$(A)| = $2^{|A|}$
Utilizzeremo l'induzione sulla cardinalità di A
- **Caso base:** |A| = 0 abbiamo $P$(A) = {∅} e quindi |$P$(A)| = 1 = $2^0$
- **Passo induttivo:** supponiamo l'asserto sia vero per tutti gli insiemi A tali che 
   0<|A| = n -1 e dimostriamolo per n. Sia allora A un insieme tale che |A| = n e sia a ∈ A
   L'insieme A' = A \ {a} ha una cardinalità di n-1 elementi e quindi  |$P$(A')| = $2^{n-1}$ .
   ovviamente, $P$(A') ⊂ $P$(A) ed inoltre possiamo dire che gli elementi di $P$(A) \ $P$(A') sono tutti sottoinsiemi di A che contengono a. Questi elementi sono esattamente tanti quanti sono gli elementi di $P$(A'), infatti la funzione:
   f<sub>a</sub> : $P$(A') -> $P$(A) ⊂ $P$(A')
   che associa ad ogni elemento X ∈ $P$(A') l'elemento X U {a} è una corrispondenza biunivoca.
- Quindi |$P$(A)| = 2 ·  |$P$(A')| = $2$ · $2^{n-1}$ = $2^n$

**Principio di induzione : Formula di Gauss, esempio 3**
Dimostriamo per induzione che dato un intero n ≥ 1 si ha che 1+2+...(n-1)+n = $\frac{n(n+1)}{2}$
- **Il caso base** è n = 1 e per n = 1 la formula è vera perché 1 = $\frac{1(1+1)}{2}$
- **Passo induttivo**: supponiamo l'asserto sia vero per n e dimostriamolo per n +1 
  essendo vero per n abbiamo:![[Pasted image 20241130201210.png]]


**FUNZIONI "FLOOR" E "CEILING"**

Sia x un numero reale, definiamo i 2 seguenti valori:
- "<font color="#c00000">Floor</font>" -> il più grande numero intero minore o uguale ad x è detto "floor" e denotato con $\lfloor x \rfloor$
- "<font color="#c00000">Ceiling</font>" -> il più piccolo numero intero maggiore o uguale ad x è detto "ceiling" e si denota con $\lceil x \rceil$

**Esempi**: ![[Pasted image 20241130202515.png|200]]

**DIVISIONE TRA INTERI**
**TEOREMA** 
Dati 2 interi a, b  ∈ ℤ con b ≠ 0, chiamati rispettivamente dividendo e divisore, esistono unici 2 interi relativi q, r, denotati rispettivamente quoziente e resto, tali che a = q · b + r con 0 ≤ r < |b|

il **modulo** è il resto (r) della divisione indicato con a mod b

Si noti che nel teorema definiamo il resto sempre positivo. Per dimostrare il teorema agiremo per casi: 
1) Nel primo caso assumiamo che il dividendo a ed il divisore b siano entrambi non negativi 
2) Nel secondo caso assumiamo che il dividendo a sia negativo ma il divisore b positivo 
3) Nel terzo caso assumiamo che il dividendo a sia positivo e il divisore b negativo 
4) Nel quarto caso assumiamo che il dividendo a ed il divisore b siano entrambi negativi Ed infine, dimostreremo l’unicità di quoziente e resto.

**Primo caso (dividendo a, divisore b positivo)** 
Assumiamo che a, b siano entrambi non negativi con b ≠ 0. 
- Consideriamo il seguente insieme di numeri interi non negativi
			  S = {a-kb | k ∈ ℕ, a-kb ≥ 0}
- L'insieme è non vuoto, perché per k = 0 abbiamo che a ∈ S. Per l'assioma del buon ordinamento, l'insieme S ha un minimo, indichiamolo con r ≥ 0. Denotiamo con q il valore di k tale che r = a-qb da cui a = qb+r.
- Notiamo subito che se r = a-qb è il minimo di S allora q è il massimo intero in  ℕ tale che a-qb ≥ 0, ossia q = $\lfloor a/b \rfloor$. Infatti, se esistesse k > q tale che a-kb ≥ 0 avremmo
				(a-qb) - (a-kb) = (k-q)b ≥ 0
  perché b > 0 e k > q. Ma questo contraddirebbe l'ipotesi che a-qb è il minimo di S
- Viceversa, se q è il massimo intero in  ℕ tale che a-qb ≥ 0, allora per ogni k ∈  ℕ se  a-kb ≥ 0 abbiamo che q  > k e quindi
				(a-kb) - (a-qb) = (q-k)b ≥ 0
- perché b > 0 e q ≥ k, e tale diseguaglianza dimostra che a-qb è il minimo in S.
- supponiamo per assurdo che sia 0 < b ≤ r. In particolare, avremmo r = b+h per qualche h≥0. Quindi
				a = qb + r = qb + b + h = (q + 1)b + h
- ed allora h = a-(q+1)b ∈ S ossia h = a-(q+1)b < a-qb = r che contraddice l'ipotesi che r era il minimo di S
**Esempi**
![[Pasted image 20241204153415.png]]

**Secondo caso (dividendo a negativo, divisore b positivo)**
 Assumiamo che b > 0 mentre a < 0
 - Consideriamo il valore assoluto |a| > 0. Dal momento che a < 0 ne segue che |a| = -a
 - Per quanto visto nel primo caso, esistono q' ed 0 ≤ r' < b tali che 
				 |a| = q′b + r ′ e quindi − a = q′b + r 
   da cui otteniamo
				   a = (−q′)b + (−r ′)
- Se r' = 0 abbiamo finito. Se r' > 0 abbiamo 0 < b-r' < b e possiamo riscrivere l'uguaglianza come
	 a = (−q′)b + (−r ′) = (−q′)b − b + b + (−r ′) = (−q′ − 1)b + (b − r ′)
  prendendo come quoziente q = -q' -1 e come resto r = b - r' il secondo caso del teorema è dimostrato.
  come nel primo caso anche qua q = $\lfloor a/b \rfloor$
  **Esempi**
  ![[Pasted image 20241204174939.png]]
**Terzo caso (dividendo a positivo, divisore b negativo)**
Assumiamo che b < 0 e a > 0
- Consideriamo il valore assoluto |b| > 0 e sappiamo che |b| = -b
- Per quanto visto nel primo caso, esistono q' ed 0 ≤ r ′ < |b| tali che 
			a = q′|b| + r ′ e quindi a = q′(−b) + r 
  da cui otteniamo
			a = (−q′)b + r 
 - Prendendo come quoziente q = -q' e come resto r = r' il terzo caso del teorema è dimostrato
 **Esempi**
 ![[Pasted image 20241204175319.png]]
**Quarto caso (dividendo a negativo, divisore b negativo)**
Assumiamo che b < 0, a < 0
- Consideriamo i valori assoluti |a| > 0 e |b| > 0 e quindi |a| = -a e |b| = -b
- Per quanto visto nel primo caso, esistono q' ed 0 ≤ r ′ < |b| ovvero 0 ≤ r ′ < −b tali che 
				|a| = q′|b| + r 
- Utilizziamo i valori di q' e r' ed agendo come nel secondo caso, abbiamo
			a = (−q′ − 1)|b| + |b| − r ′ = (q′ + 1)b − b − r 
- Prendendo come quoziente q = q'+1 e come resto r = -b -r' il quarto caso del teorema è dimostrato
**Esempi**
![[Pasted image 20241204175806.png]]

**Definizione di divisibilità**
m è un divisore di n se il resto della loro divisione è 0 (es. 12,2   12/2 q = 6, r = 0, 2 è un divisore di 12)
Divisore = $m | n$
Non divisore $m \nmid n$
    

Esiste una particolare proprietà dei numeri dispari, **ovvero la somma dei primi n numeri dispari è uguale a $n^2$** 
Dimostriamo per induzione:
- Caso base: n = 1 e la somma in questo caso è proprio 1 = $1^2$ 
- (induzione): supponiamo allora che la somma dei primi n - 1 numeri dispari sia uguale a (n - 1)$^2$ 
- Come sono fatti i primi n numeri dispari? Sono della forma 2k + 1 per 0 ≤ k ≤ n − 1 . Infatti abbiamo 1 = 2 · 0 +1      3 = 2 · 1 +1,     5 = 2 · 2 +1 ecc...
- In particolare, l'ennesimo numero dispari sarà allora uguale a 2(n - 1) + 1. Se lo aggiungiamo a (n - 1)$^2$ otteniamo 
  (n − 1)$^2$ + 2(n − 1) + 1 = n$^2$ − 2n + 1 + 2n − 2 + 1 = n$^2$
  che dimostra la proprietà.

**Proprietà della divisibiltà**
**Teorema**
Siano a, b, c ∈ Z, allora                                         (| è un divisore, $\nmid$ NON è un divisore)
**(somma)** Se a | b e a | c allora a | (b+c)
**(prodotto)** Se a | b allora a | bc
**(Transitività)** Se a | b e b | c allora a | c

**Dimostrazione**
**Somma** 
Dato che a | b esiste x tale che b = ax, e dato che a | c esiste y tale che c = ay. Quindi b + c = ax + ay = a(x + y) e ponendo z = x + y abbiamo trovato un intero tale che b + c = az dimostrando che a | (b + c). 
**Prodotto** 
Dato che a | b esiste x tale che b = ax, quindi bc = axc il che dimostra che a | bc. **Transitività** 
Dato che a | b esiste x tale che b = ax, e dato che b | c esiste y tale che c = yb. Quindi by = axy ossia c = axy e ponendo z = xy abbiamo trovato un intero tale che c = az dimostrando che a | c.

**Corollario**
**(quadrato)** Se a | b allora a | $b^2$
**(Combinazione lineare)** Se a | b e a | c allora a | (hb + kc) per ogni h, k ∈ Z

**Dimostrazione**
Il primo caso è una banale conseguenza del caso "prodotto". 
Per il secondo caso, abbiamo che se a | b allora a | hb per ogni h ∈ Z e, se a | c, allora a | kc per ogni k ∈ Z. Quindi, a | (hb + kc)

**Teorema** **(proprietà di 0)**
Ogni relativo a è un divisore di 0 (a | 0) (ovvero 0 è multiplo di tutti i relativi). 0 è divisore solo di se stesso

**Dimostrazione**
- Per ogni a ∈ Z abbiamo che a · 0 = 0, quindi a | 0
- Se 0 | a allora esiste x tale che 0  · x = a. Ma 0  · x = 0 e quindi a = 0 (quindi 0 è un divisore solo di se stesso)

**Teorema** **(proprietà antisimmetrica)**
Siano a, b ∈ Z, se a | b e b | a allora |a| = |b| quindi a = ± b (es. 12, -12)

**Dimostrazione**
- Dalle ipotesi abbiamo che b = ax e a = by. Quindi, a = axy.
- Abbiamo allora che a(xy - 1) = 0 che implica che a = 0 oppure xy = 1
- Se il prodotto fra interi è nullo almeno uno dei fattori deve essere nullo. Quindi:
		-  Se a = 0 quindi b = 0y = 0 e la proprietà è dimostrata
		- Se xy = 1 allora o sono entrambi uguali ad 1 o entrambi uguali a −1. Quindi y = ±1 e a = ±b.

slide 46