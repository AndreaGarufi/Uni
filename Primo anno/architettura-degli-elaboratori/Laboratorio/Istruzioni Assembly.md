
DCD e EQU :

| Caratteristica      | DCD                           | EQU                                  |
| ------------------- | ----------------------------- | ------------------------------------ |
| memoria riservata   | Si, riserva spazio in memoria | No, è solo una definizione simbolica |
| scopo               | Dichiarare variabili          | Definire costanti simboliche o alias |
| esempio pratico     | num1 DCD 2                    | num2 EQU 2                           |
| utilizzo nel codice | Usato per accedere ai dati    | Usato come sostituzione simbolica    |

in pratica uso EQU per rendere il codice più leggibile ma potrei direttamente assegnare un valore immediato  es.

num2 EQU 10

cmp r3,#costante           (o anche cmp r3,#10 senza dichiarare la variabile)

