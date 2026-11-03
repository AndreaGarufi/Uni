# **Costa sta sotto GPIO init (a basso livello)**
Quando facciamo l'inizializzazione di qualcosa, spesso avvengono un sacco di operazioni che noi non vediamo direttamente:

**SPF Special Function Register**
Questi registri speciali servono a gestire e monitorare le periferiche dell'STM32, questi registri sono formati da 32 bit e ogni bit si riferisce a dei flag o impostazioni di configurazione, solitamente quando vogliamo operare su una periferica basta modificare solo 1 (o pochi) di quei bit per cambiare l'impostazione di quest'ultima:
Le operazioni che possiamo fare sono:
- Settare a 1 il bit
- Pulire il bit impostandolo a 0
- Toggle (invertire) il valore di un bit
- Testare il valore di un bit andandolo a leggere

Tutte queste operazioni si fanno attraverso le bit-mask:
(i numeri vengono mostrati in esadecimale)
![[Pasted image 20261102200130.png]]

La figura mostra il registro chiamato MODER, che gestisce le periferiche GPIO (è uno per ogni porta)
- rw sta per lettura/scrittura
- Un registro STM32 è a **32 bit** (numerati da 0 a 31). Ogni porta GPIO ha fino a 16 pin (da Pin 0 a Pin 15). Poiché ci sono **4 modalità possibili**, servono **2 bit per ogni pin** ($2^2 = 4$ combinazioni):
  - Pin 0 usa i bit `[1:0]` (`MODER0`)
  - Pin 1 usa i bit `[3:2]` (`MODER1`)
  - ...
  - Pin $y$ usa i bit `[2y+1 : 2y]` (`MODERy`)

Impostando la coppia di bit di un determinato pin se ne può controllare il comportamento:
- 00 -> input
- 01 -> output
- 10 -> funzione alternata
- 11 -> il pin si usa per segnali analogici anziché digitali

**Modifica di un bit tramite maschera**
Per modificare un bit (e cambiare quindi il comportamento della porta) bisogna utilizzare le maschere di bit e le operazioni logiche (OR, AND, NOT ecc...). Le maschere nel codice sono espresse in esadecimale

**Settare un bit a 1**
Ad esempio con l'operazione di OR:
![[Pasted image 20261102201132.png|612]]

**Pulire un bit a 0**
Esempio con AND e pulizia di un bit (lo facciamo diventare 0)
![[Pasted image 20261102201534.png|612]]

**Fare il toggle di un bit**
Qui si usa l'operazione di XOR, uguale ad OR ma se sono entrambi 1 risulta 0
![[Pasted image 20261103100533.png|619]]

**Testare un bit**
![[Pasted image 20261103100659.png|623]]


**Esempio pratico:**
Vogliamo settare il pin 12 della GPIOA come output, quindi dovremmo modificare i bit 24 e 25
![[Pasted image 20261103100937.png|628]]

Queste sono le operazioni da fare
1) Clear bits 24-25: GPIOA->MODER &= 0xfcffffff;  -> AND con 0xfcffffff
2) Set bit 24: GPIOA->MODER |= 0x01000000; -> OR con 0x01000000

**Settare i bit con lo shift**
Possiamo modificare il pattern dei bit utilizzando lo *shift a sinistra* in numero uguale al numero di bit da manipolare:
Ad esempio settiamo il bit 3 a 1 della variabile A ad 8 bits
`A = A | (1 << 3);`  in sostanza 1 shiftato 3 volte

![[Pasted image 20261103101350.png|632]]

Sopra si usa lo shifting sotto la maschera

Possiamo anche *pulire i bit con lo shifting*
`A = A & ˜(1 << 4);`
![[Pasted image 20261103101545.png|643]]
Shiftiamo l'1 a sinistra di 4 posizioni, nottiamo la maschera e abbiamo pulito il bit 

