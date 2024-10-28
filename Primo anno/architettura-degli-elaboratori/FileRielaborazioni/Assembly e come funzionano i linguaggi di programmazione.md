
Il programmatore scrive i programmi in **LINGUAGGIO ASSEMBLATIVO (ASSEMBLY)**

Il programma assemblativo viene tradotto in sequenze binarie dall’ **ASSEMBLATORE (ASSEMBLER)**

Il **COMPILATORE** traduce il codice ad alto livello in codice assemblativo

![[Pasted image 20241028201958.png|400]]

**GENERAZIONE PROGRAMMA OGGETTO**

1) Il **COMPILATORE** **trasforma una serie di file sorgenti di linguaggio ad alto livello in file sorgenti assembly**

2) L **’ASSEMBLATORE trasforma una serie di file sorgenti assembly** (generati dal compilatore o scritti direttamente da un programmatore) **in file oggetto**
 
3) **Il LINKER collega assieme vari file oggetto e file di libreria in un unico programma oggetto** (un file oggetto potrebbe usare dei sottoprogrammi definiti in altri file oggetto o di libreria)
   
 **PROCESSO DI COMPILAZIONE DI ASSEMBLY**
1. Analisi lessicale: identificazione dei token / keyword
2. analisi sintattica: identifica eventuali errori grammaticali come per esempio l'utilizzo di una variabile non allocata
3. traduzione istruzioni
4. risoluzione delle etichette
5. generazione file oggetto
6. ottimizzazione (passo opzionale)

**ASSEMBLATORE A 2 PASSI**

1) Primo passo
		1.  raccoglie i nomi delle etichette
		2. raccoglie i valori associati alle etichette
		3. raccoglie indirizzi
		4. creazione tabelle simboli
		
2) Secondo passo
   1. si scorre il codice sorgente sostituendo i simboli con i valori in tabella
   2. crea il codice oggetto

**VANTAGGI**
è modulare
gestione accurata dei simboli
migliora il debugging

**SVANTAGGI**
è più lento

**LOADER**
Loader statico -> carica tutto il programma in memoria
Loader dinamico -> carico solo le parti del programma che devo usare
Bootstrap loader -> carico il sistema operativo in memoria all'avvio del PC

**LINKER**
è un programma essenziale nel processo di trasformazione in codice binario, questo lo fa generando un file oggetto che collega tutti gli altri file oggetti creati

**LIBRERIE**
sono contenitori di file che raggruppano oggetti tutti dello stesso tipo




  








