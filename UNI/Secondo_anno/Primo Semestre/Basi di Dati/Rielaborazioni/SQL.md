(Verranno inserite solo cose riassuntive e generali ma SQL va studiato direttamente dal pdf 5)[[5 lezione7_SQL_I.pdf]]

Sintassi generale Query su SQL 
![[Pasted image 20251014160731.png]]


1) La SELECT implementa gli operatori Ridenominazione Proiezione, Selezione e Join dell’algebra relazionale
2) I comandi SQL non sono case sensitive
3) Possono essere distribuiti in una o più righe
4) Le parole chiave non possono essere abbreviate o spezzate in due linee
5) Clausole sono usualmente inserite in linee separate
6) Se i nomi degli attributi non sono univoci tra le tabelle si deve usare il nome della tabella nella select
   ![[Pasted image 20251014161849.png|399]]
7) E’ consentito dall’uso della parola chiave DISTINCT nella clausola SELECT per eliminare i duplicati
8) ESPRESSIONI ARITMETICHE
   ![[Pasted image 20251014162945.png]]
9) PREDICATI DI CONFRONTO (esempi pag 21 del pdf 5)
   ![[Pasted image 20251014162147.png|400]]![[Pasted image 20251014162206.png|460]]
10) OPERATORI LOGICI
   ![[Pasted image 20251014162916.png]]
11) PRECEDENZE
    ![[Pasted image 20251014163112.png]]
    La modifica delle regole di precedenza è ottenuta con l’uso delle parentesi.
12) La join viene usata per effettuare query su più tabelle
    ![[Pasted image 20251014201658.png]]
    La condizione di join va scritta nella clausola WHERE
13) OPERATORI AGGREGATI
    – AVG – COUNT – MAX – MIN – SUM
14) GROUP BY
    Divide le righe di una tabella in gruppi piu piccoli
15) HAVING
    Esclude gruppi di risultati
16) 


