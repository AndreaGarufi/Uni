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

**Corollario** **(altre proprietà)**
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
- Se il pro<span style="color:rgb(0, 0, 0)">dotto fra interi è nullo almeno uno dei fattori deve essere nullo. Quindi:
		-  Se a = 0 quindi b = 0y = 0 e la proprietà è dimostrata
		- Se xy = 1 allora o sono entrambi uguali ad 1 o entrambi uguali a −1. Quindi y = ±1 e a = ±b.
</span>

**Divisori banali**
**Teorema**
<span style="color:rgb(0, 0, 0)">Sia a ∈ Z, allora ±a | a e ±1 | a</span>

**Dimostrazione** (esercizio)
Data la definizione di divisibilità, ovvero dati n,m ∈ Z, m è un divisore di n se il resto (r) della divisione di n per m è uguale a zero. Il resto della divisione tra un qualsiasi numero n e ± 1 è sempre uguale a 0 e quindi  ± 1 è un divisore di tutti i numeri.
Possiamo applicare la stessa definizione ponendo m = ± n, il resto della divisione di n con se stesso darà sempre resto 0 da questo capiamo che  ± n è divisore di n.

**MINIMO COMUNE MULTIPLO**
**Definizione (MCM)** 
Siano a, b ∈ Z non entrambi nulli, si chiama Minimo Comune Multiplo fra a e b un terzo intero m ∈ N (quindi positivo) tale che m è il più piccolo multiplo sia di a che di b. Ovvero, 
- a | m e b | m cioè a, b sono entrambi divisori di m 
- Se x è un multiplo comune di a e b, ovvero a | x e b | x, allora m | x cioè m divide ogni altro multiplo comune di a e b

**MASSIMO COMUNE DIVISORE**
**Definizione (MCD)**
Siano a, b ∈ Z non entrambi nulli, si chiama Massimo Comune Divisore fra a e b un terzo intero d ∈ Z tale che: 
- d | a e d | b cioè d è un divisore sia di a che di b 
- Se x è un divisore comune di a e b, ovvero x | a e x | b, allora x | d cioè d è multiplo di ogni altro divisore comune di a e b

**ALGORITMO DI EUCLIDE**
**Definizione semplice (chatGPT)**
![[Pasted image 20250120211548.png|500]]


**Definizione difficile (slide Cutello)**
è un modo più facile per calcolare il MCD.
L’algoritmo si basa su questa osservazione (che è anche la dimostrazione per induzione della sua correttezza ). 
Siano a, b ∈ N e sia b ≤ a. Allora
**(Caso Base)** se b = 0 allora il MCD(a, b) = a. Altrimenti 
**(Passo Induttivo)** visto che a = qb + r con 0 ≤ r < b allora
					MCD(a, b) = MCD(b, r )

Notiamo che se b | a allora a = qb ed il resto della divisione r = 0 e quindi MCD(a, b) = MCD(b, 0) = b per il caso base. Quindi, se b | a otteniamo in un passo che MCD(a, b) = b.

 Dimostriamo allora che se a = qb + r con r $\neq$ 0 e 0 < r < b allora 
 MCD(a, b) = MCD(b, r ) 
 - Se d è un divisore di a e b allora esistono h e k tali che a = hd = qkd + r . Quindi r = d(h − qk) e quindi d è anche un divisore di r . 
 - Viceversa, se d è un divisore di b e di r allora esistono h e k tali che a = qb + r = qkd + hd e quindi d è un divisore di a visto che a = d(qk + h)

**Esempio**
X<sub>1</sub> = 330            X<sub>2</sub> = 156 
330%156 = 18 -> 330 = 2 · 156 + 18
156%18 = 12 -> 156 = 8 · 18 + 12
18%12 = 6 -> 18 = 1 · 12 +6
12%6 = 0 -> 12 = 2 · 6 +0
quindi MCD(330,156) = 6

Notiamo che 330/6 = 55 = 5 · 11 e 156/6 = 26 = 2 · 13 e quindi il risultato è corretto

Dall'esempio, notiamo anche che andando a ritroso
6 = 18 - 12 = 
= 18 -(156 - 8 · 18) = -156 + 9 · 18 =
= -156 + 9 · (330 - 2 · 156) =
= -19 · 156 + 9 · 330

