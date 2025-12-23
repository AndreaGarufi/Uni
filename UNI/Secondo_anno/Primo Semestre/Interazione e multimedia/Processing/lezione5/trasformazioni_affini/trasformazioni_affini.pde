

/*float scale = 0.2; //zoom e de-zoom
float dir_scale = 1;

void setup(){
  size(600,600);
  background(255,255,255);
  fill(0,255,0);
  stroke(255,0,0);
  strokeWeight(5);
  rectMode(CENTER);
  frameRate(60);
}


void draw(){
  background(255,255,255);
  translate(width/2,height/2);
  scale(scale);
  rect(0,0,width,height);
  scale =scale + (dir_scale * 0.01);
  //scale = scale +0.1;
  
  if(scale >= 1 || scale <= 0){
  dir_scale = -dir_scale;
  }
}*/


/*float shX = 0.1;
float shY = 0.1;

void setup(){
  size(600,600);
  background(255,255,255);
  fill(0,255,0);
  stroke(255,0,0);
  strokeWeight(5);
  rectMode(CENTER);
  frameRate(10);
}

void draw(){
  background(255,255,255);
  translate(width/2,height/2);
  shearX(shX);
  shearY(shY);
  rect(0,0,150,150);
   shX = shX +0.1;
   //println(shX);
   shY = shY +0.1;
}*/





 //palla che gira e schiarisce mentre gira
/*float rotAngle =  10;

void setup(){
  size(600,600);
  frameRate(60);
}

void draw(){
    fill(255,50);
    rect(0,0,width, height);
    translate(width/2,height/2);
    rotate(radians(rotAngle));
    noStroke();
    fill(255,0,0);
    ellipse(250,0,20,20);
    rotAngle+=20;
}*/

/*
int a1 = 0;  //quadrati che girano indipendentemente
int a2 = 0;

void setup(){
size(500,500);
rectMode(CENTER);
}


void draw(){
  
  background(0);
  
  pushMatrix();                //una trasformazione affine si applica a tutta la canvas, ma per farle su un singolo "oggetto" possiamo fare così
  translate(width/2,height/2);  //racchiudendo tra pushMatrix e popMatrix
  rotate(radians(a1));
  fill(255);
  rect(0,0,50,50);
  popMatrix();
  
  pushMatrix();
  translate(width/2+80,height/2);
  rotate(radians(a2));
  fill(255,0,0);
  rect(0,0,50,50);
  popMatrix();
  
  a1++;
  a2 = a2+4;

}*/
