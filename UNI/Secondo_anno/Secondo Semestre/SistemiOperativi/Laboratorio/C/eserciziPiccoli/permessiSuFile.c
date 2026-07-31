/*Esercizio 3 — Creazione file con permessi controllati
Scrivi un programma che:

Stampa la umask corrente (puoi leggerla/impostarla con umask(), occhio che ritorna la vecchia maschera).
Crea un file con open(..., O_CREAT|O_WRONLY, 0666).
Verifica "manualmente" (stampando in ottale con printf("%o", ...)) che i permessi effettivi non siano 0666 ma 0666 & ~umask.
Prova a cambiare la umask con il comando di shell prima di lanciare il programma e osserva come cambia il risultato.*/