Quanto appena visto, suggerisce una dimostrazione costruttiva del seguente teorema che ci dice che il MCD tra due numeri si può sempre scrivere come una loro combinazione lineare

**Teorema**
 Siano a, b ∈ N non entrambi uguali a 0, allora esistono h, k ∈ Z tali che
MCD(a,b) = a · h + b · k

**NUMERI PRIMI**
**Definizione numero primo**
si definisce Numero Primo un intero relativo p tale che p ha come divisori solo quelli banali (se stesso e 1) e tale che p $\neq$ ± 1

**Definizione numero coprimo**
Due numeri a,b ∈ Z si dicono coprimi se MCD(a,b) = 1

- Sappiamo allora che esistono h,k ∈ Z tali che a · h + b · k = 1
- Vale anche il viceversa, ovvero il seguente teorema 
**Teorema** 
Siano a, b  ∈ N non entrambi uguali a 0, se esistono h,k ∈ Z tali che a · h + b · k = 1 allora MCD(a, b) = 1

**proprietà numeri coprimi**
1) Due numeri interi consecutivi sono coprimi
2) Siano a,b,c ∈ Z tali che c | a · b **se c, a coprimi**. Allora c | b
3) Siano a,b,c ∈ Z tali che a | c e b | c , **se a e b sono coprimi** allora a · b | c

la seconda e terza proprietà hanno l'ipotesi della coprimalità fondamentale, infatti se non sono coprimi queste 2 proprietà non valgono
es. 9 | 3 · 6 ma 9 $\nmid$ 3 e $\nmid$ 6

(vedi dimostrazioni slide 58)

**Teorema fattorizzazione degli interi**

Ogni intero n > 1 si può esprimere come prodotto di numeri primi positivi ed in modo unico a meno dell'ordine dei fattori

unicità nel senso che 84 = 2 x 2 x 3 x 7 e il massimo che si può fare è cambiare l'ordine dei fattori: 84 = 2 x 3 x 2 x 7, non c'è altro modo di avere 84 con diversi numeri primi

**Dimostrazione**
verrà dimostrato in 2 passi:
1) Prima dimostriamo che dato un qualunque intero naturale n > 1 esiste una fattorizzazione di n;
2) successivamente, dimostriamo che tale fattorizzazione è unica.

1) Se, per assurdo, esistessero interi > 1 che non siano prodotto di numeri primi positivi, potremmo costruire l’insieme
			 S = {n : n ∈ N, non prodotto di numeri primi} 
			 
Per l’assioma di buon ordinamento, possiamo scegliere il minimo dell’insieme S, denotiamolo con s. Per definizione, s non è primo perché se lo fosse sarebbe prodotto ( con un solo fattore) di primi positivi (se stesso) e quindi non sarebbe in S. Quindi, s ha divisori diversi da quelli banali e quindi almeno un divisore positivo 1 < d < s. Allora, esiste c ∈ N tale che s = d · c, e anche 1 < c < s. Poiché, c ed d sono minori di s, che ricordiamo è il più piccolo elemento in S, allora c e d sono prodotti di primi positivi, e quindi anche s lo è. 

2) Sia 
 $n = p_1 · p_2 · . . . · p_r = q_1 · q_2 · . . . · q_s$
 
 con $p_i$ e $q_j$ numeri primi positivi. Dobbiamo dimostrare che r = s e che possiamo riordinare i fattori primi ed avere $p_i =q_i$ per ogni i. Dimostriamolo per induzione su r .
 - Caso base: r = 1. Se $n = p_1$ allora n è primo, e quindi non ha divisori diversi da quelli banali, ossia se stesso e ±1. Quindi, da $p_1 = q_1 · q_2 · . . . · q_s$ otteniamo che 
   $s = 1$ e $q_1 = p_1$
 
 - Caso induttivo: supponiamo la tesi sia vera per r e dimostriamola per r + 1. Se 
 
   $n = p_1 · p_2 · . . . · p_r · p_{r + 1} = q_1 · q_2 · . . . · q_s$
   
   abbiamo che $q_1$ è un divisore di $p_1 · p_2 · . . . · p_r · p_{r +1}$ e quindi, per quanto precedentemente visto, deve dividere almeno uno dei fattori. Ma sono tutti fattori primi, quindi, $q_1$ deve essere uguale ad almeno uno dei fattori, che, a meno di riordinare il prodotto, possiamo assumere sia $p_1$. Dividendo membro a membro per $p_1$ otteniamo $p_2 · . . . · p_r · p_{r + 1} = q_2 · . . . · q_s$

   Dal momento che:
   $p_2 · . . . · p_r · p_{r + 1} = q_2 · . . . · q_s$
   e i fattori del primo membro sono r possiamo applicare l'ipotesi induttiva
   Abbiamo allora che il numero dei fattori a primo membro è uguale al numero dei fattori a secondo membro, ossia r = s - 1 e quindi $q_2,.....,q_s$ a meno dell'ordine 
   - poiché anche $p_1 = q_1$ il teorema è dimostrato


