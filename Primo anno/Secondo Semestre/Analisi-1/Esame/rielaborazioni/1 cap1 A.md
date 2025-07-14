Insiemi numerici. Dai numeri naturali ai numeri reali. Insiemi finiti, infiniti, numerabili. Elementi di struttura di R: potenza del continuo. Densità di Q e di R\Q in R. Intervalli, intorni. Insiemi limitati. Minimo e massimo, minoranti e maggioranti, estremi inferiore e superiore di un insieme numerico. Insiemi separati, insiemi contigui. Punti interni, di frontiera, di accumulazione. Proprietà delle diseguaglianze fra numeri reali. Valore assoluto e sue proprietà. Potenza intera di un numero reale. Teorema della radice n-ma aritmetica. Potenza con esponente non intero di un numero reale. Numeri complessi: definizione, forma algebrica e trigonometrica. Potenze e radici di un numero complesso.



**Dai numeri naturali ai numeri reali**
Rendiamo noti questi insiemi:
**Numeri naturali** -> $N$     es. 1,2,3,4,5...
$N_0$ -> $N \cup \{0\}$                   es. 0,1,2,3,4,5...
**Numeri relativi** -> $Z$       es. ...-2,-1,0,1,2...
**Numeri razionali** -> $Q$    es. $\frac{3}{4}$

**Successivo di n e principio di induzione su $N$**
Indicheremo il **successivo** di $n$ con $n'$ e non $n+1$ perché ancora non conosciamo l'addizione.
Nell'insieme dei numeri naturali vale il principio di induzione, ovvero che se una proprietà è vera per $n = 0$ (caso base) e si suppone sia vera anche per un certo $n$, si riesce a provare che è vera anche per $n'$ allora essa è vera anche per tutti i numeri naturali.

**Operazioni $+$ e $\cdot$** 
Il principio di induzione su $N$ è un postulato ovvero si prende per vero senza dimostrarlo.
Da qui si possono definire le operazioni **somma e prodotto**.
Se $a\,∈\,N_0$ per definire $a\,+\,n$ e $a\,\cdot\,n$ per un qualunque $n\,∈\,N_0$ si pone:
1) $a+0=a$ 
2) $a+n'=(a+n)'$
3) $a\cdot0=0$
4) $a\cdot n'= (a\cdot n) +a$

Si definisce anche la **potenza** di un numero naturale
1) $a^0 =1$
2) $a^{n'}=a^n+a$

Le potenze godono di queste **proprietà**
1) $a^n+a^m=a^{n+m}$
2) $(a^n)^m = a^{nm}$
3) $(a\cdot b)^n = a^n \cdot b^n$


**Nel seguito, ometteremo il simbolo ”·” per indicare il prodotto.**

Da $a+0=a$  emerge che $a+1=a+0' = (a+0)' = a'$

Infine definiamo $a<b$ se esiste un $n ∈\,N$ tale che $a+n=b$ 

**Sottrazione e divisione**
Servono a risolvere dei problemi quali: quello di trovare $n$ tale che $n=b+a$ (sottrazione) e quello di trovare $n$ tale che $a=bn$ (divisione). Essi tuttavia non sono sempre risolvibili e questo a portato a nuovi insiemi numerici

**Insieme numeri relativi $Z$**
Ad un $n∈N$ aggiungiamo i segni + e - creando cosi l'insieme $Z$ composto da: $\{0\} \cup \{+n : n∈N\}\cup \{-n : n∈N\}$
Qui notiamo che la sottrazione diventa sempre risolvibile, inoltre **$N$ è un sottoinsieme di $Z$** perché $n$ e $+n$ si comportano allo stesso identico modo (sono lo stesso numero)

**Insieme numeri razionali $Q$** 
Questo insieme è formato da tutte le coppie diverse da 0 di $(m,n)$ dove $m∈Z$ e $n∈N$, questo perché al denominatore il numero è positivo e il segno si mette al numeratore. Qui vediamo che anche la divisione e sempre risolvibile
$Z$ **è un sottoinsieme di** $Q$ perché $z∈Z$ e $\frac{z}{1}∈Q$ si comportano allo stesso identico modo (sono lo stesso numero)

**Insieme numeri reali $R$**
L'insieme $Q$ lascia irrisolto il problema dell'estrazione della radice (es. $\sqrt{2}$ , qual è il numero che elevato alla seconda da come risultato 2? Non esiste in $Q$), si utilizza così la rappresentazione dei numeri in decimale, infatti ogni $\frac{m}{n} ∈Q$ ammette la rappresentazione del tipo:  $a=±a_0,a_1,a_2,a_3 ...$ -> numeri con la virgola
che può essere finito o periodico.
**Adesso possiamo introdurre** $R = \{0\}\cup \{±a_0,a_1,a_2,a_3 ...:a_0 ∈N_0, a_i∈\{ 0 ...9\}∀i ∈ N_0\}$
$R$ **è quindi costituito da tutti gli allineamenti decimali periodici e non periodici e dallo zero**

