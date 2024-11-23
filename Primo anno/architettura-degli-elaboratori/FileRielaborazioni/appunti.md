# 20_11_24

le porte nand a più ingressi sono un estensione delle porte nand a 2 ingressi . **regola** l'uscita è falsa solo se tutti gli ingressi sono 1, in tutti gli altri casi l'uscita è sempre vera

a cosa servono le porte nand a più ingressi? serve perche si ha un numero più grande di ingressi, (gestisce gli ingressi) quindi una porta nand a n ingressi può gestire n input.

nelle porte nand a n ingressi, l'uscita è falsa (0) solo se tutti ingressi sono veri in tutti gli altri casi le uscite sono vere


**CIRCUITI ARITMETICI**
HALF ADDER
addizonatore a 1 bit è un circuito logico che somma 2 bit (A e B) considerando anche un possibile riporto in ingresso e uscita, produce 2 uscite (il valore della somma e il bit di riporto).

la somma si può ottenere utilizzando 2 porte XOR, la prima calcola A $\oplus$ B, la seconda prende il valore trovato prima + il riporto dell'operazione precedente (queste cose si utilizzano nelle ALU dei processori più datati)


FULL ADDER
è un circuito logico che somma 3 bit, 2 in ingresso e un riporto in ingresso, produce 2 uscite, una somma e un riporto in uscita (che viene passato all'addizionatore successivo)

ADDIZIONATORE A PROPAGAZIONE DI RIPORTO (CLA CARRY LOOKAHEAD ADDER)
è un addizionatore avanzato, fatto per migliorare la velocita della somma, riducendo i tempi di propagazione del riporto
in addizionatore tradizionale il riporto viene calcolato in modo sequenziale (rallenta la somma se sono tanti bit).
cosa fa? calcola i riporti in modo più rapido 
come fa? utilizza 2 concetti chiave: 
1) la generazione del riporto (G), (il riporto viene generato quando entrambi gli addendi sono  1)
2) propagazione del riporto (P), si verifica quando il riporto si deve sommare ai 2 valori e almeno uno è 1
è possibile calcolare i riporti in modo parallelo anziché sequenziale (quindi possiamo migliorare le performance dell' adder)

il vantaggio è: la velocità

come si realizza?
utilizza una rete di porte logiche AND OR XOR che calcolano rapidamente i segnali di P e G e determinare il riporto per ogi bit della somma da effettuare, viene utilizzato nei ciruciti ad altissime prestazioni (utilizzati nelle ALU dei moderni processori)

TRABOCCO(overflow)
quando il riporto va oltre il massimo di bit avrò un trabocco (se ho un bicchiere e lo riempio con troppa acqua l'acqua esce) si verifica quindi quando un riporto non può essere gestito perché va oltre la capacità massima di quel circuito aritmetico (es. se finisco lo spazio nel registro, es. se ho 4 bit e mi si genera un riporto nel 4 bit avrò un trabocco) 

come si gestisce?
ADDIZIONATORE ALGEBRICO A n BIT
è un circuito logico che somma 2 numeri binari a n bit e gestisce anche il segno dei numeri permettendo l'addizione dei numeri interi con segno che si rappresenta con il complemento a 2
(ripassa il complemento a 2) 
gestisce il riporto, il segno e il trabocco

abbiamo n uscite, il carry out (riporto) e il riporto finale può essere utilizzato per capire se c'è stato un overflow

CIRCUITO PER GESTIRE IL RITARDO
il ritardo totale dipende dal ritardo del percorso più lento, quindi il circuito si adatta alla velocità più lenta

GESTIONE DEI RITARDI CON IL RIPPLE CARRY ADDER (RCA)
è un tipo di addizionatore utilizzato nei circuiti digitali per sommare 2 numeri binari a più bit, utilizza addizionatori a 1 bit oppure quelli completi concatenati tra loro per eseguire la somma bit per bit.
ripple significa che il riporto si propaga bit per bit come un onda

il ritardo di un RCA è causato dalla "propagazione dell'onda" 
qui c'è dipendenza di dato

vantaggi : è semplice da realizzare
svantaggio: ritardo ([{mentale}]) 

in sintesi RCA è un tipo di addizionatore a più bit in cui i riporti si propagano in tutti i bit successivi causando ritardi che crescono in modo proporzionale alla lunghezza del numero da sommare

# 22_11_24

generazione del riporto determina ....

la generazione del riporto si verifica quando entrambi i bit sono uguali a 1

G = Xi * Yi    P = Xi + Yi

propagazione determina se il riporto in ingresso verrà propagato al bit successivo

il calcolo del riporto può essere parallelizzato, questo permette di svincolarsi dalla sequenzialità del riporto
come si fa? per parallelizzarlo si utilizzano delle tecniche che riducono il ritardo che porta il calcolo del riporto

CELLA DI STADIO DA UN BIT (FULL ADDER BIT CELL in iglish of cors)
è un componente fondamentale in un addizionatore completo a n bit (è quello che fa la somma)
come funziona? 
ogni stadio dell' addizionatore a n bit si occupa di sommare 2 bit e 1 riporto in ingresso e fornire un eventuale riporto in uscita
una cella di stadio da un bit riceve 2 input, il primo bit e Xi il secondo è Yi, Ci è il carry in (riporto della somma precedente)

CARRY LOOKAHEAD ADDER (addizionatore con anticipo di riporto a 4 bit)
migliora la velocità della somma riducendo il ritardo, l'anticipo del riporto permette di calcolare in parallelo i riporti
come è fatto?
utilizza anche lui P e G

ADDIZIONATORE CON ANTICIPO A 2 LIVELLI (versione ottimizzata di CLA)
riduce ulteriormente il tempo di calcolo utilizzando una struttura a più livelli per calcolare i riporti in parallelo, i calcoli vengono eseguiti su 2 livelli logici distinti, permettendo di ridurre la profondità di rete di calcolo (ovvero il numero di stadi che deve affrontare il calcolo)

combina più bit in gruppi e calcolare i riporti su un altro livello, in pratica prendiamo la struttura di un CLA e lo sdoppiamo su 2 livelli

per parallelizzare si usa G e P (come in tutti gli adder che parallelizzano) 

**il primo** livello si occupa di calcolare le funzioni G e P 
**il secondo** calcola i riporti

ADDIZIONATORE CON ANTICIPO DI RIPORTO A 16 BIT
è un tipo di addizionatore che utilizza un meccanismo di calcolo dei riporti rispetto a RCA per ridurre i tempi del calcolo del riporto
riportiamo tutti i riporti nei 16 bit che abbiamo a disposizione, usa anche lui G e P

MOLTIPLICATORE SEQUENZIALE
è un tipo di moltiplicatore che esegue la moltiplicazione in più fasi utilizzando una sorta di algoritmo (un approccio top-down), invece di calcolare il risultato della moltiplicazione in un unico ciclo, sfrutta i registri per memorizzare i risultati parziali.
ha un vantaggio rispetto al moltiplicatore parallelo ovvero riduce la complessità hardware (costa meno), in ogni caso le performance di un moltiplicatore parallelo sono migliori.

questi moltiplicatori sequenziali si trovano nei vecchi processori o nelle CPU a basso costo
come è fatto? (c'è sul power point slide 17) **può chiederlo agli esami**

ricodifica bit-pair
è una tecnica di compressione dei dati utilizzata per ridurre la lunghezza di una sequenza di bit senza perdere informazioni(raggruppa i bit in coppie (bit-pair))
questa tecnica e utile per ottimizzare l'uso della memoria

(algoritmo di divisione algebrica in poi non è da fare, verso le ultime slide dopo ieee 754)

--------------------------------------
nuovo power point (assembly)

cosa è una memory word --**esame** 
è la dimensione del' unita di dato che un sistema di elaborazione può gestire e memorizzare in un singolo ciclo di clock di una cpu, varia in base a se l'architettura è a 8,16,32,64 bit, 
queste memory word vengono lette e scritte dalla memoria RAM
viene gestita come vettori di memory word
ogni word ha quindi un indirizzo in memoria