**Teorema di Euclide**
I numeri primi sono infiniti
**Dimostrazione**
![[Pasted image 20241215101727.png]]

Un altro esempio del fatto che i numeri primi sono infiniti lo da il:
**Teorema di Bertrand-Chebyshev**
Per ogni n ≥ 2 esiste un numero primo p tale che n < p < 2n.



I numeri primi non solo sono infiniti ma anche distribuiti in maniera frequente, infatti vale il: 
**Teorema della densità dei numeri primi**
Sia n ∈ N e sia π(n) il numero di "numeri primi" minori o uguali ad n. Allora:
![[Pasted image 20241215102009.png|180]]
![[Pasted image 20241215102503.png]]

   
   ![[Pasted image 20241215102619.png]]

**Come si verifica se un numero n è primo?**

Bisogna capire se ha altri divisori oltre a quelli banali: 
Posso controllare tutti i numeri interi compresi tra 2 e $\sqrt{n}$ 
infatti se il più piccolo divisore di n, chiamiamolo h, fosse maggiore di $\sqrt{n}$ avremmo:

n = h · q > $\sqrt{n}$ · $\sqrt{n}$ = n
quindi questo è un **assurdo**


**Come si calcolano tutti i numeri primi minori o uguali ad un numero prefissato ?**
Posso usare il **crivello di Eratostene**

 **Come funziona?**
 Supponiamo di voler calcolare tutti i numeri primi tra 2 e n.
 1. Scriviamo in sequenza tutti i numeri naturali compresi tra 2 e n
 2. partiamo dal numero 2 e cancelliamo dalla sequenza tutti i multipli di 2.
 3. ad ogni passo successivo prendiamo il primo numero che non è stato cancellato e cancelliamo tutti i suoi multipli
 4. quando abbiamo cancellato tutti i multipli del numero più grande che sia minore o uguale a $\sqrt{n}$ ci fermiamo
 5. tutti i numeri rimasti sono compresi tra 2 e n

(Guarda esempio slide 68-72)



**CRITERI DI DIVISIBILITA'**

Esistono delle regole molto semplici per verificare, in alcuni casi speciali, se un numero a divide un numero b.

Elencherò tutte le divisibità che spiegherò:
1. **Divisibilità per 2**
2. **Divisibilità per 3**
3. **Divisibilità per 5**
4. **Divisibilità per 7**
5. **Divisibiltà per altri numeri**
6. **Divisibiltà per 9**

7) **Divisibilità per 2**:
   Un numero n è divisibile per 2 **se e solo se è pari**
   
2) **Divisibilità per 3**:
   Un numero n è divisibile per 3 **se e solo se la somma delle sue cifre è divisibile per 3.**
   Si può reiterare il procedimento fino ad arrivare a 3,6,9 
   es. 1590 = 1+5+9+0 = 15 = 1+5 = 6 -> è divisibile per 3
   
3) **Divisibilità per 5**:
   Un numero n è divisibile per 5 **se e solo se l'ultima cifra è 0 o 5**
   
4) **Divisibilità per 7**:
   Un numero è divisibile per 7 **se e solo se dopo aver diviso n per 10, q - 2r è divisibile per 7 (o che venga 0)**
   Si può reiterare il procedimento fino ad arrivare ad un numero facilmente divisibile per 7
   es. 84/10 -> 8 - 2 · 4 = 0 -> è divisibile per 7
   581/10 -> 58 - 2 · 1 = 56 -> è divisibile per 7
   582/10 -> 58 - 2 · 2 = 54 -> non è divisibile per 7
   
