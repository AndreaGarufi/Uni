### 1. **Orologio Sincronizzato con Meteo Live (NTP + OpenWeatherMap)**

- **Come funziona**:
    
    1. L'ESP32 si connette alla rete Wi-Fi e sincronizza l'orario perfetto tramite un server NTP (senza bisogno di un modulo orologio hardware RTC).
        
    2. Invia una richiesta HTTP ad un'API gratuita di meteo (es. OpenWeatherMap) passando le coordinate della tua città.
        
- **Cosa mostrare sul display (128x64)**:
    
    - In alto in grande: Ora e minuti (es. `14:30:45`).
        
    - In basso: Temperatura attuale, umidità e un'icona testuale/grafica (es. `22°C - Nuvoloso`).


### 4. **Display di Monitoraggio Rete Wi-Fi (Wi-Fi Scanner / Monitor)**

- **Come funziona**: Sfrutti le funzioni integrate nella libreria `WiFi.h` (come `WiFi.scanNetworks()`).
    
- **Cosa mostrare sul display**:
    
    - Un grafico o una lista dinamica delle reti Wi-Fi vicine con la relativa potenza di segnale (RSSI) espressa in dBm o in tacche della rete.
        
    - Puoi usare i pulsanti della scheda per scorrere la lista delle reti trovate sullo schermo.

### 5. **Orologio Pomodoro / Timer di Studio Connesso**

- **Come funziona**: Sfrutti il display e i pulsanti integrati per gestire le sessioni di studio/lavoro (25 min di lavoro, 5 min di pausa).
    
- **La chicca Wi-Fi**: Alla fine di ciascuna sessione o pausa, l'ESP32 può effettuare una chiamata Webhook a servizi come IFTTT per accendere la tua luce smart, inviarti una notifica o salvare lo storico delle sessioni su un foglio Google Sheets.