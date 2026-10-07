# **Hardware/Software Connection**

##### Registri
Un registro è un area di memoria mappata da specifici indirizzi, le interazioni hardware e software sono fatte tramite lettura/scrittura su quei registri.


*Facciamo un esempio:*
C'è un sensore di presenza che invia un impulso appena rileva una presenza.
L'impulso viene direttamente mandato ad un "external counter" che è collegato ad un pin dell'MCU, quindi esegue un incremento hardware (ovvero da solo incrementa un contatore ogni volta che riceve un input, senza che il programmatore abbia programmato quella parte).
![[Pasted image 20261007111149.png]]
Questo contatore viene aggiornato a questo indirizzo di memoria, quindi il firmware del MCU può leggerlo direttamente accedendo a quell'area di memoria.

In C:
![[Pasted image 20261007111308.png|634]]

---

# **Interfacce I/O digitali**
E' un interfaccia in cui ogni pin può avere 2 stati:
- Logical 0 -> 0 Volt
- Logica 1 -> 5 Volt, 3 Volt, dipende dalla $V_{DD}$ del sistema

Ogni interfaccia può essere programmata:
- in output -> genera corrente e può essere usata ad esempio per accendere un LED
- in input -> riceve corrente e può essere usata ad esempio per leggere un push button

---

##### General Purpose I/O (GPIO) interface of STM32
![[Pasted image 20261007112821.png]]

- Tutti gli MCUs della famiglia STM32 hanno diverse digital ports chiamate GPIOA, GPIOB, GPIOC ecc...
- Ogni porta ha 16 bit e quindi 16 pin elettrici
- Ogni pin è distinto da delle coordinate (Pxy) dove *x* è il nome della porta (A,B,...,E) e *y* è il bit (0,1,...,15),
- Ad esempio il PIN PC3 è il bit numero 3 della porta C

![[Pasted image 20261007113219.png|512]]

---

##### Utilizzare le GPIO
Prima di poter utilizzare le GPIO nel codice dobbiamo prima inizializzarle:
- *Set Up:*
  - Inizializzare tutta la porta GPIO
  - Settare la direzione (input-output) del pin che si deve utilizzare
- *Operate:*
  - Fare la read sul pin se è inizializzato come input altrimenti la write

Queste operazioni vengono semplificate utilizzando la libreria di unict: stm32_unict_lib

##### Utilizzare le GPIO con stm32_unict_lib
Esempio: utilizzare PA5 come output.

*Configurazione (Set-up)*
1. **Inizializza l'intera porta GPIO** (questa operazione fondamentalmente abilita la linea di clock per la porta GPIO):
   ```c
	GPIO_init(GPIOA);
   ```

2. **Imposta la direzione del pin che intendi utilizzare**:
   ```c
	GPIO_config_output(GPIOA, 5);
   ```

*Operatività (Operate)*

- **Scrivere 0 su PA5**
   ```c
	GPIO_write(GPIOA, 5, 0);
   ```

- **Scrivere 1 su PA5**
   ```c
	GPIO_write(GPIOA, 5, 1);
   ```



Supponiamo di utilizzare questo schema:
![[Pasted image 20261007114606.png|481]]

Programmiamo qualcosa:
![[Pasted image 20261007114627.png|595]]


---

![[Pasted image 20261007114750.png|569]]
![[Pasted image 20261007114803.png]]


![[Pasted image 20261007114842.png]]

---
**Prototipi delle funzioni GPIO**
![[Pasted image 20261007114904.png]]