5) **Divisibiltà per altri numeri**
   Per altri numeri primi vale la stessa cosa del 7 solo che cambia il numero con cui moltiplichiamo il resto quindi -> q + a · r è divisibile per p:
   
| p   | a   |
| --- | --- |
| 7   | -2  |
| 13  | 4   |
| 17  | -5  |
| 19  | 2   |
| 23  | 7   |
| 11  | -1  |
- 13 divide n se q + 4r è divisibile per 13
- 17 divide n se q − 5r è divisibile per 17 
- 19 divide n se q + 2r è divisibile per 19 
- 23 divide n se q + 7r è divisibile per 23
- 11 divide n se q - r è divisibile per 11

**Radice Numerica**

**Definizione**
dato n ∈ N la radice numeri di n, chiamiamola ρ(n) è la somma delle sue cifre reiterata sino ad ottenere una sola cifra:
198 = 18 = 9 -> ρ(198) = 9                                       (ρ(n) -> ro di enne)


**Divisibiltà per 9**
Un numero n è divisibile per 9 **se e solo se la somma delle sue cifre è un numero divisibile per 9, ossia se  ρ(n) = 9**


**Adesso scopriamo perché $\sqrt{2}$ non è un numero razionale**

Dimostriamo ragionando per assurdo:
- Assumiamo che esistano 2 numeri, a e b tali che $\sqrt{2} = \frac{a}{b}$
- Assumiamo che la frazione sia ridotta, ovvero il MCD(a,b) sia 1. Se non fosse cosi potremmo dividere numeratore e denominatore per il loro MCD ed ottenere lo stesso valore
- Allora, almeno uno dei 2 numeri deve essere dispari
- Elevando al quadrato otteniamo

  $2b^2 = a^2$

- Quindi il quadrato di a è pari ed allora anche a pari, ovvero esiste k tale che a = 2k
- Avremo allora
  $2b^2 = a^2 = 4k^2$ e quindi $b^2 = 2k^2$
- Allora anche b è pari, che contraddice la nostra ipotesi iniziale



**ARITMETICA MODULARE**

L'aritmetica modulare riguarda il calcolo sui resti delle divisioni tra interi rispetto ad un divisore fissato.

il resto (r) è denotato da: **n mod m** (n è la base, m è il modulo)

**se 2 numeri hanno lo stesso modulo e stesso resto si dicono congruenti.**
**a mod m = b mod m**
Congruenza -> a ≡ b(mod m) ->(a è congruo b modulo m)

es. 12 ≡ 9(mod 9): infatti 12 mod 3 = 0 e 9 mod 3 = 0
-15 ≡ 9(mod 4): infatti -15 mod 4 = 1 e 9 mod 4 = 1

**PROPRIETA' DELLA CONGRUENZA**
**Riflessiva**: Per ogni a ∈ Z è vero che a ≡ a(mod m)? Si, perché 0 = a − a è multiplo di m (lo 0 è multiplo di qualunque numero.)

**Simmetrica**: Se a ≡ b(mod m) allora a − b = km per qualche k ∈ Z e quindi, moltiplicando per −1 otteniamo b − a = (−k)m ossia b ≡ a(mod m)

