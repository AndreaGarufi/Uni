/*a) [8] Implementare una classe Voto con le seguenti caratteristiche: la classe è identificata da una posizione, 
una velocità lungo x. Appare come un quadrato (lato 30px) di colore giallo, al suo interno un numero randomico tra 18 e 30 
(testo 28px). Viene creata in posizione randomica nella canvas, con velocità randomica tra 2 e 10 px/frame e si muove 
inizialmente da sinistra a destra. Quando urta contro i bordi della canvas cambia direzione.

b) [7] Estendere tramite ereditarietà la classe Voto definendo Votone. Questa differisce perché il suo colore è bianco, 
resta fermo, non si muove. Quando il voto è superiore a 24, Votone ha la scritta LODE, come in figura.

[OBBLIGATORIO PER VALUTARE I PUNTI PRECEDENTI] Alla pressione del tasto sinistro del mouse si creano Voto, 
col tasto destro Votone. Si usi un ArrayList per conservare gli oggetti. Alla pressione del tasto "r" da tastiera lo sketch 
viene resettato. Implementare uno sketch in cui si apre una finestra di dimensioni 500x500 e sfondo nero*/
ArrayList <Voto> voto = new ArrayList<Voto>();

void setup(){
  size(500,500);
  background(0);
}


void draw(){
  background(0);
  for(Voto v : voto){
    v.run();
  } 
}

void mousePressed(){
  if(mousePressed && mouseButton == LEFT){
    voto.add(new Voto((int)random(30,width-30),(int)random(30,height-30),random(2,10),(int)random(18,30)));  
  }
  
  if(mousePressed && mouseButton == RIGHT){
    voto.add(new Votone((int)random(30,width-30),(int)random(30,height-30),0,(int)random(18,30)));  
  }

}


void keyPressed(){
  if(key == 'r' || key == 'R'){
    voto.clear();
  }
}
