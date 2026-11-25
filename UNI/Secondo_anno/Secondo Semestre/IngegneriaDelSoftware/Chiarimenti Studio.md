Chiarimenti sul PDF ![[studio.pdf]]

### Java imperativo VS Java funzionale (cap. 6 pag 60)
##### 1. Approccio Imperativo (Come farlo)
In questo stile, descrivi **passo dopo passo** come il computer deve eseguire l'operazione, gestendo manualmente lo stato (le variabili che cambiano) e i cicli.
```
import java.util.List;

public class EsempioImperativo {
    public static void main(String[] args) {
        List<Integer> numeri = List.of(1, 2, 3, 4, 5, 6);
        
        // 1. Inizializziamo una variabile mutabile per lo stato
        int sommaQuadrati = 0;

        // 2. Iteriamo esplicitamente sulla collezione
        for (Integer n : numeri) {
            // 3. Controlliamo la condizione
            if (n % 2 == 0) {
                // 4. Trasformiamo e mutiamo lo stato
                sommaQuadrati += n * n;
            }
        }

        System.out.println(sommaQuadrati); // Output: 56 (4 + 16 + 36)
    }
}
```

### 2. Approccio Funzionale (Cosa ottenere)

Introdotto con Java 8 tramite la **Stream API** e le **Lambda Expressions**. Qui non gestisci indici o variabili d'appoggio: dichiari una pipeline di trasformazioni su dati immutabili.
```
import java.util.List;

public class EsempioFunzionale {
    public static void main(String[] args) {
        List<Integer> numeri = List.of(1, 2, 3, 4, 5, 6);

        int sommaQuadrati = numeri.stream()         // Crea un flusso di dati
                .filter(n -> n % 2 == 0)            // Filtra solo i pari
                .mapToInt(n -> n * n)               // Trasforma ogni numero nel suo quadrato
                .sum();                             // Riduce tutto a una somma

        System.out.println(sommaQuadrati); // Output: 56 (4 + 16 + 36)
    }
}
```

### Differenze chiave

|**Caratteristica**|**Java Imperativo**|**Java Funzionale**|
|---|---|---|
|**Focus**|Sul controllo del flusso (`for`, `if`)|Sulla trasformazione dei dati (`filter`, `map`)|
|**Stato**|Mutabile (`sommaQuadrati` viene sovrascritta)|Immutabile (nessuna variabile esterna modificata)|
|**Parallelismo**|Complesso (richiede gestione manuale dei thread)|Banale (basta sostituire `.stream()` con `.parallelStream()`)|
|**Leggibilità**|Ottima per logiche semplici; tende a diventare verbosa con molte condizioni|Molto vicina al linguaggio naturale; si legge come una sequenza di passaggi logici|

---

### Sintassi e concetti di Java funzionale

Lo `Stream` non crea copie profonde degli oggetti contenuti nella lista: trasporta semplicemente i **riferimenti (puntatori)** agli stessi oggetti che si trovano in memoria, quindi fare delle modifiche ad uno stream implica che i dati originali vengano modificate perché a tutti gli effetti io lavoro su quei dati ad un livello di astrazione più alto.

##### 1. La struttura "a catena" (Method Chaining)
In Java, quando un metodo restituisce un oggetto, puoi chiamare subito un altro metodo usando il punto (`.`). Qui stiamo creando una **catena di montaggio** (pipeline) dove l'output di una riga diventa l'input della riga successiva.

```
numeri.stream()      // Restituisce uno Stream
      .filter(...)   // Prende lo Stream, lo filtra e ne restituisce uno nuovo
      .mapToInt(...) // Prende lo Stream filtrato, lo trasforma e restituisce un IntStream
      .sum();        // Prende l'IntStream e restituisce il numero finale (int)
```

##### 2. Le Lambda Expressions: `n -> n % 2 == 0`
La freccia `->` è il cuore della sintassi funzionale. Serve a scrivere una **funzione anonima** (senza nome) al volo, invece di dover creare un metodo classico.

Si legge: **"Dato un elemento `n`, esegui questa operazione su di esso"**.

