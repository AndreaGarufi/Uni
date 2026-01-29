class Votone extends Voto{

  Votone(float posizioneX,float posizioneY,float speed, int text){
    super(posizioneX,posizioneY,speed,text);
    this.colore = #FAFAFA;
  }
  
  void display(){
    noFill();
    stroke(colore);
    rect(posX,posY,dim,dim);
    textSize(28);
    text(testo,posX+5,posY-5); 
    if(testo > 24){
      text("LODE",posX+5,posY-40);
    }
  }
    
}
