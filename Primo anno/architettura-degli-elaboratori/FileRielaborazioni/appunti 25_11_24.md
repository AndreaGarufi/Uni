l'indirizzamento è quell'operazione che attribuisce ad un valore un indirizzo di memoria, in modo che possa essere trovato dalle operazioni che lo richiedono (la CPU legge o scrive dati nell'indirizzo corrispondente) 

nel big-endian il byte più significativo è memorizzato all'indirizzo più basso, mentre nel little-endian è il byte meno significativo a essere messo nell'indirizzo più basso

in sintesi l'indirizzamento permette di localizzare ogni byte in memoria mentre l'ordinamento di questi byte denota come sono strutturate le words

ISA 
è l'interfaccia tra il software e l'hardware del PC definisce il set di istruzioni che una CPU può eseguire, quanti tipi ne esistono?
questo insieme di istruzioni include operazioni logiche, aritmetiche, controllo, ecc... ogni CPU ha il proprio set ISA (CISC o RISC) 

i programmi si eseguono cosi (di solito (es. C))
LINGUAGGIO ALTO LIVELLO --> compilatore --> LINGUAGGIO MACCHINA --> assemblatore --> LINGUAGGIO MACCHINA BINARIO

il set di comandi di assembly è leggermente diverso tra CISC e RISC proprio perchè camabia l'ISA (esistono anche assembly generici) 

CI SONO DIFFERENZE TRA REGISTRI E CACHE
i registri sono più veloci e immediatamente accessibili dalla CPU, ma visto che la loro capacita è limitata (poche decine di bit), la memoria cache aiuta perche anche se è più lenta (rimane comunque velocissima) ha qualche megabyte di spazio
i registri vengono usati per salvare dati temporanei e operazioni nella ALU, somme parziali ecc... 
la cache invece memorizza i dati delle istruzioni che vengono eseguite tante volte, riducendo quindi il tempo di accesso a questi dati. è suddivisa in 3 livelli (l1 l2 l3) man mano che scendiamo di livello aumenta lo spazio ma diminuisce la velocità.

DIRETTIVE ASSEMBLATORE 
sono istruzioni che non vengono tradotte in linguaggio macchina, le direttiva aiutano, ma non influenzano l'esecuzione del programma (chiedi a chatgpt)

SINTASSI ASSEMBLY
ETICHETTA     OPERAZIONE      OPERANDI      COMMENTO
facoltativa                                                              facoltativa

esame -> può chiedere come funziona lo stack in assembly , come si fa una push e un pop

