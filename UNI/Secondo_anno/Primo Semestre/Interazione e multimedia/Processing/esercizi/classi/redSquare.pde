class redSquare extends Square{
  
  redSquare(float x, float y, float l1,float l2,float speed){
    super(x,y,l1,l2,speed);
  }
  
  void display(){
    fill(255,0,0);
    noStroke();
    rect(posX,posY,lato1,lato2);
  }
  
  void move(){
    posY = posY + velocita;
    if(posY > width-lato1){
      velocita = -velocita;  
    }
    if(posY < 0){
      velocita = -velocita;  //questa cosa moltiplica per -1 quindi inverte sempre il segno
    }
    
  }
  
};
