**ARGOMENTI**
a) Limiti. Insieme di definizione. Limite di una funzione al tendere di x a c ed a ±∞. Limiti sinistro e destro. Principali risultati. Teorema ponte. Teorema sul limite di una funzione composta. Limiti delle funzioni elementari. Confronto fra infinitesimi e fra infiniti. Asintoti. Enunciato del teorema sul limite delle funzioni monotone. Limiti notevoli. 
b) Continuità. Funzioni continue in un punto e in un intervallo. Continuità delle operazioni fra funzioni e della funzione composta. Enunciato del Teorema di Weierstrass. Teorema di Darboux. Continuità della funzione inversa di una funzione continua. Continuità delle funzioni elementari. Punti di discontinuità e loro classificazione.

**LIMITI E CONTINUITA' DELLE FUNZIONI REALI DI UNA VARIABILE REALE**
Studiare il limite di una funzione significa vedere qual è il comportamento della funzione stessa quando la variabile si avvicina (”tende”) ad un certo punto, ovvero quando $x$ appartiene ad un intorno di tale punto. Le nove definizioni si differenziano l’una dall’altra solo per il diverso significato che assume di volta in volta il termine ”definitivamente”


**Limite al tendere di $x$ a $c$**
Data una funzione reale definita nell'insieme $X⊆ R$ se $c$ è un punto di accumulazione si definisce il limite di $x$ a $c$ nel seguente modo:
1) Si dice che $f$ converge al numero l al tendere di $x$ a $c$ e si scrive $lim_{x\to c} f(x)=l∈R$ (Più ti avvicini a $c$, più $f(x)$ si avvicina a $l$)
2) Si dice che $f$ diverge a $+∞$ al tendere di $x$ a $c$ e si scrive  $lim_{x\to c} f(x)=+∞$ (Più ti avvicini a $c$, più $f(x)$ cresce senza limiti, superando qualsiasi soglia positiva $k$ tu scelga)
3) Si dice che $f$ diverge a $-∞$ al tendere di $x$ a $c$ e si scrive  $lim_{x\to c} f(x)=+-∞$ (Più ti avvicini a $c$, più $f(x)$ scende senza limiti, andando oltre qualsiasi soglia negativa $k$ tu scelga)

Per poter prendere in considerazione il calcolo del limite la $f$ deve esistere in un intorno di $c$ quindi è fondamentale che $c∈D(X)$

Se una delle 3 condizioni di sopra sono soddisfatte la funzione è regolare al tendere di $x$ a $c$ se non è regolare una funzione si dice oscillante
Anche qui ritroviamo dei teoremi delle successioni:
1) **TEOREMA DELL’UNICITA' DEL LIMITE**
   Se una funzione è regolare al tendere di $x$ a $c$, il suo limite è unico.
2) **TEOREMA DELLA PERMANENZA DEL SEGNO**. Se $lim_{x→c} f (x) = l > 0$, esiste un intorno di $c$ in cui si ha $f (x) > 0$
   analogamente se $l<0$ anche nell'intorno $c$ $f(x)<0$.
   Si giunge alla stessa conclusione se $f$ diverge. **Generalizzando questo risultato**, possiamo concludere che, se $k > l$ (risp. $k < l$), i valori della funzione saranno definitivamente minori (risp. maggiori) di $k$
3) **TEOREMA DI CONFRONTO PER FUNZIONI CONVERGENTI** (**“teorema dei carabinieri”**). Siano $f, g, h$ tre funzioni definite nello stesso insieme $X$ e sia $c \in D(X)$.  Supponiamo che  $f(x) \le g(x) \le h(x) \quad \text{per ogni } x \in X$  e che, al tendere di $x$ a $c$, le due funzioni $f$ e $h$ abbiano lo stesso limite $l$.  Allora:  $\lim_{x \to c} g(x) = l$

4) **TEOREMA DI CONFRONTO PER FUNZIONI DIVERGENTI
   Siano $f, g$ due funzioni definite nello stesso insieme $X$ e sia $c \in D(X)$.  Supponiamo che $f(x) \le g(x)$ per ogni $x \in X$. Allora:
   -  se $\lim_{x \to c} f(x) = +\infty$, allora $\lim_{x \to c} g(x) = +\infty$;
   -  se $\lim_{x \to c} g(x) = -\infty$, allora $\lim_{x \to c} f(x) = -\infty$.

