class MegaSmile extends Smile{

  color coloreMega;
  
  MegaSmile(float posizioneX, float posizioneY, float velocita){
    super(posizioneX,posizioneY,velocita);
    this.coloreMega = #FFFFFC;
  }
  
  
  void display(){
    pushMatrix();
    fill(coloreMega);
    scale(1.5);
    ellipse(posX+25,posY,50,50);
    line(posX+10,posY-10,posX+10,posY+10);//occhio
    line(posX+40,posY-10,posX+40,posY+10);//occhio
    line(posX+10,posY+15,posX+40,posY+15);//bocca
    popMatrix();
  }
  
  void move(){
    posX = posX - velX;
    if(posX < -50){
      posX = width;
    }
  }

}
