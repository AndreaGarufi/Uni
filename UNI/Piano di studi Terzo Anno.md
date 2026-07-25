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

