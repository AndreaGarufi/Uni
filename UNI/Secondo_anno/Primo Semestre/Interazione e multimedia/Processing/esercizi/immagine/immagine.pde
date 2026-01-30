PImage immagine;

void setup(){
  size(512,512);
  immagine = loadImage("lena.png");
  immagine.resize(512,512);
  image(immagine,0,0);
}


void draw(){


}
