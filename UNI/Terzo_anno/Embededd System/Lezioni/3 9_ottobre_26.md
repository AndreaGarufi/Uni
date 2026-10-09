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

![[Pasted image 20261009142951.png|425]]



