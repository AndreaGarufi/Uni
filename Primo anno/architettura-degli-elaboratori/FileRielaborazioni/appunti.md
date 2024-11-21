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
