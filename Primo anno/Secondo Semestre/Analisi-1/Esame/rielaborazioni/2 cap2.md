**ARGOMENTI**
Successioni di numeri reali. Proprietà verificate definitivamente. Successioni regolari e relativi teoremi. Teoremi di confronto. Operazioni con i limiti. Forme indeterminate. Limiti di successioni espresse mediante funzioni elementari. Il numero e. Limiti notevoli. Successioni monotone e loro limiti. Successioni estratte. Successioni definite per ricorrenza. Confronto fra infinitesimi e fra infiniti.

**Successioni di numeri reali**

**Prime definizioni**
Una successione di numeri reali è una funzione reale definita in $N$, $f: N→R$. Se $n∈N$, si usa la notazione $a_n = f(n)$, in tal modo la successione viene identificata con l'insieme dei suoi elementi: $\{a_n\}$. L'elemento generico $a_n$ viene detto elemento di posto (o indice) $n$. **Si dice che la successione verifica *definitivamente* (in seguito detto D) una condizione $P$ se esiste $α∈N$ tale che, per ogni $n>α$, l'elemento $a_n$ verifica $P$**. Ad esempio, la successione $\{n-4\}$ è **definitivamente** positiva. E' logico il fatto che se abbiamo 2 condizioni una che vale per $n>α$ e una per $n>β$ allora quando $n>max(α,β)$ valgono entrambe. **Una successione è detta limitata se lo è l'insieme dei suoi termini**, ovvero se esistono $h,k∈R$ tali che $h≤a_n≤k$ per ogni $n∈N$, si ha quindi $\{a_n\{⊆[h,k]$. I concetti di minimo e massimo estremo superiore e inferiore coincidono con quelli relativi all'insieme dei suoi termini. Ad esempio nella successione $\{n-1\}$ il minimo è $a_1= 1-1 =0$. 

**Proposizione**
Una successione **D** limitata è limitata (cioè: Se una successione è limitata **dopo un certo punto**allora è limitata **in generale**.)
**Dimostrazione**: Se si ha $h≤a_n≤k$ per ogni $n>α$, posto $h'=min\{h,a_1 ... a_α\}$, $k'=max\{k,a_1 ... a_α\}$, si ha $h'≤a_n≤k'$ per ogni $n∈N$.

(Spiegazione della dimostrazione:
abbiamo la nostra successione $a_n$ , sappiamo che è D limitata quindi ad un certo punto $α$ per qualsiasi $n>α$ la successione è limitata tra $h$ e $k$ (ma magari prima di $α$ i valori sono più grandi o più piccoli) per sistemare tutto prendiamo: $h'=min\{h,a_1 ... a_α\}$ e $k'=max\{k,a_1 ... a_α\}$ cosi creiamo un intervallo ancora più grande che contiene tutta la successione questa volta)

**Successioni regolari**
Introduciamo il concetto di **limite di una successione**.
1) Sia $l$ un numero reale. Si dice che la successione $\{a_n\}$ *converge* o *tende* ad $l$ o che $l$ è il limite della successione e si scrive $a_n→l$ o $lim\,\,\,\,a_n=l$  se è verificata la seguente condizione:
   $∀ε>0 \,\,\,\,∃α∈N:n>α⇒|a_n-l|<ε$ 

	ovvero se dato un qualunque intorno di $l$, **D** i termini della successione appartengono a tale intorno: se $n>α$ si ha $|a_n-l|<ε⇐⇒ -ε<a_n-l<ε⇐⇒l-ε<a_n<l+ε$ 
	Ad esempio, si verifica facilmente che una successione costante $a_n=k$ tende a $k;$ $\frac{1}{n}\,\,→0$ 
	Si ha un risultato fondamentale, che è basato sulla seguente proprietà di $R$: dati 2 numeri reali distinti $a,b$ esistono un intorno di $a$ un intorno di $b$ disgiunti
	
	( ✅ Cosa vuol dire che una successione ha limite $l$?
	Vuol dire che, **più vai avanti nella successione**, **più i suoi termini si avvicinano a un numero fisso $l$**.)
	
	**TEOREMA DELL’UNICITA' DEL LIMITE**
	 Se una successione converge, il suo limite è unico (è ovvio che possa tendere ad un solo numero)
	 **Dimostrazione**
	 **Supponiamo per assurdo** che $a_n → l$ e $a_n → L$, con, ad esempio, $l < L$. Scelto $ε$ tale che $0 < ε < \frac{L-l}{2}$ , **D** si ha $a_n < l+ε < L−ε < a_n$, che è un assurdo.
	
	**TEOREMA DELLA PERMANENZA DEL SEGNO**
	Se $a_n→l$ con $l>0$ allora **D** $a_n>0$, se $l<0$ allora **D** $a_n>0$
	**Dimostrazione**
	Supponiamo $l > 0$. Scelto $ε$ tale che $0 < ε < l$, **D** si ha $0 < l − ε < a_n$. Il caso $l < 0$ si prova in modo simile. Generalizzando questo risultato, possiamo affermare che se $a_n → l$ e $h < l$ (risp. $k > l$), **D** si ha $a_n > h$ (risp. $a_n < k$). 
	
	**TEOREMA DI CONFRONTO PER SUCCESSIONI CONVERGENTI**
	Se $a_n ≤ b_n ≤ c_n$ per ogni $n ∈ N$ e $a_n → l$, $c_n → l$, allora $b_n → l$. 
	**Dimostrazione**. Dato che **D** si ha sia $l−ε < a_n < l+ε$ e che $l−ε < c_n < l+ε$, **D** si avrà $l − ε < a_n ≤ b_n ≤ c_n < l + ε$

