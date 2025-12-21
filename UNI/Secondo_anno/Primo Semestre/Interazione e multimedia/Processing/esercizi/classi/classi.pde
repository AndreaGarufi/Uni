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
  for (Square quadrato:ab){    //oggetto square di nome quadrato, scorre ogni cella di ab se entro c'è qualcosa esegue run()
    quadrato.run();
  }
}


void keyPressed(){
  if(key == 'n' || key == 'N'){
    float lato1 = random(50,100);
    float lato2 = lato1;
    ab.add(new Square(0,random(0,width-lato2),lato1,lato2,random(1,7)));
    }
     
  if(key == 'g' || key == 'G'){
    float lato1 = random(20,60);
    float lato2 = lato1;
    ab.add(new redSquare(random(0,width-lato1),0,lato1,lato2,random(1,7)));
    
  }
  
}