se l'allineamento decimale (i numeri dopo la virgola) è periodico (sempre gli stessi numeri dopo la virgola es. 1,333...) è razionale, altrimenti irrazionale (cioè non può essere scritto come frazione) 

**Per introdurre ordine in $R$:**
1) Ogni numero negativo è minore di 0 e ogni positivo è maggiore di 0
2) dati 2 numeri positivi diremo maggiore quello con la prima cifra diversa maggiore es. +4, 718652 > +4, 718372
3) Dati 2 numeri $a,b<0$ diremo che $a<b$ se $-a >-b$

**Somma in $R$**
1) $a+0=a$ per ogni $a∈R$
2) Supponiamo di avere 2 numeri $a,b>0$, prendiamo le successioni decimali troncate fino a $n$ numeri e sommiamo i $a_0,a_1,a_2,a_n$ + $b_0,b_1,b_2,b_n$ vedremo che le cifre tenderanno a stabilizzarsi. es.
![[Pasted image 20250709165824.png]]


3) Se uno dei due numeri è negativo (o lo sono entrambi) si procede come nel caso dei numeri razionali: ad esempio, −π + √2 = −(π − √2)


**TEOREMA di densità di $Q$ e $R \setminus Q$ in $R$**
Siano $a,b$ 2 numeri reali con $a<b$, allora esistono infiniti numeri razionali $r$ e irrazionali $s$ tra $a$ e $b$Quindi $a < r < b$    e     $a < s <b$ 
(in pratica ci sono infiniti numeri decimali, frazioni e virgola, tra 2 numeri reali a e b)

Tutti gli infiniti numeri compresi tra $a$ e $b$ prendono il nome di **intervallo** di estremi $a$ e $b$
Considereremo **2 tipi di intervalli: limitati e non limitati**.
1) Intervalli limitati
   - $]a,b[\,=\{x∈R: a<x<b\}$
   - $[a,b]\,=\{x∈R: a≤x≤b\}$ 
1) Intervalli non limitati
   - $]a,+∞[\,=\{x ∈R: x>a\}$ ->semiretta non limitata superiormente
   - $]-∞,b[\,=\{x∈R:x <b\}$ ->semiretta non limitata inferiormente
   - analogamente: $[a,+∞[$ e $]-∞,b]$
   - $]-∞,+∞[\,=R$
 
Con la scrittura (a,b) definiamo un intervallo generico (uno qualunque di quelli sopra)
Un intervallo del tipo $]c-r,c+r[$ (con $c∈R,r>0$) è detto **intorno** di $c$ di raggio $r$




**Insiemi finiti, infiniti, numerabili**
- Siano $A$ e $B$ 2 insiemi non vuoti, diremo che hanno la **stessa potenza** se esiste una corrispondenza biunivoca $f : A\, -> B$
- Diremo che **$X$ è finito** ed ha $n$ elementi se esiste una corrispondenza biunivoca tra $X$ e $\{1,2 ...n\}$, **in caso** **contrario è detto infinito**
- Un **insieme infinito ha la caratteristica di avere la stessa potenza dei suoi sottoinsiemi**, es. prendiamo $N$ (naturali) e $P$ che è l'insieme dei numeri naturali pari, possiamo fare una corrispondenza biunivoca tra $n∈N$ e $2n∈P$ (se raddoppio un qualsiasi numero per 2, questo è pari)
- Un **insieme $X$ è detto numerabile se ha la stessa potenza di $N$**, $Z$ e $Q$ sono numerabili, per $R$ invece:
  - Tutti gli intervalli hanno la medesima potenza, (1,2) (4,6) (+∞,-∞) hanno tutti la stessa cardinalità (ci sono numeri infiniti tra 1 e 2 o tra 4 e 6)
  - La potenza degli intervalli è maggiore del numerabile, un intervallo reale come (0,1) non è numerabile: non esiste un modo per elencare tutti i numeri reali in quell'intervallo.
  - $R$ ha la stessa potenza di un suo intervallo, (hanno la stessa cardinalità)
$R$ **ha quindi una potenza maggiore del numerabile, ha quindi la potenza del continuo**


**Valore assoluto**
Se $x$ è un numero reale, definiamo $|x|$ il valore assoluto di $x$, che quando:
- $x≥0$ -> $|x| = x$ 
- $x<0$ -> $|x|=-x$ 
Fatto cosi in modo che a prescindere dal segno del numero $|x|$ sia positivo

**Proprietà per ogni x,y,z ∈ R**
1) $|x| ≥0$,   $|x|=0$ se e solo se $x=0$
2) $|-x|=|x|$
3) $−|x| ≤ x ≤ |x|$
4) $|xy| = |x| |y|$
5) $a < x < b, a < y < b ⇒ |x − y| < b − a$
6) $−a < x < a ⇔ |x| < a$
7) $|a + b| ≤ |a| + |b|$
8) $|a − b| ≤ |a| + |b|$
9) $|x| < ε\,\,\,\,\, ∀ε > 0 ⇒ x = 0$


