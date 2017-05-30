import gifAnimation.*;

void setup() {
  size(400, 300);
  frameRate(fps);
  background(255);
  grid();
  
  export = new GifMaker(this, "tarefa5.gif");
  export.setRepeat(0);
}

void draw() {
  y = height - dY;
  x = dX;
  
  //background(255);
  //grid();
  textBox();
  dY = MRUV(vY, tY, a);
  dX = MRU(vX, tX);
  projectile();
  tY += 1.0/60.0;
  tX += 1.0/60.0;
  bounce();
  export.setDelay(1000/fps);
  export.addFrame();
}