#include <iot_board.h>
#include <BLEDevice.h>
//#include <stdio.h>

BLEScan *scan;  //puntatore globale ad un oggetto di tipo scan

class ScanCallbacks : public BLEAdvertisedDeviceCallbacks { //creiamo una nuova classe personalizzata che eredita dalla classe BLEAdvertisedDeviceCallbacks
  void onResult(BLEAdvertisedDevice dev) {  //questa funzione viene richiamata ogni volta che il dispositivo riceve un pacchetto di advertising da altri dispositivi, il suo parametro contiene tutti i dati forniti dal pacchetto
    Serial.print(dev.getAddress().toString());  //stampa l'indirizzo MAC
    Serial.printf("  %d dBm  ", dev.getRSSI()); //stampa l'RSSI (potenza del segnale)
    Serial.println(dev.getName());  //stampa il device name
  }
};


void setup(){

  IoTBoard::init_serial();
  IoTBoard::init_display();
  IoTBoard::init_leds();
  
  BLEDevice::init("");                    // we only listen
  scan = BLEDevice::getScan();  //crea l'istanza dell'oggetto e la assegna al puntatore globale
  scan->setAdvertisedDeviceCallbacks(new ScanCallbacks());  //collega la collback di advertisement all'istanza della nostra classe
  scan->setActiveScan(true); //attiva la scansione dell'area e inoltre manda le scan_request ai dispositivi che trova per farsi dare più informazioni
  scan->setInterval(100); //questo è l'intervallo ogni quando lo scanner avvia un ciclo di ascolto sulla radio
  scan->setWindow(99);   //imposta la finestra di scansione a 99 millisecondi (per quanto tempo, dentro quei 100 ms, la radio resta effettivamente in ascolto)


}

void loop(){

  display->clearDisplay();
  display->setCursor(0,0);
  display->print("Scansione attiva...\n");
  display->display();
  BLEScanResults *found = scan->start(5, false);  //avvia il ciclo di scansione che dura 5 secondi, false sta per il fatto che non deve continuare il ciclo precedente ma iniziarne uno nuovo, la start è bloccante
  Serial.printf("Found %d\n",found->getCount());  //passati i 5 secondi stampa il numero totale di dispositivi trovati
  scan->clearResults();  // free RAM

}