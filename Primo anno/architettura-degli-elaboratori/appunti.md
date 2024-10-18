INTR sospende il ciclo CPU ed è un interrupt per una periferica (la CPU si dedica alle richieste della periferica)
L' Op. code serve a identificare in modo UNIVOCO un istraction set. le IS possono avere diverse lunghezze (ad esempio se ci sono tanti operandi 8+9+7+5+4+3 ecc...)
la CPU esegue dei cicli di bus (FETCH DECODE EXCUTE STORE).


Il tempo di effettiva esecuzione del microprogramma influisce relativamente sulla durata dell'istruzione, essendo il clock di CPU di almeno un ordine di grandezza superiore al clock di bus. (perché il clock della CPU è almeno 10 volte più veloce di quello del bus (bottleneck) e quindi gli sta sempre aventi)

i PC trattano in modo diverso i numeri Naturali e i numeri reali(virgola) (usano una FPU)

nei CISC i microprogrammi e microcodici sono interpretati prima dell'esecuzione 
all' orale potrebbe chiedere di disegnare l'architettura cisc/risc

la cache serve per non passare dal bus e rimanere dentro la cpu (cosi si evita il bottleneck).
l1 l2 dentro CPU l3 sulla scheda madre (quando si compra un PC sarebbe buona cosa controllare quanta cache c'è dentro alla CPU e sulla motherboard).

gli elaboratori hanno un' architettura a 3 livelli 1)hardware- 2)sistema operativo- 3)applicazioni software
le istruzioni dei risc sono almeno più veloci dei cisc (per questo erano spesso usate nei server)
adesso le CPU sono ibride e si hanno sia i vantaggi di cisc che di risc

nei risc i PROGRAMMI sono più lunghi ma le istruzioni sono più CORTE nei cisc al contrario

il problema dei risc è la compatibilità dei codici infatti non è detto che tutti i codici funzionino in tutte le cpu risc, inoltre sono difficili da programmare in assembly (è un livello molto basso)

