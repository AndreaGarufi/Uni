- Un **modello dei dati** è un insieme di *meccanismi di astrazione* per definire una base di dati, con associato un insieme predefinito di *operatori* e di *vincoli di integrità*
- Questi meccanismi di astrazione rivestono un ruolo equivalente a quello delle strutture dati nella programmazione 

Il modello relazionale dei dati implementa bene il concetto di indipendenza dei dati, è basato sul concetto matematico di **RELAZIONE**

**Relazione: 3 accezioni**

*Relazione matematica:* come nella teoria degli insiemi

*Relazione* secondo il modello relazionale dei dati

*Relazione* che rappresenta una classe di fatti, nel modello Entità-Relazione; tradotto anche con associazione o correlazione


**Relazione matematica esempio**

$D_1=\{a,b\}$
$D_2=\{x,y,z\}$
prodotto cartesiano $D_1$ x $D_2$   

| prodotto | cartesiano |
| -------- | ---------- |
| a        | x          |
| a        | y          |
| a        | z          |
| b        | x          |
| b        | y          |
| b        | z          |

una relazione è un sottoinsieme del prodotto cartesiano $r⊆ D_1$ x $D_2$  
(scelgo solo alcuni elementi del prodotto cartesiano)

| relazione |     |
| --------- | --- |
| a         | x   |
| a         | y   |
| b         | z   |

possiamo fare un prodotto cartesiano tra $n$ insiemi ($D_1 ... D_n$) e scegliere una relazione su di essi (r è un ⊆ del prodotto cartesiano) 
$D_1 ... D_n$ sono i domini della relazione

Prodotto cartesiano = $D_1$ x ... $D_n$ e avremo l’insieme di tutte le n-uple ($d_1$ , …, $d_n$) tali che
$d_1∈D_1$ , …, $d_n ∈ D_n$ 


**Proprietà**
**Una relazione è un insieme di n-uple ordinate:**
– ($d_1$ , …, $d_n$) tali che $d_1∈D_1$ , …, $d_n ∈ D_n$

**Una relazione è un insieme dove:**
1) non c'è ordinamento fra le n-uple 
2) le n-uple sono distinte 
3) ciascuna n-upla è ordinata: l’ i-esimo valore proviene dall’i-esimo dominio 


**Struttura Posizionale**
Partite ⊆ stringa × stringa × intero × intero
(la relazione partite ha 4 domini)

|       |       |     |     |
| ----- | ----- | --- | --- |
| Juve  | Lazio | 3   | 1   |
| Lazio | Milan | 2   | 0   |
| Milan | Roma  | 3   | 2   |
| Juve  | Milan | 4   | 1   |

**Ciascuno dei domini ha ruoli diversi, distinguibili attraverso la posizione:**
**Questa è una struttura posizionale**

**Struttura non Posizionale**

A ciascun dominio si associa un nome unico nella tabella (attributo), che ne descrive il "ruolo"

| casa  | Fuori | GolCasa | GolFuori |
| ----- | ----- | ------- | -------- |
| Juve  | Lazio | 3       | 1        |
| Lazio | Milan | 2       | 0        |
| Milan | Roma  | 3       | 2        |
| Juve  | Milan | 4       | 1        |


**Schema di relazione**
Uno schema di relazione $R : \{T\}$ è una coppia formata dal nome di una relazione $R$ e da un tipo relazione $T$

Significa che $R$ è il nome della relazione e $T$ è il tipo della relazione, cioè il prodotto cartesiano dei domini che la compongono
Esempio:   *Studenti:{stringa×intero}*

**Definizioni Tipi relazione**
*Interi, Reali, Booleani, Stringhe* sono tipi primitivi
Siano $T_1$ , $T_2$ , …, $T_n$ tipi primitivi e $A_1$ , $A_2$ , …, $A_n$ etichette, dette attributi, allora 
($A_1 :T_1$ , $A_2 :T_2$ , …, $A_n :T_n$) **è un tipo n-upla di grado $n$**

