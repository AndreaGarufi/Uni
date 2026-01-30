/*c) [15] Implementare la funzione con prototipo Pimage wow(PImage I). Input è a colori. 
L'output è una nuova immagine in cui la sua metà sinistra viene sostituita con la destra (vd. Immagine sotto). 
Successivamente vengono invertiti i colori per la parte superiore dell'immagine (negativo), 
per la restante te parte inferiore invece si azzera la componente di blu. 
La percentuale di immagine su cui lavorare viene estratta a random tra 0 e 1. 
Nell'esempio in basso è stato stato applicato il numero 0.45 
(quindi 0.45 in alto in cui si applica il filtro negativo e il restante 0.55 in basso in cui si azzera il blu).
[OBBLIGATORIO PER VALUTARE I PUNTI PRECEDENTI]
Alla pressione di "R" o "r" lo sketch viene resettato. 
Implementare uno sketch in cui si apre una finestra di dimensioni 512×256. 
Si apre inoltre un'immagine I e si ridimensiona a 256x256. 
Si visualizza infine questa immagine nella parte sinistra della finestra.
Per rendere (c) valutabile - Nella parte centrale della finestra, si visualizza l'immagine ottenuta usando wow() 
con input l'immagine originale.*/

PImage I;
void setup(){
  
  I = loadImage("lena.png");
  I.resize(256,256);
  size(512,256);
  
}


void draw(){
  image(I,0,0);
  
  image(wow(I),256,0);
}

PImage wow(PImage I){
  
  PImage R = I.copy();
  R.copy(R,128,0,256,256,0,0,256,256);  //copio la parte destra nella sinistra, copy(ImageSource,coordinatePixelSourceX,coordinatePixelSourceY,dimensionImageX,dimensionImageY,coordinatePixelDestinationX,coordinatePixelDestinationY,dimensionImageX,dimensionImageY);
  R.copy(R,0,0,256,256,128,0,256,256);  //
  
  R.loadPixels();
  float r,g,b;
  for(int i = 0; i < (R.pixels.length)/2;i++){  //negativo
    r = 255-red(R.pixels[i]);
    g = 255-green(R.pixels[i]);
    b = 255-blue(R.pixels[i]);
    R.pixels[i] = color(r,g,b);
  }
  
  color c,c1;
  for(int i = (R.pixels.length)/2; i < R.pixels.length;i++){  //azzeramento blu
    c1 = R.pixels[i];
    c = color(red(c1),green(c1));
    R.pixels[i] = c;
  }
  R.updatePixels();
  
  return R;
}
