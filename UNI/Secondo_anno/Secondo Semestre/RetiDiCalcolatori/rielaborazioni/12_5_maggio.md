**Distanza Di Hamming**
Misura la distanza tra 2 code word: 
1000110
1100110
distanza = 1

*Vocabolario*
![[Pasted image 20260505102514.png|429]]
In un vocabolario la distanza è misurata come il minimo tra tutte le distanze
Per comunicare si possono usare solo le code word appartenenti al vocabolario

**Error Detection**
Se arriva questa code word: 101000 che non appartiene al vocabolario posso risalire in maniera probabilistica a capire qual'era la code word originale in base alla distanza da vocabolario
![[Pasted image 20260505102620.png|483]]


**Basi teoriche per poter fare rilevazione e correzione degli errori**
Se abbiamo $e$ errori e vogliamo correggerli abbiamo bisogno di una distanza $d= 2e+1$ , invece per rilevarli abbiamo bisogno di una distanza $d = e+1$




slide 52 (vedere tutte le precedenti)
![[Pasted image 20260505105037.png|324]]
Hamming inserisce nelle potenze di 2 i bit di controllo mentre in tutti gli altri i dati
