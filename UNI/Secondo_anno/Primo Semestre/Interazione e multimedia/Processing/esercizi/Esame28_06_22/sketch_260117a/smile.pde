class Smile{

  float posX;
  float posY;
  float velX;
  int dim;
  color colore;
  
  Smile(float posizioneX, float posizioneY, float velocita){
    this.posX = posizioneX;
    this.posY = posizioneY;
    this.velX = velocita;
    this.dim = 50;
    this.colore = #FFEC3E;
  }
  
  void display(){
    fill(colore);
    ellipse(posX+25,posY,50,50);
    line(posX+10,posY-10,posX+10,posY+10);//occhio
    line(posX+40,posY-10,posX+40,posY+10);//occhio
    line(posX+10,posY+15,posX+40,posY+15);//bocca
  }
  
  void move(){
  
    posX = posX + velX;
    if(posX > width-25){
      velX = -velX;
    }
    if(posX < 0){
      velX = -velX;
    }
  }
  
  void run(){
    display();
    move();
  }
  
  
}
