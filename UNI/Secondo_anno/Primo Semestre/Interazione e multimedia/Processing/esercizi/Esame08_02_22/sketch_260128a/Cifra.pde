class Cifra{
  float posX;
  float posY;
  float velocitaY;
  int dim;
  color colore;
  
  Cifra(float posizioneX, float posizioneY, float vel, int dimensione){
    this.posX = posizioneX;
    this.posY = posizioneY;
    this.velocitaY = vel;
    this.dim = dimensione;
    this.colore = #F8FF39;
  }
  
  void display(){
    fill(colore);
    textSize(dim);
    text(random(0,9),posX,posY);
  }
  
  void run(){
    display();
  }

}
