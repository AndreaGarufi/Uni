class Casa{

  float posX;
  float posY;
  float velocita;
  int dim;
  color colore;
  
  Casa(float posizioneX, float posizioneY, float speed){
    this.posX = posizioneX;
    this.posY = posizioneY;
    this.velocita = speed;
    this.dim = 30;
    this.colore = #DBFF12;
  }
  
  void display(){
    noFill();
    stroke(colore);
    rect(posX,posY,dim,dim);
    triangle(posX,posY,posX+15,posY-15,posX+30,posY);
  }
  
  void move(){
    posX = posX + velocita;
    if(posX+30> width){
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
