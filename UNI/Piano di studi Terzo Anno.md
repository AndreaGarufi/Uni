Considero 3 possibili curricula:
Artificial Intelligence and Robotics, Data Science, Programming Web, Mobile and Virtualized Environment.

### CURRICULUM: Artificial Intelligence and Robotics

#### 1. Materie d'Indirizzo (Obbligatorie)

##### **Artificial Intelligence**

- **Insegnamento:** Obbligatorio d'indirizzo
    
- **Settore Scientifico-Disciplinare:** INF/01
    
- **Programma Riassunto:**
    
![[Pasted image 20260724174444.png|367]]
        
- **Obiettivi Chiave:**
    
    - Comprendere l'architettura degli Agenti Intelligenti.
        
    - Sviluppare capacità di formalizzare e risolvere problemi combinatori complessi, ottimizzazione e soddisfacimento di vincoli.
        
    - Applicare la logica formale e la probabilità per il ragionamento automatico e le decisioni in condizioni d'incertezza.
        
    - Comprendere le basi formali dell'apprendimento da dati.
    
- **Modalità d'Esame:**
    
    - L'esame si svolge oralmente.
		I quesiti riguardano tutte le parti del programma. In aggiunta, gli studenti presenteranno alla prova orale un progetto implementativo su uno degli argomenti del corso approfondito durante il Laboratorio.
        
- **Esempio Pratico di Attività:**
    
    - Progettare e implementare l'algoritmo $A^*$ per trovare il percorso ottimale di un agente in una mappa a griglia con ostacoli, oppure scrivere un motore di gioco per il **Tris / Scacchi** implementando l'algoritmo **Minimax con potatura Alpha-Beta**.
        
- **Opinione Personale (Peso Pratico & Concettuale):**
    
    - È la **materia fondativa ed essenziale** dell'intero percorso. Ha un'impostazione fortemente basata sull'approccio classico (Russell & Norvig), indispensabile per costruire una forma mentis solida.
        
    - Invece di trattare il Machine Learning solo come una "scatola nera" (framework già pronti), ti forza a capire la modellazione del problema, gli algoritmi di ricerca nello spazio degli stati e il ragionamento probabilistico/logico. È impegnativa dal punto di vista concettuale e algoritmico, ma imprescindibile se vuoi davvero lavorare nell'ambito AI.
        
- **Sbocchi Professionali in Italia:**
    
    - **AI Software Developer / Engineer:** Sviluppatore di moduli intelligenti e algoritmi di ottimizzazione decisionale.
        
    - **Junior Machine Learning Engineer:** Figura focalizzata sulla modellazione e implementazione di algoritmi predittivi.
        
    - **Consulting & Tech Services:** Inserimento in società di consulenza IT (es. Accenture, Deloitte, Reply) che implementano automazione di processi e AI per grandi aziende.
    
- **Indice di Difficoltà:** **78 / 100** _(Alta astrazione concettuale, richiedendo una solida padronanza di logica formale, probabilità e complessità algoritmica)._

---

##### **2. Programmazione di Sistemi Robotici e Laboratorio**

- **Insegnamento:** Obbligatorio d'indirizzo
    
- **Settore Scientifico-Disciplinare:** INF/01
    
- **Programma Riassunto:**
![[Pasted image 20260724174534.png|652]]
        
- **Obiettivi Chiave:**
    
    - Modellare matematicamente sistemi dinamici e fisici reali.
        
    - Progettare ed implementare controllori in retroazione (PID).
        
    - Programmare il comportamento di robot mobili (terrestri/aerei) e bracci meccanici.
        
    - Testare algoritmi di navigazione autonoma in laboratorio e simulazione.
        
- **Modalità d'esame:**
    
    - Progetto
    - Prova orale
        
- **Esempio Pratico di Attività:**
    
    - Calibrare e programmare un controllore **PID** per far mantenere la rotta rettilinea a un robot _differential drive_ compensando gli errori dei motori tramite gli encoder, oppure implementare un algoritmo di **obstacle avoidance** per far navigare autonomamente un drone o un rover simulato.
        
- **Opinione Personale (Peso Pratico & Concettuale):**
    
    - Ponte perfetto tra informatica, fisica e ingegneria. Estremamente appagante per chi ama la programmazione vicina all'hardware e la robotica concreta.
        
- **Sbocchi Professionali in Italia:**
    
    - **Robotics Software Engineer:** Sviluppatore di firmware e algoritmi di navigazione/controllo.
        
    - **Embedded Systems Developer:** Ingegnere software su sistemi embedded e IoT industriale.
        
    - **Automation Engineer / Industry 4.0 Developer:** Inserimento nel settore della meccatronica, automotive o aerospazio (es. STMicroelectronics, Comau, Leonardo).
        
- **Indice di Difficoltà:** **82 / 100** _(Richiede solide basi matematico-fisiche sui sistemi dinamici e competenze pratiche di programmazione a basso/medio livello)._

---


#### 2. Materie Opzionali (Gruppo A1)

##### **Embedded Systems**

- **Insegnamento:** Opzionale (Gruppo A1)
    
- **Settore Scientifico-Disciplinare:** INF/01
    
- **Programma Riassunto:**
    ![[Pasted image 20260724174559.png|625]]
        
- **Obiettivi Chiave:**
    
    - Progettare e sviluppare software a basso livello (firmware) per schede e microcontrollori.
        
    - Padroneggiare i protocolli di comunicazione bus per l'interfacciamento tra chip, sensori e attuatori.
        
    - Comprendere i vincoli di tempo reale (Real-Time) e la gestione deterministica della CPU tramite RTOS.
        
    - Sviluppare competenze pratiche nell'ottimizzazione del codice per ambienti con risorse di calcolo e memoria fortemente limitate.
        
