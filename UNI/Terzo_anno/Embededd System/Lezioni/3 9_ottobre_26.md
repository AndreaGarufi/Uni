# **Introduzione ai circutiti elettrici**

##### Elementi di base per circuiti a corrente diretta (DC)
- V -> voltaggio (volt) = differenza di potenziale
- I -> corrente (ampere) = circolazione degli elettroni all'interno dei componenti
- R -> resistenza (Ohm) = l'abilità di un materiale di "opporsi" al flusso di elettroni


![[Pasted image 20261009135752.png|332]]

---
##### Legge di Ohm
![[Pasted image 20261009135842.png|333]]

**Componenti del circuito**
- *Generatore di tensione* ($V_g$) 
- *Resistore* (R)
- *Corrente* (I)

dove:
$V_g$ ha polarità positiva in alto e polarità negativa in basso: gli elettroni tendono a uscire dal polo positivo e rientrare in quello negativo.
$V_r$ è la differenza di potenziale che è la "tensione consumata" attraversando l'oggetto, in questo caso una resistenza.

> [!abstract] Approfondimento
> Se dovessi collegare un led a questo circuito? Supponendo che il generatore eroghi 12 volt, lo dovrei posizionare dopo la resistenza e dato che solitamente i led assorbono 1.2/1.4 volt avrei bisogno di una resistenza che riesca ad assorbire 10.6 volt. 
La regola è che se dal generatore esco con N volt devo rientrare con 0, quindi devo "consumare" tutti i volt che sto generando. Se non mettessimo la resistenza il led si brucerebbe.

Vediamo le formule dell'immagine...
$$V = R \cdot I$$
Legge fondamentale di Ohm

$$V_g = V_r$$
Equilibrio delle tensioni. Per il discorso di prima, ovvero che dobbiamo ritornare al generatore con 0 volt, questo implica che dato che nel cirtuito è presente solo una resistenza questa assorbe esattamente 12 V quindi $V_g = V_r$

Da tutto questo ricaviamo questa formula
$$I = \frac{V_g}{R}$$

Esempi:
![[Pasted image 20261009142504.png|405]]

![[Pasted image 20261009142528.png|405]]


---

##### Legge di Kirchhoff
Prima abbiamo detto che se esco con 12 volt devo rientrare con 0, in un certo senso questa è la legge di Kirchhoff:

La somma algebrica dei voltaggi in un loop circuitale è pari a 0
![[Pasted image 20261009142728.png|334]]

Esempi:
![[Pasted image 20261009142905.png|422]]
![[Pasted image 20261010180505.png|422]]


![[Pasted image 20261009142951.png|425]]
![[Pasted image 20261010180559.png|428]]



##### Partitore di tensione
Serve ad ottenere una tensione ridotta in uscita rispetto ad una tensione in ingresso più ampia.

![[Pasted image 20261010180855.png|317]]

$\frac{R2}{R1 + R2}$ -> questo darà come risultato sempre un numero compreso tra 0 e 1 il che significa che in questo modo $V_{out}$ è più piccola rispetto a $V_{in}$.

Possibile esercizio:
![[Pasted image 20261010182211.png|486]]


# **Semiconduttori, Diodi e LED**

- *Un diodo è un componente elettronico composto da materiali "semi-conduttori"* (germano, silicio, arsenico, gallio ecc...).
- E' composto da un anodo e un catodo (normalmente la corrente entra dall' anodo ed esce dal catodo).
- Può essere *polarizzato direttamente* e quindi la corrente passa da anodo (+) a catodo (-), o *polarizzato inversamente* quando all'anodo colleghiamo il - e al catodo il +, in questo modo funge da interruttore aperto e blocca la corrente
- Il diodo LED è una particolare tipologia di diodo che emette luce visibile quando polarizzato direttamente

![[Pasted image 20261010184048.png]]


Esercizio con diodo LED
![[Pasted image 20261010184203.png|430]]

(per trovare la I è stata usata $Vr$ anziché $Vd$ perché la legge di Ohm può essere applicata solo ai resistori, che hanno un valore in ohm costante mentre il led potrebbe variare).

Altro esercizio:
![[Pasted image 20261010184616.png|428]]


![[Pasted image 20261010184859.png|453]]

