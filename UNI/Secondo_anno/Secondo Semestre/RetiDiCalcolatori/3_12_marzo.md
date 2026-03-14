
Il protocollo FTP ci interessa per capire la differenza con http, file transport protocol. è un protocollo che lavora in entrambe le direzioni possono prendere e mandare informazione. Serve autenticazione, e tutto deve essere in chiaro. Nelle versioni più vecchie c’era modalita di trasferimento binaria o testuale. se il file è binario lo ricopio così com’è tra le varie macchine. su una porta mandano comandi e sull’altra trasferimento dati.

se sono due canali separati, e sai blocca perchè file troppo grande posso dire lascia perdere e ricominciamo. questo è statefull

il canale di trasferimento lo apro quando mi serve. apre connessione tcp sulla porta 21, apre login e pass e il tcp rimane aperto fino a che qualcuno chiude o il sistema lo chiude per inutilizzo al termine dell’FTP si chiude anche il tcp

(farmacia)stateless senza stato, anche se ha memoria perche ad esempio premo e stampo, stato èm pronto, quando premo ce transisizone tra stato di pronto a stato di pronto con stampa. ma è stateless. ha memoria ma uno stato.

(biglietti)statefull con stato, prima metti soldi poi biglietto, quindi ci son stati: prima stato di pronto, poi stato di biglietti e poi te lo stampa. qui ha piu stati, devo passare piu stati per una sola operazione.

Http un po’ di storia, 1990 piu o meno, si doveva creare un sistema per recuperare documenti pubblici(non servono autorizzazioni), mettendo a disposizione un sistema che li mette direttamente sul pc. Sono una parte grafica (HTML) e un sistema di trasferimento, qualcosa per trovare dove è messo e farmelo inviare (HTTP).dveo contattare il server che ha il documento e lo devo identificare con URL.

apro una connessione TCP, quello approva, poi chiedo di mandare il documento e lo da. poi iniziano a pensare che questo protocollo poteva essere utilizzato in altri modi, ad esempio la mail.

HTTP sistema stateless. Il server web si scrive tutte le richieste che ho fato.

ce una richietsa e una risposta, serve a dire trasferiscimi questo file e se ce dammelo

url è un file dentro un percorso. devo dire il nome della macchina e dove si trova nel percorso del file che è da wualche parte nel sistema web

le informazioni posso mandarle in due modi: incassellatte in manier rigida o dinamica.

qui dinamica(come dimensione dei campi): prima metto un verbo o metodo(non so quando è grande, è grande fino allo spazio); URL peggio ancora, termina con il successivo spazio bianco, version , cr ed lf per dire che termina riga.

nella seconda,chiave spazio parole e termina riga, quando finisce seconda riga riga vuota, dopo il corpo(altre informazioni).

lo svantaggio qui è che devo identificare come indicare la fine della riga.

hanno stessa struttura.

ci sono sia codici che testo perche quando è stato creato dovevano sapere subito leggere cosa era successo; la macchina legge il 400 e l’umano il testo.

POST ti sto mandando questi dati e dammi una riasposra in base a questo(form)

put e delete sono stati disabilitati

differenza tra post e get: con la get le coppie chiavi valore le metto nella URL, separate da &

con la post metto le stesse informazioni sotto dalla seconda riga in poi

(cercarla bene) , get e post inviano entrambe informazioni. la differenza è la get invia coppia chiavi valore nella url, il post invia informazioni dopo la Url. Con la get vedo cosa è stato mandato, con la post no perche non vedo i campi dopo.

i cookie è un pezzo di codice alfanumerico. ha un nome e un contenuto, ha dei parametri aggiuntivi. il cookie viene scritto sul client, e dopo che ha visitato il sito vede cosa hai vistato e vede il contenuto e le cancella. Amazon sa sta cosa e quindi il cookie ha numeri assurdi. ogni volta che riaccxedo al server il cookie mi dice se devo riaccedere o no e a chi lo devo mandare e fino a dove devo andare o dove devo partire. posso metterw altre informazioni tipo quando è stato generato e quando scade il cookie. puo essere invalidato mettendo una data antecedente alla data attuale. quanfo hai finito fai log out cosi il coockie di sessione viene invalidato quando l’utente si disconnette, non perche ho ho premuto log out.

Un **cookie** (tecnicamente un _HTTP cookie_) è un piccolo file di testo che un sito web invia al tuo browser mentre lo stai visitando. Il browser lo memorizza sul tuo dispositivo e lo "restituisce" al sito ogni volta che torni su una sua pagina o compi un'azione. **Perché esistono?** Il protocollo fondamentale del web (HTTP) è "stateless". Senza i cookie, ogni volta che clicchi su una nuova pagina di un sito, il server ti tratterebbe come un perfetto sconosciuto. Ecco a cosa servono principalmente: • **Gestione della sessione:** Permettono di restare loggati. Senza cookie, dovresti inserire username e password ogni volta che passi dalla "Home" al tuo "Profilo". • **Carrello della spesa:** Ricordano cosa hai aggiunto al carrello mentre continui a navigare sul sito di e-commerce. • **Personalizzazione:** Memorizzano la lingua scelta, il tema (chiaro o scuro) o le impostazioni del layout. • **Tracciamento e Marketing:** Monitorano quali pagine visiti per capire i tuoi interessi e mostrarti pubblicità mirata. **Le tipologie principali** I cookie non sono tutti uguali. Si distinguono in base alla durata e a chi li "crea":

**Di sessione** Temporanei. Vengono cancellati non appena chiudi il browser.

**Persistenti** Rimangono sul tuo dispositivo per un tempo prefissato (giorni o anni) finché non scadono o li cancelli.

**Prima parte** Creati direttamente dal sito che stai visitando (es. per ricordarti il login).

**Terza parte** Creati da siti diversi da quello che stai visitando (es. banner pubblicitari o tasti social), usati per tracciarti su più siti diversi.

---

**Sono pericolosi?** I cookie **non sono virus né malware**. Sono semplici file di testo e non possono "eseguire" nulla sul tuo computer o leggere il tuo disco fisso. Il problema principale riguarda la **privacy**: i cookie di terza parte possono creare un profilo molto dettagliato delle tue abitudini online. È per questo che oggi vedi ovunque i "banner dei cookie" che ti chiedono il consenso per l'installazione.

Html dinamico, è nato statico in realtà, poi hanno collegato database dietro, informazioni per ppoter elaborare graficamente una pagina web. e sono nati i linguaggi adatti, prima era tutto in c. questi script sono da server non li vediamo, la programmazione lato client è tipicamente in javascript eseguito nel browser(infatti non puo scrivere sul sistema, o accedere alla webcam) certe cose è meglio farle fare al client per essere più fluido.

1.0 si apre tcp facevo richiesta e chiude tcp e fine, devo riaprirlo ogni volta

1.1 non è persistente ma finisce quando finisco di caricare tutti gli oggetti.

se apro 4 canali tcp sara piu lento, ma in realta gli oggettti piu piccoli appaiono prima, in realtà questo non è efficiente.

si cercava un protocollo più veloce, utilizza UDP (manda un messaggio invece TCP ne manda 4, ma tcp assicura la ricezione dei messaggi, UDP non è affidabile)in http/3.0. quasi tutti i server in vanno 1.1.

i protocolli sono retrocompatibili. Un protocollo si dice **retrocompatibile** (o _backward compatible_) quando una versione più recente o aggiornata è in grado di interagire correttamente con versioni precedenti dello stesso protocollo, o di gestire dati e dispositivi basati su standard più vecchi. a volte viene buttata fuori per sicurezza.