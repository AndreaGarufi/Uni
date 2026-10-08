### **Cosa è Docker:**
**Docker** è una piattaforma open source che permette di impacchettare un'applicazione e tutto ciò di cui ha bisogno per funzionare (codice, librerie, dipendenze, file di configurazione) all'interno di un'unità autonoma e standardizzata chiamata **container**.
![[Pasted image 20261003103607.png|481]]

**A cosa serve?**
Risolve il classico problema dei programmatori: _"Sul mio computer funziona, ma sul server o sul computer del collega no!"_.
Garantisce che il software si comporti esattamente nello stesso modo ovunque venga eseguito: sul computer di sviluppo, su un server in cloud o su macchine con sistemi operativi diversi.

##### I concetti chiave
- **Immagine (Image):** Il modello di sola lettura, simile alla ricetta o al file di installazione dell'applicazione.
- **Container:** L'istanza in esecuzione dell'immagine. È l'ambiente isolato e leggero in cui gira effettivamente il programma.
- **Dockerfile:** Il file di testo con le istruzioni dettagliate per creare l'immagine.

##### Cosa è un container?
Un container è una unita standardizzata di software che contiene il codice e tutte le sue dipendenze (librerie ecc...) cosi le applicazioni possono girare in qualsiasi ambiente


##### Docker vs Macchine Virtuali (VM)
A differenza delle macchine virtuali classiche (come VirtualBox o VMware), i container non emulano un intero sistema operativo:
- **Condividono il kernel del sistema operativo host**, occupando solo pochi megabyte anziché gigabyte.
- **Si avviano in frazioni di secondo**, senza dover caricare un intero sistema operativo da zero.
- **Consumano meno risorse** (RAM e CPU), permettendo di eseguire decine di servizi sullo stesso computer senza rallentarlo.

I container sono un'astrazione a livello di applicazione che raggruppa codice e dipendenze insieme. Più container possono essere eseguiti sulla stessa macchina e condividere il kernel del sistema operativo con altri container, ciascuno dei quali gira come processo isolato nello spazio utente. I container occupano meno spazio rispetto alle VM (le immagini dei container hanno in genere una dimensione di decine di MB)

Le macchine virtuali (VM) sono un'astrazione dell'hardware fisico. L'hypervisor consente a più VM di essere eseguite su un'unica macchina.
Ogni VM include una copia completa di un sistema operativo, l'applicazione, i file binari e le librerie necessarie, occupando decine di GB. Le VM possono inoltre essere lente ad avviarsi.

![[Pasted image 20261003173834.png]]

Possiamo chiaramente intendere che usare i container sia nettamente migliore in termini di utilizzo risorse.

**OCI**
I container sono utili pe tutto quello che abbiamo detto prima, ma c'è una cosa che è fondamentale: **sono uno standard**. Infatti è stato creato il Open Container Initiative (OCI) ovvero uno standard nato per semplificare l'ecosistema dei container ed evitare monopoli o altri problemi. 

- Definisce come deve essere strutturato il file dell'immagine (i layer del filesystem, i metadati, le impostazioni di avvio).
- Definisce le regole con cui il software avvia, gestisce il ciclo di vita (start, stop, pause) e isola un container sul sistema operativo.
- Descrive il protocollo standard con cui le immagini vengono caricate (`push`) e scaricate (`pull`) dai server remoti (i cosiddetti _registry_).

### Approfondiamo Docker
Su Docker le immagini diventano containers quando sono eseguite sul Docker Engine.

![[Pasted image 20261003175438.png]]

- ***Client***
  È l'interfaccia con cui interagiamo noi, tipicamente da terminale (la CLI di Docker).
