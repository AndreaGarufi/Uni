Chiarimenti sul PDF ![[studio.pdf]]

### Java imperativo VS Java funzionale (cap. 6 pag 60)
##### 1. Approccio Imperativo (Come farlo)
In questo stile, descrivi **passo dopo passo** come il computer deve eseguire l'operazione, gestendo manualmente lo stato (le variabili che cambiano) e i cicli.
```java
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
```java
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

```java
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
```java
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
```java
Predicate<Integer> positive = x -> x >= 0;

boolean risultato1 = positive.test(10);  // true
boolean risultato2 = positive.test(-5);  // false
```
2) 
```java
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
```java
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

#### FACTORY METHOD
Il **Factory Method** è il secondo pattern creazionale ed entra in gioco quando **il codice generale sa _quando_ creare un oggetto e _come_ usarlo, ma non deve sapere _quale classe concreta_ istanziare**.

##### 1. L'idea di fondo: delegare alle sottoclassi
Immagina di scrivere un _framework_ o una logica generale che lavora su un tipo astratto (es. `Document`, `Studente` o `Posto`). Il codice generale non può fare `new posto()` perché è un'interfaccia o una classe astratta, ma se scrivesse `new postoPlatea()` resterebbe bloccato su un solo formato (non potrebbe avere anche postoPalco ad esempio).

La soluzione del **Factory Method** è definire un metodo "fabbrica" (es. `factoryMethod()`) nella superclasse e **lasciare alle sottoclassi il compito di decidere quale oggetto concreto creare**. Il tutto funziona grazie al **dispatch dinamico** (_late binding_): a runtime, quando il codice generale chiama il metodo di creazione su `this`, Java esegue l'override definito nella sottoclasse concreta.

##### 2. I quattro ruoli fondamentali

- **`Product`**: l'interfaccia (o classe astratta) comune a tutti gli oggetti creati. È l'unico tipo che il client conosce e usa.
- **`ConcreteProduct`**: le singole implementazioni concrete del prodotto (es. `PdfDocument`, `StudenteAttivo`, `PostoPlatea`).
- **`Creator`**: la classe (spesso astratta) che dichiara il `factoryMethod()` con tipo di ritorno `Product`. Può anche contenere operazioni concrete che chiamano il `factoryMethod()` per ottenere un prodotto e lavorarci sopra (ad esempio aggiornando un contatore delle istanze create).
- **`ConcreteCreator`**: la sottoclasse che ridefinisce il `factoryMethod()` e restituisce l'istanza del `ConcreteProduct` scelto (`return new ConcreteProductA();`).


##### 3. Perché conviene e qual è il costo

- **Vantaggio:** puoi aggiungere nuovi tipi di prodotto (es. `WordDocument` o un nuovo tipo di posto a teatro) semplicemente aggiungendo una nuova sottoclasse, **senza modificare il codice del client** né la logica generale del `Creator`.
    
- **Costo:** aumenta il numero di classi nel progetto (spesso serve una sottoclasse di `Creator` per ogni tipo di `Product`). Se hai un solo prodotto concreto e non prevedi variazioni, questo pattern è eccessivo.