- **Parte sinistra (`n`):** È il parametro di input. Rappresenta il singolo elemento della lista che sta passando in quel momento nella catena. Il nome `n` è arbitrario (avresti potuto scrivere `numero -> numero % 2 == 0`). Java capisce da solo che `n` è un `Integer` perché `numeri` è una lista di `Integer`.
- **La freccia (`->`):** Separa l'input dalla logica da eseguire.
- **Parte destra (`n % 2 == 0`):** È il corpo della funzione, cioè cosa fare con `n`.

##### 3. I quattro passaggi nel dettaglio
###### Passaggio A: `.stream()`
- **Sintassi:** Metodo chiamato sulla lista `numeri`.
- **Cosa fa:** Non modifica la lista originale. Apre un "nastro trasportatore" virtuale su cui i numeri `[1, 2, 3, 4, 5, 6]` scorreranno uno alla volta verso le operazioni successive.

###### Passaggio B: `.filter(n -> n % 2 == 0)`
- **Sintassi:** Il metodo `filter` vuole una lambda che restituisca un **booleano** (`true` o `false`).
- **Cosa fa:** Agisce come un buttafuori. Per ogni `n` che passa:
    - Se `n % 2 == 0` è `true` (il numero è pari), lo lascia passare al passaggio successivo.
    - Se è `false`, lo scarta.
- _Sul nastro rimangono solo:_ `2, 4, 6`.

###### Passaggio C: `.mapToInt(n -> n * n)`
- **Sintassi:** Il metodo `mapToInt` vuole una lambda che trasformi un oggetto in un numero intero primitivo (`int`).
- **Cosa fa:** È un trasformatore. Prende ogni numero rimasto (`2, 4, 6`) e lo sostituisce con il risultato di `n * n`. Inoltre, converte il flusso da oggetti `Integer` a tipi primitivi `int` (più veloci per fare calcoli matematici).
- _Sul nastro ora ci sono:_ `4, 16, 36`.
- (Se avessi voluto solo trasformarli da oggetto `Integer` a primitivo `int` avrei comunque dovuto usare la lambda expression: `mapToInt(n -> n)`)

###### Passaggio D: `.sum()`
- **Sintassi:** Metodo finale senza parametri.
- **Cosa fa:** È l'operazione **terminale** (chiude il nastro trasportatore). Prende tutti gli `int` arrivati fin qui (`4, 16, 36`), li somma e restituisce il risultato finale (`56`) che viene salvato nella variabile `int sommaQuadrati`.

###### Come leggerlo in italiano
Se traduci i simboli in parole, la riga si legge quasi come una frase:
> _"Prendi i `numeri`, mettili in un flusso (`.stream()`), tieni solo quelli dove `n` è pari (`.filter`), trasforma ciascun `n` nel suo quadrato (`.mapToInt`), e infine sommaci tutto (`.sum()`)."_


>[!warning] Lo stream è usa e getta
>Una volta eseguita un operazione terminale sullo stream questo non è più accessibile, se serve ancora al massimo se ne apre un altro uguale.
Errore:
```
Stream<Integer> flusso = numeri.stream().filter(n -> n % 2 == 0);

// Prima operazione terminale: funziona e consuma lo stream
long quantiPari = flusso.count(); 

// Seconda operazione sullo stesso stream: ERRORE! (IllegalStateException)
int sommaPari = flusso.map
```

---

`Predicate<Integer> positive = x -> x >= 0;`

Questa riga **salva una regola booleana dentro una variabile** per poterla riutilizzare più volte nel codice.
Nel dettaglio, definisce una condizione chiamata `positive` che prende un numero intero (`Integer`) e restituisce `true` se è maggiore o uguale a zero, oppure `false` se è negativo.

###### Scomposizione della sintassi
- **`Predicate<Integer>`:** È un'interfaccia funzionale di Java. Serve a modellare un **test** o una **condizione** su un oggetto di tipo `Integer`.
- **`positive`:** È il nome della variabile in cui stai salvando questa regola (proprio come faresti con `int numero = 5;`, ma qui invece di un numero stai salvando un _comportamento_).
- **`x -> x >= 0`:** È la lambda expression vista prima, cioè il codice effettivo della regola ("dato `x`, verifica che `x >= 0`").

