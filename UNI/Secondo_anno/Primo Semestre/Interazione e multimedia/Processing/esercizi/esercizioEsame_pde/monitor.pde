class Monitor{

  float posX;
  float posY;
  float velocita;
  float w;
  float h;
  float colore;
  color coloreQuadrato;
  
  Monitor(float x, float y, float vX, float lun, float alt, float colorS, color colorSquare){
    this.posX = x;
    this.posY = y;
    this.velocita = vX;
    this.w = lun;
    this.h = alt;
    this.colore = colorS;
    this.coloreQuadrato = colorSquare;
    
  }
  
  Monitor(float x, float y, float lun, float alt, float colorS, color colorSquare ){
    this(x,y,0,lun,alt,colorS,colorSquare);
  }
  
  void display(){
    stroke(colore);
    strokeWeight(5);
    fill(coloreQuadrato);
    rect(posX,posY,w,h);
  }
  
  void move(){
    velocita = 4;
    posX = posX + velocita;
    
    if((posX)>width){
      posX = -60;
    }
  }
  
  void run(){    
    display();
    move();
    }

}
