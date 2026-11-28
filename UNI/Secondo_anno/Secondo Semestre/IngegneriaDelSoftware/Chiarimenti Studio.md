Chiarimenti sul PDF ![[studio.pdf]]
### Regola per leggere bene i diagrammi UML
La regola d'oro per leggere quasi tutte le frecce UML è **partire dalla coda e andare verso la punta**: la punta indica sempre **chi viene usato, esteso o posseduto**.

- **Guarda prima la punta:**
    - **Triangolo vuoto (`▷`)** = gerarchia di tipi (`extends` se linea continua, `implements` se tratteggiata).
    - **Punta aperta (`→`)** = utilizzo (`Associazione` se linea continua / attributo di classe, `Dipendenza` se tratteggiata / uso al volo).
        
- **Guarda il rombo (`◇` / `◆`):**
    - Il rombo sta **sempre dalla parte del "contenitore"** (il tutto), mai dalla parte del componente.
    - **Vuoto** = contenitore "leggero" (puoi togliere il pezzo e resta vivo).
    - **Pieno** = contenitore "totale" (il ciclo di vita è legato al contenitore).


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
### DESIGN PATTERN CREAZIONALI

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

#### DEPENDENCY INJECTION
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
#### ABSTRACT FACTORY
L'**Abstract Factory** è il fratello maggiore del _Factory Method_. Se il Factory Method serviva a delegare la creazione di **un singolo prodotto**, l'Abstract Factory serve a creare **intere famiglie di prodotti correlati** garantendo che siano coerenti tra loro.
##### 1. Il problema: creare una "famiglia" coerente senza mescolare i pezzi
Immagina di sviluppare un'applicazione lingua **Inglese** e **Giapponese**, come nell'esempio del pdf). Ogni versione richiede più componenti diversi — ad esempio un'icona `Icon` e un testo `Text`.

- **Il rischio:** Se il codice client istanziasse manualmente i singoli pezzi (`new EnglishText()` e `new JapaneseText()`), potrebbe mescolare componenti di famiglie diverse, ottenendo un'interfaccia incoerente. Inoltre, per cambiare tema o lingua dovresti riscrivere tutti i `new` sparsi nel programma.
- **La soluzione Abstract Factory:** Crei un'interfaccia fabbrica (`AbstractFactory`) che dichiara un metodo di creazione per **ciascun tipo di prodotto** della famiglia (`getIcon()`, `getText()`). Poi crei una fabbrica concreta per ogni variante (`EnglishText`, `JapaneseText`) che produce **solo** i pezzi compatibili tra loro.

##### 2. L'idea della griglia (molto utile per capire il diagramma UML)
La dispensa suggerisce di visualizzare il pattern come una **tabella (griglia)** di $m \times n$ prodotti concreti:

| **Tipo di Prodotto (AbstractProduct)** | **Famiglia 1: Inglese (CreatorEng)** | **Famiglia 2: Giapponese (CreatorJ)** |
| -------------------------------------- | ------------------------------------ | ------------------------------------- |
| **`Icon`** (metodo `getIcon()`)        | `Box`                                | `Circle`                              |
| **`Text`** (metodo `getText()`)        | `English`                            | `Japanese`                            |

- **Le righe ($m$)** sono i **tipi di prodotto** astratti (es. riga 1: `AbstractProductA` / `Icon`; riga 2: `AbstractProductB` / `Text`).
    
- **Le colonne ($n$)** sono le **famiglie** (es. colonna 1: `ConcreteFactory1` / Inglese; colonna 2: `ConcreteFactory2` / Giapponese).
    
- Ogni `ConcreteFactory` corrisponde a **un'intera colonna**: il client riceve una factory tramite l'interfaccia `AbstractFactory` e usa solo i prodotti astratti, avendo la certezza che tutti gli oggetti chiesti a quella factory appartengano alla stessa colonna (famiglia).
    

##### 3. I ruoli e l'esempio pratico della dispensa (`Icon` e `Text`)

Vediamo un esempio con due tipi di prodotto (`Icon` e `Text`) e due famiglie (`Inglese` e `Giapponese`):