5) **TEOREMA SUL LIMITE DI UNA FUNZIONE COMPOSTA**
   Siano date due funzioni $f : Y → R$, $g : X → Y$ . Sia $c ∈ D(X)$ e si supponga che $lim_{x→c} g(x)= γ$ e che $γ ∈ D(Y)$ . Allora, se $lim_{y→γ} f (y) = l$, si ha, posto $F (x) = f (g(x))$, $lim_{x→c} F (x) = l$
   ![[Pasted image 20250809124620.png]](scrittura semplice semplice)

6) **TEOREMA PONTE**
   Sia data una funzione $f : X → R$ e sia $c ∈ D(X)$. Si ha $lim_{x→c} f (x) = l$ (risp. $+∞$, $−∞$) se e solo se per ogni successione $\{x_n\}$ di elementi di $X$ convergente a $c$ si ha $f (x_n) → l$

**Limiti sinistro e destro**
Sia data una funzione $f : (a, b) → R$. Per ogni $c ∈]a, b]$ il limite della restrizione di $f$ ad $(a, c[$ al tendere di $x$ a $c$ si chiama limite sinistro di $f$ al tendere di $x$ a $c$, o limite per $x$ che tende a $c$ da sinistra, e si indica con $lim_{x→c^−} f (x)$. Per ogni $c ∈ [a, b[$ il limite della restrizione di $f$ a $]c, b)$ al tendere di $x$ a $c$ si chiama limite destro di $f$ al tendere di $x$ a $c$, o limite per $x$ che tende a $c$ da destra, e si indica con $lim_{x→c^+} f (x)$.

**Limite al tendere di $x$ all’infinito**
Data una funzione $f : (a, +∞[→ R$, si definisce il limite di $f$ al tendere di $x$ a $+∞$ nel seguente modo:
$\lim_{x \to +\infty} f(x) = l \in \mathbb{R} \ \text{ se } \ \forall \varepsilon > 0 \ \exists \bar{x} > a : x > \bar{x} \Rightarrow |f(x) - l| < \varepsilon$
$\lim_{x \to +\infty} f(x) = +\infty \ \text{ se } \ \forall k > 0 \ \exists \bar{x} > a : x > \bar{x} \Rightarrow f(x) > k$
$\lim_{x \to +\infty} f(x) = -\infty \ \text{ se } \ \forall k > 0 \ \exists \bar{x} > a : x > \bar{x} \Rightarrow f(x) < -k$


**Limiti di funzioni elementari**
Premettiamo che (la proveremo in seguito) vale la seguente 
**PROPOSIZIONE** 
Se $f : X → R$ è una funzione elementare, per ogni $c ∈ X$ si ha $lim_{x→c} f (x) = f (c)$

**Nel seguito, tratteremo alcuni casi che non rientrano in tale condizione.**

1) **Funzione esponenziale**
   Sia $a$ un numero positivo e diverso da $1$. Consideriamo la funzione $a^x$. Per studiare il suo limite al tendere di $x$ a $±∞$ si deve distinguere se $a > 1$ oppure $0 < a < 1$. Si ha, utilizzando i risultati analoghi visti per le successioni e il Teorema ponte: 
   i) $a > 1 ⇒ lim_{x→+∞} a^x = +∞; lim_{x→−∞} a^x = 0$ 
   ii)$0 < a < 1 ⇒ lim_{x→+∞} a^x = 0; lim_{x→−∞} a^x = +∞$

2) **Funzione logaritmo**
   Sia a un numero positivo e diverso da $1$. Consideriamo la funzione $log_a\,\,\, x$. Per studiare il suo limite al tendere di $x$ a $0$ o a $+∞$ si deve distinguere se $a > 1$ oppure $0 < a < 1$. Si ha, utilizzando i risultati analoghi visti per le successioni e il Teorema ponte:
   i) $a > 1 ⇒ lim_{x→+∞} log_a\,\,\, x = +∞; lim_{x→0} log_a\,\,\, x = −∞$ 
   ii) $0 < a < 1 ⇒ lim_{x→+∞} log_a\,\,\, x = −∞; lim_{x→0} log_a\,\,\, x = +∞$

