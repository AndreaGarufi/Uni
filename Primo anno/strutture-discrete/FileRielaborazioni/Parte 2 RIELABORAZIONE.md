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

**continua da slide 23**
