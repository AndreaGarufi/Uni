int lato= 50;
void setup(){
size(800,800);
background(0,255,0);
noStroke();
frameRate(60);
  for(int y=0; y<height; y= y+lato){
     for(int x=0; x<width; x= x+lato){
      fill(random(255),130);
      rect(x+random(-5,5),y+random(-5,5),lato,lato);
    } 
  }
}


void draw(){
 // background(0,255,0);
}

void mousePressed(){
setup();
}

/*
int pos = 0;
int pos2 = 0;
int vel = 3;
int dir = 1;

void setup(){
size(800,800);
frameRate(60);
}

void draw(){
  background(125);
//if(pos1==width)
//pos1 = 0;
//if(pos2==width)
//pos2 = 0;

line(pos,20,pos,height-20);
if(pos>width || pos <0)
dir = -dir;
pos = pos + (dir*vel);

}
*/


/*bezier
void setup(){
size(800,800);
background(125);
noFill();

frameRate(60);
}


void draw(){
background(125);
textSize(40);
text("A1",185,50);
text("C1",mouseX,mouseY);
text("A2",15,300);
text("C2",190,300);
line(185,50,mouseX,mouseY);
line(15,300,190,300);
bezier(185,50,mouseX,mouseY,15,300,190,300);

}
*/

/*funzione arc
void setup(){

  size(800,800);
  background(255);
  fill(255,255,0);
  
  //0-90
  arc(100,height/2,100,100,0,HALF_PI);
  //0-270
  arc(200,height/2,100,100,0,PI+HALF_PI);
  //0-180
  arc(300,height/2,100,100,0,PI);
  //360
  arc(400,height/2,100,100,0,TWO_PI);
  
  arc(700,height/2,100,100,radians(30),radians(330),PIE); //con PIE chiude tutti i bordi ci sono anche OPEN e CHORD
 
}

void draw(){

}
*/
