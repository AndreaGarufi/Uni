Certamente. Per trovare gli estremi (massimo e minimo) assoluti di una funzione in un intervallo chiuso e limitato, come quello indicato, si segue una procedura metodica che si basa sul Teorema di Weierstrass. Questo teorema garantisce che una funzione continua su un intervallo chiuso [a, b] ammette sempre un massimo e un minimo assoluto in tale intervallo.

Questi punti di estremo assoluto si trovano tra i cosiddetti "punti critici" della funzione. I punti critici da esaminare sono:
*   I punti stazionari interni all'intervallo, ovvero i punti in cui la derivata prima della funzione si annulla.
*   I punti di non derivabilità interni all'intervallo (punti angolosi, cuspidi).
*   Gli estremi dell'intervallo stesso.

Vediamo come applicare questa procedura al tuo esercizio:
**Funzione:** f(x) = |x² - 3x| + 2x² - x + 1
**Intervallo:** [-1, 4]

### Passaggio 1: Analizzare il valore assoluto

La presenza del valore assoluto |x² - 3x| ci costringe a definire la funzione a tratti. Per prima cosa, studiamo il segno dell'argomento del valore assoluto:
x² - 3x ≥ 0 → x(x - 3) ≥ 0
Le radici sono x = 0 e x = 3. La parabola è positiva per valori esterni alle radici.
Quindi:
*   x² - 3x ≥ 0 quando x ≤ 0 oppure x ≥ 3
*   x² - 3x < 0 quando 0 < x < 3

Ora possiamo riscrivere la funzione f(x) senza il modulo:
*   **Per x ≤ 0 o x ≥ 3:**
    f(x) = (x² - 3x) + 2x² - x + 1 = **3x² - 4x + 1**
*   **Per 0 < x < 3:**
    f(x) = -(x² - 3x) + 2x² - x + 1 = -x² + 3x + 2x² - x + 1 = **x² + 2x + 1**

### Passaggio 2: Calcolare la derivata prima

Ora deriviamo i due tratti della funzione per trovare i punti stazionari:
*   **Per x < 0 o x > 3:**
    f'(x) = 6x - 4
*   **Per 0 < x < 3:**
    f'(x) = 2x + 2

### Passaggio 3: Trovare i punti critici nell'intervallo [-1, 4]

Cerchiamo i punti che annullano la derivata e i punti di non derivabilità all'interno dell'intervallo [-1, 4].

1.  **Punti stazionari (f'(x) = 0):**
    *   6x - 4 = 0 → x = 4/6 = 2/3. Questo valore non è accettabile perché non si trova negli intervalli x < 0 o x > 3.
    *   2x + 2 = 0 → x = -1. Anche questo valore non è accettabile perché non si trova nell'intervallo 0 < x < 3.
    Non ci sono quindi punti stazionari interni all'intervallo.

2.  **Punti di non derivabilità:** La funzione potrebbe non essere derivabile nei punti in cui l'argomento del valore assoluto si annulla, cioè in x = 0 e x = 3. Questi sono i "punti di raccordo" tra i due tratti della funzione e sono entrambi inclusi nel nostro intervallo [-1, 4], quindi dobbiamo prenderli in considerazione.

3.  **Estremi dell'intervallo:** Gli estremi dell'intervallo sono x = -1 e x = 4.

In sintesi, i punti candidati per essere il massimo o il minimo assoluto sono: -1, 0, 3, 4.

### Passaggio 4: Calcolare il valore della funzione nei punti critici

Ora calcoliamo il valore di f(x) in ciascuno dei punti candidati che abbiamo trovato.

*   **f(-1):** Poiché -1 ≤ 0, usiamo la prima espressione:
    f(-1) = 3(-1)² - 4(-1) + 1 = 3 + 4 + 1 = **8**

*   **f(0):**
    f(0) = |0² - 3(0)| + 2(0)² - 0 + 1 = **1**

*   **f(3):**
    f(3) = |3² - 3(3)| + 2(3)² - 3 + 1 = |0| + 18 - 3 + 1 = **16**

*   **f(4):** Poiché 4 ≥ 3, usiamo la prima espressione:
    f(4) = 3(4)² - 4(4) + 1 = 3(16) - 16 + 1 = 48 - 16 + 1 = **33**

### Passaggio 5: Determinare il massimo e il minimo assoluto

Confrontiamo i valori ottenuti:
*   f(-1) = 8
*   f(0) = 1
*   f(3) = 16
*   f(4) = 33

Il valore più alto è 33 e il valore più basso è 1.

**Conclusione:**
Nell'intervallo [-1, 4], la funzione ha:
*   Un **massimo assoluto** di **33**, raggiunto nel punto **x = 4**.
*   Un **minimo assoluto** di **1**, raggiunto nel punto **x = 0**.