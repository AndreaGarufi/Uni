


/*
void setup(){
  size(700,700);
  stroke(255,0,0);
  frameRate(60);
  strokeWeight(10);
  background(255);
}

void draw(){

  if(mousePressed){
    
    line(pmouseX,pmouseY,mouseX,mouseY);
  }
}

void keyPressed(){
  if((key == 'g') || (key == 'G'))
  stroke(0,255,0);
  
  if((key == 'r') || (key == 'R'))
  stroke(random(0,255),random(0,255),random(0,255));
}
*/

/*
float x,y;
void setup(){
  size(700,700);
  noStroke();
  frameRate(6000);
}


void draw(){
  //background(0);
  
  fill(0,25);
  rect(0,0,width,height);
  x = lerp(x,mouseX,0.1);
  y = lerp(y,mouseY,0.1);
  fill(255);
  ellipse(x,y,60,60);

}
*/


/* INTRO LERP
size(700,700);
strokeWeight(5);
int x1 = 10;
int y1 = 10;

int x2 = 300;
int y2 = 300;
line(x1,y1,x2,y2);

for(int i = 1; i<10; i++){
  strokeWeight(15);
  stroke(255,0,0);
  float perc = i/10.0;
  float x = lerp(x1,x2,perc);
  float y = lerp(y1,y2,perc);
  point(x,y);
}*/

/*PACMAN
int dir = 1;
int v = 4;
int r = 40;
int x = r;
int a = 30;
int dira = -1;

void setup(){
  size(500,500);
  ellipseMode(RADIUS);
}

void draw(){
  background(0);
  fill(255,255,0);
  if(dir > 0){
    arc(x,height/2,r,r,radians(a),radians(360-a));
  }else{
    arc(x,height/2,r,r,radians(180+a),radians(360 +180-a));
  }
  
  fill(0);
  ellipse(x,height/2-20,5,5);
  
  
  if(dist(mouseX,mouseY,x,height/2) > r){
    if(x >= width-r || x < r){
      dir = -dir;
    }
    x = x + (dir*v);
    
    if(a > 30 || a < 0){
      dira = -dira;
    }
    a = a + dira;
  }
  
  
}

FINE PACMAN*/

/*
int x = 20;

void setup(){
  size(800,800);
}

void draw(){
  background(0);
  rect(x,height/2,50,50);
}

void keyPressed(){
  if(key == CODED){
    if(keyCode == LEFT){
      x = x-5;
      }else if(keyCode == RIGHT){
        x = x +5;
      }
  }
}
*/
/*
float [] r = new float[5];

void setup(){
  size(800,800);
  for(int i = 0; i < r.length; i++)
  r[i] = i*100;
}

void draw(){

  for(int i = r.length-1; i>0; i--){
    fill(random(0,255),random(0,255),random(0,255));
    ellipse(width/2,height/2,r[i],r[i]);
  }
}

void mousePressed(){
  noLoop();
}

void mouseReleased(){
  loop();
}


void keyPressed(){
  noLoop();
}

void keyReleased(){
  loop();
}

*/

/*
void setup(){
  size(500,500);
  
}

void draw(){
  
  
  if(mousePressed){
    if(mouseButton == LEFT){
      println("L");
    }
    
        if(mouseButton == RIGHT){
      println("R");
    }
    
        if(mouseButton == CENTER){
      println("C");
    }
  }
  
  
   if(keyPressed){
      if(key == 'a'){
        println("Hai cliccato sulla a");
      }
    }
}


void mouseReleased(){

  println("mouse rilasciato");
}


void mouseClicked(){

  println("mouse cliccato");
}
*/
