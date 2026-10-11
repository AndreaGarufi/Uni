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

---
##### Transistor
*Un transistor è un componente elettronico composto da materiali "semi-conduttori"* (germano, silicio, arsenico, gallio ecc...).

- Fa da amplificatore di corrente/voltaggio
- Ci sono diverse tipologie di transistor che differiscono nella struttura, nel funzionamento e nelle applicazioni
  - Bipolar Junction Transistor (BJT)
  - Junction Field-Effect Transistor (JFET)
  - Metal-Oxide-Semiconductor Field-Effect Transistor (MOSFET)

![[Pasted image 20261011114500.png|344]]


---
##### MOSFET Transistor
Il MOSFET riceve in ingresso una tensione e restituisce in uscita una corrente.

**I tre terminali (pin):**
- **Gate (G):** il terminale di controllo (ingresso).
    
- **Source (S):** la sorgente di carica, spesso presa come riferimento comune.
    
- **Drain (D):** il terminale di scarico da cui scorre la corrente principale verso il Source.

![[Pasted image 20261011120430.png|258]]


**Il MOSFET come interruttore digitale**
- Nei circuiti digitali (logica binaria), non interessa una risposta proporzionale/lineare continua, ma due stati ben distinti: **acceso (ON)** e **spento (OFF)**.

Il MOSFET viene modellato come un classico interruttore meccanico posto tra il terminale di **Drain** e quello di **Source**, il cui stato è regolato dalla tensione di ingresso sul **Gate** ($V_{GS}$).


**Esempio:** guidare un motore con un MCU
- I componenti di potenza (es. motori elettrici) non possono essere pilotati direttamente da un'uscita digitale di un MCU
- Piccolo motore elettrico:
    - Tensione di funzionamento di $6\text{ V}$, $12\text{ V}$, $24\text{ V}$, $48\text{ V}$ (e anche tensioni superiori)
        
    - Corrente tipica nell'ordine di $100\text{ mA} - 10\text{ A}$

- Uscite digitali del MCU:
    - Tensione di uscita di $5\text{ V}$ o $3.3\text{ V}$
        
    - In grado di erogare correnti nell'ordine di $100\ \mu\text{A} - 200\text{ mA}$
        
- Un MOSFET può essere utilizzato come **driver per motori**: attivato da un'uscita digitale, può pilotare il motore collegato nella rete **drain-source**:

![[Pasted image 20261011120948.png|310]]


---

##### Lo stadio di uscita di una porta digitale di un microcontrollore (MCU)

![[Pasted image 20261011121414.png|349]]

Questa foto rappresenta una porta GPIO ed è composta da 2 parti:
- *Output logic*
  È la parte a monte, gestita direttamente dal processore e dai registri periferici (come i registri dati `ODR` / `BSRR` dei microcontrollori).
  Lavora su semplici segnali logici binari (`0` o `1`).Decide **cosa** il pin deve trasmettere (livello logico alto o basso), ma non ha la capacità di pilotare direttamente correnti o gestire la modalità elettrica del pin fisico verso l'esterno.
- *Output Stage*
  È la circuiteria fisica (interfaccia elettrica) posta a valle, collegata direttamente alle linee di alimentazione **VDD** e di massa **GND**, e al piedino fisico (**output pin**). Riceve il dato dalla logica interna e si occupa di pilotare fisicamente il pin.

Vediamo 2 configurazioni circuitali:
**Push-Pull**
La configurazione Push-Pull è composta da 2 MOSFETs connessi come in figura: sono Upper e Lower.
![[Pasted image 20261011121904.png|308]]

Quando arriva il segnale 1 (programmato lato software) si attiva l'upper MOSFET, mentre se arriva 0 si attiva il lower MOSFET

**Open-Drain**
Qui l'unico MOSFET che resta è il lower.
![[Pasted image 20261011122119.png|308]]
Quando il software scrive 1 non succede nulla ma lo stato logico deve essere mantenuto da un pull-up resistor esterno

Quando il software scrive 0 si attiva il lower MOSFET come nella configurazione Push-Pull

