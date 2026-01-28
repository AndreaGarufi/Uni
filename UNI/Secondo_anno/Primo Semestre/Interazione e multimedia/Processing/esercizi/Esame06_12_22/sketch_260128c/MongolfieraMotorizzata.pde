class MongolfieraMotorizzata extends Mongolfiera{
  color coloreM;
  
  MongolfieraMotorizzata(float posizioneX, float posizioneY, float speed, int lun, int alt, int ball){
    super(posizioneX,posizioneY,speed,lun,alt,ball);
    this.coloreM = (int)random(0,255);
  }
  
  void display(){
     fill(255,0,0);
     rect(posX,posY,cestoLun,cestoAlt);
     line(posX,posY,posX,posY-70);
     line(posX+60,posY,posX+60,posY-70);
     fill(coloreM);
     ellipseMode(CENTER);
     ellipse(posX+30,posY-70,pallone,pallone); 
  }
  void move(){
    posX = posX + velocitaX;
    
    if(posX+60 > width){
      velocitaX = -velocitaX;
    }
    if(posX < 0){
      velocitaX = -velocitaX;
    }
  
  }
  
}