- **Modalità d'Esame:**
    
    - Realizzazione di un **progetto pratico** per microcontrollore, seguito da una prova orale sui concetti teorici e sulla discussione del codice prodotto.
        
- **Esempio Pratico di Attività:**
    
    - Scrivere un firmware in C che utilizzi un **RTOS** per gestire contemporaneamente la lettura di un sensore di temperatura tramite bus **I2C**, l'invio dei dati tramite bus **UART** e il controllo di un motore tramite segnale **PWM**, garantendo che ciascun task rispetti rigidi tempi di esecuzione in millisecondi senza bloccare la CPU.
        
- **Opinione Personale (Peso Pratico & Concettuale):**
    
    - È una materia **fondamentale e strategica** per chi segue il curriculum di Robotica. Un robot o un dispositivo AI "edge" non è altro che un sistema embedded complesso. Questo corso ti insegna a programmare "vicino al metallo", dove la memoria è limitata e il tempo di risposta deve essere rigorosamente deterministico. Completa perfettamente il corso di _Programmazione di Sistemi Robotici_.
        
- **Sbocchi Professionali in Italia:**
    
    - **Embedded Software / Firmware Engineer:** Sviluppatore di firmware C/C++ per dispositivi elettronici, automotive, domotica e robotica.
        
    - **IoT Systems Developer:** Sviluppatore di nodi ed edge device intelligenti per la rete Internet delle Cose.
        
    - **Automotive / Industrial Automation Software Engineer:** Inserimento in grandi realtà industriali e tecnologiche (es. STMicroelectronics, Marelli, Comau, Leonardo).
        
