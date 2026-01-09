/*
//colori che vengono disegnati di blu se la distanza tra x,y e il mouse si trova dentro il diametro del cerchio
int diametro = 50;
void setup(){
  size(500,500);
  background(#FFFF00);
  frameRate(60);
  colorMode(RGB , width); //cambia il modo in cui processing numera i colori, cosi prende RGB da 0 a 255 e lo spalma su width (500 in questo caso)
}

void draw(){
  for(int y = diametro/2; y<height; y+=diametro){
    for(int x = diametro/2; x<width; x+=diametro){
      if(dist(x,y,mouseX, mouseY)<diametro/2){
        fill(0,0,255);
      }else{
        fill(x,y,0);
      }
      ellipse(x,y,diametro,diametro);
    }
  }
}
*/
