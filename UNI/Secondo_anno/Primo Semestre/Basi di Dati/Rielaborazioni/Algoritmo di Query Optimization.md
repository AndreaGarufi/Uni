• Due espressioni sono equivalenti se producono lo stesso risultato qualunque sia l'istanza attuale della base di dati 
• L'equivalenza è importante in pratica perché i DBMS cercano di eseguire espressioni equivalenti a quelle date, ma meno "costose"

**Esempio**
Push selection (se A è attributo di $R_2$)
![[Pasted image 20251014155616.png|400]]
Riduce in modo significativo la dimensione del risultato intermedio (e quindi il costo dell'operazione) 


• Supponiamo che vogliamo trovare: 
• tutti i professori che hanno dato a Mario Rossi più di 27
![[Pasted image 20251014155752.png]]

**Regole per la quey optimization**
Anticipare l’applicazione delle proiezioni e delle restrizioni rispetto al prodotto (e quindi alle giunzioni), in modo da ridurre la dimensione delle tabelle a cui applicare il prodotto (e le giunzioni)

(regole complete al power point 4) [[4 AlgebraRelazionaleOttimizzazioneQuery.pdf]]

