/*a) [8] Implementare una classe Casa con le seguenti caratteristiche: la classe è identificata da una posizione, 
una velocità lungo x. Appare come una casa stilizzata di colore giallo, con facciata quadrata di lato 30px. 
Viene creata in posizione randomica nella canvas, con velocità randomica tra 2 e 10 px/frame e si muove inizialmente 
da sinistra a destra. Quando urta contro i bordi della canvas cambia verso di percorrenza.

b) [7] Estendere tramite ereditarietà la classe Casa definendo Casetta. Questa differisce perché il suo colore è bianco, 
si muove da destra a sinistra, quando esce da sinistra rientra a destra (stile pacman, non urta) e ha una porticina alta 10px. 
(vd. Figura).

[OBBLIGATORIO PER VALUTARE I PUNTI PRECEDENTI] Alla pressione del tasto sinistro del mouse si creano Casa, 
col tasto destro Casetta. Si usi un ArrayList conservare gli oggetti. Alla pressione del tasto "r" da tastiera lo sketch 
viene resettato. Implementare uno sketch in cui si apre una finestra di dimensioni 500x500 e sfondo nero.*/
ArrayList<Casa> casa = new ArrayList<Casa>();


void setup(){
    size(500,500);
    background(0);
}

void draw(){
  background(0);
  for(Casa c : casa){
    c.run();
  }

}

void mousePressed(){
  if(mousePressed && mouseButton == LEFT){
    casa.add(new Casa((int)random(10,width-30),(int)random(10,height-30),random(2,10)));
  }
  
  if(mousePressed && mouseButton == RIGHT){
    casa.add(new Casetta((int)random(10,width-30),(int)random(10,height-30),random(2,10)));
  }
  
}


void keyPressed(){
  if(key == 'r' || key == 'R'){
    casa.clear();
  }
}
