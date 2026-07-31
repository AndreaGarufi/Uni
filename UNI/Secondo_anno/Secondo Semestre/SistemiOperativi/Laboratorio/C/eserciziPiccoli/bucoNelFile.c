/*Esercizio 4 — Buco nel file (sparse file)
Scrivi un programma che:

Apre/crea un file.
Scrive la stringa "inizio" all'offset 0.
Si sposta con lseek all'offset, ad esempio, 100000 (senza scrivere nulla lì).
Scrive la stringa "fine".
Chiude il file.
Poi da shell controlla:
ls -l nomefile      # dimensione "logica"
du -h nomefile      # spazio realmente occupato su disco

Dovresti vedere che ls -l riporta una dimensione grande (~100KB) ma du mostra che i blocchi realmente allocati sono molti meno — il "buco" non occupa spazio reale.*/