alcuni esempi:
1) 
```
Predicate<Integer> positive = x -> x >= 0;

boolean risultato1 = positive.test(10);  // true
boolean risultato2 = positive.test(-5);  // false
```
2) 
```
List<Integer> numeri = List.of(-3, 0, 4, -1, 8);
Predicate<Integer> positive = x -> x >= 0;

// Passo direttamente la variabile "positive" al filter
List<Integer> soloPositivi = numeri.stream()
                                   .filter(positive) 
                                   .toList(); // Risultato: [0, 4, 8]
```

---
Vediamo un' operazione terminatore:  .reduce()
**`reduce()`** negli Stream di Java, cioè il meccanismo con cui si "schiaccia" (riduce) un'intera sequenza di elementi in un **unico risultato finale** (come una somma, un prodotto o la concatenazione di stringhe).

##### 1. `reduce(identity, accumulator)`
Richiede due parametri:
- **`identity` ($I$):** È il valore di partenza (l'elemento neutro dell'operazione: `0` per la somma, `1` per la moltiplicazione, `""` per le stringhe). Se lo stream è vuoto, `reduce` restituisce direttamente questo valore.
- **`accumulator` ($g$):** È una funzione a due parametri `(accum, v)` che prende il risultato parziale accumulato fino a quel momento (`accum`) e il nuovo elemento dello stream (`v`), combinandoli insieme.

**Come funziona la formula del libro nella pratica:** Immagina di avere lo stream `[2, 5, 3]` e di chiamare `.reduce(0, (accum, v) -> accum + v)`:

1. Si parte dall'identità: `accum = 0` ($a_0 = I$).
    
2. Arriva il primo elemento (`2`): `0 + 2 = 2` ($a_1$).
    
3. Arriva il secondo elemento (`5`): `2 + 5 = 7` ($a_2$).
    
4. Arriva il terzo elemento (`3`): `7 + 3 = 10` ($a_3$).
    
5. Lo stream finisce e viene restituito `10`.

---

