/*a) [8] Implementare una classe Mongolfiera con le seguenti caratteristiche: la classe è identificata da una posizione, 
una velocità lungo x, una lunghezza di 60 px e una altezza di 30px per il cesto e 70px il diametro del pallone. 
Appare come una mongolfiera (vd. immagine) di colore verde. 
Ha un metodo per cambiare la sua posizione per ciclo di draw in base alla sua velocità. 
Quando la mongolfiera esce dalla parte destra dello schermo rientra dalla parte sinistra. 
La mongolfiera ha un velocità random tra 2 e 10 px/frame e compare a un terzo dell'altezza della canvas.

b) [7] Estendere tramite ereditarietà la classe Mongolfiera definendo MongolfieraMotorizzata. 
Questa differisce perché il suo colore è random in scala di grigi (tra nero e bianco), 
ha una velocità sempre uguale alla metà di Mongolfiera, e compare a 2/3 dell'altezza della canvas. 
In aggiunta, questo tipo di Mongolfiera se urta il bordo destro o sinistro della canvas cambia la sua direzione di volo 
(urta e rimbalza).

[OBBLIGATORIO PER VALUTARE I PUNTI PRECEDENTI] Alla pressione di “R” o “r” lo sketch viene resettato. 
Implementare uno sketch in cui si apre una finestra di dimensioni 512x512 e sfondo bianco. 
A ogni ciclo di draw la finestra viene aggiornata.*/

  Mongolfiera mon,monMoto;

void setup(){
  size(512,512);
  background(255);
  float velocita = random(2,10);
  mon = new Mongolfiera(0,(height/3),velocita,60,30,70);
  monMoto = new MongolfieraMotorizzata(0,(height*2/3),velocita/2,60,30,70);
}


void draw(){
  background(255);
  if(mon != null && monMoto != null){
  mon.run();
  monMoto.run();
  }
  
}

void keyPressed(){
  if(key == 'R' || key == 'r'){
    mon = null;
    monMoto = null;
  }

}
