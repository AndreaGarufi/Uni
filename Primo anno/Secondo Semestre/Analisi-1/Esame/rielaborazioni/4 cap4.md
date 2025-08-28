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
8) **Funzioni inverse delle funzioni trigonometriche**
   ![[Pasted image 20250826154652.png]]

**Teoremi sul calcolo differenziale e loro applicazioni allo studio delle funzioni**
Il primo risultato che presentiamo è legato al Teorema di pag. 13 del cap. 1(appunti prof), secondo il quale la funzione è crescente (decrescente) in $c$ se e solo se $r(x) > 0$ ($r(x) < 0$) in un intorno di $c$. Se $f ′(c) > 0$ ($f ′(c) < 0$), allora, per il teorema della permanenza del segno si avrà $r(x) > 0$ ($r(x) < 0$) in un intorno di $c$. Ne segue:

**TEOREMA 1 (di monotonia locale)** 
Se $f ′(c) > 0$ ($risp. f ′(c) < 0$) allora $f$ è crescente (risp. è decrescente) nel punto $c$

Il viceversa non è vero, ad esempio la funzione $f (x) = x^3$ è crescente nel punto $c = 0$ ma $f ′(0) = 0$. Possiamo solo affermare che, se $f$ è crescente (decrescente) in $c$, allora $f ′(c) ≥ 0$ ($f ′(c) ≤ 0$)

Per avere dei risultati più raffinati, occorre presentare alcuni importanti teoremi

**TEOREMA DI FERMAT**
Data una funzione $f : (a, b) → R$, sia $c ∈]a, b[$ un punto di minimo o di massimo relativo per $f$ . Si supponga che $f$ sia derivabile nel punto $c$. Allora, si ha $f ′(c) = 0$
**Dimostrazione**
Dato che il punto $c$ è interno, la derivata è il limite del rapporto incrementale sia da sinistra che da destra. Ora, il numeratore del rapporto incrementale in un intorno di $c$ ha sempre lo stesso segno (ad esempio, se $c$ è un punto di minimo relativo, si ha $f (x)−f (c) ≥ 0$ in un intorno di $c$) mentre il denominatore è negativo a sinistra di $c$ e positivo a destra. Ne segue che $f ′(c) = f ′_−(c) = lim_{x→c^−}\,\,\, r(x) ≤ 0$ e, contemporaneamente, $f ′(c) = f ′_+(c) = lim_{x→c^+}\,\,\, r(x) ≥ 0$ quindi necessariamente $f ′(c) = 0$
(L’unico numero che è **≤ 0** e **≥ 0** insieme è **0**. Dunque $f′(c)=0$)

Il viceversa del teorema non vale

**TEOREMA DI ROLLE**
Sia $f$ una funzione reale continua nell’intervallo chiuso $[a, b]$ e derivabile in $]a, b[$, tale che $f (a) = f (b)$. Allora, esiste $c ∈]a, b[$ tale che $f ′(c) = 0$
**Dimostrazione**
Per il teorema di Weierstrass $f$ è dotata di minimo e massimo assoluti, siano $x_1$ il punto di minimo assoluto e $x_2$ il punto di massimo assoluto. Se $x_1 = a$ e $x_2 = b$, o viceversa, allora il minimo e il massimo assoluti della funzione sono uguali quindi $f$ è costante e la sua derivata è ovunque nulla. In caso contrario, uno dei due punti $x_1$, $x_2$ è interno, in esso allora la derivata è nulla per il teorema di Fermat

**TEOREMA DI LAGRANGE**
**Dimostrazione**
Consideriamo in $[a, b]$ la funzione $g(x) = (f (b) − f (a))x + (a − b)f (x)$. Si vede facilmente che essa verifica le ipotesi del teorema di Rolle, quindi esiste $c ∈]a, b[$ tale che $g′(c) = 0$. Dal fatto che $g′(x) = f (b) − f (a) + (a − b)f ′(x)$ segue subito la tesi.

**COROLLARI DEL TEOREMA DI LAGRANGE**
A) *Teorema di prolungamento della derivata*. Sia data una funzione $f : (a, b) → R$ e sia $c ∈ (a, b)$. Supponiamo che $f$ sia derivabile in $(a, b) \ {c}$ e che sia continua in $c$. Supponiamo inoltre che esista il $lim_{x→c} f ′(x)$, sia esso $l$ (può essere un numero oppure $±∞$). Allora, si ha $lim_{x→c} r(x) = l$
**OSSERVAZIONE** Dal teorema appena enunciato segue che le funzioni $arcsin (x)$ e $arccos (x)$ non sono derivabili in $−1$ e $1$, infatti sono continue ma le loro derivate divergono al tendere di $x$ a tali punti
B) *Criterio di monotonia*. Sia data una funzione $f : (a, b) → R$ derivabile. Condizione sufficiente affinché $f$ sia crescente in $(a, b)$ è che $f ′(x) ≥ 0 ∀x ∈ (a, b)$. 
**Dimostrazione** Siano $x, y ∈ (a, b)$, con $x < y$. Applicando il Teorema di Lagrange ad $f$ nell’intervallo $[x, y]$, si ottiene che esiste $c ∈]x, y[$ tale che $f (y) − f (x) = (y − x)f ′(c) ≥ 0$, da cui la tesi
Dal teorema B) segue subito che, se $f ′(x) > 0$ per ogni $x ∈ (a, b)$, allora $f$ è strettamente crescente in $(a, b)$. Questa condizione è comunque troppo restrittiva, basti pensare che la funzione $f (x) = x^3$ non la verifica pur essendo strettamente crescente. Si ha tuttavia il seguente risultato più generale, del quale non diamo la dimostrazione.
C) *Criterio di stretta monotonia.* Sia data una funzione $f : (a, b) → R$ derivabile. Condizione necessaria e sufficiente affinché $f$ sia strettamente crescente in $(a, b)$ è che $f ′(x) ≥ 0 ∀x ∈ (a, b)$ e che non esista nessun intervallo $(c, d) ⊆ (a, b)$ tale che $f ′(x) = 0 ∀x ∈ (c, d)$.
D) *Teorema sulle funzioni con derivata nulla.*
Sia data una funzione $f : (a, b) → R$ derivabile, tale che $f ′(x) = 0 ∀x ∈ (a, b)$. Allora, $f$ è costante in $(a, b)$
**Dimostrazione**
Siano $x$, $y$ due punti generici di $(a, b)$, con $x < y$. Applicando il Teorema di Lagrange ad $f$ nell’intervallo $[x, y]$ (le ipotesi sono verificate in quanto $f$ è derivabile in $(a, b)$) si ottiene l’esistenza di $c ∈]x, y[$ tale che $f (y) − f (x) = f ′(c)(y − x) = 0$, quindi $f (x) = f (y)$ e, dato che $x$ e $y$ sono arbitrari, ne segue la tesi.

**Metodo per lo studio dei punti stazionari**
Sia $f$ una funzione derivabile in $(a, b)$ e sia $c ∈ (a, b)$ tale che $f ′(c) = 0$. Dai risultati precedenti (T. Fermat) segue che $c$ può essere un punto di estremo relativo. Tenendo presenti i criteri di monotonia visti prima, segue che:
1) Se $f ′(x) < 0$ in un intorno sinistro di $c$ e $f ′(x) > 0$ in un intorno destro di $c$, allora $c$ è un punto di minimo relativo per $f$ 
2) Se $f ′(x) > 0$ in un intorno sinistro di $c$ e $f ′(x) < 0$ in un intorno destro di $c$, allora $c$ è un punto di massimo relativo per $f$

