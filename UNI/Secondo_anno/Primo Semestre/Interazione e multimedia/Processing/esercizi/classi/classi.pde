//fare un quadrato giallo che si muove in orizzontale e torna indietro
//fare un quadrato rosso più piccolo che si muove in verticale e torna indietro
//premendo un tasto spuntano i quadrati gialli e con un altro quelli rossi
ArrayList <Square> ab;

void setup(){
  size(700,700);
  background(0);
  frameRate(60);
  
  ab = new ArrayList<Square>();
}


void draw(){

  background(0);
  for (Square quadrato:ab){
    quadrato.run();
  }
}


void keyPressed(){
  if(key == 'n' || key == 'N'){
    ab.add(new Square(0,0,100,100));
  }
  
}
