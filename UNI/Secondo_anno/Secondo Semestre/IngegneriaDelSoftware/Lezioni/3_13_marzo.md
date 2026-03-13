principi 
- kiss -> keep it simple -> produrre componenti semplici
- dry -> dont repet yourself -> evita ripetizioni nel codice, se faccio copia e incolla di molte parti del codice e poi devo modificare una parte copiata, questa va poi modificate in tutte le copie che ho fatto, meglio costruire un metodo più piccolo che fa solo poche cose e anziché ripetere codice chiamo quei metodi
- yagni -> you aint gonna need it -> non progettare funzionalità che ora non servono, andrai a complicare inutilmente il codice e questo porta a perdite di tempo 
- lod -> low of demeter -> non parlare con gli estranei -> un oggetto deve avere conoscenza solo di oggetti a lui correlati (amici), questo viene fatto per evitare problemi (anche problemi di sicurezza), di base quindi una classe deve avere contatti con poche classi, solitamente 3 o 5 al massimo

I test vanno eseguiti molto spesso, cosi posso sapere con più precisione dove ci sono stati errori, inoltre eseguendo spesso i test evito di avere troppi errori



UML
Se ho 2 classi A e C e c'è una freccia che indica da A -> C  allora saprò che A per funzionare bene usa anche C