In pratica, un punto stazionario $c$ è un punto di estremo relativo per $f$ se in corrispondenza di $c$ la derivata cambia segno
Se esiste la derivata seconda in $c$, possiamo raffinare lo studio anche utilizzando il segno della derivata seconda, precisamente si ha: 
3) se $f ′′(c) > 0$, allora $c$ è un punto di minimo relativo per $f$ 
4) se $f ′′(c) < 0$, allora $c$ è un punto di massimo relativo per $f$

	In definitiva: se $f ′(c)\neq 0$, la funzione $f$ è crescente o decrescente nel punto $c$; se $f ′(c) = 0$ e $f ′′(c)\neq 0$, $c$ è un punto di estremo relativo per $f$


**Metodo per la ricerca degli estremi assoluti**
Sia $f$ una funzione reale continua in $[a, b]$, il teorema di Weierstrass assicura l’esistenza degli estremi assoluti. Per individuarli, occorre determinare i seguenti insiemi:
![[Pasted image 20250828121457.png]]
in quanto, se un punto di estremo assoluto appartiene all’interno di $[a, b]$, in tale punto la derivata, se esiste, è nulla per il teorema di Fermat: pertanto, i punti di estremo assoluto andranno cercati o all’interno dell’intervallo, e in tal caso la derivata o non esiste oppure esiste e vale zero, oppure agli estremi dell’intervallo. Un volta determinati i tre insiemi $A$, $B$, $C$, basta calcolare i valori della funzione in tutti i punti di tali insiemi per trovare il minimo e il massimo

**Funzioni localmente convesse**
Sia $f : (a, b) → R$ una funzione derivabile e sia c ∈ (a, b), ricordiamo che l’equazione della tangente al grafico di $f$ nel punto di ascissa $c$ è $y = f (c) + f ′(c)(x − c)$. La tangente divide il piano in due semipiani, chiamiamo semipiano superiore l’insieme $\bar{S}= {(x, y) ∈ R^2 : y ≥ f (c) + f ′(c)(x − c)}$, analogamente si definisce il semipiano inferiore che indicheremo con $\underline{S}$. Si dice che la funzione $f$ è convessa nel punto $c$ se esiste $r > 0$ tale che, se $x ∈]c − r, c + r[$ si ha $f (x) ≥ f (c) + f ′(c)(x − c)$, ossia se per tutti i punti di un opportuno intorno di $c$ il corrispondente punto del grafico appartiene a $\bar{S}$. In modo simile si definisce $f$ concava nel punto $c$ se per tutti i punti di un opportuno intorno di $c$ il corrispondente punto del grafico appartiene a $\underline{S}$ 
![[Pasted image 20250828123409.png]]
(non per forza deve essere una parabola questo è solo un esempio)

Se $f$ in $c$ non è né convessa né concava, si dice che $c$ è un punto di flesso per $f$
(Un **punto di flesso** è un punto in cui la funzione passa da **convessa a concava** (o viceversa)

hanno particolare