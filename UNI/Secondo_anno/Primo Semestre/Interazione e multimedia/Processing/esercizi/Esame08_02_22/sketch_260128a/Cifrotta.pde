class Cifrotta extends Cifra{
  
  color coloreB;
  Cifrotta(float posizioneX, float posizioneY, float vel, int text){
    super(posizioneX,posizioneY,vel,text);
    this.coloreB = 255;
    this.dim = 32;
  }
  
  void display(){
    noFill();
    stroke(255);
    ellipseMode(RADIUS);
    ellipse(posX+8,posY-10,30,30);
    fill(coloreB);
    textSize(dim);
    text(testo,posX,posY);    
  }
  
  void move(){
    posY = posY-velocitaY;
    
    if((posY-32) < -60){
      posY = height+40;
    }
  }
  
}
