/*int lunghezza = 100;
int altezza = 50;

void setup(){
size(800,800);
background(#E86767);
}


void draw(){
  for(int x = 0; x <width;x= x+lunghezza){
    for(int y = 0; y < height;y = y+altezza){
      noFill();
      strokeWeight(2);
      if(mouseX > x && mouseX < x+lunghezza && mouseY > y && mouseY < y+altezza){  //x,y sono i punti in alto a sinistra del rettangolo quindi controllo se mi trovo dentro e in caso lo coloro
        fill(0,0,255);
      }else{
        fill(#E86767);
      }
      rect(x,y,100,50);
    }
  
  }
}*/

/*int x = 200;
int y = 150;
int velx = 2;
int vely = 2;

void setup(){
size(800,800);
background(#E86767);
frameRate(300);
}


void draw(){
  
  background(#E86767);
  fill(0,0,0);
  
  ellipse(x,y,50,50);
  x = x +velx;
  y = y +vely;
  
  if(x>width || x < 0){
    velx = -velx;
  }
  
  if(y>height || y < 0){
    vely = -vely;
  }
  
}*/


void setup(){
  size(800,800);
  background(#E86767);
  frameRate(300);
}


void mouseDragged() 
{
  //mousePressed();
  strokeWeight(2);
  line(pmouseX,pmouseY,mouseX,mouseY);
}
void mousePressed(){
  stroke(random(255),random(255),random(255));
}

void keyPressed(){
  background(#E86767);
}


void draw(){
  
}