```java
// 1. ABSTRACT PRODUCT A e B: i contratti dei singoli tipi di prodotto
interface Icon {
    void happy();
    void sad();
}

interface Text {
    void welcome();
    void attention();
}

// 2. CONCRETE PRODUCT della Famiglia 1 (Inglese: Box + English)
class Box implements Icon {
    @Override public void happy() { System.out.println("[ :- ) ]"); }
    @Override public void sad()   { System.out.println("[ :-( ]"); }
}

class English implements Text {
    @Override public void welcome()   { System.out.println("Welcome!"); }
    @Override public void attention() { System.out.println("Attention!"); }
}

// 2. CONCRETE PRODUCT della Famiglia 2 (Giapponese: Circle + Japanese)
class Circle implements Icon {
    @Override public void happy() { System.out.println("( ^_^ )"); }
    @Override public void sad()   { System.out.println("( T_T )"); }
}

class Japanese implements Text {
    @Override public void welcome()   { System.out.println("Yokoso!"); }
    @Override public void attention() { System.out.println("Chui!"); }
}

// 3. ABSTRACT FACTORY: dichiara un metodo per ogni tipo di prodotto (le righe della griglia)
interface Creator {
    Icon getIcon();
    Text getText();
}

// 4. CONCRETE FACTORY 1 e 2: ciascuna produce una colonna coerente
class CreatorEng implements Creator {
    @Override public Icon getIcon() { return new Box(); }
    @Override public Text getText() { return new English(); }
}

class CreatorJ implements Creator {
    @Override public Icon getIcon() { return new Circle(); }
    @Override public Text getText() { return new Japanese(); }
}

// 5. CLIENT: lavora solo con Creator, Icon e Text (zero dipendenze dalle classi concrete!)
public class MainApp {
    public static void main(String[] args) {
        // Scegliendo la factory, fissi l'intera famiglia
        Creator c = new CreatorJ(); // Basta cambiare questo in "new CreatorEng()" per cambiare tutto!

        Icon ic = c.getIcon();
        Text t = c.getText();

        ic.happy();
        t.welcome();
    }
}
```

###### 4. Differenza chiave con Factory Method e compromessi
- **Factory Method vs Abstract Factory:** Il Factory Method usa l'ereditarietà (una sottoclasse ridefinisce un metodo) per creare **un solo prodotto**; l'Abstract Factory usa la composizione (il client riceve un oggetto factory con più metodi) per creare **un'intera famiglia di prodotti correlati**.
- **Vantaggio:** Cambiare l'intera famiglia di prodotti è immediato (basta sostituire l'istanza di `ConcreteFactory` passata al client) ed è facile aggiungere una _nuova famiglia_ (aggiungi una colonna alla griglia, es. `CreatorIta`, senza toccare il resto).
- **Svantaggio (costo):** Aggiungere un _nuovo tipo di prodotto_ (una nuova riga, es. `Audio`) è oneroso, perché obbliga a modificare l'interfaccia `AbstractFactory` e **tutte** le `ConcreteFactory` esistenti per implementare il nuovo metodo.

---
#### BUILDER
Il design pattern **Builder** serve a **separare la costruzione di un oggetto complesso dalla sua rappresentazione**, permettendo di assemblarlo **passo dopo passo** prima di consegnarlo definitivo e (spesso) immutabile.

##### 1. Il problema: oggetti con molti parametri (obbligatori e opzionali)
Immagina di dover creare un oggetto `Biglietto` che ha diversi campi: `titolare` (obbligatorio), `agente`, `data` e `prezzo` (opzionali o con valori di default). Prima di usare Builder hai due strade tradizionali, entrambe scomode:

- **Costruttori telescopici:** scrivi tanti costruttori quanti sono i possibili sottogruppi di parametri (`Biglietto(t)`, `Biglietto(t, a)`, `Biglietto(t, a, d)`, `Biglietto(t, a, d, p)`). Il problema è che quando i campi aumentano esplodono le combinazioni ed è facilissimo invertire due argomenti dello stesso tipo.
- **Costruttore vuoto + Setter (`setTitolare`, `setPrezzo`...):** è comodo, ma costringe a rinunciare all'immutabilità (i campi non possono più essere `final`) e lascia l'oggetto in uno **stato incompleto e inconsistente** tra una chiamata `set` e l'altra (magari qualcuno usa il biglietto prima di aver impostato il titolare) (vediamo meglio alla fine).

**La soluzione Builder:** sposti tutti i dati provvisori in un oggetto intermedio di appoggio (il _Builder_). Configuri i pezzi uno alla volta con metodi chiari e leggibili, e solo alla fine chiami un metodo conclusivo (es. `build()` o `getBiglietto()`) che controlla che tutto sia valido e istanzia l'oggetto vero e proprio tutto in una volta.

