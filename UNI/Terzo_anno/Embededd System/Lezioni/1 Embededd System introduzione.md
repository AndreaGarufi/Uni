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