- ***DOCKER_HOST***
  È la macchina (il tuo PC o un server remoto) su cui gira Docker. Contiene:
   - **Docker daemon (`dockerd`):** Il processo in background che ascolta i comandi del client e gestisce la creazione, l'esecuzione e il monitoraggio di immagini e container.
   - **Images:** Il magazzino locale dove risiedono le immagini scaricate o create (nel disegno si vedono Ubuntu e Redis).
   - **Containers:** Le istanze vive e in esecuzione create a partire da quelle immagini (i container blu con il logo dell'applicazione).
- ***Registry***
  E' un catalogo remoto su internet (es. Docker Hub) che raccoglie e distribuisce immagini preconfigurate

**Ma a cosa serve un container?**
Come vedremo ci sono moltissimi container, ad esempio c'è quello di ubuntu che non contiene un intero kernel ubuntu ma un terminale con privilegi da root o anche la struttura standard delle directory Linux, una shell per interagire, i comandi base di sistema GNU, la libreria C standard di Ubuntu e il gestore pacchetti. *In questo caso cosa me ne faccio di questo container?*
Ad esempio se devo usare lo standard POSIX che non è presente in maniera nativa su windows posso programmare il codice su windows e poi farlo funzionare dentro il container ubuntu.
In pratica è un mini-filesystem Ubuntu pronto per farti installare solo i pacchetti strettamente necessari al tuo progetto.

##### Vediamo qualche comando di docker.
Possiamo sia usare docker desktop con interfaccia grafica che usarlo da terminale.
```
# Docker version

docker --version

Docker version 29.5.2, build 79eb04c
```
`

```
# Runnare i container

docker run hello-world

Hello from Docker!
This message shows that your installation appears to be working correctly.
```
Quando eseguiamo questo comando cercherà l'immagine prima sul dispositivo e se non la trova proverà a carcarla sul server delle immagini, se la trova la scarica e la avvia


```
# Visionare la lista delle immagini sul dispositivo

 docker image ls
											                                                                                        i Info →   U  In Use
IMAGE                ID             DISK USAGE   CONTENT SIZE   EXTRA
hello-world:latest   5e2309035332       25.9kB         9.49kB    U
```

```
# Visionare la lista di tutti i container

docker container ls -a
CONTAINER ID   IMAGE         COMMAND    CREATED             STATUS                         
5bfd23731b3b   hello-world   "/hello"   About an hour ago   Exited (0) About an hour ago             

PORTS     NAMES

		elegant_lewin
```
se dal comando si toglie il -a (che sta per all) si vedranno solo i container attivi


```
# cambiare il nome ad un container

docker run --name CIAO Hello-world
```
Possiamo riferirci ai container per nome:

```
# chiudere un container

docker stop CIAO
CIAO

# rimuovere e cancellare definitivamente il container e ogni dato al suo interno

docker rm CIAO
CIAO
```



Se volessimo scaricare o eseguire l'immagine di ubuntu potremmo scrivere:
```
docker run ubuntu
```

se invece vogliamo anche "entrare" e utilizzare il container che abbiamo scaricato o avviato possiamo fare cosi:

```
docker run -it ubuntu

root@b54f29d8ad2f:/#
```
e ci ritroviamo dentro il terminale di ubuntu

Se cancelliamo un container perdiamo tutti i dati che quel container possedeva a meno che non usiamo un *volume*

Se si collega un volume al container, tutto ciò che scriviamo in quella cartella specifica finisce direttamente sul disco del computer host. Quindi se si esegue: docker rm "name" i dati restano salvati su quella cartella,  vediamo il comando:

```
#creare un volume

docker run -v app-data:/data ...
```

![[Pasted image 20261007172343.png]]

*Altri comandi*
- Quale immagine e quale comando hanno creato questo container? `docker inspect`
    
- Cosa ha stampato a schermo l'applicazione? `docker logs`
    
- È in esecuzione, e quali porte sono pubblicate? `docker ps`
    
- Posso ispezionare un processo attivo? `docker exec -it <container> sh`

(vedremo come creare le immagini dopo.)
```
#creare un immagine 

docker image build -t bulletinboard:1.0 .

# runnare il container

docker container run -d -p 8080:8080 --name myapp bulletinboard:1.0
```
-t serve a dare un nome e una versione, noi useremo -t

Se dobbiamo buildare ma nel terminale non ci troviamo nella cartella con il DockerFile possiamo scrivere cosi: `docker build -f /path/to/a/Dockerfile`
(in caso poi aggiungere -t ...)

---

**Un container è solo una parte dell'intera applicazione**
Un' applicazione avrà anche bisogno di porte per comunicare client-server, volumi per salvare i dati del container e connessioni per far comunicare i container

---

##### Ricapitolando
- **Immagine**: Un immagine è un modello di sola lettura con le istruzioni per creare un container docker.
- Un immagine può essere basata su un altra immagine con l'aggiunta di altri dettagli/funzionalità.
- Ad esempio possiamo "buildare" un image basata su quella di ubuntu ma con l'aggiunta di alcuni servizi che in quella base non ci sono.

- **Container**: sono l'istanza dell'immagine e vengono visti come un normale processo, quindi hanno risorse, permessi ecc... .
- Il container si sostituisce alla macchina virtuale perché può svolgere quasi gli stessi compiti ma occupando molte meno risorse.
- Il container contiene il codice e tutte le sue dipendenze per far funzionare correttamente un programma in qualsiasi ambiente ci si trovi.

---

##### Creare un immagine
Possiamo usare immagini fatte da altri o crearne di nostre.
*Per creare un immagine bisogna fare un "DockerFile"* che contiene le istruzioni per creare ed eseguire la nostra immagine.
Ogni istruzione all'interno del DockerFile contiene le istruzioni per creare un determinato layer dell'immagine. Se modifichiamo un layer e ricreiamo l'immagine cambieranno solo quelli, in questo modo si risparmia tempo nell'esecuzione dei comandi.
![[Pasted image 20261008204913.png|467]]


##### Vediamo un esempio (RepoClonataEsempio):
Illustriamo come creare ed eseguire un'applicazione **Node.js**

>[!info] Node.js è un ambiente di esecuzione (_runtime_) open-source e multipiattaforma che permette di eseguire codice JavaScript al di fuori del browser web

Questo è quello scritto dentro il DockerFile.
```
1  FROM node:current-slim
2  WORKDIR /usr/src/app
3  COPY package*.json ./
4  RUN npm install
5  COPY . .
6  EXPOSE 8080
7  CMD ["npm", "start"]
```

![[Pasted image 20261008210608.png|713]]

Possiamo visionare la sintassi a questo indirizzo: <https://docs.docker.com/reference/dockerfile/>

Se copiassi subito tutto il codice sorgente con `COPY . .` prima di `npm install`, **ogni singola modifica a un file JavaScript invaliderebbe la cache**, costringendo Docker a riscaricare tutte le dipendenze (`npm install`) ad ogni build, operazione che richiede tempo e banda.
Copiando prima solo i file `package*.json`, Docker rieseguirà `npm install` **soltanto** se hai aggiunto o modificato una libreria. Se modifichi solo il codice sorgente dell'app, Docker riutilizzerà il layer delle dipendenze dalla cache e aggiornerà solo il passaggio finale (`COPY . .`), rendendo la build quasi istantanea.


**Creazione dell'immagine "build"**
Posizioniamoci all'interno della cartella dove si trova il DockerFile e lanciamo questi comandi:
```
docker image build -t bulletinboard:1.0 .
docker container run -d -p 8080:8080 --name myapp bulletinboard:1.0
```
Il primo creerà l'immagine mentre il secondo eseguirà il container, possiamo poi andare sul browser e digitare "http://localhost:8080" oppure cliccare sullo stesso testo all'interno di dockerDesktop per visualizzare l'applicazione che in questo momento sta girando su un container.