2) Si dice che la successione $\{an\}$ diverge o tende a $+∞$ (risp. $−∞$), e si scrive $a_n → +∞$ o $lim\,\,\, a_n = +∞$ (risp. $−∞$) se è verificata la seguente condizione:
   
   $∀k>0 \,\,\,\,\,∃α ∈ N : n>α⇒a_n>k$   ($a_n<-k$)
   
   ovvero, i termini della successione sono **D** maggiori (risp. minori) di qualsivoglia numero assegnato (quindi tende a infinito): se $n > α$ si ha $a_n > k$ (risp. $a_n < −k$)
   **Anche per la divergenza vale l'unicità del limite**.
   **Il teorema della permanenza** del segno si può esprimere dicendo che i termini di una successione divergente a $+∞$ ($−∞$) sono **D** positivi (negativi). Possiamo concludere che una successione di numeri positivi può tendere ad un limite positivo, a zero o a $+∞$, una successione di numeri negativi può tendere ad un limite negativo, a zero o a $−∞$.
   
   **TEOREMA DI CONFRONTO PER SUCCESSIONI DIVERGENTI**
   Se $a_n≤b_n$ per ogni $n∈ N$, se $a_n\to+∞$ anche $b_n\to+∞$, se $b_n\to-∞$ allora anche $a_n\to-∞$ 
   **Dimostrazione**
   Se $a_n → +∞$, allora **D** si ha $a_n > k$, ne segue che $b_n ≥ a_n > k$; l’altro caso si prova allo stesso modo

Possiamo ora dare questa definizione:
**Definizione**
- Una successione è detta regolare se converge o diverge. 
- Per una successione regolare, il limite è unico. 
- Una successione non regolare è anche detta oscillante

**Successioni e valore assoluto**
Consideriamo anche $\{|a_n|\}$
1) Se $a_n\to l$ allora anche $|a_n|\to |l|$ ma viceversa non vale:
   infatti se prendiamo la successione $a_n = (-1)^n$ abbiamo che la successione dei valori assoluti converge a $1$ ma $\{a_n\}$ oscilla. (la successione normale è sempre cosi: -1,1-1,1-,1,1)

2) Se $a_n → +∞$ oppure $a_n → −∞$, si ha $|an| → +∞$. Il viceversa non vale: ad esempio, posto $a_n = (−1)^n \cdot n$, la successione dei valori assoluti vale $n$ quindi diverge ma $\{a_n\}$ oscilla.

**Regolarità e limitatezza**
1) Una successione convergente è limitata ma non vale il viceversa
2) Una successione che diverge a $+∞$ ha un limite inferiore (magari parte da 0) ma non è limitata superiormente
3) Una successione che diverge a $-∞$ ha un limite superiormente (magari i suoi termini sono minori di -1) ma non è limitata inferiormente

**Successioni monotone**
Si dice che la successione ${a_n}$ è monotona se, per ogni $n ∈ N$ o definitivamente, verifica una delle seguenti condizioni: 
1) $a_n > a_{n+1}$ (successione strettamente decrescente) 
2) $a_n ≥ a_{n+1}$ (successione decrescente) 
3) $a_n < a_{n+1}$ (successione strettamente crescente) 
4) $a_n ≤ a_{n+1}$ (successione crescente)

Le successioni monotone costituiscono una categoria di successioni sicuramente regolari, ciò e stabilito dal seguente risultato, che fornisce anche il valore del limite.

