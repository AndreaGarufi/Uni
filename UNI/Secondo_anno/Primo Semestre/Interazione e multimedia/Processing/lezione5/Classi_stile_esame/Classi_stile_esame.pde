//vogliamo una pallina che si muove e che rimbalza -> classe ball
//green ball è una pallina di colore diverso
//QUESTO SPESSE VOLTE E' L'ESERCIZIO ALL'ESAME
ArrayList <Ball> ab; //qui ho oggetti di tipo Ball e tutte le eventuali classi ereditarie di Ball

void setup(){
  size(800,500);
  ab = new ArrayList<Ball>();
}

void draw(){
  background(0);
  
  for(Ball b:ab){      //b:ab significa ogni iterazione dell'elemento b all'interno dell'arrayList di tipo Ball
    b.run();
  }

}

void keyPressed(){
  if(key == 'n' || key == 'N'){
    ab.add(new Ball(random(35,width-35),random(35,height-35),random(30,70),random(1,10),random(1,10)));
  }
  
  if(key == 'g' || key == 'G'){
    ab.add(new GreenBall(random(35,width-35),random(35,height-35),random(30,70),random(1,10),random(1,10)));
  }
}