| **Operazione**                    | **Tipologia**                 | **Cosa fa**                                                        | **Uso tipico**                                                        |
| --------------------------------- | ----------------------------- | ------------------------------------------------------------------ | --------------------------------------------------------------------- |
| `stream()`                        | Sorgente                      | Apre un flusso sequenziale di elementi da una `Collection`.        | Avviare una pipeline su liste o insiemi esistenti.                    |
| `parallelStream()`                | Sorgente                      | Apre un flusso parallelo ripartito su più core.                    | Elaborare grandi moli di dati senza stato condiviso.                  |
| `Stream.of(...)`                  | Sorgente                      | Crea uno stream finito dai valori passati come argomenti.          | Creare al volo piccoli flussi o sequenze fisse.                       |
| `Stream.iterate(seme, f)`         | Sorgente                      | Genera uno stream infinito applicando `f` all'elemento precedente. | Creare progressioni matematiche (da troncare con `limit`).            |
| `Stream.generate(supplier)`       | Sorgente                      | Genera uno stream infinito tramite un `Supplier` indipendente.     | Generare valori casuali o costanti (da troncare con `limit`).         |
| `IntStream.range(a, b)`           | Sorgente                      | Genera interi primitivi da `a` (incluso) a `b` (escluso).          | Iterare su intervalli o indici senza creare collezioni.               |
| `IntStream.rangeClosed(a, b)`     | Sorgente                      | Genera interi primitivi da `a` a `b` (entrambi inclusi).           | Generare intervalli chiusi (es. `0` fino a `size()-1`).               |
| `filter(Predicate<T>)`            | Intermedia (stateless)        | Mantiene solo gli elementi per cui il predicato è `true`.          | Selezionare o cercare elementi che rispettano una condizione.         |
| `map(Function<T, R>)`             | Intermedia (stateless)        | Trasforma ogni elemento in un altro valore o tipo (`T` -> `R`).    | Estrarre proprietà (es. `Persona::getEta`) o convertire dati.         |
| `mapToInt(...)`                   | Intermedia (stateless)        | Trasforma uno stream di oggetti in un `IntStream` primitivo.       | Preparare il flusso per calcoli matematici come `sum()`.              |
| `mapToObj(...)`                   | Intermedia (stateless)        | Converte un `IntStream` primitivo in uno `Stream<R>`.              | Mappare indici numerici in oggetti o elementi di una lista.           |
| `boxed()`                         | Intermedia (stateless)        | Converte uno stream primitivo nei relativi oggetti wrapper.        | Raccogliere primitivi in una `List<Integer>` con `toList()`.          |
| `sorted()` / `sorted(Comparator)` | Intermedia (stateful)         | Ordina gli elementi secondo ordine naturale o `Comparator`.        | Ordinare risultati alfabeticamente, numericamente o per campi.        |
| `distinct()`                      | Intermedia (stateful)         | Elimina i duplicati basandosi sul metodo `equals()`.               | Ottenere l'elenco dei valori o categorie uniche.                      |
| `limit(k)`                        | Intermedia (short-circuiting) | Tronca lo stream mantenendo al massimo i primi `k` elementi.       | Rendere finiti stream infiniti o prendere solo i primi $k$ risultati. |
| `peek(Consumer<T>)`               | Intermedia (stateless)        | Esegue un'azione su ogni elemento senza alterare il flusso.        | Fare debug e ispezionare i valori intermedi nella pipeline.           |
| `forEach(Consumer<T>)`            | Terminale                     | Esegue un'azione (es. stampa) su ogni elemento finale.             | Stampare i risultati a console o inviarli all'esterno.                |
| `count()`                         | Terminale                     | Restituisce il numero totale (`long`) di elementi rimasti.         | Contare quanti elementi hanno superato i filtri.                      |
| `toList()`                        | Terminale                     | Materializza gli elementi in una `List` non modificabile.          | Salvare il risultato della pipeline in una lista da leggere.          |
| `collect(Collector)`              | Terminale                     | Raccoglie gli elementi in una struttura mutabile o aggregata.      | Materializzare lo stream in una collezione specifica modificabile.    |
| `reduce(identity, accumulator)`   | Terminale                     | Combina gli elementi in un unico valore partendo dall'identità.    | Calcolare somme, prodotti o aggregazioni con un default sicuro.       |
| `reduce(accumulator)`             | Terminale                     | Combina gli elementi senza identità, restituendo un `Optional`.    | Aggregare elementi quando non esiste un valore neutro ovvio.          |
| `max(Comparator)`                 | Terminale                     | Seleziona l'elemento massimo secondo il `Comparator` (`Optional`). | Trovare l'oggetto con il valore più alto di un campo.                 |
| `sum()`                           | Terminale (Primitivi)         | Somma tutti gli elementi di uno stream primitivo (`IntStream`).    | Calcolare rapidamente il totale di numeri primitivi.                  |
| `findFirst()`                     | Terminale (short-circuiting)  | Restituisce il primo elemento (`Optional`) e ferma il flusso.      | Cercare il primo elemento che soddisfa una condizione.                |
| `findAny()`                       | Terminale (short-circuiting)  | Restituisce un elemento qualsiasi (`Optional`) e si ferma.         | Verificare se esiste almeno un elemento (ideale in parallelo).        |

---
### DESIGN PATTERN

#### SINGLETON
##### 1. Il problema: unicità + accesso ovunque
In molti programmi esistono risorse che, per loro natura, devono essere **uniche** e condivise da tutto il sistema (come un registro di log in cui tutte le classi scrivono errori, o uno spooler di stampa che gestisce una singola stampante).

- **Perché non basta una variabile globale?** Se dichiari una variabile globale `public static Logger log = new Logger();`, chiunque può raggiungerla, ma **nessuno impedisce** a un altro sviluppatore di scrivere altrove nel codice `Logger altroLog = new Logger();`, creando un secondo oggetto e rompendo l'unicità.
- **La soluzione Singleton:** La responsabilità di garantire che esista _al massimo un'istanza_ viene affidata direttamente alla classe stessa.

##### 2. I tre ingranaggi tecnici del Singleton
Per chiudere la porta a creazioni esterne e fornire comunque l'oggetto a chi lo chiede, la classe usa tre elementi combinati:

1. **Costruttore `private`:** Impedisce a qualsiasi classe esterna di invocare `new Singleton()`. Se provi a farlo, il compilatore dà errore. Solo i metodi _interni_ alla classe stessa possono chiamare il costruttore.
2. **Campo `private static`:** È una variabile interna alla classe (es. `private static Logs obj;`) che conserva il riferimento all'unica istanza creata. Essendo `static`, questo campo non appartiene a un singolo oggetto, ma alla classe stessa (quindi esiste in memoria anche prima che venga creato l'oggetto).
3. **Metodo `public static getInstance()`:** È l'unico "sportello" pubblico attraverso cui i client possono ottenere l'oggetto. Poiché non possono fare `new`, devono per forza chiamare `NomeClasse.getInstance()`. Essendo `static`, questo metodo può essere invocato direttamente sul nome della classe, senza avere già un'istanza in mano.

##### 3. Esempio pratico (dal pdf)
Guarda la classe `Logs` della dispensa:
```
public final class Logs {
    // 1. Riferimento statico all'unica istanza
    private static Logs obj; 
    private final List<String> righe = new ArrayList<>();

    // 2. Costruttore privato: nessuno fuori da qui può fare "new Logs()"
    private Logs() { } 

    // 3. Punto di accesso globale e statico
    public static Logs getInstance() {
        if (obj == null) {       // Se l'istanza non esiste ancora...
            obj = new Logs();    // ...la creo ora (solo la prima volta!)
        }
        return obj;              // Restituisco sempre la stessa istanza
    }
    
    public void record(String s) { righe.add(s); }
}
```

**Cosa succede a runtime?**
- Quando la classe `A` chiama `Logs l1 = Logs.getInstance();`, `obj` è `null`, quindi viene eseguito `new Logs()` e restituito il riferimento.
- Quando, poco dopo, la classe `B` chiama `Logs l2 = Logs.getInstance();`, `obj` **non è più `null`**, quindi l'`if` viene saltato e viene restituito **esattamente lo stesso oggetto** (`l1 == l2` è `true`). Quello che `A` scrive nel log sarà visibile anche a `B`.

###### Due sfumature importanti (Eager vs Lazy e Concorrenza)
- **Lazy (pigra) vs Eager (impaziente):** Nell'esempio `Logs` sopra, l'oggetto viene creato solo quando serve la prima volta (_lazy_), risparmiando memoria se non viene mai usato. Al contrario, nell'esempio `Fib`, si scrive `private static final Fib obj = new Fib();` (_eager_): l'istanza nasce subito al caricamento della classe.

- **Il rischio multithreading:** Nella versione _lazy_, se due thread chiamano `getInstance()` nello stesso identico istante mentre `obj` è ancora `null`, entrambi potrebbero superare l'`if` e creare due istanze diverse. Per evitarlo in ambienti concorrenti si usa la variante _eager_ oppure si aggiunge `synchronized` al metodo `getInstance()`.


> [!summary] RIEPILOGO SINGLETON
> Quindi si usa singleton quando ho bisogno di usare un'oggetto di una classe che però deve restare 1 solo per tutto il tempo, magari una struttura dati, e voglio evitare che altre classi/oggetti ne creino altri, quindi dichiaro il costruttore dela classe "private" (così che sia impossibile per altri oggetti fare new classe()) e uso un metodo static (che appartiene quindi alla classe e posso richiamarlo con NomeClasse.metodoStatic()) e l'oggetto si crea una sola volta (versione lazy) oppure si crea quando la classe si carica in memoria (versione eager). All'interno della classe è presente un riferimento all'oggetto della classe stessa

> [!info] VARIANTE MULTITON
> Il **Multiton** è la variante che consente un numero finito di istanze, eventualmente associandone una a una chiave


##### Diagramma UML della classe singleton
![[Pasted image 20261125103922.png|453]]

Diagramma UML della classe Singleton (è più un mockup che un diagramma reale) 

- in alto: nome classe -> Singleton

- al centro: la singola istanza alla classe singleton stessa (privata) -> -uniqueIstance:Singleton
  - altri dati  sempre privati

- in basso: costruttore privato cosi che nessuno possa fare new Singleton()
  -  metodo pubblico per creare una singola istanza
  - altre operazioni

Costruttore privato, riferimento e accesso statici; operazioni sullo stato dell’unica istanza.

---