##### 2. I quattro ruoli del pattern
- **`Product` (es. `Biglietto`):** l'oggetto complesso finale che vogliamo ottenere, con i campi di costruzione resi `final`.
- **`Builder` (es. `BBuilder`):** l'interfaccia che dichiara i passi di configurazione (`agente(...)`, `titolare(...)`, `sconto(...)`, `data(...)`) e il metodo finale di consegna (`getBiglietto()`).
- **`ConcreteBuilder` (es. `BigliettoBuilder`):** conserva i dati provvisori durante l'assemblaggio, implementa i passi restituendo `this` (stile **fluente** / _method chaining_) e nel metodo finale valida i vincoli prima di fare `new Biglietto(...)`.
- **`Director` (es. `InitBiglietto`):** un oggetto opzionale che conosce una sequenza standard di passi per costruire una particolare configurazione (es. un biglietto preconfigurato per un certo venditore) usando l'interfaccia `Builder`.

##### 3. Esempio pratico (dal pdf)

```java
import java.time.LocalDateTime;

// 1. PRODUCT: campi finali impostati una sola volta alla creazione
class Biglietto {
    final String titolare, agente;
    final LocalDateTime data;
    final double prezzo;

    Biglietto(String t, String a, double p, LocalDateTime d) {
        titolare = t;
        agente = a;
        prezzo = p;
        data = d;
    }
}

// 2. BUILDER: contratto dei passi di costruzione
interface BBuilder {
    BBuilder agente(String a);
    BBuilder titolare(String t);
    BBuilder sconto(double sc);
    BBuilder data(LocalDateTime d);
    Biglietto getBiglietto();
}

// 3. CONCRETE BUILDER: accumula lo stato provvisorio, valida e costruisce
class BigliettoBuilder implements BBuilder {
    // Valori provvisori e di default
    private String titolare;
    private String agente = "SingleSeller";
    private LocalDateTime data;
    private double prezzo = 50;

    @Override
    public BigliettoBuilder agente(String a) {
        agente = agente + " " + a;
        return this; // Restituisce se stesso per concatenare le chiamate!
    }

    @Override
    public BigliettoBuilder titolare(String t) {
        titolare = t;
        return this;
    }

    @Override
    public BigliettoBuilder data(LocalDateTime d) {
        data = d;
        return this;
    }

    @Override
    public BigliettoBuilder sconto(double sc) {
        if (prezzo >= 40 && sc <= 10) {
            prezzo = (1 - sc / 100) * prezzo;
        }
        return this;
    }

    @Override
    public Biglietto getBiglietto() {
        // Validazione finale prima di consegnare il prodotto
        if (titolare == null) return null; 
        return new Biglietto(titolare, agente, prezzo, data);
    }
}

// 4. DIRECTOR (opzionale): incapsula una ricetta standard di costruzione
class InitBiglietto {
    Biglietto getBiglietto() {
        return new BigliettoBuilder()
                .agente("Tim Seller")
                .titolare("Mario Rossi")
                .sconto(5)
                .data(LocalDateTime.now())
                .getBiglietto();
    }
}
```

##### Due punti chiave da ricordare all'esame
1. **Perché i metodi restituiscono `this`?** Si chiama **interfaccia fluente** (_method chaining_): poiché ogni metodo (`titolare(...)`, `sconto(...)`) restituisce il riferimento al `BigliettoBuilder` stesso, puoi scrivere tutta la configurazione in un'unica catena leggibile `.agente(...).titolare(...).getBiglietto()`.
2. **Validazione e immutabilità:** Il `Builder` non impedisce a priori di dimenticare un campo obbligatorio (perché ogni passo è un metodo separato); per questo il metodo finale `getBiglietto()` (o `build()`) **deve controllare esplicitamente** che i campi richiesti non siano `null` prima di creare il `Product`. Inoltre, se il `Product` espone altri metodi che modificano campi non `final` (come il campo `acconto` citato nella precisazione del tuo testo), l'oggetto non sarà strettamente immutabile: il Builder garantisce solo che i parametri di costruzione nascano già consistenti.

