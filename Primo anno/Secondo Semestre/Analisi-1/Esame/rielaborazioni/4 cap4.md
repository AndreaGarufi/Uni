Calcolo differenziale per le funzioni reali di una variabile reale. Derivata di una funzione in un punto. Derivate di ordine superiore. Approssimazione di una funzione derivabile mediante un polinomio. Interpretazione geometrica della derivata. Derivate sinistra e destra, punti di non derivabilità e loro classificazione. Regole di derivazione. Enunciati dei teoremi sulla derivata di una funzione composta e di una funzione inversa. Derivate delle funzioni elementari. Teoremi di Fermat, di Rolle, di Lagrange. Enunciato del teorema di prolungamento della derivata. Teorema sulle funzioni con derivata identicamente nulla. Criterio di monotonia e di stretta monotonia per funzioni derivabili. Studio dei punti stazionari. Metodo per la ricerca degli estremi assoluti. Funzioni localmente convesse e punti di flesso. Enunciato del Teorema di de l’Hộpital

**CALCOLO DIFFERENZIALE PER LE FUNZIONI REALI DI UNA VARIABILE REALE**

Nel cap. 1 abbiamo definito il rapporto incrementale di f relativo al punto c, nelle due forme
![[Pasted image 20250825175017.png]]

**DEFINIZIONE**. Si dice che $f$ è derivabile nel punto $c$ se il limite del rapporto incrementale ($lim_{x→c} r(x)$ oppure $lim_{h→0} R(h)$) esiste ed è finito; in questo caso, tale limite è detto derivata (o derivata prima) di $f$ in $c$ e si denota con $f ′(c)$.
Si dice che $f$ è derivabile in $(a, b)$ se lo è in ogni punto, in tal caso, si definisce una funzione $f ′ : (a, b) → R$ che ad ogni punto $x ∈ (a, b)$ associa la derivata di $f$ in $x$. Se la funzione $f$ è a sua volta derivabile in $c$, la sua derivata è detta derivata seconda di $f$ in $c$ e si denota con $f ′′(c)$, se ciò accade in ogni punto di $(a, b)$ viene definita la funzione derivata seconda $f ′′ : (a, b) → R$ e, procedendo analogamente, si possono definire le derivate di ordine superiore $f ′′′, f^{IV} , · · · , f^{(n)}, · · ·$
Se il punto $c$ è interno all’intervallo $(a, b)$, è possibile calcolare, ove occorra, i limiti sinistro e destro del rapporto incrementale: se esistono finiti, essi vengono chiamati rispettivamente derivata sinistra $(f ′ _−(c))$ e derivata destra $(f ′_+(c))$; evidentemente, $f$ è derivabile in $c$ se e solo se $f ′_−(c) = f ′_+(c)$. Se l’intervallo è chiuso, è possibile prendere in considerazione la derivata anche nei punti $a$ e $b$: evidentemente, la derivata nel punto $a$ è una derivata destra, la derivata nel punto $b$ è una derivata sinistra. Il primo risultato che presentiamo mette in relazione la derivabilità e la continuità

**TEOREMA**
Se $f$ è derivabile in $c$, allora è continua in $c$.
**Dimostrazione**
Si ha $f (x) = f (x) − f (c) + f (c) = \frac{f(x)-f(c)}{x-c}\dot (x-c)+f(c)$ e questa quantità, al tendere di $x$ a $c$, converge a $f ′(c) · 0 + f (c) = f (c)$.

Il viceversa non vale, consideriamo i due seguenti esempi. 
1) $f (x) = \sqrt{x}$, $c = 0$. Il rapporto incrementale $r(x) = \frac{1}{\sqrt{x}}$ diverge al tendere di $x$ a $0$. 
2) $f (x) = |x|$, $c = 0$. Il rapporto incrementale $r(x) = \frac{|x|}{x}$ vale $1$ per $x > 0$ e $−1$ per $x < 0$ quindi tende ad $1$ al tendere di $x$ a $0$ da destra e a $−1$ al tendere di $x$ a $0$ da sinistra. 
Le funzioni presentate nei precedenti esempi sono continue nel punto $c = 0$ ma non sono derivabili in tale punto

Il seguente risultato prova che una funzione è derivabile nel punto c se e solo se è possibile approssimarla, in un intorno di c, con un polinomio di primo grado
**TEOREMA**
$f$ è derivabile in $c$ se e solo se esiste un polinomio di primo grado $p$ tale che $p(c) = f (c)$ e che $lim_{x→c} \frac{f(x)-p(x)}{x-c}=0$ 
OSSERVAZIONE. La condizione $lim_{x→c} \frac{f(x)-p(x)}{x-c}=0$ significa che la differenza $f (x) − p(x)$ è un infinitesimo di ordine superiore rispetto a $x − c$, quindi, al tendere di $x$ a $c$, è trascurabile: dunque, $f$ si può approssimare con il polinomio $p$
**Dimostrazione**
![[Pasted image 20250826093541.png]]