**Transitiva**: Se a ≡ b(mod m) e b ≡ c(mod m) abbiamo che esistono h, k ∈ Z tali che a − b = hm e b − c = km. Sommando membro a membro le ultime due uguaglianze otteniamo: a − c = (h + k)m e quindi a ≡ c(mod m).

 **Proprietà  ->** se a ≡ b(mod m) allora a ≡ b(mod( −m)

**Congruenze:
modulo 0 -> a ≡ b(mod( 0) se e solo se a-b = 0
modulo 1 -> qualsiasi numero è congruo ad un altro se il modulo è 1
modulo 2 -> a ≡ b(mod( 2) se e solo se a-b è un numero pari**

Nella **classe di equivalenza** rispetto alla congruenza modulo $m$, ci stanno **tutti gli interi** che hanno lo **stesso resto** quando vengono divisi per $m$. E si denota con $[a]_m$

**Congruenze aritmetiche**
**Dato a ∈ Z come facciamo a stabilire in quale classe resto sta?**
$[a]_m = [r ]_m$ dove r è il resto della divisione di a per m. Quindi se m = 5 e a = 22 allora eseguendo la divisione abbiamo 22 : 5 = 4 con resto di 2, ottenendo che $[22]_5 = [2]_5$ 

**Teorema Invarianza rispetto a somma e prodotto**
Dato m ∈ N e dati a, b ∈ Z tali che a ≡ b(mod m), allora comunque prendiamo c, d ∈ Z tali che c ≡ d(mod m) abbiamo
1) a + c ≡ b + d(mod m) 
2) a · c ≡ b · d(mod m)

Grazie a questo teorema **sappiamo che se ad una congruenza sommiamo o moltiplichiamo una stessa quantità la congruenza rimane**
**Se sottraiamo ad ambo i membri uno stesso numero la congruenza riamane, ma se dividiamo per uno stesso numero la congruenza potrebbe non valere più**

**Dimostrazione fatta da Girlando**
![[Pasted image 20250106163921.png]]

**Proprietà**
1) (a + b) mod m = (a mod m + b mod m)
2) a · b) mod m = ((a mod m) · (b mod m))
3) $a^n$ ≡ $(a\,\, mod\,\, m)^n$ 
4) $a^h · b^k\,\, mod\,\, m = (a\,\, mod\,\, m)^h · (b\,\, mod\,\, m)^k$ 

es 1) 60 mod 7 = (50 +10) mod 7
es 2) 60 mod 7 = (6 · 10) mod 7
es 3) $13^2$ mod 10 = (13 mod 10)$^2$ 
es 4) 41503 mod 5 = ($11^2$ mod 5) · ($7^3$ mod 5)    

(nella slide 100 è scritto diverso c'è un altro mod 5 dopo (chiedi a girlando))

Possiamo dire:
- Dati 2 numeri consecutivi, almeno uno dei due numeri è divisibile per 2. E questo già lo sapevamo. 
- Dati 3 numeri consecutivi, esattamente uno dei tre numeri è divisibile per 3 ed almeno uno è divisibile per 2. Quindi, il prodotto di 3 numeri consecutivi è sempre divisibile per 6. 
- Dati 5 numeri consecutivi, esattamente uno dei cinque numeri è divisibile per 5, almeno uno è divisibile per 3 ed almeno 2 sono divisibili per 2. Quindi, il prodotto di 5 numeri consecutivi è sempre divisibile per 60 
- etc.


**Teorema (Esistenza dell’inverso modulare)** 
Siano a, b ∈ N entrambi maggiori di zero. Allora, esiste un elemento x ∈ N tale che 
a · x ≡ 1(mod b) se e solo se a e b sono coprimi
es.
a = 5, b = 3 : $a^{-1}$ = 2, infatti 2 · 5 mod 3 = 10 mod 3 = 1.



**FUNZIONE DI EULERO**

Sia n > 0
**vogliamo contare quanti numeri precedono n e sono coprimi**
Definiamo allora la funzione 
		φ(n) = |{x : x ∈ N, 0 < x ≤ n e MCD(n,x) = 1}|

es.
n = 1 : φ(1) = 1 poiché 0 < 1 ≤ 1 e MCD(1, 1) = 1
n = 2 : φ(2) = 1 poiché 0 < 1 ≤ 2 e MCD(2, 1) = 1, mentre MCD(2, 2) = 2
n = 3 : φ(3) = 2 poiché MCD(3, 1) = 1, e MCD(3, 2) = 1 
n = 4 : φ(4) = 2 poiché MCD(4, 1) = 1, e MCD(4, 3) = 1
n = 5 : φ(5) = 4 poiché MCD(5, x) = 1, per x = 1, 2, 3, 4

##### Calcolo della phi:
1. **Per n numero primo** allora $φ(n) = n -1$
	- **Esempio:** $φ(11) = 11-1 = 10$
1. **Con n multiplo di un numero primo** φ(n) = $n^{k_1}$ - $n^{k_2-1}$
	-  **Esempio:** φ(16) = $2^4$ - $2^3$
2. **Con n prodotto di numeri primi** $φ(n) = φ(k)\timesφ(q)...$ ($k$ e $q$ sono numeri primi)
	- **Esempio:** $φ(10) = φ(2\times5) = (2 - 1) · (5 - 1) = 1 · 4 = 4$

 
**Teorema (derivante dal teorema di Eulero)** 
Se p è primo e MCD(a, p) = 1, ovvero a non è un multiplo di p, allora ap−1 ≡ 1(mod p). 
Esempi: 
p = 3, a = 10 : 102 mod 3 = 100 mod 3 = 1 e quindi 102 ≡ 1(mod3). 
p = 5, a = 12 : 124 mod 5 = 20736 mod 5 = 1 e quindi 124 ≡ 1(mod5). 
p = 17, a = 40 : 4016 mod 17 = 1 e quindi 4016 ≡ 1(mod17).

**Teorema (derivante dal teorema di Eulero)**

Se MCD(a, n) = 1, allora per ogni x > 0 
$a^x$ ≡ $a^{x\,\, mod\,\, φ(n)}$ (mod n)

Esempio:

$12^{50}$ ≡ $12^{50\,\, mod\,\, φ(5)}$ (mod 5) ≡ $12^{50\,\, mod\,\, 4}$(mod 5) ≡ $12^2$ (mod 5) ≡ 4(mod 5) quindi 
$12^{50}$(mod 5) = 4.

[[Tips#Come calcolare i moduli]]

**CALCOLO DELL'INVERSO MODULARE**

**se n ed m sono coprimi**, l'inverso modulare è possibile e si calcola cosi:
$(n\,\, mod\,\, m)^{φ(m)−1}\,\, mod\,\, m$
es. $(12\,\, mod\,\, 13)^{φ(13)−1}\,\, mod\,\, 13$

Le applicazioni dell'aritmetica modulare sono molte, soprattutto in ambito informatico come ad esempio:

- La prova del 9 
- Codici ISBN e carte di credito 
- Cifrari a trasposizione 
- Hashing

**Sono da slide 135 a 147 (leggi quelle slide)**


**TEORIA DEI NUMERI**

**Si occupa delle proprietà dei numeri interi** (molte di queste le abbiamo già viste in precedenza)
Qui ci sono alcuni dei problemi aperti più famosi (avranno a che fare con frequenze numeriche)
**vedremo:
1) **Numeri di Mersenne**
2) **Numeri Perfetti**
3) **Numeri Primi Gemelli**
4) **Congettura di Goldbach**