###### Potrei usare Costruttore vuoto + Setter anziché builder? A cosa dovrei rinunciare?
Usare un costruttore vuoto con i `set...()` funziona, ma comporta **tre conseguenze pratiche** che il pattern Builder invece evita:
1. **Perdi l'immutabilità (`final`):** Per poter chiamare `setTitolare(...)` o `setPrezzo(...)` _dopo_ aver fatto `new Biglietto()`, i campi non possono più essere dichiarati `final`. Chiunque abbia un riferimento a quel `Biglietto` potrà modificarne i dati anche in seguito, quando l'oggetto dovrebbe già essere definitivo.
2. **Stato intermedio inconsistente (oggetto "a metà"):** Tra il momento in cui fai `Biglietto b = new Biglietto();` e il momento in cui chiami l'ultimo setter, esiste in memoria un oggetto incompleto (magari con `titolare == null`) che può già essere passato ad altri metodi o usato per sbaglio prima che la configurazione sia finita (magari c'è un thread che ottiene quell'oggetto quando ancora non ho finito di crearlo).
3. **Nessun controllo centralizzato in creazione:** Il chiamante può dimenticare di chiamare un setter obbligatorio (es. `setTitolare`) senza ricevere alcun blocco immediato, perché non c'è un punto finale come `getBiglietto()` / `build()` che verifica che tutti i dati richiesti siano presenti prima di consegnare l'oggetto vero e proprio.

---
#### PROTOTYPE

Il **Prototype** è l'ultimo dei cinque pattern creazionali classici del catalogo GoF e affronta la creazione degli oggetti da un punto di vista completamente diverso: **invece di costruire un oggetto nuovo da zero con `new`, lo si ottiene clonando (copiando) un'istanza prototipo già esistente e configurata**.
##### 1. Il problema: oggetti costosi da configurare + dipendenza dalle classi concrete
Immagina di dover creare ripetutamente oggetti che hanno uno **stato iniziale complesso** — ad esempio un `Documento` con font, margini, lingua e stili già impostati tramite decine di operazioni, oppure un'agenda (`Calendario`) che parte già con una serie di impegni ricorrenti.

- **Perché non basta fare `new` ogni volta?** Ricostruire da zero tutta la configurazione ogni volta è scomodo, ripetitivo o costoso; inoltre, scrivere `new ClasseConcreta()` nel codice client lo lega rigidamente a quella specifica classe.
- **Perché non usare una gerarchia di `Factory Method`?** Se hai tante varianti di stato (es. _CerchioRosso_, _CerchioBlu_, _CerchioGrande_), creare una sottoclasse `ConcreteCreator` per ciascuna variante farebbe esplodere inutilmente la gerarchia delle classi.
- **La soluzione Prototype:** Prepari alcune istanze modello già configurate (i **prototipi**), eventualmente salvate in un registro (`PrototypeRegistry`). Quando al client serve un nuovo oggetto, non fa `new`: chiama `prototipo.clone()` attraverso l'interfaccia comune `Prototype` e poi modifica solo i pochi dettagli specifici che cambiano (es. il titolo del nuovo documento).

##### 2. I ruoli e il meccanismo UML
![[Pasted image 20261128100446.png|539]]

- **`Prototype`:** l'interfaccia (o classe astratta) che dichiara l'operazione di clonazione (`+clone(): Prototype`).
- **`ConcretePrototype1 / 2`:** le classi concrete che implementano `clone()` restituendo una copia di se stesse.
- **`Client`:** conserva un riferimento di tipo `Prototype` e crea nuove istanze invocando `prototipo.clone()`, senza conoscere né nominare la classe concreta sottostante.
- **`PrototypeRegistry` (opzionale):** una mappa (`Map<String, Prototype>`) che associa una chiave semantica (es. `"documentoStandard"`, `"cerchioRosso"`) a un'istanza prototipo già pronta. Permette di registrare, cercare o rimuovere prototipi dinamicamente a runtime senza creare gerarchie parallele di creatori.

##### 3. Il nodo cruciale: Copia Superficiale vs Copia Profonda
Quando implementi `clone()`, devi decidere **quanto in profondità** duplicare lo stato dell'oggetto originale:

1. **Copia superficiale:** duplica l'oggetto principale, ma **copia solo i riferimenti** agli oggetti interni contenuti nei suoi campi.
    - _Conseguenza:_ originale e clone condividono gli stessi oggetti interni. Se sono oggetti immutabili (come `String` o `LocalDate`) va benissimo; ma se condividono una lista mutabile (es. la lista degli impegni in `Agenda`), aggiungere un impegno al clone lo fa comparire anche nell'originale.
