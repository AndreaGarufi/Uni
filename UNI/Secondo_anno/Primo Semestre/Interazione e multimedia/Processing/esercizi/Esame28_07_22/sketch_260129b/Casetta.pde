class Casetta extends Casa{

  Casetta(float posizioneX, float posizioneY, float speed){
    super(posizioneX,posizioneY,speed);
    this.colore = #F4F5F2;
  }
  
  void display(){
    noFill();
    stroke(colore);
    rect(posX,posY,dim,dim);
    triangle(posX,posY,posX+15,posY-15,posX+30,posY);
    rect(posX+10,posY+20,10,10);
  }
  
  void move(){
    posX = posX + velocita;
    if(posX > width){
      posX = -30;
    }  
  }
}
