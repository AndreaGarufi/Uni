
### ERROR DETECTION
**Ridondanza: elemento di base per l’error detection** 
Immaginiamo di voler trasmettere dei dati anagrafici all’interno di un generico pacchetto. Aggiungere allo stesso pacchetto un codice fiscale, mi fornisce delle informazioni si ridondanti, ma che mi permettono di individuare possibili errori di trasmissione successivamente alla comunicazione.

**Error Detection**

Nella realtà i pacchetti trasmetti contengono una sequenza di bit D (i dati) e un EDC (error detection and correction bits). L'EDC può essere una qualsiasi tecnica di controllo: CRC, Checksum, bit di parità ecc...
Una volta che il datagramma con EDC passa per il canale inaffidabile al pacchetto viene applicata la funzione inversa a quella di partenza per risalire ai dati originali e capire se ci sono stati degli errori
![[Pasted image 20260506115016.png|717]]

### ERROR CORRECTION
**Distanza Di Hamming**
Misura la distanza tra 2 code word: 
1000110
1100110
distanza = 1

*Vocabolario*
Definiamo vocabolario un insieme di codeword. Un vocabolario si dirà completo se, con $n$ bit, avrà $2^n$ codeword
![[Pasted image 20260505102514.png|429]]
In un vocabolario la distanza è misurata come il minimo tra tutte le distanze
Per comunicare si possono usare solo le code word appartenenti al vocabolario.

Se arriva questa code word: 101000 che non appartiene al vocabolario posso risalire in maniera probabilistica a capire qual'era la code word originale in base alla distanza dal vocabolario
![[Pasted image 20260505102620.png|370]]


> [!important] **Basi teoriche per poter fare rilevazione e correzione degli errori**
> 
Se abbiamo $e$ errori e vogliamo correggerli abbiamo bisogno di una distanza $d= 2e+1$ , invece per rilevarli abbiamo bisogno di una distanza $d = e+1$



>[!help] **Reminder - Formula coefficiente binomiale**
>![[Pasted image 20260506122006.png|200]]

**Formula generale per la correzione degli errori:**
![[Pasted image 20260506122115.png|717]]
![[Pasted image 20260506122130.png]]


**Codice di Hamming**
Questo algoritmo serve ad inserire dei bit di controllo prima di inviare il messaggio in modo che il destinatario possa risalire al messaggio originale in caso di errori dovuti al canale inaffidabile.

E' composto da 2 fasi: una di creazione del messaggio e una di verifica e correzione (per il destinatario)
- **Parte 1**
  L'obbiettivo qui è prendere i bit contenenti i dati e infarcirli con altri bit di controllo in modo che diventino resistenti agli errori
  Indicheremo con $b_r$ i bit di controllo, questi bit vanno posizionati solo negli indici che sono potenze di 2.
  Prendiamo la stringa di esempio: `xx1x001x0`
  Mettiamo in fila le posizioni da 1 a 9 e vediamo cosa c'è dentro:
	- Pos 1: **$b_1$** (bit di controllo, indicato con `x`)
	- Pos 2: **$b_2$** (bit di controllo, indicato con `x`)
	- Pos 3: $b_3 = 1$ (dato)
	- Pos 4: **$b_4$** (bit di controllo, indicato con `x`)
	- Pos 5: $b_5 = 0$ (dato)
	- Pos 6: $b_6 = 0$ (dato)
	- Pos 7: $b_7 = 1$ (dato)
	- Pos 8: **$b_8$** (bit di controllo, indicato con `x`)
	- Pos 9: $b_9 = 0$ (dato)
 
 Come troviamo il valore delle $x$? 
 La regola dice che ogni bit di controllo "sorveglia" uno specifico numero di bit:
>[!important] **REGOLA**
>Un bit di controllo in posizione $X$ sorveglia tutte e sole le posizioni che, scritte in binario, hanno un **1** nello stesso posto in cui ce l'ha la posizione $X$.
>Facciamo gli esempi concreti (usiamo 4 cifre binarie per comodità):
>- **Il bit $b_1$ (posizione 1):** In binario il numero 1 si scrive `0001`. L'uno si trova nell'**ultima cifra a destra**. Quindi $b_1$ sorveglia tutte le posizioni che in binario finiscono con 1. Quali sono i numeri che finiscono con 1 in binario? Esattamente i **numeri dispari**: 1 (`0001`), 3 (`0011`), 5 (`0101`), 7 (`0111`), 9 (`1001`), ecc.

L'operazione usata è lo *XOR* (se i bit sono uguali il risultato è 0, se sono diversi è 1
![[Pasted image 20260506124255.png|447]]

Sostituendo i valori calcolati ($b_1=0, b_2=0, b_4=1, b_8=0$) al posto delle `x` nella stringa di partenza, otteniamo il messaggio pronto per essere spedito: **`001100100`**

- **Parte 2**
![[Pasted image 20260506124528.png|319]]
Adesso il destinatario (che non sa ancora se c'è un errore) riesegue la stessa operazione di XOR di prima sugli stessi bit, i risultati trovati vanno confrontati con i bit di controllo (nelle pos. potenze di 2) e se sono uguali non ci sono errori, se sono diversi c'è un errore:
![[Pasted image 20260506124720.png]]

Per trovare il bit errato basta sommare gli indici dei bit di controllo che hanno fallito il test: in questo caso $b_2 + b_4 = b_6$ -> l'errore è in posizione 6. 
**Correzione**
Per correggere semplicemente eseguiamo un bit flip





slide 81