**Estremo inferiore ed estremo superiore**
Sia $X$ un insieme numerico, sottoinsieme non vuoto di $R$, un elemento $m∈X$ si dice **minimo** se $m <x$ per ogni $x∈X$, questo $m$ se esiste è unico.
un elemento $M∈X$ si dice **massimo** se $M > x$ per ogni $x∈X$, questo $M$ se esiste è unico.

**Perché potrebbero non esistere?**
Perché se l'intervallo è aperto ($]1,2[$) allora ne l'1 ne il 2 sono compresi, ma dato che tra 1 e 2 ci sono numeri infiniti non trovero mai un numero più piccolo di tutti. Stessa cosa vale per il massimo. Se l'intervallo è chiuso allora gli estremi sono massimo e minimo.

**Definizione**
1) Un numero $h∈R$ è detto **minorante** di $X$ se $h≤x$ per ogni $x∈X$, h può appartenere a X ma anche starne fuori, semplicemente se l'insieme è chiuso il minorante è anche il minimo, mentre se è aperto il minorante sarà fuori dall'intervallo dell'insieme. $\underline{M_x}$ è l'insieme dei minoranti.
2) Un numero $k∈R$ è detto **maggiorante** di $X$ se $k≥x$ per ogni $x∈X$. $\overline{M_x}$ è l'insieme dei maggioranti
3) E' detto **limitato inferiormente** se $\underline{M_x}\neq0$, è **limitato superiormente** se $\overline{M_x}\neq0$, è **limitato** se ha sia dei minoranti che dei maggioranti -> $h < x <k$ ossia quando $X$ è contenuto in un intervallo

**TEOREMA**
1) Sia $X$ un insieme numerico limitato inferiormente, allora l'insieme dei minoranti ($\underline{M_x}$) di $X$ è dotato di massimo
2) Sia $X$ un insieme numerico limitato superiormente, allora l'insieme dei maggioranti ($\overline{M_x}$) di $X$ è dotato di minimo

Possiamo ora definire l'estremo superiore e quello inferiore di $X$:
- **Se $X$ è limitato inferiormente si pone** $inf(X) =max(\underline{M_x})$, altrimenti $infX=-∞$
- **Se $X$ è limitato superiormente si pone** $sup(X) =min(\overline{M_x})$, altrimenti $infX=+∞$

**quindi un numero $l$ è un estremo inferiore di $X$ se e solo se verifica queste proprietà:**
1) $l ≤ x \,\,\,\,\,∀x ∈ X$ -> mi dice che $l$ è un minorante
2) $∀ε > 0\,\,\,\,\, ∃x ∈ X : x < l + ε$ -> mi dice che se sommo qualcosa a $l$ non è più un minorante di $X$ quindi $l$ è il massimo dei minoranti di $X$

**Analogamente un numero $L$ è un estremo superiore di $X$ se e solo se verifica queste proprietà**
1) $L ≥ x \,\,\,\,\,∀x ∈ X$
2) $∀ε > 0\,\,\,\,\, ∃x ∈ X : x > L − ε$


