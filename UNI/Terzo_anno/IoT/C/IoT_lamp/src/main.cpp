#include <iot_board.h>
#include <BLEDevice.h>

//indirizzi univoci a 128 bit BLE lo richiede per identificare i servizi 
#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"   //identifica il servizio generale della lampada
#define LED_UUID     "beb5483e-36e1-4688-b7f5-ea07361b26a8" //indentifica la specifica caratteristica del led (on/off)

BLECharacteristic *ledChar; //caratteristica BLE del led, messo qui cosi da leggerlo in qualsiasi punto del codice
// ledChar è un oggetto che contiene: LED_UUID, un valore (value) e proprietà cioò i permessi che stabiliscono cosa può fare il telefono con quel dato, in questo caso: read,write e notify

volatile bool connected = false, ledOn = false, redraw = true, notifica = false;
//variabili booleane, ledOn serve per controllare il led

//definisce cosa succede quando il central interagisce con la lampada
class LedCallbacks : public BLECharacteristicCallbacks {  //abbiamo creato una classe derivata da BLECharacteristicCallbacks che si chiama LedCallbacks, questa classe gestisce cosa succede quando il telefono interagisce con la caratteristica del led
  void onWrite(BLECharacteristic *c) {     // a central wrote, viene eseguita automaticamente ogni volta che il telefono manda un dato (write)
    ledOn = (c->getValue() == "on");       //controlla il valore della caratteristica, se è on lo da a ledOn
    digitalWrite(LED_GREEN, ledOn ? HIGH : LOW);  
    c->notify();                           // echo to subscribers, notifica lo stato della caratteristica al central
    redraw = true;                         // display: in loop(), serve per il display
  }
};

//gestisce gli eventi di connessione/disconnessione
class ServerCallbacks : public BLEServerCallbacks { //classe derivata da BLEServerCallBacks
  void onConnect(BLEServer *s) { connected = true; redraw = true; } //usiamo la funzione onConnect per aggiornare le scritte sul display
  void onDisconnect(BLEServer *s) { //anche qui stessa cosa di sopra,ma quando si disconnette ritorna in advertising
    connected = false; redraw = true;
    BLEDevice::startAdvertising();         // discoverable again
  }
};

void pulsanteOnePremuto(uint8_t pinBtn){  //gestione del pulsante fisico sulla board

  ledOn = !ledOn;
  digitalWrite(LED_GREEN, ledOn ? HIGH : LOW);
  redraw = true;
  notifica = true;

}

void setup() {
  IoTBoard::init_serial();
  IoTBoard::init_leds();
  IoTBoard::init_display();
  IoTBoard::init_buttons();

  BLEDevice::init("Garufi's-Lamp");             // accende il modulo bluetooth e definisce come si chiama il dispositivo (GAP name)
  BLEServer *server = BLEDevice::createServer();  //configuro l'esp32 come server BLE
  server->setCallbacks(new ServerCallbacks());  //al server assegno le callback definite nella funzione ServerCallBacks
  BLEService *svc = server->createService(SERVICE_UUID);  //crea il servizio della lampada assegnando il SERVICE_UUID
  ledChar = svc->createCharacteristic(LED_UUID, //crea la caratteristica con 3 permessi
      BLECharacteristic::PROPERTY_READ |  //il telefono può leggere se il led è off
      BLECharacteristic::PROPERTY_WRITE | //il telefono può inviare comandi
      BLECharacteristic::PROPERTY_NOTIFY); //la scheda può inviare notifiche

  ledChar->setValue("off"); //imposto il valore del led a off come default
  ledChar->setCallbacks(new LedCallbacks());  //assegno le callbacks riguardanti il led alla caratteristica
  svc->start(); //starto il servizio (al suo interno c'è la caratteristica)
  server->start();  //starto il server

  buttons->onBtn1Release(pulsanteOnePremuto); //funzione di interrupt per il pulsante fisico
  
 
  BLEAdvertising *adv = BLEDevice::getAdvertising();  //configura e avvia l'advertising, cosi la scheda manda periodicamente pacchetti per farsi trovare
  adv->addServiceUUID(SERVICE_UUID);  //espone l'UUID del servizio
  adv->setScanResponse(true); //funzione che serve a gestire il fatto che i pacchetti adv sono piccoli e non ci entrerebbe anche il nome del dispositivo, cosi quando il central lo richiede con una scarequest la board risponde con una scanresponce perche le abbiamo abilitate
  BLEDevice::startAdvertising();  //starta il servizio
}

void loop() {         
  if(buttons->isBtn1Pressed()){   //questo serve per capire se il pulsante è premuto, potrei anche toglierlo e funzionerebbe comunque
    Serial.println("BTN 1 is down");
  }

  if(notifica){   //gestione della notifica quando spegnamo/accendiamo il led con il pulsante fisico per notificarlo al telefono
    ledChar->setValue(ledOn ? "on" : "off");  //settiamo il valore della caratteristica in base al valore di ledOn
    ledChar->notify();  //mandiamo la notifica
    notifica = false; //se notifica è true entra nell'if, appena finiamo la rimettiamo a false altrimenti notificherebbe all'infinto
  }

  if (!redraw){ //questo serve solo per il display, se redraw è false salta la parte finale del loop e ricomincia
    return;
  } 

  redraw = false;
  display->clearDisplay();
  display->setCursor(0, 0);
  display->println(connected ? "Connected" : "Advertising");
  display->print("LED: ");
  display->print(ledOn ? "on" : "off");
  display->display();

}

