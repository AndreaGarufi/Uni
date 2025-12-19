class Square{

  float posX;
  float posY;
  float lato1;
  float lato2;
  
  float velocita;
  
  Square(float x, float y, float l1,float l2,float speed){
  
  this.posX = x;
  this.posY = y;
  this.lato1 = l1;
  this.lato2 = l2;
  this.velocita = speed;
  
  }
  
  Square(float x,float y, float l1, float l2){ 
    this(x,y,l1,l2,0);
  }

  void display(){
    fill(255,255,0);
    noStroke();
    rect(posX,posY,lato1,lato2);
  }

  void run(){
    display();
  }





};