2. **Copia profonda:** duplica l'oggetto principale **e ricorsivamente anche tutti gli oggetti mutabili** che compongono il suo stato, creando nuove copie indipendenti.
    - _Attenzione ad `addAll()`:_ come avverte la dispensa, fare `nuovaLista.addAll(vecchiaLista)` crea un contenitore nuovo, ma i singoli elementi dentro la lista restano comunque condivisi. Se anche gli elementi interni sono mutabili (es. un oggetto `Impegno` modificabile), bisogna clonare anche ciascun elemento.


Vediamo l'esempio con i documenti:
##### 1. L'idea intuitiva: il "modello da fotocopiare"
Immagina di dover generare 50 lettere aziendali o relazioni tecniche. Ogni `Documento` ha una configurazione iniziale lunga e noiosa da preparare:
- **Font:** `"Times New Roman"`, dimensione `12`
    
- **Margini:** `2.5 cm` su tutti i lati
    
- **Lingua:** `"Italiano"`
    
- **Intestazione / Stile:** logo aziendale, piè di pagina, interlinea `1.5`
    
Senza Prototype, ogni volta che devi creare una nuova lettera dovresti fare `new Documento()` e richiamare 10 metodi di configurazione uno dopo l'altro, oppure dover conoscere nel tuo codice il nome esatto della classe concreta (`new DocumentoAziendale()`, `new DocumentoLegale()`, ecc.).

**Con Prototype, invece, fai come con una fotocopiatrice:**
1. **Prepari un solo "originale" (il prototipo):** crei e configuri **una volta sola** un `Documento` con tutti i font, i margini, la lingua e lo stile già impostati, e lo metti da parte (ad esempio in un registro dei modelli).
2. **Quando ti serve un nuovo documento, lo cloni:** chiami `prototipo.clone()`. Ottieni istantaneamente un documento nuovo che ha già tutti i margini, il font e lo stile del modello.
3. **Personalizzi solo ciò che cambia:** sul documento appena clonato imposti soltanto il titolo e il testo specifico di quella lettera, lasciando intatto il modello originale.


```java
import java.util.*;

// 1. PROTOTYPE: il contratto che dice "questo oggetto sa clonarsi"
interface DocumentoPrototype {
    DocumentoPrototype clone();
}

// 2. CONCRETE PROTOTYPE: il documento vero e proprio
class Documento implements DocumentoPrototype {
    private String titolo;
    private String font;
    private double margine;
    private String lingua;
    private final List<String> paragrafi; // Oggetto interno mutabile!

    public Documento(String font, double margine, String lingua) {
        this.font = font;
        this.margine = margine;
        this.lingua = lingua;
        this.paragrafi = new ArrayList<>();
    }

    public void setTitolo(String titolo) { this.titolo = titolo; }
    public void aggiungiParagrafo(String testo) { this.paragrafi.add(testo); }

    // IL CUORE DEL PATTERN: crea e restituisce una copia di se stesso
    @Override
    public Documento clone() {
        // Copio i campi base (font, margine, lingua, titolo)
        Documento copia = new Documento(this.font, this.margine, this.lingua);
        copia.setTitolo(this.titolo);

        // COPIA PROFONDA della lista: creo una nuova ArrayList con gli stessi paragrafi,
        // così se aggiungo righe al clone non modifico il modello originale!
        for (String p : this.paragrafi) {
            copia.aggiungiParagrafo(p);
        }
        return copia;
    }

    public void stampa() {
        System.out.println("=== " + titolo + " (" + font + ", margine " + margine + ", " + lingua + ") ===");
        for (String p : paragrafi) System.out.println("  - " + p);
    }
}

// 3. PROTOTYPE REGISTRY (opzionale): l'archivio dei modelli già pronti
class RegistroDocumenti {
    private final Map<String, DocumentoPrototype> modelli = new HashMap<>();

    public void salvaModello(String nome, DocumentoPrototype doc) {
        modelli.put(nome, doc);
    }

    public DocumentoPrototype nuovoDaModello(String nome) {
        DocumentoPrototype modello = modelli.get(nome);
        // Attenzione: restituisce SEMPRE .clone(), mai il modello originale!
        return (modello != null) ? modello.clone() : null;
    }
}

// 4. CLIENT: usa i modelli senza fare "new" sulle classi concrete
public class MainDocumenti {
    public static void main(String[] args) {
        // --- FASE 1: Setup iniziale (fatto una volta sola) ---
        Documento templateLettera = new Documento("Arial", 2.0, "IT");
        templateLettera.setTitolo("Bozza");
        templateLettera.aggiungiParagrafo("Spett.le Cliente,");

        RegistroDocumenti registro = new RegistroDocumenti();
        registro.salvaModello("letteraFormale", templateLettera);

        // --- FASE 2: Uso da parte del client ---
        // Il client NON fa "new Documento(...)": chiede una copia del modello!
        Documento doc1 = (Documento) registro.nuovoDaModello("letteraFormale");
        doc1.setTitolo("Preventivo Marzo");
        doc1.aggiungiParagrafo("In allegato trova l'offerta economica.");

        Documento doc2 = (Documento) registro.nuovoDaModello("letteraFormale");
        doc2.setTitolo("Sollecito Pagamento");
        doc2.aggiungiParagrafo("Le ricordiamo la scadenza della fattura.");

        templateLettera.stampa(); // Ha ancora solo "Spett.le Cliente,"!
        doc1.stampa();            // Ha "Spett.le Cliente," + offerta economica
        doc2.stampa();            // Ha "Spett.le Cliente," + sollecito
    }
}
```

