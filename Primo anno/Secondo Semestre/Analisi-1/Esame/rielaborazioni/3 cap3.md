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
Un asintoto per $f$ è una retta $r$ tale che la distanza del generico punto del grafico di $f$ da $r$ tenda a zero.
Ne esistono di 3 tipi:
- **Asintoto orizzontale** → è una retta orizzontale $y=k$ verso cui la funzione si avvicina quando $x$ va verso $+∞$ o $−∞$ 
    Immaginalo come il “livello” che la curva raggiunge e poi non supera andando lontano a destra o a sinistra.
    
- **Asintoto verticale** → è una retta verticale $x=h$ che il grafico non può attraversare e vicino alla quale la funzione “spara” verso $+∞$ o $−∞$  
    Qui la curva si avvicina moltissimo a una linea verticale, ma senza toccarla, e nel farlo la funzione cresce o decresce senza limiti.
    
- **Asintoto obliquo** → è una retta inclinata $y=mx+q$ verso cui il grafico si avvicina per $x→±∞$ quando non c’è un asintoto orizzontale.  
    Qui la curva segue un “pendio” inclinato, come se corresse parallelamente a una diagonale sempre più da vicino.


![[Pasted image 20250814105324.png]]


**Limiti delle funzioni monotone**
Una funzione è monotona se in un intervallo $(a,b)$ la funzione è crescente o decrescente (anche strettamente).
**TEOREMA SUI LIMITI DELLE FUNZIONI MONOTONE**
Sia $f : (a, b) → R$ una funzione strettamente crescente in $(a, b)$. Allora: 
- per ogni $c ∈]a, b[$ esistono i limiti destro e sinistro di $f$ al tendere di $x$ a $c$ e si ha:
  $l^-=lim_{x\to c^-} f(x)= sup_{(a,c]}f(x)≤f(c)≤l^+=lim_{x\to c^+} f(x)=inf_{]c,b)} f(x)$
  ![[Pasted image 20250815145708.png]]

