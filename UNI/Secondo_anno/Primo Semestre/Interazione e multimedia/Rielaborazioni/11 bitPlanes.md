Un’immagine con una profondità colore di N bit (si intende la quantità di bit dedicati ad ogni colore dell'immagine) può essere rappresentata da N piani di bit (bit-planes), ciascuno dei quali può essere vista come una singola immagine binaria. In particolare si può indurre un ordine che varia dal Most Significant Bit (MSB) fino al Least Significant Bit (LSB)

![[Pasted image 20260116214851.png|500]]

**Definizione**
Il bit plane di un’immagine digitale a N bit, è un’insieme di N immagini binarie (piani), in cui l’immagine i-esima contiene i valori dell’ i-esimo bit della codifica scelta

Bit planes di lena
![[Pasted image 20260116215016.png]]
![[Pasted image 20260116215035.png]]

*Osservazioni*
Se si usa la codifica in binario puro i piani di bit più significativi contengono informazioni sulla struttura dell’immagine, mentre quelli via via meno significativi forniscono i dettagli sempre più piccoli
Come si può vedere da questa immagine
![[Pasted image 20260116215225.png]]

Si noti che solo i piani dal 7 al 3 contengono dati significativi dal punto di vista visuale

Il rumore delle immagini e gli errori di acquisizione sono più evidenti nei piani bassi

**Usi del Dit Planes**
- Questo genere di scomposizione è molto utile per eliminare tutti i valori compresi in un certo range. 
- Ad esempio, se si vogliono eliminare tutti i grigi compresi tra 32 e 63, è necessario porre a 0 il quinto bit, e quindi tutto il piano 5


**ricostruzione senza un piano di bit**
![[Pasted image 20260116220029.png]]
man mano che saliamo di livello perdiamo sempre più le informazioni più generali facendo rimanere solo i dettagli forniti dai livelli più bassi

Se la codifica usata è quella in binario puro, allora risulta evidente uno svantaggio: una piccola variazione può ripercuotersi su tutti i piani. 
Esempio: Se un pixel ha ad esempio intensità 127 (01111111) e il suo adiacente ha intensità 128 (10000000) allora la transizione tra 0 e 1 si ripercuote su tutti i piani di bit. 
*Serve un codice in cui valori molto vicini abbiano codifiche binarie molto simili!*

**Soluzione codice grey**
Il codice Gray a m bit $𝑔_{𝑚−1} … {𝑔_1𝑔_0}$ che corrisponde al numero in binario puro $𝑎_{𝑚−1} … {𝑎_1 𝑎_0}$ può essere calcolato con la formula 
$$
\begin{aligned}
g_i &= a_i \oplus a_{i+1} & 0 \le i \le m-2 \\
g_{m-1} &= a_{m-1}
\end{aligned}$$

dove ⊕ denota l’operatore XOR (OR esclusivo)

*Il codice Gray gode della proprietà per cui ogni codeword differisce dalla precedente per un solo bit (distanza di Hamming = 1)*

![[Pasted image 20260116220855.png]]
![[Pasted image 20260116220933.png]]

**Esempio con i numeri a 3 bit**
![[Pasted image 20260116221003.png]]
Si osservi il caso con maggiore variazione in binario, quello relativo ai numeri decimali 3 e 4. in questo caso a fronte di una grande variazione di bit nel binario puro si osserva la variazione di un solo bit nel gray code. Inoltre, nel gray code ogni numero con il suo successivo differisce solo per la variazione di un bit

 
- Tornando al nostro esempio dei numeri decimali 127 e 128. 
- In binario puro abbiamo 01111111 per 127 e 10000000 per 128. I due numeri consecutivi hanno la variazione di tutti i bit. 
- In gray code abbiamo 01000000 per 127 e 11000000 per 128, si noti la variazione di un solo bit

**Binario puro VS Gray Code**
![[Pasted image 20260116221252.png]]
![[Pasted image 20260116221323.png]]