Vediamo un esempio di codice:
```java
import java.util.*;

// 1. PRODUCT: il contratto comune che il client e il creator astratto conoscono
interface Posto {
    String getPosizione();
    int getCosto();
    String getSettore();
}

// 2. CONCRETE PRODUCT A
class PostoPalco implements Posto {
    private final int numero;

    public PostoPalco() {
        // Sceglie un numero casuale tra 1 e 20
        this.numero = new Random().nextInt(20) + 1;
    }

    @Override public String getPosizione() { return "Palco-" + numero; }
    @Override public int getCosto() { return (numero <= 10) ? 40 : 50; }
    @Override public String getSettore() {
        if (numero <= 10) return "Blu";
        if (numero <= 19) return "Verde";
        return "Centrale";
    }
}

// 2. CONCRETE PRODUCT B
class PostoPlatea implements Posto {
    private final int numero;

    public PostoPlatea() {
        this.numero = new Random().nextInt(80) + 1;
    }

    @Override public String getPosizione() { return "Platea-" + numero; }
    @Override public int getCosto() { return 30; }
    @Override public String getSettore() { return "Platea"; }
}

// 3. CREATOR: definisce la logica generale (quando creare e come registrare)
//    ma delega alle sottoclassi la creazione effettiva tramite il factory method
abstract class Posizioni {
    private final Set<String> postiPieni = new HashSet<>();
    private final List<Posto> posti = new ArrayList<>();

    // Operazione generale del framework: usa getPosto() senza sapere quale classe concreta crea
    public Posto prendiPosto(int tipo) {
        if (postiPieni.size() == 100) return null;
        Posto p;
        do {
            p = getPosto(tipo); // <-- Chiamata al Factory Method (dispatch dinamico!)
        } while (postiPieni.contains(p.getPosizione()));
        
        postiPieni.add(p.getPosizione());
        posti.add(p);
        return p;
    }

    public void printPostiPieni() {
        for (Posto p : posti) {
            System.out.println(p.getPosizione() + " - " + p.getSettore() + " (" + p.getCosto() + "€)");
        }
    }

    // IL FACTORY METHOD (astratto) ridefinito poi in CreatorPosti
    public abstract Posto getPosto(int tipo);
}

// 4. CONCRETE CREATOR: decide quale classe concreta istanziare
class CreatorPosti extends Posizioni {
    @Override
    public Posto getPosto(int tipo) {
        if (tipo == 1) {
            return new PostoPalco();
        }
        return new PostoPlatea();
    }
}

// CLIENT: lavora solo con i tipi astratti Posizioni e Posto
public class MainTeatro {
    public static void main(String[] args) {
        // L'unico punto in cui si nomina una classe concreta è la configurazione iniziale
        Posizioni gestore = new CreatorPosti();

        Posto p1 = gestore.prendiPosto(1); // Chiede un palco
        Posto p2 = gestore.prendiPosto(2); // Chiede una platea

        System.out.println("Assegnato: " + p1.getPosizione() + " costo " + p1.getCosto());
        gestore.printPostiPieni();
    }
}
```