**TEOREMA DI REGOLARITA' (O SUL LIMITE) DELLE SUCCESSIONI MONOTONE**
1) Una successione che verifica una delle condizioni 1) e 2) tende al proprio estremo inferiore. 
2) Una successione che verifica una delle condizioni 3) e 4) tende al proprio estremo superiore.
**Dimostrazione**
Proviamo, per semplicità, solo il caso della divergenza. 
-  Se $inf (a_n) = −∞$, fissato $k > 0$ il numero $−k$ non è un minorante per la successione, dunque esiste $α ∈ N$ tale che $a_α < −k$. Per $n > α$ si ha $a_n ≤ a_α < −k$, che è la tesi. 
-  Se $sup (a_n) = +∞$, fissato $k > 0$ il numero $k$ non è un maggiorante per la successione, dunque esiste $α ∈ N$ tale che $a_α > k$. Per $n > α$ si ha $a_n ≥ a_α > k$, che è la tesi.

Osserviamo che per una successione crescente il termine $a1$ è il minimo, per una successione decrescente è il massimo


**Operazioni con i limiti delle successioni**
1) Sia ${a_n}$ una successione regolare e sia $c$ un numero reale. Prendiamo in considerazione la successione ${ca_n}$. Si ha: 
   i) se $a_n → l$, allora $ca_n → c\cdot l$ 
   ii) se $a_n → +∞$ e $c > 0$, allora $ca_n → +∞$ 
   iii) se $a_n → +∞$ e $c < 0$, allora $ca_n → −∞$ 
   iv) se $a_n → −∞$ e $c > 0$, allora $ca_n → −∞$
   v) se $a_n → −∞$ e $c < 0$, allora $ca_n → +∞$
   
   
2) Date due successioni ${a_n}$ e ${b_n}$ prendiamo in considerazione la **successione somma** ${a_n + b_n}$. Si ha: 
   I) Se $a_n → l$ e $b_n → L$, allora $a_n + b_n → l + L$
   II) Se $a_n → +∞$ ed esiste un numero $h ≤ b_n$ per ogni $n ∈ N$, allora $a_n + b_n → +∞$ (in pratica basta che $b_n$ sia limitata inferiormente entro un certo $h$ cosi la somma tende a più infinito)
   
Se la somma di 2 successioni che rispettivamente tendono a $+∞$ e $-∞$ formano una **forma indeterminata** 

3) Date due successioni ${a_n}$ e ${b_n}$ prendiamo in considerazione la **successione prodotto** ${a_n b_n}$ Si ha:
   I) Se $a_n → l$ e $bn → L$, allora $an bn → l\cdot L$
   II) Se $a_n → 0$ e ${b_n}$ è limitata, allora $a_n b_n → 0$ 
   III) Se $a_n → +∞$ ed esiste un numero positivo $h ≤ b_n$ per ogni $n ∈ N$, allora $a_n b_n → +∞$

Se una delle 2 successioni diverge ($+/-∞$) e l'altra tende a $0$ si ha una forma indeterminata

4) Sia ${a_n}$ una successione regolare e **D** non nulla, prendiamo in considerazione la **successione reciproca** $\{ \frac{1}{a_n} \}$. Si possono dimostrare i seguenti risultati:
   I) Se $a_n → l\neq0$, allora $\frac{1}{a_n}\to \frac{1}{l}$  
   II) Se $a_n → 0$, allora $\frac{1}{a_n}\to∞$
   III) Se $a_n → ∞$, allora $\frac{1}{a_n}\to0$ 

5) Date due successioni ${a_n}$ e ${b_n}$, con $b_n\neq0$ **D**, prendiamo in considerazione la **successione quoziente** ${a_n b_n}$ . Essa viene studiata utilizzando i risultati visti ai punti 3) e 4), scrivendola nella forma $a_n\frac{1}{b_n}$ . Si ha una forma indeterminata se tale prodotto si presenta nella forma$ $0 · ∞$, quindi se entrambe le successioni sono infinitesime o infinitamente grandi

Riassumendo, le forme indeterminate che abbiamo finora trovato sono: $+∞ − ∞$, $0 · ∞$, $\frac{0}{0}$ , $\frac{∞}{∞}$


**Limiti notevoli**
Alcune successioni sono espresse mediante funzioni elementari, qui vediamo le più comuni
1) **Successione Potenza** 
   $\{n^x\}$, $x ∈ R$ 
   - Se $x=0$ la successione è costante
   - Se $x>0$ si ha $n^x\to +∞$
   - Se $x<0$ si ha $\frac{1}{n^{-x}}\to0$

1) **Successione in forma di polinomio**
   