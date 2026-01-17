/*
a) [8] Implementare una classe Smile con le seguenti caratteristiche: la classe é identificata da una posizione, una velocità lungo x. 
Appare come uno smiley di colore giallo dal diametro di 50px. Viene creata in posizione randomica nella canvas, con velocità randomica tra 2 e 10 px/frame e 
si muove inizialmente da sinistra a destra. Quando urta contro i bordi della canvas cambia direzione (implementare urto a destra e sinistra).
b) [7] Estendere tramite ereditarietà la classe Smile definendo MegaSmile. Questa differisce perché il suo colore è bianco, si muove da destra a sinistra, 
quando esce da sinistra rientra a destra (stile pacman, non urta) e ha una dimensione pari a 1.5 quella di smile (vd. Figura) [usare la funzione scale()].
[OBBLIGATORIO PER VALUTARE I PUNTI PRECEDENTI]
Alla pressione del tasto sinistro del mouse si creano Smile, col tasto destro MegaSmile. Si usi un ArrayList per conservare gli oggetti. 
Alla pressione del tasto "r" da tastiera lo sketch viene resettato. Imple uno sketch in cui si apre una finestra di dimensioni 500x500 e sfondo nero.*/

ArrayList<Smile> ab;

void setup(){
  ab = new ArrayList <Smile>();
  size(500,500);
  background(0);
  frameRate(60);
  
}

void draw(){
    background(0);
    
    for(Smile oggetto:ab){
      oggetto.run();
    }
    
    
}

void mouseClicked(){
  if(mouseButton == LEFT){
    ab.add(new Smile(0.0,random(10,450),random(2,10)));
  }
  if(mouseButton == RIGHT){
    ab.add(new MegaSmile(width,random(10,450),random(2,10)));
  }
}