**I numeri primi di Mersenne sono numeri primi della forma:**
$M_p = 2^p − 1$

es. 

$M_2 = 2^2 − 1=3$
$M_3 = 2^3 − 1=7$
$M_5 = 2^5 − 1=31$

Ad oggi si conoscono solo 52 numeri primi di Mersenne (hanno fino a 40 milioni di cifre o più). I numeri di Mersenne sono legati ai numeri perfetti
**Non si sa se i numeri di Mersenne sono infiniti**

**Numeri Perfetti: Funzione "Sigma"**

Dato n definiamo la seguente funzione:
![[Pasted image 20241223110625.png|200]]

La funzione **sigma** **restituisce la SOMMA di tutti i divisori positivi di un numero n**
es.
σ(1) = 1,  σ(2) = 3,  σ(4) = 7

ha tante proprietà ma la più semplice e intuitiva è che se **n è primo** allora σ(n) = n+1

**Numeri Perfetti**
Un numero **n** ∈ N si dice **perfetto se σ(n) = 2n**

Il primo numero perfetto è 6 , infatti σ(6) = 1+2+3+6 = 12 

si capì che se $2^n - 1$ è primo allora:
		$2^{n-1}·(2^n -1)$ 
è perfetto
es. $2^{3-1}·(2^3 -1)$  = 4 · 7 = 28 (28 è il secondo numero perfetto)

**I principali problemi ancora aperti sono:** 
1. **Esistono numeri perfetti dispari?**
2. **I numeri perfetti sono infiniti oppure no?**

(curiosità: tutti i numeri perfetti pari finiscono o per 6 o per 8)

**Numeri primi gemelli**

**2 numeri primi si dicono gemelli se la loro differenza è uguale a 2**
$|p_1 - p_2| = 2$

es. (3,5),(5,7)(17,19)...

abbiamo che $p_1 < p_2$ e il numero $p_1 + 1$ è detto separatore della coppia di gemelli
(i numeri primi che distano 4 si dicono "primi cugini")
**Anche qui il problema è se siano infiniti oppure no**
c'è anche una congettura irrisolta: Per ogni intero k ≥ 1, esistono infinite coppie di numeri primi consecutivi la cui differenza è 2k?

