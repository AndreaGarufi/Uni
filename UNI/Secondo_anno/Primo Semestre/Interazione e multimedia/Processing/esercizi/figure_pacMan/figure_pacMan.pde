//GATTO

void setup(){
background(0);
size(800,800);

ellipseMode(RADIUS);
ellipse(width/2,height/2,130,120);  
strokeWeight(10);
line(450,410,500,395);
line(350,410,300,395);
fill(0);
triangle(380,440,400,460,420,440);
fill(255);
strokeWeight(1);
noStroke();
triangle(280,280,280,360,340,300);
fill(0);
ellipse(300,315,6,6);
fill(255);
triangle(520,280,520,360,460,300);
fill(0);
ellipse(500,315,6,6);

}

/*LUNE
int diametro = 100;
int x = diametro;

void setup(){
  size(800,800);
  int y = height/2;
  background(0);
  for(int x = diametro; x < width; x = x + 125){
   if(x < width){
     ellipse(x,y,diametro,diametro);
   }
  }
  
  for(int x = diametro; x < width; x = x + 125){
    if(x < width){
       fill(0);
     x = x + 5;
     y = y - 5;
    ellipse(x,y,diametro,diametro);
  }
  }
  
}
*/
/*
int x = 10;
int y = height/2;
int raggio = 30;
int d = raggio*2;

void setup(){
  size(800,800);
  noFill();
  ellipseMode(CENTER);
  
  for(int center = raggio; center < width; center = center+raggio){
    if(d < width){
    ellipse(center,height/2,d,d);
    d = d + (raggio * 2);
    }  
}
  
  
}
*/




/* pacman che si muove con le freccie
int dir = 1;
int v = 4;
int r = 40;   //dimensione del raggio dell'arco
int x = r;    //x parte da 40
int a = 30;  //angolo di apertura della bocca
int dira = -1;    //direzione in cui si muove la bocca
int y = 100;  //da qui parte la y
void setup(){
  size(500,500);
  ellipseMode(RADIUS);  //cosi impostiamo la modalità arco
}

void draw(){
  background(0);
  fill(255,255,0);
  if(dir > 0){
    arc(x,y,r,r,radians(a),radians(360-a));      //qui creiamo l'arco
  }
  
  fill(0);
  ellipse(x,y-20,5,5);
  
  
       if(a > 30 || a < 0){
      dira = -dira;
    }
    a = a + dira;

  }
  
  void keyPressed(){
  if(key == CODED){
    if(keyCode == LEFT){
      x = x - 5;
      }else if(keyCode == RIGHT){
        x = x + 5;
      }else if(keyCode == UP){
        y = y - 5;
      }else if (keyCode == DOWN){
        y = y + 5;      
      }
  }
  }
*/

/*
int x = 20;
int y = 20;
void setup(){
  size(800,800);
}

void draw(){
  background(0);
  rect(x,y,50,50);
}

void keyPressed(){
  if(key == CODED){
    if(keyCode == LEFT){
      x = x - 5;
      }else if(keyCode == RIGHT){
        x = x + 5;
      }else if(keyCode == UP){
        y = y + 5;
      }else if (keyCode == DOWN){
        y = y +5;      
      }
  }
}
*/
