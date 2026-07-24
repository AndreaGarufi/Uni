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
