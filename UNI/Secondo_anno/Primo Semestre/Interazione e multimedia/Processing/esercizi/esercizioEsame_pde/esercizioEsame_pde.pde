ArrayList <Monitor> ab;

void setup(){
  size(500,500);
  background(230);
  frameRate(60);
  ab = new ArrayList<Monitor>();
  float larghezza = 60;
  float altezza = 33.75;
  float colore = random(0,255);
  color coloreQuadrato = color (random(0,255));
  ab.add(new Monitor(0,100,0,larghezza,altezza,colore,coloreQuadrato));
  
  altezza = 45;
  colore = 220;
  coloreQuadrato = color(0,255,0);
  ab.add(new OldMonitor(width,400,0,larghezza,altezza,colore,coloreQuadrato));
}

void draw(){
  background(230);
  for(Monitor schermo:ab){
     schermo.run();
  }
}
