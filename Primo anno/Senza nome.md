esame 
una delle tecniche per eliminare i problemi delle dipendenze sono i NOP.
(pone in stallo le istruzioni) 
NOP è un istruzione vuota o inattiva che non esegue operazioni, occupa uno slot nel flusso delle istruzioni senza effettuare alcun calcolo o modifica nello stato del processore. è utilizzata per allineare le operazioni nella CPU . (serve per temporeggiare creando dei ritardi controllati) 



PROBLEMA
ritardi della memoria
i principali ritardi della memoria si possono verificare :
le memorie hanno una propria latenza costruttiva (memory access latency) il tempo necessario ad accedere ai dati contenuti nella memoria, influisce anche la velocità del bus

impatto nel pipelining : la CPU deve attendere che i dati vengano recuperati dalla memoria ,quindi la pipeline subisce un rallentamento.

overhead = sovrapprezzo da pagare (in termini di tempo in questo caso)

tecniche per limitare i ritardi:

1 gerarchia delle cache (prima si va alle cache più vicine e poi quelle più lontane (L1 L2 L3))
2 pre-fetching (carica in anticipo i dati nella cache)
3 produrre memorie RAM con latenza più bassa



	PROBLEMA   metti i vari collegamenti con l'altra nota
i salti
nei processori moderni i salti , nel pipelining introducono grossi ritardi (brench penalties/delays)
tecniche per limitare questi ritardi 

1 brench prediction (fa uso della predizioni di istruzioni di salto per anticipare una brench penalties basandosi sui brench penalties precedenti e lo storico delle altre istruzioni, se la predizione è sbagliata si ha un brench prediction miss. in quel caso esegue il flushing ovvero la pulizia della pipeline per evitare che si eseguano istruzioni errate ) (esecuzione speculativa)

predizione statica utilizza regole semplici basate su informazioni statiche come la posizione di istruzioni nel codice oppure il tipo di istruzione di salto, per prevedere se il brench verrà preso o no, questo approccio statico è rapido, semplice ma meno preciso in caso di situazioni complesse. In queste situazioni si usa la predizione dinamica
predizione dinamica è basata sulla storia dei branch precedenti, quindi utilizza i brench prediction buffer o tabelle di predizione di branch per memorizzare il comportamento passato dei brench. i moderni processori utilizzano dei metodi di predizione come i predittori a 2 livelli o predittori neurali per migliorare l'accuratezza delle predizioni.





