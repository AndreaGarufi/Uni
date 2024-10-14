Questo file è la rielaborazione delle slide [[01_Parte1.pdf]]

# LOGICA PROPOSIZIONALE
La **logica** è un linguaggio formale usato per rappresentare informazioni. Ogni linguaggio è formato da:
- **Sintassi**: che definisce le frasi del linguaggio
- **Semantica**: che definisce il significato delle frasi
La logica più semplice di tutti è la logica proposizionale oggi basata sulla matematica booleana, quest'ultima viene detta proposizionale perché si occupa di proposizioni, più precisamente di variabili proposizionali, quest'ultime possono assumere solo 2 valori: 
- 1 = VERO
- 0 = FALSO
Ogni variabile proposizionale è già da se una "formula" proposizionale, ovviamente questa è una formula molto basilare. Per creare delle formule più complesse usiamo dei connettivi logici che sono i seguenti:

- ==¬ (negazione)==: si legge "non", e inverte il valore di verità di una proposizione. Se una proposizione è vera, la sua negazione è falsa, e viceversa. Questo connettivo logico rappresenta la porta logica NOT
- ==∨ (disgiunzione logica)==: si legge "o", ed è vera se **almeno una** delle due proposizioni è vera. Questo connettivo logico rappresenta la porta logica OR
- ==∧ (congiunzione logica)==: si legge "e", ed è vera se **entrambe** le proposizioni sono vere.  Questo connettivo logico rappresenta la porta logica AND
- ==⇒ (implicazione)==: si legge "se... allora…" o semplicemente "implica". È falsa solo se il primo termine è vero e il secondo è falso.
- ==⇔ (doppia implicazione o coimplicazione)==: si legge "se … e solo se …". È vera quando entrambi i termini sono veri o entrambi falsi.

**Esempi di formule** (usando le variabili P e Q che sono scelte casualmente):
- ¬P = "Non P"
- Q  
- P ∨ Q  = "P o Q"
- P ∧ Q = "P e Q"
- P ⇒ Q = "se P allora Q"
- P ⇔ Q = P se e solo se Q
Come per le operazioni normali (somma, moltiplicazione, ecc...) anche queste hanno delle precedenze,  la negazione (¬) ha la precedenza su tutto mentre congiunzione (∨) e disgiunzione (∧) hanno la stessa priorità infatti:
- ¬p ∨ q è la formula dove la negazione si applica solo a p 
- ¬(p ∨ q) è la formula dove la negazione si applica alla disgiunzione p ∨ q

Date 2 formule $P_1$ e $P_2$ che ovviamente posso assumere solo una valore (questa cosa la impone una funzione chiamata **interpretazione** che appunto assegna a $P_1$ e $P_2$  i valori 1 o 0) Di seguito si calcola il valore di verità delle seguenti formule: 
- I(¬$P_1$) è vera solo se $P_1$ è falsa
- I($P_1$ ∨ $P_2$) è vera se almeno una tra $P_1$ o $P_2$ è vera
- I($P_1$ ∧ $P_2$) è vera se entrambe sono vere
- I($P_1$ ⇒ $P_2$) è falsa solo quando $P_1$ è vera e $P_2$ è falsa, nei restanti casi è vera
- I($P_1$ ⇔ $P_2$) è vera se e solo se $P_1$ == $P_2$
Questa è la tabella della verità di tutte queste formule:

