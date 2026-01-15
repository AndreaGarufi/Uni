

/*
// RUMORE
void setup(){
  size(800,400);
}

void draw(){
  background(200);
  for(int x = 40; x<width; x += 40){
    //float rum = mouseX/10;
      float rum = map(mouseX, 0, width, 0,width/10);
      float rumi = random(-rum, rum); //sarebbe rumore iniziale
      float rumf = random(-rum, rum); //sarebbe rumore finale
      line(x+rumi, 100, x+rumf, height-100);
  }
}
*/

/*
//ESERCIZIO PUPILLA
int raggio = 50;
float lato = raggio*sqrt(2);
float move = lato/2;

void setup(){
  size(500,500);
  ellipseMode(RADIUS);
}

void draw(){
  background(100);
  fill(255);
  ellipse(width/2, height/2, raggio, raggio);
  float x = map(mouseX, 0, width, -move, move);
  float y = map(mouseY, 0, width, -move, move);
  fill(0);
  ellipse(x+width/2, y+height/2, 5, 5);
}
*/


/*
// Creazione di cerchi in una sottocanvas usando map
void setup(){
  size(700,700);
  
}


void draw(){
  float x = map(mouseX, 0, width, 250, 450);
  float y = map(mouseY, 0, height, 250, 450);
  ellipse(x,y,40,40);
}
*/

/*
//Funzione MAP permette di mappare un range [a , b] in un range più grande [m, n]
void setup(){
  size(700, 700);
  background(100);
}

void draw(){
  background(0);
  float r = map(mouseX, 0, width, 20, 250); // il valore da controllare è il primo poi abbiamo m, M, a, b
  fill(255,r,0);
  ellipse(width/2, height/2, r,r);
  
  //Scommentare di seguito per capire come mappa la funzione map
  println(mouseX);
  println(r);
  println("-----------");
}
*/

/*
// cerchio crescente/decrescente
int x;
int y;
int r = 30;
int dir = 1;

void setup(){
  size(500,500);
  x=width/2;
  y=height/2;
  ellipseMode(RADIUS);
}

void draw(){
  background(200);
  float d = dist(mouseX, mouseY, x, y); //dist misura la distanza tra due punti e restituisce un float, in qeusto caso la distanza tra dove ho il mouse e il centro del cerchio
  if(r == 20 || r == width/2) dir = -dir;  //se il cerchio è piccolo r = 20, o grande r = width/2 inverte la direzione
  if(d<r){
    r = r + dir;
    fill(0);
  }else{
    fill(255);
  }
  ellipse(x,y,r,r);
}
*/


/*
//pallina che rimbalza con la gravita
float y = 0;
float x;
float speed = 2;
float gravity = 0.40;
float attrito = 0.10; // La velocità diminuisce del 10%

void setup(){
  size(800,500);
  x = width/2;
}

void draw(){
  background(255);
  fill(255,0,0);
  stroke(0,0,255);
  
  y = y + speed;
  speed = speed + gravity; // la velocità aumenta perchè la pallina sta scendendo
  
  if(y>height-25){
    speed=speed*-(1-attrito);
  }
  
  ellipse(x,y,50,50);
  
}
*/
