/*c) [8] Implementare la funzione con prototipo PImage wow(PImage I).
Input è a scala di grigi. L’output è una nuova immagine in cui la sua metà inferiore viene invertita con la superiore e viceversa,
successivamente vengono sostituiti con pixel bianchi i pixel in diagonale dal centro dell’immagine all’angolo in basso a destra.

d) [7] Implementare la funzione con prototipo PImage mas(PImage I, int n) che applica l’operatore massimo sull’immagine con 
finestra di dimensioni n × n.

[OBBLIGATORIO PER VALUTARE I PUNTI PRECEDENTI]
Alla pressione di “R” o “r” lo sketch viene resettato. Implementare uno sketch in cui si apre una finestra di dimensioni 768×256.
Si apre inoltre un’immagine I, si converte a scala di grigi e si ridimensiona a 256×256. Si visualizza infine questa immagine nella
parte sinistra della finestra.

Per rendere (c) valutabile – Nella parte centrale della finestra, si visualizza l’immagine ottenuta usando wow() con input 
l’immagine originale.

Per rendere (d) valutabile – Nella parte destra della finestra, si visualizza l’immagine ottenuta usando mas() con input 
l’immagine ottenuta da wow(Im), e con n casuale tra 5 e 15.*/
color c = #F0F0F0;
PImage immagine;
void setup(){
  size(768,256);
  immagine = loadImage("lena.png");
  immagine.resize(256,256);
  image(immagine,0,0);
  immagine.filter(GRAY);
  image(wow(immagine),256,0);
  PImage massimo = wow(immagine);
  image(mas(massimo,(int)random(5,15)),512,0);
}


void draw(){
}

PImage mas(PImage I, int n){
  PImage R = I.copy();
  
  return R;
}

PImage wow(PImage I){
  PImage R = I.copy();
  R.copy(I,0,128,256,128,0,0,256,128);
  R.copy(I,0,0,256,128,0,128,256,128);
  
  R.loadPixels();
  for(int i = height/2; i < R.width; i++){
    R.pixels[pos(i,i,R.width)] = c;
  }
  
  R.updatePixels();
  
  return R;
}

int pos(int x, int y, int w){
  return x+y*w;
}


void keyPressed(){
  if(key == 'r' || key == 'R'){
    background(0);
  }
}