- **Indice di Difficoltà:** **76 / 100** _(Richiede confidenza con il linguaggio C/C++, la manipolazione dei bit, la gestione dei puntatori e la comprensione dell'architettura hardware sottostante)._

---

**MACHINE LEARNING NON TROVATO**

---

##### **Natural Language Processing**

- **Insegnamento:** Opzionale
    
- **Settore Scientifico-Disciplinare:** INF/01
    
- **Programma Riassunto:**
    
![[Pasted image 20260724174623.png]]
        
- **Obiettivi Chiave:**
    
    - Comprendere come trasformare il linguaggio naturale (testo non strutturato) in rappresentazioni matematiche/vettoriali elaborabili dagli algoritmi.
        
    - Progettare e addestrare/adattare modelli di Machine Learning e Deep Learning per compiti di analisi del testo.
        
    - Saper effettuare il fine-tuning di modelli linguistici moderni (Transformers) su dataset specifici di dominio.
        
    - Costruire pipeline end-to-end per applicazioni NLP industriali (es. analisi del sentiment, chatbot o estrazione di informazioni).
        
- **Modalità d'Esame:**
    
    - **Esame scritto + Colloquio Orale**
        
- **Esempio Pratico di Attività:**
    
    - Realizzare uno script Python che utilizzi la libreria Hugging Face Transformers per effettuare il **fine-tuning di un modello BERT pre-addestrato**, addestrandolo a classificare recensioni di prodotti (es. Amazon/TripAdvisor) in positive, negative o neutrali (Sentiment Analysis), valutandone l'accuratezza con metriche F1-score e matrice di confusione.
        
- **Opinione Personale (Peso Pratico & Concettuale):**
    
    - È una delle materie **più attuali, richieste e strategiche** in assoluto nel panorama tech odierno. Con l'esplosione dei Large Language Models (LLM) e dell'AI generativa, comprendere cosa c'è "sotto il cofano" delle architetture Transformer ti dà un vantaggio competitivo enorme sul mercato del lavoro. Unisce concetti teorici affascinanti di linguistica e matematica con uno sviluppo Python estremamente pratico.
        
- **Sbocchi Professionali in Italia:**
    
    - **NLP Engineer / Specialist:** Sviluppatore di soluzioni per la comprensione del testo, sintesi automatica e motori di ricerca semantici.
        
    - **AI / Machine Learning Engineer:** Ingegnerizzazione di modelli di Deep Learning per elaborazione dati non strutturati.
        
    - **Conversational AI Developer:** Progettazione e sviluppo di agenti conversazionali avanzati (Chatbot, assistenti virtuali e sistemi RAG aziendali) in aziende di consulenza e tech (es. Reply, Engineering, Accenture).
        
- **Indice di Difficoltà:** **75 / 100** _(Richiede una buona padronanza di Python, concetto di vettori/matrici e familiarità con la logica delle reti neurali e del Deep Learning)._

---

##### **Internet of Things**

- **Insegnamento:** Opzionale
    
- **Settore Scientifico-Disciplinare:** INF/01
    
- **Programma Riassunto:**
    
 ## Contenuti del Corso
![[Pasted image 20260724174151.png|438]]
![[Pasted image 20260724174202.png|441]]

- **Obiettivi Chiave:**
    
    - Comprendere e progettare l'architettura end-to-end di un sistema IoT, dalla raccolta dati del sensore all'analisi su Cloud.
        
    - Saper selezionare ed implementare i protocolli di comunicazione adeguati ai vincoli energetici, di memoria e di banda.
        
    - Interfacciare nodi sensore con infrastrutture di rete e broker di messaggistica.
        
    - Valutare le problematiche di sicurezza e riservatezza dei dati generati da dispositivi IoT.
        
- **Modalità d'Esame:**
    
    - La verifica delle competenze acquisite viene effettuata tramite esame scritto e colloquio orale. La valutazione complessiva tiene conto della successiva prova progettuale. Il colloquio orale è da intendersi integrativo alla prova scritta, con risultato almeno sufficiente. Tutte le prove di cui sopra sono obbligatorie. Il progetto è obbligatorio e potrà essere richiesto esclusivamente dopo il superamento della prova scritta e orale (se richieste). Il progetto assegnato dovrà essere consegnato entro 45 giorni dall'assegnazione e potrà essere proposto dallo studente o dal gruppo di persone.
    
- **Esempio Pratico di Attività:**
    
    - Progettare un sistema per il monitoraggio della qualità dell'aria: programmare una scheda **ESP32** per leggere dati da un sensore di gas/polveri, trasmettere le misurazioni in formato JSON tramite il protocollo **MQTT** a un broker **Mosquitto**, e visualizzarle in tempo reale su una dashboard grafica (**Node-RED** o **Grafana**), impostando alert automatici via e-mail al superamento di determinate soglie.
        
- **Opinione Personale (Peso Pratico & Concettuale):**
    
    - È una materia **estremamente pratica e concreta**, fantastica da affiancare ad _Embedded Systems_ o a corsi di rete. Ti dà la visione d'insieme su come far dialogare il mondo fisico con il web. Nel contesto della robotica e dell'AI, comprendere l'IoT è fondamentale per la domotica, la gestione di flotte di droni/robot e l'Industria 4.0.
        
- **Sbocchi Professionali in Italia:**
    
    - **IoT Solution Engineer / Developer:** Sviluppatore e integratore di sistemi connessi per aziende smart o manifatturiere.
        
    - **Cloud & Edge IoT Architect:** Progettista di infrastrutture di raccolta ed elaborazione dati su cloud e nodi periferici.
        
    - **Smart Automation & Industry 4.0 Specialist:** Consulente e sviluppatore per la digitalizzazione delle filiere industriali e dei sistemi urbani intelligenti (Smart Cities).
        
- **Indice di Difficoltà:** **70 / 100** _(Accessibile e molto orientato ai progetti pratici; richiede una buona comprensione delle reti di calcolatori e della programmazione di rete)._

---

##### **Social Media Data Analysis**

- **Insegnamento:** Opzionale
    
- **Settore Scientifico-Disciplinare:** INF/01
    
- **Programma Riassunto:**
    ![[Pasted image 20260724174938.png|570]]
        
- **Obiettivi Chiave:**
    
    - Modellare relazioni sociali complesse tramite la teoria dei grafi e la network analysis.
        
    - Estrarre ed elaborare grandi volumi di dati non strutturati e semi-strutturati provenienti dai social media.
        
    - Identificare utenti chiave (influencer/hub), comunità coese e dinamiche di diffusione virale dei contenuti.
        
    - Estrarre il sentiment e le opinioni degli utenti per analisi di mercato o di opinione pubblica.
        
- **Modalità d'Esame:**
    
    **Scritto + progetto**
        
- **Opinione Personale (Peso Pratico & Concettuale):**
    
    - È un esame dal **forte valore pratico e multidisciplinare**, situato esattamente all'incrocio tra Data Science, AI e Network Science. Le intuizioni grafiche (i nodi e le connessioni) rendono i concetti molto visuali e stimolanti. Ti fornisce competenze immediatamente spendibili nel mondo aziendale per il monitoraggio di brand, marketing analitico o analisi delle dinamiche sociali online.
        
- **Sbocchi Professionali in Italia:**
    
    - **Social Data Analyst / Data Scientist:** Specialista nell'estrazione e analisi di dati d'uso e di rete per aziende tech, agenzie media ed e-commerce.
        
    - **Business Intelligence & Market Research Specialist:** Consulente per l'analisi del sentiment di mercato e dei trend di consumo per brand internazionali o società di consulenza.
        
    - **Digital Analytics Consultant:** Ruolo focalizzato sull'ottimizzazione delle strategie digitali basata sui dati presso grandi system integrator (es. Reply, Accenture, Deloitte).
        
- **Indice di Difficoltà:** **68 / 100** _(Molto accessibile e visivo; l'uso intensivo di framework Python consolidati rende la parte teorica più facile da metabolizzare rispetto a corsi più astratti)._

---

### CURRICULUM: Data Science
#### 1. Materie d'Indirizzo (Obbligatorie)

##### **Introduzione al Data Mining**

- **Insegnamento:** Obbligatorio d'indirizzo
    
- **Settore Scientifico-Disciplinare:** INF/01
    
- **Programma Riassunto:**
    
![[Pasted image 20260725111347.png|584]]
        
- **Obiettivi Chiave:**
    
    - Preparazione dei dati grezzi all'estrazione di conoscenza.
        
    - Saper scegliere, implementare e tarare l'algoritmo giusto (supervisionato o non supervisionato) in base al tipo di problema e di dataset.
        
    - Pulire e trasformare i dati per renderli idonei all'analisi statistica e al Machine Learning.
        
    - Valutare rigorosamente le prestazioni dei modelli ed evitare problemi di overfitting.
        
- **Modalità d'Esame:**
    
   ![[Pasted image 20260725111503.png|507]]
        
- **Esempio Pratico di Attività:**
    
    - Prendere un dataset di e-commerce o bancario (es. prevenzione dell'abbandono dei clienti / _churn prediction_): pulire i dati mancanti e bilanciare il dataset, applicare il **K-Means** per segmentare la clientela in gruppi comportamentali, e addestrare un **Albero di Decisione** o un classificatore **Random Forest** per predire quali clienti rischiano di cancellare l'abbonamento.
        
- **Opinione Personale (Peso Pratico & Concettuale):**
    
    - È la **pietra angolare e la materia simbolo** di tutto il curriculum di Data Science. A differenza di corsi più focalizzati su modelli complessi o AI generativa, qui ci si sporca davvero le mani con i dati tabellari e con la fase di _data cleaning_ e _feature engineering_ (che nella realtà lavorativa occupa l'80% del tempo di un Data Scientist). Fondamentale per costruire un approccio solido e pragmatico.
        
- **Sbocchi Professionali in Italia:**
    
    - **Junior Data Scientist:** Modellazione e sviluppo di algoritmi predittivi per settori e-commerce, bancario, assicurativo e industriale.
        
    - **Data Analyst:** Analisi esplorativa dei dati e generazione di insight aziendali per guidare decisioni di business.
        
    - **Business Intelligence & Analytics Consultant:** Inserimento in grandi società di consulenza tech (es. Deloitte, PwC, Reply, Accenture) per la trasformazione data-driven delle aziende.
        
- **Indice di Difficoltà:** **74 / 100** _(Materia altamente applicativa; richiede una buona padronanza di Python, abilità di ragionamento analitico e comprensione di metriche statistiche/probabilistiche)._

---

**Data Analysis and Predictive Techniques and Laboratory NON TROVATA** 

---

#### 2. Materie Opzionali (Gruppo A5)

##### **Startup di Impresa e Modelli di Business**

- **Insegnamento:** Opzionale (Gruppo A5)
    
- **Settore Scientifico-Disciplinare:** SECS-P/08 (o ambito gestionale/aziendale)
    
- **Programma Riassunto:**
    
Negli ultimi anni, l’interesse per le startup ha registrato una crescita significativa, alimentata dall’accelerazione dei processi di digitalizzazione, dalla diffusione di tecnologie emergenti e dalla progressiva centralità dell’innovazione nei sistemi economici contemporanei. In tale contesto, la creazione di una nuova impresa è sempre più percepita non solo come opzione professionale, ma anche come possibile percorso di valorizzazione delle competenze tecniche e progettuali, soprattutto da parte di studenti e laureati in ambito ingegneristico e informatico.

Sebbene l’imprenditorialità costituisca da tempo un tema consolidato nella letteratura economico-aziendale, l’enfasi crescente sul fenomeno startup rischia talvolta di generare una rappresentazione semplificata del processo imprenditoriale. In particolare, l’attenzione mediatica verso i casi di successo può alimentare una visione riduttiva della startup come veicolo rapido di affermazione economica o sociale, trascurandone invece la complessità gestionale, l’elevato grado di incertezza e le condizioni necessarie alla sua effettiva sostenibilità.

La nascita di una startup rappresenta, infatti, un processo articolato, sperimentale e intrinsecamente fragile, che richiede non soltanto intuizione, creatività ed energia, ma anche metodo, competenze multidisciplinari e capacità di analisi. L’obiettivo è comprendere che il valore di una nuova iniziativa imprenditoriale non risiede esclusivamente nella qualità tecnica della soluzione proposta, ma nella sua capacità di rispondere a un bisogno reale, di generare valore per gli utenti e di tradursi in un modello di business sostenibile, scalabile e verificabile nel tempo. In questa prospettiva, il rischio della cosiddetta _death valley_ evidenzia come molte iniziative, pur tecnologicamente promettenti, non riescano a consolidarsi per carenze di validazione, organizzazione, posizionamento strategico o sostenibilità economico-finanziaria.

Il corso è articolato in tre nuclei tematici principali. La prima parte è dedicata alla figura dell’imprenditore e analizza il ruolo delle caratteristiche individuali, delle motivazioni, delle competenze e delle capacità decisionali che incidono sull’avvio di un nuovo progetto imprenditoriale. In questa sezione, particolare rilievo sarà dato anche alla dimensione del team, alla complementarità delle competenze e al contributo che profili tecnico-ingegneristici possono offrire nella generazione di soluzioni innovative.

La seconda parte affronta il concetto di startup nelle sue diverse configurazioni, approfondendone le specificità rispetto ad altre forme d’impresa, incluse le PMI innovative. Saranno esaminati i principali aspetti relativi alla costituzione della startup, al suo ciclo di vita, agli attori dell’ecosistema dell’innovazione e alle criticità che caratterizzano le prime fasi di sviluppo. In tale ambito, il confronto con testimonianze ed esperienze applicative consentirà agli studenti di comprendere più concretamente le sfide connesse alla trasformazione di un’idea tecnologica in un’iniziativa imprenditoriale strutturata.

La terza parte del corso, infine, è dedicata alla costruzione del Business Plan, inteso non come adempimento formale, ma come strumento di sintesi strategica, organizzativa ed economico-finanziaria del progetto imprenditoriale. Attraverso l’analisi delle sue componenti fondamentali e lo svolgimento di esercitazioni applicative, gli studenti saranno guidati nella traduzione di un’idea innovativa in una proposta imprenditoriale coerente, argomentata e sostenibile


- **Obiettivi Chiave:**
    
    - Imparare a validare un'idea tecnologica sul mercato prima di spendere mesi a programmarla.
        
    - Saper analizzare la sostenibilità economica di un progetto software tramite il Business Model Canvas.
        
    - Padroneggiare le tecniche di comunicazione e presentazione (_pitching_) per vendere un'idea a clienti o investitori.
        
    - Comprendere il linguaggio economico e gestionale indispensabile per dialogare con manager e stakeholder.
        
- **Modalità d'Esame:**
    
    ![[Pasted image 20260725111948.png]]
        
- **Esempio Pratico di Attività:**
    
    - Ideare una piattaforma SaaS di Data Analytics per piccoli e-commerce: identificare la proposta di valore nel **Value Proposition Canvas**, definire la strategia di prezzo (es. abbonamento mensile a scaglioni), identificare le metriche per l'**MVP** e presentare un **pitch visivo di 5 minuti** per convincere una giuria o una commissione a "investire" nel progetto.
        
- **Opinione Personale (Peso Pratico & Concettuale):**
    
    - È un esame **estremamente rinfrescante e strategico**, ideale per spezzare il carico di materie fortemente algoritmiche o matematiche. Insegna la lezione fondamentale che ogni informatico dovrebbe apprendere: _"scrivere del codice perfetto è inutile se l'applicazione non risolve un reale problema di mercato"_. Utilissimo se sogni di fondare una tua azienda o se vuoi ricoprire ruoli a metà tra tecnologia e gestione del prodotto.
        
- **Sbocchi Professionali in Italia:**
    
    - **IT Startup Founder / Tech Entrepreneur:** Creazione di una propria startup software o spin-off universitario.
        
    - **Technical Product Manager / Product Owner:** Gestione del ciclo di vita dei prodotti software allineando i requisiti tecnici agli obiettivi di business.
        
    - **Innovation Consultant / Analyst:** Ruolo in acceleratori d'impresa, incubatori o nelle divisioni di "Digital Innovation" delle grandi società di consulenza.
        
- **Indice di Difficoltà:** **55 / 100** _(Un esame leggero dal punto di vista matematico e di codice; la difficoltà risiede nel cambio di mentalità, nell'analisi critica del valore di business e nella capacità di esposizione in pubblico)._

---

##### **Programmazione Parallela su Architetture GPU**

- **Insegnamento:** Opzionale
    
- **Settore Scientifico-Disciplinare:** INF/01
    
- **Programma Riassunto:**
    
	- breve storia delle schede grafiche e nascita del GPGPU
	- fondamenti di GPGPU; introduzione a CUDA ed OpenCL
	- programmi imbarazzentemente paralleli in CUDA ed OpenCL
	- benchmarking, ottimizzazione e debugging
	- primitive parallele per riduzioni e scan; implementazione OpenCL e/o CUDA
	- cenni su multi-GPU
        
- **Obiettivi Chiave:**
    
    - Comprendere l'architettura interna delle GPU e il paradigma di calcolo parallelo GPGPU (General-Purpose Computing on GPUs).
        
    - Saper progettare e implementare kernel parallelizzati ad altissime prestazioni in linguaggio C/C++ tramite framework come NVIDIA **CUDA**.
        
    - Individuare e risolvere i colli di bottiglia legati all'accesso in memoria e al trasferimento dati CPU-GPU.
        
    - Accelerare computazioni scientifiche, algoritmi su matrici e pipeline di elaborazione dati.
        
- **Modalità d'Esame:**
    
	    Sono ammesse due modalità per l'esame di fine corso:
	
	- esame di laboratorio: viene assegnato un problema, da affrontare scrivendo un programma per il calcolo parallelo; durata: 3 ore;
	- progettino finale, da concordare con il docente, e da sviluppare in maniera individuale o al piú in coppia; il progetto va consegnato entro 3 mesi, insieme ad una relazione ed una presentazione orale;
	- la consegna della relazione del progettino e la presentazione potranno anche essere effettuati per via telematica.
        
- **Esempio Pratico di Attività:**
    
    - Implementare un **kernel CUDA per la moltiplicazione di grandi matrici** sfruttando la **shared memory** in blocchi (_tiling_) per minimizzare i tempi di lettura dalla memoria globale, dimostrando che l'esecuzione passa da diversi minuti su CPU a pochi millisecondi su GPU per matrici di dimensioni $4000 \times 4000$.
        
- **Opinione Personale (Peso Pratico & Concettuale):**
    
    - È un esame **ad altissimo valore tecnico e strategico**, specialmente per chi sceglie il percorso _Data Science_ o _AI_. Oggi l'addestramento e l'inferenza di qualsiasi modello di Machine Learning/Deep Learning avvengono su GPU. Capire cosa succede "sotto il cofano" a livello di memoria e concorrenza hardware ti trasforma da semplice utilizzatore di librerie ad alto livello a un ingegnere software capace di ottimizzare davvero le prestazioni dei sistemi.
        
- **Sbocchi Professionali in Italia:**
    
    - **HPC (High Performance Computing) Engineer:** Specialista nell'ottimizzazione di algoritmi per supercomputer, simulazioni fisiche e finanza quantitativa.
        
    - **GPU / CUDA Software Developer:** Sviluppatore di librerie ad alte prestazioni per grafica 3D, motori di rendering o sistemi di percezione visiva.
        
    - **AI Hardware & Performance Optimization Specialist:** Ingegnere focalizzato sull'accelerazione hardware dei modelli di Deep Learning presso centri R&D e grandi aziende tech (es. STMicroelectronics, realtà di consulenza avanzata o centri di ricerca).
        
- **Indice di Difficoltà:** **84 / 100** _(Richiede solide competenze di programmazione C/C++, familiarità con i puntatori e una notevole capacità di astrazione per gestire la concorrenza di migliaia di thread in parallelo)._

---

**CALCOLO NUMERICO SO GIA CHE NON MI INTERESSA**

---

Big Data 

Programma Riassunto: 
![[Pasted image 20260725171231.png]]


**Obiettivi Chiav**e:Comprendere e padroneggiare i paradigmi di calcolo distribuito (MapReduce, Spark) per la manipolazione di dataset massivi. Apprendere le tecniche di hashing probabilistico (LSH, Min-Hashing) e di riduzione dimensionale (SVD, CUR, PCA) per la ricerca di similarità in spazi ad alta dimensione. Sviluppare competenze avanzate nell'analisi e modellazione di grafi complessi e reti sociali (PageRank, Community Detection, Graph Neural Networks). Progettare e valutare architetture per sistemi di raccomandazione, text mining e frequent itemset mining.

**Modalità d'Esame**:L'esame finale consiste in **una prova scritta** ed un **colloquio orale** nel quale viene discusso un progetto.

 La prova scritta è costituita da esercizi e domande di teoria.

Chi non supera la prova scritta, non può sostenere l'orale. La prova scritta può essere visionata prima delle prove orali.

**Esempio Pratico** di Attività:Implementare una pipeline distribuita in PySpark o PyTorch Geometric per generare node embedding (Node2Vec / GCN) ed eseguire community detection su una rete di citazioni scientifiche o su un grande grafo d'acquisto; oppure realizzare un sistema di raccomandazione ed elaborazione con LSH (Locality-Sensitive Hashing) per la deduplicazione veloce di milioni di documenti testuali.

**Opinione Personale (Peso Pratico & Concettuale)**:È uno dei corsi più moderni, dinamici e concreti del percorso accademico. Riesce a combinare in modo eccellente rigore matematico (algebra lineare, probabilità, teoria dei grafi) e strumentazione software di livello industriale (Spark, PyTorch Geometric). Invece di limitarsi ad applicare librerie ad alto livello, spinge a comprendere a fondo i trade-off tra approssimazione algoritmica, memoria ed efficienza computazionale necessari quando i dati non entrano in RAM.

**Sbocchi Professionali in Italia**:Big Data Engineer: Progettazione, implementazione e gestione di pipeline di elaborazione e architetture dati distribuite in ambienti aziendali. Data Scientist / ML Engineer: Realizzazione di sistemi di raccomandazione, modellazione predittiva e analisi di grafi complessi per settori Tech, e-Commerce e Finance. Data & Business Intelligence Analyst: Estrazione di pattern ad alto valore strategico, text mining e analisi di grandi dataset per la consulenza e la gestione aziendale. Consulting & Cloud Tech Specialist: Inserimento in grandi system integrator (es. Reply, Accenture, Deloitte) come specialista in soluzioni Cloud, Spark e Data Analytics.

Indice di Difficoltà: 76 / 100 *(Richiede solide basi di algoritmi su grafi, algebra lineare e probabilità, unite alla capacità di gestire framework di programmazione distribuita e librerie di Graph Machine Learning).*

---

### CURRICULUM: Programming Web, Mobile and Virtualized Environment

#### Materie obbligatorie
**Web and Service Oriented Systems and Laboratory**
Programma Riassunto: 
![[Pasted image 20260725171643.png|569]]
![[Pasted image 20260725171657.png|568]]

**Obiettivi Chiave**:Acquisire i fondamenti concettuali e le competenze operative per la progettazione e lo sviluppo di sistemi distribuiti e applicazioni web server-side. Padroneggiare la programmazione a basso livello tramite socket di rete (Java e C/Unix) e i meccanismi di invocazione remota (RPC/RMI). Sviluppare applicazioni web scalabili e strutturate adottando il pattern MVC, container di servlet e framework enterprise (Spring Boot, Laravel). Progettare, implementare ed esporre API RESTful e servizi web sicuri e manutenibili.

**Modalità d'Esame**: Colloquio orale sugli argomenti del corso, a partire dalla correzione e discussione delle prove in laboratorio svolte e superate in precedenza.

**Esempio Pratico di Attività**: Realizzare una web application full-stack basata su architettura 3-tier utilizzando Spring Boot o Laravel (MVC), integrando un database relazionale tramite ORM/JPA, autenticazione basata su sessioni o token, ed esponendo un set di API RESTful consumate da un client dinamico asincrono.

**Opinione Personale (Peso Pratico & Concettuale):** È l'insegnamento che fa da ponte definitivo tra i concetti teorici delle reti di calcolatori e la programmazione software professionale per il web. Richiede di padroneggiare sia la parte sistemica e di basso livello (gestione manuale dei socket, thread concorrenti, chiamate remote) sia i moderni framework aziendali (Spring Boot, Laravel). È altamente formativo e spendibile immediatamente nel mondo del lavoro.

**Sbocchi Professionali in Italia**:Full-Stack / Backend Web Developer: Sviluppatore di applicazioni web complesse, portali aziendali e servizi backend scalabili. Java / Enterprise Developer: Specialista nello sviluppo di applicazioni enterprise basate su ecosistemi Java (Spring Boot, Servlets, JPA). Software Engineer per Sistemi Distribuiti: Progettista di architetture a microservizi, API REST e infrastrutture di comunicazione di rete. Consulting & System Integration: Inserimento in società di consulenza e system integrator IT (es. Reply, Accenture) per lo sviluppo di soluzioni web e system integration.

Indice di Difficoltà: 74 / 100 *(Richiede un salto di qualità nella gestione della concorrenza, della programmazione di rete a basso livello e nella padronanza simultanea di più piattaforme tecnologiche tra Java, PHP e framework moderni).*

---

**Technologies for Advanced Programming** 

**Programma Riassunto:** ![[Pasted image 20260725172058.png]]
    

**Obiettivi Chiave**:Progettare e realizzare un'architettura di pipeline di dati end-to-end distribuita, scalabile e resiliente. Padroneggiare la containerizzazione con Docker per garantire l'isolamento e la riproducibilità degli ambienti di esecuzione. Applicare i principi del paradigma Event-Driven e la gestione di flussi di dati in tempo reale con Apache Kafka. Integrare pratiche DevOps automatizzate (CI/CD) per la fase di testing, build e deployment continuo del software.

**Modalità d'Esame**:![[Pasted image 20260725172155.png]]

**Esempio Pratico di Attività**:Realizzare ed orchestrare (con Docker Compose) una pipeline in tempo reale che cattura eventi da una sorgente esterna (es. API di social media, dati finanziari o meteo), li invia a un cluster Apache Kafka, li elabora con Spark Streaming per ricavare metriche o aggregazioni live, salva i risultati su Elasticsearch e ne mostra l'andamento in tempo reale su una dashboard Kibana, il tutto coperto da test automatizzati via GitHub Actions.

**Opinione Personale (Peso Pratico & Concettuale)**:È uno dei corsi più moderni, orientati al mercato del lavoro e pratici dell'intero percorso di studi. Lascia ampio spazio all'ingegnerizzazione del software e alla comprensione del ciclo di vita dei dati. Sviluppare il progetto finale richiede impegno e pazienza nel far comunicare correttamente più tecnologie eterogenee dentro container separati, ma fornisce un bagaglio di competenze in ambito Data Engineering e DevOps immediatamente spendibile nei colloqui tecnici.

**Sbocchi Professionali in Italia:** Data Engineer: Progettista e sviluppatore di infrastrutture per la gestione, l'elaborazione e il flusso di grandi volumi di dati. DevOps / Cloud Engineer: Specialista nella gestione di container, orchestrazione e automazione di pipeline CI/CD in ambienti cloud. Backend & Distributed Systems Engineer: Sviluppatore di architetture a microservizi reattive ed event-driven. IT Tech Consultant: Inserimento in grandi società di consulenza tecnologica (es. Accenture, Reply, Deloitte) per la modernizzazione delle architetture enterprise.

Indice di Difficoltà: 75 / 100 *(Richiede ottime doti pratiche di configurazione e debugging sistemico per far interagire correttamente molteplici tecnologie distribuite all'interno di container Docker).*

---

#### Materie Opzionali A6
Mobile Programming Insegnamento: 
**Programma Riassunto**: 
![[Pasted image 20260725172410.png|523]]
![[Pasted image 20260725172429.png|526]]

**Obiettivi Chiave**:Comprendere l'architettura dei sistemi operativi mobile e governare il ciclo di vita dei componenti software. Progettare interfacce utente fluide, reattive e conformi ai principi del Material Design e della User Experience mobile. Sviluppare la persistenza dei dati in locale e sincronizzare le informazioni con servizi backend e API REST in modalità asincrona. Accedere alle funzionalità hardware native del dispositivo (GPS, sensori, fotocamera) e gestire notifiche e permessi.

**Modalità d'Esame**:![[Pasted image 20260725172514.png]]

**Esempio Pratico di Attività**:Progettare e sviluppare un'applicazione Android nativa in Kotlin seguendo l'architettura MVVM, che permetta di visualizzare punti di interesse su una mappa interattiva (Google Maps API), scaricare dati dinamici via API REST (Retrofit), salvarli in un database locale (Room) per la consultazione offline e inviare notifiche quando ci si trova nelle vicinanze di un luogo salvato.

**Opinione Personale (Peso Pratico & Concettuale)**:È uno dei corsi più concreti e appaganti del percorso, dato che permette di toccare con mano il risultato del proprio codice direttamente sullo schermo dello smartphone. Richiede però ordine nell'adottare pattern architetturali puliti (es. MVVM/Clean Architecture) e particolare attenzione alla gestione delle risorse (memoria, batteria, connettività di rete) per evitare memory leak o blocchi dell'interfaccia.

**Sbocchi Professionali in Italia**:Android / Mobile Software Engineer: Sviluppatore specializzato nell'ingegnerizzazione e creazione di applicazioni native per il mercato mobile. Frontend / App Developer: Programmatore focalizzato sull'integrazione di servizi backend, API e progettazione di UI mobile. Mobile Application Architect: Designer di architetture software per ecosistemi mobile enterprise e integrazioni di sistemi. Consulting & Software House Specialist: Inserimento in agenzie digitali e società di consulenza IT (es. Reply, Accenture, Deloitte) per lo sviluppo di soluzioni B2C e B2B.

Indice di Difficoltà: 68 / 100 *(Molto accessibile se si hanno buone basi di programmazione ad oggetti, ma richiede attenzione nel comprendere il ciclo di vita dei componenti e la gestione dei task asincroni).*

---

**Web Programming** 
**Programma Riassunto**:
![[Pasted image 20260727120846.png|426]]
![[Pasted image 20260727120934.png|426]]
![[Pasted image 20260727120957.png|421]]


**Obiettivi Chiave**:Comprendere l'architettura Client-Server e le dinamiche di comunicazione del protocollo HTTP. Progettare e sviluppare interfacce web responsive, usabili e dinamiche con HTML5, CSS3 e JavaScript. Realizzare applicazioni backend con gestione della persistenza dei dati, routing e autenticazione utenti. Identificare le principali minacce alla sicurezza delle applicazioni web e applicare le opportune contromisure.

**Modalità d'Esame**:![[Pasted image 20260727121041.png]]

**Esempio Pratico di Attività**:Sviluppare un'applicazione web completa per la prenotazione di eventi o e-commerce: interfaccia frontend responsive in HTML/CSS/JS che invia richieste asincrone (Fetch API), backend in Node.js/Express o PHP per la gestione della logica di business e delle sessioni, e database MySQL/MongoDB per memorizzare catalogo, utenti e transazioni in sicurezza.

**Opinione Personale (Peso Pratico & Concettuale)**:È la materia di riferimento per chiunque desideri muovere i primi passi concreti nello sviluppo software applicativo per il web. Permette di acquisire una visione a tutto tondo del ciclo di vita di un'applicazione full-stack. Essendo un corso estremamente pratico, offre grande soddisfazione immediata nel vedere le proprie idee prendere forma nel browser, fornendo le fondamenta necessarie prima di approcciare framework più complessi.

**Sbocchi Professionali in Italia**:Frontend Web Developer: Sviluppatore focalizzato sulle interfacce utente, responsive design e logica client-side. Full-Stack Web Developer: Figura versatile in grado di gestire sia il frontend che il backend e i database delle applicazioni web. Backend Developer (Junior): Specialista nello sviluppo di API, integrazione di database e logica di business server-side. Web Application Specialist: Inserimento presso software house, agenzie di comunicazione digitale e società di consulenza IT.

Indice di Difficoltà: 65 / 100 *(Molto intuitivo e gratificante nelle fasi iniziali, richiede ordine mentale quando occorre coordinare contemporaneamente client, server e database garantendo la sicurezza del sistema).*

---

**Sistemi Centrali** 
**Programma Riassunto:** 
    ![[Pasted image 20260727121438.png]]
![[Pasted image 20260727121453.png]]
![[Pasted image 20260727121505.png]]

**Obiettivi Chiave:** Comprendere l'architettura hardware e software dei sistemi mainframe enterprise (IBM zSystems e z/OS). Scrivere ed eseguire script di controllo dei lavori in batch tramite JCL e gestire dataset tradizionali e VSAM. Sviluppare ed eseguire programmi in linguaggio COBOL integrati con database Db2 e gestori transazionali CICS. Acquisire dimestichezza con l'interfaccia a carattere TSO/ISPF e con i principi di sicurezza e virtualizzazione enterprise.

**Modalità d'Esame:** ![[Pasted image 20260727121522.png]]

**Esempio Pratico di Attività:** Creare ed eseguire tramite JCL su sistema IBM z/OS un job batch in COBOL che legge dati da un file VSAM, esegue query SQL embedded su Db2 per aggiornare saldi bancari o inventari, gestisce le transazioni tramite CICS e genera un report di output strutturato.

**Opinione Personale (Peso Pratico & Concettuale):** È una materia unica nel suo genere, fortemente indirizzata verso le infrastrutture ad alte prestazioni utilizzate da banche, assicurazioni e grandi istituzioni. Sebbene richieda di adattarsi a un paradigma di interazione diverso da quello moderno (interfacce a carattere TSO, sintassi rigida del JCL e COBOL), offre un vantaggio competitivo enorme sul mercato lavorativo, data la fortissima richiesta di figure specializzate su tecnologia IBM Mainframe di difficile reperimento.

**Sbocchi Professionali in Italia:** Mainframe System Specialist / z/OS Systems Programmer: Gestione, manutenzione e ottimizzazione di infrastrutture IBM zSystems presso grandi data center. Enterprise COBOL / CICS / Db2 Developer: Sviluppatore backend per applicazioni mission-critical in ambito bancario, assicurativo e PA. IT Infrastructure & Enterprise Services Analyst: Consulente tecnico specializzato nella migrazione, integrazione e gestione di sistemi centralizzati. Consulting & Financial Tech Specialist: Inserimento immediato presso grandi società di consulenza (es. Accenture, DXC, IBM, Reply) gestori di core banking e sistemi di pagamento.

**Indice di Difficoltà:** 67 / 100 (I concetti teorici non sono insormontabili, ma la sintassi dei linguaggi legacy e l'ambiente di lavoro non convenzionale richiedono un periodo iniziale di adattamento).

---

**Cybersecurity**
**Programma Riassunto:** 
![[Pasted image 20260727121715.png]]

**Obiettivi Chiave:** Comprendere i principi fondamentali della sicurezza informatica (il modello CIA: Riservatezza, Integrità, Disponibilità) e il funzionamento dei meccanismi crittografici. Analizzare e identificare le principali vulnerabilità nelle reti, nei sistemi operativi e nelle applicazioni web per prevenirne l'esploitation. Progettare e configurare architetture di rete sicure utilizzando protocolli crittografici e strumenti di difesa (TLS, Firewall, IDS). Eseguire analisi di sicurezza, audit e simulazioni di attacco/difesa secondo gli standard di settore.

**Modalità d'Esame:** ![[Pasted image 20260727121739.png]]

**Esempio Pratico di Attività:** Svolgere un'attività di Vulnerability Assessment e Penetration Testing in un ambiente virtuale isolato (utilizzando strumenti come Kali Linux, Wireshark, Nmap, Metasploit e Burp Suite) per individuare falle di sicurezza su un server web target (es. SQL Injection o cattiva configurazione TLS), redigere un Security Audit Report e applicare le opportune contromisure di hardening e filtering.

**Opinione Personale (Peso Pratico & Concettuale):** È una materia fondamentale che cambia profondamente il modo di pensare di uno sviluppatore o di un amministratore di sistema. Insegna a non analizzare il software solo per ciò che _deve_ fare, ma per quello che _potrebbe_ fare se manipolato da un attaccante. Unisce la bellezza concettuale della crittografia ad aspetti estremamente pratici e dinamici. Padroneggiare le basi della Cybersecurity è una delle competenze più spendibili in assoluto nel panorama IT contemporaneo.

**Sbocchi Professionali in Italia:** Cyber Security Analyst / Consultant: Gestione della sicurezza delle informazioni, monitoraggio delle minacce (SOC) e analisi dei rischi per aziende e PA. Ethical Hacker / Penetration Tester: Identificazione e verifica sul campo di vulnerabilità software, web e infrastrutturali per conto di terzi. Security Engineer / Architect: Progettazione e implementazione di infrastrutture di rete sicure, sistemi di autenticazione e meccanismi di protezione dati. SOC & Incident Response Specialist: Monitoraggio in tempo reale, analisi forense e risposta tempestiva agli attacchi e ai data breach.

**Indice di Difficoltà:** 73 / 100 *(Richiede una preparazione trasversale che spazia dalle reti ai sistemi operativi, oltre alla capacità di combinare teorie crittografiche con tool di analisi e difesa).*