---
### DESIGN PATTERN STRUTTURALI
#### ADAPTER
L'**Adapter** è il primo dei design pattern **strutturali** ed è esattamente l'equivalente software di un **adattatore per prese elettriche**: serve a far collaborare due componenti che parlano "lingue" (interfacce) incompatibili tra loro, senza dover modificare nessuno dei due.

##### 1. I quattro ruoli del pattern
- **`Target`:** l'interfaccia (il contratto) che il `Client` conosce e si aspetta di usare.
- **`Client`:** il codice applicativo che invoca le operazioni esclusivamente tramite `Target`, ignorando l'esistenza della libreria adattata.
- **`Adaptee`:** la classe preesistente o di libreria che offre le funzionalità utili ma ha un'interfaccia incompatibile.
- **`Adapter`:** il traduttore che implementa `Target`, riceve le chiamate del client e le inoltra all'`Adaptee` convertendo parametri, sequenze di chiamate o valori di ritorno.

##### 2. Il problema: un'ottima libreria, ma con l'interfaccia sbagliata
Immagina di avere già sviluppato la tua applicazione, in cui tutto il codice (`Client`) si aspetta di interagire con un determinato contratto (`Target`), ad esempio chiamando `getLabel()` e `oneUp()`. A un certo punto vuoi integrare una classe già pronta o una libreria esterna (`Adaptee`, es. `LabelServer`) che fa proprio il lavoro che ti serve, ma **ha nomi di metodi, parametri o tipi di ritorno diversi** (ad esempio espone `nextLabel(int)` e `skip(int)`).

- **Perché non modifichi il `Client`?** Perché dovresti riscrivere tutti i punti dell'applicazione che usano `Target`, accoppiando il tuo programma a quella specifica libreria.
- **Perché non modifichi l'`Adaptee`?** Perché spesso è una libreria esterna di cui non hai il codice sorgente, oppure è già usata altrove con il suo contratto originale.
- **La soluzione Adapter:** Crei una classe intermediaria (`Adapter`) che si presenta al `Client` rispettando il contratto atteso (`Target`) e, al proprio interno, **traduce** ogni chiamata nel metodo corrispondente dell'`Adaptee`.

##### 3. Le due varianti: Object Adapter vs Class Adapter
La dispensa distingue due modi diversi di costruire l'adattatore (illustrati con l'esempio `Label` e `LabelC` nella sezione 8.2.2):

1. **Object Adapter (basato sulla composizione — la variante più usata):**
    - `Adapter` **implementa** `Target` e **conserva al suo interno un riferimento** (un campo) all'oggetto `Adaptee`.
    - Quando il client chiama `request()`, l'adattatore delega la chiamata al proprio campo `adaptee.specificRequest()`.
    - _Vantaggio:_ è molto flessibile. Puoi passare l'`Adaptee` dall'esterno, sostituirlo a runtime con una sua sottoclasse oppure istanziarlo pigramente (_lazy initialisation_) solo alla prima chiamata che ne ha davvero bisogno (come mostra il frame `opt` nel diagramma di sequenza della Figura 8.2).