| $P_1$ | $P_2$ | ¬$P_1$ | $P_1$ ∨ $P_2$ | $P_1$ ∧ $P_2$ | $P_1$ ⇒ $P_2$ | $P_1$ ⇔ $P_2$ |
| ----- | ----- | ------ | ------------- | ------------- | ------------- | ------------- |
| 1     | 1     | 0      | 1             | 1             | 1             | 1             |
| 1     | 0     | 0      | 1             | 0             | 0             | 0             |
| 0     | 1     | 1      | 1             | 0             | 1             | 0             |
| 0     | 0     | 1      | 0             | 0             | 1             | 1             |
##### Nomenclature varie:
- Data una formula diremo che è **soddisfacibile** se esiste almeno un caso in cui sia vera, qualunque siano i valori delle variabili.
- Data una formula diremo che è **insoddisfacibile** se non esiste almeno una caso in cui sia vera, qualunque siano i valori delle variabili.
- Data una formula si dice **tautologia** se è sempre vera qualunque siano i valori delle variabili.
Di seguito degli esempi (usando le variabili della tabella di verità):
- $P_1$ ∧ $P_2$ è soddisfacibile
- $P_2$ ∨ ¬$P_2$ è tautologia (Questo viene chiamato **Principio del terzo escluso**)
- $P_2$ ∧ ¬$P_2$ è insoddisfacibile (Questo viene chiamato **Principio di non contraddizione**)

Due formule $P_1$ e $P_2$ si dicono equivalenti se hanno lo stesso valore è si scrivono in questo modo:  $P_1$ $\equiv$ $P_2$

Per la disgiunzione e la congiunzione vale la proprietà commutativa e associativa 
- p ∨ q ≡ q ∨ p (commutativa della disgiunzione)
- p ∨ (q ∨ r ) ≡ (p ∨ q) ∨ r (associatività della disgiunzione)

##### Giustificazione o conseguenza logica:
Sia $P$ un insieme di proposizioni e $p$ una proposizione generica, ci chiediamo quando $P$ giustifica $p$ questa domanda la denotiamo con: $P$  |= $p$
Di seguito un esempio:
$P$ = { p, p => q }  
$P$  |= $q$
Questa è la tavola di verità dell'esempio
![[Pasted image 20241008151855.png]]
==N.B:== Per essere vero che $P$ giustifica $q$ tutte le formule di $P$ devono essere vere e anche $q$ deve essere vera. Questa cosa si capisce ancora meglio in questo esempio

$P$ = { p ∨ r, q ∨ ¬r }  
$P$  |= p ∨ q

![[Pasted image 20241008232946.png]]

Come possiamo facilmente notare P giustifica quella disgiunzione (ovvero p ∨ q) solo quando tutte le formule di $P$ e la disgiunzione tra $p$ e $q$ sono vere (attenzione ai vari casi nella tabella). 

