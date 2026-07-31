/*Esercizio 1 — Copia file "a mano" (mycp)
Scrivi un programma mycp sorgente destinazione che copia un file usando solo open, read, write, close (niente fopen!).

Apri la sorgente in sola lettura.
Crea/apri la destinazione in scrittura con permessi 0644, troncandola se esiste già.
Copia a blocchi (es. buffer da 4096 byte) finché read non ritorna 0.
Gestisci gli errori con perror e termina con EXIT_FAILURE/EXIT_SUCCESS.*/