**Schema Relazionale**
Uno schema relazionale è costituito da: 
- un insieme di schemi di relazione $R_i$ : $\{T_i\}$, i=1, 2,…, k 
- un insieme di vincoli di integrità relativi a tali schemi
(una cosa simile allo schema $E-R$)
infatti lo schema relazionale costituisce il livello intensionale

**La cardinalità** di una relazione è il numero di n-uple (in pratica quante **righe** ha la tabella)
esempio:
![[Pasted image 20251002155704.png|270]]
cardinalità = 4


![[Pasted image 20251002155953.png]]
Seguendo questo schema: $A_1 :T_1$ , $A_2 :T_2$ , …, $A_n :T_n$
Nome : stringa , Matricola : intero , Indirizzo : stringa , Telefono : intero
e ha cardinalità 4

Ciascuna riga è una n-upla della relazione

**Esempio di schema relazionale**
![[Pasted image 20251002160238.png]]


**Dominio di un attributo**
$dom(A_i)$ è l’insieme dei possibili valori dell’attributo $A_i$
esempio $A_1$ = voto 
$dom(A_1)=\{18 ...30\}$


**Vincoli di integrità**
I vincoli di integrità servono a migliorare la qualità delle informazioni contenute nella base di dati
- Un vincolo è un predicato che deve essere soddisfatto da ogni n-upla nella base di dati
- Un’istanza valida di uno schema di relazione è una relazione dello schema che soddisfa tutti i vincoli di integrità

Esempio:
Il voto deve essere compreso tra 18 e 30
per avere la lode il voto deve essere uguale a 30 ecc...

Ci sono vari tipi di vincoli va i 3 importanti sono:
![[Pasted image 20251002161829.png]]

(alcuni attivbuti se non vincolati possono anche essere NULL)



**CHIAVI**
- Un insieme $X$ di attributi di uno schema di relazione $R$ è una superchiave dello schema se ogni istanza valida dello schema non contiene due n-uple distinte $t_1$ e $t_2$ con $t_1 [X]$ = $t_2 [X]$ 
- Una chiave è una superchiave minimale rispetto alla relazione ⊆ (non contiene un’altra superchiave).

Esempio:
![[Pasted image 20251002162305.png]]


**Esistenza delle chiavi**
• Una relazione non può contenere n-uple distinte ma uguali (significa che non può avere righe che siano uguali tra loro)
• Ogni relazione ha come superchiave l’insieme degli attributi su cui è definita e quindi ha (almeno) una chiave


- **L'esistenza delle chiavi garantisce l'accessibilità a ciascun dato del database**

- La **Chiave Primaria** è una delle chiavi scelta per un dato schema. 
- Non ammette valori NULL![[Pasted image 20251002162942.png]]

**Chiave Esterna**
• Un insieme di attributi {$A_1$, $A_2$ , …, $A_n$} di uno schema di relazione $R$ è una chiave esterna che riferisce una chiave primaria {$B_1$, $B_2$ , …, $B_n$}

![[Pasted image 20251003184139.png]]

Esercizio: 
Definire uno schema relazionale per organizzare le informazioni di un’azienda che ha impiegati (ognuno con codice fiscale, cognome, nome e data di nascita), filiali (con codice, sede e direttore, che è un impiegato). Ogni lavoratore lavora presso una filiale. Indicare le chiavi e i vincoli di integrità referenziale dello schema. Mostrare un’istanza della base di dati e verificare che soddisfa i vincoli. 
![[Pasted image 20251003185430.png]]


Esercizio:
Un albero genealogico rappresenta, in forma grafica, la struttura di una famiglia (o più famiglie, quando è ben articolato). Mostrare come si possa rappresentare, in una base di dati relazionale, un albero genealogico, cominciando eventualmente da una struttura semplificata, in cui si rappresentano solo le discendenze in linea maschile (cioè i figli vengono rappresentati solo per i componenti di sesso maschile) oppure solo quelle in linea femminile.
![[Pasted image 20251003190330.png]]