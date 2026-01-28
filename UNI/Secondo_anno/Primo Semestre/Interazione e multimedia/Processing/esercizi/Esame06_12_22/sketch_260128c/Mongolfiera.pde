class Mongolfiera{
  float posX;
  float posY;
  float velocitaX;
  int cestoLun;
  int cestoAlt;
  int pallone;
  color colore;
  
  Mongolfiera(float posizioneX, float posizioneY, float speed, int lun, int alt, int ball){
    this.posX = posizioneX;
    this.posY = posizioneY;
    this.velocitaX = speed;
    this.cestoLun = lun;
    this.cestoAlt = alt;
    this.pallone = ball;
    this.colore = #4CFF40;
  }
  
  void display(){
     fill(255,0,0);
     rect(posX,posY,cestoLun,cestoAlt);
     line(posX,posY,posX,posY-70);
     line(posX+60,posY,posX+60,posY-70);
     fill(colore);
     ellipseMode(CENTER);
     ellipse(posX+30,posY-70,pallone,pallone); 
  }
  
  void move(){
    posX = posX + velocitaX;
    
    if(posX-35 > width){
      posX = -70;
    }
  
  }
  
  void run(){
    display();
    move();
  }


}