**TIPS**: [[Tips#Come creare tutte le combinazioni tra le variabili senza confondersi]] 

**Molte volte formule complesse vengono standardizzate in 2 forme chiamate "normali":**
- CNF (Forma Normale Congiuntiva) che si basa sul fare un AND di vari OR:
	- (p ∨ q) ∧ (¬p ∨ ¬r ∨ s)
- DNF (Forma Normale Disgiuntiva) che si basa sul fare un OR di vari AND:
	- (p ∧ q) ∨ (¬p ∧ ¬r ∧ s)

Una qualunque formula P si può trasformare in una delle due forme normali, attraverso un semplice procedimento algoritmico.

**Algoritmo di Trasformazione in Forma Normale**

**(Fase 1)** Elimina le doppie implicazioni p ⇔ q sostituendole con (p ⇒ q) ∧ (q ⇒ p) 
**(Fase 2)** Elimina le implicazioni p ⇒ q dalla formula sostituendole con ¬p ∨ q 
**(Fase 3)** Sposta le negazioni ¬ a ridosso delle variabili proposizionali, utilizzando le regole di De Morgan, ed eliminando le doppie negazioni.
Per esempio ¬(¬p ∨ ¬r ∨ s) diventa (p ∧ r ∧ ¬s)

**(Fase 4-a)** **Per costruire una CNF** distribuire la congiunzione sulla disgiunzione ed eliminare tautologie. Per esempio (p ∧ q) ∨ (¬p ∧ ¬r ∧ s) è una formula in DNF che vogliamo trasformare in CNF. Abbiamo 
(p ∨ (¬p ∧ ¬r ∧ s)) ∧ (q ∨ (¬p ∧ ¬r ∧ s)) 
≡
(p ∨ ¬p) ∧ (p ∨ ¬r ) ∧ (p ∨ s) ∧ (q ∨ ¬p) ∧ (q ∨ ¬r ) ∧ (q ∨ s)      (qui ha eliminato una tautologia)
≡
		  (p ∨ ¬r ) ∧ (p ∨ s) ∧ (q ∨ ¬p) ∧ (q ∨ ¬r ) ∧ (q ∨ s)

**(Fase 4-b) Per costruire una DNF** distribuire la disgiunzione sulla congiunzione ed eliminare disgiunti insoddisfacibili e ripetizioni. Per esempio, (p ∨ q) ∧ (¬p ∨ ¬r ) è una formula in CNF che vogliamo trasformare in DNF. Abbiamo 
(p ∧ ¬p) ∨ (p ∧ ¬r ) ∨ (q ∧ ¬p) ∨ (q ∧ ¬r )             (qui ha eliminato un insoddisfacibile)
≡
		  (p ∧ ¬r ) ∨ (q ∧ ¬p) ∨ (q ∧ ¬r )

Esercizi per capire meglio:
Dimostrare, utilizzando le tavole di verità, che (p ∧ q) ∨ (¬p ∧ ¬r ∧ s) ≡ (p ∨ ¬r ) ∧ (p ∨ s) ∧ (q ∨ ¬p) ∧ (q ∨ ¬r ) ∧ (q ∨ s)  CNF
Dimostrare, utilizzando le tavole di verità, che (p ∨ q) ∧ (¬p ∨ ¬r ) ≡ (p ∧ ¬r ) ∨ (q ∧ ¬p) ∨ (q ∧ ¬r )  (DNF)


![[Pasted image 20241013110104.png]]


![[Pasted image 20241013110249.png]]



# INSIEMI
**Due insiemi A e B sono uguali se hanno gli stessi elementi. In simboli:**
**A = B ⇔ (∀x)(x ∈ A ⇔ x ∈ B)**
gli insiemi A = {1, 2, 3} e B = {2, 3, 1, 2, 3} sono uguali perché contengono gli stessi elementi.

- In un insieme gli elementi compaiono solo una volta ciascuno.

- Un insieme che ha solo un elemento è detto Singoletto {a}.

- Con il simbolo ∅ indicheremo un insieme vuoto.

Cosa vuol dire che P è una proprietà ben definita? Vuol dire che per ogni valore di x, P(x) può assumere sempre solo i 2 valori (BEN DEFINITI **vero o falso** (anche se non sappiamo quale).

La **cardinalità** definisce il numero di elementi che compone l'insieme. E si esprime con  |A| .
Esempio:
- la cardinalità di |{1,2,3}| = 3 
- la cardinalità dell'insieme dei numeri pari è +∞


Se abbiamo due insiemi A e B e tutti gli elementi di A sono anche elementi di B allora diciamo che A è incluso in B, ovvero che A è un sottoinsieme di B. 
**Definizione (Inclusione)** A è un sottoinsieme di B, denotato con A ⊆ B se :
A ⊆ B ⇔ (∀x)(x ∈ A ⇒ x ∈ B)
B è il suo sovra insieme B ⊇ A


**Definizione (Insieme discreto)** Un insieme A si dice discreto se è possibile ordinare i suoi elementi in maniera tale che tra un qualunque elemento ed il successivo nell’ordinamento dato, non vi sono altri elementi dell’insieme. Quindi, è un insieme composto da elementi "isolati".

Esempio: l'insieme dei numeri naturali A={1,2,3,4,5,6,7,8,9} dove in questo caso tra i numeri non c'è nulla perché abbiamo preso in considerazione i numeri naturali (N).
invece se prendessimo in considerazione i numeri reali (R), quello non sarebbe un insieme discreto.

**Operazioni tra insiemi ∪, ∩**

**Unione di due insiemi** 
L’unione di due insiemi A e B è l’insieme formato da quegli **elementi che appartengono ad almeno uno dei due insiemi** A e B. La notazione per indicare l’unione è A ∪ B e quindi: 
A ∪ B = {x : x ∈ A oppure x ∈ B.}
Esempio: A = {1,2,3} B = {3,4,5}     A ∪ B = {1,2,3,4,5,6}

**Intersezione di due insiemi**
L’intersezione di due insiemi A e B è l’insieme formato da quegli **elementi che appartengono ad entrambi gli insiemi** A e B. La notazione per indicare l’intersezione è A ∩ B e quindi: 
A ∩ B = {x : x ∈ A e x ∈ B.}
Esempio: A = {1,2,3} B = {3,4,5}   A ∩ B = {3}

![[Pasted image 20241013184436.png]]

**Differenza di due insiemi**
La differenza di due insiemi A e B denotata con A \ B è **l’insieme formato da quegli elementi del primo insieme A che non appartengono al secondo insieme B**. 
Quindi A \ B = {x : x ∈ A e x /∈ B.}
Esempio Se A = {1, 2, 3} e B = {3, 4, 5} allora A \ B = {1, 2}, l’elemento 3, che è l’unico presente in entrambi gli insiemi, è sottratto da A.

Se assumiamo di trattare con insiemi che siano tutti sottoinsiemi di un insieme "universo" U, dato A ⊆ U l’insieme U \ A viene detto complemento di A. **Quindi, il complemento di un insieme A è l’insieme di tutti gli elementi che non appartengono ad A.** 
Ci sono diverse notazioni per indicare il complemento di un insieme, le più comuni sono: 
U / A = $A^C$ 
U/\ A = ¯A 
Esempio Se A = {1, 2, 3} e U = {1, 2, 3, · · · , 10}| allora AC = {4, 5, · · · , 10}

![[Pasted image 20241013190459.png]]

**Differenza simmetrica di due insiemi**
La differenza simmetrica di due insiemi A e B è l’unione delle 2 differenze, **ovvero (A \ B) ∪ (B \ A), quindi è l’insieme formato da quegli elementi del primo o del secondo insieme che non appartengono ad entrambi.** La notazione per indicare la differenza simmetrica è ∆ e quindi: A∆B = (A \ B) ∪ (B \ A).
Esempio:
Se A = {1, 2, 3} e B = {3, 4, 5}| allora A∆B = {1, 2, 4, 5}    (si levano gli elementi in comune)

**Una famiglia di insiemi** **che ha un numero infinito di elementi è una famiglia infinita.** **Se invece ha un numero finito di elementi allora è una famiglia finita.** Si noti che la definizione appena data non riguarda la cardinalità (finita o infinita) degli elementi della famiglia.
Esempio:
Sia F = {P, D} dove P è l’insieme dei numeri pari (infinito) e D è l’insieme dei numeri dispari (infinito). La famiglia F è una famiglia finita di insiemi.

Sia dato un insieme U ed una operazione definita su uno o più elementi di U. **Se l’operazione può essere definita o completata all’interno di U allora diciamo che U è chiuso rispetto a tale operazione.** 
Esempi: 
1) Sia U = N se consideriamo l’operazione binaria "somma" allora N è chiuso rispetto alla somma, perché la somma di due numeri interi non negativi è a sua volta un numero intero non negativo. Se invece consideriamo l’operazione "sottrazione" allora N non è chiuso rispetto alla sottrazione perché il risultato della sottrazione potrebbe essere un numero negativo che non appartiene a N. (in breve quando fai l'operazione non devi "uscire fuori dall'insieme"). 
2) Sia X = {1, 2, 3}. Se consideriamo l’operazione binaria "minimo comune multiplo" (mcm) allora dato che mcm(2, 3) = 6, X non è chiuso rispetto a tale operazione. 
3) Se poniamo X = {1, 2, 3, 6} allora X è chiuso rispetto all’operazione mcm.

**Definizione** 
**UNIONE**
Sia F una famiglia di insiemi diciamo che F è chiusa rispetto all’unione se per ogni coppia di insiemi X e Y appartenenti a F anche X ∪ Y appartiene a F. 
**INTERSEZIONE**
Diciamo che F è chiusa rispetto all’intersezione se per ogni coppia di insiemi X e Y appartenenti a F anche X ∩ Y appartiene a F.