**Regole di derivazione.**
In questo paragrafo vengono presentate le regole per derivare funzioni ottenute mediante operazioni fra funzioni derivabili
1) **Combinazione lineare.** Siano $f, g$ derivabili in un punto $c$ e $h, k ∈ R$. Indicata con $F$ la combinazione lineare $F (x) = hf (x) + kg(x)$, la funzione $F$ è derivabile nel punto $c$ e si ha $F ′(c) = hf ′(c) + kg′(c)$. Infatti, come si vede facilmente, il rapporto incrementale di $F$ è la combinazione lineare dei rapporti incrementali di $f$ e di $g$ mediante le stesse costanti $h$ e $k$
2) **Prodotto**. Siano $f$, $g$ derivabili in un punto $c$. Indicata con p la funzione prodotto $p(x) = f (x)g(x)$, la funzione $p$ è derivabile nel punto $c$ e si ha $p′(c) = f (c)g′(c) + f ′(c)g(c)$
3) **Reciproco**. Sia $f$ derivabile in un punto $c$ e tale che $f (c)\neq 0$. Indicata con $F$ la funzione reciproca $F (x) =\frac{1}{f(x)}$ , la funzione $F$ è derivabile nel punto $c$ e si ha $F ′(c) =\frac{-f ′(c)}{(f(c))^2}$
4) **Quoziente**. Siano $f, g$ derivabili in un punto $c$, e si abbia $g(c) \neq 0$. Indicata con $q$ la funzione quoziente $q(x) = \frac{f (x)}{g(x)}$ , la funzione $q$ è derivabile nel punto $c$ e si ha $q′(c) = \frac{ f′(c)g(c)−f (c)g′(c)}{(g(x))^2}$
5) **Funzione composta**. Siano date due funzioni $f : (α, β) → R$ e $g : (a, b) → (α, β)$. Sia $c ∈ (a, b)$ e supponiamo che $g$ sia derivabile nel punto $c$ e che $f$ sia derivabile nel punto $g(c) ∈ (α, β)$. Indicata con $F$ la funzione composta $F (x) = f (g(x))$, la funzione $F$ è derivabile nel punto $c$ e si ha $F ′(c) = f ′(g(c)) g′(c)$
6) Funzione inversa. Sia $f : [a, b] → R$ una funzione strettamente crescente e continua, sappiamo allora che essa è invertibile e la sua inversa è $f^{-1} : [f (a), f (b)] → [a, b]$ ed è anch’essa strettamente crescente e continua (valgono considerazioni analoghe nel caso in cui $f$ sia strettamente decrescente). Sia $γ ∈ [f (a), f (b)]$, vogliamo sapere se $f^{-1}$ sia derivabile in $γ$. Sia $c ∈ [a, b]$ tale che $γ = f (c)$, si supponga che $f ′(c)\neq 0$, allora si può dimostrare che $f^{-1}$ è derivabile in $γ$ e $(f^{−1})′(γ) = \frac{1}{f ′(c)}$

**Derivate delle funzioni elementari**
In questo paragrafo presentiamo le formule che permettono di derivare le funzioni elementari presentate nel cap. 1
1) **Funzione costante** Se $f (x) = k\,\,\, ∀x ∈ R$, il suo rapporto incrementale è nullo quindi $f ′(x) = 0\,\,\, ∀x ∈ R$.
2) **Funzione potenza con esponente intero** Sia $f (x) = x^n$. Si ha $f ′(x) = nx^{n−1} ∀x ∈ R$. Lo proviamo solo nel caso $n = 2$. Il rapporto incrementale è $r(x) = \frac{x^2-c^2}{x-c} = x + c$ il cui limite al tendere di $x$ a $c$ è $2c$
3) **Funzione valore assoluto** Non è derivabile se $x= 0$ mentre se $x<0$ allora $f'(x)=-1$ se $x>0$ allora $f'(x)=+1$ 
4) **Funzione esponenziale** Se $f (x) = a^x$, si ha $f ′(x) = a^x \,\,\,log\,\,\, a\,\,\, ∀x ∈ R$ 
5) **Logaritmo** Se $log\,\,\,a^x$ allora si ha $\frac{1}{x}log_a\,\,\,e$ per ogni $x>0$ 
6) **Potenza con esponente qualunque** Stessa formula per esponenti interi ovvero $ax^{a-1}$ ma per esponenti reali non interi (numeri con la virgola) bisogna che $x>0$ mentre se l'esponente è compreso tra $0$ e $1$ allora la funzione non è derivabile in $x=0$ 
7) **Funzioni trigonometriche**
   ![[Pasted image 20250826154513.png]]
8) **Funzioni inverese delle funzioni trigonometriche**
   ![[Pasted image 20250826154652.png]]

**Teoremi sul calcolo differenziale e loro applicazioni allo studio delle funzioni**
Il primo risultato che presentiamo è legato al Teorema di pag. 13 del cap. 1, secondo il quale la funzione è crescente (decrescente) in $c$ se e solo se $r(x) > 0$ ($r(x) < 0$) in un intorno di $c$. Se $f ′(c) > 0$ ($f ′(c) < 0$), allora, per il teorema della permanenza del segno si avrà $r(x) > 0$ ($r(x) < 0$) in un intorno di $c$. Ne segue:

**TEOREMA**
