class Voto{
  float posX;
  float posY;
  float dim;
  int testo;
  float velocita;
  color colore;
  
  Voto(float posizioneX,float posizioneY,float speed, int text){
    this.posX = posizioneX;
    this.posY = posizioneY;
    this.dim = 30;
    this.testo = text;
    this.velocita = speed;
    this.colore = #DBFA30;
  }
    
  void display(){
    noFill();
    stroke(colore);
    rect(posX,posY,dim,dim);
    textSize(28);
    text(testo,posX+5,posY-5);
  }
  
  void move(){
    posX = posX + velocita;
    if(posX +30 > width){
      velocita = -velocita;
    }
    if(posX < 0){
      velocita = -velocita;
    }
  
  }
  
  void run(){
    display();
    move();
  }
  
}
