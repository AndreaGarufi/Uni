/*a) [8] Implementare una classe Cifra con le seguenti caratteristiche: la classe è identificata da una posizione, 
una velocità lungo y. Appare come un carattere numerico di colore giallo, di grandezza 32px. 
Ha un metodo per cambiare la sua posizione per ciclo di draw in base alla sua velocità. 
Quando il carattere esce dalla parte inferiore dello schermo rientra dalla parte superiore. 
Esso compare a dalla parte superiore dello schermo a coordinata x randomica e ha un velocità random tra 2 e 10 px/frame

b) [7] Estendere tramite ereditarietà la classe Cifra definendo Cifrotta. 
Questa differisce perché il suo colore è bianco, ha cerchio che la circoscrive e si muove dal basso verso l'alto. 
Se la Cifrotta esce dalla parte superiore dello schermo, rientra da quella inferiore.

[OBBLIGATORIO PER VALUTARE I PUNTI PRECEDENTI)

Alla pressione di un tasto (numerico) da tastiera, se il numero è compreso tra 0 e 4 (estremi inclusi) viene generata una Cifra, 
altrimenti (numeri tra 5 e 9, estremi inclusi) una Cifrotta. 
Si usi un ArrayList per conservare gli oggetti. Alla pressione del tasto destro del mouse lo sketch viene resettato. 
Implementare uno sketch in cui si apre una finestra di dimensioni 500x500 e sfondo nero.*/
ArrayList <Cifra> numero;

void setup(){
  size(500,500);
  numero = new ArrayList<Cifra>();
}

void draw(){
  background(0);
  for(Cifra c : numero){
    c.run();
  }
}

void keyPressed(){

   if(key >= '0' && key <= '4'){
     numero.add(new Cifra(random(0,width-20),20,random(2,10),(int)random(0,9)));
   }
   
   if(key >= '5' && key <= '9'){
     numero.add(new Cifrotta(random(0,width-20),height,random(2,10),(int)random(0,9)));
   }
  
}

void mousePressed(){
  if(mousePressed == true){
    numero.clear();
  }
}
