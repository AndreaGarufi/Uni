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
1) Sia $l$ un numero reale. Si dice che la successione $\{a_n\}$ *converge* o *tende* ad $l$ o che $l$ è il limite della successione e si scrive $a_n->l$ o $lim\,\,\,\,a_n=l$  se è verificata la seguente condizione:
   $∀ε>0 \,\,\,\,∃α∈N:n>α⇒|a_n-l|<ε$ 

ovvero se dato un qualunque intorno di $l$, **D** i termini della successione appartengono a tale intorno: se $n>α$ si ha $|a-n-l|<ε⇐⇒ -ε<a_n-l<ε⇐⇒l-ε<a_n<l+ε$ 
Ad esempio, si verifica facilmente che una successione costante $a_n=k$ tende a $k;$ $\frac{1}{n}\,\,→0$ 
Si ha un risultato fondamentale, che è basato sulla seguente proprietà di $R$: dati 2 numeri reali distinti $a,b$ esistono un intorno di $a$ un intorno di $b$ disgiunti

