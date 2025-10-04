### **1. `fseek`**

**Cosa fa:**  
Sposta il "cursore" all'interno di un file aperto. È utile per accedere a una posizione specifica nel file, evitando di dover leggere tutto sequenzialmente.

**Sintassi:**

`int fseek(FILE *file, long offset, int origin);`

**Parametri:**

- `file`: il puntatore al file aperto.
- `offset`: il numero di byte da spostare.
- `origin`: da dove partire per il movimento del cursore. Può essere:
    - `SEEK_SET`: inizia dall'inizio del file.
    - `SEEK_CUR`: inizia dalla posizione corrente.
    - `SEEK_END`: inizia dalla fine del file.

**Esempio:**

`fseek(fp, 10, SEEK_SET); // Sposta il cursore al decimo byte dall'inizio.`

---

### **2. `fwrite`**

**Cosa fa:**  
Scrive dati da una variabile in memoria direttamente su un file binario.

**Sintassi:**

`size_t fwrite(const void *ptr, size_t size, size_t count, FILE *file);`

**Parametri:**

- `ptr`: puntatore ai dati da scrivere.
- `size`: dimensione di un singolo elemento (in byte).
- `count`: numero di elementi da scrivere.
- `file`: puntatore al file aperto.

**Ritorna:**  
Il numero di elementi scritti correttamente.

**Esempio:**

``int data = 42; 
`fwrite(&data, sizeof(int), 1, fp); // Scrive l'intero data nel file.

---

### **3. `fread`**

**Cosa fa:**  
Legge dati da un file binario e li memorizza in una variabile.

**Sintassi:**

`size_t fread(void *ptr, size_t size, size_t count, FILE *file);`

**Parametri:**

- `ptr`: puntatore alla memoria dove salvare i dati letti.
- `size`: dimensione di un singolo elemento (in byte).
- `count`: numero di elementi da leggere.
- `file`: puntatore al file aperto.

**Ritorna:**  
Il numero di elementi letti correttamente.

**Esempio:**

``int data;` 
`fread(&data, sizeof(int), 1, fp); // Legge un intero dal file e lo salva in data.``

**Esempio completo:**
`// Scrivere dati nel file` 
`int num = 12345;` 
`fwrite(&num, sizeof(int), 1, fp);`

`// Spostare il cursore all'inizio del file` 
`fseek(fp, 0, SEEK_SET);`

`// Leggere i dati dal file` 
`int letto; fread(&letto, sizeof(int), 1, fp);` 
`printf("Numero letto dal file: %d\n", letto);`