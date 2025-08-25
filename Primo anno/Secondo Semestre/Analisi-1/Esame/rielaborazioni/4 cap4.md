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
