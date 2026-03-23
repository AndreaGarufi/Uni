Tecnica Estrai metodo -> crea un nuovo metodo che contiene il codice di una parte del metodo iniziale (dividi il metodo grande in tanti metodi piccoli che fanno cose il più basilari possibili)

ragionamento simile per la tecnica estrai classe


ESTRAI METODO
L'obbiettivo è prendere un gruppo di linee di codice di un metodo e farlo diventare un metodo a se stante
Avere metodi piccoli favorisce il riuso di questi piccoli metodi
Quando si fa questa operazione non basta copiare e incollare direttamente bisogna sapere già cosa fare e più o meno già cosa copiare, bisogna vedere se il codice copiato contiene variabili locali e nel caso passarle come parametri e se una variabile del metodo sorgente è modificata dal codice che devo copiare bisogna cercare di capire se è possibile farlo diventare un metodo query per assegnarli quel valore

TEMP E QUERY
Questo metodo conviene usarlo solo se la variabile temporanea è usata una volta solo all'interno del metodo.
Posso prendere un' espressione che mi ritorna un valore e farla diventare un metodo che restituisce quel valore (usata anche quando si usano variabili temporanee (temp)) 
Bisogna cercare una variabile temporanea assegnata una sola volta, dichiarare temp come final per vedere se serve veramente una volta sola e creare il metodo che sostituisce questa variabile temp facendo un return dell'espressione


DIVIDI VARIABILE TEMP
Se ho una variabile temp assegnata più volte (non in un loop) allora posso usare più variabili per separare meglio e rendere più leggibile il codice