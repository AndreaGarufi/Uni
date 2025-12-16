//ci sono altri esercizi

/*PImage Im, ImN, ImG, ImL;

//prendere questo esercizio perche non è completo

void setup(){
  Im = loadImage("immagine.png");
  size(512,512);
  Im.resize(256,256);
  image(Im,0,0);
  
  
  ImN = negativo(Im);
  image(ImN,256,0);
}

void draw(){
}

PImage negativo(PImage I){
  PImage R=I.copy();
  float r,g,b;
  R.loadPixels();
  for(int i = 0; i < R.pixels.length;i++){
    r = 255-red(R.pixels[i]);
    g = 255-green(R.pixels[i]);
    b = 255-blue(R.pixels[i]);
    
    R.pixels[i] = color(r,g,b);
  }
  
  R.updatePixels();
  return R;
}*/


/*PImage I;
float r,g,b;
color c;

int pos(int x, int y,int w){
  return x+y*w;
}

void setup(){

  I = createImage(500,500,RGB);
  size(500,500);
  I.loadPixels();
  for(int y=0; y<I.height; y++){
    for(int x=0;x<I.height;x++){
      r = lerp(0,255,float(x)/I.width);
      g = lerp(0,255,float(y)/I.height);
      c = color(r,g,b);
      I.pixels[pos(x,y,I.width)] = c;
    }
  }
  
  I.updatePixels();
}

void draw(){
image(I,0,0);
  
}*/



/*PImage I;      //non va controlla con chat gpt e file girlando
float r,g,b;
color c,c1;

void setup(){
  size(512,512);
  c = color(255,255,0);
  I = loadImage("immagine.png");
  I.loadPixels();
  for(int i = 0; i <I.width;i++){
    I.pixels[pos(i,i,I.width)] = c;
    //I.set(i,i,c);
  }
}

void draw(){

  image(I,0,0);
}

int pos(int x, int y,int w){
  return x+y*w;
}
*/


/*
// argomento fondamentale della seconda parte del corso    (quando clicco - l'immagine ritorna normale ma non dovrbbe farlo, guardare file girlando e chat gpt)
PImage I;
float r,g,b;
color c,c1;
int ar;
//guarda lazione di girlando per altri commenti


void setup(){
  size(925,556);
  I = loadImage("immagine.png");
  
}


void draw(){
  image(I,0,0);
}

void keyPressed(){
  if(key =='+'){
  ar++;
  }
  
  if(key =='-'){
  ar--;
  }
  
  I.loadPixels();
  for(int i = 0; i < I.pixels.length; i++){
    c1=I.pixels[i];
    c = color(red(c1)+ar,green(c1),blue(c1));
    I.pixels[i] = c;
  }
  
  I.updatePixels();
  println(ar);
  
}*/



/*   //foto con sfondo che cambia colore
PImage H;
color c;
int x,y;

void setup(){
  size(500,500);
  H = loadImage("immagine.png");
  H.resize(200,200);
  c = color(0);
  x = width/2-H.width/2;
  y = height/2-H.height/2;
}

void draw(){
background(c);
c = H.get(mouseX-x,mouseY-y);
image(H,x,y);

}*/