- `p1` e `p2` sono 2 `posto` ovvero 2 *concrete product* che implementano l'interfaccia `posto`
- `gestore.prendiPosto()` va in prendi posto (dentro posizioni, dato che non ha fatto l'override nella sua classe va nella sua superclasse)
- `public Posto prendiPosto(int tipo)` ritorna il tipo `posto` e dentro di se crea una variabile di tipo posto e chiama il *factory method* che dentro la classe `posizioni` è solo dichiarato come prototipo, l'implementazione è dentro `CreatorPosti`, quindi si esegue l'override dentro `CreatorPosti` e se il tipo passato è 1 allora si ritorna postoPalco altrimenti postoPlatea

###### Questo è il diagramma dei posti a teatro
![[Pasted image 20261125193326.png|720]]

> [!info] UTILITÀ 
> In questo modo potrei anche definire più tipologie di posti (postoBalcone, postoLusso ecc...) ma anche più creatorPosti differenti (classi diverse) che implementano ognuno una versione diversa del factory method (getPosto) senza dover cambiare il codice già scritto

###### Diagramma UML del factory method
![[Pasted image 20261125185105.png]]

- Il client fa ottiene oggetti dell'`interfaccia prodotto`
- l'interfaccia è in relazione con la classe `Creator` che a sua volta ha delle operazioni al suo interno e la definizione (firma) del factory method
- la classe `ConcreteCreatore` è una sotto classe di `Creator`, al suo interno c'è la definizione effettiva del factory method
- i `concreteProductA e B` implementano l' `interfaccia prodotto` 

---
#### OBJECT POOL
Immaginiamo di usare oggetti che sono delle forme geometriche.
##### 1. Il problema: oggetti costosi da creare + riuso controllato
Creare e distruggere continuamente certi oggetti (come connessioni a un database, thread, socket o figure grafiche pesanti) costa molto tempo e risorse.

- **Perché non basta fare `new` ogni volta?** Se ogni client crea un oggetto nuovo e poi lo butta via al garbage collector, il sistema rallenta o esaurisce le risorse disponibili.
    
- Nell'Object Pool, hai un **deposito (una collezione) di più istanze** che vengono **prestate in uso esclusivo** a un client alla volta e poi **restituite** al deposito per essere riutilizzate da altri.

##### 2. I tre ingranaggi tecnici dell'Object Pool
Il gestore del pool (spesso combinato con un **Factory Method** come `ConcreteCreator` o con un **Singleton** affinché il deposito sia unico) gestisce il ciclo di vita degli oggetti attraverso tre meccanismi:

1. **Un deposito interno (es. una `List`):** conserva le istanze già create e attualmente **libere** (disponibili).
    
2. **Metodo di acquisizione (`getShape()` / `acquire()`):** quando un client chiede una risorsa, il pool controlla se nel deposito c'è un oggetto libero:
    
    - Se c'è, lo **toglie** dalla lista dei liberi (`pool.remove(0)`) e lo consegna al client. È fondamentale rimuoverlo dal deposito perché **l'uso deve essere esclusivo**: finché un client lo usa, nessun altro può riceverlo.
        
    - Se il deposito è vuoto, il comportamento dipende dalla politica scelta: un **pool estendibile** ne crea uno nuovo (`new Circle()`), mentre un **pool a dimensione fissa** blocca la creazione (rifiuta la richiesta, restituisce `null` o fa attendere).
        
3. **Metodo di rilascio (`releaseShape(s)` / `release()`):** quando il client ha finito di usare l'oggetto, **deve restituirlo** al pool, che lo rimette nella lista dei disponibili (`pool.add(s)`). Prima di consegnarlo di nuovo a un altro client, è necessario **reimpostarne lo stato (reset)**, altrimenti il nuovo utilizzatore vedrebbe i dati lasciati dal precedente.
    

##### 3. Esempio pratico (dal pdf)

Guarda la classe `CreatorPool` della dispensa, che realizza un pool **estendibile** di `Shape`:

```java
public class CreatorPool {
    // 1. Il deposito delle istanze
    private List<Shape> pool = new ArrayList<>();

    // 2. Acquisizione: riusa se disponibile, altrimenti crea
    public Shape getShape() {
        if (pool.size() > 0) {
            return pool.remove(0); // Rimuove e consegna in uso esclusivo
        }
        return new Circle();       // Deposito vuoto: crea nuova istanza (pool estendibile)
    }

    // 3. Rilascio: rimette l'oggetto nel deposito per il riuso
    public void releaseShape(Shape s) {
        // Qui, se Shape avesse uno stato sporco, andrebbe fatto il reset!
        pool.add(s);
    }
}
```

**Cosa succede a runtime?**

- Il client A chiama `Shape s1 = gestore.getShape();`. La lista `pool` è vuota, quindi viene creato un nuovo `Circle` e consegnato ad A.
    
- Il client A finisce il suo lavoro e chiama `gestore.releaseShape(s1);`. L'oggetto torna nella lista `pool`.
    
- Il client B chiama `Shape s2 = gestore.getShape();`. Stavolta `pool.size() > 0` è vero: il pool estrae quell'oggetto con `remove(0)` e lo dà a B senza fare alcun `new` (`s1 == s2` è `true`!).

###### Quattro regole/rischi da ricordare (molto richiesti all'esame)
1. **Pool fisso vs Pool estendibile:** In un pool a **capacità limitata** (fisso), devi distinguere il numero di istanze _create complessivamente_ dal numero di istanze _attualmente libere_: la sola `pool.size()` ti dice solo quante sono libere in quel momento, non quante sono in giro presso i client.
    
2. **Reset dello stato:** Se l'oggetto ha attributi mutabili (es. colore, posizione o dati di una sessione), va ripulito al momento del rilascio o prima della nuova consegna.
    
3. **Integrità dei rilasci:** Il pool deve proteggersi da errori dei client, evitando **rilasci duplicati** (lo stesso oggetto restituito due volte di fila, che verrebbe poi consegnato contemporaneamente a due client diversi!) e **oggetti estranei** (oggetti creati fuori dal pool e inseriti con `release`).
    
4. **Combinazione con Singleton e Factory Method:**
    
    - Combinato con **Factory Method**, `CreatorPool` funge da `ConcreteCreator` e nasconde al client il fatto che l'oggetto sia nuovo o riciclato.
        
    - Combinato con **Singleton**, si rende unico il _gestore del pool_ (`CreatorPool`), **non** il numero di risorse (`Shape`) contenute al suo interno.

Diagramma UML
![[Pasted image 20261126123046.png|355]]


---

### DEPENDENCY INJECTION
La **Dependency Injection (DI)** è un design pattern che invece di far creare a una classe gli oggetti da cui dipende (tramite `new`), questi le vengono **passati dall'esterno**.

##### Come funziona (con esempio in Java)
**Senza Dependency Injection (forte accoppiamento):**
La classe `OrderService` crea internamente il proprio repository. Se domani vuoi cambiare database o scrivere un test unitario senza toccare il DB vero, devi modificare `OrderService`.

```java
public class OrderService {
    private MySQLOrderRepository repository;

    public OrderService() {
        // La classe decide e crea la propria dipendenza
        this.repository = new MySQLOrderRepository(); 
    }
}
```

**Con Dependency Injection (disaccoppiamento):**
`OrderService` dichiara solo di aver bisogno di un'interfaccia `OrderRepository` e la riceve dall'esterno.

```java
public class OrderService {
    private final OrderRepository repository;

    // Constructor Injection: la dipendenza viene iniettata dall'esterno
    public OrderService(OrderRepository repository) {
        this.repository = repository;
    }
}
```

##### Le 3 modalità principali di iniezione
1. **Constructor Injection (la più consigliata):** Le dipendenze vengono passate nei parametri del costruttore. Garantisce che l'oggetto nasca già in uno stato valido e permette di dichiarare i campi `final` (immutabili).
2. **Setter Injection:** Le dipendenze vengono fornite tramite metodi `setDipendenza(...)` dopo la creazione dell'oggetto. Utile solo per dipendenze opzionali o riconfigurabili a runtime.
3. **Field / Property Injection:** Le dipendenze vengono inserite direttamente negli attributi tramite reflection o annotazioni. È comoda ma nasconde le dipendenze della classe e rende più scomodi i test senza framework.

###### Perché si usa
- **Testabilità (JUnit / Mock):** Puoi passare facilmente un oggetto finto (_mock_ o _stub_) nel costruttore per testare la logica di `OrderService` in totale isolamento.
- **Flessibilità e manutenibilità:** Puoi sostituire un'implementazione con un'altra (es. passare da `MySQLOrderRepository` a `PostgresOrderRepository`) senza toccare una riga del codice che la usa.
- **Gestione centralizzata:** Nei progetti grandi, un _DI Container_ (come Spring, Guice o Dagger) si occupa automaticamente di istanziare tutte le classi e collegare il grafo delle dipendenze al posto tuo.

###### Controindicazioni
- **Complessità iniziale e "magia" dei framework:** Se ti affidi a un container automatico, il flusso di creazione degli oggetti non è più visibile leggendo direttamente il codice, e gli errori di configurazione possono emergere solo a runtime.
- **Over-engineering su classi banali:** Creare interfacce e iniettare qualsiasi classe di utilità che non cambierà mai né richiede mock aggiunge solo codice boilerplate inutile.

---

