
**Definizioni iniziali:**
- Σ: Insieme dei caratteri (la soluzione a questo è T)
- Consideriamo due nodi a e b (le foglie con frequenza minima) e il loro genitore z.
- $Σ'=Σ−\{a,b\}∪\{z\}$ (la soluzione a questo è T′)

**Relazioni tra frequenze e profondità:**

1. $f(z)=f(a)+f(b)$
    - La frequenza del nodo padre è la somma delle frequenze dei figli.
2. $d_T(a)=d_{T′}(z)+1$ e $d_T(b)=d_{T′}(z)+1$
    - La profondità di a/b nell'albero originale (T) è la profondità di z nell'albero ridotto (T') più 1. **Costruzione di una relazione tra T e T':** Il costo dell'albero T, denotato come $b(T)$, è dato, come detto prima, dalla somma delle frequenze per le profondità: $b(T) = Σ_{c ∈ Σ}\,\, f(c) * d_T(c)$
3. Espandendo la sommatoria per mettere in relazione T con T′: $b(T) = [Σ_{c ∈ Σ'}\,\, f(c) * d_{T'}(c)]−f(z)⋅d_{T'}(z)+f(a)d_T(a)+f(b)d_T(b)$ 
   _Nota_: Il termine tra parentesi quadre è $b(T′)$. Sottraiamo il contributo di z (che è in T′ ma non è foglia in T) e aggiungiamo i contributi di a e b, così abbiamo ottenuto $b(t)$, e l'uguaglianza è vera.
4. Sostituendo le relazioni di profondità e frequenza ($f(z) = f(a)+f(b)$): $b(T)=b(T′)−(f(a)+f(b))d_{T′}(z)+f(a)(d_{T′}(z)+1)+f(b)(d_{T′}(z)+1)$
5. Svolgendo i calcoli, i termini con $d_{T′}(z)$ si cancellano: $=f(a)+f(b)$
6. Quindi la relazione fondamentale è: $b(T)=b(T′)+f(a)+f(b)$ 
  
  **Suppongo che la sottostruttura ottima non esista (dimostrazione per assurdo)**
- _Ipotesi per assurdo_: Supponiamo che T **non** sia l'albero ottimo per Σ (e quindi anche che T′ non sia l'albero ottimo per Σ′). Di conseguenza, deve esistere un albero $T_{opt}$ con costo strettamente inferiore a T: $b(T_{opt})<b(T)$
- _Costruzione dell'albero ridotto_: Prendiamo $T_{opt}$ e uniamo le foglie a e b nel padre z. Otteniamo un nuovo albero $T'_{opt}$ valido per l'alfabeto ridotto $\Sigma'$. Il costo di questo albero ridotto è: $$b(T'_{opt}) = b(T_{opt}) - (f(a) + f(b))$$
- _Sviluppo algebrico_: Riprendiamo la disuguaglianza del punto 1: $b(T_{opt})<b(T)$ Sottraiamo a entrambi i membri la quantità costante $(f(a)+f(b))$: $b(T_{opt})−(f(a)+f(b))<b(T)−(f(a)+f(b))$ Sostituiamo i termini con le definizioni dei costi ridotti ($b(T'_{opt})$ e $b(T')$): $$\underbrace{b(T_{opt}) - (f(a) + f(b))}_{b(T'_{opt})} < \underbrace{b(T) - (f(a) + f(b))}_{b(T')}$$ Otteniamo infine: $$b(T'_{opt}) < b(T')$$ Abbiamo dimostrato l'esistenza di un albero $T'_{opt}$ con costo inferiore a T′. Questo _contraddice l'ipotesi iniziale_ che T′ fosse l'albero ottimo per Σ′.