**Nozioni di topologia**
$]c-r,c+r[$ -> si intende l'intervallo creato quindi da c ad r
**Punto Interno**
Sia $X$ un insieme numerico. Si dice **punto interno di $X$** un punto $c$ se esiste $r>0$ tale che $]c-r,c+r[$ ⊆ $X$ -> un punto che sta dentro l'insieme numerico $X$
Osserviamo che se X è un intervallo (a, b), i punti interni sono tutti e soli i punti dell’intervallo aperto $]a, b[$, l'insieme dei punti interni di $X$ è chiamato interno di $X$ e si denota con $int(X)$.
L'insieme **$X$ è detto aperto** se è vuoto oppure, quando non è vuoto, tutti i suoi punti sono interni: $X = int(X)$ (es. $]a,b[$ oppure (1,3), anche ∅ e $R$)

**Punto di frontiera**
Un numero reale $c$ è detto di frontiera se per ogni $r>0$ nell'intorno $]c-r,c+r[$ ci sono elementi di $X$ e elementi di $R\setminus X$ 

**Punto di accumulazione**
Un numero reale $c$ è detto di accumulazione se per ogni $r>0$ nell'intorno $]c-r,c+r[$ ci sono elementi di $X$ diversi da $c$ e il loro insieme si denota con $D(X)$ (la clausola “diverso da $c$” serve per **escludere i punti isolati**)
(in breve un punto di accumulazione può essere dentro o fuori da $X$ basta che nell'intervallo $]c-r,c+r[$ ci sia almeno un punto di X diverso da $c$)
Un punto interno è sempre di accumulazione mentre uno di frontiera può non esserlo.
Un punto che non è di accumulazione si dice **punto isolato**

L’insieme $X$ è detto chiuso se il suo complementare $R \setminus X$ è aperto. **Si definisce chiusura di $X$ l’insieme**: $\overline{X}=X∪D(X)$ 
da cui segue che un insieme è chiuso se e solo se contiene tutti i suoi punti di accumulazione e tutti i suoi punti di frontiera.

Diremo che $X$ è denso in $R$ se $\overline X = R$ 


**Potenze, radici, logaritmi**
Se $a∈R$ e $n∈N_0$ allora **si definisce**:
- $a^0=1$
- $a^{n+1}=a^n+a$
Se $a∈R\setminus\{0\}$ e $n∈N$ allora **si definisce**:
$a^{-n}=\frac{1}{a^n}$

Per esprimere la potenza quando l'esponente è razionale o irrazionale serve prima questo teorema:
**TEOREMA DELLA RADICE $n$-esima ARITMETICA**
Siano $a∈R$, con $a > 0$ e $n∈N$, con $n ≥2$ , allora esiste uno ed un solo numero $b$ tale che $b^n=a$ 

il numero $b$ introdotto dal precedente teorema è detto radice $n$-esima aritmetica di $a$ e si indica con $\sqrt[n]{a}$ 
Grazie a questo teorema se $a>0$ e $n∈N$ **si definisce**:
$a^{\frac{1}{n}}=\sqrt[n]{a}$ 
$a^{\frac{m}{n}}=(\sqrt[n]{a})^m$ 

Per definire $a^b$ con $a > 0$ e $b$ irrazionale, si procede per stabilizzazione.

**Le potenze ab che abbiamo definito sono tutte positive**. E' possibile anche vedere che, se $a > 1$, si ha $a^b > 1$ se e solo se $b > 0$; $0 < a < 1$, si ha $a^b > 1$ se e solo se $b < 0$


**Discussione dell’equazione binomia**
Siano $a∈R$ e $n∈N$ con $n≥2$, vogliamo trovare tutti i numeri reali $x$ tale che $x^n=a$ .
Questa equazione è detta binomia.
Vediamo quante soluzioni ha al variare di $a$
1) $a=0$ , per la legge di annullamento del prodotto $x = 0$
2) $a>0$ per il teorema della radice l'unica soluzione positiva è 
   - $\sqrt[n]{a}$ 
   - $x=0$ non è soluzione
   - altre soluzioni saranno negative, in breve per $n$ pari $±\sqrt[n]{a}$ , per $n$ dispari $\sqrt[n]{a}$ 
3) $a<0$ , $x=0$ non è soluzione e non possono esserci soluzioni positive, quindi la soluzione è negativa, per $n$ pari non ci sono soluzioni mentre per $n$ dispari si ha  $-\sqrt[n]{-a}$ 

grazie a quanto visto possiamo estendere la nozione della radice: $\sqrt[n]{0}=0$  e $\sqrt[n]{x}=-\sqrt[n]{-x}$
per $x<0$ e $n$ dispari


**Logaritmo**
Siano $a$ e $b$ due numeri positivi con $a\neq1$, si può dimostrare che l'equazione $a^x=b$ ha una sola soluzione, detta logaritmo di $b$ in base $a$ -> $log_a\,\,\,b$ , il logaritmo verifica l'uguaglianza:
$a^{log_a\,\,\,b}=b$
**Proprietà**
1) $log_a\,\,\,a=1$    (l'equazione sarebbe $a^1=a$)
2) $log_a\,\,\,b=0$ se e solo se $b=1$ 
3) $log_a\,\,\,bc=log_a\,\,\,b+log_a\,\,\,c$
4) $log_a\,\,\,b^x=x log_a\,\,\,b$
5) $log_a\,\,\,\frac{b}{c}=log_a\,\,\,b-log_a\,\,\,c$
6) $log_a\,\,\,b=(log_a\,\,\,c)(log_c\,\,\,b)$ 
7) Dalla prima e dall’ultima delle precedenti eguaglianze, si ottiene:
   $1=log_a\,\,\,a=(log_a\,\,\,b)(log_b\,\,\,a)⇒log_b\,\,\,a = \frac{1}{log_a\,\,\,b}$

Osserviamo inoltre che: $log_a\,\,\,b>0$ se e solo se $a,b$ sono entrambi $> 1$ o $< 1$


**CENNI SUI NUMERI COMPLESSI**
**Definizioni e prime proprietà**
