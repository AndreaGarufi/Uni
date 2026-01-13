class OldMonitor extends Monitor{
    
    int flag;
  
    OldMonitor(float x, float y,float vX,float lun, float alt, float colorS, color colorSquare ){
      super(x,y,lun,alt,colorS,colorSquare);
      this.flag = 1;
    }
  
    void display(){
      stroke(colore);
      strokeWeight(5);
      color temp = coloreQuadrato;
      if(flag == 1){
        fill(coloreQuadrato);
      }else{
        coloreQuadrato = color(255,255,255);
      }
      coloreQuadrato = temp;
      rect(posX,posY,w,h);
    }
    
    void move(){
      if (mouseX > posX && mouseX < posX + w && mouseY > posY && mouseY < posY + h) {
        velocita = 0;
        flag = 0;
      }else{
        flag = 1;
        velocita = 4;
      }
      posX = posX - velocita;
      
      if((posX)<-60){
        posX = width+60;
      }
    }  
}
