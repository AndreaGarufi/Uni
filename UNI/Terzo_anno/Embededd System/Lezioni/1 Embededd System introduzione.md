
# **Introduzione**

Un **Embededd system** è un dispotivo creato per rispondere a esigenze specifiche.
- Domatica
- IOT
- Settore auto
- Dispositivi in casa come TV non smart, lavatrici ecc...
- Settore industriale come la gestione di vari sensori ecc...

Gli embededd system sono generalmente composti usando i **microcontrollori**

**Microcontrollore**
Un microcontrollore è a tutti gli effetti un piccolo computer e anche lui ha quindi principalmente le stesse componenti:
Includono quindi :
- una piccola CPU
- memoria RAM (pochi megaBytes)
- memoria flash (poche megaBytes)
- un oscillatore per il clock

![[Pasted image 20261002140201.png|489]]




**Differenza tra microcontrollori e microprocessori**
Nel microcontrollore i pin corrispondono alle periferiche di I/O, mentre nei microprocessori i pin sono collegamenti con il bus.

In alcuni microcontrollori ci sono anche delle parti relegate all'esecuzione di piccoli modelli di IA (non LLM) ma ad esempio riconoscimento facciale o di oggetti.

**Sistemi operativi nei microcontrollori**
Generalmente i software che programmiamo per i microcontrollori partono direttamente (bare metal) senza sistema operativo, non ci sono quindi tutte quelle componenti come bios, SO, file system ecc... siamo noi quindi a essere a contatto diretto con l'hardware.

In alcuni casi riescono a far girare dei micro SO cioè un piccolo kernel capace di fornire un minimo di astrazione o ad esempio un layer di driver o un piccolo scheduler.

Quando il SO non è compreso nel microntrollore è il programmatore che deve occuparsi di programmare anche le periferiche.
![[Pasted image 20261002140614.png|496]]

un programma è fatto principalmente da 3 cose:

1) inizializzazione delle perififeriche
2) fase di input in cui si leggono dati provenienti dalle periferiche
3) eleborare i dati e fornire una risposta e poi ricomincia da capo
(effettivamente è come programmavamo arduino alle superiori).

C'è anche una parte di "costruzione" delle interrupt service routine
![[Pasted image 20261002140614.png|581]]

**Ambiente di sviluppo e compilazione**
Si programma su un qualsiasi editor (noi useremo VS code) ma si utilizzano dei compilatori particolari che non compilano per il nostro normale PC ma compilano per adattarsi al microcontrollore, poi si prende il file binario generato e si carica sul microcontrollore.

C'è una parte del microcontrollore che si occupa di prendere il file binario passato da noi e lo da al microprocessore principale del microcontrollore, questa parte serve anche per fare debugging.
![[Pasted image 20261002113351.png|359]]

La parte in questione è la parte in alto "separata" da quella più in basso (dove c'è la USB gialla).

La scheda in foto è la ST NUCLEO-F401RE che è quella che noi useremo nel corso.
In particolare le specifiche sono queste:
![[Pasted image 20261002141007.png|570]]

Una certa zona di memoria è riservata per le periferiche e in quella zona ogni locazione ha un particolare significato, ogni regione si chiama **SPECIAL FUNCTION REGISTERS (SFRs)**.
Quindi leggere o scrivere da quelle locazioni implica che la periferica legata a quella locazione abbia un senso e sia stata programmata.

*Come si accede alle SFRs?*
Si accede tramite puntatori C, ma dato che usare tutti questi puntatori introduce complessità, si usano delle librerie che forniscono un aiuto, ovvero forniscono delle variabili globali in cui è mappata la locazione di memoria associata a ciascuna periferica.

**Librerie**
Le librerie sono utili perché rendono la programmazione più semplice.
Noi useremo una libreria creare da unict per interfacciarci facilmente all'inizio.

![[Pasted image 20261002141537.png|228]]

![[Pasted image 20261002141637.png|631]]

---

# **Circuiti Logici**
I circuiti logici sono caratterizzati dal fatto che il voltaggio sui cavi può essere solo:
- $0\,\, V$ -> valore 0/bit 0
- $+ Vdd$ -> valore 1/bit 1

Dove $Vdd$ è il power supply dell'intero circuito, può essere 5V, 3.3V, 1.8V ecc...

---

##### Circuiti combinatori

Sono dei circuiti il cui output dipende solo dal valore della tensione in ingresso.

*Porte logiche*
Le porte logiche sono un tipo di circuiti combinatori.
![[Pasted image 20261005123849.png|661]]

*Multiplexer*
I multiplexer sono altri circuiti combinatori che hanno lo scopo di switchare il segnale in base al valore in input e al valore dei control input bits:
![[Pasted image 20261005124028.png|662]]



*Circuiti sequenziali*
- Sono circuiti il cui output dipende solo dallo stato attuale e passato degli input
- Sono quindi sensibili alle variazioni degli input
- Sono circuiti logici che hanno una memoria
![[Pasted image 20261005124751.png|527]]


# **Segnali logici**
Si dividono in segnali costanti e segnali variabili.
- I segnali costanti restano uguali nel tempo
- I segnali variabili possono cambiare e sono caratterizzati da degli "edges" ovvero dei fronti.

si può avere un falling edge ovvero una variazione da 1 a 0 oppure si può avere un rising edge ovvero una variazione da 0 a 1.
![[Pasted image 20261007104351.png]]

**Circuiti sequenziali e edges**
I circuiti sequenziali sono sensibili agli edges e nelle rappresentazioni grafiche gli edges sono rappresentati da dei triangoli:
Triangolo normale = rising edge
Triangolo + cerchio = falling edge
![[Pasted image 20261007104543.png|479]]

##### Segnali periodici
Sono un particolare tipo di segnali variabili la cui caratteristica è che la distanza in termini di tempo tra 2 edges è sempre la stessa:
![[Pasted image 20261007104724.png|491]]

Questa distanza è chiamata *periodo* (P) ed è misurata in secondi.
La *frequenza* è il numero di periodi per secondo ed è calcolata come: $f=\frac{1}{P}$ , si misura in Hertz (Hz)

I segnali periodici possono essere di 2 tipi:
- Simmetrici
- Asimmetrici

*Simmetrici*
La distanza temporale tra lo stato 0 e lo stato 1 è la stessa ed è uguale: $T_0 = T_1 = \frac{P}{2}$
![[Pasted image 20261007105156.png|351]]

*Asimmetrici*
La distanza temporale tra lo stato 0 e lo stato 1 è diversa: $T_0 \neq T_1$ 
![[Pasted image 20261007105325.png|355]]

L'asimmetria è chiamata *duty cicle* e rappresenta la durata percentuale di periodo in cui lo stato è 1
$$
DC = \frac{T_1}{T_0 + T_1} \cdot 100 = \frac{T_1}{P} \cdot 100
$$

---

![[Pasted image 20261007105537.png|649]]

