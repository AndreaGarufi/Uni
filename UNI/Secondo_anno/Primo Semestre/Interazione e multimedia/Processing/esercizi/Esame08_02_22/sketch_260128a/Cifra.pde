class Cifra{
  float posX;
  float posY;
  float velocitaY;
  int dim;
  color colore;
  int testo;
  
  Cifra(float posizioneX, float posizioneY, float vel, int text){
    this.posX = posizioneX;
    this.posY = posizioneY;
    this.velocitaY = vel;
    this.dim = 32;
    this.colore = #F8FF39;
    this.testo = text;
  }
  
  void display(){
    fill(colore);
    textSize(dim);
    text(testo,posX,posY);
  }
  
  void move(){
    posY = posY+velocitaY;
    
    if((posY-32) > height){
      posY = 0;
    }
  }
  
  void run(){
    display();
    move();
  }

}
