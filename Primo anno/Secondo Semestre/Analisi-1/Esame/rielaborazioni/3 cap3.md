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

   