**Congettura di Goldbach**

La congettura afferma che ogni numero maggiore di 4 può essere scritto come somma di 2 numeri primi
es. 6 = 3+3, 12 = 7+3+2, 10 = 3+7

**ad oggi non è stata dimostrata ne si è trovato un numero pari che non si possa scrivere come somma di 2 numeri primi**

 - **Sappiamo che per ogni intero x ≥ 2 esiste un intero d ≥ 0 tale che** 
   **x-d e x+d sono entrambi numeri primi**
   d è la distanza di Goldbach: vale 0 per i numeri primi (sono già primi)
   es. d(2) = 0, d(3) = 0, d(4) = 1 (4 -1 = 3, 4+1 = 5)

Si dicono "Interprimi" i numeri che sono il punto di mezzo di 2 numeri primi

I = {4, 6, 9, 12, 15, 18, 21, 26, 30, 34, . . .}

Grazie ai computer moderni si è verificata la congettura fino a interi pari a circa $10^{17}$
Si assume la sua veridicità (grazie al teorema sulla densità dei numeri primi)


**Congettura di Collatz**

Si basa su un algoritmo iterativo:

![[Pasted image 20241223185728.png|250]]

L’algoritmo è il seguente

Algoritmo di Collatz 
**Leggi un intero** x ≥ 1 
**while** (x > 1) **do**
**if** x mod 2 == 0 x = x/2; 
**else** x = 3 ∗ x + 1; 
**end_while**

**Il problema è: l' algoritmo si ferma sempre oppure esiste un x partendo dal quale non si raggiunge mai il valore 1?**

es.
n = 1 :→ 1 
n = 2 :→ 2, 1 
n = 3 :→ 3, 10, 5, 16, 8, 4, 2, 1 
n = 4 :→ 4, 2, 1 n = 5 :→ 5, 16, 8, 4, 2, 1 
n = 6 :→ 6, 3, 10, 5, 16, 8, 4, 2, 1 
n = 7 :→ 7, 22, 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1 
n = 8 :→ 8, 4, 2, 1 
n = 9 :→ 9, 28, 14, 7, 22, 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1 
n = 10 :→ 10, 5, 16, 8, 4, 2, 1
		$\uparrow$  Questa è la sequenza che si genera ed è detta **traiettoria**

Da queste traiettorie si possono ricavare molti dati, come il numero massimo, i record di numeri massimi, la lunghezza ecc..

Esiste un algoritmo semplificato:
Algoritmo di Collatz (semplificato)
**Leggi un intero** x ≥ 1 
**while** (x > 1) **do**
**if** x mod 2 == 0 x = x/2; 
**else** x = (3 ∗ x + 1)/2; 
**end_while**

 (cambia che c'è un /2 nella riga dell'else)
in questo modo le traiettorie si accorciano:
es. n = 1 :→ 1
n = 2 :→ 2, 1 
n = 3 :→ 3, 5, 8, 4, 2, 1 
n = 4 :→ 4, 2, 1 
n = 5 :→ 5, 8, 4, 2, 1 
n = 6 :→ 6, 3, 5, 8, 4, 2, 1 
n = 7 :→ 7, 11, 17, 26, 13, 20, 10, 5, 8, 4, 2, 1

La congettura si può riformulare in questo modo: dato un intero n ≥ 1 l’algoritmo raggiunge sempre una potenza di 2? (ci fermiamo quando raggiungiamo una potenza di 2)

in questo modo le traiettorie si accorciano:
n = 1 :→ 1 
n = 2 :→ **2** 
n = 3 :→ 3, 10, 5, **16** 
n = 4 :→ **4** 
n = 5 :→ 5, **16**
n = 6 :→ 6, 3, 10, 5, **16** 
n = 7 :→ 7, 22, 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, **16** 
n = 8 :→ **8** 
n = 9 :→ 9, 28, 14, 7, 22, 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, **16**
n = 10 :→ 10, 5, **16** 
n = 11 :→ 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, **16** 
n = 12 :→ 12, 6, 3, 10, 5, **16** 
n = 13 :→ 13, 40, 20, 10, 5, **16**
n = 14 :→ 14, 7, 22, 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, **16**
n = 15 :→ 15, 46, 23, 70, 35, 106, 53, 160, 80, 40, 20, 10, 5, **16**