- esistono i limiti di $f$ al tendere di $x$ ad $a$ e a $b$ e si ha:
  $l^+ = lim_{x→a} f (x) = inf_{]a,b)} f (x)$
  $l^− = lim_{x→b} f (x) = sup_{(a,b[} f (x)$
  (nell'immagine sopra sarebbero dove la $x$ vale $-2$ e $+2$)

**OSSERVAZIONI**
1) Se $a$, $b$ appartengono all’insieme di definizione, si ha $l^+ ≥ f (a)$; $l^− ≤ f (b)$
2) Se $f$ è decrescente, si ha $l^− = lim_{x→c^−} f (x) = inf_{(a,c[} f (x) ≥ f (c) ≥ l^+ = lim_{x→c^+} f (x) = sup_{]c,b)} f (x)$

**Funzioni continue**
Sia data una funzione $f : X → R$ e sia $c$ un punto non isolato di $X$. Si dice che la funzione $f$ è continua in $c$ se $lim_{x→c} f (x) = f (c)$. Si dice che $f$ è continua in $X$ se è continua in ogni punto di $X$. Dai risultati visti nel capitolo precedente si vede subito che somma, prodotto, quoziente di funzioni continue sono continue, e che una funzione composta mediante funzioni continue è continua.

Nel seguito, esporremo due importanti proprietà delle funzioni continue in un intervallo. La prima è espressa dal seguente risultato, del quale diamo solo l’enunciato

**TEOREMA DI WEIERSTRASS**
Sia $f$ una funzione reale continua in un intervallo chiuso e limitato $[a, b]$. Allora, $f$ ammette minimo e massimo assoluti

La seconda è la seguente proprietà dei valori intermedi. Si dice che una funzione $f : X → R$ gode della proprietà dei valori intermedi (brevemente, PVI), se, dati $α, β ∈ f (X)$, con $α < β$, per ogni $γ ∈]α, β[$ esiste $x ∈ X$ tale che $f (x) = γ$. In altre parole, se la funzione assume due valori assume anche tutti i valori fra essi compresi. La PVI è legata alla continuità mediante alcuni risultati che ora illustreremo.

**TEOREMA DI ESISTENZA DEGLI ZERI**
Sia $f$ una funzione reale continua in un intervallo chiuso e limitato $[a, b]$ e si supponga che $f (a) < 0$ e $f (b) > 0$ (o viceversa). Allora esiste $c ∈ [a, b]$ tale che $f (c) = 0$
**Dimostrazione**
Posto $x_0 = \frac{a+b}{2}$, se $f(x_0) = 0$ la tesi è dimostrata, se $f(x_0) < 0$ poniamo $[a_1, b_1] = [x_0, b]$, se $f(x_0) > 0$ poniamo $[a_1, b_1] = [a, x_0]$, si ha dunque $f(a_1) < 0$, $f(b_1) > 0$, $a \le a_1 \le b_1 \le b$, $b_1 - a_1 = \frac{b-a}{2}$.  
Procedendo analogamente a partire dall’intervallo $[a_1, b_1]$ e poi reiterando lo stesso ragionamento, se per un certo $n$ si trova $f(x_n) = 0$ la tesi è dimostrata, in caso contrario si determinano due successioni $\{a_n\}$ e $\{b_n\}$ tali che, per ogni $n \in \mathbb{N}$, si ha $f(a_n) < 0$, $f(b_n) > 0$, $a \le a_1 \le \dots \le a_n < b_n \le b_{n-1} \le \dots \le b$, $b_n - a_n = \frac{b-a}{2^n}$.  
La successione $\{a_n\}$ è crescente e limitata superiormente (da $b$), quindi converge al proprio estremo superiore $c \le b$. Si ha poi $b_n = b_{n-1} + a_n = \frac{b-a}{2^n} + a_n \to c$. Si ha allora, per la continuità di $f$, $f(a_n) \to f(c)$ e $f(b_n) \to f(c)$ ma da $f(a_n) < 0$ segue $f(c) \le 0$ e da $f(b_n) > 0$ segue $f(c) \ge 0$ quindi necessariamente $f(c) = 0$.


**TEOREMA DI ESISTENZA DEI VALORI INTERMEDI (o Teorema di Darboux)**
Sia $f$ una funzione reale continua in un intervallo chiuso e limitato $[a, b]$ e si supponga che $f (a)\neq f (b)$, ad esempio $f (a) < f (b)$. Allora, per ogni $γ ∈]f (a), f (b)[$ esiste $c ∈ [a, b]$ tale che $f (c) = γ$
**Dimostrazione**
Consideriamo in $[a, b]$ la funzione $g(x) = f (x) − γ$, che è continua e agli estremi dell’intervallo assume valori di segno diverso, quindi, per il Teorema di esistenza degli zeri, si annulla in un punto $c$: si ha dunque $f (c) − γ = 0$
**OSSERVAZIONI SUL TEOREMA DI DARBOUX**
1) Se l’intervallo non è chiuso e limitato la tesi vale egualmente: basta applicare il teorema ad una restrizione
2) Se $f$ non è definita in un intervallo il teorema non vale: basti pensare ad esempio ad una funzione definita nell’unione di due intervalli disgiunti, costante in ciascuno di essi, con valori diversi delle costanti
3) Il viceversa del teorema non vale: la funzione definita in $[0, 1]$ ponendo $f (x) = x$ in $]0, 1[$, $f (0) = 1$, $f (1) = 0$, verifica la PVI ma non è continua


**TEOREMA DI CONTINUITA' DELLE FUNZIONI MONOTONE**
$f : (a, b) → R$ una funzione strettamente monotona. Sia verificata la PVI. Allora, $f$ è continua

**Dimostrazione**
Supponiamo che $f$ sia crescente e proviamo la continuità, ad esempio, in un punto $c$ interno ad $(a,b)$. Dal teorema sui limiti delle funzioni monotone segue che $l^{-} \leq f(c) \leq l^{+}$. Per provare la continuità basta provare che $l^{-} = f(c) = l^{+}$. Supponiamo per assurdo che non sia vero, ad esempio si abbia $l^{-} < f(c)$. Sia $\gamma \in [l^{-}, f(c)[$; per la PVI esiste $\bar{x} \in (a,b)$ tale che $f(\bar{x}) = \gamma$. L'assurdo segue dal fatto che $\bar{x}$ non può esistere, infatti: 
- se fosse $\bar{x} = c$ si avrebbe $\gamma = f(\bar{x}) = f(c)$
- se fosse $\bar{x} < c$ si avrebbe $\gamma = f(\bar{x}) \leq l^{-}$ 
- se fosse $\bar{x} > c$ si avrebbe $\gamma = f(\bar{x}) > f(c)$ 
L’assurdo è dunque trovato

Fra le conseguenze di questi teoremi, vediamo le seguenti:
1) **Immagine di un intervallo mediante una funzione continua**
   Sia $f : [a, b] → R$ una funzione continua. Dal teorema di Darboux segue che la sua immagine è un intervallo, e dal teorema di Weierstrass segue che $f$ possiede minimo $m$ e massimo $M$ , quindi la sua immagine è l’intervallo chiuso e limitato $[m, M ]$. Se, in particolare, $f$ è crescente, la sua immagine è l’intervallo $[f (a), f (b)]$; se $f$ è decrescente, la sua immagine è l’intervallo $[f (b), f (a)]$. In generale, se $f$ è una funzione continua in un intervallo generico $(a, b)$, la sua immagine è l’intervallo $(inf_{(a,b)} f (x), sup_{(a,b)} f (x))$. In particolare, ricordando il teorema sui limiti delle funzioni monotone, se $f$ è crescente in $(a, b)$ la sua immagine è l’intervallo $(lim_{x→a} f (x), lim_{x→b} f (x))$; se $f$ è decrescente in $(a, b)$ la sua immagine è l’intervallo $(lim_{x→b} f (x), lim_{x→a} f (x))$.

2) **Continuità della funzione inversa.**
   Sia $f : [a, b] → [f (a), f (b)]$ una funzione strettamente crescente (oppure $f : [a, b] → [f (b), f (a)]$ una funzione strettamente decrescente) e continua. Allora, la sua funzione inversa è continua.

3) **Continuità delle funzioni elementari**
   Tutte le funzioni elementari che abbiamo introdotto sono continue nei rispettivi insiemi di definizione. Sia infatti $c$ un punto dell’insieme di definizione di $f$ . Se $c$ è contenuto in un intervallo in cui $f$ è monotona, la continuità in $c$ segue dal teorema di continuità delle funzioni monotone. In caso contrario, si verifica che i limiti sinistro e destro coincidono. Ad esempio, $lim_{x→0^−} x^2 = inf_{]−∞,0[} x^2 = 0 = lim_{x→0^+} x^2 = inf_{]0,+∞[} x^2$ 

**Punti di discontinuità**
Data una funzione $f : X → R$, un punto $c ∈ D(X)$ è detto punto di discontinuità per $f$ in uno dei seguenti casi: 
- se $f$ non è definita in $c$: ad esempio, $f (x) = log \,\,\,x, c = 0$
- se $f$ non è dotata di limite al tendere di $x$ a $c$: ad esempio, $f (x) = \frac{|x|}{x}$ , $c = 0$ 
- se $lim_{x → c} f (x) \neq f (c)$: ad esempio, $f (x) = x$ per $x \neq 0$, $f (0) = 5$, $c = 0$

Sia $c$ un punto di discontinuità
![[Pasted image 20250816114503.png]]




   