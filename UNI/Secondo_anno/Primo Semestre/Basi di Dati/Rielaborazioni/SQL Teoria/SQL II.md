Riassumiamo la sintassi della SELECT:
![[Pasted image 20251030161432.png|700]]


Facciamo un esempio:
![[Pasted image 20251030162023.png]]

Creare una query che restituisca: nome, matricola, voto minimo, voto massimo, voto medio per gli studenti che hanno dato più di 8 materie


`SQL SELECT studenti.nome,studenti.matricola AVG(voto),MIN(voto),MAX(voto)
`FROM studenti, esami
`WHERE studenti.matricola = esami.matricola
`GROUP BY studenti.nome,studenti.matricola
`HAVING COUNT(*) > 8`

Letteralmente prendo nome matricola AVG MIN MAX dove la matricola di studenti combacia con quella di esami, ordino per nome e matricola quello che trovo e poi quando conto tutto deve essere > 8.