3) **Funzione potenza** 
   Esaminiamo intanto il caso della potenza con esponente intero. La funzione potenza con esponente intero positivo è definita per ogni $x$, quella con esponente intero negativo è definita per $x \neq 0$
   Sia allora $n ∈ R$:
   si ha facilmente: 
   $lim_{x→+∞} x^n = +∞$ 
   $lim_{x→−∞} x^n = +∞$ se $n$ è pari 
   $lim_{x→−∞} x^n = −∞$ se n è dispari.
   
   Si ha poi, tenendo presente che $x^{-n}=\frac{1}{}x^n$:
   se n è pari, $lim_{x→±∞} x^{−n} = 0$, $lim_{x→0} x^{−n} = +∞$
   se n è dispari, $lim_{x→±∞} x^{−n} = 0$, $lim_{x→0^−} x^{−n} = −∞$, $lim_{x→0^+} x^{−n} = +∞$

   Se l’esponente è un numero $α$ non intero:
   - Se **α > 0** e non è intero → possiamo calcolare $x^α$ solo se **x ≥ 0**
   - Se **α < 0** e non è intero → possiamo calcolare $x^α$ solo se **x > 0** (perché con α negativo serve anche che x non sia zero, altrimenti si divide per 0
   
4) **Polinomi** 
   Consideriamo il polinomio $f (x) = a_0x^n + a_1x^{n−1} + · · · + a_n$
   La funzione potrebbe trovarsi nella forma indeterminata $+∞ − ∞$ e si procede nel seguente modo. $f (x) = x^n(a_0 + \frac{a_1}{x} + · · · + \frac{a_n}{x^n} )$
   (in pratica come nelle successioni devo raccogliere la $x$, $\frac{a}{x}$ anche qui tende a $0$)
   Ne segue quindi:
   ![[Pasted image 20250813164602.png]]
   In sostanza, possiamo concludere che, al tendere di $x$ a $±∞$, i polinomi divergono sempre, per capire il segno della divergenza occorre esaminare il grado di $x^n$ e il segno del suo coefficiente.
   
5) **Funzioni razionali fratte**
   Consideriamo la funzione $f(x)= \frac{a_0 x^n + a_1 x^{n-1} + \dots + a_n}{b_0 x^m + b_1 x^{m-1} + \dots + b_m}$
   Supporremo che il numeratore e il denominatore non abbiano divisori a comune
   Per $x → ±∞$ la funzione si presenta nella forma indeterminata $\frac{∞ }{∞ }$ e si procede nel seguente modo:
- Se $n>m$ (sono gli esponenti)
      Per determinare il segno corretto, si considera il rapporto dei termini di grado massimo:
     ![[Pasted image 20250813165729.png]]
     ![[Pasted image 20250813165952.png]]
- Se $n=m$
  Il limite è dato dal rapporto dei coefficienti dei termini di grado massimo:
  ![[Pasted image 20250813170225.png]]
  ![[Pasted image 20250813170327.png]]
- Se $n<m$
  Qui si ha un numero sopra (che sia anche grande) che viene diviso per un numero che cresce molto di più quindi la frazione tende a $0$ (come nelle successioni)
  ![[Pasted image 20250813170621.png]]


**Alcuni limiti notevoli** 
Esaminiamo adesso alcuni limiti che **si presentano in forma indeterminata**.
1) **Limiti notevoli con funzioni trigonometriche**
   Consideriamo la funzione $f (x) = \frac{sen(x)}{x}$; essa è definita per $x\neq0$ e, per $x → 0$, si presenta nella forma indeterminata $\frac{0}{0}$ 
   Utilizzando il limite notevole studiato per le successioni, si ottiene che
   ![[Pasted image 20250813170959.png]]
   (semplicemente quando $x$ tende a $0$ il valore di $x$ e del seno di $x$ sono praticamente identici quindi sarebbe come fare $\frac{x}{x}$ e quindi $1$)
   E analogamente si hanno i seguenti altri limiti notevoli:
   ![[Pasted image 20250813171423.png]]
2) **Limiti notevoli di tipo esponenziale**
   Utilizzando i limiti visti per le successioni, si ottengono i seguenti limiti notevoli (osserviamo che si presentano tutti in forma indeterminata $1^∞$):
   ![[Pasted image 20250813171718.png]]


**Confronto fra infinitesimi e fra infiniti**
Una funzione che tende a zero è detta infinitesima (o ”un infinitesimo”), una funzione che diverge è detta infinitamente grande (o ”un infinito”).

**Asintoti**