2. **Class Adapter (basato sull'ereditarietà):**
    - `Adapter` **implementa** `Target` ed **estende** (`extends`) direttamente `Adaptee`.
    - Non ha bisogno di un campo interno perché eredita direttamente i metodi dell'`Adaptee` e li richiama su se stesso.
    - _Caratteristica chiave:_ è un **adapter a due vie**, perché l'oggetto risultante è sia un `Target` sia un `Adaptee`, quindi può essere passato a codice che si aspetta l'uno o l'altro tipo. Di contro, è legato rigidamente a quella specifica classe `Adaptee` (non può adattarne altre sottoclassi a runtime e in Java non funziona se devi adattare più classi contemporaneamente, perché non c'è ereditarietà multipla).

##### 4. Esempio pratico in Java (ispirato a `Label` / `LabelServer`)
Ecco come appare nel codice l'esempio in entrambe le varianti:
```java
// 1. TARGET: il contratto atteso dal nostro Client
interface ILabel {
    String getLabel();
    void oneUp();
}

// 2. ADAPTEE: la libreria esterna con metodi incompatibili
class LabelServer {
    private int current = 1;
    private final String prefix;

    public LabelServer(String prefix) {
        this.prefix = prefix;
    }

    public String nextLabel(int offset) {
        return prefix + "-" + (current + offset);
    }

    public void skip(int step) {
        current += step;
    }
}

// 3A. OBJECT ADAPTER (Composizione + Lazy Initialization)
class Label implements ILabel {
    private LabelServer server; // Riferimento all'Adaptee
    private final String prefix;

    public Label(String prefix) {
        this.prefix = prefix;
    }

    // Crea il server solo quando serve davvero (lazy)
    private LabelServer getServer() {
        if (server == null) {
            server = new LabelServer(prefix);
        }
        return server;
    }

    @Override
    public String getLabel() {
        return getServer().nextLabel(0); // Traduce getLabel() -> nextLabel(0)
    }

    @Override
    public void oneUp() {
        getServer().skip(1);             // Traduce oneUp() -> skip(1)
    }
}

// 3B. CLASS ADAPTER (Ereditarietà -> Adapter a due vie)
class LabelC extends LabelServer implements ILabel {
    public LabelC(String prefix) {
        super(prefix);
    }

    @Override
    public String getLabel() {
        return nextLabel(0); // Chiama il metodo ereditato
    }

    @Override
    public void oneUp() {
        skip(1);             // Chiama il metodo ereditato
    }
}

// 4. CLIENT: conosce solo ILabel
public class MainAdapter {
    public static void main(String[] args) {
        ILabel etichetta = new Label("ORD"); // Oppure new LabelC("ORD")
        System.out.println(etichetta.getLabel()); // Stampa: ORD-1
        etichetta.oneUp();
        System.out.println(etichetta.getLabel()); // Stampa: ORD-2
    }
}
```

###### Due punti da ricordare per l'esame
- **Non confondere Adapter con Facade:** _Adapter_ fa comunicare due interfacce **incompatibili** traducendo un contratto in un altro; _Facade_ invece prende un sottosistema complesso formato da più classi e offre un'interfaccia nuova **più semplice e di alto livello**.
- **Precondizioni, postcondizioni e costo:** Oltre a tradurre i nomi dei metodi, l'adattatore può verificare precondizioni prima di delegare all'`Adaptee` e garantire postcondizioni dopo la chiamata. Il costo è un livello aggiuntivo di indirezione (una chiamata in più a ogni operazione).

>[!info] In breve...
>Se ad esempio sul quel codice, in futuro dovessi cambiare libreria non devo modificare il main, ma solo la classe adapter in modo da tradurre le operazioni del nuovo adaptee in base all'interfaccia che il client (main) usa

###### Diagramma UML
![[Pasted image 20261128105120.png|647]]

---
#### FACADE
Il **Facade** è il secondo pattern strutturale ed è esattamente il contrario di un pannello pieno di levette e manopole: **nasconde la complessità di un intero sottosistema dietro un unico pulsante semplice e ad alto livello**.

#### 1. Il problema: troppe classi e troppe chiamate da coordinare
Immagina un sottosistema formato da molte classi che svolgono ciascuna un compito specifico — ad esempio, in una biblioteca (l'esempio `Registro` del tuo testo) hai:

- `Soci` (per controllare se un utente è iscritto),
- `BlockList` (per verificare se l'utente è abilitato ai prestiti),
- `ListaLibri` (per vedere se il libro è libero e rimuoverlo dagli scaffali),
- `Prestiti` (per registrare l'associazione tra socio e libro).

**Cosa succede senza Facade?** Ogni client che vuole semplicemente "prestare un libro" deve conoscere tutte e quattro queste classi, sapere in quale ordine esatto chiamarle e gestire ogni controllo intermedio. Se domani cambia una regola interna (ad esempio si aggiunge un quinto controllo), devi modificare tutti i client.

**La soluzione Facade:** Crei una classe "facciata" (es. `Registro`) che espone al client **poche operazioni semplici orientate al suo obiettivo** (es. `prestaLib(socio, lib)`) e, al proprio interno, orchestra nell'ordine giusto tutte le classi del sottosistema, facendo i vari controlli ecc... .

#### 2. Come funziona e cosa cambia nella struttura
![[Pasted image 20261128111117.png|423]]

- **Prima della Facade:** ogni `Client` ha frecce di dipendenza verso tutte le classi interne (`ClassA`, `ClassB`, `ClassC`).
- **Con la Facade:** i `Client` puntano **solo** a `Facade`, mentre è `Facade` a possedere i riferimenti e a coordinare `ClassA`, `ClassB` e `ClassC`.
- **Nota importante:** Facade **non nasconde per forza** le classi interne ai client avanzati (chi ha bisogno di funzioni di basso livello può ancora usarle, a meno che non vengano rese private o chiuse in un package/modulo). Inoltre, le classi del sottosistema **non conoscono la Facade**: la comunicazione è a senso unico, dal client verso la facciata e dalla facciata verso il sottosistema.

#### 3. Esempio pratico (dal pdf: `Translator`)
Guarda, dove `Translator` fa da facciata coordinando due dizionari separati (`English` e `Italian`):
Il `Translator` espone ai client solo `addEnglish(String)` e `multiPrinting()`, le funzioni delle classi che gestisce invece il client non le vede.
```java
import java.util.List;

// SOTTOSISTEMA - Classe 1
class English {
    private String text = " ";
    private final List<String> d = List.of("Alright", "Hello", "Understood", "Yes");

    boolean test(String s) { return d.contains(s); }
    void add(String s) { text = text + " " + s; }
    int getIndex(String s) { return d.indexOf(s); }
    void printText() { System.out.println(text); }
}

// SOTTOSISTEMA - Classe 2
class Italian {
    private String text = " ";
    private final List<String> d = List.of("Va bene", "Ciao", "Capito", "Sì");

    void add(int i) { text = text + " " + d.get(i); }
    void printText() { System.out.println(text); }
}

// FACADE: offre un punto di accesso semplice e coordinato al client
class Translator {
    private final English e = new English();
    private final Italian i = new Italian();

    // Il client chiama un solo metodo; la Facade coordina entrambi i dizionari
    void addEnglish(String s) {
        if (e.test(s)) {
            e.add(s);
            i.add(e.getIndex(s));
        }
    }

    void multiPrinting() {
        System.out.print("Italiano: "); i.printText();
        System.out.print("English: ");  e.printText();
    }
}
```

Il client chiama solo `translator.addEnglish("Hello")` e `translator.multiPrinting()`, senza dover sapere che dietro ci sono due liste parallele da tenere sincronizzate tramite `getIndex(s)`.
  
###### Tre distinzioni fondamentali per l'esame
1. **Facade vs Adapter:** _Adapter_ serve a **tradurre** un'interfaccia incompatibile in un'altra attesa dal client; _Facade_ non traduce contratti incompatibili, ma **semplifica e unifica** l'accesso a un gruppo di classi già esistenti.
2. **Facade vs Mediator:** Anche _Mediator_ coordina più oggetti, ma in modo **bidirezionale** tra pari (`Colleague` $\leftrightarrow$ `Mediator` $\leftrightarrow$ `Colleague`, dove i colleghi conoscono il mediatore); _Facade_ invece è **unidirezionale** (`Client` $\rightarrow$ `Facade` $\rightarrow$ `Sottosistema`, dove il sottosistema ignora la facciata).
3. **Cosa NON fa una Facade:** Una facciata non deve limitarsi a ripubblicare tutti i 14 metodi delle classi interne (altrimenti non semplifica nulla). Inoltre, la sola presenza di una Facade non garantisce automaticamente transazioni atomiche o sicurezza nei thread: quelli richiedono sincronizzazione esplicita.
---

